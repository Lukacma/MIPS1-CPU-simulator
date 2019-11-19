.set noreorder
.globl entry
 entry:
 ori $v0,0x8000
 sll $v0,16
 ori $a2, 0x0001
sub $v0,$v0,$a2
    jr $zero	
    