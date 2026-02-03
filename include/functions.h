#ifndef _FUNCTIONS_H_
#define _FUNCTIONS_H_

#include "ultra64.h"
#include "common_structs.h"

float sqrtf(float);

void func_80023570(MtxF *arg0, f32 arg1, f32 arg2, f32 arg3);
void func_8002371C(MtxF *arg0, f32 arg1, f32 arg2, f32 arg3, f32 arg4, f32 arg5, f32 arg6);
void func_80023DF4(MtxF *arg0, f32 arg1, f32 arg2, f32 arg3);
void func_80035510(float m[4][4], float n[4][4], float r[4][4]); //guMtxCatF
void func_80023A08(MtxF*, f32, f32, f32); 
void func_8001B448(u8, u8*, u8, u8, s32, s32);
void func_80026A04(void);
u8 func_80026554(u8);
void func_80026658(void);
s32 func_8002543C(s32);
void func_800253F0(s32);
void func_80025B8C(s32 arg0, s32 arg1, s32 arg2); //not from this file
void func_800307D8(s32 arg0, s32 arg1, s32 arg2, s32 arg3, s32 arg4); //not from this file
void func_80030EA0(s32 arg0, s32 arg1, u8 *arg2); //not from this file
s32 count_digits(s32 value, u8 *str_ptr, u16 flags);
void func_80031CF0(u16 arg0, u8* arg1);
void func_80031DD4(s32 arg0);
void func_80031F1C(s16 arg0, s16 arg1);
void func_80031F74(u8* arg0);
void func_80031FBC(u8*, s32);

#endif //_FUNCTIONS_H_
