.set noreorder
.globl entry
 entry:
    ori $t1, 0xFFFF
    ori $t0, 0x2
    sll $t0,28
    sw		$t1, 12($t0)
    lhu  $2,  14($t0)
    srl $2,24
    jr $zero		# $t0 = $t1 + $t2
    