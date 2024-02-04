#include "raster.h"

#define SCREEN_HEIGHT 400	/* These can be moved later on if there is a better */
#define SCREEN_WIDTH 640	/* spot to put them */

/*void plot_something_2(UINT16 *base, int x, int y, ..)
{
	 [TO DO] delete this example function 
}*/

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
		UINT8 *loc = base + y * 80 + (x >> 3);
		*loc |= 1 << 7 - (x & 7);
	}
}

void plot_bitmap_16(UINT16 *base, int x, int y, const UINT16 *bitmap, unsigned int height)
{
    UINT16 *loc = base + (y * 40) + (x >> 4);
    int row;
    int bitOffset = x % 16;  
	if ( loc < base | y + height > 400) {
		return;
	}
    for (row = 0; row < height; row++)
    {
		UINT16 right_word = bitmap[row] << bitOffset;     /*since this function can plot on any x pixel, the bitmap needs to be broken into 2 seperate words.*/
		UINT16 left_word = bitmap[row] >> 16 - bitOffset; /*the right word is is printed to the screen in the current location, and the left word is printed in the current location -1 word*/
        *loc = (*loc  | right_word);					  /*print right word to screen*/	     
		*(loc -1) = *(loc - 1) | left_word;				  /*print left word to screen*/
        loc += 40;										  /*move down 1 pixel in y*/
		
}
}