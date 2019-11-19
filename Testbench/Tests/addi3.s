   .set noreorder
.globl entry
 entry:
 ori $4, 1
 sll $4,31
    addi $2,$4,-1
    jr $zero	
    