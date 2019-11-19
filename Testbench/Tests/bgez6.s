.set noreorder
.globl entry
 entry:	
    ori $4,1
    sll $4,30
    bgez $4,fi
    sll $4,1
    ori $2,25
    fi:jr $0
