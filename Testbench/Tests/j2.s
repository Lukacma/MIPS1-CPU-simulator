.set noreorder
.globl entry
 entry:	
    j l1		# $t0 = $t1 + $t2
    nop
    l2:
        jr $0
        nop
    l1: 
        ori $2,1
        j l2
        sll $2,2
