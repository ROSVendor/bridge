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
    C_VOIDP,
    EXTERN_TYPE
};

/**
 * 来自外部系统的数据类型
 */
enum ExternType {
    UNUSED_FIELD = 0,
    PCL_PC,
    MATLAB_MAT,
    CUSTOM_EXTERN_TYPE
};

/**
 * 定义类型的数据表示
 */
typedef struct {
    bool is_const, is_signed, is_atom, is_volatile;
    enum CBasicType type;
    enum ExternType extern_type;
    int  ptr_level; // 0 -> raw data
} CType;

typedef struct {
    CType * type;
    void  * pointer;
} CValue;

#endif //BRIDGE_TYPESYSTEM_H
