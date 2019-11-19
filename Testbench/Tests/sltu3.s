.set noreorder
.globl entry
 entry:
 ori $t0,255
 sll $t0,24
 ori $t1,2
 sltu $v0,$t0,$t1
    jr $zero	
    