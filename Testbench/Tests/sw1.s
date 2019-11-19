.globl entry
 entry:
    ori $t0, 0x00000003
    sll $t0,28
    ori $t0, 0x00000004
    ori $t1, 0x00000030
    sw		$t1, 0($t0)		# 
    jr $zero		# $t0 = $t1 + $t2
    