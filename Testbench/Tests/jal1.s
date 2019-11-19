.set noreorder
.globl entry
 entry:	
    jal l1		# $t0 = $t1 + $t2
    nop
    l2:
        jr $0
        nop
    l1: 
        or $2,$31
        jal l2
        