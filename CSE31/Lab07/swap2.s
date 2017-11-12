	.text
main:
	la	$a0,n1
	la	$a1,n2
	jal	swap
	li	$v0,1	# print n1 and n2; should be 27 and 14
	lw	$a0,n1
	syscall
	li	$v0,11
	li	$a0,' '
	syscall
	li	$v0,1
	lw	$a0,n2
	syscall
	li	$v0,11
	li	$a0,'\n'
	syscall
	li	$v0,10	# exit
	syscall

swap:	# your code goes here
	addi	$sp, $sp, -4
	
	lw	$t1, 0($sp)
	
	lw	$t0, 0($a0) # t0 = *px
	
	sw	$t0, 0($t1) # *temp = t0
	lw 	$t0, 0($a1) # t0 = *py
	sw	$t0, 0($a0) # *px = t0
	lw	$t0, 0($t1) # t0 = *temp
	sw 	$t0, 0($a1) # *py = *temp

	.data
n1:	.word	14
n2:	.word	27
