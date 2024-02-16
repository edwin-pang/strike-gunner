#ifndef RASTER_H
#define RASTER_H
#include "types.h"

extern void clear_screen();

/*
=====================================================================================================================
purpose:     will print a horizontal line to the screen, left or right, starting at long boundaries for x
input:       base   - this is a pointer to the location (0,0) in the frame buffer
             x      - this is the x coordinate that the line will start at
             y      - this is the y coordinate that the line will start at
             length - this is how long the line will be
             right  - this is a boolean for which direction the line will go. 1 for right, 0 for left
output:      a frame buffer changed as requested (it has your horizontal line)
assumptions: this function assumes that the programmer starts at an x aligned long boundary (a multiple of 32),
             if the programmer does not do this, the function will truncate to the previous long boundary.
limitations: this function cannot work with non multiples of 32, but this shouldn't be an issue of the programmer
             understands this.              
bugs:        this function will continue to draw a line until it wraps around the screen. This should be known to the 
             programmer as there isn't a dire need for error checking in this domain (it won't destory random data)
=====================================================================================================================
*/
void plot_horizontal_line(UINT32 *base, int x, int y, unsigned int length, int right);

/*
=====================================================================================================================
purpose:     will print a vertical line onto the screen at any starting x or y coordinate for the length
             and direction specified
input:       base   - this is a pointer to the location (0,0) in the frame buffer
             x      - this is the x coordinate that the line will start at
             y      - this is the y coordinate that the line will start at
             length - this is how long the line will be
             up  - this is a boolean for which direction the line will go. 1 for up, 0 for down
output:      a frame buffer changed as requested (it has your vertical line)
assumptions: there is error checking, but just stay in the frame buffer
limitations: N/A
bugs:        N/A
=====================================================================================================================
*/
void plot_vertical_line(UINT32 *base, int x, int y, unsigned int length, int up);

/*
=====================================================================================================================
purpose:     will plot a single pixel at the desired x and y value
input:       base   - this is a pointer to the location (0,0) in the frame buffer
             x      - this is the x coordinate that the pixel will be
             y      - this is the y coordinate that the pixel will be
output:      a frame buffer changed as requested (it has your pixel)
assumptions: there is error checking, but just stay in the frame buffer
limitations: N/A
bugs:        N/A
=====================================================================================================================
*/
void plot_pixel(UINT8 *base, int x, int y);

/*
=====================================================================================================================
purpose:     will plot an 8x8 bitmap with the top left of that bitmap starting at the x and y value provided
input:       base   - this is a pointer to the location (0,0) in the frame buffer
             x      - this is the x coordinate that the bitmap will start at
             y      - this is the y coordinate that the bitmap will start at
             bitmap - this is a pointer to an array housing Byte sized bitmap information
             height - how far down the bitmap will go down
output:      a frame buffer changed as requested (it has your bitmap)
assumptions: bitmap won't exceed screen on either left or right, if it does it will wrap around with y -= 1
             the bitmap can go above or below frame buffer, and will be cut accordingly
limitations: will not be cut off if bit map goes past screen on left or right, will instead wrap around.
bugs:        see above
=====================================================================================================================
*/
void plot_bitmap_8(UINT8 *base, int x, int y, const UINT8 *bitmap, unsigned int height);

/*
=====================================================================================================================
purpose:     will plot an 16x16 bitmap with the top left of that bitmap starting at the x and y value provided
input:       base   - this is a pointer to the location (0,0) in the frame buffer
             x      - this is the x coordinate that the bitmap will start at
             y      - this is the y coordinate that the bitmap will start at
             bitmap - this is a pointer to an array housing Word sized bitmap information
             height - how far down the bitmap will go down
output:      a frame buffer changed as requested (it has your bitmap)
assumptions: bitmap won't exceed screen on either left or right, if it does it will wrap around with y -= 1
             the bitmap can go above or below frame buffer, and will be cut accordingly
limitations: will not be cut off if bit map goes past screen on left or right, will instead wrap around.
bugs:        see above
=====================================================================================================================
*/
void plot_bitmap_16(UINT16 *base, int x, int y, const UINT16 *bitmap, unsigned int height);

/*
=====================================================================================================================
purpose:     will plot an 32x32 bitmap with the top left of that bitmap starting at the x and y value provided
input:       base   - this is a pointer to the location (0,0) in the frame buffer
             x      - this is the x coordinate that the bitmap will start at
             y      - this is the y coordinate that the bitmap will start at
             bitmap - this is a pointer to an array housing long sized bitmap information
             height - how far down the bitmap will go down
output:      a frame buffer changed as requested (it has your bitmap)
assumptions: bitmap won't exceed screen on either left or right, if it does it will wrap around with y -= 1
             the bitmap can go above or below frame buffer, and will be cut accordingly
limitations: will not be cut off if bit map goes past screen on left or right, will instead wrap around.
bugs:        see above
=====================================================================================================================
*/
void plot_bitmap_32(UINT32 *base, int x, int y, const UINT32 *bitmap, unsigned int height);


#endif
