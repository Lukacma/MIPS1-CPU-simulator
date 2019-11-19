.set noreorder
.globl entry
 entry:	
    ori $4,1
    bgez $4,la
    nop
      fi:jr $0
    nop
    la:
        bgez $4,fi
        