#include "RASTER.H"
#include "bitmap.c"
#include <osbind.h>

int main(){
    UINT8 *base = Physbase();
    int i;

    clear_screen(base);

    /* Black Background */

    /*for (i = 0; i < 639; i++){
        plot_horizontal_line((UINT32*) base, 0, i, 640, 1);
    }*/

    /* S */
    plot_bitmap_32((UINT32 *)base, 10, 40, s_32, 32);

    /* T */
    plot_bitmap_32((UINT32 *)base, 50, 40, t_32, 32);

    /* R */
    plot_bitmap_32((UINT32 *)base, 100, 40, r_32, 32);

    /* I */
    plot_bitmap_32((UINT32 *)base, 150, 40, i_32, 32);

    /* K */
    plot_bitmap_32((UINT32 *)base, 200, 40, k_32, 32);

    /* E */
    plot_bitmap_32((UINT32 *)base, 250, 40, e_32, 32);

    /* WORK IN PROGRESS */

    return 0;
}