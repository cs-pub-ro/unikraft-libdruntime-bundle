#include <sys/_sigset.h>
#include <sys/stat.h>
#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
#include <float.h>
#include <math.h>

FILE *_stdin;
FILE *_stdout;
FILE *_stderr;

void initStdIO() {
    _stdin = stdin;
    _stdout = stdout;
    _stderr = stderr;
}

int *__errno_location(void)
{
    return 0;
}


// from newlib/libc/include/sys/signal.h
typedef __sigset_t  sigset_t;
int sigfillset(sigset_t *set)
{
    return 0;
}

int sigdelset(sigset_t *set, int t)
{
    return 0;
}

int pthread_setschedprio(pthread_t t, int prio)
{
    return 0;
}

struct _pthread_cleanup_buffer {};
void _pthread_cleanup_push(struct _pthread_cleanup_buffer* buf, void (*function)(void), void* t) {}
void _pthread_cleanup_pop(struct _pthread_cleanup_buffer* buf, int t) {}


uint32_t htonl(uint32_t t)
{
    return 0;
}
uint32_t ntohl(uint32_t t)
{
    return 0;
}


/*
 * See implementation in musl: musl-1.1.19/src/signal/sigrtmin.c
 * and newlibc: newlib/libc/sys/linux/linuxthreads/pthread.c
 */
int __libc_current_sigrtmin()
{
    return 0;
}
int __libc_current_sigrtmax()
{
    return 0;
}


struct tls_index {};
void* __tls_get_addr(struct tls_index* ti)
{
    return ti;
}

//char* program_invocation_name;
#undef weak_alias
#define weak_alias(old, new) \
	extern __typeof(old) new __attribute__((weak, alias(#old)))
char *__progname=0, *__progname_full=0;

weak_alias(__progname, program_invocation_short_name);
weak_alias(__progname_full, program_invocation_name);

struct msghdr {};
struct cmsghdr {};
struct cmsghdr * __cmsg_nxthdr(struct msghdr *msg, struct cmsghdr *cmsg)
{
    return NULL;
}

