.set noreorder
.globl entry
 entry:
 ori $t0,1
 sll $t0,31
 sltu $v0,$v0,$t0
    jr $zero	
    