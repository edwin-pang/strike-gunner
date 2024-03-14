#include "MUSIC.H"
#include "INPUT.H"
#include <osbind.h>

int main(){
    UINT32 timeThen, timeNow, timeElapsed;

    timeThen = get_time();
    start_music();

    while(!Cconis()){
        timeNow = get_time();
        timeElapsed = timeNow - timeThen;
        update_music(timeElapsed);
    }

    set_volume(CHANNEL_A, 0);
    Cnecin();
    return 0;
}