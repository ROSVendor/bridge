/**
 * 测试Bridge.IO
 */

#include <stdio.h>
#include <bridge/bridge.h>
#include <bridge/_io.h>

int main(int args, char *argv[]) {
    char buffer[24] = {};
    _bridge_io_write(1, "Hello World", 12);
    _bridge_io_read(0, buffer, 4);
    _bridge_io_write(1, buffer, 4);
    return 0;
}
