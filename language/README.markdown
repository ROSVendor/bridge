# Bridge - Language

Bridge项目中不同语言语言的兼容层的实现。
这些不同语言的支持会被编译成独立的静态链接库，
以供Bridge在运行时加载调用。

一个语言模块应该包含以下结构：
+ `interface.c`或者`include/`
+ `wrapper.c`或者`dwrapper/`
+ `typesystem.c`或者`typesystem/`

他们分别负责实现