.set noreorder
.globl entry
 entry:
    ori $t0, 3
    sll $t0,28
    lw		$2 , 0($t0)		# 
    jr $zero		# $t0 = $t1 + $t2
    