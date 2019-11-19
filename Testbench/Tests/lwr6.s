.set noreorder
.globl entry
entry:
    
    ori $4,0x0102
    sll $4,16
    ori $4,0x0304
    
    ori $20, 0x2
    sll $20,28
    ori $21,4
    sll $21,24
    or $20,$21

    lwr $2,0($20)
    jr $0
    