.set noreorder
.globl entry
 entry:
 ori $v0,0xFFFF
 sll $v0,16
ori $v0,0xFFC0
subu $v0,$zero,$v0
    jr $zero	
    