.globl entry
 entry:
    ori $t1,0xF
    ori $t0, 0x2
    sll $t0,28
    sb		$t1, -153($t0)
    lw   $2,  150($t0)
    jr $zero		# $t0 = $t1 + $t2
    