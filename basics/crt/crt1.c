extern void __wasm_call_ctors(void);
void _Exit(int) __attribute__((noreturn));

#ifdef REACTOR_RUNTIME
extern void reactor_setup(int, char *[]);
#else
extern int main(int, char *[]);
extern void __prepare_for_exit(void);
#endif

#ifdef REACTOR_RUNTIME
void __wasi_unstable_reactor_start(void) {
#else
void _start(void) {
#endif
    /* The linker synthesizes this to call constructors. */
    __wasm_call_ctors();

#ifdef REACTOR_RUNTIME
    /* Call reactor_setup with the arguments. */
    reactor_setup(argc, argv);
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
