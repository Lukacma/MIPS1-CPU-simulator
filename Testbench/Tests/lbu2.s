.set noreorder
.globl entry
 entry:
    ori $t1,0xFF
    ori $t0, 0x2
    sll $t0,28
    sb		$t1, 152($t0)
    addi	$t0, $t0, 160		# $t0 = $01 1600
        lbu   $2,  -8($t0)
    srl $2,24
    jr $zero		# $t0 = $t1 + $t2
    