.globl entry
 entry:
    sw		$t1, 0($t0)		# 
    jr $zero		# $t0 = $t1 + $t2
    