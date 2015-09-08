/**
 * Bridge中C++实现共享的定义
 */
#ifndef BRIDGE__BRIDGE_HPP
#define BRIDGE__BRIDGE_HPP

#include <string>
#include <map>

#ifdef __cplusplus
extern "C" {
#endif

    typedef std::map<std::string, void *>   record_t;
    typedef std::map<std::string, record_t*> group_t;

#ifdef __cplusplus
}
#endif

#endif //BRIDGE__BRIDGE_HPP
