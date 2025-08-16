#include "common.h"
#include "synthInternals.h"

void func_80036920(void) {
}

//#pragma GLOBAL_ASM("asm/nonmatchings/audio/synthesizer/func_80036928.s")
s32 func_80036928(ALSynth* synth, s32 micros) {
    f32 tmp = ((f32)micros) * synth->outputRate / 1000000.0 + 0.5;
    return (s32)tmp & ~0xF;
}

//#pragma GLOBAL_ASM("asm/nonmatchings/audio/synthesizer/func_80036980.s")
void func_80036980(ALSynth *drvr, PVoice *pvoice) 
{
    alUnlink((ALLink *)pvoice);
    alLink((ALLink *)pvoice, &drvr->pLameList);
}

//#pragma GLOBAL_ASM("asm/nonmatchings/audio/synthesizer/func_800369B8.s")
void func_800369B8(ALSynth *drvr) 
{
    ALLink       *dl;
    PVoice      *pv;

    while ((dl = drvr->pLameList.next) != 0) {
        pv = (PVoice *)dl;

        /* ### remove from mixer */

        alUnlink(dl);
        alLink(dl, &drvr->pFreeList);        
    }
}

//#pragma GLOBAL_ASM("asm/nonmatchings/audio/synthesizer/func_80036A18.s")
void func_80036A18(ALParam *param) 
{
    ALSynth *drvr = &alGlobals->drvr;
    param->next = drvr->paramList;
    drvr->paramList = param;
}

//#pragma GLOBAL_ASM("asm/nonmatchings/audio/synthesizer/func_80036A30.s")
ALParam *func_80036A30() 
{
    ALParam *update = 0;
    ALSynth *drvr = &alGlobals->drvr;

    if (drvr->paramList) {        
        update = drvr->paramList;
        drvr->paramList = drvr->paramList->next;
        update->next = 0;
    }
    return update;
}

void func_80036A60(void) {
}

#pragma GLOBAL_ASM("asm/nonmatchings/audio/synthesizer/func_80036A68.s")

#pragma GLOBAL_ASM("asm/nonmatchings/audio/synthesizer/func_80036D00.s")
