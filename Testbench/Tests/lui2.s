.set noreorder
.globl entry
 entry:
    ori $5, 25
    lui $5,0xFFFF
    or $2,$5
    jr $zero		# $t0 = $t1 + $t2
    