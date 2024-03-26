#include "raster.h"
#include <stdio.h>
#include <osbind.h>

#define SCREEN_HEIGHT 400	/* These can be moved later on if there is a better */
#define SCREEN_WIDTH 640	/* spot to put them */

void flip_screen(UINT32* base){
	int x = 0;
	int y = 0;
	int i, j;
	UINT32 *loc = base + (y * 20) + (x >> 5);
	for (i = 0; i < SCREEN_HEIGHT; i++){
		for (j = 0; j < SCREEN_WIDTH; j++){
    		*loc ^= 0xFFFFFFFF;
			loc ++;
		}
	}            

}

void plot_vertical_line(UINT32 *base, int x, int y, unsigned int length, int up){
	UINT32 *loc = base + (y * 20) + (x >> 5);
	int extra_x = 32 - (x % 32);
	UINT32 hex_for_line = 1;
	int pixels = length;
	hex_for_line = hex_for_line << extra_x;
	if (up == 1){
		while (pixels > 0 && loc >= base) {
			*loc |= hex_for_line;
			loc -= 20;
			pixels--;
		}
	}
	else {
		while (pixels > 0 && loc < base + 8000){
			*loc |= hex_for_line;
			loc += 20;
			pixels--;
		}
	}

}

void clear_part(UINT32 *base, int x, int y, int length, int height){
	UINT32 *loc = base + (y * 20) + (x >> 5);
	UINT32 x_array[20];
	UINT32 clear = 0x00000000;
	UINT32 dont_clear = 0xFFFFFFFF;
	int row = 1;
	int long_length = (length >> 5) + 1;
	int column;
	int right_offset = x % 32;
	int left_offset = 32 - right_offset;
	int x_add_loc = 20 - long_length;
	x_array[0] = (dont_clear << left_offset);
	while (row < long_length -1){ 
		x_array[row] = clear;
		row++;
	}
	x_array[row] = (dont_clear >> right_offset);
	row = 0;
	for (column = 0; column < height; column++)	
	{
		if ((loc < base) || (loc > base + 8000)){
				loc += 20;
			}
		else{	
			for(row = 0; row < long_length; row++){
				/*printf("%d", row);*/
				*loc = (*loc & x_array[row]); 
				loc += 1;
			}
			/*printf("/n");*/
			loc += x_add_loc;
		}
	}
}
void plot_horizontal_line(UINT32 *base, int x, int y, unsigned int length,int right){
	UINT32 *loc = base + (y * 20) + (x >> 5);
	int full_longs = length >> 5;
	UINT32 extra_to_add = 0;
	int extra_bits = 32 - (length % 32);
	if (right == 1){
		while (full_longs >0 && loc <= (base += 8000)) {
			full_longs--;
			*loc |= 0xFFFFFFFF;
			loc ++;
		} 
		extra_to_add = 0xFFFFFFFF;
			extra_to_add = extra_to_add << extra_bits;
	}
	else {
		while (full_longs !=0 && loc > base) {
			full_longs--;
			*loc |= 0xFFFFFFFF;
			loc--;
		} 
		extra_to_add = 0xFFFFFFFF;
		extra_to_add = extra_to_add >> extra_bits;
	}
	if (loc <= base + 8000 || loc > base){
	*loc |= extra_to_add;
	}
}

void plot_bitmap_8(UINT8 *base, int x, int y, const UINT8 *bitmap, unsigned int height)
{
	UINT8 *loc = (base + (y * 80) + (x >> 3) + 1);
	int row;
	int bitOffset = x % 8;


	for (row = 0; row < height; row++)
	{
		if ((loc < base) || (loc > base + 32000)){
			loc += 80;
		}
		else{
		UINT8 right_char = bitmap[row] << 8 - bitOffset ;
		UINT8 left_char = bitmap[row] >> bitOffset;

		*loc = (*loc | right_char);
		*(loc - 1) = *(loc - 1) | left_char;
		loc += 80;
	}
}
}
void plot_bitmap_32(UINT32 *base, int x, int y, const UINT32 *bitmap, unsigned int height)
{
	UINT32 *loc = (base + (y * 20) + (x >> 5) + 1);
	int row;
	int bitOffset = x % 32;
	

	for(row = 0; row < height; row++)
	{
		if ((loc < base) || (loc > base + 8000)){
			loc += 20;
		}
		else{
		UINT32 right_long = bitmap[row] << 32 - bitOffset;
		UINT32 left_long = bitmap[row] >> bitOffset;

		*loc = (*loc | right_long);
		*(loc - 1) = *(loc - 1) | left_long;
		loc += 20;
	}
}
}
void plot_bitmap_16(UINT16 *base, int x, int y, const UINT16 *bitmap, unsigned int height)
{
	
    UINT16 *loc = (base + (y * 40) + (x >> 4)+ 1);
    int row;
    int bitOffset = x % 16;  

    for (row = 0; row < height; row++)
    {
		if ((loc < base) || (loc > base + 16000)){
			loc += 40;
		}
		else{

		
		UINT16 right_word = bitmap[row] << 16 - bitOffset;     /*since this function can plot on any x pixel, the bitmap needs to be broken into 2 seperate words.*/
		UINT16 left_word = bitmap[row] >> bitOffset; /*the right word is is printed to the screen in the current location, and the left word is printed in the current location -1 word*/
        *loc = (*loc  | right_word);					  /*print right word to screen*/	     
		*(loc -1) = *(loc - 1) | left_word;				  /*print left word to screen*/
        loc += 40;										  /*move down 1 pixel in y*/
		}
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

UINT16 * get_video_base(){
	long old_ssp;
	UINT8 * temp_word;
	UINT16 * the_base;
	UINT32 temp;
	UINT32 address;
	old_ssp = Super(0); /* enter privileged mode */
	temp_word = VIDEO_HIGH;
	temp = *temp_word;
	temp = temp << 16 ;
	address = temp;
	temp_word = VIDEO_MED;
	temp = *temp_word;
	temp = temp << 8;
	address += temp;
	the_base = (UINT16 *) address;
	Super(old_ssp); /* exit privileged mode as soon as possible */
	
	return the_base;

}
void set_video_base_C(UINT16 * base){
	long old_ssp;
	old_ssp = Super(0); /* enter privileged mode */
	set_video_base(base);
	Super(old_ssp); /* exit privileged mode as soon as possible */
}