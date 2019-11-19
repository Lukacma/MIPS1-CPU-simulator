.set noreorder
.globl entry
 entry:
 ori $v0,0x0008
 sll $v0,16
    ori $v0,$v0, 0xFFFF
    srl $v0,16
    jr $zero	
    