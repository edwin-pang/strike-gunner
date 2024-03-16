#ifndef MUSIC_H
#define MUSIC_H

#include "PSG.H"
#include "TYPES.H"

#define E3 0x2A7
#define G3 0x23B
#define B3 0x1C5
#define D3 0x2FA
#define F3 0x281
#define A3 0x1FC
#define C3 0x357

#define E4 0x153
#define G4 0x11D
#define B4 0x0E2
#define D4 0x17D
#define F4 0x140
#define A4 0x0FE
#define C4 0x1AC

                            /*note: 1 beat = 32Hz = 0.45s*/
#define WHOLE_NOTE 128      /*4 beats (1 full bar)*/
#define HALF_NOTE 64        /*2 beats*/
#define QUARTER_NOTE 32     /*1 beat*/
#define EIGHTH_NOTE 16      /*1/2 beat*/
#define SIXTEENTH_NOTE 8    /*1/4 beat*/

typedef struct{
    UINT16 the_note;
    UINT16 sustain;
} Note;

/*
=====================================================================================================================
purpose:  Begin the music track

input:      
output:      first note through channel A
assumptions: N/A
limitations: 
bugs:        boom music
=====================================================================================================================
*/
void start_music();
/*
=====================================================================================================================
purpose:  Update music when ready

input:      
output:      potentially start a note through channel A
assumptions: N/A
limitations: 
bugs:        boom music
=====================================================================================================================
*/
void update_music(UINT32 time_elapsed);

#endif