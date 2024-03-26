#ifndef ISR_H
#define ISR_H
#define VB_ISR 28
#define IKBD_ISR 70
typedef void (*Vector)(); /* a Vector is a function start addr. */
Vector install_vector(int num, Vector vector);
void new_vb_isr_c();
void new_vb_isr()
#endif