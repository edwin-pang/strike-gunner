#include "RENDERER.H"
#include "RASTER.H"
#include <osbind.h>
#include "bitmap.c"
#include "font.c"
#include <stdio.h>
#include "STRIKE.H"

void render_clear(){
    void *base = Physbase();
    clear_screen(base);
}
void render_score(Model *model, UINT8 *base){
    int divisor = 10000;
    UINT16 score = model->score.total;
    int subtractor = 0;
    char num[5];
    int index = NUMS;
    int i = 0;
    int x = model->score.position.x;
    int y = model->score.position.y; 
    while (i < 5){
        num[i] = (score - subtractor) / divisor;
        subtractor += num[i] * divisor;
        divisor /= 10;
        i++;
    }
    i = 0;
    index += (num[i] << 3);
    while (i < 5) {
    plot_bitmap_8(base,x,y,font + index, FONT_HEIGHT);
    x += 12;
    i++;
    index = NUMS + (num[i] << 3);
    }
    }

void render_life_counter(Model *model, UINT8 *base){
    UINT8 lives = model->lives.health_bar;
    int index = NUMS + (lives << 3);

    int letter_l = LETTERS + (11 << 3);
    int letter_i = LETTERS + (8 << 3);
    int letter_v = LETTERS + (21 << 3);
    int letter_e = LETTERS + (4 << 3);
    int letter_s = LETTERS + (18 << 3);
    int colon = NUMS + (10 << 3);

    int x = model->lives.position.x;
    int y = model->lives.position.y;

    plot_bitmap_8(base, x, y, font + letter_l, FONT_HEIGHT);
    plot_bitmap_8(base, x + 10, y, font + letter_i, FONT_HEIGHT);
    plot_bitmap_8(base, x + 20, y, font + letter_v, FONT_HEIGHT);
    plot_bitmap_8(base, x + 30, y, font + letter_e, FONT_HEIGHT);
    plot_bitmap_8(base, x + 40, y, font + letter_s, FONT_HEIGHT);
    plot_bitmap_8(base, x + 49, y, font + colon, FONT_HEIGHT);
    plot_bitmap_8(base, x + 60, y, font + index, FONT_HEIGHT);


}

void render_panel_left(UINT32 *base){
    plot_vertical_line(base,96,0,400,0);
    plot_vertical_line(base,97,0,400,0);
    plot_vertical_line(base,98,0,400,0);
    plot_vertical_line(base,99,0,400,0);
    plot_vertical_line(base,100,0,400,0);

}
void render_panel_right(UINT32 *base){
    plot_vertical_line(base,540,0,400,0);
    plot_vertical_line(base,541,0,400,0);
    plot_vertical_line(base,542,0,400,0);
    plot_vertical_line(base,543,0,400,0);
    plot_vertical_line(base,544,0,400,0);

}

void render_all_32(Model *model, UINT32 *base) {
    int i = 0;
     while (i < NUM_BULLET && model->playerBullets[i].position.x != 0) {
        if (model->playerBullets[i].position.x == 1)
            ;
        else if(model->playerBullets[i].collision == 1)
            clear_part(base,model->playerBullets[i].prev_x,model->playerBullets[i].prev_y,SHIP_WIDTH,PLAYER_BULLET_HEIGHT);
        else{
            
            plot_bitmap_32(base,model->playerBullets[i].position.x,model->playerBullets[i].position.y,player_bullet_hex, PLAYER_BULLET_HEIGHT);
        }
        i++;
    }
    i = 0;
    while (i < NUM_PLAYER && model->ship[i].position.x != 0) {
        if (model->ship[i].hor_dir != 0 || model->ship[i].ver_dir != 0){
            if(model->ship[i].position.x != model->ship[i].prev_x || model->ship[i].position.y != model->ship[i].prev_y)
                clear_part(base,model->ship[i].prev_x,model->ship[i].prev_y,SHIP_WIDTH,SHIP_HEIGHT);

        plot_bitmap_32(base,model->ship[i].position.x,model->ship[i].position.y,player_ship, SHIP_HEIGHT);
        i++;
        }
        else {
        i++;
        }
    }
    render_enemies(model,base);
}
void render_enemies(Model *model, UINT32 *base){
    int i = 0;
    while (i < NUM_ENEMY && model->enemies[i].position.x != 0) {
        if ((model->enemies[i].hor_dir == 0 && model->enemies[i].ver_dir == 0) || model->enemies[i].position.x == 1){
            i++;
        }
        else{
             if(model->enemies[i].position.x != model->enemies[i].prev_x || model->enemies[i].position.y != model->enemies[i].prev_y)
                clear_part(base,model->enemies[i].prev_x,model->enemies[i].prev_y,SHIP_WIDTH,SHIP_HEIGHT);
            if (model->enemies[i].type == 1)
                plot_bitmap_32(base,model->enemies[i].position.x,model->enemies[i].position.y, helicopter, SHIP_HEIGHT);
            else
                plot_bitmap_32(base,model->enemies[i].position.x,model->enemies[i].position.y, jet, SHIP_HEIGHT);                
            i++;
        }
    }
   /* i = 0;
    while (i < NUM_ENEMY && model->jets[i].position.x != 0) {
        if (model->jets[i].hor_dir == 0 && model->jets[i].ver_dir == 0){
            i++;
        }
        else{
        plot_bitmap_32(base,model->jets[i].position.x +(model->jets[i].hor_dir * model->jets[i].speed), model->jets[i].position.y + (model->jets[i].ver_dir * model->jets[i].speed), empty_32, SHIP_HEIGHT );
        plot_bitmap_32(base,model->jets[i].position.x,model->jets[i].position.y, jet, SHIP_HEIGHT);
        i++;
    }
    }*/
}

void render_all_8(Model *model, UINT8 *base) {
     int i = 0;
     while (i < NUM_BULLET && model->bullets[i].position.x != 0) {
         if (model->bullets[i].position.x == 1){
            i++;
        }
        else{
            plot_bitmap_8(base,model->bullets[i].position.x,model->bullets[i].position.y - model->bullets->speed,empty_8, BULLET_HEIGHT);
            plot_bitmap_8(base,model->bullets[i].position.x,model->bullets[i].position.y,heli_bullet_bitmap, BULLET_HEIGHT);
            i++;
        }
    }
}
void render_all_16(Model *model, UINT16 *base) {
    if (model->powerup.position.x != 0){
        plot_bitmap_16(base,model->powerup.position.x,model->powerup.position.y,powerup, POWER_UP_HEIGHT);
    }
}
void render(Model *model, UINT8 *base){
    /*void *base = Physbase();*/
    clear_screen(base);         /*clear entire screen*/
    plot_bitmap_32((UINT32 *)base,model->ship[0].position.x,model->ship[0].position.y,player_ship, SHIP_HEIGHT); /*rasterize all 32 bitmaps that should be on screen */
    render_all_32(model,(UINT32 *) base);

    render_all_16(model,(UINT16 *) base);/*rasterize all 16 bitmaps to screen*/
    render_all_8(model, base); /*rasterize all 8 bitmaps to screen*/

    render_panel_left((UINT32*)base);
    render_panel_right((UINT32*)base);
    render_score(model,base);
    render_life_counter(model,base);
}
void render_moveables(Model *model, UINT8 *base){
    render_all_32(model,(UINT32*) base);/*rasterize all 32 bitmaps that should be on screen */

    render_all_16(model,(UINT16*) base);/*rasterize all 16 bitmaps to screen*/
    render_all_8(model, (UINT8 *)base); /*rasterize all 8 bitmaps to screen*/
}

void clear_moveables(Model *model){
 
}
void clear_32(UINT16 height, UINT16 x, UINT16 y, UINT8 hor_dir, UINT8 Ver_dir){
    
}

void clear_score(Model *model){

}

void clear_lives(Model *model){

}


void check_snapshot(UINT8 *base){
    snap_player((UINT32 *)base);
    snap_enemy((UINT32 *)base);
    snap_enemy_bullet(base);
}

void snap_player(UINT32 *base){
    PlayerShip *players = model.ship;
    PlayerBullet *bullets = model.playerBullets;

    int i = 0;
     while (i < NUM_BULLET && bullets[i].position.x != 0) {
        if(bullets[i].collision == 1)
            clear_part(base,bullets[i].prev_x,bullets[i].prev_y,SHIP_WIDTH,PLAYER_BULLET_HEIGHT);
        else if (bullets[i].position.x == 1){
           ;
        }
        else {
        clear_part(base,bullets[i].prev_x,bullets[i].prev_y,SHIP_WIDTH,PLAYER_BULLET_HEIGHT);
        plot_bitmap_32(base,bullets[i].position.x,bullets[i].position.y,player_bullet_hex, PLAYER_BULLET_HEIGHT);
        
        }
        i++;
    }
    i = 0;
    while(i < NUM_PLAYER && players[i].position.x != 0){
        if(players[i].position.x == 1){
            i++;
        }
        else if (players[i].prev_x != players[i].position.x || players[i].prev_y != players[i].position.y){
            clear_part(base,players[i].prev_x,players[i].prev_y,SHIP_WIDTH,SHIP_HEIGHT);
            plot_bitmap_32(base,players[i].position.x,players[i].position.y,player_ship, SHIP_HEIGHT);
            i++;
        }
        else   
            i++;
    }
}

void snap_enemy(UINT32 *base){
    Enemy *enemies = model.enemies;
    int i = 0;
    while(i < NUM_ENEMY && enemies[i].position.x != 0){
        if(enemies[i].position.x == 1)
            ;
        else if (enemies[i].death_time > 0){
            if(enemies[i].death_time == 1){
                clear_part(base,enemies[i].prev_x,enemies[i].prev_y,SHIP_WIDTH,SHIP_HEIGHT);
            }
            clear_part(base,enemies[i].position.x,enemies[i].position.y,SHIP_WIDTH,SHIP_HEIGHT);
            if (enemies[i].death_time < 8)
                plot_bitmap_32(base,enemies[i].position.x,enemies[i].position.y,explosion,SHIP_HEIGHT);
        }
        else if (enemies[i].prev_x != enemies[i].position.x || enemies[i].prev_y != enemies[i].position.y){
            clear_part(base,enemies[i].prev_x,enemies[i].prev_y,SHIP_WIDTH,SHIP_HEIGHT);
            if(enemies[i].collision == 1)
                plot_bitmap_32(base,enemies[i].position.x,enemies[i].position.y,explosion,SHIP_HEIGHT);
            
            else if(enemies[i].type == 1)
                plot_bitmap_32(base,enemies[i].position.x,enemies[i].position.y,helicopter,SHIP_HEIGHT);
            else 
                plot_bitmap_32(base,enemies[i].position.x,enemies[i].position.y,jet,SHIP_HEIGHT);
        }
        i++;
    }
}
void snap_enemy_bullet(UINT8 *base){
    Bullet *bullets = model.bullets;
    int i = 0;
    while(i < NUM_BULLET && bullets[i].position.x != 0){
        if(bullets[i].position.x == 1)
            i++;
        else if (bullets[i].prev_x != bullets[i].position.x || bullets[i].prev_y != bullets[i].position.y){
            clear_part((UINT32 *)base,bullets[i].prev_x,bullets[i].prev_y,BULLET_WIDTH,BULLET_HEIGHT);
            plot_bitmap_8(base,bullets[i].position.x,bullets[i].position.y,heli_bullet_bitmap, BULLET_HEIGHT);
            i++;
        }
        else   
            i++;
    }
}
    