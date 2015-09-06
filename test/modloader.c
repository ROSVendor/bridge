/**
 * Bridge.ModLoader的测试程序
 */

#include <bridge/modloader.h>
#include <bridge/io.h>

int main(int args, char *argv[]) {
    REQUIRE(ModIO, io, "Bridge.IO");
    io->write(1, "Hello, world!", 14);
    return 0;
}
