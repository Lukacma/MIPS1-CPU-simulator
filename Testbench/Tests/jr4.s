.globl entry
 entry:
    ori $t0, 0x00000003
    sll $t0,28
    jr	$t0	
    jr $zero		# $t0 = $t1 + $t2
    