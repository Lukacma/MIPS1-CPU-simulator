.set noreorder
.globl entry
 entry:
 ori $t0,0xFFFF
 sll $t0,16
  ori $t0,0xFFFE
 ori $t1,0xFFFF
 sll $t1,16
 ori $t1,0x5
 div $t1,$t0
 mflo $v0
 mfhi $4
 or $v0,$4
     jr $zero	
    