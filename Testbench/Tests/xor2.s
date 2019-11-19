.set noreorder
.globl entry
 entry:
 ori $t0, 0x9C
    ori $t1, 0xAA
    xor $v0,$t0,$t1
    jr $zero	
    