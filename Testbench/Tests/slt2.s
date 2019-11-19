.set noreorder
.globl entry
 entry:
 ori $t0,0x1
 sll $t0,31
 slt $v0,$t0,$t1
    jr $zero	
    