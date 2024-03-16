#include "MUSIC.H"
#include "TST_MUS.H"

const Note song[] = {
    {A3, QUARTER_NOTE},
    {G4, QUARTER_NOTE},
    {F3, QUARTER_NOTE},
    {C3, QUARTER_NOTE},
    {C3, QUARTER_NOTE},
    {F4, QUARTER_NOTE},
    {G4, QUARTER_NOTE},
    {F4, QUARTER_NOTE},
    {G4, QUARTER_NOTE},
    {F4, QUARTER_NOTE},
    {C3, QUARTER_NOTE},
    {C4, QUARTER_NOTE},
    {C4, QUARTER_NOTE},
    {C3, QUARTER_NOTE},
    {A4, QUARTER_NOTE},
    {G4, QUARTER_NOTE}
};

int SONG_SZ = sizeof(song) / sizeof(song[0]);
static int current_note = 0;

void start_music(){
    set_envelope(0x00, song[current_note].sustain);
    set_tone(CHANNEL_A, song[current_note].the_note);
    enable_channel(CHANNEL_A, TRUE, FALSE);
    set_volume(CHANNEL_A, 0x10);
}

void update_music(UINT32 time_elapsed) {

    if(duration == 0){
        set_noise(0x00);
        set_volume(CHANNEL_C, 0x00);
        set_volume(CHANNEL_B, 0x00);
        duration = song[current_note].sustain;
        current_note = (current_note == SONG_SZ - 1) ? 0 : current_note + 1;
        set_envelope(0x00, song[current_note].sustain);
        set_tone(CHANNEL_A, song[current_note].the_note);
    }else if(time_elapsed >= 0){
        duration -=1;
    }
}

