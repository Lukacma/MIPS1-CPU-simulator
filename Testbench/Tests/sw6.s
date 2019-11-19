.set noreorder
.globl entry
 entry:
    sw		$t1, -1($t0)		# 
    jr $zero		# $t0 = $t1 + $t2
    