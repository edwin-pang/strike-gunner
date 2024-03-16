#ifndef EFFECTS_H
#define EFFECTS_H

#include "TYPES.H"
#include "PSG.H"
/*
=====================================================================================================================
purpose:  play an explosion sound through channel C

input:      
output:      Sound through channel C
assumptions: N/A
limitations: 
bugs:        boom music
=====================================================================================================================
*/
void play_explosion();
/*
=====================================================================================================================
purpose:  play an gunshot sound through channel B

input:      
output:      Sound through channel B
assumptions: N/A
limitations: 
bugs:        music gun
=====================================================================================================================
*/
void play_bullet();

#endif