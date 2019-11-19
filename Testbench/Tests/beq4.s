.set noreorder
.globl entry
 entry:	
    ori $2,15
    beq $0,$2,fi
    nop 
    jr $0
    fi:
    
