            xref    _do_IKBD_ISR
            xdef    _ikbd_isr

_ikbd_isr:  movem.l d0-2/a0-2,-(sp)
            jsr     _do_IKBD_ISR
            movem.l (sp)+,d0-2/a0-2
            rte