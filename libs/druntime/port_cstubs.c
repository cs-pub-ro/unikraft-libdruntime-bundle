#include <sys/types.h>
#include <sys/_sigset.h>
#include <pthread.h>

typedef struct _MY_IO_FILE
    {
        int     _flags;
        char*   _read_ptr;
        char*   _read_end;
        char*   _read_base;
        char*   _write_base;
        char*   _write_ptr;
        char*   _write_end;
        char*   _buf_base;
        char*   _buf_end;
        char*   _save_base;
        char*   _backup_base;
        char*   _save_end;
        void*   _markers;
        struct _IO_FILE* _chain;
        int     _fileno;
        int     _blksize;
        int     _old_offset;
        ushort  _cur_column;
        char    _vtable_offset;
        char _shortbuf[1];
        void*   _lock;
    } FILE;

FILE* stderr;
FILE* stdout;
FILE* stdin;


int *__errno_location(void) {return 0;}


// from newlib/libc/include/sys/signal.h
typedef __sigset_t  sigset_t;

int sigfillset(sigset_t *set) {return 0;}

int sigdelset(sigset_t *set, int t) {return 0;}



/*
 * Implemented, apparently, in musl:
 *  build/libmusl/origin/musl-1.1.19/src/thread/pthread_setschedprio.c
 *
 */
int pthread_setschedprio(pthread_t t, int prio) { return 0;}



struct _pthread_cleanup_buffer
{
    void (*__routine)(void);
    void*                       __arg;
    int                         __canceltype;
    struct _pthread_cleanup_buffer*    __prev;
};

void _pthread_cleanup_push(struct _pthread_cleanup_buffer* buf, void (*function)(void), void* t) {}
void _pthread_cleanup_pop(struct _pthread_cleanup_buffer* buf, int t) {}



//void* mmap64(void* a, size_t b, int c, int d , int e, off_t f) {return 0;}


uint32_t htonl(uint32_t t) {return 0;}
uint32_t ntohl(uint32_t t) {return 0;}


/*
 * See implementation in musl: musl-1.1.19/src/signal/sigrtmin.c
 * and newlibc: newlib/libc/sys/linux/linuxthreads/pthread.c
 */
int __libc_current_sigrtmin() {}
int __libc_current_sigrtmax() {}


struct tls_index {
    ulong ti_module;
    ulong ti_offset;
};
void* __tls_get_addr(struct tls_index* ti) {return ti;}


//char* program_invocation_name;
#undef weak_alias
#define weak_alias(old, new) \
	extern __typeof(old) new __attribute__((weak, alias(#old)))
char *__progname=0, *__progname_full=0;

weak_alias(__progname, program_invocation_short_name);
weak_alias(__progname_full, program_invocation_name);

