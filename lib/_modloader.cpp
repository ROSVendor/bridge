/**
 * Bridge的模块加载器的默认实现
 */

#include <dlfcn.h>
#include <unistd.h>
#include <cstring>
#include <cstdlib>
#include <cctype>
#include <include/module.h>
#include <include/_modloader.h>
#include <include/_error.h>
#include <include/_io.h>

#include <map>
#include <string>
#include <algorithm>
#include <functional>

static void strmap(char * src, int (fn)(int)) {
    for (int i = 0; src[i]; ++i) {
        src[i] = (char) fn(src[i]);
    }
}

typedef std::map <std::string, void *> record_t;
static record_t *entities;
static record_t * dylibs;

static std::string *local_dylib_path(const char *mod_name) {
    std::string * dylib_path = new std::string("/usr/local/lib/.so");
    std::string s = mod_name;
    std::transform(s.begin(), s.end(), s.begin(), [](auto c) {
        if (c == '.')
            return '/';
        return char(tolower(c));
    });
    dylib_path->insert(15, s);
    return dylib_path;
}

#define _SETTER_(name, map) \
    static inline void name(const std::string& key, void * value) { \
        (*map)[key] = value; \
    }

_SETTER_(set_dylib,   dylibs);
_SETTER_(set_entity, entities);
#undef _SETTER_

#define _GETTER_(name, map) \
    static inline void * name(std::string& key) { \
        record_t::const_iterator i = map->find(key); \
        if (i != map->end()) \
            return i->second; \
        return nullptr; \
    } \
    template<typename T> \
    static inline void * name(T& key) { \
        std::string s = key; \
        return name(s);      \
    } \

_GETTER_(get_dylib,  dylibs);
_GETTER_(get_entity, entities);
#undef _GETTER_

static void * load_dylib(const char * path) {
    void * dylib = dlopen(path, RTLD_NOW);
    if (dylib == nullptr) {
        _bridge_error_set_error(ES_MOD_LOAD_FIALURE,
                                "module not found");
        return nullptr;
    }
    return dylib;
}

static void * load_entity(void * dylib) {
    typedef void (entity_getter_t)(void **);
    void * getter = dlsym(dylib, "entity_getter");
    void * entity = nullptr;
    if (getter != nullptr) {
        reinterpret_cast<entity_getter_t*>(getter)(&entity);
        if (entity != nullptr)
            return entity;
    }
    _bridge_error_set_error(ES_MOD_LOAD_FIALURE,
                            "bad module format");
    return nullptr;
}

ret_state _bridge_modloader_require(void ** addrp, const char * mod_name) {
    typedef ret_state (*getter)(void**);
    std::string& dylib_path = *local_dylib_path(mod_name);
    void * entity = get_entity(mod_name);
    void * dylib  = get_dylib(dylib_path);
    if (dylib == nullptr) {
        dylib = load_dylib(dylib_path.c_str());
        set_dylib(dylib_path, dylib);
    }
    if (entity == nullptr) {
        entity = load_entity(dylib);
        set_entity(mod_name, entity);
    }
    *addrp = entity;
    return ES_NORMAL;
}

ret_state _bridge_modloader_remove(const void * mod) {
    return ES_NORMAL;
}

MODULE_CONSTRUCTOR {
    entities = new record_t();
    dylibs   = new record_t();
}

MODULE_FINALIZER {
    delete entities;
    delete dylibs;
};

