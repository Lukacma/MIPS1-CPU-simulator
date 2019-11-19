.set noreorder
.globl entry
 entry:
 ori $v0,1
 ori $a2, 32
srav $v0,$v0,$a2
    jr $zero	
    