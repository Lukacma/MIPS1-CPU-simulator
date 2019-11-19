.set noreorder
.globl entry
 entry:
 ori $v0,15
 ori $a2,1
subu $v0,$v0,$a2
    jr $zero	
    