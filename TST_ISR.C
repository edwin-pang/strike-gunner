#include "ISR.H"
#include "model.h"
#include "MUSIC.H"
Model model;
Model front;
Model back;
UINT8 *front_base;
UINT8 *back_base;
UINT8 *active_base;
UINT8 *inactive_base;
UINT8 render_request;
UINT8 key_buff[50];
UINT8 head;
UINT8 rear;
UINT32 duration = QUARTER_NOTE;
int main(){
    Vector orig_vb_vector;
    int i;
    orig_vb_vector = install_vector(VB_ISR,VBL_ISR);
    for(i = 0; i < 100000; i++)
        ;
    install_vector(VB_ISR,orig_vb_vector);
    return 0;
}