.set noreorder
.globl entry
 entry:
    ori $t0, 0x2
    sll $t0,28
    ori $t1, 0xFFFF    
    sw  $t1, 0($t0)
    lh  $2,  2($t0)
    srl $2, 16 
    jr $zero		# $t0 = $t1 + $t2
    