.set noreorder
.globl entry
 entry:
    ori $t0, 0x00000004
    jr	$t0	
    jr $zero		# $t0 = $t1 + $t2
    