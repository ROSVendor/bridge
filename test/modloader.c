/**
 * Bridge.ModLoader的测试程序
 */

#include <include/_modloader.h>
#include <include/io.h>

int main(int args, char *argv[]) {
    ModIO * modio;
    _bridge_modloader_require((void**)&modio, "Bridge.IO");
    modio->write(1, "Hello, world!", 14);
    return 0;
}