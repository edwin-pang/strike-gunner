#ifndef PSG_H
#define PSG_H

#include "TYPES.H"

#define CHANNEL_A 0
#define CHANNEL_B 1
#define CHANNEL_C 2

#define CHANNEL_A_FINE 0x0
#define CHANNEL_B_FINE 0x2
#define CHANNEL_C_FINE 0x4

#define CHANNEL_A_ROUGH 0x1
#define CHANNEL_B_ROUGH 0x3
#define CHANNEL_C_ROUGH 0x5

#define CHANNEL_A_VOL 0x8
#define CHANNEL_B_VOL 0x9
#define CHANNEL_C_VOL 0xA

#define MIXER_REG 0x7
#define NOISE_REG 0x6
#define SHAPE_REG 0xD
#define ENVELOPE_FINE 0xB
#define ENVELOPE_ROUGH 0xC

#define IO_A_NOISEON_TONEON 0x36
#define IO_A_NOISEON_TONEOFF 0x37
#define IO_A_NOISEOFF_TONEON 0x3E
#define IO_A 0xF6
#define IO_A_TURN_NOISE_TONE 0x09
#define IO_A_TURN_NOISE 0x08
#define IO_A_TURN_TONE  0x01     

#define IO_B_NOISEON_TONEON 0x2D
#define IO_B_NOISEON_TONEOFF 0x2F
#define IO_B_NOISEOFF_TONEON 0x3D
#define IO_B 0xED
#define IO_B_TURN_NOISE_TONE 0x12
#define IO_B_TURN_NOISE 0x10
#define IO_B_TURN_TONE  0x02

#define IO_C_NOISEON_TONEON 0x1B
#define IO_C_NOISEON_TONEOFF 0x1F
#define IO_C_NOISEOFF_TONEON 0x3B
#define IO_C 0xDB
#define IO_C_TURN_NOISE_TONE 0x24
#define IO_C_TURN_NOISE 0x20
#define IO_C_TURN_TONE  0x04


#define FADE_OUT 0x00


#define ENVELOPE_FINE_REG 0xB
#define ENVELOPE_ROUGH_REG 0xC
#define ENVELOPE_SHAPE_REG 0xD

#define ENVELOPE_ROUGH_MASK 0xFF00
#define ENVELOPE_FINE_MASK 0x00FF

#define SHAPE_1 0x00

extern volatile char *PSG_reg_select = 0xFF8800;
extern volatile char *PSG_reg_write = 0xFF8802;

void write_psg(int reg, UINT8 val);
int read_psg(int reg);
void set_tone(int channel, int tuning);
void set_volume(int channel, int volume);
void enable_channel(int channel, int noise_on, int tone_on);
void stop_sound();
void set_noise(int tuning);
void set_envelope(int shape, UINT16 sustain);

#endif