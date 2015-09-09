/**
 * Bridge.ModLoader的默认实现的定义
 */

#ifndef BRIDGE__MODLOADER_H
#define BRIDGE__MODLOADER_H

#include <bridge/error.h>
#include <bridge/macro.h>

// TODO 实现一个ANSI C的版本
// TODO 添加静态扫描以配置足够的内存空间

template <typename V>
class Field {
    public:
    typedef V * content_ptr;
    Field(auto name, record_t * record) : name(name), record(record) {};
    inline content_ptr get(const char * key) {
        return get(std::string(key));
    }
    inline content_ptr get(const std::string& key) {
        record_t::const_iterator i = record->find(key);
        if (i != record->end())
            return i->second;
        return nullptr;
    }
    inline void set(const char * key, content_ptr value) {
        std::string s = key;
        set(s, value);
    }
    inline void set(const std::string& key, content_ptr value) {
        (*record)[key] = value;
    }
    inline void clear(auto key) {
        set(key, nullptr);
    }
    private:
    record_t *  record;
    std::string name;
};

#ifdef __cplusplus
extern "C" {

#endif
    ret_state _bridge_modloader_require(void **, const char *);
    ret_state _bridge_modloader_replace(void **, const char *, const char *);
    ret_state _bridge_modloader_remove(const void *);
#ifdef __cplusplus
};
#endif

#endif //BRIDGE__MODLOADER_H
