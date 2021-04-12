	.arch msp430g2553
	.p2align 1, 0
	.text
	;; routines to access sr

	.global toggle_red
toggle_red:
	mov.b r2, r12		;
	cmp.b state, 0		;
	mov.b &0, &red_on	;
	mov.b &1, &state	;
	cmp.b state, 1
	mov.b &1, &red_on	;
	mov.b &0, &state	;
	ret
