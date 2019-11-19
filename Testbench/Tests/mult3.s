.set noreorder
.globl entry
 entry:
 ori $t0,1
 sll $t0,31
 ori $a1,4
 sub	$t1, $t1,$a1			# $t1 = $t1 - 0
 mult $t1,$t0
 mfhi $v0
     jr $zero	
     