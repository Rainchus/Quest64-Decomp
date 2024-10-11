#ifndef _EL_MATH_H_
#define _EL_MATH_H_

#define SQ(x) ((x) * (x))

typedef struct unk_23df4_s //this struct probably doesn't exit. Every other function uses Mtx or MtxF
{
    f32 unk0;
    f32 unk4;
    f32 unk8;
    f32 unkC;
    f32 unk10;
    f32 unk14;
    f32 unk18;
    f32 unk1C;
    f32 unk20;
    f32 unk24;
    f32 unk28;
}unk23df4s;

typedef struct Coordinates2D_s{
    f32 x;
    f32 y;
}Coordinates2D;

extern u32 gRNG;
extern MtxF D_8008D030;

void func_80023A08(MtxF* arg0, f32 arg1, f32 arg2, f32 arg3);

#endif
