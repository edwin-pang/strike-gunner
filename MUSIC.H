#ifndef MUSIC_H
#define MUSIC_H

#include "PSG.H"
#include "TYPES.H"

#define A5 0x07F
#define E5 0x0AA

#define A3 0x1FC
#define E3 0x2A7

#define SONG_SIZE

                            /*note: 1 beat = 32Hz = 0.45s*/
#define WHOLE_NOTE 128      /*4 beats (1 full bar)*/
#define HALF_NOTE 64        /*2 beats*/
#define QUARTER_NOTE 32     /*1 beats*/
#define EIGHTH_NOTE 16      /*1/2 beats*/
#define SIXTEENTH_NOTE 8    /*1/4 beats*/

typedef struct{
    UINT16 the_note;
    UINT16 sustain;
} Note;

void start_music();
void update_music(UINT32 time_elapsed);

#endif