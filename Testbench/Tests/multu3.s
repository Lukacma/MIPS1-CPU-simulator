.set noreorder
.globl entry
 entry:
 ori $v0,4
 ori $t1,1
  sll $t1,30
 multu $t1,$v0
 mfhi $v0

     jr $zero	
    