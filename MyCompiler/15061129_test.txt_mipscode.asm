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
	sw	$t0	,	-32($sp)
	sw	$t1	,	-36($sp)
	sw	$t2	,	-40($sp)
	sw	$t3	,	-44($sp)
	sw	$t4	,	-48($sp)
	sw	$t5	,	-52($sp)
	sw	$t6	,	-56($sp)
	sw	$s0	,	-60($sp)
	sw	$s1	,	-64($sp)
	sw	$s2	,	-68($sp)
	sw	$s3	,	-72($sp)
	sw	$s4	,	-76($sp)
	sw	$s5	,	-80($sp)
	sw	$s6	,	-84($sp)
	sw	$fp	,	-88($sp)
	sw	$ra	,	-92($sp)
	add	$fp	,	$sp	,	$zero
	addi	$sp	,	$sp	,	-96
	lw	$t2	,	0($fp)
	addi	$t0	,	$t2	,	0
	subi	$t7	,	$t0	,	0
	bgtz	$t7	,	$label0
	nop
	li	$v0	,	0
	j	$label4
	nop
$label0:
	sw	$t0	,	-4($fp)
	addi	$t0	,	$t2	,	0
	subi	$t7	,	$t0	,	1
	bne	$t7	,	$zero	,	$label2
	nop
	li	$v0	,	1
	j	$label4
	nop
$label2:
	sw	$t0	,	-8($fp)
	addi	$t0	,	$t2	,	0
	subi	$t7	,	$t0	,	2
	bltz	$t7	,	$label4
	nop
	sw	$t0	,	-12($fp)
	addi	$t0	,	$t2	,	0
	subi	$t0	,	$t0	,	1
	sw	$t0	,	0($sp)
	addi	$sp	,	$sp	,	-4
	jal	fibo
	nop
	addi	$t1	,	$v0	,	0
	sw	$t0	,	-16($fp)
	addi	$t0	,	$t2	,	0
	subi	$t0	,	$t0	,	2
	sw	$t0	,	0($sp)
	addi	$sp	,	$sp	,	-4
	jal	fibo
	nop
	sw	$t0	,	-24($fp)
	addi	$t0	,	$v0	,	0
	add	$t1	,	$t1	,	$t0
	addi	$v0	,	$t1	,	0
$label4:
	lw	$ra	,	4($sp)
	lw	$fp	,	8($sp)
	lw	$s6	,	12($sp)
	lw	$s5	,	16($sp)
	lw	$s4	,	20($sp)
	lw	$s3	,	24($sp)
	lw	$s2	,	28($sp)
	lw	$s1	,	32($sp)
	lw	$s0	,	36($sp)
	lw	$t6	,	40($sp)
	lw	$t5	,	44($sp)
	lw	$t4	,	48($sp)
	lw	$t3	,	52($sp)
	lw	$t2	,	56($sp)
	lw	$t1	,	60($sp)
	lw	$t0	,	64($sp)
	addi	$sp	,	$sp	,	96
	jr	$ra
	nop
main4:
	addi	$sp	,	$sp	,	0
	sw	$t0	,	-12($sp)
	sw	$t1	,	-16($sp)
	sw	$t2	,	-20($sp)
	sw	$t3	,	-24($sp)
	sw	$t4	,	-28($sp)
	sw	$t5	,	-32($sp)
	sw	$t6	,	-36($sp)
	sw	$s0	,	-40($sp)
	sw	$s1	,	-44($sp)
	sw	$s2	,	-48($sp)
	sw	$s3	,	-52($sp)
	sw	$s4	,	-56($sp)
	sw	$s5	,	-60($sp)
	sw	$s6	,	-64($sp)
	sw	$fp	,	-68($sp)
	sw	$ra	,	-72($sp)
	add	$fp	,	$sp	,	$zero
	addi	$sp	,	$sp	,	-76
	li	$v0	,	5
	syscall
	add	$t1	,	$v0	,	$zero
	addi	$t0	,	$t1	,	0
	sw	$t0	,	0($sp)
	addi	$sp	,	$sp	,	-4
	jal	fibo
	nop
	sw	$t0	,	-4($fp)
	addi	$t0	,	$v0	,	0
	li	$v0	,	1
	add	$a0	,	$t0	,	$zero
	syscall
main4$end:
	lw	$ra	,	4($sp)
	lw	$fp	,	8($sp)
	lw	$s6	,	12($sp)
	lw	$s5	,	16($sp)
	lw	$s4	,	20($sp)
	lw	$s3	,	24($sp)
	lw	$s2	,	28($sp)
	lw	$s1	,	32($sp)
	lw	$s0	,	36($sp)
	lw	$t6	,	40($sp)
	lw	$t5	,	44($sp)
	lw	$t4	,	48($sp)
	lw	$t3	,	52($sp)
	lw	$t2	,	56($sp)
	lw	$t1	,	60($sp)
	lw	$t0	,	64($sp)
	addi	$sp	,	$sp	,	76
	jr	$ra
	nop
fib:
	addi	$sp	,	$sp	,	4
	sw	$t0	,	-336($sp)
	sw	$t1	,	-340($sp)
	sw	$t2	,	-344($sp)
	sw	$t3	,	-348($sp)
	sw	$t4	,	-352($sp)
	sw	$t5	,	-356($sp)
	sw	$t6	,	-360($sp)
	sw	$s0	,	-364($sp)
	sw	$s1	,	-368($sp)
	sw	$s2	,	-372($sp)
	sw	$s3	,	-376($sp)
	sw	$s4	,	-380($sp)
	sw	$s5	,	-384($sp)
	sw	$s6	,	-388($sp)
	sw	$fp	,	-392($sp)
	sw	$ra	,	-396($sp)
	add	$fp	,	$sp	,	$zero
	addi	$sp	,	$sp	,	-400
	lw	$s0	,	0($fp)
	addi	$t0	,	$s0	,	0
	sub	$t0	,	$zero	,	$t0
	subi	$t7	,	$t0	,	-1
	bgez	$t7	,	$label6
	nop
	addi	$t1	,	$s0	,	0
	subi	$t1	,	$t1	,	1
	addi	$t9	,	$t1	,	2037
	sll	$t9	,	$t9	,	2
	sw	$t0	,	-216($fp)
	lw	$t0	,	268435856($t9)
	subi	$t7	,	$t0	,	-1
	bgtz	$t7	,	$label8
	nop
	sw	$t0	,	-224($fp)
	addi	$t0	,	$s0	,	0
	subi	$t0	,	$t0	,	1
	sw	$t0	,	0($sp)
	addi	$sp	,	$sp	,	-4
	jal	fib
	nop
	sw	$t0	,	-228($fp)
	addi	$t0	,	$v0	,	0
	addi	$s2	,	$t0	,	0
	j	$label9
	nop
$label8:
	sw	$t1	,	-220($fp)
	addi	$t1	,	$s0	,	0
	subi	$t1	,	$t1	,	1
	addi	$t9	,	$t1	,	2037
	sll	$t9	,	$t9	,	2
	sw	$t0	,	-232($fp)
	lw	$t0	,	268435856($t9)
	addi	$s2	,	$t0	,	0
$label9:
	addi	$t2	,	$s0	,	0
	subi	$t6	,	$t2	,	2
	addi	$t9	,	$t6	,	2037
	sll	$t9	,	$t9	,	2
	lw	$t5	,	268435856($t9)
	addi	$s1	,	$t5	,	0
	addi	$t3	,	$s1	,	0
	addi	$t4	,	$s2	,	0
	add	$t4	,	$t4	,	$t3
	addi	$s3	,	$t4	,	0
	sw	$t1	,	-236($fp)
	addi	$t1	,	$s3	,	0
	addi	$t7	,	$t2	,	2037
	sll	$t7	,	$t7	,	2
	sw	$t1	,	268435856($t7)
	addi	$v0	,	$t1	,	0
	j	$label11
	nop
$label6:
	sw	$t0	,	-240($fp)
	addi	$t0	,	$s0	,	0
	sw	$t1	,	-264($fp)
	addi	$t1	,	$t0	,	1
	sw	$t2	,	-260($fp)
	mul	$t2	,	$t0	,	$t1
	div	$t2	,	$t1
	mflo	$t2
	subi	$t7	,	$t2	,	0
	beq	$t7	,	$zero	,	$label10
	nop
	sw	$t6	,	-244($fp)
	li	$t6	,	1
	li	$t8	,	1
	addi	$t7	,	$t8	,	4
	sll	$t7	,	$t7	,	2
	sub	$t7	,	$fp	,	$t7
	sw	$t6	,	0($t7)
	li	$t8	,	1
	addi	$t9	,	$t8	,	4
	sll	$t9	,	$t9	,	2
	sw	$t4	,	-252($fp)
	sub	$t9	,	$fp	,	$t9
	lw	$t4	,	0($t9)
	li	$t8	,	1
	addi	$t7	,	$t8	,	2037
	sll	$t7	,	$t7	,	2
	sw	$t6	,	268435856($t7)
	addi	$t9	,	$t4	,	2037
	sll	$t9	,	$t9	,	2
	sw	$t3	,	-256($fp)
	lw	$t3	,	268435856($t9)
	addi	$t9	,	$t3	,	4
	sll	$t9	,	$t9	,	2
	sw	$t2	,	-272($fp)
	sub	$t9	,	$fp	,	$t9
	lw	$t2	,	0($t9)
	mul	$t2	,	$t2	,	$t3
	addi	$v0	,	$t2	,	0
	j	$label11
	nop
$label10:
	sw	$t5	,	-248($fp)
	li	$t5	,	0
	li	$t8	,	0
	addi	$t7	,	$t8	,	2037
	sll	$t7	,	$t7	,	2
	sw	$t5	,	268435856($t7)
	li	$t8	,	0
	addi	$t9	,	$t8	,	2037
	sll	$t9	,	$t9	,	2
	sw	$t3	,	-296($fp)
	lw	$t3	,	268435856($t9)
	li	$t8	,	0
	addi	$t7	,	$t8	,	4
	sll	$t7	,	$t7	,	2
	sub	$t7	,	$fp	,	$t7
	sw	$t5	,	0($t7)
	li	$t8	,	0
	addi	$t9	,	$t8	,	4
	sll	$t9	,	$t9	,	2
	sw	$t1	,	-276($fp)
	sub	$t9	,	$fp	,	$t9
	lw	$t1	,	0($t9)
	addi	$t9	,	$t1	,	2037
	sll	$t9	,	$t9	,	2
	sw	$t0	,	-280($fp)
	lw	$t0	,	268435856($t9)
	addi	$t9	,	$t3	,	4
	sll	$t9	,	$t9	,	2
	sw	$t2	,	-300($fp)
	sub	$t9	,	$fp	,	$t9
	lw	$t2	,	0($t9)
	mul	$t2	,	$t2	,	$t0
	addi	$v0	,	$t2	,	0
$label11:
	lw	$ra	,	4($sp)
	lw	$fp	,	8($sp)
	lw	$s6	,	12($sp)
	lw	$s5	,	16($sp)
	lw	$s4	,	20($sp)
	lw	$s3	,	24($sp)
	lw	$s2	,	28($sp)
	lw	$s1	,	32($sp)
	lw	$s0	,	36($sp)
	lw	$t6	,	40($sp)
	lw	$t5	,	44($sp)
	lw	$t4	,	48($sp)
	lw	$t3	,	52($sp)
	lw	$t2	,	56($sp)
	lw	$t1	,	60($sp)
	lw	$t0	,	64($sp)
	addi	$sp	,	$sp	,	400
	jr	$ra
	nop
main1:
	addi	$sp	,	$sp	,	0
	sw	$t0	,	-92($sp)
	sw	$t1	,	-96($sp)
	sw	$t2	,	-100($sp)
	sw	$t3	,	-104($sp)
	sw	$t4	,	-108($sp)
	sw	$t5	,	-112($sp)
	sw	$t6	,	-116($sp)
	sw	$s0	,	-120($sp)
	sw	$s1	,	-124($sp)
	sw	$s2	,	-128($sp)
	sw	$s3	,	-132($sp)
	sw	$s4	,	-136($sp)
	sw	$s5	,	-140($sp)
	sw	$s6	,	-144($sp)
	sw	$fp	,	-148($sp)
	sw	$ra	,	-152($sp)
	add	$fp	,	$sp	,	$zero
	addi	$sp	,	$sp	,	-156
	li	$s2	,	0
$label12:
	addi	$t0	,	$s2	,	0
	subi	$t7	,	$t0	,	46
	bgez	$t7	,	$label13
	nop
	addi	$s1	,	$s2	,	0
	li	$s0	,	-1
	addi	$t7	,	$s1	,	3037
	sll	$t7	,	$t7	,	2
	sw	$s0	,	268435856($t7)
	addi	$t7	,	$s1	,	2037
	sll	$t7	,	$t7	,	2
	sw	$s0	,	268435856($t7)
	li	$t3	,	48
	addi	$t7	,	$s1	,	35
	sll	$t7	,	$t7	,	2
	sw	$t3	,	268435856($t7)
	addi	$t7	,	$s1	,	1035
	sll	$t7	,	$t7	,	2
	sw	$t3	,	268435856($t7)
	sw	$t0	,	-4($fp)
	addi	$t0	,	$s1	,	1
	addi	$s2	,	$t0	,	0
	j	$label12
	nop
$label13:
	li	$t7	,	0
	sw	$t7	,	268452004($zero)
	li	$v0	,	4
	la	$a0	,	$Message0
	syscall
	li	$v0	,	5
	syscall
	add	$t7	,	$v0	,	$zero
	sw	$t7	,	268452004($zero)
	lw	$t9	,	268452004($zero)
	sw	$t0	,	-40($fp)
	addi	$t0	,	$t9	,	0
	subi	$t7	,	$t0	,	2
	bgez	$t7	,	$label14
	nop
	li	$v0	,	4
	la	$a0	,	$Message1
	syscall
	j	$label19
	nop
$label14:
	lw	$t9	,	268452004($zero)
	sw	$t0	,	-44($fp)
	addi	$t0	,	$t9	,	0
	subi	$t7	,	$t0	,	45
	blez	$t7	,	$label16
	nop
	li	$v0	,	4
	la	$a0	,	$Message2
	syscall
	j	$label19
	nop
$label16:
	lw	$t9	,	268452004($zero)
	addi	$t1	,	$t9	,	0
	li	$t7	,	0
	sw	$t7	,	0($sp)
	addi	$sp	,	$sp	,	-4
	jal	fib
	nop
	sw	$t0	,	-48($fp)
	addi	$t0	,	$v0	,	0
	add	$t1	,	$t1	,	$t0
	li	$t7	,	1
	sw	$t7	,	0($sp)
	addi	$sp	,	$sp	,	-4
	jal	fib
	nop
	sw	$t0	,	-56($fp)
	addi	$t0	,	$v0	,	0
	sub	$t1	,	$t1	,	$t0
	li	$t7	,	2
	sw	$t7	,	0($sp)
	addi	$sp	,	$sp	,	-4
	jal	fib
	nop
	sw	$t0	,	-60($fp)
	addi	$t0	,	$v0	,	0
	add	$t1	,	$t1	,	$t0
	sw	$t1	,	0($sp)
	addi	$sp	,	$sp	,	-4
	jal	fib
	nop
$label18:
	lw	$t9	,	268452004($zero)
	sw	$t0	,	-64($fp)
	addi	$t0	,	$t9	,	0
	subi	$t7	,	$t0	,	0
	bltz	$t7	,	$label19
	nop
	lw	$t9	,	268452004($zero)
	sw	$t0	,	-68($fp)
	addi	$t0	,	$t9	,	0
	addi	$t9	,	$t0	,	2037
	sll	$t9	,	$t9	,	2
	lw	$t2	,	268435856($t9)
	sub	$t2	,	$zero	,	$t2
	sub	$t2	,	$zero	,	$t2
	li	$v0	,	1
	add	$a0	,	$t2	,	$zero
	syscall
	lw	$t9	,	268452004($zero)
	sw	$t1	,	-52($fp)
	addi	$t1	,	$t9	,	0
	addi	$t9	,	$t1	,	3037
	sll	$t9	,	$t9	,	2
	sw	$t0	,	-72($fp)
	lw	$t0	,	268435856($t9)
	subi	$t7	,	$t0	,	-1
	beq	$t7	,	$zero	,	$label20
	nop
	li	$v0	,	4
	la	$a0	,	$Message3
	syscall
$label20:
	li	$v0	,	4
	la	$a0	,	$Message4
	syscall
	lw	$t9	,	268452004($zero)
	sw	$t0	,	-84($fp)
	addi	$t0	,	$t9	,	0
	subi	$t0	,	$t0	,	1
	addi	$t7	,	$t0	,	0
	sw	$t7	,	268452004($zero)
	j	$label18
	nop
$label19:
	lw	$ra	,	4($sp)
	lw	$fp	,	8($sp)
	lw	$s6	,	12($sp)
	lw	$s5	,	16($sp)
	lw	$s4	,	20($sp)
	lw	$s3	,	24($sp)
	lw	$s2	,	28($sp)
	lw	$s1	,	32($sp)
	lw	$s0	,	36($sp)
	lw	$t6	,	40($sp)
	lw	$t5	,	44($sp)
	lw	$t4	,	48($sp)
	lw	$t3	,	52($sp)
	lw	$t2	,	56($sp)
	lw	$t1	,	60($sp)
	lw	$t0	,	64($sp)
	addi	$sp	,	$sp	,	156
	jr	$ra
	nop
printarray:
	addi	$sp	,	$sp	,	0
	sw	$t0	,	-32($sp)
	sw	$t1	,	-36($sp)
	sw	$t2	,	-40($sp)
	sw	$t3	,	-44($sp)
	sw	$t4	,	-48($sp)
	sw	$t5	,	-52($sp)
	sw	$t6	,	-56($sp)
	sw	$s0	,	-60($sp)
	sw	$s1	,	-64($sp)
	sw	$s2	,	-68($sp)
	sw	$s3	,	-72($sp)
	sw	$s4	,	-76($sp)
	sw	$s5	,	-80($sp)
	sw	$s6	,	-84($sp)
	sw	$fp	,	-88($sp)
	sw	$ra	,	-92($sp)
	add	$fp	,	$sp	,	$zero
	addi	$sp	,	$sp	,	-96
	li	$t2	,	1
	lw	$t9	,	268456412($zero)
	addi	$t0	,	$t9	,	0
	subi	$t7	,	$t0	,	1
	bltz	$t7	,	$label22
	nop
	li	$t8	,	0
	addi	$t9	,	$t8	,	5038
	sll	$t9	,	$t9	,	2
	sw	$t0	,	-4($fp)
	lw	$t0	,	268435856($t9)
	li	$v0	,	1
	add	$a0	,	$t0	,	$zero
	syscall
	j	$label23
	nop
$label22:
	li	$v0	,	-1
	j	printarray$end
	nop
$label23:
	addi	$t1	,	$t2	,	0
	lw	$t9	,	268456412($zero)
	sw	$t0	,	-8($fp)
	addi	$t0	,	$t9	,	0
	sub	$t7	,	$t1	,	$t0
	bgez	$t7	,	$label25
	nop
	sw	$t0	,	-16($fp)
	addi	$t0	,	$t2	,	0
	addi	$t9	,	$t0	,	5038
	sll	$t9	,	$t9	,	2
	sw	$t1	,	-12($fp)
	lw	$t1	,	268435856($t9)
	li	$v0	,	4
	la	$a0	,	$Message5
	syscall
	li	$v0	,	1
	add	$a0	,	$t1	,	$zero
	syscall
	sw	$t0	,	-20($fp)
	addi	$t0	,	$t2	,	0
	addi	$t0	,	$t0	,	1
	addi	$t2	,	$t0	,	0
	j	$label23
	nop
$label25:
	li	$v0	,	0
printarray$end:
	lw	$ra	,	4($sp)
	lw	$fp	,	8($sp)
	lw	$s6	,	12($sp)
	lw	$s5	,	16($sp)
	lw	$s4	,	20($sp)
	lw	$s3	,	24($sp)
	lw	$s2	,	28($sp)
	lw	$s1	,	32($sp)
	lw	$s0	,	36($sp)
	lw	$t6	,	40($sp)
	lw	$t5	,	44($sp)
	lw	$t4	,	48($sp)
	lw	$t3	,	52($sp)
	lw	$t2	,	56($sp)
	lw	$t1	,	60($sp)
	lw	$t0	,	64($sp)
	addi	$sp	,	$sp	,	96
	jr	$ra
	nop
quicksort:
	addi	$sp	,	$sp	,	8
	sw	$t0	,	-144($sp)
	sw	$t1	,	-148($sp)
	sw	$t2	,	-152($sp)
	sw	$t3	,	-156($sp)
	sw	$t4	,	-160($sp)
	sw	$t5	,	-164($sp)
	sw	$t6	,	-168($sp)
	sw	$s0	,	-172($sp)
	sw	$s1	,	-176($sp)
	sw	$s2	,	-180($sp)
	sw	$s3	,	-184($sp)
	sw	$s4	,	-188($sp)
	sw	$s5	,	-192($sp)
	sw	$s6	,	-196($sp)
	sw	$fp	,	-200($sp)
	sw	$ra	,	-204($sp)
	add	$fp	,	$sp	,	$zero
	addi	$sp	,	$sp	,	-208
	lw	$s6	,	0($fp)
	addi	$t1	,	$s6	,	0
	lw	$s5	,	-4($fp)
	addi	$t0	,	$s5	,	0
	sub	$t7	,	$t1	,	$t0
	bltz	$t7	,	$label26
	nop
	j	quicksort$end
	nop
$label26:
	sw	$t0	,	-24($fp)
	addi	$t0	,	$s6	,	0
	sw	$t1	,	-20($fp)
	addi	$t1	,	$t0	,	1
	addi	$s4	,	$t1	,	0
	addi	$s3	,	$t0	,	0
$label28:
	sw	$t1	,	-28($fp)
	addi	$t1	,	$s4	,	0
	sw	$t0	,	-32($fp)
	addi	$t0	,	$s5	,	0
	sub	$t7	,	$t1	,	$t0
	bgtz	$t7	,	$label29
	nop
	addi	$t3	,	$s4	,	0
	addi	$t9	,	$t3	,	5038
	sll	$t9	,	$t9	,	2
	lw	$t2	,	268435856($t9)
	sw	$t1	,	-36($fp)
	addi	$t1	,	$s3	,	0
	addi	$t9	,	$t1	,	5038
	sll	$t9	,	$t9	,	2
	sw	$t0	,	-40($fp)
	lw	$t0	,	268435856($t9)
	sub	$t7	,	$t2	,	$t0
	bgez	$t7	,	$label30
	nop
	addi	$s1	,	$s4	,	0
	addi	$t9	,	$s1	,	5038
	sll	$t9	,	$t9	,	2
	lw	$s0	,	268435856($t9)
	addi	$t5	,	$s3	,	0
	addi	$t9	,	$t5	,	5038
	sll	$t9	,	$t9	,	2
	lw	$t4	,	268435856($t9)
	addi	$t7	,	$s1	,	5038
	sll	$t7	,	$t7	,	2
	sw	$t4	,	268435856($t7)
	addi	$s2	,	$s0	,	0
	sw	$t2	,	-48($fp)
	addi	$t2	,	$s2	,	0
	addi	$t7	,	$t5	,	5038
	sll	$t7	,	$t7	,	2
	sw	$t2	,	268435856($t7)
	addi	$t9	,	$s1	,	5038
	sll	$t9	,	$t9	,	2
	sw	$t0	,	-56($fp)
	lw	$t0	,	268435856($t9)
	addi	$t7	,	$t5	,	1
	sw	$t7	,	-100($fp)
	lw	$t8	,	-100($fp)
	addi	$t9	,	$t8	,	5038
	sll	$t9	,	$t9	,	2
	lw	$t7	,	268435856($t9)
	sw	$t7	,	-104($fp)
	addi	$t7	,	$s1	,	5038
	sll	$t7	,	$t7	,	2
	lw	$t9	,	-104($fp)
	sw	$t9	,	268435856($t7)
	addi	$s2	,	$t0	,	0
	addi	$t7	,	$s2	,	0
	sw	$t7	,	-112($fp)
	lw	$t8	,	-100($fp)
	addi	$t7	,	$t8	,	5038
	sll	$t7	,	$t7	,	2
	lw	$t9	,	-112($fp)
	sw	$t9	,	268435856($t7)
	lw	$t9	,	-100($fp)
	addi	$s3	,	$t9	,	0
	lw	$t9	,	268456408($zero)
	addi	$t7	,	$t9	,	0
	sw	$t7	,	-120($fp)
	lw	$t9	,	-120($fp)
	addi	$t7	,	$t9	,	1
	sw	$t7	,	-120($fp)
	lw	$t9	,	-120($fp)
	addi	$t7	,	$t9	,	0
	sw	$t7	,	268456408($zero)
$label30:
	sw	$t0	,	-92($fp)
	addi	$t0	,	$s4	,	0
	addi	$t0	,	$t0	,	1
	addi	$s4	,	$t0	,	0
	j	$label28
	nop
$label29:
	sw	$t1	,	-52($fp)
	addi	$t1	,	$s6	,	0
	sw	$t1	,	0($sp)
	addi	$sp	,	$sp	,	-4
	sw	$t0	,	-124($fp)
	addi	$t0	,	$s3	,	0
	subi	$t0	,	$t0	,	1
	sw	$t0	,	0($sp)
	addi	$sp	,	$sp	,	-4
	jal	quicksort
	nop
	sw	$t1	,	-128($fp)
	addi	$t1	,	$s3	,	0
	addi	$t1	,	$t1	,	1
	sw	$t1	,	0($sp)
	addi	$sp	,	$sp	,	-4
	sw	$t0	,	-132($fp)
	addi	$t0	,	$s5	,	0
	sw	$t0	,	0($sp)
	addi	$sp	,	$sp	,	-4
	jal	quicksort
	nop
quicksort$end:
	lw	$ra	,	4($sp)
	lw	$fp	,	8($sp)
	lw	$s6	,	12($sp)
	lw	$s5	,	16($sp)
	lw	$s4	,	20($sp)
	lw	$s3	,	24($sp)
	lw	$s2	,	28($sp)
	lw	$s1	,	32($sp)
	lw	$s0	,	36($sp)
	lw	$t6	,	40($sp)
	lw	$t5	,	44($sp)
	lw	$t4	,	48($sp)
	lw	$t3	,	52($sp)
	lw	$t2	,	56($sp)
	lw	$t1	,	60($sp)
	lw	$t0	,	64($sp)
	addi	$sp	,	$sp	,	208
	jr	$ra
	nop
return1:
	addi	$sp	,	$sp	,	0
	sw	$t0	,	0($sp)
	sw	$t1	,	-4($sp)
	sw	$t2	,	-8($sp)
	sw	$t3	,	-12($sp)
	sw	$t4	,	-16($sp)
	sw	$t5	,	-20($sp)
	sw	$t6	,	-24($sp)
	sw	$s0	,	-28($sp)
	sw	$s1	,	-32($sp)
	sw	$s2	,	-36($sp)
	sw	$s3	,	-40($sp)
	sw	$s4	,	-44($sp)
	sw	$s5	,	-48($sp)
	sw	$s6	,	-52($sp)
	sw	$fp	,	-56($sp)
	sw	$ra	,	-60($sp)
	add	$fp	,	$sp	,	$zero
	addi	$sp	,	$sp	,	-64
	li	$v0	,	1
return1$end:
	lw	$ra	,	4($sp)
	lw	$fp	,	8($sp)
	lw	$s6	,	12($sp)
	lw	$s5	,	16($sp)
	lw	$s4	,	20($sp)
	lw	$s3	,	24($sp)
	lw	$s2	,	28($sp)
	lw	$s1	,	32($sp)
	lw	$s0	,	36($sp)
	lw	$t6	,	40($sp)
	lw	$t5	,	44($sp)
	lw	$t4	,	48($sp)
	lw	$t3	,	52($sp)
	lw	$t2	,	56($sp)
	lw	$t1	,	60($sp)
	lw	$t0	,	64($sp)
	addi	$sp	,	$sp	,	64
	jr	$ra
	nop
return999:
	addi	$sp	,	$sp	,	0
	sw	$t0	,	0($sp)
	sw	$t1	,	-4($sp)
	sw	$t2	,	-8($sp)
	sw	$t3	,	-12($sp)
	sw	$t4	,	-16($sp)
	sw	$t5	,	-20($sp)
	sw	$t6	,	-24($sp)
	sw	$s0	,	-28($sp)
	sw	$s1	,	-32($sp)
	sw	$s2	,	-36($sp)
	sw	$s3	,	-40($sp)
	sw	$s4	,	-44($sp)
	sw	$s5	,	-48($sp)
	sw	$s6	,	-52($sp)
	sw	$fp	,	-56($sp)
	sw	$ra	,	-60($sp)
	add	$fp	,	$sp	,	$zero
	addi	$sp	,	$sp	,	-64
	li	$v0	,	999
return999$end:
	lw	$ra	,	4($sp)
	lw	$fp	,	8($sp)
	lw	$s6	,	12($sp)
	lw	$s5	,	16($sp)
	lw	$s4	,	20($sp)
	lw	$s3	,	24($sp)
	lw	$s2	,	28($sp)
	lw	$s1	,	32($sp)
	lw	$s0	,	36($sp)
	lw	$t6	,	40($sp)
	lw	$t5	,	44($sp)
	lw	$t4	,	48($sp)
	lw	$t3	,	52($sp)
	lw	$t2	,	56($sp)
	lw	$t1	,	60($sp)
	lw	$t0	,	64($sp)
	addi	$sp	,	$sp	,	64
	jr	$ra
	nop
returnminus998:
	addi	$sp	,	$sp	,	0
	sw	$t0	,	0($sp)
	sw	$t1	,	-4($sp)
	sw	$t2	,	-8($sp)
	sw	$t3	,	-12($sp)
	sw	$t4	,	-16($sp)
	sw	$t5	,	-20($sp)
	sw	$t6	,	-24($sp)
	sw	$s0	,	-28($sp)
	sw	$s1	,	-32($sp)
	sw	$s2	,	-36($sp)
	sw	$s3	,	-40($sp)
	sw	$s4	,	-44($sp)
	sw	$s5	,	-48($sp)
	sw	$s6	,	-52($sp)
	sw	$fp	,	-56($sp)
	sw	$ra	,	-60($sp)
	add	$fp	,	$sp	,	$zero
	addi	$sp	,	$sp	,	-64
	li	$v0	,	-998
returnminus998$end:
	lw	$ra	,	4($sp)
	lw	$fp	,	8($sp)
	lw	$s6	,	12($sp)
	lw	$s5	,	16($sp)
	lw	$s4	,	20($sp)
	lw	$s3	,	24($sp)
	lw	$s2	,	28($sp)
	lw	$s1	,	32($sp)
	lw	$s0	,	36($sp)
	lw	$t6	,	40($sp)
	lw	$t5	,	44($sp)
	lw	$t4	,	48($sp)
	lw	$t3	,	52($sp)
	lw	$t2	,	56($sp)
	lw	$t1	,	60($sp)
	lw	$t0	,	64($sp)
	addi	$sp	,	$sp	,	64
	jr	$ra
	nop
main2:
	addi	$sp	,	$sp	,	0
	sw	$t0	,	-84($sp)
	sw	$t1	,	-88($sp)
	sw	$t2	,	-92($sp)
	sw	$t3	,	-96($sp)
	sw	$t4	,	-100($sp)
	sw	$t5	,	-104($sp)
	sw	$t6	,	-108($sp)
	sw	$s0	,	-112($sp)
	sw	$s1	,	-116($sp)
	sw	$s2	,	-120($sp)
	sw	$s3	,	-124($sp)
	sw	$s4	,	-128($sp)
	sw	$s5	,	-132($sp)
	sw	$s6	,	-136($sp)
	sw	$fp	,	-140($sp)
	sw	$ra	,	-144($sp)
	add	$fp	,	$sp	,	$zero
	addi	$sp	,	$sp	,	-148
	li	$t7	,	0
	sw	$t7	,	268456408($zero)
	lw	$t9	,	268456408($zero)
	addi	$t4	,	$t9	,	0
	li	$v0	,	4
	la	$a0	,	$Message6
	syscall
	li	$v0	,	5
	syscall
	add	$t7	,	$v0	,	$zero
	sw	$t7	,	268456412($zero)
	lw	$t9	,	268456412($zero)
	addi	$t0	,	$t9	,	0
	subi	$t7	,	$t0	,	0
	beq	$t7	,	$zero	,	$label32
	nop
	lw	$t9	,	268456412($zero)
	addi	$t1	,	$t9	,	0
	lw	$t8	,	268456412($zero)
	sw	$t0	,	-8($fp)
	mul	$t0	,	$t1	,	$t8
	add	$t1	,	$t1	,	$t0
	lw	$t8	,	268456412($zero)
	div	$t1	,	$t8
	mflo	$t1
	subi	$t1	,	$t1	,	1
	addi	$t7	,	$t1	,	0
	sw	$t7	,	268456412($zero)
$label32:
	li	$v0	,	4
	la	$a0	,	$Message7
	syscall
$label34:
	sw	$t1	,	-12($fp)
	addi	$t1	,	$t4	,	0
	lw	$t9	,	268456412($zero)
	sw	$t0	,	-16($fp)
	addi	$t0	,	$t9	,	0
	sub	$t7	,	$t1	,	$t0
	bgez	$t7	,	$label35
	nop
	li	$v0	,	5
	syscall
	add	$t3	,	$v0	,	$zero
	addi	$t2	,	$t4	,	0
	sw	$t1	,	-20($fp)
	addi	$t1	,	$t2	,	0
	sw	$t0	,	-24($fp)
	addi	$t0	,	$t3	,	0
	addi	$t7	,	$t2	,	5038
	sll	$t7	,	$t7	,	2
	sw	$t0	,	268435856($t7)
	jal	return999
	nop
	sw	$t0	,	-32($fp)
	addi	$t0	,	$v0	,	0
	add	$t1	,	$t1	,	$t0
	jal	returnminus998
	nop
	sw	$t0	,	-40($fp)
	addi	$t0	,	$v0	,	0
	add	$t1	,	$t1	,	$t0
	addi	$t4	,	$t1	,	0
	j	$label34
	nop
$label35:
	lw	$t9	,	268456412($zero)
	sw	$t1	,	-36($fp)
	addi	$t1	,	$t9	,	0
	sw	$t0	,	-44($fp)
	li	$t0	,	0
	sub	$t7	,	$t0	,	$t1
	bne	$t7	,	$zero	,	$label37
	nop
	jal	printarray
	nop
	j	$label40
	nop
$label37:
	sw	$t0	,	-52($fp)
	li	$t0	,	1
	sub	$t7	,	$t0	,	$t1
	bne	$t7	,	$zero	,	$label38
	nop
	jal	printarray
	nop
	j	$label40
	nop
$label38:
	lw	$t9	,	268456412($zero)
	sw	$t0	,	-56($fp)
	addi	$t0	,	$t9	,	0
	subi	$t7	,	$t0	,	0
	bgez	$t7	,	$label39
	nop
	li	$v0	,	4
	la	$a0	,	$Message8
	syscall
	j	main2$end
	nop
$label39:
	jal	return999
	nop
	sw	$t0	,	-60($fp)
	addi	$t0	,	$v0	,	0
	subi	$t0	,	$t0	,	999
	sw	$t0	,	0($sp)
	addi	$sp	,	$sp	,	-4
	lw	$t9	,	268456412($zero)
	sw	$t2	,	-28($fp)
	addi	$t2	,	$t9	,	0
	jal	return999
	nop
	sw	$t1	,	-48($fp)
	addi	$t1	,	$v0	,	0
	jal	returnminus998
	nop
	sw	$t0	,	-64($fp)
	addi	$t0	,	$v0	,	0
	add	$t1	,	$t1	,	$t0
	sub	$t2	,	$t2	,	$t1
	sw	$t2	,	0($sp)
	addi	$sp	,	$sp	,	-4
	jal	quicksort
	nop
	jal	printarray
	nop
$label40:
	lw	$t9	,	268456408($zero)
	sw	$t0	,	-76($fp)
	addi	$t0	,	$t9	,	0
	li	$v0	,	4
	la	$a0	,	$Message9
	syscall
	li	$v0	,	1
	add	$a0	,	$t0	,	$zero
	syscall
main2$end:
	lw	$ra	,	4($sp)
	lw	$fp	,	8($sp)
	lw	$s6	,	12($sp)
	lw	$s5	,	16($sp)
	lw	$s4	,	20($sp)
	lw	$s3	,	24($sp)
	lw	$s2	,	28($sp)
	lw	$s1	,	32($sp)
	lw	$s0	,	36($sp)
	lw	$t6	,	40($sp)
	lw	$t5	,	44($sp)
	lw	$t4	,	48($sp)
	lw	$t3	,	52($sp)
	lw	$t2	,	56($sp)
	lw	$t1	,	60($sp)
	lw	$t0	,	64($sp)
	addi	$sp	,	$sp	,	148
	jr	$ra
	nop
returna:
	addi	$sp	,	$sp	,	0
	sw	$t0	,	0($sp)
	sw	$t1	,	-4($sp)
	sw	$t2	,	-8($sp)
	sw	$t3	,	-12($sp)
	sw	$t4	,	-16($sp)
	sw	$t5	,	-20($sp)
	sw	$t6	,	-24($sp)
	sw	$s0	,	-28($sp)
	sw	$s1	,	-32($sp)
	sw	$s2	,	-36($sp)
	sw	$s3	,	-40($sp)
	sw	$s4	,	-44($sp)
	sw	$s5	,	-48($sp)
	sw	$s6	,	-52($sp)
	sw	$fp	,	-56($sp)
	sw	$ra	,	-60($sp)
	add	$fp	,	$sp	,	$zero
	addi	$sp	,	$sp	,	-64
	li	$v0	,	97
returna$end:
	lw	$ra	,	4($sp)
	lw	$fp	,	8($sp)
	lw	$s6	,	12($sp)
	lw	$s5	,	16($sp)
	lw	$s4	,	20($sp)
	lw	$s3	,	24($sp)
	lw	$s2	,	28($sp)
	lw	$s1	,	32($sp)
	lw	$s0	,	36($sp)
	lw	$t6	,	40($sp)
	lw	$t5	,	44($sp)
	lw	$t4	,	48($sp)
	lw	$t3	,	52($sp)
	lw	$t2	,	56($sp)
	lw	$t1	,	60($sp)
	lw	$t0	,	64($sp)
	addi	$sp	,	$sp	,	64
	jr	$ra
	nop
returnplus:
	addi	$sp	,	$sp	,	0
	sw	$t0	,	0($sp)
	sw	$t1	,	-4($sp)
	sw	$t2	,	-8($sp)
	sw	$t3	,	-12($sp)
	sw	$t4	,	-16($sp)
	sw	$t5	,	-20($sp)
	sw	$t6	,	-24($sp)
	sw	$s0	,	-28($sp)
	sw	$s1	,	-32($sp)
	sw	$s2	,	-36($sp)
	sw	$s3	,	-40($sp)
	sw	$s4	,	-44($sp)
	sw	$s5	,	-48($sp)
	sw	$s6	,	-52($sp)
	sw	$fp	,	-56($sp)
	sw	$ra	,	-60($sp)
	add	$fp	,	$sp	,	$zero
	addi	$sp	,	$sp	,	-64
	li	$v0	,	43
returnplus$end:
	lw	$ra	,	4($sp)
	lw	$fp	,	8($sp)
	lw	$s6	,	12($sp)
	lw	$s5	,	16($sp)
	lw	$s4	,	20($sp)
	lw	$s3	,	24($sp)
	lw	$s2	,	28($sp)
	lw	$s1	,	32($sp)
	lw	$s0	,	36($sp)
	lw	$t6	,	40($sp)
	lw	$t5	,	44($sp)
	lw	$t4	,	48($sp)
	lw	$t3	,	52($sp)
	lw	$t2	,	56($sp)
	lw	$t1	,	60($sp)
	lw	$t0	,	64($sp)
	addi	$sp	,	$sp	,	64
	jr	$ra
	nop
returnstar:
	addi	$sp	,	$sp	,	0
	sw	$t0	,	0($sp)
	sw	$t1	,	-4($sp)
	sw	$t2	,	-8($sp)
	sw	$t3	,	-12($sp)
	sw	$t4	,	-16($sp)
	sw	$t5	,	-20($sp)
	sw	$t6	,	-24($sp)
	sw	$s0	,	-28($sp)
	sw	$s1	,	-32($sp)
	sw	$s2	,	-36($sp)
	sw	$s3	,	-40($sp)
	sw	$s4	,	-44($sp)
	sw	$s5	,	-48($sp)
	sw	$s6	,	-52($sp)
	sw	$fp	,	-56($sp)
	sw	$ra	,	-60($sp)
	add	$fp	,	$sp	,	$zero
	addi	$sp	,	$sp	,	-64
	li	$v0	,	42
returnstar$end:
	lw	$ra	,	4($sp)
	lw	$fp	,	8($sp)
	lw	$s6	,	12($sp)
	lw	$s5	,	16($sp)
	lw	$s4	,	20($sp)
	lw	$s3	,	24($sp)
	lw	$s2	,	28($sp)
	lw	$s1	,	32($sp)
	lw	$s0	,	36($sp)
	lw	$t6	,	40($sp)
	lw	$t5	,	44($sp)
	lw	$t4	,	48($sp)
	lw	$t3	,	52($sp)
	lw	$t2	,	56($sp)
	lw	$t1	,	60($sp)
	lw	$t0	,	64($sp)
	addi	$sp	,	$sp	,	64
	jr	$ra
	nop
returnchar:
	addi	$sp	,	$sp	,	4
	sw	$t0	,	-8($sp)
	sw	$t1	,	-12($sp)
	sw	$t2	,	-16($sp)
	sw	$t3	,	-20($sp)
	sw	$t4	,	-24($sp)
	sw	$t5	,	-28($sp)
	sw	$t6	,	-32($sp)
	sw	$s0	,	-36($sp)
	sw	$s1	,	-40($sp)
	sw	$s2	,	-44($sp)
	sw	$s3	,	-48($sp)
	sw	$s4	,	-52($sp)
	sw	$s5	,	-56($sp)
	sw	$s6	,	-60($sp)
	sw	$fp	,	-64($sp)
	sw	$ra	,	-68($sp)
	add	$fp	,	$sp	,	$zero
	addi	$sp	,	$sp	,	-72
	lw	$t1	,	0($fp)
	addi	$t0	,	$t1	,	0
	addi	$v0	,	$t0	,	0
returnchar$end:
	lw	$ra	,	4($sp)
	lw	$fp	,	8($sp)
	lw	$s6	,	12($sp)
	lw	$s5	,	16($sp)
	lw	$s4	,	20($sp)
	lw	$s3	,	24($sp)
	lw	$s2	,	28($sp)
	lw	$s1	,	32($sp)
	lw	$s0	,	36($sp)
	lw	$t6	,	40($sp)
	lw	$t5	,	44($sp)
	lw	$t4	,	48($sp)
	lw	$t3	,	52($sp)
	lw	$t2	,	56($sp)
	lw	$t1	,	60($sp)
	lw	$t0	,	64($sp)
	addi	$sp	,	$sp	,	72
	jr	$ra
	nop
main3:
	addi	$sp	,	$sp	,	0
	sw	$t0	,	-588($sp)
	sw	$t1	,	-592($sp)
	sw	$t2	,	-596($sp)
	sw	$t3	,	-600($sp)
	sw	$t4	,	-604($sp)
	sw	$t5	,	-608($sp)
	sw	$t6	,	-612($sp)
	sw	$s0	,	-616($sp)
	sw	$s1	,	-620($sp)
	sw	$s2	,	-624($sp)
	sw	$s3	,	-628($sp)
	sw	$s4	,	-632($sp)
	sw	$s5	,	-636($sp)
	sw	$s6	,	-640($sp)
	sw	$fp	,	-644($sp)
	sw	$ra	,	-648($sp)
	add	$fp	,	$sp	,	$zero
	addi	$sp	,	$sp	,	-652
	li	$s0	,	0
$label41:
	addi	$t0	,	$s0	,	0
	subi	$t7	,	$t0	,	45
	bgez	$t7	,	$label42
	nop
	addi	$t6	,	$s0	,	0
	li	$t5	,	97
	addi	$t7	,	$t6	,	35
	sll	$t7	,	$t7	,	2
	sw	$t5	,	268435856($t7)
	li	$t3	,	100
	addi	$t7	,	$t6	,	4038
	sll	$t7	,	$t7	,	2
	sw	$t3	,	268435856($t7)
	li	$t1	,	-1
	addi	$t7	,	$t6	,	2037
	sll	$t7	,	$t7	,	2
	sw	$t1	,	268435856($t7)
	sw	$t0	,	-4($fp)
	addi	$t0	,	$t6	,	1
	addi	$s0	,	$t0	,	0
	j	$label41
	nop
$label42:
	li	$s0	,	0
	li	$v0	,	4
	la	$a0	,	$Message10
	syscall
	li	$v0	,	11
	li	$t7	,	95
	add	$a0	,	$t7	,	$zero
	syscall
	li	$t7	,	65
	sw	$t7	,	268443996($zero)
	li	$v0	,	4
	la	$a0	,	$Message11
	syscall
	lw	$t9	,	268443996($zero)
	sw	$t0	,	-32($fp)
	addi	$t0	,	$t9	,	0
	li	$v0	,	11
	add	$a0	,	$t0	,	$zero
	syscall
	li	$v0	,	4
	la	$a0	,	$Message12
	syscall
	li	$v0	,	11
	li	$t7	,	43
	add	$a0	,	$t7	,	$zero
	syscall
	li	$v0	,	4
	la	$a0	,	$Message13
	syscall
	li	$t8	,	1
	addi	$t9	,	$t8	,	35
	sll	$t9	,	$t9	,	2
	sw	$t0	,	-36($fp)
	lw	$t0	,	268435856($t9)
	li	$v0	,	11
	add	$a0	,	$t0	,	$zero
	syscall
	li	$v0	,	4
	la	$a0	,	$Message14
	syscall
	li	$t8	,	5
	addi	$t9	,	$t8	,	35
	sll	$t9	,	$t9	,	2
	sw	$t0	,	-40($fp)
	lw	$t0	,	268435856($t9)
	sw	$t0	,	0($sp)
	addi	$sp	,	$sp	,	-4
	jal	returnchar
	nop
	sw	$t0	,	-44($fp)
	addi	$t0	,	$v0	,	0
	li	$v0	,	11
	add	$a0	,	$t0	,	$zero
	syscall
	li	$v0	,	4
	la	$a0	,	$Message15
	syscall
	jal	returna
	nop
	sw	$t0	,	-48($fp)
	addi	$t0	,	$v0	,	0
	li	$v0	,	11
	add	$a0	,	$t0	,	$zero
	syscall
	li	$v0	,	4
	la	$a0	,	$Message16
	syscall
	li	$v0	,	1
	li	$t7	,	34545
	add	$a0	,	$t7	,	$zero
	syscall
	li	$v0	,	4
	la	$a0	,	$Message17
	syscall
	li	$v0	,	1
	li	$t7	,	-400
	add	$a0	,	$t7	,	$zero
	syscall
	li	$v0	,	4
	la	$a0	,	$Message18
	syscall
	li	$v0	,	1
	li	$t7	,	-1563
	add	$a0	,	$t7	,	$zero
	syscall
	li	$v0	,	4
	la	$a0	,	$Message19
	syscall
	li	$v0	,	1
	li	$t7	,	1000
	add	$a0	,	$t7	,	$zero
	syscall
	li	$v0	,	4
	la	$a0	,	$Message20
	syscall
	li	$v0	,	1
	li	$t7	,	0
	add	$a0	,	$t7	,	$zero
	syscall
	li	$v0	,	4
	la	$a0	,	$Message21
	syscall
	li	$v0	,	1
	li	$t7	,	-888
	add	$a0	,	$t7	,	$zero
	syscall
	li	$v0	,	4
	la	$a0	,	$Message22
	syscall
	li	$v0	,	1
	li	$t7	,	456
	add	$a0	,	$t7	,	$zero
	syscall
	li	$v0	,	4
	la	$a0	,	$Message23
	syscall
	li	$t8	,	20
	addi	$t9	,	$t8	,	4038
	sll	$t9	,	$t9	,	2
	sw	$t0	,	-52($fp)
	lw	$t0	,	268435856($t9)
	li	$v0	,	1
	add	$a0	,	$t0	,	$zero
	syscall
	li	$v0	,	4
	la	$a0	,	$Message24
	syscall
	li	$t8	,	1
	addi	$t9	,	$t8	,	4038
	sll	$t9	,	$t9	,	2
	sw	$t0	,	-56($fp)
	lw	$t0	,	268435856($t9)
	li	$v0	,	1
	add	$a0	,	$t0	,	$zero
	syscall
	li	$v0	,	4
	la	$a0	,	$Message25
	syscall
	li	$t7	,	0
	sw	$t7	,	0($sp)
	addi	$sp	,	$sp	,	-4
	jal	fib
	nop
	sw	$t0	,	-60($fp)
	addi	$t0	,	$v0	,	0
	li	$v0	,	1
	add	$a0	,	$t0	,	$zero
	syscall
	li	$v0	,	4
	la	$a0	,	$Message26
	syscall
	li	$t7	,	1
	sw	$t7	,	0($sp)
	addi	$sp	,	$sp	,	-4
	jal	fib
	nop
	sw	$t0	,	-64($fp)
	addi	$t0	,	$v0	,	0
	li	$v0	,	1
	add	$a0	,	$t0	,	$zero
	syscall
	li	$v0	,	4
	la	$a0	,	$Message27
	syscall
	li	$t7	,	5
	sw	$t7	,	0($sp)
	addi	$sp	,	$sp	,	-4
	jal	fib
	nop
	sw	$t0	,	-68($fp)
	addi	$t0	,	$v0	,	0
	li	$v0	,	1
	add	$a0	,	$t0	,	$zero
	syscall
	li	$v0	,	4
	la	$a0	,	$Message28
	syscall
	li	$v0	,	1
	li	$t7	,	100
	add	$a0	,	$t7	,	$zero
	syscall
	li	$v0	,	4
	la	$a0	,	$Message29
	syscall
	li	$t8	,	20
	addi	$t9	,	$t8	,	4038
	sll	$t9	,	$t9	,	2
	sw	$t0	,	-72($fp)
	lw	$t0	,	268435856($t9)
	li	$v0	,	1
	add	$a0	,	$t0	,	$zero
	syscall
	li	$v0	,	4
	la	$a0	,	$Message30
	syscall
	li	$t7	,	5
	sw	$t7	,	0($sp)
	addi	$sp	,	$sp	,	-4
	jal	fib
	nop
	sw	$t0	,	-76($fp)
	addi	$t0	,	$v0	,	0
	li	$v0	,	1
	add	$a0	,	$t0	,	$zero
	syscall
	li	$v0	,	4
	la	$a0	,	$Message31
	syscall
	lw	$t9	,	268443996($zero)
	sw	$t0	,	-80($fp)
	addi	$t0	,	$t9	,	0
	li	$t9	,	95
	mul	$t0	,	$t9	,	$t0
	li	$v0	,	1
	add	$a0	,	$t0	,	$zero
	syscall
	li	$v0	,	4
	la	$a0	,	$Message32
	syscall
	li	$t8	,	1
	addi	$t9	,	$t8	,	35
	sll	$t9	,	$t9	,	2
	sw	$t0	,	-84($fp)
	lw	$t0	,	268435856($t9)
	li	$t9	,	43
	div	$t9	,	$t0
	mflo	$t0
	li	$v0	,	1
	add	$a0	,	$t0	,	$zero
	syscall
	li	$v0	,	4
	la	$a0	,	$Message33
	syscall
	li	$t8	,	1
	addi	$t9	,	$t8	,	35
	sll	$t9	,	$t9	,	2
	sw	$t0	,	-88($fp)
	lw	$t0	,	268435856($t9)
	li	$t8	,	-400
	div	$t0	,	$t8
	mflo	$t0
	li	$v0	,	1
	add	$a0	,	$t0	,	$zero
	syscall
	li	$v0	,	4
	la	$a0	,	$Message34
	syscall
	li	$t7	,	47
	sw	$t7	,	0($sp)
	addi	$sp	,	$sp	,	-4
	jal	returnchar
	nop
	sw	$t0	,	-92($fp)
	addi	$t0	,	$v0	,	0
	li	$t7	,	1
	sw	$t7	,	0($sp)
	addi	$sp	,	$sp	,	-4
	jal	fib
	nop
	mul	$t0	,	$t0	,	$v0
	li	$v0	,	1
	add	$a0	,	$t0	,	$zero
	syscall
	li	$v0	,	4
	la	$a0	,	$Message35
	syscall
	li	$v0	,	1
	li	$t7	,	355200
	add	$a0	,	$t7	,	$zero
	syscall
	li	$v0	,	4
	la	$a0	,	$Message36
	syscall
	li	$t7	,	5
	sw	$t7	,	0($sp)
	addi	$sp	,	$sp	,	-4
	jal	fib
	nop
	sw	$t0	,	-96($fp)
	addi	$t0	,	$v0	,	0
	li	$t9	,	1000
	div	$t9	,	$t0
	mflo	$t0
	li	$v0	,	1
	add	$a0	,	$t0	,	$zero
	syscall
	li	$v0	,	4
	la	$a0	,	$Message37
	syscall
	lw	$t9	,	268443996($zero)
	sw	$t0	,	-100($fp)
	addi	$t0	,	$t9	,	0
	li	$t9	,	95
	div	$t9	,	$t0
	mflo	$t0
	li	$t7	,	1
	sw	$t7	,	0($sp)
	addi	$sp	,	$sp	,	-4
	jal	fib
	nop
	mul	$t0	,	$t0	,	$v0
	li	$v0	,	1
	add	$a0	,	$t0	,	$zero
	syscall
	li	$v0	,	4
	la	$a0	,	$Message38
	syscall
	li	$t7	,	0
	sw	$t7	,	0($sp)
	addi	$sp	,	$sp	,	-4
	jal	fib
	nop
	sw	$t0	,	-104($fp)
	addi	$t0	,	$v0	,	0
	li	$t9	,	355200
	mul	$t0	,	$t9	,	$t0
	li	$v0	,	1
	add	$a0	,	$t0	,	$zero
	syscall
	li	$v0	,	4
	la	$a0	,	$Message39
	syscall
	lw	$t9	,	268443996($zero)
	sw	$t0	,	-108($fp)
	addi	$t0	,	$t9	,	0
	li	$t9	,	355200
	div	$t9	,	$t0
	mflo	$t0
	li	$v0	,	1
	add	$a0	,	$t0	,	$zero
	syscall
	li	$v0	,	4
	la	$a0	,	$Message40
	syscall
	li	$t8	,	5
	addi	$t9	,	$t8	,	35
	sll	$t9	,	$t9	,	2
	sw	$t0	,	-112($fp)
	lw	$t0	,	268435856($t9)
	sw	$t0	,	0($sp)
	addi	$sp	,	$sp	,	-4
	jal	returnchar
	nop
	sw	$t1	,	-28($fp)
	addi	$t1	,	$v0	,	0
	li	$t8	,	5
	addi	$t9	,	$t8	,	35
	sll	$t9	,	$t9	,	2
	sw	$t0	,	-116($fp)
	lw	$t0	,	268435856($t9)
	sw	$t0	,	0($sp)
	addi	$sp	,	$sp	,	-4
	jal	returnchar
	nop
	mul	$t1	,	$t1	,	$v0
	li	$t8	,	5
	addi	$t9	,	$t8	,	35
	sll	$t9	,	$t9	,	2
	sw	$t0	,	-124($fp)
	lw	$t0	,	268435856($t9)
	sw	$t0	,	0($sp)
	addi	$sp	,	$sp	,	-4
	jal	returnchar
	nop
	mul	$t1	,	$t1	,	$v0
	li	$v0	,	1
	add	$a0	,	$t1	,	$zero
	syscall
	li	$v0	,	4
	la	$a0	,	$Message41
	syscall
	lw	$t9	,	268443996($zero)
	sw	$t1	,	-120($fp)
	addi	$t1	,	$t9	,	0
	li	$t9	,	355200
	div	$t9	,	$t1
	mflo	$t1
	li	$t8	,	355200
	div	$t1	,	$t8
	mflo	$t1
	li	$t8	,	20
	addi	$t9	,	$t8	,	4038
	sll	$t9	,	$t9	,	2
	sw	$t0	,	-128($fp)
	lw	$t0	,	268435856($t9)
	mul	$t1	,	$t1	,	$t0
	li	$v0	,	1
	add	$a0	,	$t1	,	$zero
	syscall
	li	$v0	,	4
	la	$a0	,	$Message42
	syscall
	li	$t8	,	5
	addi	$t9	,	$t8	,	35
	sll	$t9	,	$t9	,	2
	sw	$t0	,	-136($fp)
	lw	$t0	,	268435856($t9)
	sw	$t0	,	0($sp)
	addi	$sp	,	$sp	,	-4
	jal	returnchar
	nop
	sw	$t1	,	-132($fp)
	addi	$t1	,	$v0	,	0
	li	$t8	,	5
	addi	$t9	,	$t8	,	35
	sll	$t9	,	$t9	,	2
	sw	$t0	,	-140($fp)
	lw	$t0	,	268435856($t9)
	sw	$t0	,	0($sp)
	addi	$sp	,	$sp	,	-4
	jal	returnchar
	nop
	mul	$t1	,	$t1	,	$v0
	li	$t8	,	5
	addi	$t9	,	$t8	,	35
	sll	$t9	,	$t9	,	2
	sw	$t0	,	-148($fp)
	lw	$t0	,	268435856($t9)
	sw	$t0	,	0($sp)
	addi	$sp	,	$sp	,	-4
	jal	returnchar
	nop
	mul	$t1	,	$t1	,	$v0
	li	$t9	,	95
	mul	$t1	,	$t9	,	$t1
	li	$v0	,	1
	add	$a0	,	$t1	,	$zero
	syscall
	li	$v0	,	4
	la	$a0	,	$Message43
	syscall
	li	$t7	,	6
	sw	$t7	,	0($sp)
	addi	$sp	,	$sp	,	-4
	jal	fib
	nop
	sw	$t0	,	-152($fp)
	addi	$t0	,	$v0	,	0
	sw	$t0	,	0($sp)
	addi	$sp	,	$sp	,	-4
	jal	fib
	nop
	sw	$t1	,	-144($fp)
	addi	$t1	,	$v0	,	0
	li	$t7	,	5
	sw	$t7	,	0($sp)
	addi	$sp	,	$sp	,	-4
	jal	fib
	nop
	sw	$t0	,	-156($fp)
	addi	$t0	,	$v0	,	0
	sub	$t1	,	$t1	,	$t0
	sw	$t1	,	0($sp)
	addi	$sp	,	$sp	,	-4
	jal	fib
	nop
	sw	$t0	,	-164($fp)
	addi	$t0	,	$v0	,	0
	li	$v0	,	1
	add	$a0	,	$t0	,	$zero
	syscall
	li	$v0	,	4
	la	$a0	,	$Message44
	syscall
	li	$t7	,	0
	sw	$t7	,	0($sp)
	addi	$sp	,	$sp	,	-4
	jal	fib
	nop
	sw	$t0	,	-168($fp)
	addi	$t0	,	$v0	,	0
	sw	$t0	,	0($sp)
	addi	$sp	,	$sp	,	-4
	jal	fib
	nop
	sw	$t0	,	-172($fp)
	addi	$t0	,	$v0	,	0
	sw	$t0	,	0($sp)
	addi	$sp	,	$sp	,	-4
	jal	fib
	nop
	sw	$t3	,	-20($fp)
	addi	$t3	,	$v0	,	0
	addi	$t9	,	$t3	,	4038
	sll	$t9	,	$t9	,	2
	lw	$t2	,	268435856($t9)
	li	$t8	,	0
	addi	$t9	,	$t8	,	4038
	sll	$t9	,	$t9	,	2
	sw	$t1	,	-160($fp)
	lw	$t1	,	268435856($t9)
	div	$t1	,	$t1
	mflo	$t1
	sw	$t1	,	0($sp)
	addi	$sp	,	$sp	,	-4
	jal	fib
	nop
	sw	$t0	,	-176($fp)
	addi	$t0	,	$v0	,	0
	sw	$t0	,	0($sp)
	addi	$sp	,	$sp	,	-4
	jal	fib
	nop
	sw	$t1	,	-188($fp)
	addi	$t1	,	$v0	,	0
	addi	$t9	,	$t1	,	4038
	sll	$t9	,	$t9	,	2
	sw	$t0	,	-196($fp)
	lw	$t0	,	268435856($t9)
	sub	$t2	,	$t2	,	$t0
	sw	$t2	,	0($sp)
	addi	$sp	,	$sp	,	-4
	jal	fib
	nop
	sw	$t1	,	-200($fp)
	addi	$t1	,	$v0	,	0
	addi	$t9	,	$t1	,	4038
	sll	$t9	,	$t9	,	2
	sw	$t0	,	-204($fp)
	lw	$t0	,	268435856($t9)
	li	$v0	,	1
	add	$a0	,	$t0	,	$zero
	syscall
	li	$v0	,	4
	la	$a0	,	$Message45
	syscall
	li	$v0	,	1
	li	$t7	,	-888
	add	$a0	,	$t7	,	$zero
	syscall
	li	$v0	,	4
	la	$a0	,	$Message46
	syscall
	jal	returna
	nop
	sw	$t0	,	-212($fp)
	addi	$t0	,	$v0	,	0
	sub	$t0	,	$zero	,	$t0
	li	$v0	,	1
	add	$a0	,	$t0	,	$zero
	syscall
	li	$v0	,	4
	la	$a0	,	$Message47
	syscall
	li	$t7	,	0
	sw	$t7	,	0($sp)
	addi	$sp	,	$sp	,	-4
	jal	fib
	nop
	sw	$t0	,	-216($fp)
	addi	$t0	,	$v0	,	0
	sw	$t0	,	0($sp)
	addi	$sp	,	$sp	,	-4
	jal	fib
	nop
	sw	$t0	,	-220($fp)
	addi	$t0	,	$v0	,	0
	sw	$t0	,	0($sp)
	addi	$sp	,	$sp	,	-4
	jal	fib
	nop
	sw	$t3	,	-180($fp)
	addi	$t3	,	$v0	,	0
	addi	$t9	,	$t3	,	4038
	sll	$t9	,	$t9	,	2
	sw	$t2	,	-184($fp)
	lw	$t2	,	268435856($t9)
	li	$t8	,	0
	addi	$t9	,	$t8	,	4038
	sll	$t9	,	$t9	,	2
	sw	$t1	,	-208($fp)
	lw	$t1	,	268435856($t9)
	div	$t1	,	$t1
	mflo	$t1
	sw	$t1	,	0($sp)
	addi	$sp	,	$sp	,	-4
	jal	fib
	nop
	sw	$t0	,	-224($fp)
	addi	$t0	,	$v0	,	0
	sw	$t0	,	0($sp)
	addi	$sp	,	$sp	,	-4
	jal	fib
	nop
	sw	$t1	,	-236($fp)
	addi	$t1	,	$v0	,	0
	addi	$t9	,	$t1	,	4038
	sll	$t9	,	$t9	,	2
	sw	$t0	,	-244($fp)
	lw	$t0	,	268435856($t9)
	sub	$t2	,	$t2	,	$t0
	sw	$t2	,	0($sp)
	addi	$sp	,	$sp	,	-4
	jal	fib
	nop
	sw	$t3	,	-228($fp)
	addi	$t3	,	$v0	,	0
	addi	$t9	,	$t3	,	4038
	sll	$t9	,	$t9	,	2
	sw	$t2	,	-232($fp)
	lw	$t2	,	268435856($t9)
	sub	$t2	,	$zero	,	$t2
	lw	$t9	,	268443996($zero)
	sw	$t1	,	-248($fp)
	addi	$t1	,	$t9	,	0
	li	$t9	,	355200
	div	$t9	,	$t1
	mflo	$t1
	li	$t8	,	355200
	div	$t1	,	$t8
	mflo	$t1
	li	$t8	,	20
	addi	$t9	,	$t8	,	4038
	sll	$t9	,	$t9	,	2
	sw	$t0	,	-252($fp)
	lw	$t0	,	268435856($t9)
	mul	$t1	,	$t1	,	$t0
	add	$t2	,	$t2	,	$t1
	li	$v0	,	1
	add	$a0	,	$t2	,	$zero
	syscall
	li	$v0	,	4
	la	$a0	,	$Message48
	syscall
	li	$t7	,	0
	sw	$t7	,	0($sp)
	addi	$sp	,	$sp	,	-4
	jal	fib
	nop
	sw	$t0	,	-268($fp)
	addi	$t0	,	$v0	,	0
	sw	$t0	,	0($sp)
	addi	$sp	,	$sp	,	-4
	jal	fib
	nop
	sw	$t0	,	-272($fp)
	addi	$t0	,	$v0	,	0
	sw	$t0	,	0($sp)
	addi	$sp	,	$sp	,	-4
	jal	fib
	nop
	sw	$t3	,	-256($fp)
	addi	$t3	,	$v0	,	0
	addi	$t9	,	$t3	,	4038
	sll	$t9	,	$t9	,	2
	sw	$t2	,	-260($fp)
	lw	$t2	,	268435856($t9)
	li	$t8	,	0
	addi	$t9	,	$t8	,	4038
	sll	$t9	,	$t9	,	2
	sw	$t1	,	-264($fp)
	lw	$t1	,	268435856($t9)
	div	$t1	,	$t1
	mflo	$t1
	sw	$t1	,	0($sp)
	addi	$sp	,	$sp	,	-4
	jal	fib
	nop
	sw	$t0	,	-276($fp)
	addi	$t0	,	$v0	,	0
	sw	$t0	,	0($sp)
	addi	$sp	,	$sp	,	-4
	jal	fib
	nop
	sw	$t1	,	-288($fp)
	addi	$t1	,	$v0	,	0
	addi	$t9	,	$t1	,	4038
	sll	$t9	,	$t9	,	2
	sw	$t0	,	-296($fp)
	lw	$t0	,	268435856($t9)
	sub	$t2	,	$t2	,	$t0
	sw	$t2	,	0($sp)
	addi	$sp	,	$sp	,	-4
	jal	fib
	nop
	sw	$t1	,	-300($fp)
	addi	$t1	,	$v0	,	0
	addi	$t9	,	$t1	,	4038
	sll	$t9	,	$t9	,	2
	sw	$t2	,	-284($fp)
	lw	$t2	,	268435856($t9)
	li	$t8	,	5
	addi	$t9	,	$t8	,	35
	sll	$t9	,	$t9	,	2
	sw	$t0	,	-304($fp)
	lw	$t0	,	268435856($t9)
	sw	$t0	,	0($sp)
	addi	$sp	,	$sp	,	-4
	jal	returnchar
	nop
	sw	$t1	,	-308($fp)
	addi	$t1	,	$v0	,	0
	li	$t8	,	5
	addi	$t9	,	$t8	,	35
	sll	$t9	,	$t9	,	2
	sw	$t0	,	-316($fp)
	lw	$t0	,	268435856($t9)
	sw	$t0	,	0($sp)
	addi	$sp	,	$sp	,	-4
	jal	returnchar
	nop
	mul	$t1	,	$t1	,	$v0
	li	$t8	,	5
	addi	$t9	,	$t8	,	35
	sll	$t9	,	$t9	,	2
	sw	$t0	,	-324($fp)
	lw	$t0	,	268435856($t9)
	sw	$t0	,	0($sp)
	addi	$sp	,	$sp	,	-4
	jal	returnchar
	nop
	mul	$t1	,	$t1	,	$v0
	li	$t9	,	95
	mul	$t1	,	$t9	,	$t1
	sub	$t2	,	$t2	,	$t1
	li	$v0	,	1
	add	$a0	,	$t2	,	$zero
	syscall
	li	$v0	,	4
	la	$a0	,	$Message49
	syscall
	li	$t7	,	0
	sw	$t7	,	0($sp)
	addi	$sp	,	$sp	,	-4
	jal	fib
	nop
	sw	$t0	,	-328($fp)
	addi	$t0	,	$v0	,	0
	sw	$t0	,	0($sp)
	addi	$sp	,	$sp	,	-4
	jal	fib
	nop
	sw	$t0	,	-332($fp)
	addi	$t0	,	$v0	,	0
	sw	$t0	,	0($sp)
	addi	$sp	,	$sp	,	-4
	jal	fib
	nop
	sw	$t3	,	-280($fp)
	addi	$t3	,	$v0	,	0
	addi	$t9	,	$t3	,	4038
	sll	$t9	,	$t9	,	2
	sw	$t2	,	-312($fp)
	lw	$t2	,	268435856($t9)
	li	$t8	,	0
	addi	$t9	,	$t8	,	4038
	sll	$t9	,	$t9	,	2
	sw	$t1	,	-320($fp)
	lw	$t1	,	268435856($t9)
	div	$t1	,	$t1
	mflo	$t1
	sw	$t1	,	0($sp)
	addi	$sp	,	$sp	,	-4
	jal	fib
	nop
	sw	$t0	,	-336($fp)
	addi	$t0	,	$v0	,	0
	sw	$t0	,	0($sp)
	addi	$sp	,	$sp	,	-4
	jal	fib
	nop
	sw	$t1	,	-348($fp)
	addi	$t1	,	$v0	,	0
	addi	$t9	,	$t1	,	4038
	sll	$t9	,	$t9	,	2
	sw	$t0	,	-356($fp)
	lw	$t0	,	268435856($t9)
	sub	$t2	,	$t2	,	$t0
	sw	$t2	,	0($sp)
	addi	$sp	,	$sp	,	-4
	jal	fib
	nop
	sw	$t1	,	-360($fp)
	addi	$t1	,	$v0	,	0
	addi	$t9	,	$t1	,	4038
	sll	$t9	,	$t9	,	2
	sw	$t2	,	-344($fp)
	lw	$t2	,	268435856($t9)
	li	$t8	,	5
	addi	$t9	,	$t8	,	35
	sll	$t9	,	$t9	,	2
	sw	$t0	,	-364($fp)
	lw	$t0	,	268435856($t9)
	sw	$t0	,	0($sp)
	addi	$sp	,	$sp	,	-4
	jal	returnchar
	nop
	sw	$t1	,	-368($fp)
	addi	$t1	,	$v0	,	0
	li	$t8	,	5
	addi	$t9	,	$t8	,	35
	sll	$t9	,	$t9	,	2
	sw	$t0	,	-376($fp)
	lw	$t0	,	268435856($t9)
	sw	$t0	,	0($sp)
	addi	$sp	,	$sp	,	-4
	jal	returnchar
	nop
	mul	$t1	,	$t1	,	$v0
	li	$t8	,	5
	addi	$t9	,	$t8	,	35
	sll	$t9	,	$t9	,	2
	sw	$t0	,	-384($fp)
	lw	$t0	,	268435856($t9)
	sw	$t0	,	0($sp)
	addi	$sp	,	$sp	,	-4
	jal	returnchar
	nop
	mul	$t1	,	$t1	,	$v0
	li	$t9	,	95
	mul	$t1	,	$t9	,	$t1
	sub	$t2	,	$t2	,	$t1
	li	$t7	,	6
	sw	$t7	,	0($sp)
	addi	$sp	,	$sp	,	-4
	jal	fib
	nop
	sw	$t0	,	-388($fp)
	addi	$t0	,	$v0	,	0
	sw	$t0	,	0($sp)
	addi	$sp	,	$sp	,	-4
	jal	fib
	nop
	sw	$t1	,	-380($fp)
	addi	$t1	,	$v0	,	0
	li	$t7	,	5
	sw	$t7	,	0($sp)
	addi	$sp	,	$sp	,	-4
	jal	fib
	nop
	sw	$t0	,	-392($fp)
	addi	$t0	,	$v0	,	0
	sub	$t1	,	$t1	,	$t0
	sw	$t1	,	0($sp)
	addi	$sp	,	$sp	,	-4
	jal	fib
	nop
	sw	$t0	,	-400($fp)
	addi	$t0	,	$v0	,	0
	sub	$t0	,	$zero	,	$t0
	sub	$t2	,	$t2	,	$t0
	li	$t7	,	0
	sw	$t7	,	0($sp)
	addi	$sp	,	$sp	,	-4
	jal	fib
	nop
	sw	$t0	,	-404($fp)
	addi	$t0	,	$v0	,	0
	li	$t9	,	355200
	mul	$t0	,	$t9	,	$t0
	add	$t2	,	$t2	,	$t0
	li	$v0	,	1
	add	$a0	,	$t2	,	$zero
	syscall
	li	$v0	,	4
	la	$a0	,	$Message50
	syscall
	li	$t7	,	5
	sw	$t7	,	0($sp)
	addi	$sp	,	$sp	,	-4
	jal	fib
	nop
	addi	$t4	,	$v0	,	0
	li	$t9	,	1000
	div	$t9	,	$t4
	mflo	$t4
	subi	$t4	,	$t4	,	200
	li	$t7	,	0
	sw	$t7	,	0($sp)
	addi	$sp	,	$sp	,	-4
	jal	fib
	nop
	sw	$t0	,	-408($fp)
	addi	$t0	,	$v0	,	0
	sw	$t0	,	0($sp)
	addi	$sp	,	$sp	,	-4
	jal	fib
	nop
	sw	$t0	,	-416($fp)
	addi	$t0	,	$v0	,	0
	sw	$t0	,	0($sp)
	addi	$sp	,	$sp	,	-4
	jal	fib
	nop
	sw	$t3	,	-340($fp)
	addi	$t3	,	$v0	,	0
	addi	$t9	,	$t3	,	4038
	sll	$t9	,	$t9	,	2
	sw	$t2	,	-372($fp)
	lw	$t2	,	268435856($t9)
	li	$t8	,	0
	addi	$t9	,	$t8	,	4038
	sll	$t9	,	$t9	,	2
	sw	$t1	,	-396($fp)
	lw	$t1	,	268435856($t9)
	div	$t1	,	$t1
	mflo	$t1
	sw	$t1	,	0($sp)
	addi	$sp	,	$sp	,	-4
	jal	fib
	nop
	sw	$t0	,	-420($fp)
	addi	$t0	,	$v0	,	0
	sw	$t0	,	0($sp)
	addi	$sp	,	$sp	,	-4
	jal	fib
	nop
	sw	$t1	,	-432($fp)
	addi	$t1	,	$v0	,	0
	addi	$t9	,	$t1	,	4038
	sll	$t9	,	$t9	,	2
	sw	$t0	,	-440($fp)
	lw	$t0	,	268435856($t9)
	sub	$t2	,	$t2	,	$t0
	sw	$t2	,	0($sp)
	addi	$sp	,	$sp	,	-4
	jal	fib
	nop
	sw	$t1	,	-444($fp)
	addi	$t1	,	$v0	,	0
	addi	$t9	,	$t1	,	4038
	sll	$t9	,	$t9	,	2
	sw	$t3	,	-424($fp)
	lw	$t3	,	268435856($t9)
	li	$t8	,	5
	addi	$t9	,	$t8	,	35
	sll	$t9	,	$t9	,	2
	sw	$t0	,	-448($fp)
	lw	$t0	,	268435856($t9)
	sw	$t0	,	0($sp)
	addi	$sp	,	$sp	,	-4
	jal	returnchar
	nop
	sw	$t1	,	-452($fp)
	addi	$t1	,	$v0	,	0
	li	$t8	,	5
	addi	$t9	,	$t8	,	35
	sll	$t9	,	$t9	,	2
	sw	$t0	,	-460($fp)
	lw	$t0	,	268435856($t9)
	sw	$t0	,	0($sp)
	addi	$sp	,	$sp	,	-4
	jal	returnchar
	nop
	mul	$t1	,	$t1	,	$v0
	li	$t8	,	5
	addi	$t9	,	$t8	,	35
	sll	$t9	,	$t9	,	2
	sw	$t0	,	-468($fp)
	lw	$t0	,	268435856($t9)
	sw	$t0	,	0($sp)
	addi	$sp	,	$sp	,	-4
	jal	returnchar
	nop
	mul	$t1	,	$t1	,	$v0
	li	$t9	,	95
	mul	$t1	,	$t9	,	$t1
	sub	$t3	,	$t3	,	$t1
	li	$t7	,	5
	sw	$t7	,	0($sp)
	addi	$sp	,	$sp	,	-4
	jal	fib
	nop
	sw	$t0	,	-472($fp)
	addi	$t0	,	$v0	,	0
	addi	$t0	,	$t0	,	3
	sw	$t0	,	0($sp)
	addi	$sp	,	$sp	,	-4
	jal	fib
	nop
	sw	$t1	,	-464($fp)
	addi	$t1	,	$v0	,	0
	li	$t7	,	5
	sw	$t7	,	0($sp)
	addi	$sp	,	$sp	,	-4
	jal	fib
	nop
	sw	$t0	,	-476($fp)
	addi	$t0	,	$v0	,	0
	sub	$t1	,	$t1	,	$t0
	sw	$t1	,	0($sp)
	addi	$sp	,	$sp	,	-4
	jal	fib
	nop
	sw	$t0	,	-484($fp)
	addi	$t0	,	$v0	,	0
	sw	$t0	,	0($sp)
	addi	$sp	,	$sp	,	-4
	jal	fib
	nop
	sw	$t0	,	-488($fp)
	addi	$t0	,	$v0	,	0
	sub	$t0	,	$zero	,	$t0
	sub	$t3	,	$t3	,	$t0
	li	$t7	,	0
	sw	$t7	,	0($sp)
	addi	$sp	,	$sp	,	-4
	jal	fib
	nop
	sw	$t0	,	-492($fp)
	addi	$t0	,	$v0	,	0
	li	$t9	,	355200
	mul	$t0	,	$t9	,	$t0
	add	$t3	,	$t3	,	$t0
	li	$t7	,	0
	sw	$t7	,	0($sp)
	addi	$sp	,	$sp	,	-4
	jal	fib
	nop
	sw	$t0	,	-496($fp)
	addi	$t0	,	$v0	,	0
	sw	$t0	,	0($sp)
	addi	$sp	,	$sp	,	-4
	jal	fib
	nop
	sw	$t0	,	-500($fp)
	addi	$t0	,	$v0	,	0
	sw	$t0	,	0($sp)
	addi	$sp	,	$sp	,	-4
	jal	fib
	nop
	sw	$t5	,	-12($fp)
	addi	$t5	,	$v0	,	0
	addi	$t9	,	$t5	,	4038
	sll	$t9	,	$t9	,	2
	sw	$t2	,	-428($fp)
	lw	$t2	,	268435856($t9)
	li	$t8	,	0
	addi	$t9	,	$t8	,	4038
	sll	$t9	,	$t9	,	2
	sw	$t1	,	-480($fp)
	lw	$t1	,	268435856($t9)
	div	$t1	,	$t1
	mflo	$t1
	sw	$t1	,	0($sp)
	addi	$sp	,	$sp	,	-4
	jal	fib
	nop
	sw	$t0	,	-504($fp)
	addi	$t0	,	$v0	,	0
	sw	$t0	,	0($sp)
	addi	$sp	,	$sp	,	-4
	jal	fib
	nop
	sw	$t1	,	-516($fp)
	addi	$t1	,	$v0	,	0
	addi	$t9	,	$t1	,	4038
	sll	$t9	,	$t9	,	2
	sw	$t0	,	-524($fp)
	lw	$t0	,	268435856($t9)
	sub	$t2	,	$t2	,	$t0
	sw	$t2	,	0($sp)
	addi	$sp	,	$sp	,	-4
	jal	fib
	nop
	sw	$t1	,	-528($fp)
	addi	$t1	,	$v0	,	0
	addi	$t9	,	$t1	,	4038
	sll	$t9	,	$t9	,	2
	sw	$t2	,	-512($fp)
	lw	$t2	,	268435856($t9)
	li	$t8	,	5
	addi	$t9	,	$t8	,	35
	sll	$t9	,	$t9	,	2
	sw	$t0	,	-532($fp)
	lw	$t0	,	268435856($t9)
	sw	$t0	,	0($sp)
	addi	$sp	,	$sp	,	-4
	jal	returnchar
	nop
	sw	$t1	,	-536($fp)
	addi	$t1	,	$v0	,	0
	li	$t8	,	5
	addi	$t9	,	$t8	,	35
	sll	$t9	,	$t9	,	2
	sw	$t0	,	-544($fp)
	lw	$t0	,	268435856($t9)
	sw	$t0	,	0($sp)
	addi	$sp	,	$sp	,	-4
	jal	returnchar
	nop
	mul	$t1	,	$t1	,	$v0
	li	$t8	,	5
	addi	$t9	,	$t8	,	35
	sll	$t9	,	$t9	,	2
	sw	$t0	,	-552($fp)
	lw	$t0	,	268435856($t9)
	sw	$t0	,	0($sp)
	addi	$sp	,	$sp	,	-4
	jal	returnchar
	nop
	mul	$t1	,	$t1	,	$v0
	li	$t9	,	95
	mul	$t1	,	$t9	,	$t1
	sub	$t2	,	$t2	,	$t1
	sub	$t2	,	$zero	,	$t2
	li	$t7	,	5
	sw	$t7	,	0($sp)
	addi	$sp	,	$sp	,	-4
	jal	fib
	nop
	sw	$t0	,	-556($fp)
	addi	$t0	,	$v0	,	0
	addi	$t0	,	$t0	,	3
	sw	$t0	,	0($sp)
	addi	$sp	,	$sp	,	-4
	jal	fib
	nop
	sw	$t1	,	-548($fp)
	addi	$t1	,	$v0	,	0
	li	$t7	,	5
	sw	$t7	,	0($sp)
	addi	$sp	,	$sp	,	-4
	jal	fib
	nop
	sw	$t0	,	-560($fp)
	addi	$t0	,	$v0	,	0
	sub	$t1	,	$t1	,	$t0
	sw	$t1	,	0($sp)
	addi	$sp	,	$sp	,	-4
	jal	fib
	nop
	sw	$t0	,	-568($fp)
	addi	$t0	,	$v0	,	0
	sw	$t0	,	0($sp)
	addi	$sp	,	$sp	,	-4
	jal	fib
	nop
	sw	$t0	,	-572($fp)
	addi	$t0	,	$v0	,	0
	sub	$t0	,	$zero	,	$t0
	sub	$t2	,	$t2	,	$t0
	li	$t7	,	0
	sw	$t7	,	0($sp)
	addi	$sp	,	$sp	,	-4
	jal	fib
	nop
	sw	$t0	,	-576($fp)
	addi	$t0	,	$v0	,	0
	li	$t9	,	355200
	mul	$t0	,	$t9	,	$t0
	add	$t2	,	$t2	,	$t0
	div	$t3	,	$t2
	mflo	$t3
	add	$t4	,	$t4	,	$t3
	sw	$t4	,	0($sp)
	addi	$sp	,	$sp	,	-4
	jal	fib
	nop
	sw	$t0	,	-580($fp)
	addi	$t0	,	$v0	,	0
	li	$v0	,	1
	add	$a0	,	$t0	,	$zero
	syscall
main3$end:
	lw	$ra	,	4($sp)
	lw	$fp	,	8($sp)
	lw	$s6	,	12($sp)
	lw	$s5	,	16($sp)
	lw	$s4	,	20($sp)
	lw	$s3	,	24($sp)
	lw	$s2	,	28($sp)
	lw	$s1	,	32($sp)
	lw	$s0	,	36($sp)
	lw	$t6	,	40($sp)
	lw	$t5	,	44($sp)
	lw	$t4	,	48($sp)
	lw	$t3	,	52($sp)
	lw	$t2	,	56($sp)
	lw	$t1	,	60($sp)
	lw	$t0	,	64($sp)
	addi	$sp	,	$sp	,	652
	jr	$ra
	nop
main:
	addi	$sp	,	$sp	,	0
	sw	$t0	,	-24($sp)
	sw	$t1	,	-28($sp)
	sw	$t2	,	-32($sp)
	sw	$t3	,	-36($sp)
	sw	$t4	,	-40($sp)
	sw	$t5	,	-44($sp)
	sw	$t6	,	-48($sp)
	sw	$s0	,	-52($sp)
	sw	$s1	,	-56($sp)
	sw	$s2	,	-60($sp)
	sw	$s3	,	-64($sp)
	sw	$s4	,	-68($sp)
	sw	$s5	,	-72($sp)
	sw	$s6	,	-76($sp)
	sw	$fp	,	-80($sp)
	sw	$ra	,	-84($sp)
	add	$fp	,	$sp	,	$zero
	addi	$sp	,	$sp	,	-88
	li	$v0	,	4
	la	$a0	,	$Message51
	syscall
	li	$v0	,	12
	syscall
	add	$t2	,	$v0	,	$zero
	addi	$t1	,	$t2	,	0
	li	$t0	,	97
	sub	$t7	,	$t0	,	$t1
	bne	$t7	,	$zero	,	$label44
	nop
	jal	main1
	nop
	j	$label43
	nop
$label44:
	sw	$t0	,	-8($fp)
	li	$t0	,	98
	sub	$t7	,	$t0	,	$t1
	bne	$t7	,	$zero	,	$label45
	nop
	jal	main2
	nop
	j	$label43
	nop
$label45:
	sw	$t0	,	-12($fp)
	li	$t0	,	99
	sub	$t7	,	$t0	,	$t1
	bne	$t7	,	$zero	,	$label46
	nop
	jal	main3
	nop
	j	$label43
	nop
$label46:
	sw	$t0	,	-16($fp)
	li	$t0	,	100
	sub	$t7	,	$t0	,	$t1
	bne	$t7	,	$zero	,	$label47
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
