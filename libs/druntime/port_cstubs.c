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

/*
 * math.d
 */
int __fpclassify(double x)
{
    if (x <= FLT_MAX)
        return __fpclassifyf((float)x);
    return 0;
}

int __fpclassifyl(long double x)
{
    if (x <= FLT_MAX)
        return __fpclassifyf((float)x);
    return 0;
}

int __isinf(double x)
{
    if (x <= FLT_MAX)
        return __isinff((float)x);
    return 0;
}

int __isinfl(long double x)
{
    if (x <= FLT_MAX)
        return __isinff((float)x);
    return 0;
}

int __isnan(double x)
{
    if (x <= FLT_MAX)
        return __isnanf((float)x);
    return 0;
}

int __isnanl(long double x)
{
    if (x <= FLT_MAX)
        return __isnanf((float)x);
    return 0;
}

int __signbit(double x)
{
    if (x <= FLT_MAX)
        return __signbitf((float)x);
    return 0;
}

int __signbitl(long double x)
{
    if (x <= FLT_MAX)
        return __signbitf((float)x);
    return 0;
}

int __finite(double x)
{
    return 0;
}

int __finitel(long double x)
{
    return 0;
}

int __finitef(float x)
{
    return 0;
}

long lroundl(long double x)
{
    if (x <= DBL_MAX)
        return lround((double)x);
    return 0;
}

long double roundl(long double x)
{
    if (x <= DBL_MAX)
        return round((double)x);
    return 0;
}

long double logbl(long double x)
{
    if (x <= DBL_MAX)
        return logb((double)x);
    return 0;
}

long double modfl(long double value, long double *iptr)
{
    return modf((double)value, (double *)iptr);
}

long double scalbnl(long double x, int n)
{
    if (x <= DBL_MAX)
        return scalbn((double)x, n);
    return 0;
}


long double cbrtl(long double x)
{
    if (x <= DBL_MAX)
        return cbrt((double)x);
    return 0;
}

long double nearbyintl(long double x)
{
    if (x <= DBL_MAX)
        return nearbyint((double)x);
    return 0;
}

long double remainderl(long double x, long double y)
{
    if (x <= DBL_MAX && y <= DBL_MAX)
        return remainder((double)x, (double)y);
    return 0;
}

long double remquol(long double x, long double y, int *quo)
{
    if (x <= DBL_MAX && y <= DBL_MAX)
        return remquo((double)x, (double)y, quo);
    return 0;
}

