.globl entry
 entry:
    ori $t0, 0x00000002
    sll $t0,28
    jalr	$t0	
    jr $zero		# $t0 = $t1 + $t2
    