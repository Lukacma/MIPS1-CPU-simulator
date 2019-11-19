.set noreorder
.globl entry
 entry:
 ori $t1,0xF001
 ori $t0,1
 sllv $v0,$t0,$t1
    jr $zero	
    