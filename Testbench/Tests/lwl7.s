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
    ori $21,4
    sll $21,24
    or $20,$21

    ori $2,0xFFFF
    sll $2,16
    ori $2,0xFFFF

    lwl $2,0($20)
    srl $2,24
    jr $0
    