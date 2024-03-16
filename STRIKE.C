#include "EVENTS.H"
#include "INPUT.H"
#include "MODEL.H"
#include "RENDERER.H"
#include <stdio.h>
#include <osbind.h>
#include "STRIKE.H"
#include "RANDOM.H"
#include "MUSIC.H"

UINT8 buff[32256];
Model model;
UINT32 duration = QUARTER_NOTE;

UINT8 *get_base(UINT8 *second_buffer){
    UINT8 *base;
    UINT16 difference;
    base = second_buffer;
    difference = (int)base;
    difference %= 0x100;
    difference = 0x100 - difference;
    return base + difference;
}


int main(){
    UINT8 *base1 = Physbase();
    UINT8 *base2 = get_base(buff);
    UINT8 *active_base = base1;
    UINT8 *inactive_base = base2;
    UINT8 prev_hor;
    UINT8 prev_ver;

    Model *model_ptr = &model;
    int old_lives = 3;
    int old_score = 0;
    int key;
    int collision;
    int collision2;
    PlayerShip *player = &(model_ptr->ship[PLAYER_ONE]);
    UINT32 timeThen,timeNow,timeElapsed;
    UINT32 seed = 0;
    init_model(model_ptr);
    random_formation(0);
    render(model_ptr, active_base);
    render(model_ptr, base2);
    timeThen = get_time();
    start_music();

    while(model_ptr->quit_game == FALSE){
        timeNow = get_time();
        timeElapsed = timeNow - timeThen;
        if (timeElapsed <= 3){ 
            if(Cconis())
            {
                seed++;
                key_request();
                model.shot_time++;
            }
        }
        else{
            update_music(duration);
            sync_event_check();
            /*printf("%d %d %d %d %d %d %d %d %d %d \n", model_ptr->enemies[0].prev_y,model_ptr->enemies[0].position.y, model_ptr->enemies[1].prev_y,model_ptr->enemies[1].position.y,model_ptr->enemies[2].prev_y,model_ptr->enemies[2].position.y,model_ptr->enemies[3].prev_y,model_ptr->enemies[3].position.y,model_ptr->enemies[4].prev_y,model_ptr->enemies[4].position.y);*/
            render_moveables(model_ptr, active_base);
            if (active_base == base1){
                active_base = base2;
                inactive_base = base1;
            }else{
                active_base = base1;
                inactive_base = base2;
            }
            check_snapshot(active_base);
            Setscreen(-1, active_base, -1);
            timeThen = timeNow;
            model.shot_time++;
            move_up_cancel(player);
            move_right_cancel(player);
            fire_main_cancel(player);
            
        }

    }
    if (base2 = active_base){
        Setscreen(-1, base1, -1);
    }
        set_volume(CHANNEL_A, 0);
    return 0;
}