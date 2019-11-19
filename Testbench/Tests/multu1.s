.set noreorder
.globl entry
 entry:
 ori $t1,0x0008
 ori $t0,0x0009
 multu $t1,$t0
 mflo $v0
     jr $zero	
    