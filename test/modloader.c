/**
 * Bridge.ModLoader的测试程序
 */

#include <bridge/bridge.h>
#include <bridge/modloader.h>
#include <bridge/io.h>

int main(int args, char *argv[]) {
    bridge_initialize();
    REQUIRE(ModIO, io, "Bridge.IO");
    io->write(1, "Hello, world!", 14);
    bridge_finalize();
    return 0;
}
