#include <osbind.h>
#include "raster.h"
#include "TYPES.H"
#include "bitmap.c"



int main()
{
	void *base = Physbase();

	clear_screen(base);

	plot_bitmap_16(base,128,120,powerup,16);
	plot_bitmap_16(base,640,120,powerup,16);		/* various test cases of 16 ensuring it works*/
	plot_bitmap_16(base,624,120,powerup,16);
	plot_bitmap_16(base,300,390,powerup,16);
	plot_bitmap_16(base,305,370,powerup,16);
	plot_bitmap_16(base,620,330,powerup,16);
	plot_bitmap_16(base,622,300,powerup,16);
	plot_bitmap_16(base,400,-5,powerup,16);
	plot_bitmap_16(base,400,390,powerup,16);
	plot_bitmap_16(base,634,200,powerup,16);


	plot_bitmap_32(base,320,200,player_ship,32);
	plot_bitmap_32(base,630,80,player_ship,32);
	plot_bitmap_32(base,334,250,player_ship,32);
	plot_bitmap_32(base,310,150,player_ship,32);
	plot_bitmap_32(base,310,-15,player_ship,32);
	plot_bitmap_32(base,100,390,player_ship,32);


	plot_pixel(base,500,250);



	plot_horizontal_line(base, 320,245,40,1);
	plot_horizontal_line(base, 320,250,50,1);
	plot_horizontal_line(base, 320,256,51,1);
	plot_horizontal_line(base, 320,257,52,1);		/*various test cases of horizontal right ensuring it works*/
	plot_horizontal_line(base, 320,258,53,1);
	plot_horizontal_line(base, 320,259,54,1);
	plot_horizontal_line(base, 320,260,55,1);

	plot_horizontal_line(base, 310,270,58,1);
	plot_horizontal_line(base, 320,273,40,0);
	plot_horizontal_line(base, 320,275,50,0);
	plot_horizontal_line(base, 320,276,51,0); 		/*various test cases of horizontal left ensuring it works*/
	plot_horizontal_line(base, 320,277,52,0);
	plot_horizontal_line(base, 320,278,53,0);
	plot_horizontal_line(base, 320,279,54,0);
	plot_horizontal_line(base, 320,280,55,0);

	plot_horizontal_line(base, 0,0,55,0);			/* ensure they cannot go out of bounds*/
	plot_horizontal_line(base, 640,400,55,1);


	plot_vertical_line(base,250,350,75,1);
	plot_vertical_line(base,255,275,75,1);


	return 0;
}
