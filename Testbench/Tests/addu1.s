.set noreorder
.globl entry
 entry:
 ori $4, 1
 sll $4,30
 ori $4,1
    addu $2,$4,$4
    sll $4,1
    addu $5,$4,$4
    jr $zero	
    