.set noreorder
.globl entry
 entry:
 ori $t0,1
 sll $t0,31
sra $t0,$t0,30
ori $v0,1
 sll $v0,2
sra $v0,$v0,2
xor $v0,$t0,$v0
    jr $zero	
    