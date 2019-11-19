.globl entry
 entry:
    ori $t0, 0x00000003
    sll $t0,28
    ori $t0, 0x00000004		# 
    ori $t1, 72
    sw		$t1, 0($t0)
    and $t1,$0
        ori $t1, 101
    sw		$t1, 0($t0)
    and $t1,$0
        ori $t1, 108
    sw		$t1, 0($t0)
    and $t1,$0
        ori $t1, 108
    sw		$t1, 0($t0)
    and $t1,$0
        ori $t1, 111
    sw		$t1, 0($t0)
    and $t1,$0
        ori $t1, 32
    sw		$t1, 0($t0)
    and $t1,$0
        ori $t1, 116
    sw		$t1, 0($t0)
    and $t1,$0
        ori $t1, 104
    sw		$t1, 0($t0)
    and $t1,$0
        ori $t1, 101
    sw		$t1, 0($t0)
    and $t1,$0
        ori $t1, 114
    sw		$t1, 0($t0)
    and $t1,$0
        ori $t1, 101
    sw		$t1, 0($t0)
    and $t1,$0
        ori $t1, 33
    sw		$t1, 0($t0)
    and $t1,$0
    jr $zero		# $t0 = $t1 + $t2
    