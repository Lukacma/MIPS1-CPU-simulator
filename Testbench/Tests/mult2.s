.set noreorder
.globl entry
 entry:
 ori $t0,1
 sll $t0,31
 ori $t1,2
 mult $t1,$t0
 mfhi $v0
     jr $zero	
    