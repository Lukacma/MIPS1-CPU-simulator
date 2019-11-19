.globl entry
 entry:
    ori $t1, 0xFFFF
    sll $t1, 7
    ori $t0, 0x2
    sll $t0,28
    addi $t0,7
    sh		$t1, -3($t0)
    addi $t0,-7
    lw   $2,  4($t0)
    srl $2,16
    jr $zero		# $t0 = $t1 + $t2
    