/**
 * 系统信息
 */
#ifndef BRIDGE_ENV_H
#define BRIDGE_ENV_H

#include <include/entity.h>

#ifdef __cplusplus
extern "C" {
#endif

/**
 * 定义运行容器
 */
enum ContainerType {
    LXC,             // Linux Container
    VM,              // Any kind of VM
    PHY,             // Any kind of physical machine
    LOCAL,           // Run on local machine. GOD NO.
    CUSTOM_CONTAINER
};

typedef struct {
    DERIVING_NAMED;
} Container;

typedef struct {
    Container * container;
} Env;

#ifdef __cplusplus
}
#endif

#endif //BRIDGE_ENV_H
