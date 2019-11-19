.set noreorder
.globl entry
 entry:
 ori $t0,3
 ori $t1,5
 mult $t1,$t0
 mflo $v0
     jr $zero	
    