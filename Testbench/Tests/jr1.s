.set noreorder
.globl entry
 entry:
    ori $t0, 0x00000004
    jr	$t0			# $t0 = $t1 + $t2
    