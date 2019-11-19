.set noreorder
.globl entry
 entry:	
    ori $4,1
    sll $4,31
    bgez $4,fi
    nop
    ori $2,25
    fi:jr $0
