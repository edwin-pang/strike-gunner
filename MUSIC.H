#ifndef MUSIC_H
#define MUSIC_H

#include "PSG.H"
#include "TYPES.H"

#define E1 0xA9B
#define G1 0x8EB
#define B1 0x714
#define D1 0xBE7
#define F1 0xA02
#define A1 0x7F2
#define C1 0xD5D

#define E2 0x54D
#define G2 0x475
#define B2 0x38A
#define D2 0x5F4
#define F2 0x501
#define A2 0x3F9
#define C2 0x6AE

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

#define E7 0x02A
#define G7 0x024
#define B7 0x01C
#define D7 0x030
#define F7 0x028
#define A7 0x020
#define C7 0x035

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
void update_music();

#endif