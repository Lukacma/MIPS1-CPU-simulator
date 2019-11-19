.set noreorder
.globl entry
 entry:	
 ori $4,1
 sll $4,31
    bltzal $4,la
    nop
    fi:jr $0
    nop
    la:
        nop
        ori $2,7
        jr $31
        