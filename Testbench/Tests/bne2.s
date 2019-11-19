    .set noreorder
.globl entry
 entry:	
    ori $4,1
    bne $4,$0,la
    nop
    fi:jr $0
    nop
    la:
        nop
        ori $2,7
        bne $4,$0, fi
        