#include "EFFECTS.H"

void play_explosion(){
    set_tone(CHANNEL_A, 1);
    enable_channel(CHANNEL_A, TRUE, FALSE);
    set_volume(CHANNEL_A, 10);
    set_noise(0x1F);
}