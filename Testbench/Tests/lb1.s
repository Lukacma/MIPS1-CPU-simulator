.set noreorder
.globl entry
 entry:
    ori $t1,0xF
    ori $t0, 0x2
    sll $t0,28
    sb		$t1, 151($t0)
    lb   $2,  151($t0)
    jr $zero		# $t0 = $t1 + $t2
    