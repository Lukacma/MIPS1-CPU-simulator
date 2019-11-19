.set noreorder
.globl entry
 entry:	
    beq $0,$4,fi
    ori $4,5
    fi: jr $0
    ori $2,21
    jr $0
