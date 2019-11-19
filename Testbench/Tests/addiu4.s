   .set noreorder
.globl entry
 entry:
 ori $4, 0xFFFF
 sll $4,15
 ori $4, 0xFFFF
    addiu $2,$4,1
    jr $zero	
    