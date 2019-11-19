.set noreorder
.globl entry
 entry:
    ori $t0, 2
    sll $t0,28
    lw		$2 , -1($t0)		# 
    jr $zero		# $t0 = $t1 + $t2
    