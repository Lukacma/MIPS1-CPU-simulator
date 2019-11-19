.set noreorder
.globl entry
 entry:
 ori $v0,1
 mult $v0,$t0
 mflo $v0
     jr $zero	
  