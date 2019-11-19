.set noreorder
.globl entry
entry:
    
    ori $4,0x0102
    sll $4,16
    ori $4,0x0304
    
   
    ori $20, 0x2
    sll $20,28

    sw $4,0($20)

    lwr $2,1($20)

    jr $0
    