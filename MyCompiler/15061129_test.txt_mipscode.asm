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
fib:
	addi	$sp	,	$sp	,	4
	sw	$fp	,	-216($sp)
	sw	$ra	,	-220($sp)
	add	$fp	,	$sp	,	$zero
	addi	$sp	,	$sp	,	-224
	lw	$t0	,	0($fp)
	li	$t1	,	0
	add	$t0	,	$t0	,	$t1
	sw	$t0	,	268456416($zero)
	li	$t0	,	0
	lw	$t1	,	268456416($zero)
	sub	$t0	,	$t0	,	$t1
	sw	$t0	,	268456416($zero)
	lw	$t0	,	268456416($zero)
	li	$t1	,	-1
	sub	$t0	,	$t0	,	$t1
	bgez	$t0	,	$label0
	nop
	lw	$t0	,	0($fp)
	li	$t1	,	0
	add	$t0	,	$t0	,	$t1
	sw	$t0	,	268456420($zero)
	lw	$t0	,	268456420($zero)
	li	$t1	,	1
	sub	$t0	,	$t0	,	$t1
	sw	$t0	,	268456420($zero)
	lw	$t0	,	268456420($zero)
	addi	$t0	,	$t0	,	2037
	sll	$t0	,	$t0	,	2
	lw	$t0	,	268435856($t0)
	sw	$t0	,	268456424($zero)
	lw	$t0	,	268456424($zero)
	li	$t1	,	-1
	sub	$t0	,	$t0	,	$t1
	bgtz	$t0	,	$label2
	nop
	lw	$t0	,	0($fp)
	li	$t1	,	0
	add	$t0	,	$t0	,	$t1
	sw	$t0	,	268456428($zero)
	lw	$t0	,	268456428($zero)
	li	$t1	,	1
	sub	$t0	,	$t0	,	$t1
	sw	$t0	,	268456428($zero)
	lw	$t0	,	268456428($zero)
	sw	$t0	,	0($sp)
	addi	$sp	,	$sp	,	-4
	jal	fib
	nop
	add	$t0	,	$v0	,	$zero
	li	$t1	,	0
	add	$t0	,	$t0	,	$t1
	sw	$t0	,	268456432($zero)
	lw	$t0	,	268456432($zero)
	li	$t1	,	0
	add	$t0	,	$t0	,	$t1
	sw	$t0	,	-8($fp)
	j	$label3
	nop
$label2:
	lw	$t0	,	0($fp)
	li	$t1	,	0
	add	$t0	,	$t0	,	$t1
	sw	$t0	,	268456436($zero)
	lw	$t0	,	268456436($zero)
	li	$t1	,	1
	sub	$t0	,	$t0	,	$t1
	sw	$t0	,	268456436($zero)
	lw	$t0	,	268456436($zero)
	addi	$t0	,	$t0	,	2037
	sll	$t0	,	$t0	,	2
	lw	$t0	,	268435856($t0)
	sw	$t0	,	268456440($zero)
	lw	$t0	,	268456440($zero)
	li	$t1	,	0
	add	$t0	,	$t0	,	$t1
	sw	$t0	,	-8($fp)
$label3:
	lw	$t0	,	0($fp)
	li	$t1	,	0
	add	$t0	,	$t0	,	$t1
	sw	$t0	,	268456444($zero)
	lw	$t0	,	268456444($zero)
	li	$t1	,	2
	sub	$t0	,	$t0	,	$t1
	sw	$t0	,	268456444($zero)
	lw	$t0	,	268456444($zero)
	addi	$t0	,	$t0	,	2037
	sll	$t0	,	$t0	,	2
	lw	$t0	,	268435856($t0)
	sw	$t0	,	268456448($zero)
	lw	$t0	,	268456448($zero)
	li	$t1	,	0
	add	$t0	,	$t0	,	$t1
	sw	$t0	,	-12($fp)
	lw	$t0	,	-8($fp)
	li	$t1	,	0
	add	$t0	,	$t0	,	$t1
	sw	$t0	,	268456452($zero)
	lw	$t0	,	-12($fp)
	li	$t1	,	0
	add	$t0	,	$t0	,	$t1
	sw	$t0	,	268456456($zero)
	lw	$t0	,	268456452($zero)
	lw	$t1	,	268456456($zero)
	add	$t0	,	$t0	,	$t1
	sw	$t0	,	268456452($zero)
	lw	$t0	,	268456452($zero)
	li	$t1	,	0
	add	$t0	,	$t0	,	$t1
	sw	$t0	,	-4($fp)
	lw	$t0	,	0($fp)
	li	$t1	,	0
	add	$t0	,	$t0	,	$t1
	sw	$t0	,	268456460($zero)
	lw	$t0	,	-4($fp)
	li	$t1	,	0
	add	$t0	,	$t0	,	$t1
	sw	$t0	,	268456464($zero)
	lw	$t1	,	268456460($zero)
	addi	$t1	,	$t1	,	2037
	sll	$t0	,	$t1	,	2
	lw	$t1	,	268456464($zero)
	sw	$t1	,	268435856($t0)
	lw	$t0	,	-4($fp)
	li	$t1	,	0
	add	$t0	,	$t0	,	$t1
	sw	$t0	,	268456468($zero)
	lw	$t0	,	268456468($zero)
	li	$t1	,	0
	add	$t0	,	$t0	,	$t1
	add	$v0	,	$t0	,	$zero
	j	fib$end
	nop
	j	$label1
	nop
$label0:
	lw	$t0	,	0($fp)
	li	$t1	,	0
	add	$t0	,	$t0	,	$t1
	sw	$t0	,	268456472($zero)
	lw	$t0	,	0($fp)
	li	$t1	,	0
	add	$t0	,	$t0	,	$t1
	sw	$t0	,	268456476($zero)
	lw	$t0	,	268456476($zero)
	li	$t1	,	1
	add	$t0	,	$t0	,	$t1
	sw	$t0	,	268456476($zero)
	lw	$t0	,	268456472($zero)
	lw	$t1	,	268456476($zero)
	mul	$t0	,	$t0	,	$t1
	sw	$t0	,	268456472($zero)
	lw	$t0	,	0($fp)
	li	$t1	,	0
	add	$t0	,	$t0	,	$t1
	sw	$t0	,	268456480($zero)
	lw	$t0	,	268456480($zero)
	li	$t1	,	1
	add	$t0	,	$t0	,	$t1
	sw	$t0	,	268456480($zero)
	lw	$t0	,	268456472($zero)
	lw	$t1	,	268456480($zero)
	div	$t0	,	$t1
	mflo	$t0
	sw	$t0	,	268456472($zero)
	lw	$t0	,	268456472($zero)
	li	$t1	,	0
	sub	$t0	,	$t0	,	$t1
	beq	$t0	,	$zero	,	$label4
	nop
	li	$t0	,	1
	li	$t1	,	0
	add	$t0	,	$t0	,	$t1
	sw	$t0	,	268456484($zero)
	li	$t1	,	1
	addi	$t1	,	$t1	,	2037
	sll	$t0	,	$t1	,	2
	lw	$t1	,	268456484($zero)
	sw	$t1	,	268435856($t0)
	li	$t0	,	1
	li	$t1	,	0
	add	$t0	,	$t0	,	$t1
	sw	$t0	,	268456488($zero)
	li	$t1	,	1
	addi	$t1	,	$t1	,	4
	sll	$t0	,	$t1	,	2
	lw	$t1	,	268456488($zero)
	sub	$t0	,	$fp	,	$t0
	sw	$t1	,	0($t0)
	li	$t0	,	1
	addi	$t0	,	$t0	,	4
	sll	$t0	,	$t0	,	2
	sub	$t0	,	$fp	,	$t0
	lw	$t0	,	0($t0)
	sw	$t0	,	268456492($zero)
	lw	$t0	,	268456492($zero)
	addi	$t0	,	$t0	,	2037
	sll	$t0	,	$t0	,	2
	lw	$t0	,	268435856($t0)
	sw	$t0	,	268456496($zero)
	lw	$t0	,	268456496($zero)
	addi	$t0	,	$t0	,	4
	sll	$t0	,	$t0	,	2
	sub	$t0	,	$fp	,	$t0
	lw	$t0	,	0($t0)
	sw	$t0	,	268456500($zero)
	li	$t0	,	1
	addi	$t0	,	$t0	,	4
	sll	$t0	,	$t0	,	2
	sub	$t0	,	$fp	,	$t0
	lw	$t0	,	0($t0)
	sw	$t0	,	268456504($zero)
	lw	$t0	,	268456504($zero)
	addi	$t0	,	$t0	,	2037
	sll	$t0	,	$t0	,	2
	lw	$t0	,	268435856($t0)
	sw	$t0	,	268456508($zero)
	lw	$t0	,	268456500($zero)
	lw	$t1	,	268456508($zero)
	mul	$t0	,	$t0	,	$t1
	sw	$t0	,	268456500($zero)
	lw	$t0	,	268456500($zero)
	li	$t1	,	0
	add	$t0	,	$t0	,	$t1
	sw	$t0	,	268456500($zero)
	lw	$t0	,	268456500($zero)
	li	$t1	,	0
	add	$t0	,	$t0	,	$t1
	add	$v0	,	$t0	,	$zero
	j	fib$end
	nop
	j	$label5
	nop
$label4:
	li	$t0	,	0
	li	$t1	,	0
	add	$t0	,	$t0	,	$t1
	sw	$t0	,	268456512($zero)
	li	$t1	,	0
	addi	$t1	,	$t1	,	2037
	sll	$t0	,	$t1	,	2
	lw	$t1	,	268456512($zero)
	sw	$t1	,	268435856($t0)
	li	$t0	,	0
	li	$t1	,	0
	add	$t0	,	$t0	,	$t1
	sw	$t0	,	268456516($zero)
	li	$t1	,	0
	addi	$t1	,	$t1	,	4
	sll	$t0	,	$t1	,	2
	lw	$t1	,	268456516($zero)
	sub	$t0	,	$fp	,	$t0
	sw	$t1	,	0($t0)
	li	$t0	,	0
	addi	$t0	,	$t0	,	2037
	sll	$t0	,	$t0	,	2
	lw	$t0	,	268435856($t0)
	sw	$t0	,	268456520($zero)
	lw	$t0	,	268456520($zero)
	addi	$t0	,	$t0	,	4
	sll	$t0	,	$t0	,	2
	sub	$t0	,	$fp	,	$t0
	lw	$t0	,	0($t0)
	sw	$t0	,	268456524($zero)
	li	$t0	,	0
	addi	$t0	,	$t0	,	4
	sll	$t0	,	$t0	,	2
	sub	$t0	,	$fp	,	$t0
	lw	$t0	,	0($t0)
	sw	$t0	,	268456528($zero)
	lw	$t0	,	268456528($zero)
	addi	$t0	,	$t0	,	2037
	sll	$t0	,	$t0	,	2
	lw	$t0	,	268435856($t0)
	sw	$t0	,	268456532($zero)
	lw	$t0	,	268456524($zero)
	lw	$t1	,	268456532($zero)
	mul	$t0	,	$t0	,	$t1
	sw	$t0	,	268456524($zero)
	lw	$t0	,	268456524($zero)
	li	$t1	,	0
	add	$t0	,	$t0	,	$t1
	sw	$t0	,	268456524($zero)
	lw	$t0	,	268456524($zero)
	li	$t1	,	0
	add	$t0	,	$t0	,	$t1
	add	$v0	,	$t0	,	$zero
	j	fib$end
	nop
$label5:
$label1:
fib$end:
	lw	$ra	,	4($sp)
	lw	$fp	,	8($sp)
	addi	$sp	,	$sp	,	224
	jr	$ra
	nop
main1:
	addi	$sp	,	$sp	,	0
	sw	$fp	,	-4($sp)
	sw	$ra	,	-8($sp)
	add	$fp	,	$sp	,	$zero
	addi	$sp	,	$sp	,	-12
	li	$t0	,	0
	li	$t1	,	0
	add	$t0	,	$t0	,	$t1
	sw	$t0	,	0($fp)
$label6:
	lw	$t0	,	0($fp)
	li	$t1	,	0
	add	$t0	,	$t0	,	$t1
	sw	$t0	,	268456536($zero)
	lw	$t0	,	268456536($zero)
	li	$t1	,	46
	sub	$t0	,	$t0	,	$t1
	bgez	$t0	,	$label7
	nop
	lw	$t0	,	0($fp)
	li	$t1	,	0
	add	$t0	,	$t0	,	$t1
	sw	$t0	,	268456540($zero)
	li	$t0	,	-1
	li	$t1	,	0
	add	$t0	,	$t0	,	$t1
	sw	$t0	,	268456544($zero)
	lw	$t1	,	268456540($zero)
	addi	$t1	,	$t1	,	3037
	sll	$t0	,	$t1	,	2
	lw	$t1	,	268456544($zero)
	sw	$t1	,	268435856($t0)
	lw	$t0	,	0($fp)
	li	$t1	,	0
	add	$t0	,	$t0	,	$t1
	sw	$t0	,	268456548($zero)
	li	$t0	,	-1
	li	$t1	,	0
	add	$t0	,	$t0	,	$t1
	sw	$t0	,	268456552($zero)
	lw	$t1	,	268456548($zero)
	addi	$t1	,	$t1	,	2037
	sll	$t0	,	$t1	,	2
	lw	$t1	,	268456552($zero)
	sw	$t1	,	268435856($t0)
	lw	$t0	,	0($fp)
	li	$t1	,	0
	add	$t0	,	$t0	,	$t1
	sw	$t0	,	268456556($zero)
	lw	$t0	,	268456556($zero)
	li	$t1	,	0
	add	$t0	,	$t0	,	$t1
	sw	$t0	,	268456556($zero)
	li	$t0	,	48
	li	$t1	,	0
	add	$t0	,	$t0	,	$t1
	sw	$t0	,	268456560($zero)
	lw	$t1	,	268456556($zero)
	addi	$t1	,	$t1	,	35
	sll	$t0	,	$t1	,	2
	lw	$t1	,	268456560($zero)
	sw	$t1	,	268435856($t0)
	lw	$t0	,	0($fp)
	li	$t1	,	0
	add	$t0	,	$t0	,	$t1
	sw	$t0	,	268456564($zero)
	li	$t0	,	48
	li	$t1	,	0
	add	$t0	,	$t0	,	$t1
	sw	$t0	,	268456568($zero)
	lw	$t1	,	268456564($zero)
	addi	$t1	,	$t1	,	1035
	sll	$t0	,	$t1	,	2
	lw	$t1	,	268456568($zero)
	sw	$t1	,	268435856($t0)
	lw	$t0	,	0($fp)
	li	$t1	,	0
	add	$t0	,	$t0	,	$t1
	sw	$t0	,	268456572($zero)
	lw	$t0	,	268456572($zero)
	li	$t1	,	1
	add	$t0	,	$t0	,	$t1
	sw	$t0	,	268456572($zero)
	lw	$t0	,	268456572($zero)
	li	$t1	,	0
	sub	$t0	,	$t0	,	$t1
	sw	$t0	,	268456572($zero)
	lw	$t0	,	268456572($zero)
	li	$t1	,	0
	add	$t0	,	$t0	,	$t1
	sw	$t0	,	0($fp)
	j	$label6
	nop
$label7:
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
	sw	$t0	,	268456576($zero)
	lw	$t0	,	268456576($zero)
	li	$t1	,	2
	sub	$t0	,	$t0	,	$t1
	bgez	$t0	,	$label8
	nop
	li	$v0	,	4
	la	$a0	,	$Message1
	syscall
	j	$label9
	nop
$label8:
	lw	$t0	,	268452004($zero)
	li	$t1	,	0
	add	$t0	,	$t0	,	$t1
	sw	$t0	,	268456580($zero)
	lw	$t0	,	268456580($zero)
	li	$t1	,	45
	sub	$t0	,	$t0	,	$t1
	blez	$t0	,	$label10
	nop
	li	$v0	,	4
	la	$a0	,	$Message2
	syscall
	j	$label11
	nop
$label10:
	lw	$t0	,	268452004($zero)
	li	$t1	,	0
	add	$t0	,	$t0	,	$t1
	sw	$t0	,	268456584($zero)
	li	$t0	,	0
	sw	$t0	,	0($sp)
	addi	$sp	,	$sp	,	-4
	jal	fib
	nop
	add	$t0	,	$v0	,	$zero
	li	$t1	,	0
	add	$t0	,	$t0	,	$t1
	sw	$t0	,	268456588($zero)
	lw	$t0	,	268456584($zero)
	lw	$t1	,	268456588($zero)
	add	$t0	,	$t0	,	$t1
	sw	$t0	,	268456584($zero)
	li	$t0	,	1
	sw	$t0	,	0($sp)
	addi	$sp	,	$sp	,	-4
	jal	fib
	nop
	add	$t0	,	$v0	,	$zero
	li	$t1	,	0
	add	$t0	,	$t0	,	$t1
	sw	$t0	,	268456592($zero)
	lw	$t0	,	268456584($zero)
	lw	$t1	,	268456592($zero)
	sub	$t0	,	$t0	,	$t1
	sw	$t0	,	268456584($zero)
	li	$t0	,	2
	sw	$t0	,	0($sp)
	addi	$sp	,	$sp	,	-4
	jal	fib
	nop
	add	$t0	,	$v0	,	$zero
	li	$t1	,	0
	add	$t0	,	$t0	,	$t1
	sw	$t0	,	268456596($zero)
	lw	$t0	,	268456584($zero)
	lw	$t1	,	268456596($zero)
	add	$t0	,	$t0	,	$t1
	sw	$t0	,	268456584($zero)
	lw	$t0	,	268456584($zero)
	sw	$t0	,	0($sp)
	addi	$sp	,	$sp	,	-4
	jal	fib
	nop
$label12:
	lw	$t0	,	268452004($zero)
	li	$t1	,	0
	add	$t0	,	$t0	,	$t1
	sw	$t0	,	268456600($zero)
	lw	$t0	,	268456600($zero)
	li	$t1	,	0
	sub	$t0	,	$t0	,	$t1
	bltz	$t0	,	$label13
	nop
	lw	$t0	,	268452004($zero)
	li	$t1	,	0
	add	$t0	,	$t0	,	$t1
	sw	$t0	,	268456604($zero)
	lw	$t0	,	268456604($zero)
	addi	$t0	,	$t0	,	2037
	sll	$t0	,	$t0	,	2
	lw	$t0	,	268435856($t0)
	sw	$t0	,	268456608($zero)
	li	$t0	,	0
	lw	$t1	,	268456608($zero)
	sub	$t0	,	$t0	,	$t1
	sw	$t0	,	268456608($zero)
	li	$t0	,	0
	lw	$t1	,	268456608($zero)
	sub	$t0	,	$t0	,	$t1
	sw	$t0	,	268456608($zero)
	li	$v0	,	1
	lw	$a0	,	268456608($zero)
	syscall
	lw	$t0	,	268452004($zero)
	li	$t1	,	0
	add	$t0	,	$t0	,	$t1
	sw	$t0	,	268456612($zero)
	lw	$t0	,	268456612($zero)
	addi	$t0	,	$t0	,	3037
	sll	$t0	,	$t0	,	2
	lw	$t0	,	268435856($t0)
	sw	$t0	,	268456616($zero)
	lw	$t0	,	268456616($zero)
	li	$t1	,	-1
	sub	$t0	,	$t0	,	$t1
	beq	$t0	,	$zero	,	$label14
	nop
	li	$v0	,	4
	la	$a0	,	$Message3
	syscall
	j	$label15
	nop
$label14:
$label15:
	li	$v0	,	4
	la	$a0	,	$Message4
	syscall
	lw	$t0	,	268452004($zero)
	li	$t1	,	0
	add	$t0	,	$t0	,	$t1
	sw	$t0	,	268456620($zero)
	lw	$t0	,	268456620($zero)
	li	$t1	,	1
	sub	$t0	,	$t0	,	$t1
	sw	$t0	,	268456620($zero)
	lw	$t0	,	268456620($zero)
	li	$t1	,	0
	add	$t0	,	$t0	,	$t1
	sw	$t0	,	268452004($zero)
	j	$label12
	nop
$label13:
$label11:
$label9:
main1$end:
	lw	$ra	,	4($sp)
	lw	$fp	,	8($sp)
	addi	$sp	,	$sp	,	12
	jr	$ra
	nop
printarray:
	addi	$sp	,	$sp	,	0
	sw	$fp	,	-4($sp)
	sw	$ra	,	-8($sp)
	add	$fp	,	$sp	,	$zero
	addi	$sp	,	$sp	,	-12
	li	$t0	,	1
	li	$t1	,	0
	add	$t0	,	$t0	,	$t1
	sw	$t0	,	0($fp)
	lw	$t0	,	268456412($zero)
	li	$t1	,	0
	add	$t0	,	$t0	,	$t1
	sw	$t0	,	268456624($zero)
	lw	$t0	,	268456624($zero)
	li	$t1	,	1
	sub	$t0	,	$t0	,	$t1
	bltz	$t0	,	$label16
	nop
	li	$t0	,	0
	addi	$t0	,	$t0	,	5038
	sll	$t0	,	$t0	,	2
	lw	$t0	,	268435856($t0)
	sw	$t0	,	268456628($zero)
	li	$v0	,	1
	lw	$a0	,	268456628($zero)
	syscall
	j	$label17
	nop
$label16:
	li	$t0	,	-1
	li	$t1	,	0
	add	$t0	,	$t0	,	$t1
	add	$v0	,	$t0	,	$zero
	j	printarray$end
	nop
$label17:
$label18:
	lw	$t0	,	0($fp)
	li	$t1	,	0
	add	$t0	,	$t0	,	$t1
	sw	$t0	,	268456632($zero)
	lw	$t0	,	268456412($zero)
	li	$t1	,	0
	add	$t0	,	$t0	,	$t1
	sw	$t0	,	268456636($zero)
	lw	$t0	,	268456632($zero)
	lw	$t1	,	268456636($zero)
	sub	$t0	,	$t0	,	$t1
	bgez	$t0	,	$label19
	nop
	li	$v0	,	4
	la	$a0	,	$Message5
	syscall
	lw	$t0	,	0($fp)
	li	$t1	,	0
	add	$t0	,	$t0	,	$t1
	sw	$t0	,	268456640($zero)
	lw	$t0	,	268456640($zero)
	addi	$t0	,	$t0	,	5038
	sll	$t0	,	$t0	,	2
	lw	$t0	,	268435856($t0)
	sw	$t0	,	268456644($zero)
	li	$v0	,	1
	lw	$a0	,	268456644($zero)
	syscall
	lw	$t0	,	0($fp)
	li	$t1	,	0
	add	$t0	,	$t0	,	$t1
	sw	$t0	,	268456648($zero)
	lw	$t0	,	268456648($zero)
	li	$t1	,	1
	add	$t0	,	$t0	,	$t1
	sw	$t0	,	268456648($zero)
	lw	$t0	,	268456648($zero)
	li	$t1	,	0
	add	$t0	,	$t0	,	$t1
	sw	$t0	,	0($fp)
	j	$label18
	nop
$label19:
	li	$t0	,	0
	li	$t1	,	0
	add	$t0	,	$t0	,	$t1
	add	$v0	,	$t0	,	$zero
	j	printarray$end
	nop
printarray$end:
	lw	$ra	,	4($sp)
	lw	$fp	,	8($sp)
	addi	$sp	,	$sp	,	12
	jr	$ra
	nop
quicksort:
	addi	$sp	,	$sp	,	8
	sw	$fp	,	-20($sp)
	sw	$ra	,	-24($sp)
	add	$fp	,	$sp	,	$zero
	addi	$sp	,	$sp	,	-28
	lw	$t0	,	0($fp)
	li	$t1	,	0
	add	$t0	,	$t0	,	$t1
	sw	$t0	,	268456652($zero)
	lw	$t0	,	-4($fp)
	li	$t1	,	0
	add	$t0	,	$t0	,	$t1
	sw	$t0	,	268456656($zero)
	lw	$t0	,	268456652($zero)
	lw	$t1	,	268456656($zero)
	sub	$t0	,	$t0	,	$t1
	bltz	$t0	,	$label20
	nop
	j	quicksort$end
	nop
	j	$label21
	nop
$label20:
$label21:
	lw	$t0	,	0($fp)
	li	$t1	,	0
	add	$t0	,	$t0	,	$t1
	sw	$t0	,	268456660($zero)
	lw	$t0	,	268456660($zero)
	li	$t1	,	1
	add	$t0	,	$t0	,	$t1
	sw	$t0	,	268456660($zero)
	lw	$t0	,	268456660($zero)
	li	$t1	,	0
	add	$t0	,	$t0	,	$t1
	sw	$t0	,	-8($fp)
	lw	$t0	,	0($fp)
	li	$t1	,	0
	add	$t0	,	$t0	,	$t1
	sw	$t0	,	268456664($zero)
	lw	$t0	,	268456664($zero)
	li	$t1	,	0
	add	$t0	,	$t0	,	$t1
	sw	$t0	,	-12($fp)
$label22:
	lw	$t0	,	-8($fp)
	li	$t1	,	0
	add	$t0	,	$t0	,	$t1
	sw	$t0	,	268456668($zero)
	lw	$t0	,	-4($fp)
	li	$t1	,	0
	add	$t0	,	$t0	,	$t1
	sw	$t0	,	268456672($zero)
	lw	$t0	,	268456668($zero)
	lw	$t1	,	268456672($zero)
	sub	$t0	,	$t0	,	$t1
	bgtz	$t0	,	$label23
	nop
	lw	$t0	,	-8($fp)
	li	$t1	,	0
	add	$t0	,	$t0	,	$t1
	sw	$t0	,	268456676($zero)
	lw	$t0	,	268456676($zero)
	addi	$t0	,	$t0	,	5038
	sll	$t0	,	$t0	,	2
	lw	$t0	,	268435856($t0)
	sw	$t0	,	268456680($zero)
	lw	$t0	,	-12($fp)
	li	$t1	,	0
	add	$t0	,	$t0	,	$t1
	sw	$t0	,	268456684($zero)
	lw	$t0	,	268456684($zero)
	addi	$t0	,	$t0	,	5038
	sll	$t0	,	$t0	,	2
	lw	$t0	,	268435856($t0)
	sw	$t0	,	268456688($zero)
	lw	$t0	,	268456680($zero)
	lw	$t1	,	268456688($zero)
	sub	$t0	,	$t0	,	$t1
	bgez	$t0	,	$label24
	nop
	lw	$t0	,	-8($fp)
	li	$t1	,	0
	add	$t0	,	$t0	,	$t1
	sw	$t0	,	268456692($zero)
	lw	$t0	,	268456692($zero)
	addi	$t0	,	$t0	,	5038
	sll	$t0	,	$t0	,	2
	lw	$t0	,	268435856($t0)
	sw	$t0	,	268456696($zero)
	lw	$t0	,	268456696($zero)
	li	$t1	,	0
	add	$t0	,	$t0	,	$t1
	sw	$t0	,	-16($fp)
	lw	$t0	,	-8($fp)
	li	$t1	,	0
	add	$t0	,	$t0	,	$t1
	sw	$t0	,	268456700($zero)
	lw	$t0	,	-12($fp)
	li	$t1	,	0
	add	$t0	,	$t0	,	$t1
	sw	$t0	,	268456704($zero)
	lw	$t0	,	268456704($zero)
	addi	$t0	,	$t0	,	5038
	sll	$t0	,	$t0	,	2
	lw	$t0	,	268435856($t0)
	sw	$t0	,	268456708($zero)
	lw	$t1	,	268456700($zero)
	addi	$t1	,	$t1	,	5038
	sll	$t0	,	$t1	,	2
	lw	$t1	,	268456708($zero)
	sw	$t1	,	268435856($t0)
	lw	$t0	,	-12($fp)
	li	$t1	,	0
	add	$t0	,	$t0	,	$t1
	sw	$t0	,	268456712($zero)
	lw	$t0	,	-16($fp)
	li	$t1	,	0
	add	$t0	,	$t0	,	$t1
	sw	$t0	,	268456716($zero)
	lw	$t1	,	268456712($zero)
	addi	$t1	,	$t1	,	5038
	sll	$t0	,	$t1	,	2
	lw	$t1	,	268456716($zero)
	sw	$t1	,	268435856($t0)
	lw	$t0	,	-8($fp)
	li	$t1	,	0
	add	$t0	,	$t0	,	$t1
	sw	$t0	,	268456720($zero)
	lw	$t0	,	268456720($zero)
	addi	$t0	,	$t0	,	5038
	sll	$t0	,	$t0	,	2
	lw	$t0	,	268435856($t0)
	sw	$t0	,	268456724($zero)
	lw	$t0	,	268456724($zero)
	li	$t1	,	0
	add	$t0	,	$t0	,	$t1
	sw	$t0	,	-16($fp)
	lw	$t0	,	-8($fp)
	li	$t1	,	0
	add	$t0	,	$t0	,	$t1
	sw	$t0	,	268456728($zero)
	lw	$t0	,	-12($fp)
	li	$t1	,	0
	add	$t0	,	$t0	,	$t1
	sw	$t0	,	268456732($zero)
	lw	$t0	,	268456732($zero)
	li	$t1	,	1
	add	$t0	,	$t0	,	$t1
	sw	$t0	,	268456732($zero)
	lw	$t0	,	268456732($zero)
	addi	$t0	,	$t0	,	5038
	sll	$t0	,	$t0	,	2
	lw	$t0	,	268435856($t0)
	sw	$t0	,	268456736($zero)
	lw	$t1	,	268456728($zero)
	addi	$t1	,	$t1	,	5038
	sll	$t0	,	$t1	,	2
	lw	$t1	,	268456736($zero)
	sw	$t1	,	268435856($t0)
	lw	$t0	,	-12($fp)
	li	$t1	,	0
	add	$t0	,	$t0	,	$t1
	sw	$t0	,	268456740($zero)
	lw	$t0	,	268456740($zero)
	li	$t1	,	1
	add	$t0	,	$t0	,	$t1
	sw	$t0	,	268456740($zero)
	lw	$t0	,	-16($fp)
	li	$t1	,	0
	add	$t0	,	$t0	,	$t1
	sw	$t0	,	268456744($zero)
	lw	$t1	,	268456740($zero)
	addi	$t1	,	$t1	,	5038
	sll	$t0	,	$t1	,	2
	lw	$t1	,	268456744($zero)
	sw	$t1	,	268435856($t0)
	lw	$t0	,	-12($fp)
	li	$t1	,	0
	add	$t0	,	$t0	,	$t1
	sw	$t0	,	268456748($zero)
	lw	$t0	,	268456748($zero)
	li	$t1	,	1
	add	$t0	,	$t0	,	$t1
	sw	$t0	,	268456748($zero)
	lw	$t0	,	268456748($zero)
	li	$t1	,	0
	add	$t0	,	$t0	,	$t1
	sw	$t0	,	-12($fp)
	lw	$t0	,	268456408($zero)
	li	$t1	,	0
	add	$t0	,	$t0	,	$t1
	sw	$t0	,	268456752($zero)
	lw	$t0	,	268456752($zero)
	li	$t1	,	1
	add	$t0	,	$t0	,	$t1
	sw	$t0	,	268456752($zero)
	lw	$t0	,	268456752($zero)
	li	$t1	,	0
	add	$t0	,	$t0	,	$t1
	sw	$t0	,	268456408($zero)
	j	$label25
	nop
$label24:
$label25:
	lw	$t0	,	-8($fp)
	li	$t1	,	0
	add	$t0	,	$t0	,	$t1
	sw	$t0	,	268456756($zero)
	lw	$t0	,	268456756($zero)
	li	$t1	,	1
	add	$t0	,	$t0	,	$t1
	sw	$t0	,	268456756($zero)
	lw	$t0	,	268456756($zero)
	li	$t1	,	0
	add	$t0	,	$t0	,	$t1
	sw	$t0	,	-8($fp)
	j	$label22
	nop
$label23:
	lw	$t0	,	0($fp)
	li	$t1	,	0
	add	$t0	,	$t0	,	$t1
	sw	$t0	,	268456760($zero)
	lw	$t0	,	268456760($zero)
	sw	$t0	,	0($sp)
	addi	$sp	,	$sp	,	-4
	lw	$t0	,	-12($fp)
	li	$t1	,	0
	add	$t0	,	$t0	,	$t1
	sw	$t0	,	268456764($zero)
	lw	$t0	,	268456764($zero)
	li	$t1	,	1
	sub	$t0	,	$t0	,	$t1
	sw	$t0	,	268456764($zero)
	lw	$t0	,	268456764($zero)
	sw	$t0	,	0($sp)
	addi	$sp	,	$sp	,	-4
	jal	quicksort
	nop
	lw	$t0	,	-12($fp)
	li	$t1	,	0
	add	$t0	,	$t0	,	$t1
	sw	$t0	,	268456768($zero)
	lw	$t0	,	268456768($zero)
	li	$t1	,	1
	add	$t0	,	$t0	,	$t1
	sw	$t0	,	268456768($zero)
	lw	$t0	,	268456768($zero)
	sw	$t0	,	0($sp)
	addi	$sp	,	$sp	,	-4
	lw	$t0	,	-4($fp)
	li	$t1	,	0
	add	$t0	,	$t0	,	$t1
	sw	$t0	,	268456772($zero)
	lw	$t0	,	268456772($zero)
	sw	$t0	,	0($sp)
	addi	$sp	,	$sp	,	-4
	jal	quicksort
	nop
	j	quicksort$end
	nop
quicksort$end:
	lw	$ra	,	4($sp)
	lw	$fp	,	8($sp)
	addi	$sp	,	$sp	,	28
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
	sw	$fp	,	-8($sp)
	sw	$ra	,	-12($sp)
	add	$fp	,	$sp	,	$zero
	addi	$sp	,	$sp	,	-16
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
	sw	$t0	,	268456776($zero)
	lw	$t0	,	268456776($zero)
	li	$t1	,	0
	sub	$t0	,	$t0	,	$t1
	beq	$t0	,	$zero	,	$label26
	nop
	lw	$t0	,	268456412($zero)
	li	$t1	,	0
	add	$t0	,	$t0	,	$t1
	sw	$t0	,	268456780($zero)
	lw	$t0	,	268456412($zero)
	li	$t1	,	0
	add	$t0	,	$t0	,	$t1
	sw	$t0	,	268456784($zero)
	lw	$t0	,	268456784($zero)
	lw	$t1	,	268456412($zero)
	mul	$t0	,	$t0	,	$t1
	sw	$t0	,	268456784($zero)
	lw	$t0	,	268456780($zero)
	lw	$t1	,	268456784($zero)
	add	$t0	,	$t0	,	$t1
	sw	$t0	,	268456780($zero)
	lw	$t0	,	268456780($zero)
	lw	$t1	,	268456412($zero)
	div	$t0	,	$t1
	mflo	$t0
	sw	$t0	,	268456780($zero)
	lw	$t0	,	268456780($zero)
	li	$t1	,	1
	sub	$t0	,	$t0	,	$t1
	sw	$t0	,	268456780($zero)
	lw	$t0	,	268456780($zero)
	li	$t1	,	0
	add	$t0	,	$t0	,	$t1
	sw	$t0	,	268456412($zero)
	j	$label27
	nop
$label26:
$label27:
	li	$v0	,	4
	la	$a0	,	$Message7
	syscall
$label28:
	lw	$t0	,	0($fp)
	li	$t1	,	0
	add	$t0	,	$t0	,	$t1
	sw	$t0	,	268456788($zero)
	lw	$t0	,	268456412($zero)
	li	$t1	,	0
	add	$t0	,	$t0	,	$t1
	sw	$t0	,	268456792($zero)
	lw	$t0	,	268456788($zero)
	lw	$t1	,	268456792($zero)
	sub	$t0	,	$t0	,	$t1
	bgez	$t0	,	$label29
	nop
	li	$v0	,	5
	syscall
	add	$t0	,	$v0	,	$zero
	sw	$t0	,	-4($fp)
	lw	$t0	,	0($fp)
	li	$t1	,	0
	add	$t0	,	$t0	,	$t1
	sw	$t0	,	268456796($zero)
	lw	$t0	,	-4($fp)
	li	$t1	,	0
	add	$t0	,	$t0	,	$t1
	sw	$t0	,	268456800($zero)
	lw	$t1	,	268456796($zero)
	addi	$t1	,	$t1	,	5038
	sll	$t0	,	$t1	,	2
	lw	$t1	,	268456800($zero)
	sw	$t1	,	268435856($t0)
	lw	$t0	,	0($fp)
	li	$t1	,	0
	add	$t0	,	$t0	,	$t1
	sw	$t0	,	268456804($zero)
	jal	return999
	nop
	add	$t0	,	$v0	,	$zero
	li	$t1	,	0
	add	$t0	,	$t0	,	$t1
	sw	$t0	,	268456808($zero)
	lw	$t0	,	268456804($zero)
	lw	$t1	,	268456808($zero)
	add	$t0	,	$t0	,	$t1
	sw	$t0	,	268456804($zero)
	jal	returnminus998
	nop
	add	$t0	,	$v0	,	$zero
	li	$t1	,	0
	add	$t0	,	$t0	,	$t1
	sw	$t0	,	268456812($zero)
	lw	$t0	,	268456804($zero)
	lw	$t1	,	268456812($zero)
	add	$t0	,	$t0	,	$t1
	sw	$t0	,	268456804($zero)
	lw	$t0	,	268456804($zero)
	li	$t1	,	0
	add	$t0	,	$t0	,	$t1
	sw	$t0	,	0($fp)
	j	$label28
	nop
$label29:
	lw	$t0	,	268456412($zero)
	li	$t1	,	0
	add	$t0	,	$t0	,	$t1
	sw	$t0	,	268456816($zero)
	li	$t0	,	0
	li	$t1	,	0
	add	$t0	,	$t0	,	$t1
	sw	$t0	,	268456820($zero)
	lw	$t0	,	268456820($zero)
	lw	$t1	,	268456816($zero)
	sub	$t0	,	$t0	,	$t1
	bne	$t0	,	$zero	,	$label31
	nop
	jal	printarray
	nop
	j	$label30
	nop
$label31:
	li	$t0	,	1
	li	$t1	,	0
	add	$t0	,	$t0	,	$t1
	sw	$t0	,	268456824($zero)
	lw	$t0	,	268456824($zero)
	lw	$t1	,	268456816($zero)
	sub	$t0	,	$t0	,	$t1
	bne	$t0	,	$zero	,	$label32
	nop
	jal	printarray
	nop
	j	$label30
	nop
$label32:
	lw	$t0	,	268456412($zero)
	li	$t1	,	0
	add	$t0	,	$t0	,	$t1
	sw	$t0	,	268456828($zero)
	lw	$t0	,	268456828($zero)
	li	$t1	,	0
	sub	$t0	,	$t0	,	$t1
	bgez	$t0	,	$label33
	nop
	li	$v0	,	4
	la	$a0	,	$Message8
	syscall
	j	main2$end
	nop
	j	$label34
	nop
$label33:
	jal	return999
	nop
	add	$t0	,	$v0	,	$zero
	li	$t1	,	0
	add	$t0	,	$t0	,	$t1
	sw	$t0	,	268456832($zero)
	lw	$t0	,	268456832($zero)
	li	$t1	,	999
	sub	$t0	,	$t0	,	$t1
	sw	$t0	,	268456832($zero)
	lw	$t0	,	268456832($zero)
	sw	$t0	,	0($sp)
	addi	$sp	,	$sp	,	-4
	lw	$t0	,	268456412($zero)
	li	$t1	,	0
	add	$t0	,	$t0	,	$t1
	sw	$t0	,	268456836($zero)
	jal	return999
	nop
	add	$t0	,	$v0	,	$zero
	li	$t1	,	0
	add	$t0	,	$t0	,	$t1
	sw	$t0	,	268456840($zero)
	jal	returnminus998
	nop
	add	$t0	,	$v0	,	$zero
	li	$t1	,	0
	add	$t0	,	$t0	,	$t1
	sw	$t0	,	268456844($zero)
	lw	$t0	,	268456840($zero)
	lw	$t1	,	268456844($zero)
	add	$t0	,	$t0	,	$t1
	sw	$t0	,	268456840($zero)
	lw	$t0	,	268456836($zero)
	lw	$t1	,	268456840($zero)
	sub	$t0	,	$t0	,	$t1
	sw	$t0	,	268456836($zero)
	lw	$t0	,	268456836($zero)
	sw	$t0	,	0($sp)
	addi	$sp	,	$sp	,	-4
	jal	quicksort
	nop
	jal	printarray
	nop
$label34:
$label30:
	li	$v0	,	4
	la	$a0	,	$Message9
	syscall
	lw	$t0	,	268456408($zero)
	li	$t1	,	0
	add	$t0	,	$t0	,	$t1
	sw	$t0	,	268456848($zero)
	li	$v0	,	1
	lw	$a0	,	268456848($zero)
	syscall
	j	main2$end
	nop
main2$end:
	lw	$ra	,	4($sp)
	lw	$fp	,	8($sp)
	addi	$sp	,	$sp	,	16
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
	sw	$fp	,	-4($sp)
	sw	$ra	,	-8($sp)
	add	$fp	,	$sp	,	$zero
	addi	$sp	,	$sp	,	-12
	lw	$t0	,	0($fp)
	li	$t1	,	0
	add	$t0	,	$t0	,	$t1
	sw	$t0	,	268456852($zero)
	lw	$t0	,	268456852($zero)
	li	$t1	,	0
	add	$t0	,	$t0	,	$t1
	add	$v0	,	$t0	,	$zero
	j	returnchar$end
	nop
returnchar$end:
	lw	$ra	,	4($sp)
	lw	$fp	,	8($sp)
	addi	$sp	,	$sp	,	12
	jr	$ra
	nop
main3:
	addi	$sp	,	$sp	,	0
	sw	$fp	,	-4($sp)
	sw	$ra	,	-8($sp)
	add	$fp	,	$sp	,	$zero
	addi	$sp	,	$sp	,	-12
	li	$t0	,	0
	li	$t1	,	0
	add	$t0	,	$t0	,	$t1
	sw	$t0	,	0($fp)
$label35:
	lw	$t0	,	0($fp)
	li	$t1	,	0
	add	$t0	,	$t0	,	$t1
	sw	$t0	,	268456856($zero)
	lw	$t0	,	268456856($zero)
	li	$t1	,	45
	sub	$t0	,	$t0	,	$t1
	bgez	$t0	,	$label36
	nop
	lw	$t0	,	0($fp)
	li	$t1	,	0
	add	$t0	,	$t0	,	$t1
	sw	$t0	,	268456860($zero)
	li	$t0	,	97
	li	$t1	,	0
	add	$t0	,	$t0	,	$t1
	sw	$t0	,	268456864($zero)
	lw	$t1	,	268456860($zero)
	addi	$t1	,	$t1	,	35
	sll	$t0	,	$t1	,	2
	lw	$t1	,	268456864($zero)
	sw	$t1	,	268435856($t0)
	lw	$t0	,	0($fp)
	li	$t1	,	0
	add	$t0	,	$t0	,	$t1
	sw	$t0	,	268456868($zero)
	li	$t0	,	100
	li	$t1	,	0
	add	$t0	,	$t0	,	$t1
	sw	$t0	,	268456872($zero)
	lw	$t1	,	268456868($zero)
	addi	$t1	,	$t1	,	4038
	sll	$t0	,	$t1	,	2
	lw	$t1	,	268456872($zero)
	sw	$t1	,	268435856($t0)
	lw	$t0	,	0($fp)
	li	$t1	,	0
	add	$t0	,	$t0	,	$t1
	sw	$t0	,	268456876($zero)
	li	$t0	,	-1
	li	$t1	,	0
	add	$t0	,	$t0	,	$t1
	sw	$t0	,	268456880($zero)
	lw	$t1	,	268456876($zero)
	addi	$t1	,	$t1	,	2037
	sll	$t0	,	$t1	,	2
	lw	$t1	,	268456880($zero)
	sw	$t1	,	268435856($t0)
	lw	$t0	,	0($fp)
	li	$t1	,	0
	add	$t0	,	$t0	,	$t1
	sw	$t0	,	268456884($zero)
	lw	$t0	,	268456884($zero)
	li	$t1	,	1
	add	$t0	,	$t0	,	$t1
	sw	$t0	,	268456884($zero)
	lw	$t0	,	268456884($zero)
	li	$t1	,	0
	add	$t0	,	$t0	,	$t1
	sw	$t0	,	0($fp)
	j	$label35
	nop
$label36:
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
	sw	$t0	,	268456888($zero)
	li	$v0	,	11
	lw	$a0	,	268456888($zero)
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
	sw	$t0	,	268456892($zero)
	li	$v0	,	11
	lw	$a0	,	268456892($zero)
	syscall
	li	$v0	,	4
	la	$a0	,	$Message14
	syscall
	li	$t0	,	5
	addi	$t0	,	$t0	,	35
	sll	$t0	,	$t0	,	2
	lw	$t0	,	268435856($t0)
	sw	$t0	,	268456896($zero)
	lw	$t0	,	268456896($zero)
	sw	$t0	,	0($sp)
	addi	$sp	,	$sp	,	-4
	jal	returnchar
	nop
	add	$t0	,	$v0	,	$zero
	li	$t1	,	0
	add	$t0	,	$t0	,	$t1
	sw	$t0	,	268456900($zero)
	li	$v0	,	11
	lw	$a0	,	268456900($zero)
	syscall
	li	$v0	,	4
	la	$a0	,	$Message15
	syscall
	jal	returna
	nop
	add	$t0	,	$v0	,	$zero
	li	$t1	,	0
	add	$t0	,	$t0	,	$t1
	sw	$t0	,	268456904($zero)
	li	$v0	,	11
	lw	$a0	,	268456904($zero)
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
	sw	$t0	,	268456908($zero)
	li	$v0	,	1
	lw	$a0	,	268456908($zero)
	syscall
	li	$v0	,	4
	la	$a0	,	$Message24
	syscall
	li	$t0	,	1
	addi	$t0	,	$t0	,	4038
	sll	$t0	,	$t0	,	2
	lw	$t0	,	268435856($t0)
	sw	$t0	,	268456912($zero)
	li	$v0	,	1
	lw	$a0	,	268456912($zero)
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
	sw	$t0	,	268456916($zero)
	li	$v0	,	1
	lw	$a0	,	268456916($zero)
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
	sw	$t0	,	268456920($zero)
	li	$v0	,	1
	lw	$a0	,	268456920($zero)
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
	sw	$t0	,	268456924($zero)
	li	$v0	,	1
	lw	$a0	,	268456924($zero)
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
	sw	$t0	,	268456928($zero)
	li	$v0	,	1
	lw	$a0	,	268456928($zero)
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
	sw	$t0	,	268456932($zero)
	li	$v0	,	1
	lw	$a0	,	268456932($zero)
	syscall
	li	$v0	,	4
	la	$a0	,	$Message31
	syscall
	lw	$t0	,	268443996($zero)
	li	$t1	,	0
	add	$t0	,	$t0	,	$t1
	sw	$t0	,	268456936($zero)
	li	$t0	,	95
	lw	$t1	,	268456936($zero)
	mul	$t0	,	$t0	,	$t1
	sw	$t0	,	268456936($zero)
	li	$v0	,	1
	lw	$a0	,	268456936($zero)
	syscall
	li	$v0	,	4
	la	$a0	,	$Message32
	syscall
	li	$t0	,	1
	addi	$t0	,	$t0	,	35
	sll	$t0	,	$t0	,	2
	lw	$t0	,	268435856($t0)
	sw	$t0	,	268456940($zero)
	li	$t0	,	43
	lw	$t1	,	268456940($zero)
	div	$t0	,	$t1
	mflo	$t0
	sw	$t0	,	268456940($zero)
	li	$v0	,	1
	lw	$a0	,	268456940($zero)
	syscall
	li	$v0	,	4
	la	$a0	,	$Message33
	syscall
	li	$t0	,	1
	addi	$t0	,	$t0	,	35
	sll	$t0	,	$t0	,	2
	lw	$t0	,	268435856($t0)
	sw	$t0	,	268456944($zero)
	lw	$t0	,	268456944($zero)
	li	$t1	,	-400
	div	$t0	,	$t1
	mflo	$t0
	sw	$t0	,	268456944($zero)
	li	$v0	,	1
	lw	$a0	,	268456944($zero)
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
	sw	$t0	,	268456948($zero)
	li	$t0	,	1
	sw	$t0	,	0($sp)
	addi	$sp	,	$sp	,	-4
	jal	fib
	nop
	lw	$t0	,	268456948($zero)
	add	$t1	,	$v0	,	$zero
	mul	$t0	,	$t0	,	$t1
	sw	$t0	,	268456948($zero)
	li	$v0	,	1
	lw	$a0	,	268456948($zero)
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
	sw	$t0	,	268456952($zero)
	li	$t0	,	1000
	lw	$t1	,	268456952($zero)
	div	$t0	,	$t1
	mflo	$t0
	sw	$t0	,	268456952($zero)
	li	$v0	,	1
	lw	$a0	,	268456952($zero)
	syscall
	li	$v0	,	4
	la	$a0	,	$Message37
	syscall
	lw	$t0	,	268443996($zero)
	li	$t1	,	0
	add	$t0	,	$t0	,	$t1
	sw	$t0	,	268456956($zero)
	li	$t0	,	95
	lw	$t1	,	268456956($zero)
	div	$t0	,	$t1
	mflo	$t0
	sw	$t0	,	268456956($zero)
	li	$t0	,	1
	sw	$t0	,	0($sp)
	addi	$sp	,	$sp	,	-4
	jal	fib
	nop
	lw	$t0	,	268456956($zero)
	add	$t1	,	$v0	,	$zero
	mul	$t0	,	$t0	,	$t1
	sw	$t0	,	268456956($zero)
	li	$v0	,	1
	lw	$a0	,	268456956($zero)
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
	sw	$t0	,	268456960($zero)
	li	$t0	,	355200
	lw	$t1	,	268456960($zero)
	mul	$t0	,	$t0	,	$t1
	sw	$t0	,	268456960($zero)
	li	$v0	,	1
	lw	$a0	,	268456960($zero)
	syscall
	li	$v0	,	4
	la	$a0	,	$Message39
	syscall
	lw	$t0	,	268443996($zero)
	li	$t1	,	0
	add	$t0	,	$t0	,	$t1
	sw	$t0	,	268456964($zero)
	li	$t0	,	355200
	lw	$t1	,	268456964($zero)
	div	$t0	,	$t1
	mflo	$t0
	sw	$t0	,	268456964($zero)
	li	$v0	,	1
	lw	$a0	,	268456964($zero)
	syscall
	li	$v0	,	4
	la	$a0	,	$Message40
	syscall
	li	$t0	,	5
	addi	$t0	,	$t0	,	35
	sll	$t0	,	$t0	,	2
	lw	$t0	,	268435856($t0)
	sw	$t0	,	268456968($zero)
	lw	$t0	,	268456968($zero)
	sw	$t0	,	0($sp)
	addi	$sp	,	$sp	,	-4
	jal	returnchar
	nop
	add	$t0	,	$v0	,	$zero
	li	$t1	,	0
	add	$t0	,	$t0	,	$t1
	sw	$t0	,	268456972($zero)
	li	$t0	,	5
	addi	$t0	,	$t0	,	35
	sll	$t0	,	$t0	,	2
	lw	$t0	,	268435856($t0)
	sw	$t0	,	268456976($zero)
	lw	$t0	,	268456976($zero)
	sw	$t0	,	0($sp)
	addi	$sp	,	$sp	,	-4
	jal	returnchar
	nop
	lw	$t0	,	268456972($zero)
	add	$t1	,	$v0	,	$zero
	mul	$t0	,	$t0	,	$t1
	sw	$t0	,	268456972($zero)
	li	$t0	,	5
	addi	$t0	,	$t0	,	35
	sll	$t0	,	$t0	,	2
	lw	$t0	,	268435856($t0)
	sw	$t0	,	268456980($zero)
	lw	$t0	,	268456980($zero)
	sw	$t0	,	0($sp)
	addi	$sp	,	$sp	,	-4
	jal	returnchar
	nop
	lw	$t0	,	268456972($zero)
	add	$t1	,	$v0	,	$zero
	mul	$t0	,	$t0	,	$t1
	sw	$t0	,	268456972($zero)
	li	$v0	,	1
	lw	$a0	,	268456972($zero)
	syscall
	li	$v0	,	4
	la	$a0	,	$Message41
	syscall
	lw	$t0	,	268443996($zero)
	li	$t1	,	0
	add	$t0	,	$t0	,	$t1
	sw	$t0	,	268456984($zero)
	li	$t0	,	355200
	lw	$t1	,	268456984($zero)
	div	$t0	,	$t1
	mflo	$t0
	sw	$t0	,	268456984($zero)
	lw	$t0	,	268456984($zero)
	li	$t1	,	355200
	div	$t0	,	$t1
	mflo	$t0
	sw	$t0	,	268456984($zero)
	li	$t0	,	20
	addi	$t0	,	$t0	,	4038
	sll	$t0	,	$t0	,	2
	lw	$t0	,	268435856($t0)
	sw	$t0	,	268456988($zero)
	lw	$t0	,	268456984($zero)
	lw	$t1	,	268456988($zero)
	mul	$t0	,	$t0	,	$t1
	sw	$t0	,	268456984($zero)
	li	$v0	,	1
	lw	$a0	,	268456984($zero)
	syscall
	li	$v0	,	4
	la	$a0	,	$Message42
	syscall
	li	$t0	,	5
	addi	$t0	,	$t0	,	35
	sll	$t0	,	$t0	,	2
	lw	$t0	,	268435856($t0)
	sw	$t0	,	268456992($zero)
	lw	$t0	,	268456992($zero)
	sw	$t0	,	0($sp)
	addi	$sp	,	$sp	,	-4
	jal	returnchar
	nop
	add	$t0	,	$v0	,	$zero
	li	$t1	,	0
	add	$t0	,	$t0	,	$t1
	sw	$t0	,	268456996($zero)
	li	$t0	,	5
	addi	$t0	,	$t0	,	35
	sll	$t0	,	$t0	,	2
	lw	$t0	,	268435856($t0)
	sw	$t0	,	268457000($zero)
	lw	$t0	,	268457000($zero)
	sw	$t0	,	0($sp)
	addi	$sp	,	$sp	,	-4
	jal	returnchar
	nop
	lw	$t0	,	268456996($zero)
	add	$t1	,	$v0	,	$zero
	mul	$t0	,	$t0	,	$t1
	sw	$t0	,	268456996($zero)
	li	$t0	,	5
	addi	$t0	,	$t0	,	35
	sll	$t0	,	$t0	,	2
	lw	$t0	,	268435856($t0)
	sw	$t0	,	268457004($zero)
	lw	$t0	,	268457004($zero)
	sw	$t0	,	0($sp)
	addi	$sp	,	$sp	,	-4
	jal	returnchar
	nop
	lw	$t0	,	268456996($zero)
	add	$t1	,	$v0	,	$zero
	mul	$t0	,	$t0	,	$t1
	sw	$t0	,	268456996($zero)
	li	$t0	,	95
	lw	$t1	,	268456996($zero)
	mul	$t0	,	$t0	,	$t1
	sw	$t0	,	268456996($zero)
	li	$v0	,	1
	lw	$a0	,	268456996($zero)
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
	sw	$t0	,	268457008($zero)
	lw	$t0	,	268457008($zero)
	sw	$t0	,	0($sp)
	addi	$sp	,	$sp	,	-4
	jal	fib
	nop
	add	$t0	,	$v0	,	$zero
	li	$t1	,	0
	add	$t0	,	$t0	,	$t1
	sw	$t0	,	268457012($zero)
	li	$t0	,	5
	sw	$t0	,	0($sp)
	addi	$sp	,	$sp	,	-4
	jal	fib
	nop
	add	$t0	,	$v0	,	$zero
	li	$t1	,	0
	add	$t0	,	$t0	,	$t1
	sw	$t0	,	268457016($zero)
	lw	$t0	,	268457012($zero)
	lw	$t1	,	268457016($zero)
	sub	$t0	,	$t0	,	$t1
	sw	$t0	,	268457012($zero)
	lw	$t0	,	268457012($zero)
	sw	$t0	,	0($sp)
	addi	$sp	,	$sp	,	-4
	jal	fib
	nop
	add	$t0	,	$v0	,	$zero
	li	$t1	,	0
	add	$t0	,	$t0	,	$t1
	sw	$t0	,	268457020($zero)
	li	$v0	,	1
	lw	$a0	,	268457020($zero)
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
	sw	$t0	,	268457024($zero)
	lw	$t0	,	268457024($zero)
	sw	$t0	,	0($sp)
	addi	$sp	,	$sp	,	-4
	jal	fib
	nop
	add	$t0	,	$v0	,	$zero
	li	$t1	,	0
	add	$t0	,	$t0	,	$t1
	sw	$t0	,	268457028($zero)
	lw	$t0	,	268457028($zero)
	sw	$t0	,	0($sp)
	addi	$sp	,	$sp	,	-4
	jal	fib
	nop
	add	$t0	,	$v0	,	$zero
	li	$t1	,	0
	add	$t0	,	$t0	,	$t1
	sw	$t0	,	268457032($zero)
	lw	$t0	,	268457032($zero)
	addi	$t0	,	$t0	,	4038
	sll	$t0	,	$t0	,	2
	lw	$t0	,	268435856($t0)
	sw	$t0	,	268457036($zero)
	li	$t0	,	0
	addi	$t0	,	$t0	,	4038
	sll	$t0	,	$t0	,	2
	lw	$t0	,	268435856($t0)
	sw	$t0	,	268457040($zero)
	li	$t0	,	0
	addi	$t0	,	$t0	,	4038
	sll	$t0	,	$t0	,	2
	lw	$t0	,	268435856($t0)
	sw	$t0	,	268457044($zero)
	lw	$t0	,	268457040($zero)
	lw	$t1	,	268457044($zero)
	div	$t0	,	$t1
	mflo	$t0
	sw	$t0	,	268457040($zero)
	lw	$t0	,	268457040($zero)
	sw	$t0	,	0($sp)
	addi	$sp	,	$sp	,	-4
	jal	fib
	nop
	add	$t0	,	$v0	,	$zero
	li	$t1	,	0
	add	$t0	,	$t0	,	$t1
	sw	$t0	,	268457048($zero)
	lw	$t0	,	268457048($zero)
	sw	$t0	,	0($sp)
	addi	$sp	,	$sp	,	-4
	jal	fib
	nop
	add	$t0	,	$v0	,	$zero
	li	$t1	,	0
	add	$t0	,	$t0	,	$t1
	sw	$t0	,	268457052($zero)
	lw	$t0	,	268457052($zero)
	addi	$t0	,	$t0	,	4038
	sll	$t0	,	$t0	,	2
	lw	$t0	,	268435856($t0)
	sw	$t0	,	268457056($zero)
	lw	$t0	,	268457036($zero)
	lw	$t1	,	268457056($zero)
	sub	$t0	,	$t0	,	$t1
	sw	$t0	,	268457036($zero)
	lw	$t0	,	268457036($zero)
	sw	$t0	,	0($sp)
	addi	$sp	,	$sp	,	-4
	jal	fib
	nop
	add	$t0	,	$v0	,	$zero
	li	$t1	,	0
	add	$t0	,	$t0	,	$t1
	sw	$t0	,	268457060($zero)
	lw	$t0	,	268457060($zero)
	addi	$t0	,	$t0	,	4038
	sll	$t0	,	$t0	,	2
	lw	$t0	,	268435856($t0)
	sw	$t0	,	268457064($zero)
	li	$v0	,	1
	lw	$a0	,	268457064($zero)
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
	sw	$t0	,	268457068($zero)
	li	$t0	,	0
	lw	$t1	,	268457068($zero)
	sub	$t0	,	$t0	,	$t1
	sw	$t0	,	268457068($zero)
	li	$v0	,	1
	lw	$a0	,	268457068($zero)
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
	sw	$t0	,	268457072($zero)
	lw	$t0	,	268457072($zero)
	sw	$t0	,	0($sp)
	addi	$sp	,	$sp	,	-4
	jal	fib
	nop
	add	$t0	,	$v0	,	$zero
	li	$t1	,	0
	add	$t0	,	$t0	,	$t1
	sw	$t0	,	268457076($zero)
	lw	$t0	,	268457076($zero)
	sw	$t0	,	0($sp)
	addi	$sp	,	$sp	,	-4
	jal	fib
	nop
	add	$t0	,	$v0	,	$zero
	li	$t1	,	0
	add	$t0	,	$t0	,	$t1
	sw	$t0	,	268457080($zero)
	lw	$t0	,	268457080($zero)
	addi	$t0	,	$t0	,	4038
	sll	$t0	,	$t0	,	2
	lw	$t0	,	268435856($t0)
	sw	$t0	,	268457084($zero)
	li	$t0	,	0
	addi	$t0	,	$t0	,	4038
	sll	$t0	,	$t0	,	2
	lw	$t0	,	268435856($t0)
	sw	$t0	,	268457088($zero)
	li	$t0	,	0
	addi	$t0	,	$t0	,	4038
	sll	$t0	,	$t0	,	2
	lw	$t0	,	268435856($t0)
	sw	$t0	,	268457092($zero)
	lw	$t0	,	268457088($zero)
	lw	$t1	,	268457092($zero)
	div	$t0	,	$t1
	mflo	$t0
	sw	$t0	,	268457088($zero)
	lw	$t0	,	268457088($zero)
	sw	$t0	,	0($sp)
	addi	$sp	,	$sp	,	-4
	jal	fib
	nop
	add	$t0	,	$v0	,	$zero
	li	$t1	,	0
	add	$t0	,	$t0	,	$t1
	sw	$t0	,	268457096($zero)
	lw	$t0	,	268457096($zero)
	sw	$t0	,	0($sp)
	addi	$sp	,	$sp	,	-4
	jal	fib
	nop
	add	$t0	,	$v0	,	$zero
	li	$t1	,	0
	add	$t0	,	$t0	,	$t1
	sw	$t0	,	268457100($zero)
	lw	$t0	,	268457100($zero)
	addi	$t0	,	$t0	,	4038
	sll	$t0	,	$t0	,	2
	lw	$t0	,	268435856($t0)
	sw	$t0	,	268457104($zero)
	lw	$t0	,	268457084($zero)
	lw	$t1	,	268457104($zero)
	sub	$t0	,	$t0	,	$t1
	sw	$t0	,	268457084($zero)
	lw	$t0	,	268457084($zero)
	sw	$t0	,	0($sp)
	addi	$sp	,	$sp	,	-4
	jal	fib
	nop
	add	$t0	,	$v0	,	$zero
	li	$t1	,	0
	add	$t0	,	$t0	,	$t1
	sw	$t0	,	268457108($zero)
	lw	$t0	,	268457108($zero)
	addi	$t0	,	$t0	,	4038
	sll	$t0	,	$t0	,	2
	lw	$t0	,	268435856($t0)
	sw	$t0	,	268457112($zero)
	li	$t0	,	0
	lw	$t1	,	268457112($zero)
	sub	$t0	,	$t0	,	$t1
	sw	$t0	,	268457112($zero)
	lw	$t0	,	268443996($zero)
	li	$t1	,	0
	add	$t0	,	$t0	,	$t1
	sw	$t0	,	268457116($zero)
	li	$t0	,	355200
	lw	$t1	,	268457116($zero)
	div	$t0	,	$t1
	mflo	$t0
	sw	$t0	,	268457116($zero)
	lw	$t0	,	268457116($zero)
	li	$t1	,	355200
	div	$t0	,	$t1
	mflo	$t0
	sw	$t0	,	268457116($zero)
	li	$t0	,	20
	addi	$t0	,	$t0	,	4038
	sll	$t0	,	$t0	,	2
	lw	$t0	,	268435856($t0)
	sw	$t0	,	268457120($zero)
	lw	$t0	,	268457116($zero)
	lw	$t1	,	268457120($zero)
	mul	$t0	,	$t0	,	$t1
	sw	$t0	,	268457116($zero)
	lw	$t0	,	268457112($zero)
	lw	$t1	,	268457116($zero)
	add	$t0	,	$t0	,	$t1
	sw	$t0	,	268457112($zero)
	li	$v0	,	1
	lw	$a0	,	268457112($zero)
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
	sw	$t0	,	268457124($zero)
	lw	$t0	,	268457124($zero)
	sw	$t0	,	0($sp)
	addi	$sp	,	$sp	,	-4
	jal	fib
	nop
	add	$t0	,	$v0	,	$zero
	li	$t1	,	0
	add	$t0	,	$t0	,	$t1
	sw	$t0	,	268457128($zero)
	lw	$t0	,	268457128($zero)
	sw	$t0	,	0($sp)
	addi	$sp	,	$sp	,	-4
	jal	fib
	nop
	add	$t0	,	$v0	,	$zero
	li	$t1	,	0
	add	$t0	,	$t0	,	$t1
	sw	$t0	,	268457132($zero)
	lw	$t0	,	268457132($zero)
	addi	$t0	,	$t0	,	4038
	sll	$t0	,	$t0	,	2
	lw	$t0	,	268435856($t0)
	sw	$t0	,	268457136($zero)
	li	$t0	,	0
	addi	$t0	,	$t0	,	4038
	sll	$t0	,	$t0	,	2
	lw	$t0	,	268435856($t0)
	sw	$t0	,	268457140($zero)
	li	$t0	,	0
	addi	$t0	,	$t0	,	4038
	sll	$t0	,	$t0	,	2
	lw	$t0	,	268435856($t0)
	sw	$t0	,	268457144($zero)
	lw	$t0	,	268457140($zero)
	lw	$t1	,	268457144($zero)
	div	$t0	,	$t1
	mflo	$t0
	sw	$t0	,	268457140($zero)
	lw	$t0	,	268457140($zero)
	sw	$t0	,	0($sp)
	addi	$sp	,	$sp	,	-4
	jal	fib
	nop
	add	$t0	,	$v0	,	$zero
	li	$t1	,	0
	add	$t0	,	$t0	,	$t1
	sw	$t0	,	268457148($zero)
	lw	$t0	,	268457148($zero)
	sw	$t0	,	0($sp)
	addi	$sp	,	$sp	,	-4
	jal	fib
	nop
	add	$t0	,	$v0	,	$zero
	li	$t1	,	0
	add	$t0	,	$t0	,	$t1
	sw	$t0	,	268457152($zero)
	lw	$t0	,	268457152($zero)
	addi	$t0	,	$t0	,	4038
	sll	$t0	,	$t0	,	2
	lw	$t0	,	268435856($t0)
	sw	$t0	,	268457156($zero)
	lw	$t0	,	268457136($zero)
	lw	$t1	,	268457156($zero)
	sub	$t0	,	$t0	,	$t1
	sw	$t0	,	268457136($zero)
	lw	$t0	,	268457136($zero)
	sw	$t0	,	0($sp)
	addi	$sp	,	$sp	,	-4
	jal	fib
	nop
	add	$t0	,	$v0	,	$zero
	li	$t1	,	0
	add	$t0	,	$t0	,	$t1
	sw	$t0	,	268457160($zero)
	lw	$t0	,	268457160($zero)
	addi	$t0	,	$t0	,	4038
	sll	$t0	,	$t0	,	2
	lw	$t0	,	268435856($t0)
	sw	$t0	,	268457164($zero)
	li	$t0	,	5
	addi	$t0	,	$t0	,	35
	sll	$t0	,	$t0	,	2
	lw	$t0	,	268435856($t0)
	sw	$t0	,	268457168($zero)
	lw	$t0	,	268457168($zero)
	sw	$t0	,	0($sp)
	addi	$sp	,	$sp	,	-4
	jal	returnchar
	nop
	add	$t0	,	$v0	,	$zero
	li	$t1	,	0
	add	$t0	,	$t0	,	$t1
	sw	$t0	,	268457172($zero)
	li	$t0	,	5
	addi	$t0	,	$t0	,	35
	sll	$t0	,	$t0	,	2
	lw	$t0	,	268435856($t0)
	sw	$t0	,	268457176($zero)
	lw	$t0	,	268457176($zero)
	sw	$t0	,	0($sp)
	addi	$sp	,	$sp	,	-4
	jal	returnchar
	nop
	lw	$t0	,	268457172($zero)
	add	$t1	,	$v0	,	$zero
	mul	$t0	,	$t0	,	$t1
	sw	$t0	,	268457172($zero)
	li	$t0	,	5
	addi	$t0	,	$t0	,	35
	sll	$t0	,	$t0	,	2
	lw	$t0	,	268435856($t0)
	sw	$t0	,	268457180($zero)
	lw	$t0	,	268457180($zero)
	sw	$t0	,	0($sp)
	addi	$sp	,	$sp	,	-4
	jal	returnchar
	nop
	lw	$t0	,	268457172($zero)
	add	$t1	,	$v0	,	$zero
	mul	$t0	,	$t0	,	$t1
	sw	$t0	,	268457172($zero)
	li	$t0	,	95
	lw	$t1	,	268457172($zero)
	mul	$t0	,	$t0	,	$t1
	sw	$t0	,	268457172($zero)
	lw	$t0	,	268457164($zero)
	lw	$t1	,	268457172($zero)
	sub	$t0	,	$t0	,	$t1
	sw	$t0	,	268457164($zero)
	li	$v0	,	1
	lw	$a0	,	268457164($zero)
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
	sw	$t0	,	268457184($zero)
	lw	$t0	,	268457184($zero)
	sw	$t0	,	0($sp)
	addi	$sp	,	$sp	,	-4
	jal	fib
	nop
	add	$t0	,	$v0	,	$zero
	li	$t1	,	0
	add	$t0	,	$t0	,	$t1
	sw	$t0	,	268457188($zero)
	lw	$t0	,	268457188($zero)
	sw	$t0	,	0($sp)
	addi	$sp	,	$sp	,	-4
	jal	fib
	nop
	add	$t0	,	$v0	,	$zero
	li	$t1	,	0
	add	$t0	,	$t0	,	$t1
	sw	$t0	,	268457192($zero)
	lw	$t0	,	268457192($zero)
	addi	$t0	,	$t0	,	4038
	sll	$t0	,	$t0	,	2
	lw	$t0	,	268435856($t0)
	sw	$t0	,	268457196($zero)
	li	$t0	,	0
	addi	$t0	,	$t0	,	4038
	sll	$t0	,	$t0	,	2
	lw	$t0	,	268435856($t0)
	sw	$t0	,	268457200($zero)
	li	$t0	,	0
	addi	$t0	,	$t0	,	4038
	sll	$t0	,	$t0	,	2
	lw	$t0	,	268435856($t0)
	sw	$t0	,	268457204($zero)
	lw	$t0	,	268457200($zero)
	lw	$t1	,	268457204($zero)
	div	$t0	,	$t1
	mflo	$t0
	sw	$t0	,	268457200($zero)
	lw	$t0	,	268457200($zero)
	sw	$t0	,	0($sp)
	addi	$sp	,	$sp	,	-4
	jal	fib
	nop
	add	$t0	,	$v0	,	$zero
	li	$t1	,	0
	add	$t0	,	$t0	,	$t1
	sw	$t0	,	268457208($zero)
	lw	$t0	,	268457208($zero)
	sw	$t0	,	0($sp)
	addi	$sp	,	$sp	,	-4
	jal	fib
	nop
	add	$t0	,	$v0	,	$zero
	li	$t1	,	0
	add	$t0	,	$t0	,	$t1
	sw	$t0	,	268457212($zero)
	lw	$t0	,	268457212($zero)
	addi	$t0	,	$t0	,	4038
	sll	$t0	,	$t0	,	2
	lw	$t0	,	268435856($t0)
	sw	$t0	,	268457216($zero)
	lw	$t0	,	268457196($zero)
	lw	$t1	,	268457216($zero)
	sub	$t0	,	$t0	,	$t1
	sw	$t0	,	268457196($zero)
	lw	$t0	,	268457196($zero)
	sw	$t0	,	0($sp)
	addi	$sp	,	$sp	,	-4
	jal	fib
	nop
	add	$t0	,	$v0	,	$zero
	li	$t1	,	0
	add	$t0	,	$t0	,	$t1
	sw	$t0	,	268457220($zero)
	lw	$t0	,	268457220($zero)
	addi	$t0	,	$t0	,	4038
	sll	$t0	,	$t0	,	2
	lw	$t0	,	268435856($t0)
	sw	$t0	,	268457224($zero)
	li	$t0	,	5
	addi	$t0	,	$t0	,	35
	sll	$t0	,	$t0	,	2
	lw	$t0	,	268435856($t0)
	sw	$t0	,	268457228($zero)
	lw	$t0	,	268457228($zero)
	sw	$t0	,	0($sp)
	addi	$sp	,	$sp	,	-4
	jal	returnchar
	nop
	add	$t0	,	$v0	,	$zero
	li	$t1	,	0
	add	$t0	,	$t0	,	$t1
	sw	$t0	,	268457232($zero)
	li	$t0	,	5
	addi	$t0	,	$t0	,	35
	sll	$t0	,	$t0	,	2
	lw	$t0	,	268435856($t0)
	sw	$t0	,	268457236($zero)
	lw	$t0	,	268457236($zero)
	sw	$t0	,	0($sp)
	addi	$sp	,	$sp	,	-4
	jal	returnchar
	nop
	lw	$t0	,	268457232($zero)
	add	$t1	,	$v0	,	$zero
	mul	$t0	,	$t0	,	$t1
	sw	$t0	,	268457232($zero)
	li	$t0	,	5
	addi	$t0	,	$t0	,	35
	sll	$t0	,	$t0	,	2
	lw	$t0	,	268435856($t0)
	sw	$t0	,	268457240($zero)
	lw	$t0	,	268457240($zero)
	sw	$t0	,	0($sp)
	addi	$sp	,	$sp	,	-4
	jal	returnchar
	nop
	lw	$t0	,	268457232($zero)
	add	$t1	,	$v0	,	$zero
	mul	$t0	,	$t0	,	$t1
	sw	$t0	,	268457232($zero)
	li	$t0	,	95
	lw	$t1	,	268457232($zero)
	mul	$t0	,	$t0	,	$t1
	sw	$t0	,	268457232($zero)
	lw	$t0	,	268457224($zero)
	lw	$t1	,	268457232($zero)
	sub	$t0	,	$t0	,	$t1
	sw	$t0	,	268457224($zero)
	li	$t0	,	6
	sw	$t0	,	0($sp)
	addi	$sp	,	$sp	,	-4
	jal	fib
	nop
	add	$t0	,	$v0	,	$zero
	li	$t1	,	0
	add	$t0	,	$t0	,	$t1
	sw	$t0	,	268457244($zero)
	lw	$t0	,	268457244($zero)
	sw	$t0	,	0($sp)
	addi	$sp	,	$sp	,	-4
	jal	fib
	nop
	add	$t0	,	$v0	,	$zero
	li	$t1	,	0
	add	$t0	,	$t0	,	$t1
	sw	$t0	,	268457248($zero)
	li	$t0	,	5
	sw	$t0	,	0($sp)
	addi	$sp	,	$sp	,	-4
	jal	fib
	nop
	add	$t0	,	$v0	,	$zero
	li	$t1	,	0
	add	$t0	,	$t0	,	$t1
	sw	$t0	,	268457252($zero)
	lw	$t0	,	268457248($zero)
	lw	$t1	,	268457252($zero)
	sub	$t0	,	$t0	,	$t1
	sw	$t0	,	268457248($zero)
	lw	$t0	,	268457248($zero)
	sw	$t0	,	0($sp)
	addi	$sp	,	$sp	,	-4
	jal	fib
	nop
	add	$t0	,	$v0	,	$zero
	li	$t1	,	0
	add	$t0	,	$t0	,	$t1
	sw	$t0	,	268457256($zero)
	li	$t0	,	0
	lw	$t1	,	268457256($zero)
	sub	$t0	,	$t0	,	$t1
	sw	$t0	,	268457256($zero)
	lw	$t0	,	268457224($zero)
	lw	$t1	,	268457256($zero)
	sub	$t0	,	$t0	,	$t1
	sw	$t0	,	268457224($zero)
	li	$t0	,	0
	sw	$t0	,	0($sp)
	addi	$sp	,	$sp	,	-4
	jal	fib
	nop
	add	$t0	,	$v0	,	$zero
	li	$t1	,	0
	add	$t0	,	$t0	,	$t1
	sw	$t0	,	268457260($zero)
	li	$t0	,	355200
	lw	$t1	,	268457260($zero)
	mul	$t0	,	$t0	,	$t1
	sw	$t0	,	268457260($zero)
	lw	$t0	,	268457224($zero)
	lw	$t1	,	268457260($zero)
	add	$t0	,	$t0	,	$t1
	sw	$t0	,	268457224($zero)
	li	$v0	,	1
	lw	$a0	,	268457224($zero)
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
	sw	$t0	,	268457264($zero)
	li	$t0	,	1000
	lw	$t1	,	268457264($zero)
	div	$t0	,	$t1
	mflo	$t0
	sw	$t0	,	268457264($zero)
	lw	$t0	,	268457264($zero)
	li	$t1	,	200
	sub	$t0	,	$t0	,	$t1
	sw	$t0	,	268457264($zero)
	li	$t0	,	0
	sw	$t0	,	0($sp)
	addi	$sp	,	$sp	,	-4
	jal	fib
	nop
	add	$t0	,	$v0	,	$zero
	li	$t1	,	0
	add	$t0	,	$t0	,	$t1
	sw	$t0	,	268457268($zero)
	lw	$t0	,	268457268($zero)
	sw	$t0	,	0($sp)
	addi	$sp	,	$sp	,	-4
	jal	fib
	nop
	add	$t0	,	$v0	,	$zero
	li	$t1	,	0
	add	$t0	,	$t0	,	$t1
	sw	$t0	,	268457272($zero)
	lw	$t0	,	268457272($zero)
	sw	$t0	,	0($sp)
	addi	$sp	,	$sp	,	-4
	jal	fib
	nop
	add	$t0	,	$v0	,	$zero
	li	$t1	,	0
	add	$t0	,	$t0	,	$t1
	sw	$t0	,	268457276($zero)
	lw	$t0	,	268457276($zero)
	addi	$t0	,	$t0	,	4038
	sll	$t0	,	$t0	,	2
	lw	$t0	,	268435856($t0)
	sw	$t0	,	268457280($zero)
	li	$t0	,	0
	addi	$t0	,	$t0	,	4038
	sll	$t0	,	$t0	,	2
	lw	$t0	,	268435856($t0)
	sw	$t0	,	268457284($zero)
	li	$t0	,	0
	addi	$t0	,	$t0	,	4038
	sll	$t0	,	$t0	,	2
	lw	$t0	,	268435856($t0)
	sw	$t0	,	268457288($zero)
	lw	$t0	,	268457284($zero)
	lw	$t1	,	268457288($zero)
	div	$t0	,	$t1
	mflo	$t0
	sw	$t0	,	268457284($zero)
	lw	$t0	,	268457284($zero)
	sw	$t0	,	0($sp)
	addi	$sp	,	$sp	,	-4
	jal	fib
	nop
	add	$t0	,	$v0	,	$zero
	li	$t1	,	0
	add	$t0	,	$t0	,	$t1
	sw	$t0	,	268457292($zero)
	lw	$t0	,	268457292($zero)
	sw	$t0	,	0($sp)
	addi	$sp	,	$sp	,	-4
	jal	fib
	nop
	add	$t0	,	$v0	,	$zero
	li	$t1	,	0
	add	$t0	,	$t0	,	$t1
	sw	$t0	,	268457296($zero)
	lw	$t0	,	268457296($zero)
	addi	$t0	,	$t0	,	4038
	sll	$t0	,	$t0	,	2
	lw	$t0	,	268435856($t0)
	sw	$t0	,	268457300($zero)
	lw	$t0	,	268457280($zero)
	lw	$t1	,	268457300($zero)
	sub	$t0	,	$t0	,	$t1
	sw	$t0	,	268457280($zero)
	lw	$t0	,	268457280($zero)
	sw	$t0	,	0($sp)
	addi	$sp	,	$sp	,	-4
	jal	fib
	nop
	add	$t0	,	$v0	,	$zero
	li	$t1	,	0
	add	$t0	,	$t0	,	$t1
	sw	$t0	,	268457304($zero)
	lw	$t0	,	268457304($zero)
	addi	$t0	,	$t0	,	4038
	sll	$t0	,	$t0	,	2
	lw	$t0	,	268435856($t0)
	sw	$t0	,	268457308($zero)
	li	$t0	,	5
	addi	$t0	,	$t0	,	35
	sll	$t0	,	$t0	,	2
	lw	$t0	,	268435856($t0)
	sw	$t0	,	268457312($zero)
	lw	$t0	,	268457312($zero)
	sw	$t0	,	0($sp)
	addi	$sp	,	$sp	,	-4
	jal	returnchar
	nop
	add	$t0	,	$v0	,	$zero
	li	$t1	,	0
	add	$t0	,	$t0	,	$t1
	sw	$t0	,	268457316($zero)
	li	$t0	,	5
	addi	$t0	,	$t0	,	35
	sll	$t0	,	$t0	,	2
	lw	$t0	,	268435856($t0)
	sw	$t0	,	268457320($zero)
	lw	$t0	,	268457320($zero)
	sw	$t0	,	0($sp)
	addi	$sp	,	$sp	,	-4
	jal	returnchar
	nop
	lw	$t0	,	268457316($zero)
	add	$t1	,	$v0	,	$zero
	mul	$t0	,	$t0	,	$t1
	sw	$t0	,	268457316($zero)
	li	$t0	,	5
	addi	$t0	,	$t0	,	35
	sll	$t0	,	$t0	,	2
	lw	$t0	,	268435856($t0)
	sw	$t0	,	268457324($zero)
	lw	$t0	,	268457324($zero)
	sw	$t0	,	0($sp)
	addi	$sp	,	$sp	,	-4
	jal	returnchar
	nop
	lw	$t0	,	268457316($zero)
	add	$t1	,	$v0	,	$zero
	mul	$t0	,	$t0	,	$t1
	sw	$t0	,	268457316($zero)
	li	$t0	,	95
	lw	$t1	,	268457316($zero)
	mul	$t0	,	$t0	,	$t1
	sw	$t0	,	268457316($zero)
	lw	$t0	,	268457308($zero)
	lw	$t1	,	268457316($zero)
	sub	$t0	,	$t0	,	$t1
	sw	$t0	,	268457308($zero)
	li	$t0	,	5
	sw	$t0	,	0($sp)
	addi	$sp	,	$sp	,	-4
	jal	fib
	nop
	add	$t0	,	$v0	,	$zero
	li	$t1	,	0
	add	$t0	,	$t0	,	$t1
	sw	$t0	,	268457328($zero)
	li	$t0	,	3
	lw	$t1	,	268457328($zero)
	add	$t0	,	$t0	,	$t1
	sw	$t0	,	268457328($zero)
	lw	$t0	,	268457328($zero)
	sw	$t0	,	0($sp)
	addi	$sp	,	$sp	,	-4
	jal	fib
	nop
	add	$t0	,	$v0	,	$zero
	li	$t1	,	0
	add	$t0	,	$t0	,	$t1
	sw	$t0	,	268457332($zero)
	li	$t0	,	5
	sw	$t0	,	0($sp)
	addi	$sp	,	$sp	,	-4
	jal	fib
	nop
	add	$t0	,	$v0	,	$zero
	li	$t1	,	0
	add	$t0	,	$t0	,	$t1
	sw	$t0	,	268457336($zero)
	lw	$t0	,	268457332($zero)
	lw	$t1	,	268457336($zero)
	sub	$t0	,	$t0	,	$t1
	sw	$t0	,	268457332($zero)
	lw	$t0	,	268457332($zero)
	sw	$t0	,	0($sp)
	addi	$sp	,	$sp	,	-4
	jal	fib
	nop
	add	$t0	,	$v0	,	$zero
	li	$t1	,	0
	add	$t0	,	$t0	,	$t1
	sw	$t0	,	268457340($zero)
	lw	$t0	,	268457340($zero)
	sw	$t0	,	0($sp)
	addi	$sp	,	$sp	,	-4
	jal	fib
	nop
	add	$t0	,	$v0	,	$zero
	li	$t1	,	0
	add	$t0	,	$t0	,	$t1
	sw	$t0	,	268457344($zero)
	li	$t0	,	0
	lw	$t1	,	268457344($zero)
	sub	$t0	,	$t0	,	$t1
	sw	$t0	,	268457344($zero)
	lw	$t0	,	268457308($zero)
	lw	$t1	,	268457344($zero)
	sub	$t0	,	$t0	,	$t1
	sw	$t0	,	268457308($zero)
	li	$t0	,	0
	sw	$t0	,	0($sp)
	addi	$sp	,	$sp	,	-4
	jal	fib
	nop
	add	$t0	,	$v0	,	$zero
	li	$t1	,	0
	add	$t0	,	$t0	,	$t1
	sw	$t0	,	268457348($zero)
	li	$t0	,	355200
	lw	$t1	,	268457348($zero)
	mul	$t0	,	$t0	,	$t1
	sw	$t0	,	268457348($zero)
	lw	$t0	,	268457308($zero)
	lw	$t1	,	268457348($zero)
	add	$t0	,	$t0	,	$t1
	sw	$t0	,	268457308($zero)
	li	$t0	,	0
	sw	$t0	,	0($sp)
	addi	$sp	,	$sp	,	-4
	jal	fib
	nop
	add	$t0	,	$v0	,	$zero
	li	$t1	,	0
	add	$t0	,	$t0	,	$t1
	sw	$t0	,	268457352($zero)
	lw	$t0	,	268457352($zero)
	sw	$t0	,	0($sp)
	addi	$sp	,	$sp	,	-4
	jal	fib
	nop
	add	$t0	,	$v0	,	$zero
	li	$t1	,	0
	add	$t0	,	$t0	,	$t1
	sw	$t0	,	268457356($zero)
	lw	$t0	,	268457356($zero)
	sw	$t0	,	0($sp)
	addi	$sp	,	$sp	,	-4
	jal	fib
	nop
	add	$t0	,	$v0	,	$zero
	li	$t1	,	0
	add	$t0	,	$t0	,	$t1
	sw	$t0	,	268457360($zero)
	lw	$t0	,	268457360($zero)
	addi	$t0	,	$t0	,	4038
	sll	$t0	,	$t0	,	2
	lw	$t0	,	268435856($t0)
	sw	$t0	,	268457364($zero)
	li	$t0	,	0
	addi	$t0	,	$t0	,	4038
	sll	$t0	,	$t0	,	2
	lw	$t0	,	268435856($t0)
	sw	$t0	,	268457368($zero)
	li	$t0	,	0
	addi	$t0	,	$t0	,	4038
	sll	$t0	,	$t0	,	2
	lw	$t0	,	268435856($t0)
	sw	$t0	,	268457372($zero)
	lw	$t0	,	268457368($zero)
	lw	$t1	,	268457372($zero)
	div	$t0	,	$t1
	mflo	$t0
	sw	$t0	,	268457368($zero)
	lw	$t0	,	268457368($zero)
	sw	$t0	,	0($sp)
	addi	$sp	,	$sp	,	-4
	jal	fib
	nop
	add	$t0	,	$v0	,	$zero
	li	$t1	,	0
	add	$t0	,	$t0	,	$t1
	sw	$t0	,	268457376($zero)
	lw	$t0	,	268457376($zero)
	sw	$t0	,	0($sp)
	addi	$sp	,	$sp	,	-4
	jal	fib
	nop
	add	$t0	,	$v0	,	$zero
	li	$t1	,	0
	add	$t0	,	$t0	,	$t1
	sw	$t0	,	268457380($zero)
	lw	$t0	,	268457380($zero)
	addi	$t0	,	$t0	,	4038
	sll	$t0	,	$t0	,	2
	lw	$t0	,	268435856($t0)
	sw	$t0	,	268457384($zero)
	lw	$t0	,	268457364($zero)
	lw	$t1	,	268457384($zero)
	sub	$t0	,	$t0	,	$t1
	sw	$t0	,	268457364($zero)
	lw	$t0	,	268457364($zero)
	sw	$t0	,	0($sp)
	addi	$sp	,	$sp	,	-4
	jal	fib
	nop
	add	$t0	,	$v0	,	$zero
	li	$t1	,	0
	add	$t0	,	$t0	,	$t1
	sw	$t0	,	268457388($zero)
	lw	$t0	,	268457388($zero)
	addi	$t0	,	$t0	,	4038
	sll	$t0	,	$t0	,	2
	lw	$t0	,	268435856($t0)
	sw	$t0	,	268457392($zero)
	li	$t0	,	5
	addi	$t0	,	$t0	,	35
	sll	$t0	,	$t0	,	2
	lw	$t0	,	268435856($t0)
	sw	$t0	,	268457396($zero)
	lw	$t0	,	268457396($zero)
	sw	$t0	,	0($sp)
	addi	$sp	,	$sp	,	-4
	jal	returnchar
	nop
	add	$t0	,	$v0	,	$zero
	li	$t1	,	0
	add	$t0	,	$t0	,	$t1
	sw	$t0	,	268457400($zero)
	li	$t0	,	5
	addi	$t0	,	$t0	,	35
	sll	$t0	,	$t0	,	2
	lw	$t0	,	268435856($t0)
	sw	$t0	,	268457404($zero)
	lw	$t0	,	268457404($zero)
	sw	$t0	,	0($sp)
	addi	$sp	,	$sp	,	-4
	jal	returnchar
	nop
	lw	$t0	,	268457400($zero)
	add	$t1	,	$v0	,	$zero
	mul	$t0	,	$t0	,	$t1
	sw	$t0	,	268457400($zero)
	li	$t0	,	5
	addi	$t0	,	$t0	,	35
	sll	$t0	,	$t0	,	2
	lw	$t0	,	268435856($t0)
	sw	$t0	,	268457408($zero)
	lw	$t0	,	268457408($zero)
	sw	$t0	,	0($sp)
	addi	$sp	,	$sp	,	-4
	jal	returnchar
	nop
	lw	$t0	,	268457400($zero)
	add	$t1	,	$v0	,	$zero
	mul	$t0	,	$t0	,	$t1
	sw	$t0	,	268457400($zero)
	li	$t0	,	95
	lw	$t1	,	268457400($zero)
	mul	$t0	,	$t0	,	$t1
	sw	$t0	,	268457400($zero)
	lw	$t0	,	268457392($zero)
	lw	$t1	,	268457400($zero)
	sub	$t0	,	$t0	,	$t1
	sw	$t0	,	268457392($zero)
	li	$t0	,	0
	lw	$t1	,	268457392($zero)
	sub	$t0	,	$t0	,	$t1
	sw	$t0	,	268457392($zero)
	li	$t0	,	5
	sw	$t0	,	0($sp)
	addi	$sp	,	$sp	,	-4
	jal	fib
	nop
	add	$t0	,	$v0	,	$zero
	li	$t1	,	0
	add	$t0	,	$t0	,	$t1
	sw	$t0	,	268457412($zero)
	li	$t0	,	3
	lw	$t1	,	268457412($zero)
	add	$t0	,	$t0	,	$t1
	sw	$t0	,	268457412($zero)
	lw	$t0	,	268457412($zero)
	sw	$t0	,	0($sp)
	addi	$sp	,	$sp	,	-4
	jal	fib
	nop
	add	$t0	,	$v0	,	$zero
	li	$t1	,	0
	add	$t0	,	$t0	,	$t1
	sw	$t0	,	268457416($zero)
	li	$t0	,	5
	sw	$t0	,	0($sp)
	addi	$sp	,	$sp	,	-4
	jal	fib
	nop
	add	$t0	,	$v0	,	$zero
	li	$t1	,	0
	add	$t0	,	$t0	,	$t1
	sw	$t0	,	268457420($zero)
	lw	$t0	,	268457416($zero)
	lw	$t1	,	268457420($zero)
	sub	$t0	,	$t0	,	$t1
	sw	$t0	,	268457416($zero)
	lw	$t0	,	268457416($zero)
	sw	$t0	,	0($sp)
	addi	$sp	,	$sp	,	-4
	jal	fib
	nop
	add	$t0	,	$v0	,	$zero
	li	$t1	,	0
	add	$t0	,	$t0	,	$t1
	sw	$t0	,	268457424($zero)
	lw	$t0	,	268457424($zero)
	sw	$t0	,	0($sp)
	addi	$sp	,	$sp	,	-4
	jal	fib
	nop
	add	$t0	,	$v0	,	$zero
	li	$t1	,	0
	add	$t0	,	$t0	,	$t1
	sw	$t0	,	268457428($zero)
	li	$t0	,	0
	lw	$t1	,	268457428($zero)
	sub	$t0	,	$t0	,	$t1
	sw	$t0	,	268457428($zero)
	lw	$t0	,	268457392($zero)
	lw	$t1	,	268457428($zero)
	sub	$t0	,	$t0	,	$t1
	sw	$t0	,	268457392($zero)
	li	$t0	,	0
	sw	$t0	,	0($sp)
	addi	$sp	,	$sp	,	-4
	jal	fib
	nop
	add	$t0	,	$v0	,	$zero
	li	$t1	,	0
	add	$t0	,	$t0	,	$t1
	sw	$t0	,	268457432($zero)
	li	$t0	,	355200
	lw	$t1	,	268457432($zero)
	mul	$t0	,	$t0	,	$t1
	sw	$t0	,	268457432($zero)
	lw	$t0	,	268457392($zero)
	lw	$t1	,	268457432($zero)
	add	$t0	,	$t0	,	$t1
	sw	$t0	,	268457392($zero)
	lw	$t0	,	268457308($zero)
	lw	$t1	,	268457392($zero)
	div	$t0	,	$t1
	mflo	$t0
	sw	$t0	,	268457308($zero)
	lw	$t0	,	268457264($zero)
	lw	$t1	,	268457308($zero)
	add	$t0	,	$t0	,	$t1
	sw	$t0	,	268457264($zero)
	lw	$t0	,	268457264($zero)
	sw	$t0	,	0($sp)
	addi	$sp	,	$sp	,	-4
	jal	fib
	nop
	add	$t0	,	$v0	,	$zero
	li	$t1	,	0
	add	$t0	,	$t0	,	$t1
	sw	$t0	,	268457436($zero)
	li	$v0	,	1
	lw	$a0	,	268457436($zero)
	syscall
main3$end:
	lw	$ra	,	4($sp)
	lw	$fp	,	8($sp)
	addi	$sp	,	$sp	,	12
	jr	$ra
	nop
main:
	addi	$sp	,	$sp	,	0
	sw	$fp	,	-4($sp)
	sw	$ra	,	-8($sp)
	add	$fp	,	$sp	,	$zero
	addi	$sp	,	$sp	,	-12
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
	sw	$t0	,	268457440($zero)
	li	$t0	,	97
	li	$t1	,	0
	add	$t0	,	$t0	,	$t1
	sw	$t0	,	268457444($zero)
	lw	$t0	,	268457444($zero)
	lw	$t1	,	268457440($zero)
	sub	$t0	,	$t0	,	$t1
	bne	$t0	,	$zero	,	$label38
	nop
	jal	main1
	nop
	j	$label37
	nop
$label38:
	li	$t0	,	98
	li	$t1	,	0
	add	$t0	,	$t0	,	$t1
	sw	$t0	,	268457448($zero)
	lw	$t0	,	268457448($zero)
	lw	$t1	,	268457440($zero)
	sub	$t0	,	$t0	,	$t1
	bne	$t0	,	$zero	,	$label39
	nop
	jal	main2
	nop
	j	$label37
	nop
$label39:
	li	$t0	,	99
	li	$t1	,	0
	add	$t0	,	$t0	,	$t1
	sw	$t0	,	268457452($zero)
	lw	$t0	,	268457452($zero)
	lw	$t1	,	268457440($zero)
	sub	$t0	,	$t0	,	$t1
	bne	$t0	,	$zero	,	$label40
	nop
	jal	main3
	nop
	j	$label37
	nop
$label40:
	li	$v0	,	4
	la	$a0	,	$Message52
	syscall
$label37:
	li	$v0	,	10
	syscall
