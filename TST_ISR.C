#include "ISR.H"

UINT8 key_buff[50];
UINT8 head;
UINT8 rear;
UINT32 duration;
int main(){
    do_IKBD_ISR();
    return 0;
}