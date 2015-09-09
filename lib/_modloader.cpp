/**
 * Bridge的模块加载器的默认实现
 */

#include <dlfcn.h>
#include <unistd.h>
#include <cstring>
#include <cstdlib>
#include <cctype>
#include <bridge/module.h>
#include <bridge/runtime.h>
#include <bridge/_runtime.h>
#include <bridge/_modloader.h>
#include <bridge/_error.h>
#include <bridge/_io.h>
#include <bridge/_bridge.hpp>

template <typename V>
class Field {
public:
    typedef V * content_ptr;
    Field(record_t * record) : record(record) {};
    inline content_ptr get(const char * key) {
        return get(std::string(key));
    }
    inline content_ptr get(const std::string& key) {
        record_t::const_iterator i = record->find(key);
        if (i != record->end())
            return (const content_ptr) i->second;
        return nullptr;
    }
    inline void set(const char * key, content_ptr value) {
        std::string s = key;
        set(s, value);
    }
    inline void set(const std::string& key, content_ptr value) {
        (*record)[key] = value;
    }
    inline void clear(const char * key){
        set(key, nullptr);
    }
    inline void clear(const std::string& key){
        set(key, nullptr);
    }
private:
    record_t *  record;
};
static void strmap(char * src, int (fn)(int)) {
    for (int i = 0; src[i]; ++i) {
        src[i] = (char) fn(src[i]);
    }
}

typedef std::map<std::string, void *> record_t;
static Field<void>        * entities;
static Field<void>        * dylibs;
static Field<std::string> * dylibpaths;

static std::string * local_dylib_path(const char * mod_name) {
    std::string * dylib_path = new std::string("/usr/local/lib/bridge/.so");
    std::string s = mod_name;
    std::transform(s.begin(), s.end(), s.begin(), [ ](auto c) {
        if (c == '.')
            return '/';
        return char(tolower(c));
    });
    dylib_path->insert(22, s);
    return dylib_path;
}


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
        reinterpret_cast<entity_getter_t *>(getter)(&entity);
        if (entity != nullptr)
            return entity;
    }
    _bridge_error_set_error(ES_MOD_LOAD_FIALURE,
                            "bad module format");
    return nullptr;
}

ret_state _bridge_modloader_require(void ** addrp, const char * mod_name) {
    typedef ret_state (* getter)(void **);
    std::string& dylib_path = * local_dylib_path(mod_name);
    void * entity = entities->get(mod_name);
    void * dylib  = dylibs->get(dylib_path);
    if (dylib == nullptr) {
        dylib = load_dylib(dylib_path.c_str());
        dylibs->set(dylib_path, dylib);
    }
    if (entity == nullptr) {
        entity = load_entity(dylib);
        entities->set(mod_name, entity);
    }
    CALL_MODULE_INITIALIZER(entity);
    *addrp = entity;
    return ES_NORMAL;
}

ret_state _bridge_modloader_remove(const void * entity) {
#define NULL_END(val) if (val == nullptr) return ES_NORMAL;
    NULL_END(entity);
    const char * mod_name = GET_MODULE_NAME(entity);
    CALL_MODULE_FINALIZER(entity);
    entities->clear(mod_name);
    std::string * dylib_path = (std::string *) dylibpaths->get(mod_name);
    NULL_END(dylib_path);
    void * dylib = dylibs->get(*dylib_path);
    NULL_END(dylib);
    dlclose(dylib);
    return ES_NORMAL;
#undef NULL_END
}

void _bridge_modloader_initialize() {
    BridgeRTS * runtime = _bridge_rts_get_runtime();
    record_t * _entities = (record_t *) runtime->get_domain("Entity");
    record_t * _dylibs = (record_t *) runtime->get_domain("Dylib");
    record_t * _dylibnames = (record_t *) runtime->get_domain("DylibName");
    dylibs     = new Field<void>(_dylibs);
    entities   = new Field<void>(_entities);
    dylibpaths = new Field<std::string>(_dylibnames);
}

void _bridge_modloader_finialize() {};

