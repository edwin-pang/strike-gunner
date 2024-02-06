#ifndef RASTER_H
#define RASTER_H

#include "types.h"

/*
purpose: Will make the entire screen white, clears all bits in frame buffer
input: no input is required
output: no output is required
*/
void clear_screen();

/*


*/


void plot_horizontal_line(UINT32 *base, int x, int y, unsigned int length, int right);

void plot_vertical_line(UINT32 *base, int x, int y, unsigned int length, int up);

void plot_pixel(UINT8 *base, int x, int y);
void plot_bitmap_8(UINT8 *base, int x, int y, const UINT8 *bitmap, unsigned int height);
void plot_bitmap_16(UINT16 *base, int x, int y, const UINT16 *bitmap, unsigned int height);
void plot_bitmap_32(UINT32 *base, int x, int y, const UINT32 *bitmap, unsigned int height);


#endif
