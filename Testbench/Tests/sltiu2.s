.set noreorder
.globl entry
 entry:
 ori $v0,0xFFFF
 sll $v0,1
 sltiu $v0,$v0,0x1
    jr $zero	
    