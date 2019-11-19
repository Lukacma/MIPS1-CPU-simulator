.set noreorder
.globl entry
 entry:	
    bgez $0,fi
    nop
    jr $0
    nop
    fi:ori $2,21
    jr $0
