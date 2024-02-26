#include "EVENTS.H"
#include "INPUT.H"
#include "MODEL.H"
#include "RENDERER.H"
#include <stdio.h>




int main(){
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

    render(model_ptr);
    timeThen = get_time();
    while(model_ptr->quit_game == FALSE){
        timeNow = get_time();
        timeElapsed = timeNow - timeThen;
        if (timeElapsed <= 5){ 
            key = get_key();
            if(key)
            {
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

            render(model_ptr);
            timeThen = timeNow;
        }

    }
    return 0;
}