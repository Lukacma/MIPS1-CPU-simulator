.set noreorder
.globl entry
 entry:	
    ori $4,1
    sll $4,31
    bgez $4,la
    nop
      fi:jr $0
    nop
    la:
        ori $2,6
        bgez $4,fi
        