#include "EFFECTS.H"
#include "PSG.H"
void play_explosion(){
    enable_channel(CHANNEL_C, FALSE, TRUE);
    set_volume(CHANNEL_C, 0x10);
    set_noise(0x1F);
    set_envelope(0x00,0x0038);
    set_volume(CHANNEL_C, 0);
}

void play_bullet(){
    enable_channel(CHANNEL_B, FALSE, TRUE);
    set_volume(CHANNEL_B, 0x10);
    set_noise(0x0F);
    set_envelope(0x00,0x0010);
    set_volume(CHANNEL_B, 0);
}
