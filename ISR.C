#include "ISR.H"
#include <osbind.h>
#include "strike.h"
#include "MUSIC.H"
#include "PSG.H"
void new_vb_isr_c(){
    update_music()

}

Vector install_vector(int num, Vector vector){
    Vector orig;
    Vector *vectp = (Vector *)((long)num << 2);
    long old_ssp = Super(0);
    orig = *vectp;
    *vectp = vector;
    Super(old_ssp);
    return orig;
}
