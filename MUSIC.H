#ifndef MUSIC_H
#define MUSIC_H
#include "TYPES.H"

typedef struct{
    UINT16 the_note;
    UINT16 sustain;
} Note;

void start_music();
void update_music(UINT32 time_elapsed);

#endif