#include "EVENTS.H"
#include "INPUT.H"
#include "MODEL.H"
#include "RENDERER.H"
#include <stdio.h>
#include <osbind.h>

char buff[32256];

char *get_base(char *second_buffer){
    char *base;
    UINT16 difference;
    base = second_buffer;
    difference = (int)base;
    difference %= 0x100;
    difference = 0x100 - difference;
    return base + difference;
}


int main(){
    char *base1 = Physbase();
    char *base2 = get_base(buff);
    char *active_base = base1;

    Model model;
    Model *model_ptr = &model;
    int old_lives = 3;
    int old_score = 0;
    int key;
    int collision;
    int collision2;
    PlayerShip *player = &(model_ptr->ship[PLAYER_ONE]);
    UINT32 timeThen,timeNow,timeElapsed;
    init_model(model_ptr);

    render(model_ptr, active_base);
    timeThen = get_time();
    while(model_ptr->quit_game == FALSE){
        timeNow = get_time();
        timeElapsed = timeNow - timeThen;
        if (timeElapsed <= 4){ 
            if(Cconis())
            {
                key = get_key();

                if(key == 'w'){
                    move_up_request(player);
                }
                else if(key == 's'){
                    move_down_request(player);
                }
                else if(key == 'a'){
                    move_left_request(player);        
                }   
                else if(key == 'd'){
                    move_right_request(player);
                }
                else if(key == 'x'){
                    fire_main_request(player);
                }
                else if (key == ESC_KEY){
                    model_ptr->quit_game = TRUE;
                }

            }
        }
        else{
            move_all(model_ptr);
            shoot_bullets(model_ptr);
            check_collisions(model_ptr);
            destroy_all(model_ptr);

            move_up_cancel(player);
            move_right_cancel(player);
            fire_main_cancel(player);

            if (active_base == base1){
                active_base = base2;
            }else{
                active_base = base1;
            }
            
            render(model_ptr, active_base);
            Setscreen(-1, active_base, -1);

            timeThen = timeNow;
        }

    }
    return 0;
}