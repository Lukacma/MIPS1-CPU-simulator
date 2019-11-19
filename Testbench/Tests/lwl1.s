.set noreorder
.globl entry
entry:
    
    ori $4,0x0102
    sll $4,16
    ori $4,0x0304
    
    ori $5,0x0506
    sll $5,16
    ori $5,0x0708
    
    ori $20, 0x2
    sll $20,28

    sw $4,0($20)
    sw $5,4($20)

    lwl $2,0($20)
    jr $0
    