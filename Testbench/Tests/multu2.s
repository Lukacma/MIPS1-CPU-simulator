.set noreorder
.globl entry
 entry:
 ori $t1,1
 sll $t1,30
  ori $t1,1
 ori $t0,4
 multu $t1,$t0
 mfhi $v0
 mflo $a1
 or $v0,$v0,$a1
     jr $zero	
 
