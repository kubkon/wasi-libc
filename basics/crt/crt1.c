#include "crt1.h"

#ifdef REACTOR_RUNTIME
void __wasi_unstable_reactor_start(void) {
#else
void _start(void) {
#endif
    /*
     * In the basics directory, we don't have a way to pass in command-line
     * parameters, so we just use some simple placeholder arguments. For real
     * command-line argument handling, see the crt1.c in libc-bottom-half.
     */
    static char *argv[] = {
        "program",
        NULL
    };

    /* Start the program! */
    start_program(1, argv);
}
