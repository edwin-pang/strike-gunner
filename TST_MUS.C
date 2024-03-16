#include "MUSIC.H"
#include "INPUT.H"
#include <osbind.h>
#include <stdio.h>

UINT32 duration = 32;

int main(){
    UINT32 timeThen, timeNow, timeElapsed;

    timeThen = get_time();
    start_music();

    while(!Cconis()){
        timeNow = get_time();
        timeElapsed = timeNow - timeThen;
        if(timeElapsed >= 1){
            update_music(duration);
            timeThen = timeNow;
        }
    }

    set_volume(CHANNEL_A, 0);
    Cnecin();
    return 0;
}