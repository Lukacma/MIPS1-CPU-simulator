.set noreorder
.globl entry
 entry:	
    jal l1
    andi $31,0		# $t0 = $t1 + $t2
    nop
    l1: 
        jr $31
        