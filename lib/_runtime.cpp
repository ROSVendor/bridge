/**
 * Bridge运行时系统的实现
 */

#include <bridge/runtime.h>
#include <bridge/_runtime.h>
#include <bridge/_bridge.hpp>
#include <bridge/module.h>

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

}

MODULE_CONSTRUCTOR {
    type_trans_holder = new  record_t();
    module_holder = new record_t();
    group = new group_t();
    (*group)["Module"] = module_holder;
    (*group)["TypeSystem"] = type_trans_holder;
}

MODULE_FINALIZER {
    for(auto rp: *group) {
        delete(rp.second);
    }
    delete(group);
}




