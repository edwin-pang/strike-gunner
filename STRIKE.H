#ifndef STRIKE_H
#define STRIKE_H

#define KEY_BUFF_SZ 50

extern Model model;
extern Model front;
extern Model back;
extern UINT32 duration;
extern UINT8 *front_base;
extern UINT8 *back_base;
extern UINT8 *active_base;
extern UINT8 *inactive_base;
extern UINT8 key_buff[50];
extern UINT8 front;
extern UINT8 rear;
UINT8 *get_base(UINT8 *second_buffer);
void menu();
void game();
#endif