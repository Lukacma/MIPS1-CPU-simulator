.set noreorder
.globl entry
 entry:
 #setting up memory address
  ori $t0, 0x00000003
    sll $t0,28
    ori $t0, 0x00000004	
 #first arithmetic test   
 ori $v0,0x8000
 sll $v0,16
 ori $a2, 31
srav $v0,$v0,$a2
sw		$v0, 0($t0)
#second arithmetic test
ori $t1, 0x7000
 sll $t1,16
 ori $a3, 29
srav $sp,$t1,$a3
sw		$sp, 0($t0)
    jr $zero	
    