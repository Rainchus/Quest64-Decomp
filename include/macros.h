#ifndef __MACROS_H__
#define __MACROS_H__

#define ALIGNED(x) __attribute__((aligned(x)))

#define ARRLEN(x) ((s32)(sizeof(x) / sizeof(x[0])))

#define STUBBED_PRINTF(x) ((void)(x))

#define UNUSED __attribute__((unused))

#ifndef __GNUC__
#define __attribute__(x)
#endif

#define UNK_SIZE_0 0x20
#define UNK_SIZE_1 0x10
#define INVENTORY_SIZE 151
#define UNK_SIZE_2 1

#ifdef OLD_GCC
#define VLA 0
#else
#define VLA
#endif

#ifdef M2CTX
#define VLA 0
#endif

#endif
