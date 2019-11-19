.set noreorder
.globl entry
entry:
    
    ori $4,0x0102
    sll $4,16
    ori $4,0x0304
    
    
    ori $20, 0x2
    sll $20,28

    sw $4,0($20)

    ori $2,0xFFFF
    sll $2,16
    lwr $2,1($20)
    nop
    srl $2,16
    jr $0
    