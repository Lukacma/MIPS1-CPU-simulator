.set noreorder
.globl entry
 entry:	
    ori $2,15
    beq $0,$5,else
    nop 
    jr $0
    nop
   else: sub $2,8
    jr $0
