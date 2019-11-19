.set noreorder
.globl entry
 entry:
 ori $v0,0x0FFF
 sltiu $v0,$v0,0x0FFF
    jr $zero	
    