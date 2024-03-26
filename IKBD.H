#ifndef IKBD_H
#define IKBD_H

#define ESC_MAKE  ((SCANCODE) 0x01)
#define ESC_BREAK ((SCANCODE) 0X81)

#define BREAK_CODE 0x80
#define MAKE_CODE 0xEF

void ikbd_isr();

#endif
