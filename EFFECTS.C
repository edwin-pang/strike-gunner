#include "EFFECTS.H"
#include <osbind.h>

void play_explosion(){
    set_tone(CHANNEL_A, 1);
    enable_channel(CHANNEL_A, TRUE, TRUE);
    set_volume(CHANNEL_A, 10);
    set_noise(0x1F);
    set_envelope(SHAPE_1, 0x3800);

    /*long old_ssp = Super(0);

    *PSG_reg_select = 6;
    *PSG_reg_write = 0x1F;

    *PSG_reg_select = 7;
    *PSG_reg_write = 0x07;

    *PSG_reg_select = 8;
    *PSG_reg_write = 0x10;

    *PSG_reg_select = 9;
    *PSG_reg_write = 0x10;

    *PSG_reg_select = 10;
    *PSG_reg_write = 0x10;

    *PSG_reg_select = 12;
    *PSG_reg_write = 0x38;

    *PSG_reg_select = 13;
    *PSG_reg_write = 0x00;

    Super(old_ssp);*/
}