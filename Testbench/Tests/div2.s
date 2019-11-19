.set noreorder
.globl entry
 entry:
 ori $t0,0xFFFF
 ori $t1,0xFFFF
 div $t1,$t0
 mflo $v0
 mfhi $4
 or $v0,$4
     jr $zero	
    