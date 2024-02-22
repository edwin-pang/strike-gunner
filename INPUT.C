#include <osbind.h>
#include "input.h"

UINT16 get_key(){
    int key;
    key = Cnecin();     /*return a key from the keyboard*/
    return key;
}

UINT32 get_time(){
    long old_ssp;
    long *timer = (long *)0x462;
    long timeNow;
    old_ssp = Super(0); /* enter privileged mode */
    timeNow = *timer;
    Super(old_ssp); /* exit privileged mode as soon as possible */
    return timeNow;
}

