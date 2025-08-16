#include <libaudio.h>

//ALGlobals *alGlobals=0;

void alUnlink(ALLink *ln)			
{					
    if (ln->next)                   
        ln->next->prev = ln->prev;  
    if (ln->prev)                   
        ln->prev->next = ln->next;  
}
void alLink(ALLink *ln, ALLink *to)
{					
    ln->next = to->next;     
    ln->prev = to;           
    if (to->next)            
        to->next->prev = ln; 
    to->next = ln;           
}
void alClose(ALGlobals *glob)
{
    if (alGlobals) {
        func_8003FD40(&glob->drvr); //alSynDelete
        alGlobals = 0;
    }
}
void alInit(ALGlobals *g, ALSynConfig *c)
{
    if (!alGlobals) { /* already initialized? */
        alGlobals = g;
        func_80036D00(&alGlobals->drvr, c); //alSynNew
    }
}