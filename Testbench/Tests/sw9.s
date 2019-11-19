.set noreorder
.globl entry
 entry:
    ori $t1,9
    ori $t0, 0x2
    sll $t0,28
    addi $t0,8
    sw		$t1, -4($t0)	
    addi $t0,-8
    lw    $2,4($t0) 
    jr $zero		# $t0 = $t1 + $t2
    