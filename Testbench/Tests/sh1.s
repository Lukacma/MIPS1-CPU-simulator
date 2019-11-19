.globl entry
 entry:
    ori $t1, 190
    ori $t0, 0x2
    sll $t0,28
    sh		$t1, 0($t0)
    lw   $2,  0($t0)
    srl $2,16
    jr $zero		# $t0 = $t1 + $t2
    