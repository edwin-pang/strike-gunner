#ifndef ISR_H
#define ISR_H
#include "TYPES.H"
#include <osbind.h>

typedef void (*Vector)();

#define IKBD_ISR 70

#define RX_DISABLE 0x16
#define RX_ENABLE 0x80
#define TOS_DEFAULT 0x96
#define RDR_FULL 0x01

SCANCODE read_scancode();
Vector install_vector(int num, Vector vector);
void do_IKBD_ISR();

#endif
