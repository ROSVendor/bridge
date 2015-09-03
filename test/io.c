/**
 * 测试Bridge.IO
 */

#include <include/bridge.h>
#include <include/_io.h>

int main(int args, char *argv[]) {
    _bridge_io_write(1, "Hello World", 12);
    return 0;
}