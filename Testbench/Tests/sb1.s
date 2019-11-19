.globl entry
 entry:
    ori $t1,0xF
    ori $t0, 0x2
    sll $t0,28
    sb		$t1, 152($t0)
    lw   $2,  152($t0)
    srl $2,24
    jr $zero		# $t0 = $t1 + $t2
    