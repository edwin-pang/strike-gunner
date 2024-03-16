#include <osbind.h>
#include "PSG.H"
#include "TYPES.H"
#include <stdio.h>
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
    int rough = tuning;
    int tune;
    if (tuning < TWELVE_BIT_MAX){
        rough >= 8;
        switch(channel){
            case CHANNEL_A:
                write_psg(CHANNEL_A_FINE, tuning);
                break;
            case CHANNEL_B:
                write_psg(CHANNEL_B_FINE, tuning);
                break;
            case CHANNEL_C:
                write_psg(CHANNEL_C_FINE, tuning);
                break;
            default:
                break;
        }
    }
}
void set_volume(int channel, int volume){
    if (volume < FIVE_BIT_MAX){
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
}

void enable_channel(int channel, int noise_on, int tone_on){
    UINT8 mixer_control;
     mixer_control = read_psg(MIXER_REG);

    switch (channel)
    {
    case CHANNEL_A:
        if (noise_on && tone_on){
            mixer_control = (mixer_control & IO_A) | IO_A_TURN_NOISE_TONE;
        }
        if (noise_on && !tone_on){
            mixer_control = (mixer_control & IO_A) | IO_A_TURN_NOISE;
        }
        if (!noise_on && tone_on){
            mixer_control = (mixer_control & IO_A) | IO_A_TURN_TONE;
        }
        break;
    case CHANNEL_B:
        if (noise_on && tone_on){
            mixer_control = (mixer_control & IO_B) | IO_B_TURN_NOISE_TONE;
        }
        if (noise_on && !tone_on){
            mixer_control = (mixer_control & IO_B) | IO_B_TURN_NOISE;
        }
        if (!noise_on && tone_on){
            mixer_control = (mixer_control & IO_B) | IO_B_TURN_TONE;
        }
        break;
    case CHANNEL_C:
        if (noise_on && tone_on){
            mixer_control = (mixer_control & IO_C) | IO_C_TURN_NOISE_TONE;
        }
        if (noise_on && !tone_on){
            mixer_control = (mixer_control & IO_C) | IO_C_TURN_NOISE;
        }
        if (!noise_on && tone_on){
            mixer_control = (mixer_control & IO_C) | IO_C_TURN_TONE;
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
    if (tuning < FIVE_BIT_MAX){
    write_psg(NOISE_REG, tuning);
    }
}


void set_envelope(int shape, UINT16 sustain){
    UINT16 rough = sustain;
    if(sustain < SIXTEEN_BIT_MAX){
        rough >= 8;
        write_psg(SHAPE_REG,shape);

        write_psg(ENVELOPE_FINE,sustain);
        write_psg(ENVELOPE_ROUGH,rough);
    }
}