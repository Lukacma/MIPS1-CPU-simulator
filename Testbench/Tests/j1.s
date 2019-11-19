.set noreorder
.globl entry
 entry:	
    j l1		# $t0 = $t1 + $t2
    nop
    l2:
        jr $0
        nop
    l1: 
        ori $2,8
        j l2
