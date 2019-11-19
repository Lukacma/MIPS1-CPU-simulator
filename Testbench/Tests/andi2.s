.set noreorder
.globl entry
 entry:
    ori $2,1
    sll $2,31
    and $2,$2,0xFFFF
    srl $2,31
    jr $zero		# $t0 = $t1 + $t2
    

