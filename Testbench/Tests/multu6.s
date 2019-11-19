.set noreorder
.globl entry
 entry:
 ori $t0,2
 multu $t1,$t0
 mflo $v0
 mfhi $a1
 or $v0,$a1
     jr $zero	
    