.set noreorder
.globl entry
 entry:
    xori $v0,$t0,0xAA
    srl $v0,8
    jr $zero	
    