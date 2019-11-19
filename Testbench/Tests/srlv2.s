.set noreorder
.globl entry
 entry:
 ori $v0,8
 ori $a2, 31
 sll $a2,5
srlv $v0,$v0,$a2
    jr $zero	
    