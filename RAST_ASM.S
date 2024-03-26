			xdef		_clear_screen
			xdef 		_set_video_base
;=====================================================================================================================
;purpose:			will make the entire screen white, clears all bits in frame buffer
;input:				base	- this is a pointer to the location (0,0) in the frame buffer
;output:			a clear frame buffer
;assumptions:		N/A
;limitations:		N/A
;bugs:				N/A
;=====================================================================================================================

y			equ			14
x			equ			12
base		equ			64		; offset from SP, not A6
SET_BASE	equ			8
VIDEO_HIGH  equ         $FFFF8201
VIDEO_MED 	equ			$FFFF8203
_clear_screen:	
			movem.l		d0-7/a0-6,-(sp)
			lea			zeros,a0
			movem.l		(a0)+,d1-7/a1-6
			movea.l		base(sp),a0
			adda.l		#32000,a0
			move.w		#614,d0
fill_loop:	
			movem.l		d1-7/a1-6,-(a0)
			dbra		d0,fill_loop
			movem.l		d1-5,-(a0)
			movem.l		(sp)+,d0-7/a0-6
			rts


_set_video_base:
			link		a6,#0
			movem.l 	d0-2/a0-2,-(sp)
			move.l      #VIDEO_HIGH,a0
			move.l		SET_BASE(a6),d0
			ror.l		#8,d0
			movep.w		d0,0(a0)
			movem.l	(sp)+,d0-2/a0-2
			unlk		a6
			rts


zeros:		ds.l		13

