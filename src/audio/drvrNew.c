#include "common.h"
#include <libaudio.h>
#include "synthInternals.h"
#include <os.h>
#include "initfx.h"


//#pragma GLOBAL_ASM("asm/nonmatchings/audio/drvrNew/alSaveNew.s")
void alSaveNew(ALSave* r) {
    alFilterNew(&r->filter, alSavePull, alSaveParam, 3);
    r->dramout = 0;
    r->first = 1;
}
//#pragma GLOBAL_ASM("asm/nonmatchings/audio/drvrNew/alMainBusNew.s")
void alMainBusNew(ALMainBus *m, void *sources, s32 maxSources)
{
    alFilterNew((ALFilter *) m, alMainBusPull, alMainBusParam, AL_MAINBUS);
    m->sourceCount = 0;
    m->maxSources = maxSources;
    m->sources = (ALFilter **)sources;
}

//#pragma GLOBAL_ASM("asm/nonmatchings/audio/drvrNew/alAuxBusNew.s")
void alAuxBusNew(ALAuxBus *m, void *sources, s32 maxSources)
{
    alFilterNew((ALFilter *) m, alAuxBusPull, alAuxBusParam, AL_AUXBUS);
    m->sourceCount = 0;
    m->maxSources = maxSources;
    m->sources = (ALFilter **)sources;
}

#pragma GLOBAL_ASM("asm/nonmatchings/audio/drvrNew/alResampleNew.s")


//#pragma GLOBAL_ASM("asm/nonmatchings/audio/drvrNew/alLoadNew.s")
void alLoadNew(ALLoadFilter *f, ALDMANew dmaNew, ALHeap *hp) 
{
    s32
        i;
    
    /*
     * init filter superclass
     */

    alFilterNew((ALFilter *) f, alAdpcmPull, alLoadParam, AL_ADPCM);

    f->state = alHeapAlloc(hp, 1, sizeof(ADPCM_STATE));
    f->lstate = alHeapAlloc(hp, 1, sizeof(ADPCM_STATE));
    
    f->dma = dmaNew(&f->dmaState);
    
    /*
     * init the adpcm state
     */
    f->lastsam = 0;
    f->first = 1;
    f->memin = 0;
}

#pragma GLOBAL_ASM("asm/nonmatchings/audio/drvrNew/alEnvmixerNew.s")

#pragma GLOBAL_ASM("asm/nonmatchings/audio/drvrNew/_init_lpfilter.s")

#pragma GLOBAL_ASM("asm/nonmatchings/audio/drvrNew/alFxNew.s")
