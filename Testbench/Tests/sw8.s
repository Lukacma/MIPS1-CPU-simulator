.globl entry
 entry:
    ori $t1,9
    ori $t0, 0x2
    sll $t0,28
    sw		$t1, 8($t0)	
    lw    $2,8($t0) 
    jr $zero		# $t0 = $t1 + $t2
    