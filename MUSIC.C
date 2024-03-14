#include "MUSIC.H"

const Note song[] = {
    {E3, QUARTER_NOTE},
    {A3, QUARTER_NOTE},
    {E3, QUARTER_NOTE},
    {A3, QUARTER_NOTE},
    {E3, QUARTER_NOTE},
    {A3, QUARTER_NOTE},
    {E3, QUARTER_NOTE},
    {A3, QUARTER_NOTE},
    {E3, QUARTER_NOTE},
    {A3, QUARTER_NOTE},
    {E3, QUARTER_NOTE},
    {A3, QUARTER_NOTE},
    {E3, QUARTER_NOTE},
    {A3, QUARTER_NOTE}
};


int SONG_SZ = sizeof(song) / sizeof(song[0]);
int current_note = 0;

void start_music(){
    write_psg(MIXER_REG, song[current_note].the_note);
    enable_channel(CHANNEL_A, TRUE, FALSE);
    set_volume(CHANNEL_A, 0x0F);
}

void update_music(UINT32 time_elapsed) {
    static int time = 0;
    if (time_elapsed > time){
        current_note = (current_note >= SONG_SIZE - 1) ? 0 : current_note + 1;
        set_tone(CHANNEL_A, song[current_note].the_note);
    }
}

