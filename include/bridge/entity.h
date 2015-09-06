/**
 * 定义Bridge中的各种实体结构的通用部分
 */


#ifndef BRIDGE_ENTITY_H
#define BRIDGE_ENTITY_H

#include <include/entity.h>

#ifdef __cplusplus
extern "C" {
#endif

#define DERIVING_NAMED const char * name
#define NAMEOF(entity) (entity->name)

#ifdef __cplusplus
}
#endif

#endif //BRIDGE_ENTITY_H
