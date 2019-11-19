.set noreorder
.globl entry
 entry:
 ori $v0,0x8000
 sll $v0,16
srl $v0,$v0,31
    jr $zero	
    