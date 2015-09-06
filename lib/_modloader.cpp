/**
 * Bridge的模块加载器的默认实现
 */

#include <dlfcn.h>
#include <unistd.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
#include <include/_modloader.h>
#include <include/_error.h>

#define  DYLIB_NAME_LEN_MAX 4096

static char dyname[DYLIB_NAME_LEN_MAX] = "lib";

static void strmap(char * src, int (fn)(int)) {
    for (int i = 0; src[i]; ++i) {
        src[i] = (char) fn(src[i]);
    }
}

// TODO 准备Linux平台版本
static const char * dylib_name(const char * mod_name) {
    char * tok;
    char * mutable_mod_name = strdup(mod_name);
    strmap(mutable_mod_name, tolower);
    memcpy(dyname, "lib", 4);
    for(tok = strtok(mutable_mod_name, ".");
        tok;
        tok = strtok(NULL, ".")) {
        strcat(dyname, tok);
    }
    strcat(dyname, ".dylib");
    free(mutable_mod_name);
    return strdup(dyname);
}

ret_state _bridge_modloader_require(void ** addrp, const char * name) {
    typedef ret_state (*getter)(void**);
    const char * dylib_file_name = dylib_name(name);
    void * mod = dlopen(dylib_file_name, RTLD_NOW);
    free((void *)dylib_file_name);
    if (mod == NULL) {
        _bridge_error_set_error(ES_MOD_LOAD_FIALURE, "!!!");
        return ES_MOD_LOAD_FIALURE;
    }
    void * ge = dlsym(mod, "get_entity");
    ((getter)ge)(addrp);
    return ES_NORMAL;
}

ret_state _bridge_modloader_remove(const void * mod) {
    return ES_NORMAL;
}

