/**
 * Bridge运行时系统的实现
 */

#include <bridge/runtime.h>
#include <bridge/_runtime.h>
#include <bridge/_bridge.hpp>

static inline void * elem_or_nil(group_t * group, std::string& key) {
    auto it = group->find(key);
    if (it == group->end())
        return nullptr;
    return it->second;
}

static inline void * elem_or_nil(group_t * group, const char * key) {
    std::string domain_s = key;
    return elem_or_nil(group, domain_s);
}
static inline void * elem_or_new(group_t * group, std::string& key) {
    auto it = group->find(key);
    if (it == group->end())
        it->second = new record_t();
    return it->second;
}
static inline void * elem_or_new(group_t * group, const char * key) {
    std::string domain_s = key;
    return elem_or_new(group, domain_s);
}

extern "C" {

static record_t * type_trans_holder;
static record_t * module_holder;
static group_t  * group;

void * _bridge_rts_get_domain(const char * domain) {
    return elem_or_new(group, domain);
}

void _bridge_rts_release_domain(const char * domain) {
    record_t * record = (record_t *) elem_or_nil(group, domain);
    if (record)
        delete(record);
}

void _bridge_rts_initialize() {
    type_trans_holder = new  record_t();
    module_holder = new record_t();
    group = new group_t();
    (*group)["Module"] = module_holder;
    (*group)["TypeSystem"] = type_trans_holder;
}

void _bridge_rts_finalize() {
    for(auto rp: *group) {
        delete(rp.second);
    }
    delete(group);
}

}
