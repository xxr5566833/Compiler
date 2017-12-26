#³õÊ¼»¯×Ö·û´®
	.data
	$Message0:.asciiz"please give me your max index in range from 2 to 45 :"
	$Message1:.asciiz"num is less than 2!"
	$Message2:.asciiz"num is more than 45!"
	$Message3:.asciiz"error"
	$Message4:.asciiz" "
	$Message5:.asciiz", "
	$Message6:.asciiz"this is a quick sort, input count of numbers in the first line:"
	$Message7:.asciiz"input your raw array, split numbers with space:"
	$Message8:.asciiz"invalid length!"
	$Message9:.asciiz"exchange time of numbers:"
	$Message10:.asciiz" "
	$Message11:.asciiz" "
	$Message12:.asciiz" "
	$Message13:.asciiz" "
	$Message14:.asciiz" "
	$Message15:.asciiz" "
	$Message16:.asciiz" "
	$Message17:.asciiz" "
	$Message18:.asciiz" "
	$Message19:.asciiz" "
	$Message20:.asciiz" "
	$Message21:.asciiz" "
	$Message22:.asciiz" "
	$Message23:.asciiz" "
	$Message24:.asciiz" "
	$Message25:.asciiz" "
	$Message26:.asciiz" "
	$Message27:.asciiz" "
	$Message28:.asciiz" "
	$Message29:.asciiz" "
	$Message30:.asciiz" "
	$Message31:.asciiz" "
	$Message32:.asciiz" "
	$Message33:.asciiz" "
	$Message34:.asciiz" "
	$Message35:.asciiz" "
	$Message36:.asciiz" "
	$Message37:.asciiz" "
	$Message38:.asciiz" "
	$Message39:.asciiz" "
	$Message40:.asciiz" "
	$Message41:.asciiz" "
	$Message42:.asciiz" "
	$Message43:.asciiz" "
	$Message44:.asciiz" "
	$Message45:.asciiz" "
	$Message46:.asciiz" "
	$Message47:.asciiz" "
	$Message48:.asciiz" "
	$Message49:.asciiz" "
	$Message50:.asciiz" "
	$Message51:.asciiz"give me your choice  a is Fibonacci  b is quicksort c is expressions print :"
	$Message52:.asciiz"out of range"
	.text
	li	$t9	,	95
	sw	$t9	,	268435856($zero)
	li	$t9	,	97
	sw	$t9	,	268435860($zero)
	li	$t9	,	98
	sw	$t9	,	268435864($zero)
	li	$t9	,	99
	sw	$t9	,	268435868($zero)
	li	$t9	,	100
	sw	$t9	,	268435872($zero)
	li	$t9	,	65
	sw	$t9	,	268435876($zero)
	li	$t9	,	66
	sw	$t9	,	268435880($zero)
	li	$t9	,	67
	sw	$t9	,	268435884($zero)
	li	$t9	,	68
	sw	$t9	,	268435888($zero)
	li	$t9	,	48
	sw	$t9	,	268435892($zero)
	li	$t9	,	49
	sw	$t9	,	268435896($zero)
	li	$t9	,	50
	sw	$t9	,	268435900($zero)
	li	$t9	,	51
	sw	$t9	,	268435904($zero)
	li	$t9	,	52
	sw	$t9	,	268435908($zero)
	li	$t9	,	53
	sw	$t9	,	268435912($zero)
	li	$t9	,	54
	sw	$t9	,	268435916($zero)
	li	$t9	,	55
	sw	$t9	,	268435920($zero)
	li	$t9	,	56
	sw	$t9	,	268435924($zero)
	li	$t9	,	57
	sw	$t9	,	268435928($zero)
	li	$t9	,	43
	sw	$t9	,	268435932($zero)
	li	$t9	,	45
	sw	$t9	,	268435936($zero)
	li	$t9	,	42
	sw	$t9	,	268435940($zero)
	li	$t9	,	47
	sw	$t9	,	268435944($zero)
	li	$t9	,	0
	sw	$t9	,	268435948($zero)
	li	$t9	,	1
	sw	$t9	,	268435952($zero)
	li	$t9	,	256
	sw	$t9	,	268435956($zero)
	li	$t9	,	34545
	sw	$t9	,	268435960($zero)
	li	$t9	,	-400
	sw	$t9	,	268435964($zero)
	li	$t9	,	-888
	sw	$t9	,	268435968($zero)
	li	$t9	,	-1563
	sw	$t9	,	268435972($zero)
	li	$t9	,	567
	sw	$t9	,	268435976($zero)
	li	$t9	,	5
	sw	$t9	,	268435980($zero)
	li	$t9	,	1000
	sw	$t9	,	268435984($zero)
	li	$t9	,	77
	sw	$t9	,	268435988($zero)
	li	$t9	,	56
	sw	$t9	,	268435992($zero)
	add	$fp	,	$sp	,	$zero
	j	main
	nop
fibo:
	addi	$sp	,	$sp	,	4
	sw	$fp	,	-32($sp)
	sw	$ra	,	-36($sp)
	add	$fp	,	$sp	,	$zero
	addi	$sp	,	$sp	,	-40
	lw	$t0	,	0($fp)
	li	$t1	,	0
	add	$t0	,	$t0	,	$t1
	sw	$t0	,	-4($fp)
	lw	$t0	,	-4($fp)
	li	$t1	,	0
	sub	$t0	,	$t0	,	$t1
	bgtz	$t0	,	$label0
	nop
	li	$t0	,	0
	li	$t1	,	0
	add	$t0	,	$t0	,	$t1
	add	$v0	,	$t0	,	$zero
	j	fibo$end
	nop
	j	$label1
	nop
$label0:
$label1:
	lw	$t0	,	0($fp)
	li	$t1	,	0
	add	$t0	,	$t0	,	$t1
	sw	$t0	,	-8($fp)
	lw	$t0	,	-8($fp)
	li	$t1	,	1
	sub	$t0	,	$t0	,	$t1
	bne	$t0	,	$zero	,	$label2
	nop
	li	$t0	,	1
	li	$t1	,	0
	add	$t0	,	$t0	,	$t1
	add	$v0	,	$t0	,	$zero
	j	fibo$end
	nop
	j	$label3
	nop
$label2:
$label3:
	lw	$t0	,	0($fp)
	li	$t1	,	0
	add	$t0	,	$t0	,	$t1
	sw	$t0	,	-12($fp)
	lw	$t0	,	-12($fp)
	li	$t1	,	2
	sub	$t0	,	$t0	,	$t1
	bltz	$t0	,	$label4
	nop
	lw	$t0	,	0($fp)
	li	$t1	,	0
	add	$t0	,	$t0	,	$t1
	sw	$t0	,	-16($fp)
	lw	$t0	,	-16($fp)
	li	$t1	,	1
	sub	$t0	,	$t0	,	$t1
	sw	$t0	,	-16($fp)
	lw	$t0	,	-16($fp)
	sw	$t0	,	0($sp)
	addi	$sp	,	$sp	,	-4
	jal	fibo
	nop
	add	$t0	,	$v0	,	$zero
	li	$t1	,	0
	add	$t0	,	$t0	,	$t1
	sw	$t0	,	-20($fp)
	lw	$t0	,	0($fp)
	li	$t1	,	0
	add	$t0	,	$t0	,	$t1
	sw	$t0	,	-24($fp)
	lw	$t0	,	-24($fp)
	li	$t1	,	2
	sub	$t0	,	$t0	,	$t1
	sw	$t0	,	-24($fp)
	lw	$t0	,	-24($fp)
	sw	$t0	,	0($sp)
	addi	$sp	,	$sp	,	-4
	jal	fibo
	nop
	add	$t0	,	$v0	,	$zero
	li	$t1	,	0
	add	$t0	,	$t0	,	$t1
	sw	$t0	,	-28($fp)
	lw	$t0	,	-20($fp)
	lw	$t1	,	-28($fp)
	add	$t0	,	$t0	,	$t1
	sw	$t0	,	-20($fp)
	lw	$t0	,	-20($fp)
	li	$t1	,	0
	add	$t0	,	$t0	,	$t1
	add	$v0	,	$t0	,	$zero
	j	fibo$end
	nop
	j	$label5
	nop
$label4:
$label5:
fibo$end:
	lw	$ra	,	4($sp)
	lw	$fp	,	8($sp)
	addi	$sp	,	$sp	,	40
	jr	$ra
	nop
main4:
	addi	$sp	,	$sp	,	0
	sw	$fp	,	-12($sp)
	sw	$ra	,	-16($sp)
	add	$fp	,	$sp	,	$zero
	addi	$sp	,	$sp	,	-20
	li	$v0	,	5
	syscall
	add	$t0	,	$v0	,	$zero
	sw	$t0	,	0($fp)
	lw	$t0	,	0($fp)
	li	$t1	,	0
	add	$t0	,	$t0	,	$t1
	sw	$t0	,	-4($fp)
	lw	$t0	,	-4($fp)
	sw	$t0	,	0($sp)
	addi	$sp	,	$sp	,	-4
	jal	fibo
	nop
	add	$t0	,	$v0	,	$zero
	li	$t1	,	0
	add	$t0	,	$t0	,	$t1
	sw	$t0	,	-8($fp)
	li	$v0	,	1
	lw	$a0	,	-8($fp)
	syscall
	j	main4$end
	nop
main4$end:
	lw	$ra	,	4($sp)
	lw	$fp	,	8($sp)
	addi	$sp	,	$sp	,	20
	jr	$ra
	nop
fib:
	addi	$sp	,	$sp	,	4
	sw	$fp	,	-336($sp)
	sw	$ra	,	-340($sp)
	add	$fp	,	$sp	,	$zero
	addi	$sp	,	$sp	,	-344
	lw	$t0	,	0($fp)
	li	$t1	,	0
	add	$t0	,	$t0	,	$t1
	sw	$t0	,	-216($fp)
	li	$t0	,	0
	lw	$t1	,	-216($fp)
	sub	$t0	,	$t0	,	$t1
	sw	$t0	,	-216($fp)
	lw	$t0	,	-216($fp)
	li	$t1	,	-1
	sub	$t0	,	$t0	,	$t1
	bgez	$t0	,	$label6
	nop
	lw	$t0	,	0($fp)
	li	$t1	,	0
	add	$t0	,	$t0	,	$t1
	sw	$t0	,	-220($fp)
	lw	$t0	,	-220($fp)
	li	$t1	,	1
	sub	$t0	,	$t0	,	$t1
	sw	$t0	,	-220($fp)
	lw	$t0	,	-220($fp)
	addi	$t0	,	$t0	,	2037
	sll	$t0	,	$t0	,	2
	lw	$t0	,	268435856($t0)
	sw	$t0	,	-224($fp)
	lw	$t0	,	-224($fp)
	li	$t1	,	-1
	sub	$t0	,	$t0	,	$t1
	bgtz	$t0	,	$label8
	nop
	lw	$t0	,	0($fp)
	li	$t1	,	0
	add	$t0	,	$t0	,	$t1
	sw	$t0	,	-228($fp)
	lw	$t0	,	-228($fp)
	li	$t1	,	1
	sub	$t0	,	$t0	,	$t1
	sw	$t0	,	-228($fp)
	lw	$t0	,	-228($fp)
	sw	$t0	,	0($sp)
	addi	$sp	,	$sp	,	-4
	jal	fib
	nop
	add	$t0	,	$v0	,	$zero
	li	$t1	,	0
	add	$t0	,	$t0	,	$t1
	sw	$t0	,	-232($fp)
	lw	$t0	,	-232($fp)
	li	$t1	,	0
	add	$t0	,	$t0	,	$t1
	sw	$t0	,	-8($fp)
	j	$label9
	nop
$label8:
	lw	$t0	,	0($fp)
	li	$t1	,	0
	add	$t0	,	$t0	,	$t1
	sw	$t0	,	-236($fp)
	lw	$t0	,	-236($fp)
	li	$t1	,	1
	sub	$t0	,	$t0	,	$t1
	sw	$t0	,	-236($fp)
	lw	$t0	,	-236($fp)
	addi	$t0	,	$t0	,	2037
	sll	$t0	,	$t0	,	2
	lw	$t0	,	268435856($t0)
	sw	$t0	,	-240($fp)
	lw	$t0	,	-240($fp)
	li	$t1	,	0
	add	$t0	,	$t0	,	$t1
	sw	$t0	,	-8($fp)
$label9:
	lw	$t0	,	0($fp)
	li	$t1	,	0
	add	$t0	,	$t0	,	$t1
	sw	$t0	,	-244($fp)
	lw	$t0	,	-244($fp)
	li	$t1	,	2
	sub	$t0	,	$t0	,	$t1
	sw	$t0	,	-244($fp)
	lw	$t0	,	-244($fp)
	addi	$t0	,	$t0	,	2037
	sll	$t0	,	$t0	,	2
	lw	$t0	,	268435856($t0)
	sw	$t0	,	-248($fp)
	lw	$t0	,	-248($fp)
	li	$t1	,	0
	add	$t0	,	$t0	,	$t1
	sw	$t0	,	-12($fp)
	lw	$t0	,	-8($fp)
	li	$t1	,	0
	add	$t0	,	$t0	,	$t1
	sw	$t0	,	-252($fp)
	lw	$t0	,	-12($fp)
	li	$t1	,	0
	add	$t0	,	$t0	,	$t1
	sw	$t0	,	-256($fp)
	lw	$t0	,	-252($fp)
	lw	$t1	,	-256($fp)
	add	$t0	,	$t0	,	$t1
	sw	$t0	,	-252($fp)
	lw	$t0	,	-252($fp)
	li	$t1	,	0
	add	$t0	,	$t0	,	$t1
	sw	$t0	,	-4($fp)
	lw	$t0	,	0($fp)
	li	$t1	,	0
	add	$t0	,	$t0	,	$t1
	sw	$t0	,	-260($fp)
	lw	$t0	,	-4($fp)
	li	$t1	,	0
	add	$t0	,	$t0	,	$t1
	sw	$t0	,	-264($fp)
	lw	$t1	,	-260($fp)
	addi	$t1	,	$t1	,	2037
	sll	$t0	,	$t1	,	2
	lw	$t1	,	-264($fp)
	sw	$t1	,	268435856($t0)
	lw	$t0	,	-4($fp)
	li	$t1	,	0
	add	$t0	,	$t0	,	$t1
	sw	$t0	,	-268($fp)
	lw	$t0	,	-268($fp)
	li	$t1	,	0
	add	$t0	,	$t0	,	$t1
	add	$v0	,	$t0	,	$zero
	j	fib$end
	nop
	j	$label7
	nop
$label6:
	lw	$t0	,	0($fp)
	li	$t1	,	0
	add	$t0	,	$t0	,	$t1
	sw	$t0	,	-272($fp)
	lw	$t0	,	0($fp)
	li	$t1	,	0
	add	$t0	,	$t0	,	$t1
	sw	$t0	,	-276($fp)
	lw	$t0	,	-276($fp)
	li	$t1	,	1
	add	$t0	,	$t0	,	$t1
	sw	$t0	,	-276($fp)
	lw	$t0	,	-272($fp)
	lw	$t1	,	-276($fp)
	mul	$t0	,	$t0	,	$t1
	sw	$t0	,	-272($fp)
	lw	$t0	,	0($fp)
	li	$t1	,	0
	add	$t0	,	$t0	,	$t1
	sw	$t0	,	-280($fp)
	lw	$t0	,	-280($fp)
	li	$t1	,	1
	add	$t0	,	$t0	,	$t1
	sw	$t0	,	-280($fp)
	lw	$t0	,	-272($fp)
	lw	$t1	,	-280($fp)
	div	$t0	,	$t1
	mflo	$t0
	sw	$t0	,	-272($fp)
	lw	$t0	,	-272($fp)
	li	$t1	,	0
	sub	$t0	,	$t0	,	$t1
	beq	$t0	,	$zero	,	$label10
	nop
	li	$t0	,	1
	li	$t1	,	0
	add	$t0	,	$t0	,	$t1
	sw	$t0	,	-284($fp)
	li	$t1	,	1
	addi	$t1	,	$t1	,	2037
	sll	$t0	,	$t1	,	2
	lw	$t1	,	-284($fp)
	sw	$t1	,	268435856($t0)
	li	$t0	,	1
	li	$t1	,	0
	add	$t0	,	$t0	,	$t1
	sw	$t0	,	-288($fp)
	li	$t1	,	1
	addi	$t1	,	$t1	,	4
	sll	$t0	,	$t1	,	2
	lw	$t1	,	-288($fp)
	sub	$t0	,	$fp	,	$t0
	sw	$t1	,	0($t0)
	li	$t0	,	1
	addi	$t0	,	$t0	,	4
	sll	$t0	,	$t0	,	2
	sub	$t0	,	$fp	,	$t0
	lw	$t0	,	0($t0)
	sw	$t0	,	-292($fp)
	lw	$t0	,	-292($fp)
	addi	$t0	,	$t0	,	2037
	sll	$t0	,	$t0	,	2
	lw	$t0	,	268435856($t0)
	sw	$t0	,	-296($fp)
	lw	$t0	,	-296($fp)
	addi	$t0	,	$t0	,	4
	sll	$t0	,	$t0	,	2
	sub	$t0	,	$fp	,	$t0
	lw	$t0	,	0($t0)
	sw	$t0	,	-300($fp)
	li	$t0	,	1
	addi	$t0	,	$t0	,	4
	sll	$t0	,	$t0	,	2
	sub	$t0	,	$fp	,	$t0
	lw	$t0	,	0($t0)
	sw	$t0	,	-304($fp)
	lw	$t0	,	-304($fp)
	addi	$t0	,	$t0	,	2037
	sll	$t0	,	$t0	,	2
	lw	$t0	,	268435856($t0)
	sw	$t0	,	-308($fp)
	lw	$t0	,	-300($fp)
	lw	$t1	,	-308($fp)
	mul	$t0	,	$t0	,	$t1
	sw	$t0	,	-300($fp)
	lw	$t0	,	-300($fp)
	li	$t1	,	0
	add	$t0	,	$t0	,	$t1
	sw	$t0	,	-300($fp)
	lw	$t0	,	-300($fp)
	li	$t1	,	0
	add	$t0	,	$t0	,	$t1
	add	$v0	,	$t0	,	$zero
	j	fib$end
	nop
	j	$label11
	nop
$label10:
	li	$t0	,	0
	li	$t1	,	0
	add	$t0	,	$t0	,	$t1
	sw	$t0	,	-312($fp)
	li	$t1	,	0
	addi	$t1	,	$t1	,	2037
	sll	$t0	,	$t1	,	2
	lw	$t1	,	-312($fp)
	sw	$t1	,	268435856($t0)
	li	$t0	,	0
	li	$t1	,	0
	add	$t0	,	$t0	,	$t1
	sw	$t0	,	-316($fp)
	li	$t1	,	0
	addi	$t1	,	$t1	,	4
	sll	$t0	,	$t1	,	2
	lw	$t1	,	-316($fp)
	sub	$t0	,	$fp	,	$t0
	sw	$t1	,	0($t0)
	li	$t0	,	0
	addi	$t0	,	$t0	,	2037
	sll	$t0	,	$t0	,	2
	lw	$t0	,	268435856($t0)
	sw	$t0	,	-320($fp)
	lw	$t0	,	-320($fp)
	addi	$t0	,	$t0	,	4
	sll	$t0	,	$t0	,	2
	sub	$t0	,	$fp	,	$t0
	lw	$t0	,	0($t0)
	sw	$t0	,	-324($fp)
	li	$t0	,	0
	addi	$t0	,	$t0	,	4
	sll	$t0	,	$t0	,	2
	sub	$t0	,	$fp	,	$t0
	lw	$t0	,	0($t0)
	sw	$t0	,	-328($fp)
	lw	$t0	,	-328($fp)
	addi	$t0	,	$t0	,	2037
	sll	$t0	,	$t0	,	2
	lw	$t0	,	268435856($t0)
	sw	$t0	,	-332($fp)
	lw	$t0	,	-324($fp)
	lw	$t1	,	-332($fp)
	mul	$t0	,	$t0	,	$t1
	sw	$t0	,	-324($fp)
	lw	$t0	,	-324($fp)
	li	$t1	,	0
	add	$t0	,	$t0	,	$t1
	sw	$t0	,	-324($fp)
	lw	$t0	,	-324($fp)
	li	$t1	,	0
	add	$t0	,	$t0	,	$t1
	add	$v0	,	$t0	,	$zero
	j	fib$end
	nop
$label11:
$label7:
fib$end:
	lw	$ra	,	4($sp)
	lw	$fp	,	8($sp)
	addi	$sp	,	$sp	,	344
	jr	$ra
	nop
main1:
	addi	$sp	,	$sp	,	0
	sw	$fp	,	-92($sp)
	sw	$ra	,	-96($sp)
	add	$fp	,	$sp	,	$zero
	addi	$sp	,	$sp	,	-100
	li	$t0	,	0
	li	$t1	,	0
	add	$t0	,	$t0	,	$t1
	sw	$t0	,	0($fp)
$label12:
	lw	$t0	,	0($fp)
	li	$t1	,	0
	add	$t0	,	$t0	,	$t1
	sw	$t0	,	-4($fp)
	lw	$t0	,	-4($fp)
	li	$t1	,	46
	sub	$t0	,	$t0	,	$t1
	bgez	$t0	,	$label13
	nop
	lw	$t0	,	0($fp)
	li	$t1	,	0
	add	$t0	,	$t0	,	$t1
	sw	$t0	,	-8($fp)
	li	$t0	,	-1
	li	$t1	,	0
	add	$t0	,	$t0	,	$t1
	sw	$t0	,	-12($fp)
	lw	$t1	,	-8($fp)
	addi	$t1	,	$t1	,	3037
	sll	$t0	,	$t1	,	2
	lw	$t1	,	-12($fp)
	sw	$t1	,	268435856($t0)
	lw	$t0	,	0($fp)
	li	$t1	,	0
	add	$t0	,	$t0	,	$t1
	sw	$t0	,	-16($fp)
	li	$t0	,	-1
	li	$t1	,	0
	add	$t0	,	$t0	,	$t1
	sw	$t0	,	-20($fp)
	lw	$t1	,	-16($fp)
	addi	$t1	,	$t1	,	2037
	sll	$t0	,	$t1	,	2
	lw	$t1	,	-20($fp)
	sw	$t1	,	268435856($t0)
	lw	$t0	,	0($fp)
	li	$t1	,	0
	add	$t0	,	$t0	,	$t1
	sw	$t0	,	-24($fp)
	lw	$t0	,	-24($fp)
	li	$t1	,	0
	add	$t0	,	$t0	,	$t1
	sw	$t0	,	-24($fp)
	li	$t0	,	48
	li	$t1	,	0
	add	$t0	,	$t0	,	$t1
	sw	$t0	,	-28($fp)
	lw	$t1	,	-24($fp)
	addi	$t1	,	$t1	,	35
	sll	$t0	,	$t1	,	2
	lw	$t1	,	-28($fp)
	sw	$t1	,	268435856($t0)
	lw	$t0	,	0($fp)
	li	$t1	,	0
	add	$t0	,	$t0	,	$t1
	sw	$t0	,	-32($fp)
	li	$t0	,	48
	li	$t1	,	0
	add	$t0	,	$t0	,	$t1
	sw	$t0	,	-36($fp)
	lw	$t1	,	-32($fp)
	addi	$t1	,	$t1	,	1035
	sll	$t0	,	$t1	,	2
	lw	$t1	,	-36($fp)
	sw	$t1	,	268435856($t0)
	lw	$t0	,	0($fp)
	li	$t1	,	0
	add	$t0	,	$t0	,	$t1
	sw	$t0	,	-40($fp)
	lw	$t0	,	-40($fp)
	li	$t1	,	1
	add	$t0	,	$t0	,	$t1
	sw	$t0	,	-40($fp)
	lw	$t0	,	-40($fp)
	li	$t1	,	0
	sub	$t0	,	$t0	,	$t1
	sw	$t0	,	-40($fp)
	lw	$t0	,	-40($fp)
	li	$t1	,	0
	add	$t0	,	$t0	,	$t1
	sw	$t0	,	0($fp)
	j	$label12
	nop
$label13:
	li	$t0	,	0
	li	$t1	,	0
	add	$t0	,	$t0	,	$t1
	sw	$t0	,	268452004($zero)
	li	$v0	,	4
	la	$a0	,	$Message0
	syscall
	li	$v0	,	5
	syscall
	add	$t0	,	$v0	,	$zero
	sw	$t0	,	268452004($zero)
	lw	$t0	,	268452004($zero)
	li	$t1	,	0
	add	$t0	,	$t0	,	$t1
	sw	$t0	,	-44($fp)
	lw	$t0	,	-44($fp)
	li	$t1	,	2
	sub	$t0	,	$t0	,	$t1
	bgez	$t0	,	$label14
	nop
	li	$v0	,	4
	la	$a0	,	$Message1
	syscall
	j	$label15
	nop
$label14:
	lw	$t0	,	268452004($zero)
	li	$t1	,	0
	add	$t0	,	$t0	,	$t1
	sw	$t0	,	-48($fp)
	lw	$t0	,	-48($fp)
	li	$t1	,	45
	sub	$t0	,	$t0	,	$t1
	blez	$t0	,	$label16
	nop
	li	$v0	,	4
	la	$a0	,	$Message2
	syscall
	j	$label17
	nop
$label16:
	lw	$t0	,	268452004($zero)
	li	$t1	,	0
	add	$t0	,	$t0	,	$t1
	sw	$t0	,	-52($fp)
	li	$t0	,	0
	sw	$t0	,	0($sp)
	addi	$sp	,	$sp	,	-4
	jal	fib
	nop
	add	$t0	,	$v0	,	$zero
	li	$t1	,	0
	add	$t0	,	$t0	,	$t1
	sw	$t0	,	-56($fp)
	lw	$t0	,	-52($fp)
	lw	$t1	,	-56($fp)
	add	$t0	,	$t0	,	$t1
	sw	$t0	,	-52($fp)
	li	$t0	,	1
	sw	$t0	,	0($sp)
	addi	$sp	,	$sp	,	-4
	jal	fib
	nop
	add	$t0	,	$v0	,	$zero
	li	$t1	,	0
	add	$t0	,	$t0	,	$t1
	sw	$t0	,	-60($fp)
	lw	$t0	,	-52($fp)
	lw	$t1	,	-60($fp)
	sub	$t0	,	$t0	,	$t1
	sw	$t0	,	-52($fp)
	li	$t0	,	2
	sw	$t0	,	0($sp)
	addi	$sp	,	$sp	,	-4
	jal	fib
	nop
	add	$t0	,	$v0	,	$zero
	li	$t1	,	0
	add	$t0	,	$t0	,	$t1
	sw	$t0	,	-64($fp)
	lw	$t0	,	-52($fp)
	lw	$t1	,	-64($fp)
	add	$t0	,	$t0	,	$t1
	sw	$t0	,	-52($fp)
	lw	$t0	,	-52($fp)
	sw	$t0	,	0($sp)
	addi	$sp	,	$sp	,	-4
	jal	fib
	nop
$label18:
	lw	$t0	,	268452004($zero)
	li	$t1	,	0
	add	$t0	,	$t0	,	$t1
	sw	$t0	,	-68($fp)
	lw	$t0	,	-68($fp)
	li	$t1	,	0
	sub	$t0	,	$t0	,	$t1
	bltz	$t0	,	$label19
	nop
	lw	$t0	,	268452004($zero)
	li	$t1	,	0
	add	$t0	,	$t0	,	$t1
	sw	$t0	,	-72($fp)
	lw	$t0	,	-72($fp)
	addi	$t0	,	$t0	,	2037
	sll	$t0	,	$t0	,	2
	lw	$t0	,	268435856($t0)
	sw	$t0	,	-76($fp)
	li	$t0	,	0
	lw	$t1	,	-76($fp)
	sub	$t0	,	$t0	,	$t1
	sw	$t0	,	-76($fp)
	li	$t0	,	0
	lw	$t1	,	-76($fp)
	sub	$t0	,	$t0	,	$t1
	sw	$t0	,	-76($fp)
	li	$v0	,	1
	lw	$a0	,	-76($fp)
	syscall
	lw	$t0	,	268452004($zero)
	li	$t1	,	0
	add	$t0	,	$t0	,	$t1
	sw	$t0	,	-80($fp)
	lw	$t0	,	-80($fp)
	addi	$t0	,	$t0	,	3037
	sll	$t0	,	$t0	,	2
	lw	$t0	,	268435856($t0)
	sw	$t0	,	-84($fp)
	lw	$t0	,	-84($fp)
	li	$t1	,	-1
	sub	$t0	,	$t0	,	$t1
	beq	$t0	,	$zero	,	$label20
	nop
	li	$v0	,	4
	la	$a0	,	$Message3
	syscall
	j	$label21
	nop
$label20:
$label21:
	li	$v0	,	4
	la	$a0	,	$Message4
	syscall
	lw	$t0	,	268452004($zero)
	li	$t1	,	0
	add	$t0	,	$t0	,	$t1
	sw	$t0	,	-88($fp)
	lw	$t0	,	-88($fp)
	li	$t1	,	1
	sub	$t0	,	$t0	,	$t1
	sw	$t0	,	-88($fp)
	lw	$t0	,	-88($fp)
	li	$t1	,	0
	add	$t0	,	$t0	,	$t1
	sw	$t0	,	268452004($zero)
	j	$label18
	nop
$label19:
$label17:
$label15:
main1$end:
	lw	$ra	,	4($sp)
	lw	$fp	,	8($sp)
	addi	$sp	,	$sp	,	100
	jr	$ra
	nop
printarray:
	addi	$sp	,	$sp	,	0
	sw	$fp	,	-32($sp)
	sw	$ra	,	-36($sp)
	add	$fp	,	$sp	,	$zero
	addi	$sp	,	$sp	,	-40
	li	$t0	,	1
	li	$t1	,	0
	add	$t0	,	$t0	,	$t1
	sw	$t0	,	0($fp)
	lw	$t0	,	268456412($zero)
	li	$t1	,	0
	add	$t0	,	$t0	,	$t1
	sw	$t0	,	-4($fp)
	lw	$t0	,	-4($fp)
	li	$t1	,	1
	sub	$t0	,	$t0	,	$t1
	bltz	$t0	,	$label22
	nop
	li	$t0	,	0
	addi	$t0	,	$t0	,	5038
	sll	$t0	,	$t0	,	2
	lw	$t0	,	268435856($t0)
	sw	$t0	,	-8($fp)
	li	$v0	,	1
	lw	$a0	,	-8($fp)
	syscall
	j	$label23
	nop
$label22:
	li	$t0	,	-1
	li	$t1	,	0
	add	$t0	,	$t0	,	$t1
	add	$v0	,	$t0	,	$zero
	j	printarray$end
	nop
$label23:
$label24:
	lw	$t0	,	0($fp)
	li	$t1	,	0
	add	$t0	,	$t0	,	$t1
	sw	$t0	,	-12($fp)
	lw	$t0	,	268456412($zero)
	li	$t1	,	0
	add	$t0	,	$t0	,	$t1
	sw	$t0	,	-16($fp)
	lw	$t0	,	-12($fp)
	lw	$t1	,	-16($fp)
	sub	$t0	,	$t0	,	$t1
	bgez	$t0	,	$label25
	nop
	li	$v0	,	4
	la	$a0	,	$Message5
	syscall
	lw	$t0	,	0($fp)
	li	$t1	,	0
	add	$t0	,	$t0	,	$t1
	sw	$t0	,	-20($fp)
	lw	$t0	,	-20($fp)
	addi	$t0	,	$t0	,	5038
	sll	$t0	,	$t0	,	2
	lw	$t0	,	268435856($t0)
	sw	$t0	,	-24($fp)
	li	$v0	,	1
	lw	$a0	,	-24($fp)
	syscall
	lw	$t0	,	0($fp)
	li	$t1	,	0
	add	$t0	,	$t0	,	$t1
	sw	$t0	,	-28($fp)
	lw	$t0	,	-28($fp)
	li	$t1	,	1
	add	$t0	,	$t0	,	$t1
	sw	$t0	,	-28($fp)
	lw	$t0	,	-28($fp)
	li	$t1	,	0
	add	$t0	,	$t0	,	$t1
	sw	$t0	,	0($fp)
	j	$label24
	nop
$label25:
	li	$t0	,	0
	li	$t1	,	0
	add	$t0	,	$t0	,	$t1
	add	$v0	,	$t0	,	$zero
	j	printarray$end
	nop
printarray$end:
	lw	$ra	,	4($sp)
	lw	$fp	,	8($sp)
	addi	$sp	,	$sp	,	40
	jr	$ra
	nop
quicksort:
	addi	$sp	,	$sp	,	8
	sw	$fp	,	-144($sp)
	sw	$ra	,	-148($sp)
	add	$fp	,	$sp	,	$zero
	addi	$sp	,	$sp	,	-152
	lw	$t0	,	0($fp)
	li	$t1	,	0
	add	$t0	,	$t0	,	$t1
	sw	$t0	,	-20($fp)
	lw	$t0	,	-4($fp)
	li	$t1	,	0
	add	$t0	,	$t0	,	$t1
	sw	$t0	,	-24($fp)
	lw	$t0	,	-20($fp)
	lw	$t1	,	-24($fp)
	sub	$t0	,	$t0	,	$t1
	bltz	$t0	,	$label26
	nop
	j	quicksort$end
	nop
	j	$label27
	nop
$label26:
$label27:
	lw	$t0	,	0($fp)
	li	$t1	,	0
	add	$t0	,	$t0	,	$t1
	sw	$t0	,	-28($fp)
	lw	$t0	,	-28($fp)
	li	$t1	,	1
	add	$t0	,	$t0	,	$t1
	sw	$t0	,	-28($fp)
	lw	$t0	,	-28($fp)
	li	$t1	,	0
	add	$t0	,	$t0	,	$t1
	sw	$t0	,	-8($fp)
	lw	$t0	,	0($fp)
	li	$t1	,	0
	add	$t0	,	$t0	,	$t1
	sw	$t0	,	-32($fp)
	lw	$t0	,	-32($fp)
	li	$t1	,	0
	add	$t0	,	$t0	,	$t1
	sw	$t0	,	-12($fp)
$label28:
	lw	$t0	,	-8($fp)
	li	$t1	,	0
	add	$t0	,	$t0	,	$t1
	sw	$t0	,	-36($fp)
	lw	$t0	,	-4($fp)
	li	$t1	,	0
	add	$t0	,	$t0	,	$t1
	sw	$t0	,	-40($fp)
	lw	$t0	,	-36($fp)
	lw	$t1	,	-40($fp)
	sub	$t0	,	$t0	,	$t1
	bgtz	$t0	,	$label29
	nop
	lw	$t0	,	-8($fp)
	li	$t1	,	0
	add	$t0	,	$t0	,	$t1
	sw	$t0	,	-44($fp)
	lw	$t0	,	-44($fp)
	addi	$t0	,	$t0	,	5038
	sll	$t0	,	$t0	,	2
	lw	$t0	,	268435856($t0)
	sw	$t0	,	-48($fp)
	lw	$t0	,	-12($fp)
	li	$t1	,	0
	add	$t0	,	$t0	,	$t1
	sw	$t0	,	-52($fp)
	lw	$t0	,	-52($fp)
	addi	$t0	,	$t0	,	5038
	sll	$t0	,	$t0	,	2
	lw	$t0	,	268435856($t0)
	sw	$t0	,	-56($fp)
	lw	$t0	,	-48($fp)
	lw	$t1	,	-56($fp)
	sub	$t0	,	$t0	,	$t1
	bgez	$t0	,	$label30
	nop
	lw	$t0	,	-8($fp)
	li	$t1	,	0
	add	$t0	,	$t0	,	$t1
	sw	$t0	,	-60($fp)
	lw	$t0	,	-60($fp)
	addi	$t0	,	$t0	,	5038
	sll	$t0	,	$t0	,	2
	lw	$t0	,	268435856($t0)
	sw	$t0	,	-64($fp)
	lw	$t0	,	-64($fp)
	li	$t1	,	0
	add	$t0	,	$t0	,	$t1
	sw	$t0	,	-16($fp)
	lw	$t0	,	-8($fp)
	li	$t1	,	0
	add	$t0	,	$t0	,	$t1
	sw	$t0	,	-68($fp)
	lw	$t0	,	-12($fp)
	li	$t1	,	0
	add	$t0	,	$t0	,	$t1
	sw	$t0	,	-72($fp)
	lw	$t0	,	-72($fp)
	addi	$t0	,	$t0	,	5038
	sll	$t0	,	$t0	,	2
	lw	$t0	,	268435856($t0)
	sw	$t0	,	-76($fp)
	lw	$t1	,	-68($fp)
	addi	$t1	,	$t1	,	5038
	sll	$t0	,	$t1	,	2
	lw	$t1	,	-76($fp)
	sw	$t1	,	268435856($t0)
	lw	$t0	,	-12($fp)
	li	$t1	,	0
	add	$t0	,	$t0	,	$t1
	sw	$t0	,	-80($fp)
	lw	$t0	,	-16($fp)
	li	$t1	,	0
	add	$t0	,	$t0	,	$t1
	sw	$t0	,	-84($fp)
	lw	$t1	,	-80($fp)
	addi	$t1	,	$t1	,	5038
	sll	$t0	,	$t1	,	2
	lw	$t1	,	-84($fp)
	sw	$t1	,	268435856($t0)
	lw	$t0	,	-8($fp)
	li	$t1	,	0
	add	$t0	,	$t0	,	$t1
	sw	$t0	,	-88($fp)
	lw	$t0	,	-88($fp)
	addi	$t0	,	$t0	,	5038
	sll	$t0	,	$t0	,	2
	lw	$t0	,	268435856($t0)
	sw	$t0	,	-92($fp)
	lw	$t0	,	-92($fp)
	li	$t1	,	0
	add	$t0	,	$t0	,	$t1
	sw	$t0	,	-16($fp)
	lw	$t0	,	-8($fp)
	li	$t1	,	0
	add	$t0	,	$t0	,	$t1
	sw	$t0	,	-96($fp)
	lw	$t0	,	-12($fp)
	li	$t1	,	0
	add	$t0	,	$t0	,	$t1
	sw	$t0	,	-100($fp)
	lw	$t0	,	-100($fp)
	li	$t1	,	1
	add	$t0	,	$t0	,	$t1
	sw	$t0	,	-100($fp)
	lw	$t0	,	-100($fp)
	addi	$t0	,	$t0	,	5038
	sll	$t0	,	$t0	,	2
	lw	$t0	,	268435856($t0)
	sw	$t0	,	-104($fp)
	lw	$t1	,	-96($fp)
	addi	$t1	,	$t1	,	5038
	sll	$t0	,	$t1	,	2
	lw	$t1	,	-104($fp)
	sw	$t1	,	268435856($t0)
	lw	$t0	,	-12($fp)
	li	$t1	,	0
	add	$t0	,	$t0	,	$t1
	sw	$t0	,	-108($fp)
	lw	$t0	,	-108($fp)
	li	$t1	,	1
	add	$t0	,	$t0	,	$t1
	sw	$t0	,	-108($fp)
	lw	$t0	,	-16($fp)
	li	$t1	,	0
	add	$t0	,	$t0	,	$t1
	sw	$t0	,	-112($fp)
	lw	$t1	,	-108($fp)
	addi	$t1	,	$t1	,	5038
	sll	$t0	,	$t1	,	2
	lw	$t1	,	-112($fp)
	sw	$t1	,	268435856($t0)
	lw	$t0	,	-12($fp)
	li	$t1	,	0
	add	$t0	,	$t0	,	$t1
	sw	$t0	,	-116($fp)
	lw	$t0	,	-116($fp)
	li	$t1	,	1
	add	$t0	,	$t0	,	$t1
	sw	$t0	,	-116($fp)
	lw	$t0	,	-116($fp)
	li	$t1	,	0
	add	$t0	,	$t0	,	$t1
	sw	$t0	,	-12($fp)
	lw	$t0	,	268456408($zero)
	li	$t1	,	0
	add	$t0	,	$t0	,	$t1
	sw	$t0	,	-120($fp)
	lw	$t0	,	-120($fp)
	li	$t1	,	1
	add	$t0	,	$t0	,	$t1
	sw	$t0	,	-120($fp)
	lw	$t0	,	-120($fp)
	li	$t1	,	0
	add	$t0	,	$t0	,	$t1
	sw	$t0	,	268456408($zero)
	j	$label31
	nop
$label30:
$label31:
	lw	$t0	,	-8($fp)
	li	$t1	,	0
	add	$t0	,	$t0	,	$t1
	sw	$t0	,	-124($fp)
	lw	$t0	,	-124($fp)
	li	$t1	,	1
	add	$t0	,	$t0	,	$t1
	sw	$t0	,	-124($fp)
	lw	$t0	,	-124($fp)
	li	$t1	,	0
	add	$t0	,	$t0	,	$t1
	sw	$t0	,	-8($fp)
	j	$label28
	nop
$label29:
	lw	$t0	,	0($fp)
	li	$t1	,	0
	add	$t0	,	$t0	,	$t1
	sw	$t0	,	-128($fp)
	lw	$t0	,	-128($fp)
	sw	$t0	,	0($sp)
	addi	$sp	,	$sp	,	-4
	lw	$t0	,	-12($fp)
	li	$t1	,	0
	add	$t0	,	$t0	,	$t1
	sw	$t0	,	-132($fp)
	lw	$t0	,	-132($fp)
	li	$t1	,	1
	sub	$t0	,	$t0	,	$t1
	sw	$t0	,	-132($fp)
	lw	$t0	,	-132($fp)
	sw	$t0	,	0($sp)
	addi	$sp	,	$sp	,	-4
	jal	quicksort
	nop
	lw	$t0	,	-12($fp)
	li	$t1	,	0
	add	$t0	,	$t0	,	$t1
	sw	$t0	,	-136($fp)
	lw	$t0	,	-136($fp)
	li	$t1	,	1
	add	$t0	,	$t0	,	$t1
	sw	$t0	,	-136($fp)
	lw	$t0	,	-136($fp)
	sw	$t0	,	0($sp)
	addi	$sp	,	$sp	,	-4
	lw	$t0	,	-4($fp)
	li	$t1	,	0
	add	$t0	,	$t0	,	$t1
	sw	$t0	,	-140($fp)
	lw	$t0	,	-140($fp)
	sw	$t0	,	0($sp)
	addi	$sp	,	$sp	,	-4
	jal	quicksort
	nop
	j	quicksort$end
	nop
quicksort$end:
	lw	$ra	,	4($sp)
	lw	$fp	,	8($sp)
	addi	$sp	,	$sp	,	152
	jr	$ra
	nop
return1:
	addi	$sp	,	$sp	,	0
	sw	$fp	,	0($sp)
	sw	$ra	,	-4($sp)
	add	$fp	,	$sp	,	$zero
	addi	$sp	,	$sp	,	-8
	li	$t0	,	1
	li	$t1	,	0
	add	$t0	,	$t0	,	$t1
	add	$v0	,	$t0	,	$zero
	j	return1$end
	nop
return1$end:
	lw	$ra	,	4($sp)
	lw	$fp	,	8($sp)
	addi	$sp	,	$sp	,	8
	jr	$ra
	nop
return999:
	addi	$sp	,	$sp	,	0
	sw	$fp	,	0($sp)
	sw	$ra	,	-4($sp)
	add	$fp	,	$sp	,	$zero
	addi	$sp	,	$sp	,	-8
	li	$t0	,	999
	li	$t1	,	0
	add	$t0	,	$t0	,	$t1
	add	$v0	,	$t0	,	$zero
	j	return999$end
	nop
return999$end:
	lw	$ra	,	4($sp)
	lw	$fp	,	8($sp)
	addi	$sp	,	$sp	,	8
	jr	$ra
	nop
returnminus998:
	addi	$sp	,	$sp	,	0
	sw	$fp	,	0($sp)
	sw	$ra	,	-4($sp)
	add	$fp	,	$sp	,	$zero
	addi	$sp	,	$sp	,	-8
	li	$t0	,	-998
	li	$t1	,	0
	add	$t0	,	$t0	,	$t1
	add	$v0	,	$t0	,	$zero
	j	returnminus998$end
	nop
returnminus998$end:
	lw	$ra	,	4($sp)
	lw	$fp	,	8($sp)
	addi	$sp	,	$sp	,	8
	jr	$ra
	nop
main2:
	addi	$sp	,	$sp	,	0
	sw	$fp	,	-84($sp)
	sw	$ra	,	-88($sp)
	add	$fp	,	$sp	,	$zero
	addi	$sp	,	$sp	,	-92
	li	$t0	,	0
	li	$t1	,	0
	add	$t0	,	$t0	,	$t1
	sw	$t0	,	268456408($zero)
	li	$t0	,	0
	li	$t1	,	0
	add	$t0	,	$t0	,	$t1
	sw	$t0	,	0($fp)
	li	$v0	,	4
	la	$a0	,	$Message6
	syscall
	li	$v0	,	5
	syscall
	add	$t0	,	$v0	,	$zero
	sw	$t0	,	268456412($zero)
	lw	$t0	,	268456412($zero)
	li	$t1	,	0
	add	$t0	,	$t0	,	$t1
	sw	$t0	,	-8($fp)
	lw	$t0	,	-8($fp)
	li	$t1	,	0
	sub	$t0	,	$t0	,	$t1
	beq	$t0	,	$zero	,	$label32
	nop
	lw	$t0	,	268456412($zero)
	li	$t1	,	0
	add	$t0	,	$t0	,	$t1
	sw	$t0	,	-12($fp)
	lw	$t0	,	268456412($zero)
	li	$t1	,	0
	add	$t0	,	$t0	,	$t1
	sw	$t0	,	-16($fp)
	lw	$t0	,	-16($fp)
	lw	$t1	,	268456412($zero)
	mul	$t0	,	$t0	,	$t1
	sw	$t0	,	-16($fp)
	lw	$t0	,	-12($fp)
	lw	$t1	,	-16($fp)
	add	$t0	,	$t0	,	$t1
	sw	$t0	,	-12($fp)
	lw	$t0	,	-12($fp)
	lw	$t1	,	268456412($zero)
	div	$t0	,	$t1
	mflo	$t0
	sw	$t0	,	-12($fp)
	lw	$t0	,	-12($fp)
	li	$t1	,	1
	sub	$t0	,	$t0	,	$t1
	sw	$t0	,	-12($fp)
	lw	$t0	,	-12($fp)
	li	$t1	,	0
	add	$t0	,	$t0	,	$t1
	sw	$t0	,	268456412($zero)
	j	$label33
	nop
$label32:
$label33:
	li	$v0	,	4
	la	$a0	,	$Message7
	syscall
$label34:
	lw	$t0	,	0($fp)
	li	$t1	,	0
	add	$t0	,	$t0	,	$t1
	sw	$t0	,	-20($fp)
	lw	$t0	,	268456412($zero)
	li	$t1	,	0
	add	$t0	,	$t0	,	$t1
	sw	$t0	,	-24($fp)
	lw	$t0	,	-20($fp)
	lw	$t1	,	-24($fp)
	sub	$t0	,	$t0	,	$t1
	bgez	$t0	,	$label35
	nop
	li	$v0	,	5
	syscall
	add	$t0	,	$v0	,	$zero
	sw	$t0	,	-4($fp)
	lw	$t0	,	0($fp)
	li	$t1	,	0
	add	$t0	,	$t0	,	$t1
	sw	$t0	,	-28($fp)
	lw	$t0	,	-4($fp)
	li	$t1	,	0
	add	$t0	,	$t0	,	$t1
	sw	$t0	,	-32($fp)
	lw	$t1	,	-28($fp)
	addi	$t1	,	$t1	,	5038
	sll	$t0	,	$t1	,	2
	lw	$t1	,	-32($fp)
	sw	$t1	,	268435856($t0)
	lw	$t0	,	0($fp)
	li	$t1	,	0
	add	$t0	,	$t0	,	$t1
	sw	$t0	,	-36($fp)
	jal	return999
	nop
	add	$t0	,	$v0	,	$zero
	li	$t1	,	0
	add	$t0	,	$t0	,	$t1
	sw	$t0	,	-40($fp)
	lw	$t0	,	-36($fp)
	lw	$t1	,	-40($fp)
	add	$t0	,	$t0	,	$t1
	sw	$t0	,	-36($fp)
	jal	returnminus998
	nop
	add	$t0	,	$v0	,	$zero
	li	$t1	,	0
	add	$t0	,	$t0	,	$t1
	sw	$t0	,	-44($fp)
	lw	$t0	,	-36($fp)
	lw	$t1	,	-44($fp)
	add	$t0	,	$t0	,	$t1
	sw	$t0	,	-36($fp)
	lw	$t0	,	-36($fp)
	li	$t1	,	0
	add	$t0	,	$t0	,	$t1
	sw	$t0	,	0($fp)
	j	$label34
	nop
$label35:
	lw	$t0	,	268456412($zero)
	li	$t1	,	0
	add	$t0	,	$t0	,	$t1
	sw	$t0	,	-48($fp)
	li	$t0	,	0
	li	$t1	,	0
	add	$t0	,	$t0	,	$t1
	sw	$t0	,	-52($fp)
	lw	$t0	,	-52($fp)
	lw	$t1	,	-48($fp)
	sub	$t0	,	$t0	,	$t1
	bne	$t0	,	$zero	,	$label37
	nop
	jal	printarray
	nop
	j	$label36
	nop
$label37:
	li	$t0	,	1
	li	$t1	,	0
	add	$t0	,	$t0	,	$t1
	sw	$t0	,	-56($fp)
	lw	$t0	,	-56($fp)
	lw	$t1	,	-48($fp)
	sub	$t0	,	$t0	,	$t1
	bne	$t0	,	$zero	,	$label38
	nop
	jal	printarray
	nop
	j	$label36
	nop
$label38:
	lw	$t0	,	268456412($zero)
	li	$t1	,	0
	add	$t0	,	$t0	,	$t1
	sw	$t0	,	-60($fp)
	lw	$t0	,	-60($fp)
	li	$t1	,	0
	sub	$t0	,	$t0	,	$t1
	bgez	$t0	,	$label39
	nop
	li	$v0	,	4
	la	$a0	,	$Message8
	syscall
	j	main2$end
	nop
	j	$label40
	nop
$label39:
	jal	return999
	nop
	add	$t0	,	$v0	,	$zero
	li	$t1	,	0
	add	$t0	,	$t0	,	$t1
	sw	$t0	,	-64($fp)
	lw	$t0	,	-64($fp)
	li	$t1	,	999
	sub	$t0	,	$t0	,	$t1
	sw	$t0	,	-64($fp)
	lw	$t0	,	-64($fp)
	sw	$t0	,	0($sp)
	addi	$sp	,	$sp	,	-4
	lw	$t0	,	268456412($zero)
	li	$t1	,	0
	add	$t0	,	$t0	,	$t1
	sw	$t0	,	-68($fp)
	jal	return999
	nop
	add	$t0	,	$v0	,	$zero
	li	$t1	,	0
	add	$t0	,	$t0	,	$t1
	sw	$t0	,	-72($fp)
	jal	returnminus998
	nop
	add	$t0	,	$v0	,	$zero
	li	$t1	,	0
	add	$t0	,	$t0	,	$t1
	sw	$t0	,	-76($fp)
	lw	$t0	,	-72($fp)
	lw	$t1	,	-76($fp)
	add	$t0	,	$t0	,	$t1
	sw	$t0	,	-72($fp)
	lw	$t0	,	-68($fp)
	lw	$t1	,	-72($fp)
	sub	$t0	,	$t0	,	$t1
	sw	$t0	,	-68($fp)
	lw	$t0	,	-68($fp)
	sw	$t0	,	0($sp)
	addi	$sp	,	$sp	,	-4
	jal	quicksort
	nop
	jal	printarray
	nop
$label40:
$label36:
	li	$v0	,	4
	la	$a0	,	$Message9
	syscall
	lw	$t0	,	268456408($zero)
	li	$t1	,	0
	add	$t0	,	$t0	,	$t1
	sw	$t0	,	-80($fp)
	li	$v0	,	1
	lw	$a0	,	-80($fp)
	syscall
	j	main2$end
	nop
main2$end:
	lw	$ra	,	4($sp)
	lw	$fp	,	8($sp)
	addi	$sp	,	$sp	,	92
	jr	$ra
	nop
returna:
	addi	$sp	,	$sp	,	0
	sw	$fp	,	0($sp)
	sw	$ra	,	-4($sp)
	add	$fp	,	$sp	,	$zero
	addi	$sp	,	$sp	,	-8
	li	$t0	,	97
	li	$t1	,	0
	add	$t0	,	$t0	,	$t1
	add	$v0	,	$t0	,	$zero
	j	returna$end
	nop
returna$end:
	lw	$ra	,	4($sp)
	lw	$fp	,	8($sp)
	addi	$sp	,	$sp	,	8
	jr	$ra
	nop
returnplus:
	addi	$sp	,	$sp	,	0
	sw	$fp	,	0($sp)
	sw	$ra	,	-4($sp)
	add	$fp	,	$sp	,	$zero
	addi	$sp	,	$sp	,	-8
	li	$t0	,	43
	li	$t1	,	0
	add	$t0	,	$t0	,	$t1
	add	$v0	,	$t0	,	$zero
	j	returnplus$end
	nop
returnplus$end:
	lw	$ra	,	4($sp)
	lw	$fp	,	8($sp)
	addi	$sp	,	$sp	,	8
	jr	$ra
	nop
returnstar:
	addi	$sp	,	$sp	,	0
	sw	$fp	,	0($sp)
	sw	$ra	,	-4($sp)
	add	$fp	,	$sp	,	$zero
	addi	$sp	,	$sp	,	-8
	li	$t0	,	42
	li	$t1	,	0
	add	$t0	,	$t0	,	$t1
	add	$v0	,	$t0	,	$zero
	j	returnstar$end
	nop
returnstar$end:
	lw	$ra	,	4($sp)
	lw	$fp	,	8($sp)
	addi	$sp	,	$sp	,	8
	jr	$ra
	nop
returnchar:
	addi	$sp	,	$sp	,	4
	sw	$fp	,	-8($sp)
	sw	$ra	,	-12($sp)
	add	$fp	,	$sp	,	$zero
	addi	$sp	,	$sp	,	-16
	lw	$t0	,	0($fp)
	li	$t1	,	0
	add	$t0	,	$t0	,	$t1
	sw	$t0	,	-4($fp)
	lw	$t0	,	-4($fp)
	li	$t1	,	0
	add	$t0	,	$t0	,	$t1
	add	$v0	,	$t0	,	$zero
	j	returnchar$end
	nop
returnchar$end:
	lw	$ra	,	4($sp)
	lw	$fp	,	8($sp)
	addi	$sp	,	$sp	,	16
	jr	$ra
	nop
main3:
	addi	$sp	,	$sp	,	0
	sw	$fp	,	-588($sp)
	sw	$ra	,	-592($sp)
	add	$fp	,	$sp	,	$zero
	addi	$sp	,	$sp	,	-596
	li	$t0	,	0
	li	$t1	,	0
	add	$t0	,	$t0	,	$t1
	sw	$t0	,	0($fp)
$label41:
	lw	$t0	,	0($fp)
	li	$t1	,	0
	add	$t0	,	$t0	,	$t1
	sw	$t0	,	-4($fp)
	lw	$t0	,	-4($fp)
	li	$t1	,	45
	sub	$t0	,	$t0	,	$t1
	bgez	$t0	,	$label42
	nop
	lw	$t0	,	0($fp)
	li	$t1	,	0
	add	$t0	,	$t0	,	$t1
	sw	$t0	,	-8($fp)
	li	$t0	,	97
	li	$t1	,	0
	add	$t0	,	$t0	,	$t1
	sw	$t0	,	-12($fp)
	lw	$t1	,	-8($fp)
	addi	$t1	,	$t1	,	35
	sll	$t0	,	$t1	,	2
	lw	$t1	,	-12($fp)
	sw	$t1	,	268435856($t0)
	lw	$t0	,	0($fp)
	li	$t1	,	0
	add	$t0	,	$t0	,	$t1
	sw	$t0	,	-16($fp)
	li	$t0	,	100
	li	$t1	,	0
	add	$t0	,	$t0	,	$t1
	sw	$t0	,	-20($fp)
	lw	$t1	,	-16($fp)
	addi	$t1	,	$t1	,	4038
	sll	$t0	,	$t1	,	2
	lw	$t1	,	-20($fp)
	sw	$t1	,	268435856($t0)
	lw	$t0	,	0($fp)
	li	$t1	,	0
	add	$t0	,	$t0	,	$t1
	sw	$t0	,	-24($fp)
	li	$t0	,	-1
	li	$t1	,	0
	add	$t0	,	$t0	,	$t1
	sw	$t0	,	-28($fp)
	lw	$t1	,	-24($fp)
	addi	$t1	,	$t1	,	2037
	sll	$t0	,	$t1	,	2
	lw	$t1	,	-28($fp)
	sw	$t1	,	268435856($t0)
	lw	$t0	,	0($fp)
	li	$t1	,	0
	add	$t0	,	$t0	,	$t1
	sw	$t0	,	-32($fp)
	lw	$t0	,	-32($fp)
	li	$t1	,	1
	add	$t0	,	$t0	,	$t1
	sw	$t0	,	-32($fp)
	lw	$t0	,	-32($fp)
	li	$t1	,	0
	add	$t0	,	$t0	,	$t1
	sw	$t0	,	0($fp)
	j	$label41
	nop
$label42:
	li	$t0	,	0
	li	$t1	,	0
	add	$t0	,	$t0	,	$t1
	sw	$t0	,	0($fp)
	li	$v0	,	4
	la	$a0	,	$Message10
	syscall
	li	$v0	,	11
	li	$a0	,	95
	syscall
	li	$t0	,	65
	li	$t1	,	0
	add	$t0	,	$t0	,	$t1
	sw	$t0	,	268443996($zero)
	li	$v0	,	4
	la	$a0	,	$Message11
	syscall
	lw	$t0	,	268443996($zero)
	li	$t1	,	0
	add	$t0	,	$t0	,	$t1
	sw	$t0	,	-36($fp)
	li	$v0	,	11
	lw	$a0	,	-36($fp)
	syscall
	li	$v0	,	4
	la	$a0	,	$Message12
	syscall
	li	$v0	,	11
	li	$a0	,	43
	syscall
	li	$v0	,	4
	la	$a0	,	$Message13
	syscall
	li	$t0	,	1
	addi	$t0	,	$t0	,	35
	sll	$t0	,	$t0	,	2
	lw	$t0	,	268435856($t0)
	sw	$t0	,	-40($fp)
	li	$v0	,	11
	lw	$a0	,	-40($fp)
	syscall
	li	$v0	,	4
	la	$a0	,	$Message14
	syscall
	li	$t0	,	5
	addi	$t0	,	$t0	,	35
	sll	$t0	,	$t0	,	2
	lw	$t0	,	268435856($t0)
	sw	$t0	,	-44($fp)
	lw	$t0	,	-44($fp)
	sw	$t0	,	0($sp)
	addi	$sp	,	$sp	,	-4
	jal	returnchar
	nop
	add	$t0	,	$v0	,	$zero
	li	$t1	,	0
	add	$t0	,	$t0	,	$t1
	sw	$t0	,	-48($fp)
	li	$v0	,	11
	lw	$a0	,	-48($fp)
	syscall
	li	$v0	,	4
	la	$a0	,	$Message15
	syscall
	jal	returna
	nop
	add	$t0	,	$v0	,	$zero
	li	$t1	,	0
	add	$t0	,	$t0	,	$t1
	sw	$t0	,	-52($fp)
	li	$v0	,	11
	lw	$a0	,	-52($fp)
	syscall
	li	$v0	,	4
	la	$a0	,	$Message16
	syscall
	li	$v0	,	1
	li	$a0	,	34545
	syscall
	li	$v0	,	4
	la	$a0	,	$Message17
	syscall
	li	$v0	,	1
	li	$a0	,	-400
	syscall
	li	$v0	,	4
	la	$a0	,	$Message18
	syscall
	li	$v0	,	1
	li	$a0	,	-1563
	syscall
	li	$v0	,	4
	la	$a0	,	$Message19
	syscall
	li	$v0	,	1
	li	$a0	,	1000
	syscall
	li	$v0	,	4
	la	$a0	,	$Message20
	syscall
	li	$v0	,	1
	li	$a0	,	0
	syscall
	li	$v0	,	4
	la	$a0	,	$Message21
	syscall
	li	$v0	,	1
	li	$a0	,	-888
	syscall
	li	$v0	,	4
	la	$a0	,	$Message22
	syscall
	li	$v0	,	1
	li	$a0	,	456
	syscall
	li	$v0	,	4
	la	$a0	,	$Message23
	syscall
	li	$t0	,	20
	addi	$t0	,	$t0	,	4038
	sll	$t0	,	$t0	,	2
	lw	$t0	,	268435856($t0)
	sw	$t0	,	-56($fp)
	li	$v0	,	1
	lw	$a0	,	-56($fp)
	syscall
	li	$v0	,	4
	la	$a0	,	$Message24
	syscall
	li	$t0	,	1
	addi	$t0	,	$t0	,	4038
	sll	$t0	,	$t0	,	2
	lw	$t0	,	268435856($t0)
	sw	$t0	,	-60($fp)
	li	$v0	,	1
	lw	$a0	,	-60($fp)
	syscall
	li	$v0	,	4
	la	$a0	,	$Message25
	syscall
	li	$t0	,	0
	sw	$t0	,	0($sp)
	addi	$sp	,	$sp	,	-4
	jal	fib
	nop
	add	$t0	,	$v0	,	$zero
	li	$t1	,	0
	add	$t0	,	$t0	,	$t1
	sw	$t0	,	-64($fp)
	li	$v0	,	1
	lw	$a0	,	-64($fp)
	syscall
	li	$v0	,	4
	la	$a0	,	$Message26
	syscall
	li	$t0	,	1
	sw	$t0	,	0($sp)
	addi	$sp	,	$sp	,	-4
	jal	fib
	nop
	add	$t0	,	$v0	,	$zero
	li	$t1	,	0
	add	$t0	,	$t0	,	$t1
	sw	$t0	,	-68($fp)
	li	$v0	,	1
	lw	$a0	,	-68($fp)
	syscall
	li	$v0	,	4
	la	$a0	,	$Message27
	syscall
	li	$t0	,	5
	sw	$t0	,	0($sp)
	addi	$sp	,	$sp	,	-4
	jal	fib
	nop
	add	$t0	,	$v0	,	$zero
	li	$t1	,	0
	add	$t0	,	$t0	,	$t1
	sw	$t0	,	-72($fp)
	li	$v0	,	1
	lw	$a0	,	-72($fp)
	syscall
	li	$v0	,	4
	la	$a0	,	$Message28
	syscall
	li	$v0	,	1
	li	$a0	,	100
	syscall
	li	$v0	,	4
	la	$a0	,	$Message29
	syscall
	li	$t0	,	20
	addi	$t0	,	$t0	,	4038
	sll	$t0	,	$t0	,	2
	lw	$t0	,	268435856($t0)
	sw	$t0	,	-76($fp)
	li	$v0	,	1
	lw	$a0	,	-76($fp)
	syscall
	li	$v0	,	4
	la	$a0	,	$Message30
	syscall
	li	$t0	,	5
	sw	$t0	,	0($sp)
	addi	$sp	,	$sp	,	-4
	jal	fib
	nop
	add	$t0	,	$v0	,	$zero
	li	$t1	,	0
	add	$t0	,	$t0	,	$t1
	sw	$t0	,	-80($fp)
	li	$v0	,	1
	lw	$a0	,	-80($fp)
	syscall
	li	$v0	,	4
	la	$a0	,	$Message31
	syscall
	lw	$t0	,	268443996($zero)
	li	$t1	,	0
	add	$t0	,	$t0	,	$t1
	sw	$t0	,	-84($fp)
	li	$t0	,	95
	lw	$t1	,	-84($fp)
	mul	$t0	,	$t0	,	$t1
	sw	$t0	,	-84($fp)
	li	$v0	,	1
	lw	$a0	,	-84($fp)
	syscall
	li	$v0	,	4
	la	$a0	,	$Message32
	syscall
	li	$t0	,	1
	addi	$t0	,	$t0	,	35
	sll	$t0	,	$t0	,	2
	lw	$t0	,	268435856($t0)
	sw	$t0	,	-88($fp)
	li	$t0	,	43
	lw	$t1	,	-88($fp)
	div	$t0	,	$t1
	mflo	$t0
	sw	$t0	,	-88($fp)
	li	$v0	,	1
	lw	$a0	,	-88($fp)
	syscall
	li	$v0	,	4
	la	$a0	,	$Message33
	syscall
	li	$t0	,	1
	addi	$t0	,	$t0	,	35
	sll	$t0	,	$t0	,	2
	lw	$t0	,	268435856($t0)
	sw	$t0	,	-92($fp)
	lw	$t0	,	-92($fp)
	li	$t1	,	-400
	div	$t0	,	$t1
	mflo	$t0
	sw	$t0	,	-92($fp)
	li	$v0	,	1
	lw	$a0	,	-92($fp)
	syscall
	li	$v0	,	4
	la	$a0	,	$Message34
	syscall
	li	$t0	,	47
	sw	$t0	,	0($sp)
	addi	$sp	,	$sp	,	-4
	jal	returnchar
	nop
	add	$t0	,	$v0	,	$zero
	li	$t1	,	0
	add	$t0	,	$t0	,	$t1
	sw	$t0	,	-96($fp)
	li	$t0	,	1
	sw	$t0	,	0($sp)
	addi	$sp	,	$sp	,	-4
	jal	fib
	nop
	lw	$t0	,	-96($fp)
	add	$t1	,	$v0	,	$zero
	mul	$t0	,	$t0	,	$t1
	sw	$t0	,	-96($fp)
	li	$v0	,	1
	lw	$a0	,	-96($fp)
	syscall
	li	$v0	,	4
	la	$a0	,	$Message35
	syscall
	li	$v0	,	1
	li	$a0	,	355200
	syscall
	li	$v0	,	4
	la	$a0	,	$Message36
	syscall
	li	$t0	,	5
	sw	$t0	,	0($sp)
	addi	$sp	,	$sp	,	-4
	jal	fib
	nop
	add	$t0	,	$v0	,	$zero
	li	$t1	,	0
	add	$t0	,	$t0	,	$t1
	sw	$t0	,	-100($fp)
	li	$t0	,	1000
	lw	$t1	,	-100($fp)
	div	$t0	,	$t1
	mflo	$t0
	sw	$t0	,	-100($fp)
	li	$v0	,	1
	lw	$a0	,	-100($fp)
	syscall
	li	$v0	,	4
	la	$a0	,	$Message37
	syscall
	lw	$t0	,	268443996($zero)
	li	$t1	,	0
	add	$t0	,	$t0	,	$t1
	sw	$t0	,	-104($fp)
	li	$t0	,	95
	lw	$t1	,	-104($fp)
	div	$t0	,	$t1
	mflo	$t0
	sw	$t0	,	-104($fp)
	li	$t0	,	1
	sw	$t0	,	0($sp)
	addi	$sp	,	$sp	,	-4
	jal	fib
	nop
	lw	$t0	,	-104($fp)
	add	$t1	,	$v0	,	$zero
	mul	$t0	,	$t0	,	$t1
	sw	$t0	,	-104($fp)
	li	$v0	,	1
	lw	$a0	,	-104($fp)
	syscall
	li	$v0	,	4
	la	$a0	,	$Message38
	syscall
	li	$t0	,	0
	sw	$t0	,	0($sp)
	addi	$sp	,	$sp	,	-4
	jal	fib
	nop
	add	$t0	,	$v0	,	$zero
	li	$t1	,	0
	add	$t0	,	$t0	,	$t1
	sw	$t0	,	-108($fp)
	li	$t0	,	355200
	lw	$t1	,	-108($fp)
	mul	$t0	,	$t0	,	$t1
	sw	$t0	,	-108($fp)
	li	$v0	,	1
	lw	$a0	,	-108($fp)
	syscall
	li	$v0	,	4
	la	$a0	,	$Message39
	syscall
	lw	$t0	,	268443996($zero)
	li	$t1	,	0
	add	$t0	,	$t0	,	$t1
	sw	$t0	,	-112($fp)
	li	$t0	,	355200
	lw	$t1	,	-112($fp)
	div	$t0	,	$t1
	mflo	$t0
	sw	$t0	,	-112($fp)
	li	$v0	,	1
	lw	$a0	,	-112($fp)
	syscall
	li	$v0	,	4
	la	$a0	,	$Message40
	syscall
	li	$t0	,	5
	addi	$t0	,	$t0	,	35
	sll	$t0	,	$t0	,	2
	lw	$t0	,	268435856($t0)
	sw	$t0	,	-116($fp)
	lw	$t0	,	-116($fp)
	sw	$t0	,	0($sp)
	addi	$sp	,	$sp	,	-4
	jal	returnchar
	nop
	add	$t0	,	$v0	,	$zero
	li	$t1	,	0
	add	$t0	,	$t0	,	$t1
	sw	$t0	,	-120($fp)
	li	$t0	,	5
	addi	$t0	,	$t0	,	35
	sll	$t0	,	$t0	,	2
	lw	$t0	,	268435856($t0)
	sw	$t0	,	-124($fp)
	lw	$t0	,	-124($fp)
	sw	$t0	,	0($sp)
	addi	$sp	,	$sp	,	-4
	jal	returnchar
	nop
	lw	$t0	,	-120($fp)
	add	$t1	,	$v0	,	$zero
	mul	$t0	,	$t0	,	$t1
	sw	$t0	,	-120($fp)
	li	$t0	,	5
	addi	$t0	,	$t0	,	35
	sll	$t0	,	$t0	,	2
	lw	$t0	,	268435856($t0)
	sw	$t0	,	-128($fp)
	lw	$t0	,	-128($fp)
	sw	$t0	,	0($sp)
	addi	$sp	,	$sp	,	-4
	jal	returnchar
	nop
	lw	$t0	,	-120($fp)
	add	$t1	,	$v0	,	$zero
	mul	$t0	,	$t0	,	$t1
	sw	$t0	,	-120($fp)
	li	$v0	,	1
	lw	$a0	,	-120($fp)
	syscall
	li	$v0	,	4
	la	$a0	,	$Message41
	syscall
	lw	$t0	,	268443996($zero)
	li	$t1	,	0
	add	$t0	,	$t0	,	$t1
	sw	$t0	,	-132($fp)
	li	$t0	,	355200
	lw	$t1	,	-132($fp)
	div	$t0	,	$t1
	mflo	$t0
	sw	$t0	,	-132($fp)
	lw	$t0	,	-132($fp)
	li	$t1	,	355200
	div	$t0	,	$t1
	mflo	$t0
	sw	$t0	,	-132($fp)
	li	$t0	,	20
	addi	$t0	,	$t0	,	4038
	sll	$t0	,	$t0	,	2
	lw	$t0	,	268435856($t0)
	sw	$t0	,	-136($fp)
	lw	$t0	,	-132($fp)
	lw	$t1	,	-136($fp)
	mul	$t0	,	$t0	,	$t1
	sw	$t0	,	-132($fp)
	li	$v0	,	1
	lw	$a0	,	-132($fp)
	syscall
	li	$v0	,	4
	la	$a0	,	$Message42
	syscall
	li	$t0	,	5
	addi	$t0	,	$t0	,	35
	sll	$t0	,	$t0	,	2
	lw	$t0	,	268435856($t0)
	sw	$t0	,	-140($fp)
	lw	$t0	,	-140($fp)
	sw	$t0	,	0($sp)
	addi	$sp	,	$sp	,	-4
	jal	returnchar
	nop
	add	$t0	,	$v0	,	$zero
	li	$t1	,	0
	add	$t0	,	$t0	,	$t1
	sw	$t0	,	-144($fp)
	li	$t0	,	5
	addi	$t0	,	$t0	,	35
	sll	$t0	,	$t0	,	2
	lw	$t0	,	268435856($t0)
	sw	$t0	,	-148($fp)
	lw	$t0	,	-148($fp)
	sw	$t0	,	0($sp)
	addi	$sp	,	$sp	,	-4
	jal	returnchar
	nop
	lw	$t0	,	-144($fp)
	add	$t1	,	$v0	,	$zero
	mul	$t0	,	$t0	,	$t1
	sw	$t0	,	-144($fp)
	li	$t0	,	5
	addi	$t0	,	$t0	,	35
	sll	$t0	,	$t0	,	2
	lw	$t0	,	268435856($t0)
	sw	$t0	,	-152($fp)
	lw	$t0	,	-152($fp)
	sw	$t0	,	0($sp)
	addi	$sp	,	$sp	,	-4
	jal	returnchar
	nop
	lw	$t0	,	-144($fp)
	add	$t1	,	$v0	,	$zero
	mul	$t0	,	$t0	,	$t1
	sw	$t0	,	-144($fp)
	li	$t0	,	95
	lw	$t1	,	-144($fp)
	mul	$t0	,	$t0	,	$t1
	sw	$t0	,	-144($fp)
	li	$v0	,	1
	lw	$a0	,	-144($fp)
	syscall
	li	$v0	,	4
	la	$a0	,	$Message43
	syscall
	li	$t0	,	6
	sw	$t0	,	0($sp)
	addi	$sp	,	$sp	,	-4
	jal	fib
	nop
	add	$t0	,	$v0	,	$zero
	li	$t1	,	0
	add	$t0	,	$t0	,	$t1
	sw	$t0	,	-156($fp)
	lw	$t0	,	-156($fp)
	sw	$t0	,	0($sp)
	addi	$sp	,	$sp	,	-4
	jal	fib
	nop
	add	$t0	,	$v0	,	$zero
	li	$t1	,	0
	add	$t0	,	$t0	,	$t1
	sw	$t0	,	-160($fp)
	li	$t0	,	5
	sw	$t0	,	0($sp)
	addi	$sp	,	$sp	,	-4
	jal	fib
	nop
	add	$t0	,	$v0	,	$zero
	li	$t1	,	0
	add	$t0	,	$t0	,	$t1
	sw	$t0	,	-164($fp)
	lw	$t0	,	-160($fp)
	lw	$t1	,	-164($fp)
	sub	$t0	,	$t0	,	$t1
	sw	$t0	,	-160($fp)
	lw	$t0	,	-160($fp)
	sw	$t0	,	0($sp)
	addi	$sp	,	$sp	,	-4
	jal	fib
	nop
	add	$t0	,	$v0	,	$zero
	li	$t1	,	0
	add	$t0	,	$t0	,	$t1
	sw	$t0	,	-168($fp)
	li	$v0	,	1
	lw	$a0	,	-168($fp)
	syscall
	li	$v0	,	4
	la	$a0	,	$Message44
	syscall
	li	$t0	,	0
	sw	$t0	,	0($sp)
	addi	$sp	,	$sp	,	-4
	jal	fib
	nop
	add	$t0	,	$v0	,	$zero
	li	$t1	,	0
	add	$t0	,	$t0	,	$t1
	sw	$t0	,	-172($fp)
	lw	$t0	,	-172($fp)
	sw	$t0	,	0($sp)
	addi	$sp	,	$sp	,	-4
	jal	fib
	nop
	add	$t0	,	$v0	,	$zero
	li	$t1	,	0
	add	$t0	,	$t0	,	$t1
	sw	$t0	,	-176($fp)
	lw	$t0	,	-176($fp)
	sw	$t0	,	0($sp)
	addi	$sp	,	$sp	,	-4
	jal	fib
	nop
	add	$t0	,	$v0	,	$zero
	li	$t1	,	0
	add	$t0	,	$t0	,	$t1
	sw	$t0	,	-180($fp)
	lw	$t0	,	-180($fp)
	addi	$t0	,	$t0	,	4038
	sll	$t0	,	$t0	,	2
	lw	$t0	,	268435856($t0)
	sw	$t0	,	-184($fp)
	li	$t0	,	0
	addi	$t0	,	$t0	,	4038
	sll	$t0	,	$t0	,	2
	lw	$t0	,	268435856($t0)
	sw	$t0	,	-188($fp)
	li	$t0	,	0
	addi	$t0	,	$t0	,	4038
	sll	$t0	,	$t0	,	2
	lw	$t0	,	268435856($t0)
	sw	$t0	,	-192($fp)
	lw	$t0	,	-188($fp)
	lw	$t1	,	-192($fp)
	div	$t0	,	$t1
	mflo	$t0
	sw	$t0	,	-188($fp)
	lw	$t0	,	-188($fp)
	sw	$t0	,	0($sp)
	addi	$sp	,	$sp	,	-4
	jal	fib
	nop
	add	$t0	,	$v0	,	$zero
	li	$t1	,	0
	add	$t0	,	$t0	,	$t1
	sw	$t0	,	-196($fp)
	lw	$t0	,	-196($fp)
	sw	$t0	,	0($sp)
	addi	$sp	,	$sp	,	-4
	jal	fib
	nop
	add	$t0	,	$v0	,	$zero
	li	$t1	,	0
	add	$t0	,	$t0	,	$t1
	sw	$t0	,	-200($fp)
	lw	$t0	,	-200($fp)
	addi	$t0	,	$t0	,	4038
	sll	$t0	,	$t0	,	2
	lw	$t0	,	268435856($t0)
	sw	$t0	,	-204($fp)
	lw	$t0	,	-184($fp)
	lw	$t1	,	-204($fp)
	sub	$t0	,	$t0	,	$t1
	sw	$t0	,	-184($fp)
	lw	$t0	,	-184($fp)
	sw	$t0	,	0($sp)
	addi	$sp	,	$sp	,	-4
	jal	fib
	nop
	add	$t0	,	$v0	,	$zero
	li	$t1	,	0
	add	$t0	,	$t0	,	$t1
	sw	$t0	,	-208($fp)
	lw	$t0	,	-208($fp)
	addi	$t0	,	$t0	,	4038
	sll	$t0	,	$t0	,	2
	lw	$t0	,	268435856($t0)
	sw	$t0	,	-212($fp)
	li	$v0	,	1
	lw	$a0	,	-212($fp)
	syscall
	li	$v0	,	4
	la	$a0	,	$Message45
	syscall
	li	$v0	,	1
	li	$a0	,	-888
	syscall
	li	$v0	,	4
	la	$a0	,	$Message46
	syscall
	jal	returna
	nop
	add	$t0	,	$v0	,	$zero
	li	$t1	,	0
	add	$t0	,	$t0	,	$t1
	sw	$t0	,	-216($fp)
	li	$t0	,	0
	lw	$t1	,	-216($fp)
	sub	$t0	,	$t0	,	$t1
	sw	$t0	,	-216($fp)
	li	$v0	,	1
	lw	$a0	,	-216($fp)
	syscall
	li	$v0	,	4
	la	$a0	,	$Message47
	syscall
	li	$t0	,	0
	sw	$t0	,	0($sp)
	addi	$sp	,	$sp	,	-4
	jal	fib
	nop
	add	$t0	,	$v0	,	$zero
	li	$t1	,	0
	add	$t0	,	$t0	,	$t1
	sw	$t0	,	-220($fp)
	lw	$t0	,	-220($fp)
	sw	$t0	,	0($sp)
	addi	$sp	,	$sp	,	-4
	jal	fib
	nop
	add	$t0	,	$v0	,	$zero
	li	$t1	,	0
	add	$t0	,	$t0	,	$t1
	sw	$t0	,	-224($fp)
	lw	$t0	,	-224($fp)
	sw	$t0	,	0($sp)
	addi	$sp	,	$sp	,	-4
	jal	fib
	nop
	add	$t0	,	$v0	,	$zero
	li	$t1	,	0
	add	$t0	,	$t0	,	$t1
	sw	$t0	,	-228($fp)
	lw	$t0	,	-228($fp)
	addi	$t0	,	$t0	,	4038
	sll	$t0	,	$t0	,	2
	lw	$t0	,	268435856($t0)
	sw	$t0	,	-232($fp)
	li	$t0	,	0
	addi	$t0	,	$t0	,	4038
	sll	$t0	,	$t0	,	2
	lw	$t0	,	268435856($t0)
	sw	$t0	,	-236($fp)
	li	$t0	,	0
	addi	$t0	,	$t0	,	4038
	sll	$t0	,	$t0	,	2
	lw	$t0	,	268435856($t0)
	sw	$t0	,	-240($fp)
	lw	$t0	,	-236($fp)
	lw	$t1	,	-240($fp)
	div	$t0	,	$t1
	mflo	$t0
	sw	$t0	,	-236($fp)
	lw	$t0	,	-236($fp)
	sw	$t0	,	0($sp)
	addi	$sp	,	$sp	,	-4
	jal	fib
	nop
	add	$t0	,	$v0	,	$zero
	li	$t1	,	0
	add	$t0	,	$t0	,	$t1
	sw	$t0	,	-244($fp)
	lw	$t0	,	-244($fp)
	sw	$t0	,	0($sp)
	addi	$sp	,	$sp	,	-4
	jal	fib
	nop
	add	$t0	,	$v0	,	$zero
	li	$t1	,	0
	add	$t0	,	$t0	,	$t1
	sw	$t0	,	-248($fp)
	lw	$t0	,	-248($fp)
	addi	$t0	,	$t0	,	4038
	sll	$t0	,	$t0	,	2
	lw	$t0	,	268435856($t0)
	sw	$t0	,	-252($fp)
	lw	$t0	,	-232($fp)
	lw	$t1	,	-252($fp)
	sub	$t0	,	$t0	,	$t1
	sw	$t0	,	-232($fp)
	lw	$t0	,	-232($fp)
	sw	$t0	,	0($sp)
	addi	$sp	,	$sp	,	-4
	jal	fib
	nop
	add	$t0	,	$v0	,	$zero
	li	$t1	,	0
	add	$t0	,	$t0	,	$t1
	sw	$t0	,	-256($fp)
	lw	$t0	,	-256($fp)
	addi	$t0	,	$t0	,	4038
	sll	$t0	,	$t0	,	2
	lw	$t0	,	268435856($t0)
	sw	$t0	,	-260($fp)
	li	$t0	,	0
	lw	$t1	,	-260($fp)
	sub	$t0	,	$t0	,	$t1
	sw	$t0	,	-260($fp)
	lw	$t0	,	268443996($zero)
	li	$t1	,	0
	add	$t0	,	$t0	,	$t1
	sw	$t0	,	-264($fp)
	li	$t0	,	355200
	lw	$t1	,	-264($fp)
	div	$t0	,	$t1
	mflo	$t0
	sw	$t0	,	-264($fp)
	lw	$t0	,	-264($fp)
	li	$t1	,	355200
	div	$t0	,	$t1
	mflo	$t0
	sw	$t0	,	-264($fp)
	li	$t0	,	20
	addi	$t0	,	$t0	,	4038
	sll	$t0	,	$t0	,	2
	lw	$t0	,	268435856($t0)
	sw	$t0	,	-268($fp)
	lw	$t0	,	-264($fp)
	lw	$t1	,	-268($fp)
	mul	$t0	,	$t0	,	$t1
	sw	$t0	,	-264($fp)
	lw	$t0	,	-260($fp)
	lw	$t1	,	-264($fp)
	add	$t0	,	$t0	,	$t1
	sw	$t0	,	-260($fp)
	li	$v0	,	1
	lw	$a0	,	-260($fp)
	syscall
	li	$v0	,	4
	la	$a0	,	$Message48
	syscall
	li	$t0	,	0
	sw	$t0	,	0($sp)
	addi	$sp	,	$sp	,	-4
	jal	fib
	nop
	add	$t0	,	$v0	,	$zero
	li	$t1	,	0
	add	$t0	,	$t0	,	$t1
	sw	$t0	,	-272($fp)
	lw	$t0	,	-272($fp)
	sw	$t0	,	0($sp)
	addi	$sp	,	$sp	,	-4
	jal	fib
	nop
	add	$t0	,	$v0	,	$zero
	li	$t1	,	0
	add	$t0	,	$t0	,	$t1
	sw	$t0	,	-276($fp)
	lw	$t0	,	-276($fp)
	sw	$t0	,	0($sp)
	addi	$sp	,	$sp	,	-4
	jal	fib
	nop
	add	$t0	,	$v0	,	$zero
	li	$t1	,	0
	add	$t0	,	$t0	,	$t1
	sw	$t0	,	-280($fp)
	lw	$t0	,	-280($fp)
	addi	$t0	,	$t0	,	4038
	sll	$t0	,	$t0	,	2
	lw	$t0	,	268435856($t0)
	sw	$t0	,	-284($fp)
	li	$t0	,	0
	addi	$t0	,	$t0	,	4038
	sll	$t0	,	$t0	,	2
	lw	$t0	,	268435856($t0)
	sw	$t0	,	-288($fp)
	li	$t0	,	0
	addi	$t0	,	$t0	,	4038
	sll	$t0	,	$t0	,	2
	lw	$t0	,	268435856($t0)
	sw	$t0	,	-292($fp)
	lw	$t0	,	-288($fp)
	lw	$t1	,	-292($fp)
	div	$t0	,	$t1
	mflo	$t0
	sw	$t0	,	-288($fp)
	lw	$t0	,	-288($fp)
	sw	$t0	,	0($sp)
	addi	$sp	,	$sp	,	-4
	jal	fib
	nop
	add	$t0	,	$v0	,	$zero
	li	$t1	,	0
	add	$t0	,	$t0	,	$t1
	sw	$t0	,	-296($fp)
	lw	$t0	,	-296($fp)
	sw	$t0	,	0($sp)
	addi	$sp	,	$sp	,	-4
	jal	fib
	nop
	add	$t0	,	$v0	,	$zero
	li	$t1	,	0
	add	$t0	,	$t0	,	$t1
	sw	$t0	,	-300($fp)
	lw	$t0	,	-300($fp)
	addi	$t0	,	$t0	,	4038
	sll	$t0	,	$t0	,	2
	lw	$t0	,	268435856($t0)
	sw	$t0	,	-304($fp)
	lw	$t0	,	-284($fp)
	lw	$t1	,	-304($fp)
	sub	$t0	,	$t0	,	$t1
	sw	$t0	,	-284($fp)
	lw	$t0	,	-284($fp)
	sw	$t0	,	0($sp)
	addi	$sp	,	$sp	,	-4
	jal	fib
	nop
	add	$t0	,	$v0	,	$zero
	li	$t1	,	0
	add	$t0	,	$t0	,	$t1
	sw	$t0	,	-308($fp)
	lw	$t0	,	-308($fp)
	addi	$t0	,	$t0	,	4038
	sll	$t0	,	$t0	,	2
	lw	$t0	,	268435856($t0)
	sw	$t0	,	-312($fp)
	li	$t0	,	5
	addi	$t0	,	$t0	,	35
	sll	$t0	,	$t0	,	2
	lw	$t0	,	268435856($t0)
	sw	$t0	,	-316($fp)
	lw	$t0	,	-316($fp)
	sw	$t0	,	0($sp)
	addi	$sp	,	$sp	,	-4
	jal	returnchar
	nop
	add	$t0	,	$v0	,	$zero
	li	$t1	,	0
	add	$t0	,	$t0	,	$t1
	sw	$t0	,	-320($fp)
	li	$t0	,	5
	addi	$t0	,	$t0	,	35
	sll	$t0	,	$t0	,	2
	lw	$t0	,	268435856($t0)
	sw	$t0	,	-324($fp)
	lw	$t0	,	-324($fp)
	sw	$t0	,	0($sp)
	addi	$sp	,	$sp	,	-4
	jal	returnchar
	nop
	lw	$t0	,	-320($fp)
	add	$t1	,	$v0	,	$zero
	mul	$t0	,	$t0	,	$t1
	sw	$t0	,	-320($fp)
	li	$t0	,	5
	addi	$t0	,	$t0	,	35
	sll	$t0	,	$t0	,	2
	lw	$t0	,	268435856($t0)
	sw	$t0	,	-328($fp)
	lw	$t0	,	-328($fp)
	sw	$t0	,	0($sp)
	addi	$sp	,	$sp	,	-4
	jal	returnchar
	nop
	lw	$t0	,	-320($fp)
	add	$t1	,	$v0	,	$zero
	mul	$t0	,	$t0	,	$t1
	sw	$t0	,	-320($fp)
	li	$t0	,	95
	lw	$t1	,	-320($fp)
	mul	$t0	,	$t0	,	$t1
	sw	$t0	,	-320($fp)
	lw	$t0	,	-312($fp)
	lw	$t1	,	-320($fp)
	sub	$t0	,	$t0	,	$t1
	sw	$t0	,	-312($fp)
	li	$v0	,	1
	lw	$a0	,	-312($fp)
	syscall
	li	$v0	,	4
	la	$a0	,	$Message49
	syscall
	li	$t0	,	0
	sw	$t0	,	0($sp)
	addi	$sp	,	$sp	,	-4
	jal	fib
	nop
	add	$t0	,	$v0	,	$zero
	li	$t1	,	0
	add	$t0	,	$t0	,	$t1
	sw	$t0	,	-332($fp)
	lw	$t0	,	-332($fp)
	sw	$t0	,	0($sp)
	addi	$sp	,	$sp	,	-4
	jal	fib
	nop
	add	$t0	,	$v0	,	$zero
	li	$t1	,	0
	add	$t0	,	$t0	,	$t1
	sw	$t0	,	-336($fp)
	lw	$t0	,	-336($fp)
	sw	$t0	,	0($sp)
	addi	$sp	,	$sp	,	-4
	jal	fib
	nop
	add	$t0	,	$v0	,	$zero
	li	$t1	,	0
	add	$t0	,	$t0	,	$t1
	sw	$t0	,	-340($fp)
	lw	$t0	,	-340($fp)
	addi	$t0	,	$t0	,	4038
	sll	$t0	,	$t0	,	2
	lw	$t0	,	268435856($t0)
	sw	$t0	,	-344($fp)
	li	$t0	,	0
	addi	$t0	,	$t0	,	4038
	sll	$t0	,	$t0	,	2
	lw	$t0	,	268435856($t0)
	sw	$t0	,	-348($fp)
	li	$t0	,	0
	addi	$t0	,	$t0	,	4038
	sll	$t0	,	$t0	,	2
	lw	$t0	,	268435856($t0)
	sw	$t0	,	-352($fp)
	lw	$t0	,	-348($fp)
	lw	$t1	,	-352($fp)
	div	$t0	,	$t1
	mflo	$t0
	sw	$t0	,	-348($fp)
	lw	$t0	,	-348($fp)
	sw	$t0	,	0($sp)
	addi	$sp	,	$sp	,	-4
	jal	fib
	nop
	add	$t0	,	$v0	,	$zero
	li	$t1	,	0
	add	$t0	,	$t0	,	$t1
	sw	$t0	,	-356($fp)
	lw	$t0	,	-356($fp)
	sw	$t0	,	0($sp)
	addi	$sp	,	$sp	,	-4
	jal	fib
	nop
	add	$t0	,	$v0	,	$zero
	li	$t1	,	0
	add	$t0	,	$t0	,	$t1
	sw	$t0	,	-360($fp)
	lw	$t0	,	-360($fp)
	addi	$t0	,	$t0	,	4038
	sll	$t0	,	$t0	,	2
	lw	$t0	,	268435856($t0)
	sw	$t0	,	-364($fp)
	lw	$t0	,	-344($fp)
	lw	$t1	,	-364($fp)
	sub	$t0	,	$t0	,	$t1
	sw	$t0	,	-344($fp)
	lw	$t0	,	-344($fp)
	sw	$t0	,	0($sp)
	addi	$sp	,	$sp	,	-4
	jal	fib
	nop
	add	$t0	,	$v0	,	$zero
	li	$t1	,	0
	add	$t0	,	$t0	,	$t1
	sw	$t0	,	-368($fp)
	lw	$t0	,	-368($fp)
	addi	$t0	,	$t0	,	4038
	sll	$t0	,	$t0	,	2
	lw	$t0	,	268435856($t0)
	sw	$t0	,	-372($fp)
	li	$t0	,	5
	addi	$t0	,	$t0	,	35
	sll	$t0	,	$t0	,	2
	lw	$t0	,	268435856($t0)
	sw	$t0	,	-376($fp)
	lw	$t0	,	-376($fp)
	sw	$t0	,	0($sp)
	addi	$sp	,	$sp	,	-4
	jal	returnchar
	nop
	add	$t0	,	$v0	,	$zero
	li	$t1	,	0
	add	$t0	,	$t0	,	$t1
	sw	$t0	,	-380($fp)
	li	$t0	,	5
	addi	$t0	,	$t0	,	35
	sll	$t0	,	$t0	,	2
	lw	$t0	,	268435856($t0)
	sw	$t0	,	-384($fp)
	lw	$t0	,	-384($fp)
	sw	$t0	,	0($sp)
	addi	$sp	,	$sp	,	-4
	jal	returnchar
	nop
	lw	$t0	,	-380($fp)
	add	$t1	,	$v0	,	$zero
	mul	$t0	,	$t0	,	$t1
	sw	$t0	,	-380($fp)
	li	$t0	,	5
	addi	$t0	,	$t0	,	35
	sll	$t0	,	$t0	,	2
	lw	$t0	,	268435856($t0)
	sw	$t0	,	-388($fp)
	lw	$t0	,	-388($fp)
	sw	$t0	,	0($sp)
	addi	$sp	,	$sp	,	-4
	jal	returnchar
	nop
	lw	$t0	,	-380($fp)
	add	$t1	,	$v0	,	$zero
	mul	$t0	,	$t0	,	$t1
	sw	$t0	,	-380($fp)
	li	$t0	,	95
	lw	$t1	,	-380($fp)
	mul	$t0	,	$t0	,	$t1
	sw	$t0	,	-380($fp)
	lw	$t0	,	-372($fp)
	lw	$t1	,	-380($fp)
	sub	$t0	,	$t0	,	$t1
	sw	$t0	,	-372($fp)
	li	$t0	,	6
	sw	$t0	,	0($sp)
	addi	$sp	,	$sp	,	-4
	jal	fib
	nop
	add	$t0	,	$v0	,	$zero
	li	$t1	,	0
	add	$t0	,	$t0	,	$t1
	sw	$t0	,	-392($fp)
	lw	$t0	,	-392($fp)
	sw	$t0	,	0($sp)
	addi	$sp	,	$sp	,	-4
	jal	fib
	nop
	add	$t0	,	$v0	,	$zero
	li	$t1	,	0
	add	$t0	,	$t0	,	$t1
	sw	$t0	,	-396($fp)
	li	$t0	,	5
	sw	$t0	,	0($sp)
	addi	$sp	,	$sp	,	-4
	jal	fib
	nop
	add	$t0	,	$v0	,	$zero
	li	$t1	,	0
	add	$t0	,	$t0	,	$t1
	sw	$t0	,	-400($fp)
	lw	$t0	,	-396($fp)
	lw	$t1	,	-400($fp)
	sub	$t0	,	$t0	,	$t1
	sw	$t0	,	-396($fp)
	lw	$t0	,	-396($fp)
	sw	$t0	,	0($sp)
	addi	$sp	,	$sp	,	-4
	jal	fib
	nop
	add	$t0	,	$v0	,	$zero
	li	$t1	,	0
	add	$t0	,	$t0	,	$t1
	sw	$t0	,	-404($fp)
	li	$t0	,	0
	lw	$t1	,	-404($fp)
	sub	$t0	,	$t0	,	$t1
	sw	$t0	,	-404($fp)
	lw	$t0	,	-372($fp)
	lw	$t1	,	-404($fp)
	sub	$t0	,	$t0	,	$t1
	sw	$t0	,	-372($fp)
	li	$t0	,	0
	sw	$t0	,	0($sp)
	addi	$sp	,	$sp	,	-4
	jal	fib
	nop
	add	$t0	,	$v0	,	$zero
	li	$t1	,	0
	add	$t0	,	$t0	,	$t1
	sw	$t0	,	-408($fp)
	li	$t0	,	355200
	lw	$t1	,	-408($fp)
	mul	$t0	,	$t0	,	$t1
	sw	$t0	,	-408($fp)
	lw	$t0	,	-372($fp)
	lw	$t1	,	-408($fp)
	add	$t0	,	$t0	,	$t1
	sw	$t0	,	-372($fp)
	li	$v0	,	1
	lw	$a0	,	-372($fp)
	syscall
	li	$v0	,	4
	la	$a0	,	$Message50
	syscall
	li	$t0	,	5
	sw	$t0	,	0($sp)
	addi	$sp	,	$sp	,	-4
	jal	fib
	nop
	add	$t0	,	$v0	,	$zero
	li	$t1	,	0
	add	$t0	,	$t0	,	$t1
	sw	$t0	,	-412($fp)
	li	$t0	,	1000
	lw	$t1	,	-412($fp)
	div	$t0	,	$t1
	mflo	$t0
	sw	$t0	,	-412($fp)
	lw	$t0	,	-412($fp)
	li	$t1	,	200
	sub	$t0	,	$t0	,	$t1
	sw	$t0	,	-412($fp)
	li	$t0	,	0
	sw	$t0	,	0($sp)
	addi	$sp	,	$sp	,	-4
	jal	fib
	nop
	add	$t0	,	$v0	,	$zero
	li	$t1	,	0
	add	$t0	,	$t0	,	$t1
	sw	$t0	,	-416($fp)
	lw	$t0	,	-416($fp)
	sw	$t0	,	0($sp)
	addi	$sp	,	$sp	,	-4
	jal	fib
	nop
	add	$t0	,	$v0	,	$zero
	li	$t1	,	0
	add	$t0	,	$t0	,	$t1
	sw	$t0	,	-420($fp)
	lw	$t0	,	-420($fp)
	sw	$t0	,	0($sp)
	addi	$sp	,	$sp	,	-4
	jal	fib
	nop
	add	$t0	,	$v0	,	$zero
	li	$t1	,	0
	add	$t0	,	$t0	,	$t1
	sw	$t0	,	-424($fp)
	lw	$t0	,	-424($fp)
	addi	$t0	,	$t0	,	4038
	sll	$t0	,	$t0	,	2
	lw	$t0	,	268435856($t0)
	sw	$t0	,	-428($fp)
	li	$t0	,	0
	addi	$t0	,	$t0	,	4038
	sll	$t0	,	$t0	,	2
	lw	$t0	,	268435856($t0)
	sw	$t0	,	-432($fp)
	li	$t0	,	0
	addi	$t0	,	$t0	,	4038
	sll	$t0	,	$t0	,	2
	lw	$t0	,	268435856($t0)
	sw	$t0	,	-436($fp)
	lw	$t0	,	-432($fp)
	lw	$t1	,	-436($fp)
	div	$t0	,	$t1
	mflo	$t0
	sw	$t0	,	-432($fp)
	lw	$t0	,	-432($fp)
	sw	$t0	,	0($sp)
	addi	$sp	,	$sp	,	-4
	jal	fib
	nop
	add	$t0	,	$v0	,	$zero
	li	$t1	,	0
	add	$t0	,	$t0	,	$t1
	sw	$t0	,	-440($fp)
	lw	$t0	,	-440($fp)
	sw	$t0	,	0($sp)
	addi	$sp	,	$sp	,	-4
	jal	fib
	nop
	add	$t0	,	$v0	,	$zero
	li	$t1	,	0
	add	$t0	,	$t0	,	$t1
	sw	$t0	,	-444($fp)
	lw	$t0	,	-444($fp)
	addi	$t0	,	$t0	,	4038
	sll	$t0	,	$t0	,	2
	lw	$t0	,	268435856($t0)
	sw	$t0	,	-448($fp)
	lw	$t0	,	-428($fp)
	lw	$t1	,	-448($fp)
	sub	$t0	,	$t0	,	$t1
	sw	$t0	,	-428($fp)
	lw	$t0	,	-428($fp)
	sw	$t0	,	0($sp)
	addi	$sp	,	$sp	,	-4
	jal	fib
	nop
	add	$t0	,	$v0	,	$zero
	li	$t1	,	0
	add	$t0	,	$t0	,	$t1
	sw	$t0	,	-452($fp)
	lw	$t0	,	-452($fp)
	addi	$t0	,	$t0	,	4038
	sll	$t0	,	$t0	,	2
	lw	$t0	,	268435856($t0)
	sw	$t0	,	-456($fp)
	li	$t0	,	5
	addi	$t0	,	$t0	,	35
	sll	$t0	,	$t0	,	2
	lw	$t0	,	268435856($t0)
	sw	$t0	,	-460($fp)
	lw	$t0	,	-460($fp)
	sw	$t0	,	0($sp)
	addi	$sp	,	$sp	,	-4
	jal	returnchar
	nop
	add	$t0	,	$v0	,	$zero
	li	$t1	,	0
	add	$t0	,	$t0	,	$t1
	sw	$t0	,	-464($fp)
	li	$t0	,	5
	addi	$t0	,	$t0	,	35
	sll	$t0	,	$t0	,	2
	lw	$t0	,	268435856($t0)
	sw	$t0	,	-468($fp)
	lw	$t0	,	-468($fp)
	sw	$t0	,	0($sp)
	addi	$sp	,	$sp	,	-4
	jal	returnchar
	nop
	lw	$t0	,	-464($fp)
	add	$t1	,	$v0	,	$zero
	mul	$t0	,	$t0	,	$t1
	sw	$t0	,	-464($fp)
	li	$t0	,	5
	addi	$t0	,	$t0	,	35
	sll	$t0	,	$t0	,	2
	lw	$t0	,	268435856($t0)
	sw	$t0	,	-472($fp)
	lw	$t0	,	-472($fp)
	sw	$t0	,	0($sp)
	addi	$sp	,	$sp	,	-4
	jal	returnchar
	nop
	lw	$t0	,	-464($fp)
	add	$t1	,	$v0	,	$zero
	mul	$t0	,	$t0	,	$t1
	sw	$t0	,	-464($fp)
	li	$t0	,	95
	lw	$t1	,	-464($fp)
	mul	$t0	,	$t0	,	$t1
	sw	$t0	,	-464($fp)
	lw	$t0	,	-456($fp)
	lw	$t1	,	-464($fp)
	sub	$t0	,	$t0	,	$t1
	sw	$t0	,	-456($fp)
	li	$t0	,	5
	sw	$t0	,	0($sp)
	addi	$sp	,	$sp	,	-4
	jal	fib
	nop
	add	$t0	,	$v0	,	$zero
	li	$t1	,	0
	add	$t0	,	$t0	,	$t1
	sw	$t0	,	-476($fp)
	li	$t0	,	3
	lw	$t1	,	-476($fp)
	add	$t0	,	$t0	,	$t1
	sw	$t0	,	-476($fp)
	lw	$t0	,	-476($fp)
	sw	$t0	,	0($sp)
	addi	$sp	,	$sp	,	-4
	jal	fib
	nop
	add	$t0	,	$v0	,	$zero
	li	$t1	,	0
	add	$t0	,	$t0	,	$t1
	sw	$t0	,	-480($fp)
	li	$t0	,	5
	sw	$t0	,	0($sp)
	addi	$sp	,	$sp	,	-4
	jal	fib
	nop
	add	$t0	,	$v0	,	$zero
	li	$t1	,	0
	add	$t0	,	$t0	,	$t1
	sw	$t0	,	-484($fp)
	lw	$t0	,	-480($fp)
	lw	$t1	,	-484($fp)
	sub	$t0	,	$t0	,	$t1
	sw	$t0	,	-480($fp)
	lw	$t0	,	-480($fp)
	sw	$t0	,	0($sp)
	addi	$sp	,	$sp	,	-4
	jal	fib
	nop
	add	$t0	,	$v0	,	$zero
	li	$t1	,	0
	add	$t0	,	$t0	,	$t1
	sw	$t0	,	-488($fp)
	lw	$t0	,	-488($fp)
	sw	$t0	,	0($sp)
	addi	$sp	,	$sp	,	-4
	jal	fib
	nop
	add	$t0	,	$v0	,	$zero
	li	$t1	,	0
	add	$t0	,	$t0	,	$t1
	sw	$t0	,	-492($fp)
	li	$t0	,	0
	lw	$t1	,	-492($fp)
	sub	$t0	,	$t0	,	$t1
	sw	$t0	,	-492($fp)
	lw	$t0	,	-456($fp)
	lw	$t1	,	-492($fp)
	sub	$t0	,	$t0	,	$t1
	sw	$t0	,	-456($fp)
	li	$t0	,	0
	sw	$t0	,	0($sp)
	addi	$sp	,	$sp	,	-4
	jal	fib
	nop
	add	$t0	,	$v0	,	$zero
	li	$t1	,	0
	add	$t0	,	$t0	,	$t1
	sw	$t0	,	-496($fp)
	li	$t0	,	355200
	lw	$t1	,	-496($fp)
	mul	$t0	,	$t0	,	$t1
	sw	$t0	,	-496($fp)
	lw	$t0	,	-456($fp)
	lw	$t1	,	-496($fp)
	add	$t0	,	$t0	,	$t1
	sw	$t0	,	-456($fp)
	li	$t0	,	0
	sw	$t0	,	0($sp)
	addi	$sp	,	$sp	,	-4
	jal	fib
	nop
	add	$t0	,	$v0	,	$zero
	li	$t1	,	0
	add	$t0	,	$t0	,	$t1
	sw	$t0	,	-500($fp)
	lw	$t0	,	-500($fp)
	sw	$t0	,	0($sp)
	addi	$sp	,	$sp	,	-4
	jal	fib
	nop
	add	$t0	,	$v0	,	$zero
	li	$t1	,	0
	add	$t0	,	$t0	,	$t1
	sw	$t0	,	-504($fp)
	lw	$t0	,	-504($fp)
	sw	$t0	,	0($sp)
	addi	$sp	,	$sp	,	-4
	jal	fib
	nop
	add	$t0	,	$v0	,	$zero
	li	$t1	,	0
	add	$t0	,	$t0	,	$t1
	sw	$t0	,	-508($fp)
	lw	$t0	,	-508($fp)
	addi	$t0	,	$t0	,	4038
	sll	$t0	,	$t0	,	2
	lw	$t0	,	268435856($t0)
	sw	$t0	,	-512($fp)
	li	$t0	,	0
	addi	$t0	,	$t0	,	4038
	sll	$t0	,	$t0	,	2
	lw	$t0	,	268435856($t0)
	sw	$t0	,	-516($fp)
	li	$t0	,	0
	addi	$t0	,	$t0	,	4038
	sll	$t0	,	$t0	,	2
	lw	$t0	,	268435856($t0)
	sw	$t0	,	-520($fp)
	lw	$t0	,	-516($fp)
	lw	$t1	,	-520($fp)
	div	$t0	,	$t1
	mflo	$t0
	sw	$t0	,	-516($fp)
	lw	$t0	,	-516($fp)
	sw	$t0	,	0($sp)
	addi	$sp	,	$sp	,	-4
	jal	fib
	nop
	add	$t0	,	$v0	,	$zero
	li	$t1	,	0
	add	$t0	,	$t0	,	$t1
	sw	$t0	,	-524($fp)
	lw	$t0	,	-524($fp)
	sw	$t0	,	0($sp)
	addi	$sp	,	$sp	,	-4
	jal	fib
	nop
	add	$t0	,	$v0	,	$zero
	li	$t1	,	0
	add	$t0	,	$t0	,	$t1
	sw	$t0	,	-528($fp)
	lw	$t0	,	-528($fp)
	addi	$t0	,	$t0	,	4038
	sll	$t0	,	$t0	,	2
	lw	$t0	,	268435856($t0)
	sw	$t0	,	-532($fp)
	lw	$t0	,	-512($fp)
	lw	$t1	,	-532($fp)
	sub	$t0	,	$t0	,	$t1
	sw	$t0	,	-512($fp)
	lw	$t0	,	-512($fp)
	sw	$t0	,	0($sp)
	addi	$sp	,	$sp	,	-4
	jal	fib
	nop
	add	$t0	,	$v0	,	$zero
	li	$t1	,	0
	add	$t0	,	$t0	,	$t1
	sw	$t0	,	-536($fp)
	lw	$t0	,	-536($fp)
	addi	$t0	,	$t0	,	4038
	sll	$t0	,	$t0	,	2
	lw	$t0	,	268435856($t0)
	sw	$t0	,	-540($fp)
	li	$t0	,	5
	addi	$t0	,	$t0	,	35
	sll	$t0	,	$t0	,	2
	lw	$t0	,	268435856($t0)
	sw	$t0	,	-544($fp)
	lw	$t0	,	-544($fp)
	sw	$t0	,	0($sp)
	addi	$sp	,	$sp	,	-4
	jal	returnchar
	nop
	add	$t0	,	$v0	,	$zero
	li	$t1	,	0
	add	$t0	,	$t0	,	$t1
	sw	$t0	,	-548($fp)
	li	$t0	,	5
	addi	$t0	,	$t0	,	35
	sll	$t0	,	$t0	,	2
	lw	$t0	,	268435856($t0)
	sw	$t0	,	-552($fp)
	lw	$t0	,	-552($fp)
	sw	$t0	,	0($sp)
	addi	$sp	,	$sp	,	-4
	jal	returnchar
	nop
	lw	$t0	,	-548($fp)
	add	$t1	,	$v0	,	$zero
	mul	$t0	,	$t0	,	$t1
	sw	$t0	,	-548($fp)
	li	$t0	,	5
	addi	$t0	,	$t0	,	35
	sll	$t0	,	$t0	,	2
	lw	$t0	,	268435856($t0)
	sw	$t0	,	-556($fp)
	lw	$t0	,	-556($fp)
	sw	$t0	,	0($sp)
	addi	$sp	,	$sp	,	-4
	jal	returnchar
	nop
	lw	$t0	,	-548($fp)
	add	$t1	,	$v0	,	$zero
	mul	$t0	,	$t0	,	$t1
	sw	$t0	,	-548($fp)
	li	$t0	,	95
	lw	$t1	,	-548($fp)
	mul	$t0	,	$t0	,	$t1
	sw	$t0	,	-548($fp)
	lw	$t0	,	-540($fp)
	lw	$t1	,	-548($fp)
	sub	$t0	,	$t0	,	$t1
	sw	$t0	,	-540($fp)
	li	$t0	,	0
	lw	$t1	,	-540($fp)
	sub	$t0	,	$t0	,	$t1
	sw	$t0	,	-540($fp)
	li	$t0	,	5
	sw	$t0	,	0($sp)
	addi	$sp	,	$sp	,	-4
	jal	fib
	nop
	add	$t0	,	$v0	,	$zero
	li	$t1	,	0
	add	$t0	,	$t0	,	$t1
	sw	$t0	,	-560($fp)
	li	$t0	,	3
	lw	$t1	,	-560($fp)
	add	$t0	,	$t0	,	$t1
	sw	$t0	,	-560($fp)
	lw	$t0	,	-560($fp)
	sw	$t0	,	0($sp)
	addi	$sp	,	$sp	,	-4
	jal	fib
	nop
	add	$t0	,	$v0	,	$zero
	li	$t1	,	0
	add	$t0	,	$t0	,	$t1
	sw	$t0	,	-564($fp)
	li	$t0	,	5
	sw	$t0	,	0($sp)
	addi	$sp	,	$sp	,	-4
	jal	fib
	nop
	add	$t0	,	$v0	,	$zero
	li	$t1	,	0
	add	$t0	,	$t0	,	$t1
	sw	$t0	,	-568($fp)
	lw	$t0	,	-564($fp)
	lw	$t1	,	-568($fp)
	sub	$t0	,	$t0	,	$t1
	sw	$t0	,	-564($fp)
	lw	$t0	,	-564($fp)
	sw	$t0	,	0($sp)
	addi	$sp	,	$sp	,	-4
	jal	fib
	nop
	add	$t0	,	$v0	,	$zero
	li	$t1	,	0
	add	$t0	,	$t0	,	$t1
	sw	$t0	,	-572($fp)
	lw	$t0	,	-572($fp)
	sw	$t0	,	0($sp)
	addi	$sp	,	$sp	,	-4
	jal	fib
	nop
	add	$t0	,	$v0	,	$zero
	li	$t1	,	0
	add	$t0	,	$t0	,	$t1
	sw	$t0	,	-576($fp)
	li	$t0	,	0
	lw	$t1	,	-576($fp)
	sub	$t0	,	$t0	,	$t1
	sw	$t0	,	-576($fp)
	lw	$t0	,	-540($fp)
	lw	$t1	,	-576($fp)
	sub	$t0	,	$t0	,	$t1
	sw	$t0	,	-540($fp)
	li	$t0	,	0
	sw	$t0	,	0($sp)
	addi	$sp	,	$sp	,	-4
	jal	fib
	nop
	add	$t0	,	$v0	,	$zero
	li	$t1	,	0
	add	$t0	,	$t0	,	$t1
	sw	$t0	,	-580($fp)
	li	$t0	,	355200
	lw	$t1	,	-580($fp)
	mul	$t0	,	$t0	,	$t1
	sw	$t0	,	-580($fp)
	lw	$t0	,	-540($fp)
	lw	$t1	,	-580($fp)
	add	$t0	,	$t0	,	$t1
	sw	$t0	,	-540($fp)
	lw	$t0	,	-456($fp)
	lw	$t1	,	-540($fp)
	div	$t0	,	$t1
	mflo	$t0
	sw	$t0	,	-456($fp)
	lw	$t0	,	-412($fp)
	lw	$t1	,	-456($fp)
	add	$t0	,	$t0	,	$t1
	sw	$t0	,	-412($fp)
	lw	$t0	,	-412($fp)
	sw	$t0	,	0($sp)
	addi	$sp	,	$sp	,	-4
	jal	fib
	nop
	add	$t0	,	$v0	,	$zero
	li	$t1	,	0
	add	$t0	,	$t0	,	$t1
	sw	$t0	,	-584($fp)
	li	$v0	,	1
	lw	$a0	,	-584($fp)
	syscall
main3$end:
	lw	$ra	,	4($sp)
	lw	$fp	,	8($sp)
	addi	$sp	,	$sp	,	596
	jr	$ra
	nop
main:
	addi	$sp	,	$sp	,	0
	sw	$fp	,	-24($sp)
	sw	$ra	,	-28($sp)
	add	$fp	,	$sp	,	$zero
	addi	$sp	,	$sp	,	-32
	li	$v0	,	4
	la	$a0	,	$Message51
	syscall
	li	$v0	,	12
	syscall
	add	$t0	,	$v0	,	$zero
	sw	$t0	,	0($fp)
	lw	$t0	,	0($fp)
	li	$t1	,	0
	add	$t0	,	$t0	,	$t1
	sw	$t0	,	-4($fp)
	li	$t0	,	97
	li	$t1	,	0
	add	$t0	,	$t0	,	$t1
	sw	$t0	,	-8($fp)
	lw	$t0	,	-8($fp)
	lw	$t1	,	-4($fp)
	sub	$t0	,	$t0	,	$t1
	bne	$t0	,	$zero	,	$label44
	nop
	jal	main1
	nop
	j	$label43
	nop
$label44:
	li	$t0	,	98
	li	$t1	,	0
	add	$t0	,	$t0	,	$t1
	sw	$t0	,	-12($fp)
	lw	$t0	,	-12($fp)
	lw	$t1	,	-4($fp)
	sub	$t0	,	$t0	,	$t1
	bne	$t0	,	$zero	,	$label45
	nop
	jal	main2
	nop
	j	$label43
	nop
$label45:
	li	$t0	,	99
	li	$t1	,	0
	add	$t0	,	$t0	,	$t1
	sw	$t0	,	-16($fp)
	lw	$t0	,	-16($fp)
	lw	$t1	,	-4($fp)
	sub	$t0	,	$t0	,	$t1
	bne	$t0	,	$zero	,	$label46
	nop
	jal	main3
	nop
	j	$label43
	nop
$label46:
	li	$t0	,	100
	li	$t1	,	0
	add	$t0	,	$t0	,	$t1
	sw	$t0	,	-20($fp)
	lw	$t0	,	-20($fp)
	lw	$t1	,	-4($fp)
	sub	$t0	,	$t0	,	$t1
	bne	$t0	,	$zero	,	$label47
	nop
	jal	main4
	nop
	j	$label43
	nop
$label47:
	li	$v0	,	4
	la	$a0	,	$Message52
	syscall
$label43:
	li	$v0	,	10
	syscall
