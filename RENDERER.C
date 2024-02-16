#include "RENDERER.H"
#include "RASTER.H"
#include <osbind.h>
#include "bitmap.c"

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
    if (model->bullets[i].position.x != 0){
        plot_bitmap_16(base,model->powerup.position.x,model->powerup.position.y,powerup, POWER_UP_HEIGHT);
    }
}
void render(Model *model){
    void *base = Physbase();
    clear_screen(base);         /*clear entire screen*/
    plot_bitmap_32(base,model->ship[0].position.x,model->ship[0].position.y,player_ship, SHIP_HEIGHT); /*rasterize all 32 bitmaps that should be on screen */
    render_all_32(model, base);

    render_all_16(model, base);/*rasterize all 16 bitmaps to screen*/
    render_all_8(model, base); /*rasterize all 8 bitmaps to screen*/

    
    
    
}

