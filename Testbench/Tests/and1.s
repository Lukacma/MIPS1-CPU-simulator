.globl entry
 entry:
    ori $5,217
    ori $6,0xFFFF
    and $2,$5,$6
    jr $zero		# $t0 = $t1 + $t2
    