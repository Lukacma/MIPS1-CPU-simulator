.set noreorder
.globl entry
 entry:
 ori $t0,3
 ori $t1,5
 divu $t1,$t0
 mflo $v0
 mfhi $4
 or $v0,$4
     jr $zero	
    