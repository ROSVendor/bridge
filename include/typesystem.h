/**
 * 类型系统的关键定义
 */
#ifndef BRIDGE_TYPESYSTEM_H
#define BRIDGE_TYPESYSTEM_H

#include <stdbool.h>
#include <include/language.h>

/**
 * 定义基本类型
 */
enum CBasicType {
    C_VOID,
    C_I8, C_I16, C_I32, C_I64,
          C_F16, C_F32, C_F64,
    C_VOIDP
};

/**
 * 定义类型的数据表示
 */
typedef struct {
    bool is_const, is_signed, is_atom, is_volatile;
    enum CBasicType type;
    int  ptr_level; // 0 -> raw data
} CType;

typedef struct {
    CType * type;
    void  * pointer;
} CValue;


/**
 * 类型互换
 * 不支持两个外部语言之间的相互转换，必须使用C语言桥接
 * 这会降低性能，但是总线架构能有效地抑制复杂度
 */
void   * cast_to_foreign(Family*, Runtime*, CValue *);
CValue * cast_to_native (Family*, Runtime*, void   *);

#endif //BRIDGE_TYPESYSTEM_H
