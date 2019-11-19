.set noreorder
.globl entry
 entry:	
    ori $4,1
    sll $4,31
    blez $4,la
    srl $4,1
    fi:jr $0
    nop
    la:
        nop
        ori $2,7
        blez $4,fi
        