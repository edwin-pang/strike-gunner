#include "RASTER.H"
#include "bitmap.c"
#include <osbind.h>

int main(){
    UINT8 *base = Physbase();

    clear_screen(base);

    /* STRIKE */
    plot_bitmap_32((UINT32 *)base, 10, 40, s_32, 32);
    plot_bitmap_32((UINT32 *)base, 50, 40, t_32, 32);
    plot_bitmap_32((UINT32 *)base, 100, 40, r_32, 32);
    plot_bitmap_32((UINT32 *)base, 150, 40, i_32, 32);
    plot_bitmap_32((UINT32 *)base, 200, 40, k_32, 32);
    plot_bitmap_32((UINT32 *)base, 250, 40, e_32, 32);

    /* GUNNER */
    plot_bitmap_32((UINT32 *)base, 350, 40, g_32, 32);
    plot_bitmap_32((UINT32 *)base, 400, 40, u_32, 32);
    plot_bitmap_32((UINT32 *)base, 450, 40, n_32, 32);
    plot_bitmap_32((UINT32 *)base, 500, 40, n_32, 32);
    plot_bitmap_32((UINT32 *)base, 550, 40, e_32, 32);
    plot_bitmap_32((UINT32 *)base, 600, 40, r_32, 32);

    /* Player Ship */
    plot_bitmap_32 ((UINT32 *)base, 300, 40, player_ship, 32);

    /* Underline */
    plot_horizontal_line((UINT32 *)base, 35, 80, 600, 1);
    plot_horizontal_line((UINT32 *)base, 35, 81, 600, 1);
    plot_horizontal_line((UINT32 *)base, 35, 82, 600, 1);
    /* TO FIX ITS BUGGY */

    /* 1P */
    plot_bitmap_16((UINT16 *)base, 240, 200, one_16, 16);
    plot_bitmap_16((UINT16 *)base, 260, 200, p_16, 16);

    /* START */
    plot_bitmap_16((UINT16 *)base, 300, 200, s_16, 16);
    plot_bitmap_16((UINT16 *)base, 320, 200, t_16, 16);
    plot_bitmap_16((UINT16 *)base, 340, 200, a_16, 16);
    plot_bitmap_16((UINT16 *)base, 360, 200, r_16, 16);
    plot_bitmap_16((UINT16 *)base, 380, 200, t_16, 16);

    /* Black Background */
    flip_screen((UINT32*) base);
    
    return 0;
}