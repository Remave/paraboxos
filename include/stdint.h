#ifndef _STDINT
#define _STDINT

#ifndef _PBRT_cmpl_prcs
#define _PBRT_cmpl_prcs
#define INTN(n) int##n##_t
#define UINTN(n) uint##n##_t
#endif

// SIGNED INTS
typedef signed char        int8_t;
typedef short              int16_t;
typedef int                int32_t;
typedef long long          int64_t;
// UNSIGNED INTS
typedef unsigned char      uint8_t;
typedef unsigned short     uint16_t;
typedef unsigned int       uint32_t;
typedef unsigned long long uint64_t;

#endif