#ifndef INPUT_H
#define INPUT_H
#include "types.h"
/*
=====================================================================================================================
purpose:  grabs the current key thats been read in by the keyboard

input:      
output:         key - contains key press information
assumptions: N/A
limitations: can only take in the information of one key currently
bugs:        N/A
=====================================================================================================================
*/
UINT16 get_key();
/*
=====================================================================================================================
purpose:        get the current time from the clock

input:      
output:         time    -   current time value
assumptions: N/A
limitations: N/A
bugs:        N/A
=====================================================================================================================
*/
UINT32 get_time();



#endif