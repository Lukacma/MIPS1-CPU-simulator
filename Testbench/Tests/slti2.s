.set noreorder
.globl entry
 entry:
ori $t0,0xFFFF
sll $t0,16
slti $v0,$t0,1
    jr $zero	
    