#ifndef RASTER_H
#define RASTER_H

#include "types.h"

void plot_bitmap_8(UINT8 *base, int x, int y, const UINT8 *bitmap, unsigned int height);

void plot_bitmap_16(UINT16 *base, int x, int y, const UINT16 *bitmap, unsigned int height);

void plot_bitmap_32(UINT32 *base, int x, int y, const UINT32 *bitmap, unsigned int height);

void plot_pixel(UINT8 *base, int x, int y);

#endif
