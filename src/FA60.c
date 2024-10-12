#include "common.h"

#pragma GLOBAL_ASM("asm/nonmatchings/FA60/func_8000EE60.s")

#pragma GLOBAL_ASM("asm/nonmatchings/FA60/func_8000F0BC.s")

#pragma GLOBAL_ASM("asm/nonmatchings/FA60/func_8000F238.s")

//#pragma GLOBAL_ASM("asm/nonmatchings/FA60/func_8000F5A4.s")
s32 func_8000F5A4(f32 arg0, f32 arg1, f32 arg2, f32 arg3, f32 arg4, f32 arg5) {
    if (((arg3 <= arg1) && (arg1 < arg5)) || ((arg5 <= arg1) && (arg1 < arg3))) {
        if ((arg2 <= arg0) && (arg4 < arg0)) {
            return 1;
        }
        if ((arg0 <= arg2) && (arg0 < arg4)) {
            return 0;
        }
        if ((arg3 != arg5) && ((((arg1 - arg3) * ((arg2 - arg4) / (arg3 - arg5))) + arg2) < arg0)) {
            return 1;
        }
    }
    return 0;
}

#pragma GLOBAL_ASM("asm/nonmatchings/FA60/func_8000F6A4.s")

#pragma GLOBAL_ASM("asm/nonmatchings/FA60/func_8000FCBC.s")

#pragma GLOBAL_ASM("asm/nonmatchings/FA60/func_8000FDE0.s")

//#pragma GLOBAL_ASM("asm/nonmatchings/FA60/func_8000FF54.s")
s32 func_8000FF54(f32 arg0)
{
  if (M_PI < arg0)
  {
    arg0 -= M_PI * 2;
  }
  else
    if (arg0 < -M_PI)
  {
    arg0 += M_PI * 2;
  }
  if (arg0 < 0.0f)
  {
    arg0 = -arg0;
  } 
  return arg0 < M_PI / 8; //arg0 < 22.5° in radians. 
}

#pragma GLOBAL_ASM("asm/nonmatchings/FA60/func_8000FFE8.s")
