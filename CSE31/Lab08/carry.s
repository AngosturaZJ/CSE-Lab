	.text
main:	addu	$t5, $t3, $t4
	sltu	$t2, $t5, $t3 # t2 will be either 0 or 1, after comparing t5 and t3
