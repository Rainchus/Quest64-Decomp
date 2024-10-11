#ifndef _COMMON_H_
#define _COMMON_H_

#include "ultra64.h"

//until I can use proper n64 libs
typedef u8 Addr[];
typedef unsigned short uint16_t;
typedef uint16_t  qu102_t;
#define qu102(n)                      ((qu102_t)((n)*0x0004))
float _nsqrtf(float);

#include "common_structs.h"

#endif

