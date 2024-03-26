/*#include "EVENTS.H"
#include "INPUT.H"
#include "MODEL.H"
#include "RENDERER.H"
#include <stdio.h>
#include <osbind.h>
#include "STRIKE.H"
#include "RANDOM.H"
#include "MUSIC.H"
#include "RASTER.H"
#include "ISR.H"
#include "IKBD.H"

volatile       UINT8 * const IKBD_control = 0xFFFC00;
volatile const UINT8 * const IKBD_status = 0xFFFC00;
volatile const UINT8 * const IKBD_RDR = 0xFFFC02;
void new_vb_isr_c(){
    update_music(1);
}
SCANCODE read_scancode(){
    while(!(*IKBD_status & RDR_FULL))
        ;
    return *IKBD_RDR;
}

Vector install_vector(int num, Vector vector){
    Vector orig;
    Vector *vectp = (Vector *)((long)num << 2);
    long old_ssp = Super(0);
    orig = *vectp;
    *vectp = vector;
    Super(old_ssp);
    return orig;
}

void do_IKBD_ISR(){
    UINT8 scancode;
    UINT8 ascii;
    char *scancode_2_ascii = (char *)((Keytbl(-1,-1,-1))->unshift);

    *IKBD_control = RX_DISABLE;

    scancode = read_scancode();
    key_buff[(rear + 1) % KEY_BUFF_SZ] = scancode;
    
    *IKBD_control = TOS_DEFAULT;
}
*/