    .set noreorder
.globl entry
 entry:	
    bne $4,$0,la
    nop
    fi:jr $0
    nop
    la:
        nop
        ori $2,7
        bltz $4,fi
        