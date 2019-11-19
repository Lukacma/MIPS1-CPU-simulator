.set noreorder
.globl entry
 entry:	
    bgezal $4,la
    xori $4,1
    jr $0
    ori $2,4
    jr $0 
    la:
        jr $31       
        