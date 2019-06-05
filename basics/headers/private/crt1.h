/*
 * Common code for defining the crt1.o object, which defines the program
 * entrypoint.
 */

extern void __wasm_call_ctors(void);
void _Exit(int) __attribute__((noreturn));

#ifdef REACTOR_RUNTIME
extern void reactor_setup(int, char *[]) __attribute__((weak));
#else
extern int main(int, char *[]);
extern void __prepare_for_exit(void);
#endif

static inline void start_program(int argc, char *argv[]) {
    /* The linker synthesizes this to call constructors. */
    __wasm_call_ctors();

#ifdef REACTOR_RUNTIME
    /*
     * Call reactor_setup with the arguments. It's a weak external, so we
     * can skip calling it if it's not defined.
     */
    if (reactor_setup) {
        reactor_setup(argc, argv);
    }
#else
    /* Call main with no arguments. */
    int r = main(0, 0);

    /* Call atexit functions, destructors, stdio cleanup, etc. */
    __prepare_for_exit();

    /* If main exited successfully, just return, otherwise call _Exit. */
    if (r != 0) {
        _Exit(r);
    }
#endif
}
