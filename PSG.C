#include <osbind.h>
#include "PSG.H"
#include "TYPES.H"

void write_psg(int reg, UINT8 val){
    long old_ssp;

    if (reg >= 0 && reg <= 15 ){
        old_ssp = Super(0);

        *PSG_reg_select = reg;
        *PSG_reg_write = val;

        Super(old_ssp);
    }
}

int read_psg(int reg){
    long old_ssp;
    int val = -1;

    if (reg >= 0 && reg <= 15){
        old_ssp = Super(0);

        *PSG_reg_select = reg;
        val = *PSG_reg_select;

        Super(old_ssp);
    }

    return val;
}

void set_tone(int channel, int tuning){
    int fine_tune = tuning * 0x00FF;
    int rough_tune = tuning * 0x00F0;

    switch(channel){
        case CHANNEL_A:
            write_psg(CHANNEL_A_FINE, fine_tune);
            write_psg(CHANNEL_A_ROUGH, rough_tune);
            break;
        case CHANNEL_B:
            write_psg(CHANNEL_B_FINE, fine_tune);
            write_psg(CHANNEL_B_ROUGH, rough_tune);
            break;
        case CHANNEL_C:
            write_psg(CHANNEL_C_FINE, fine_tune);
            write_psg(CHANNEL_C_ROUGH, rough_tune);
            break;
        default:
            break;
    }
}

void set_volume(int channel, int volume){
    switch (channel)
    {
    case CHANNEL_A:
        write_psg(CHANNEL_A_VOL, volume);
        break;
    case CHANNEL_B:
        write_psg(CHANNEL_B_VOL, volume);
        break;
    case CHANNEL_C:
        write_psg(CHANNEL_C_VOL, volume);
    default:
        break;
    }
}

void enable_channel(int channel, int noise_on, int tone_on){
    UINT8 mixer_control;
    mixer_control = read_psg(MIXER_REG);

    switch (channel)
    {
    case CHANNEL_A:
        if (noise_on && tone_on){
            mixer_control = mixer_control & IO_A_NOISEON_TONEON;
        }
        if (noise_on && !tone_on){
            mixer_control = mixer_control & IO_A_NOISEON_TONEOFF;
        }
        if (!noise_on && tone_on){
            mixer_control = mixer_control & IO_A_NOISEOFF_TONEON;
        }
        break;
    case CHANNEL_B:
        if (noise_on && tone_on){
            mixer_control = mixer_control & IO_B_NOISEON_TONEON;
        }
        if (noise_on && !tone_on){
            mixer_control = mixer_control & IO_B_NOISEON_TONEOFF;
        }
        if (!noise_on && tone_on){
            mixer_control = mixer_control & IO_B_NOISEOFF_TONEON;
        }
        break;
    case CHANNEL_C:
        if (noise_on && tone_on){
            mixer_control = mixer_control & IO_C_NOISEON_TONEON;
        }
        if (noise_on && !tone_on){
            mixer_control = mixer_control & IO_C_NOISEON_TONEOFF;
        }
        if (!noise_on && tone_on){
            mixer_control = mixer_control & IO_C_NOISEOFF_TONEON;
        }
        break;
    default:
        break;
    }

    write_psg(MIXER_REG, mixer_control);
}

void stop_sound(){
    write_psg(CHANNEL_A_VOL, 0);
    write_psg(CHANNEL_B_VOL, 0);
    write_psg(CHANNEL_C_VOL, 0);
}

void set_noise(int tuning){
    write_psg(NOISE_REG, tuning);
}

void set_envelope(int shape, unsigned int sustain){
    write_psg(ENVELOPE_SHAPE_REG, shape);
    write_psg(ENVELOPE_FINE_REG, sustain);
}