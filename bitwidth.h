#include <stdint.h>
#if defined(__LP64__) || defined(_WIN64) || (defined(__x86_64__) && !defined(__ILP32__)) || defined(_M_X64) || defined(__ia64) || defined (_M_IA64) || defined(__aarch64__) || defined(__powerpc64__)
#define __64BIT__ 1
typedef uint64_t uintmax_t;
typedef int64_t intmax_t;
#elif defined(__LP32__) || defined(_WIN32) || (defined(__x86__) && defined(__ILP32__)) || defined(_M_X86) || defined(__ia32) || defined (_M_IA32) || defined(__aarch32__) || defined(__powerpc__) || defined(__GNUC__)
#define __32BIT__ 1
typedef uint32_t uintmax_t;
typedef int32_t intmax_t;
#else
#error "Unknown bitwidth or corrupted compiler. Stop."
#endif
