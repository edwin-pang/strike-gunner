            xdef    _new_vb_isr


_new_vb_isr movem.l	d0-d2/a0-a2,-(sp)  
            jsr _new_vb_isr_c
            movem.l	(sp)+,d0-d2/a0-a2
            rte     ; subroutine which wraps a