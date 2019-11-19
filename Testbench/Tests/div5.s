.set noreorder
.globl entry
 entry:
 ori $t0,0
 ori $t1,0x5
 div $t0,$t1
 mflo $v0
 mfhi $4
 or $v0,$4
     jr $zero	
    