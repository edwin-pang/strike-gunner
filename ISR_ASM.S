            xdef    _VBL_ISR
            xref    _VB_ISR_c

_VBL_ISR movem.l	d0-d2/a0-a2,-(sp)  
            jsr _VB_ISR_c
            movem.l	(sp)+,d0-d2/a0-a2
            rte     ; subroutine which wraps a