.set noreorder
.globl entry
 entry:
 ori $v0,0x8000
 sll $v0,16
sub $v0,$zero,$v0
    jr $zero	
    