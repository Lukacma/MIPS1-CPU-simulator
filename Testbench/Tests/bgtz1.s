.set noreorder
.globl entry
 entry:	
    bgtz $4,la
    nop
      fi:jr $0
    nop
    la:
        nop
        ori $2,7
        bgtz $4,fi
        