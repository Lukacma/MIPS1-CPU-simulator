.set noreorder
.globl entry
 entry:
 ori $t0,2
 ori $t1,1
  sll $t1,31
 multu $t1,$t0
 mfhi $v0
     jr $zero	
    