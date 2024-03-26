#include "EVENTS.H"
#include "INPUT.H"
#include "MODEL.H"
#include "RENDERER.H"
#include <stdio.h>
#include <osbind.h>
#include "STRIKE.H"
#include "RANDOM.H"
#include "MUSIC.H"
#include "RASTER.H"
#include "ISR.H"
#include "IKBD.H"

UINT8 buff[32256];
Model model;
Model front;
Model back;
UINT8 *front_base;
UINT8 *back_base;
UINT8 *active_base;
UINT8 *inactive_base;
UINT8 key_buff[50];
UINT8 head = 0;
UINT8 rear = 0;

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
void menu(){
    active_base = (UINT8 *) get_video_base();
    run_menu(active_base);
    while (!Cconis()){

    }
    key_request();
}
void game(){
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
    Model* inactive_model;
    front_base = (UINT8 *) get_video_base();
    back_base = get_base(buff);
    active_base = front_base;
    inactive_base = back_base;
    init_model(model_ptr);
    init_model(&front);
    init_model(&back);
    random_formation(0);
    render(model_ptr, active_base);
    render(model_ptr, back_base);
    inactive_model = &back;
    timeThen = get_time();
    start_music();

    while(model_ptr->quit_game == FALSE){
        timeNow = get_time();
        timeElapsed = timeNow - timeThen;
        if(Cconis())
        {
            seed++;
            key_request();
            model.shot_time++;
        }
        if(timeElapsed >= 2){
            update_music(duration);
            sync_event_check();
            /*printf("%d %d %d %d %d %d %d %d %d %d \n", model_ptr->enemies[0].prev_y,model_ptr->enemies[0].position.y, model_ptr->enemies[1].prev_y,model_ptr->enemies[1].position.y,model_ptr->enemies[2].prev_y,model_ptr->enemies[2].position.y,model_ptr->enemies[3].prev_y,model_ptr->enemies[3].position.y,model_ptr->enemies[4].prev_y,model_ptr->enemies[4].position.y);*/
            /*check_snapshot(inactive_base);*/
            render_moveables(inactive_model, inactive_base);
            if (active_base == front_base){
                active_base = back_base;
                inactive_base = front_base;
                inactive_model = &front;
            }else{
                active_base = front_base;
                inactive_base = back_base;
                inactive_model = &back;
            }
            set_video_base_C((UINT16 *)active_base);
            timeThen = get_time();
            model.shot_time++;
            move_up_cancel(player);
            move_right_cancel(player);
            fire_main_cancel(player);
            
        }
    }

    if (back_base = active_base){
        set_video_base_C((UINT16 *)front_base);
    }
        set_volume(CHANNEL_A, 0);
}
int main(){
    Vector orig_vector = install_vector(IKBD_ISR, ikbd_isr);
    menu();
    game();
    install_vector(IKBD_ISR, orig_vector);
    return 0;
}