#ifndef BRIDGE_LANGUAGE_H
#define BRIDGE_LANGUAGE_H

#include <include/entity.h>
#include <include/typesystem.h>

/**
 * 定义语言族系
 * 注意：这不是具体语言，只是定义了语言的族系
 * 这里的族系以实现为界，而且严格受限于类型系统
 * 例如，Clojure属于Java族系，Elixir属于Erlang族系
 * Hack似乎是typed PHP，语法和新版的PHP几无出入，但其类型系统并不是PHP的类型系统，详见HHVM
 * 要处理Hack之类的类型系统被重新实现的语言，请使用对应类型系统的族系
 */
enum LanguageFamily {
    C = 0,
    CPP,
    HASKELL,
    ERLANG,
    PYTHON,
    RUBY,
    JAVASCRIPT,
    COMMONLISP,
    SHCEMA,
    ROCKET,
    GO,
    JAVA,
    FAMILY_COUNT,
    CUSTOM_FAMILY
};

typedef struct {
    DERIVING_NAMED;
} Family;

/**
 * 语言的运行时环境
 */
enum LanguageRuntime {
    NATIVE = 0,     // 编译成本地代码
    RTS,            // Haskell's RunTime System
    BEAM,           // Erlang's beam VM
    PVM,            // Python VM
    RVM,            // Ruby's VM
    V8,             // Google V8 Engine
    PARROT,         // Parrot VM
    OPEN_JVM,       // OpenJDKd JVM
    ORACLE_JVM,     // Oracle's JVM
    RUNTIME_COUNT,  // 统计内置运行时环境的数量
    CUSTOM_RUNTIME, // 其他需要解释器或者虚拟机运行的语言，如CLisp
};

typedef void* (*cast_foreign_func)(CValue*);
typedef CValue* (*cast_native_func)();

typedef struct {
    DERIVING_NAMED;

} Runtime;


typedef struct {
    enum LanguageFamily  native;
    enum LanguageRuntime runtime;
} Bridge;

#endif //BRIDGE_LANGUAGE_H
