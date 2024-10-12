#include "common.h"
#include "1BCD0.h"

//#pragma GLOBAL_ASM("asm/nonmatchings/1BCD0/func_8001B0D0.s")
void func_8001B0D0(void) {
    s32 var_v1;
    Dust* var_v0;

    var_v0 = D_80088428;
    var_v1 = 0x100;
    while (var_v1 > 0) {
        var_v0->unk0 = 0;
        var_v0++;
        var_v1--;
    }
    gNumDustParticlesToSpawn = 0;
}


//#pragma GLOBAL_ASM("asm/nonmatchings/1BCD0/func_8001B108.s")
Dust* func_8001B108(Dust* arg0) {
    Dust* ret = D_80088428;
    u32 i = 0x100;

    while((i > 0) && (ret->unk0 != 0)){
        i--;
        ret++;
    }

    if (i != 0) {
        *ret = *arg0;
        gNumDustParticlesToSpawn++;
    } else {
        ret = NULL;
    }
    return ret;
}

#pragma GLOBAL_ASM("asm/nonmatchings/1BCD0/func_8001B19C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/1BCD0/func_8001B448.s")
