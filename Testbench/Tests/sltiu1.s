.set noreorder
.globl entry
 entry:
 ori $t0,0xFFFF
 sll $t0,1
 sltiu $v0,$t0,0xFFFF
    jr $zero	
    