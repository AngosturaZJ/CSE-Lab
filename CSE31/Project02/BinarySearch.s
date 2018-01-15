.data 

original_list: .space 100 
sorted_list: .space 100

str0: .asciiz "Enter size of list (between 1 and 25): "
str1: .asciiz "Enter one list element: \n"
str2: .asciiz "Content of list: "
str3: .asciiz "Enter a key to search for: "
strYes: .asciiz "Key found!"
strNo: .asciiz "Key not found!"



.text 

#This is the main program.
#It first asks user to enter the size of a list.
#It then asks user to input the elements of the list, one at a time.
#It then calls printList to print out content of the list.
#It then calls inSort to perform insertion sort
#It then asks user to enter a search key and calls bSearch on the sorted list.
#It then prints out search result based on return value of bSearch
main: 
	addi $sp, $sp -8
	sw $ra, 0($sp)
	li $v0, 4 
	la $a0, str0 
	syscall 
	li $v0, 5	#Read size of list from user
	syscall
	move $s0, $v0
	move $t0, $0
	la $s1, original_list
loop_in:
	li $v0, 4 
	la $a0, str1 
	syscall 
	sll $t1, $t0, 2
	add $t1, $t1, $s1
	li $v0, 5	#Read elements from user
	syscall
	sw $v0, 0($t1)
	addi $t0, $t0, 1
	bne $t0, $s0, loop_in
	
	li $v0, 4 
	la $a0, str2 
	syscall 
	move $a0, $s1
	move $a1, $s0
	jal printList	#Call print original list
	
	jal inSort	#Call inSort to perform insertion sort in original list
	sw $v0, 4($sp)
	li $v0, 4 
	la $a0, str2 
	syscall 
	lw $a0, 4($sp)
	jal printList	#Print sorted list
	
	li $v0, 4 
	la $a0, str3 
	syscall 
	li $v0, 5	#Read search key from user
	syscall
	move $a2, $v0
	lw $a0, 4($sp)
	jal bSearch	#Call bSearch to perform binary search
	
	beq $v0, $0, notFound
	li $v0, 4 
	la $a0, strYes 
	syscall 
	j end
	
notFound:
	li $v0, 4 
	la $a0, strNo 
	syscall 
end:
	lw $ra, 0($sp)
	addi $sp, $sp 8
	li $v0, 10 
	syscall
	
	
#printList takes in a list and its size as arguments. 
#It prints all the elements in one line.
printList:
	#Your implementation of printList here	
	la $t0, ($a0) # pointer t0 = address of array
	la $t2, ($a0) # for later on a0 became original_list again
	li $t1, 0 # t1 = loop counter
	
	printLoop:
		beq $t1, $a1, printEnd # loop to keep printing elements of list
		
		# print array[i]
		li $v0, 1
		lw $a0, ($t0)
		syscall
		
		# print space
		li $v0, 11
		li $a0, 32
		syscall
		
		# array[i+1] and loop counter+1
		addi $t1, $t1, 1
		addi $t0, $t0, 4
		j printLoop
	
	printEnd:
		# print "\n"
		li $v0, 11
		li $a0, 10
		syscall
		
		# make a0 become original_list again and pass to next function
		la $a0, ($t2)
		
		jr $ra
	
	
#inSort takes in a list and it size as arguments. 
#It performs INSERTION sort in ascending order and returns a new sorted list
#You may use the pre-defined sorted_list to store the result
inSort:
	#Your implementation of inSort here
	li $t1, 1 # i = 1
	move $t6, $a1 # give the size of list to t6
	subi $t6, $t6, 1 # t6 = size -1
	la $v0, ($a0) # give the address of list to v0
	forLoop: # for loop
		bgt $t1, $t6, forLoop_end # for (i=0; i < size; i++)
		subi $t2, $t1, 1 # j = i - 1
		mul $t3, $t1, 4 # offset
		add $t3, $v0, $t3 # address of list[i]
		lw $t4, 0($t3) # key(t4) = list[i]
		whileLoop: # while loop
			blt $t2, $zero, whileLoop_end # when j < 0, dont run while-loop
			mul $t3, $t2, 4  # offset for list[j]
			add $t3, $v0, $t3 # address of list[j]
			lw $t5, 0($t3) # get value of list[j]
			ble $t5, $t4, whileLoop_end # when list[j] <= key, dont run while-loop
			sw $t5, 4($t3) # get value of list[j+1]
			sub $t2, $t2, 1 # j = j -1
			j whileLoop # keep looping
		whileLoop_end:
			mul $t3, $t2, 4 # offset
			add $t3, $v0, $t3 # address of list[j]
			sw $t4, 4($t3) # get value of list[j+1]
			addi $t1, $t1, 1 # add 1 to i for for-loop
			j forLoop # keep for-loop
	forLoop_end:
		sw $v0, sorted_list # save sorted list into sorted_list
		jr $ra
	
	
#bSearch takes in a list, its size, and a search key as arguments.
#It performs binary search RECURSIVELY to look for the search key.
#It will return a 1 if the key is found, or a 0 otherwise.
#Note: you MUST NOT use iterative approach in this function.
bSearch:
	#Your implementation of bSearch here
	# assign stack
	addi $sp, $sp, -4
	sw $ra, 0($sp)
	
	# load address of list to t0
	la $t0, ($a0)

	# base case
	search:
		blez $a1, false # size less than or equals to 0 means no element matches to the key
		subi $s0, $a1, 1 # s0 = size -1
		div $t1, $s0, 2 # t1 = [mid]
		bltz $t1, false # mid index less than 0 means no element matches to the key
		mul $t2, $t1, 4 # calculate offset
		add $t0, $t0, $t2 # get address of the middle element
		lw $s1, ($t0) # s1 = list[mid]
		beq $s1, $a2, true # list[mid] == key, done, recover stack
		blt $a2, $s1, go_left # when key is less than middle element, go left
	go_right: # when key > array[mid]
		addi $a0, $t0, 4 # a0=list[mid+1]
		sub $a1, $a1, $t1 # new size = old size - mid - 1
		subi $a1, $a1, 1 # a1 is new size of list
		jal bSearch
		b return
		
	go_left: # when key < list[mid]
		move $a1, $t1 # mid index becomes to the size of array, if key < list[mid]
		jal bSearch
		b return
		
	true: # if element is found
		li $v0, 1
		j return
		
	false: # if no elements in array is match to the key
		li $v0, 0
		j return
		
	return: # recover stack
		lw $ra, 0($sp)
		addi $sp, $sp, 4
		jr $ra
	
