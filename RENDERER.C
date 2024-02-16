#include "RENDERER.H"
#include "RASTER.H"
#include <osbind.h>
#include "bitmap.c"


void render(Model *model){
    void *base = Physbase();
    clear_screen(base);         /*clear entire screen*/
    plot_bitmap_32(base,model->ship[0].position.x,model->ship[0].position.y,player_ship, SHIP_HEIGHT);
}