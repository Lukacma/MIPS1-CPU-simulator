.set noreorder
.globl entry
 entry:
    ori $t0, 0x1
    sll $t0,28
    addi $t0,8
    lh  $2,  -6($t0)
    jr $zero		# $t0 = $t1 + $t2
    