#include "raster.h"

#define SCREEN_HEIGHT 400	// These can be moved later on if there is a better
#define SCREEN_WIDTH 640	// spot to put them

void plot_bitmap_8(UINT8 *base, int x, int y, const UINT8 *bitmap, unsigned int height)
{
	UINT8 *loc = base + (y * 80) + (x >> 3);
	int row;

	for (row = 0; row < height; row++)
	{
		*loc |= bitmap[row];
		loc += 80;
	}
}

void plot_bitmap_16(UINT16 *base, int x, int y, const UINT16 *bitmap, unsigned int height)
{
	UINT16 *loc = base + (y * 40) + (x >> 4);
	int row;

	for(row = 0; row < height; row++)
	{
		*loc |= bitmap[row];
		loc += 40;
	}
}

void plot_bitmap_32(UINT32 *base, int x, int y, const UINT32 *bitmap, unsigned int height)
{
	UINT32 *loc = base + (y * 20) + (x >> 5);
	int row;

	for(row = 0; row < height; row++)
	{
		*loc |= bitmap[row];
		loc += 20;
	}
}

void plot_pixel(UINT8 *base, int x, int y)
{
	if (x >= 0 && x < SCREEN_WIDTH && y >= 0 && y < SCREEN_HEIGHT)
	{
		UINT8 *loc = base + y * 80 + (y >> 3);
		*loc |= 1 << 7 - (x & 7);
	}
}

int main(){
	return 0;
}