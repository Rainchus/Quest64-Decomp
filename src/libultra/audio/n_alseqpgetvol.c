#include <PR/libaudio.h>
#include <PR/n_libaudio.h>


s16 n_alSeqpGetVol(N_ALSeqPlayer *seqp)
{
    return seqp->vol;
}

