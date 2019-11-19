.set noreorder
.globl entry
entry:
    
    ori $20, 0x3
    sll $20,28
    lwl $2,0($20)

    jr $0
    