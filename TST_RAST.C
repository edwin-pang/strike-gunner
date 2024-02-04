#include <osbind.h>
#include "raster.h"
#include "TYPES.H"
const UINT32 player_ship[32] = {
	0x00018000,
	0x00018000,
	0x00018000,
	0x00018000,
	0x00018000,
	0x0003C000,
	0x0003C000,
	0x0003C000,
	0x0003C000,
	0x0003C000,
	0x00024000,
	0x0003C000,
	0x0003C000,
	0x001FF800,
	0x001FF800,
	0x001FF800,
	0x001FF800,
	0x001FF800,
	0x00FE7F00,
	0x00FE7F00,
	0x01FFFF80,
	0x03FFFFC0,
	0x03FFFFC0,
	0x0FFFFFF0,
	0x3FFFFFFC,
	0xFF17E8FF,
	0xF81FF81F,
	0x001E7800,
	0x01F66F80,
	0x01F66F80,
	0x03FE7FC0,
	0x03FE7FC0,
};

const UINT16 powerup[16] = {
	0x1FF8,
	0x300C,
	0x67E6,
	0xCFF3,
	0x8C31,
	0x8C31,
	0x8C31,
	0x8FF1,
	0x8FE1,
	0x8E01,
	0x8E01,
	0x8E01,
	0xCE03,
	0x6E06,
	0x3E0C,
	0x1FF8
};





	

int main()
{
	void *base = Physbase();

	/*clear_screen();*/
	plot_bitmap_16(base,128,120,powerup,16);
	plot_bitmap_16(base,640,120,powerup,16);
	plot_bitmap_16(base,624,120,powerup,16);
	plot_bitmap_16(base,300,390,powerup,16);
	plot_bitmap_32(base,320,200,player_ship,32);
	plot_pixel(base,500,250);
	return 0;
}
