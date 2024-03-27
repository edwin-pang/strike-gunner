#ifndef ISR_H
#define ISR_H
#include "TYPES.H"
#define IKBD_ISR 70
#define RX_DISABLE 0x16
#define RX_ENABLE 0x80
#define TOS_DEFAULT 0x96
#define RDR_FULL 0x01
#define VB_ISR 28
#define IKBD_ISR 70
typedef void (*Vector)(); /* a Vector is a function start addr. */
Vector install_vector(int num, Vector vector);
SCANCODE read_scancode();
extern void VBL_ISR();
void do_IKBD_ISR();
void VB_ISR_c();
#endif
