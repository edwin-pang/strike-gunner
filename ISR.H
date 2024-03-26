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
#define VB_ISR 28
#define IKBD_ISR 70
typedef void (*Vector)(); /* a Vector is a function start addr. */
Vector install_vector(int num, Vector vector);
void new_vb_isr_c();
void new_vb_isr()
SCANCODE read_scancode();
Vector install_vector(int num, Vector vector);
void do_IKBD_ISR();

#endif
