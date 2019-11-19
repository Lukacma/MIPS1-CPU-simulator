.set noreorder
.globl entry
 entry:
 ori $v0,0x0008
 ori $t0,0x0009
 or $v0,$t0,$v0
     jr $zero	
    