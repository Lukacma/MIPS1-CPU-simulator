.set noreorder
.globl entry
 entry:
    ori $5,217
    and $2,$5,0xFFFF
    jr $zero		# $t0 = $t1 + $t2
    