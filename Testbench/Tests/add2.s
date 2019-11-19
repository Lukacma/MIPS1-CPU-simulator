.set noreorder
.globl entry
 entry:
 ori $4, 1
 sll $4,31
    add $2,$4,$4
    jr $zero	
    