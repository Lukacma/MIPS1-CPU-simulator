.set noreorder
.globl entry
 entry:	
 #start data address
    ori $4,0x2
    sll $4,28
    #final data address
    ori $7,0x24
    sll $7,24
    loop:
        lb		$6, 0($4)
        nop
        or $2,$2,$6
        addi $4,$4,1
        bne		$7, $4, loop	# if $5 !=4t1looptarget
        nop


    #start instr address
    ori $15,0x1
    sll $15,28
    ori $15,88
 #end instr address   
    ori $16,0x11
    sll $16,24
    loop2:
         lb		$6, 0($15)
        nop
        or $2,$2,$6
        addi $15,$15,1
        bne		$15, $16, loop2	# if $5 !=4t1looptarget
        nop   
    
    jr $0
    