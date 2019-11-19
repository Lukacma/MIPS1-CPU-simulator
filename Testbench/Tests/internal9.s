.set noreorder
.globl entry
 entry:
    ori $t0, 3
    sll $t0,28
    ori $t1, 0x00000003
    sll $t1,28
    ori $t1, 0x00000004	
    ori $6,0xFFFF
    sll $6,16
    ori $6,0xFFFF

file_loop:
    lw		$5 , 0($t0)		# 
    beq		$5, $6,end 	# if $5 ==6t1 then target
    nop
    sw      $5,0($t1)
    j file_loop
    nop
  
  end:  jr $zero		# $t0 = $t1 + $t2
    