#include "PR/os_internal.h"
#include "osint.h"
#include "PR/os_version.h"

// this is not supposed to be here, but the def check below is broken I guess.
#ifdef __sgi
#define __GNUC__ 0
#endif

void osDestroyThread(OSThread* t) {
    register u32 saveMask;
    register OSThread* pred;
    register OSThread* succ;

    saveMask = __osDisableInt();

    if (t == NULL) {
        t = __osRunningThread;
    } else if (t->state != OS_STATE_STOPPED) {
        __osDequeueThread(t->queue, t);
    }

    if (__osActiveQueue == t) {
        __osActiveQueue = __osActiveQueue->tlnext;
    } else {
        pred = __osActiveQueue;
        succ = pred->tlnext;
        while (succ != NULL) {
            if (succ == t) {
                pred->tlnext = t->tlnext;
                break;
            }
            pred = succ;
            succ = pred->tlnext;
        }
    }

    if (t == __osRunningThread) {
        __osDispatchThread();
    }

    __osRestoreInt(saveMask);
}
