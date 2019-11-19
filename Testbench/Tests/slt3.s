.set noreorder
.globl entry
 entry:
 ori $t0,0xF8
 ori $t1,0XFA
 slt $v0,$t0,$t1
    jr $zero	
    