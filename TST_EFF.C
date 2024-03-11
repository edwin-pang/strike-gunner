#include "EFFECTS.H"
#include "PSG.H"
#include <osbind.h>


int main(){
    play_explosion();
    while (!Cconis())
        ;
    set_volume(CHANNEL_A, 0);
    Cnecin();
    return 0;
}