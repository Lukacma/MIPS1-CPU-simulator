.set noreorder
.globl entry
entry:
    
    
    
   
    ori $20, 0x3
    sll $20,28
    lwr $2,3($20)

    jr $0
    