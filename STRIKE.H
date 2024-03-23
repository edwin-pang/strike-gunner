#ifndef STRIKE_H
#define STRIKE_H

extern Model model;
extern Model front;
extern Model back;
extern UINT32 duration;
extern UINT8 *front_base;
extern UINT8 *back_base;
extern UINT8 *active_base;
extern UINT8 *inactive_base;
UINT8 *get_base(UINT8 *second_buffer);
void menu();
void game();
#endif