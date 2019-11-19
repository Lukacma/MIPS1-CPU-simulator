.set noreorder
.globl entry
 entry:	
    bgezal $4,la
    nop
    jr $0
    nop
    la:ori $2,5
        jr $31       
        