#include "RENDERER.H"
#include "RASTER.H"
#include <osbind.h>
#include "bitmap.c"
#include "font.c"


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
     while (i < 49 && model->playerBullets[i].position.x != 0) {
        plot_bitmap_32(base,model->playerBullets[i].position.x,model->playerBullets[i].position.y,player_bullet_hex, PLAYER_BULLET_HEIGHT);
        i++;
    }
    i = 0;
    while (i < 19 && model->helicopters[i].position.x != 0) {
        plot_bitmap_32(base,model->helicopters[i].position.x,model->helicopters[i].position.y, helicopter, SHIP_HEIGHT);
        i++;
    }
    i = 0;
    while (i < 19 && model->jets[i].position.x != 0) {
        plot_bitmap_32(base,model->jets[i].position.x,model->jets[i].position.y, jet, SHIP_HEIGHT);
        i++;
    }
}
void render_all_8(Model *model, UINT8 *base) {
     int i = 0;
     while (i < 49 && model->bullets[i].position.x != 0) {
        plot_bitmap_8(base,model->bullets[i].position.x,model->bullets[i].position.y,heli_bullet_bitmap, BULLET_HEIGHT);
        i++;
    }
}
void render_all_16(Model *model, UINT16 *base) {
    if (model->powerup.position.x != 0){
        plot_bitmap_16(base,model->powerup.position.x,model->powerup.position.y,powerup, POWER_UP_HEIGHT);
    }
}
void render(Model *model, char *base){
    /*void *base = Physbase();*/
    clear_screen(base);         /*clear entire screen*/
    plot_bitmap_32(base,model->ship[0].position.x,model->ship[0].position.y,player_ship, SHIP_HEIGHT); /*rasterize all 32 bitmaps that should be on screen */
    render_all_32(model, base);

    render_all_16(model, base);/*rasterize all 16 bitmaps to screen*/
    render_all_8(model, base); /*rasterize all 8 bitmaps to screen*/

    render_panel_left(base);
    render_panel_right(base);
    render_score(model,base);
    render_life_counter(model,base);
}

