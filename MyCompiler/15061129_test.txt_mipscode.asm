#³õÊ¼»¯×Ö·û´®
	.data
	$Message0:.asciiz"*"
	$Message1:.asciiz" "
	$Message2:.asciiz" "
	$Message3:.asciiz" "
	$Message4:.asciiz" "
	$Message5:.asciiz" "
	$Message6:.asciiz" "
	$Message7:.asciiz" "
	$Message8:.asciiz" "
	$Message9:.asciiz" "
	$Message10:.asciiz" "
	$Message11:.asciiz" "
	$Message12:.asciiz" "
	$Message13:.asciiz" "
	$Message14:.asciiz" "
	$Message15:.asciiz" "
	$Message16:.asciiz" "
	$Message17:.asciiz"  "
	$Message18:.asciiz"  "
	$Message19:.asciiz"  "
	$Message20:.asciiz"num is less than 2!"
	$Message21:.asciiz"num is more than 45!"
	$Message22:.asciiz"the fib is : "
	$Message23:.asciiz"no."
	$Message24:.asciiz" is "
	$Message25:.asciiz" "
	$Message26:.asciiz"  "
	$Message27:.asciiz"please input a number from 0 to 4: "
	$Message28:.asciiz"out of range!"
	$Message29:.asciiz""
	.text
	li	$t9	,	95
	sw	$t9	,	268435856($zero)
	li	$t9	,	43
	sw	$t9	,	268435860($zero)
	li	$t9	,	45
	sw	$t9	,	268435864($zero)
	li	$t9	,	42
	sw	$t9	,	268435868($zero)
	li	$t9	,	47
	sw	$t9	,	268435872($zero)
	li	$t9	,	97
	sw	$t9	,	268435876($zero)
	li	$t9	,	48
	sw	$t9	,	268435880($zero)
	li	$t9	,	0
	sw	$t9	,	268435884($zero)
	li	$t9	,	4
	sw	$t9	,	268435888($zero)
	li	$t9	,	3
	sw	$t9	,	268435892($zero)
	li	$t9	,	-9
	sw	$t9	,	268435896($zero)
	li	$t9	,	20
	sw	$t9	,	268435900($zero)
	li	$t9	,	56
	sw	$t9	,	268435904($zero)
	li	$t9	,	-78
	sw	$t9	,	268435908($zero)
	li	$t9	,	5783
	sw	$t9	,	268435912($zero)
	li	$t9	,	326
	sw	$t9	,	268435916($zero)
	li	$t9	,	-111
	sw	$t9	,	268435920($zero)
	li	$t9	,	0
	sw	$t9	,	268435924($zero)
	li	$t9	,	100
	sw	$t9	,	268435928($zero)
	li	$t9	,	-1000
	sw	$t9	,	268435932($zero)
	li	$t9	,	97
	sw	$t9	,	268435936($zero)
	li	$t9	,	95
	sw	$t9	,	268435940($zero)
	li	$t9	,	65
	sw	$t9	,	268435944($zero)
	li	$t9	,	45
	sw	$t9	,	268435948($zero)
	li	$t9	,	42
	sw	$t9	,	268435952($zero)
	li	$t9	,	48
	sw	$t9	,	268435956($zero)
	add	$fp	,	$sp	,	$zero
	j	main
	nop
_4fib:
	addi	$sp	,	$sp	,	4
	sw	$fp	,	-20($sp)
	sw	$ra	,	-24($sp)
	li	$t9	,	95
	sw	$t9	,	-4($sp)
	add	$fp	,	$sp	,	$zero
	addi	$sp	,	$sp	,	-28
	lw	$t0	,	0($fp)
	sw	$t0	,	268443968($zero)
	li	$t0	,	0
	lw	$t1	,	268443968($zero)
	sub	$t0	,	$t0	,	$t1
	sw	$t0	,	268443968($zero)
	lw	$t0	,	268443968($zero)
	li	$t1	,	-1
	sub	$t0	,	$t0	,	$t1
	bgez	$t0	,	$label0
	nop
	lw	$t0	,	0($fp)
	sw	$t0	,	268443972($zero)
	lw	$t0	,	268443972($zero)
	li	$t1	,	1
	sub	$t0	,	$t0	,	$t1
	sw	$t0	,	268443972($zero)
	lw	$t0	,	268443972($zero)
	addi	$t0	,	$t0	,	27
	li	$t1	,	4
	mul	$t0	,	$t0	,	$t1
	lw	$t0	,	268435856($t0)
	sw	$t0	,	268443976($zero)
	lw	$t0	,	268443976($zero)
	li	$t1	,	-1
	sub	$t0	,	$t0	,	$t1
	bgtz	$t0	,	$label2
	nop
	lw	$t0	,	0($fp)
	sw	$t0	,	268443980($zero)
	lw	$t0	,	268443980($zero)
	li	$t1	,	1
	sub	$t0	,	$t0	,	$t1
	sw	$t0	,	268443980($zero)
	lw	$t0	,	268443980($zero)
	sw	$t0	,	0($sp)
	addi	$sp	,	$sp	,	-4
	jal	_4fib
	nop
	add	$t0	,	$v0	,	$zero
	sw	$t0	,	268443984($zero)
	lw	$t0	,	268443984($zero)
	sw	$t0	,	-12($fp)
	j	$label3
	nop
$label2:
	lw	$t0	,	0($fp)
	sw	$t0	,	268443988($zero)
	lw	$t0	,	268443988($zero)
	li	$t1	,	1
	sub	$t0	,	$t0	,	$t1
	sw	$t0	,	268443988($zero)
	lw	$t0	,	268443988($zero)
	addi	$t0	,	$t0	,	27
	li	$t1	,	4
	mul	$t0	,	$t0	,	$t1
	lw	$t0	,	268435856($t0)
	sw	$t0	,	268443992($zero)
	lw	$t0	,	268443992($zero)
	sw	$t0	,	-12($fp)
$label3:
	lw	$t0	,	0($fp)
	sw	$t0	,	268443996($zero)
	lw	$t0	,	268443996($zero)
	li	$t1	,	2
	sub	$t0	,	$t0	,	$t1
	sw	$t0	,	268443996($zero)
	lw	$t0	,	268443996($zero)
	addi	$t0	,	$t0	,	27
	li	$t1	,	4
	mul	$t0	,	$t0	,	$t1
	lw	$t0	,	268435856($t0)
	sw	$t0	,	268444000($zero)
	lw	$t0	,	268444000($zero)
	sw	$t0	,	-16($fp)
	lw	$t0	,	-12($fp)
	sw	$t0	,	268444004($zero)
	lw	$t0	,	-16($fp)
	sw	$t0	,	268444008($zero)
	lw	$t0	,	268444004($zero)
	lw	$t1	,	268444008($zero)
	add	$t0	,	$t0	,	$t1
	sw	$t0	,	268444004($zero)
	lw	$t0	,	268444004($zero)
	sw	$t0	,	-8($fp)
	lw	$t0	,	0($fp)
	sw	$t0	,	268444012($zero)
	lw	$t0	,	-8($fp)
	sw	$t0	,	268444016($zero)
	lw	$t1	,	268444012($zero)
	addi	$t1	,	$t1	,	27
	li	$t0	,	4
	mul	$t0	,	$t0	,	$t1
	lw	$t1	,	268444016($zero)
	sw	$t1	,	268435856($t0)
	lw	$t0	,	-8($fp)
	sw	$t0	,	268444020($zero)
	lw	$t0	,	268444020($zero)
	add	$v0	,	$t0	,	$zero
	j	_4fib$end
	nop
	j	$label1
	nop
$label0:
	li	$t0	,	4
	li	$t1	,	0
	sub	$t0	,	$t0	,	$t1
	beq	$t0	,	$zero	,	$label4
	nop
	li	$t0	,	1
	sw	$t0	,	268444024($zero)
	li	$t1	,	1
	addi	$t1	,	$t1	,	27
	li	$t0	,	4
	mul	$t0	,	$t0	,	$t1
	lw	$t1	,	268444024($zero)
	sw	$t1	,	268435856($t0)
	li	$t0	,	1
	add	$v0	,	$t0	,	$zero
	j	_4fib$end
	nop
	j	$label5
	nop
$label4:
	li	$t0	,	0
	sw	$t0	,	268444028($zero)
	li	$t1	,	0
	addi	$t1	,	$t1	,	27
	li	$t0	,	4
	mul	$t0	,	$t0	,	$t1
	lw	$t1	,	268444028($zero)
	sw	$t1	,	268435856($t0)
	li	$t0	,	0
	add	$v0	,	$t0	,	$zero
	j	_4fib$end
	nop
$label5:
$label1:
_4fib$end:
	lw	$ra	,	4($sp)
	lw	$fp	,	8($sp)
	addi	$sp	,	$sp	,	28
	jr	$ra
	nop
printstar:
	addi	$sp	,	$sp	,	0
	sw	$fp	,	0($sp)
	sw	$ra	,	-4($sp)
	add	$fp	,	$sp	,	$zero
	addi	$sp	,	$sp	,	-8
	li	$v0	,	4
	la	$a0	,	$Message0
	syscall
	j	printstar$end
	nop
printstar$end:
	lw	$ra	,	4($sp)
	lw	$fp	,	8($sp)
	addi	$sp	,	$sp	,	8
	jr	$ra
	nop
printchar:
	addi	$sp	,	$sp	,	8
	sw	$fp	,	-8($sp)
	sw	$ra	,	-12($sp)
	add	$fp	,	$sp	,	$zero
	addi	$sp	,	$sp	,	-16
	lw	$t0	,	-4($fp)
	sw	$t0	,	268444032($zero)
	lw	$t0	,	268444032($zero)
	li	$t1	,	0
	sub	$t0	,	$t0	,	$t1
	bne	$t0	,	$zero	,	$label6
	nop
	j	printchar$end
	nop
	j	$label7
	nop
$label6:
	lw	$t0	,	0($fp)
	sw	$t0	,	268444036($zero)
	li	$v0	,	11
	lw	$a0	,	268444036($zero)
	syscall
	lw	$t0	,	0($fp)
	sw	$t0	,	268444040($zero)
	lw	$t0	,	268444040($zero)
	sw	$t0	,	0($sp)
	addi	$sp	,	$sp	,	-4
	lw	$t0	,	-4($fp)
	sw	$t0	,	268444044($zero)
	lw	$t0	,	268444044($zero)
	li	$t1	,	1
	sub	$t0	,	$t0	,	$t1
	sw	$t0	,	268444044($zero)
	lw	$t0	,	268444044($zero)
	sw	$t0	,	0($sp)
	addi	$sp	,	$sp	,	-4
	jal	printchar
	nop
$label7:
printchar$end:
	lw	$ra	,	4($sp)
	lw	$fp	,	8($sp)
	addi	$sp	,	$sp	,	16
	jr	$ra
	nop
returnstar:
	addi	$sp	,	$sp	,	0
	sw	$fp	,	0($sp)
	sw	$ra	,	-4($sp)
	add	$fp	,	$sp	,	$zero
	addi	$sp	,	$sp	,	-8
	li	$v0	,	11
	li	$a0	,	42
	syscall
	li	$t0	,	42
	add	$v0	,	$t0	,	$zero
	j	returnstar$end
	nop
returnstar$end:
	lw	$ra	,	4($sp)
	lw	$fp	,	8($sp)
	addi	$sp	,	$sp	,	8
	jr	$ra
	nop
main:
	addi	$sp	,	$sp	,	0
	sw	$fp	,	-64($sp)
	sw	$ra	,	-68($sp)
	li	$t9	,	95
	sw	$t9	,	0($sp)
	add	$fp	,	$sp	,	$zero
	addi	$sp	,	$sp	,	-72
	li	$t0	,	0
	sw	$t0	,	-48($fp)
$label8:
	lw	$t0	,	-48($fp)
	sw	$t0	,	268444048($zero)
	lw	$t0	,	268444048($zero)
	li	$t1	,	999
	sub	$t0	,	$t0	,	$t1
	bgtz	$t0	,	$label9
	nop
	lw	$t0	,	-48($fp)
	sw	$t0	,	268444052($zero)
	lw	$t0	,	-48($fp)
	sw	$t0	,	268444056($zero)
	li	$t0	,	0
	lw	$t1	,	268444056($zero)
	sub	$t0	,	$t0	,	$t1
	sw	$t0	,	268444056($zero)
	lw	$t1	,	268444052($zero)
	addi	$t1	,	$t1	,	27
	li	$t0	,	4
	mul	$t0	,	$t0	,	$t1
	lw	$t1	,	268444056($zero)
	sw	$t1	,	268435856($t0)
	lw	$t0	,	-48($fp)
	sw	$t0	,	268444060($zero)
	lw	$t0	,	268444060($zero)
	li	$t1	,	1
	add	$t0	,	$t0	,	$t1
	sw	$t0	,	268444060($zero)
	lw	$t0	,	268444060($zero)
	sw	$t0	,	-48($fp)
	j	$label8
	nop
$label9:
	li	$t0	,	0
	addi	$t0	,	$t0	,	27
	li	$t1	,	4
	mul	$t0	,	$t0	,	$t1
	lw	$t0	,	268435856($t0)
	sw	$t0	,	268444064($zero)
	li	$v0	,	1
	lw	$a0	,	268444064($zero)
	syscall
	li	$v0	,	11
	li	$a0	,	95
	syscall
	li	$v0	,	4
	la	$a0	,	$Message1
	syscall
	li	$t0	,	0
	addi	$t0	,	$t0	,	27
	li	$t1	,	4
	mul	$t0	,	$t0	,	$t1
	lw	$t0	,	268435856($t0)
	sw	$t0	,	268444068($zero)
	li	$t0	,	0
	lw	$t1	,	268444068($zero)
	sub	$t0	,	$t0	,	$t1
	sw	$t0	,	268444068($zero)
	li	$v0	,	1
	lw	$a0	,	268444068($zero)
	syscall
	li	$v0	,	4
	la	$a0	,	$Message2
	syscall
	li	$t0	,	9
	addi	$t0	,	$t0	,	27
	li	$t1	,	4
	mul	$t0	,	$t0	,	$t1
	lw	$t0	,	268435856($t0)
	sw	$t0	,	268444072($zero)
	li	$v0	,	1
	lw	$a0	,	268444072($zero)
	syscall
	li	$v0	,	4
	la	$a0	,	$Message3
	syscall
	li	$v0	,	1
	li	$a0	,	-5783
	syscall
	li	$v0	,	4
	la	$a0	,	$Message4
	syscall
	li	$v0	,	1
	li	$a0	,	-100
	syscall
	li	$v0	,	4
	la	$a0	,	$Message5
	syscall
	li	$v0	,	1
	li	$a0	,	-23
	syscall
	li	$v0	,	4
	la	$a0	,	$Message6
	syscall
	li	$v0	,	1
	li	$a0	,	-97
	syscall
	li	$v0	,	4
	la	$a0	,	$Message7
	syscall
	li	$t0	,	4
	sw	$t0	,	0($sp)
	addi	$sp	,	$sp	,	-4
	jal	_4fib
	nop
	add	$t0	,	$v0	,	$zero
	sw	$t0	,	268444076($zero)
	lw	$t0	,	268444076($zero)
	sw	$t0	,	0($sp)
	addi	$sp	,	$sp	,	-4
	jal	_4fib
	nop
	add	$t0	,	$v0	,	$zero
	sw	$t0	,	268444080($zero)
	li	$t0	,	0
	lw	$t1	,	268444080($zero)
	sub	$t0	,	$t0	,	$t1
	sw	$t0	,	268444080($zero)
	li	$v0	,	1
	lw	$a0	,	268444080($zero)
	syscall
	li	$v0	,	4
	la	$a0	,	$Message8
	syscall
	li	$v0	,	1
	li	$a0	,	-9506
	syscall
	li	$v0	,	4
	la	$a0	,	$Message9
	syscall
	li	$t0	,	20
	sw	$t0	,	0($sp)
	addi	$sp	,	$sp	,	-4
	jal	_4fib
	nop
	add	$t0	,	$v0	,	$zero
	sw	$t0	,	268444084($zero)
	li	$t0	,	6
	sw	$t0	,	0($sp)
	addi	$sp	,	$sp	,	-4
	jal	_4fib
	nop
	lw	$t0	,	268444084($zero)
	add	$t1	,	$v0	,	$zero
	div	$t0	,	$t1
	mflo	$t0
	sw	$t0	,	268444084($zero)
	li	$v0	,	1
	lw	$a0	,	268444084($zero)
	syscall
	li	$v0	,	4
	la	$a0	,	$Message10
	syscall
	li	$v0	,	1
	li	$a0	,	0
	syscall
	li	$v0	,	4
	la	$a0	,	$Message11
	syscall
	li	$v0	,	1
	li	$a0	,	0
	syscall
	li	$v0	,	4
	la	$a0	,	$Message12
	syscall
	li	$t0	,	20
	sw	$t0	,	0($sp)
	addi	$sp	,	$sp	,	-4
	jal	_4fib
	nop
	add	$t0	,	$v0	,	$zero
	sw	$t0	,	268444088($zero)
	li	$t0	,	6
	sw	$t0	,	0($sp)
	addi	$sp	,	$sp	,	-4
	jal	_4fib
	nop
	lw	$t0	,	268444088($zero)
	add	$t1	,	$v0	,	$zero
	div	$t0	,	$t1
	mflo	$t0
	sw	$t0	,	268444088($zero)
	li	$t0	,	-9506
	lw	$t1	,	268444088($zero)
	add	$t0	,	$t0	,	$t1
	sw	$t0	,	268444088($zero)
	li	$v0	,	1
	lw	$a0	,	268444088($zero)
	syscall
	li	$v0	,	4
	la	$a0	,	$Message13
	syscall
	li	$v0	,	1
	li	$a0	,	0
	syscall
	li	$v0	,	4
	la	$a0	,	$Message14
	syscall
	li	$v0	,	1
	li	$a0	,	-2100
	syscall
	li	$v0	,	4
	la	$a0	,	$Message15
	syscall
	li	$t0	,	9
	addi	$t0	,	$t0	,	27
	li	$t1	,	4
	mul	$t0	,	$t0	,	$t1
	lw	$t0	,	268435856($t0)
	sw	$t0	,	268444092($zero)
	li	$t0	,	0
	lw	$t1	,	268444092($zero)
	add	$t0	,	$t0	,	$t1
	sw	$t0	,	268444092($zero)
	li	$t0	,	-1000
	lw	$t1	,	268444092($zero)
	mul	$t0	,	$t0	,	$t1
	sw	$t0	,	268444092($zero)
	li	$v0	,	1
	lw	$a0	,	268444092($zero)
	syscall
	li	$v0	,	4
	la	$a0	,	$Message16
	syscall
	li	$v0	,	11
	li	$a0	,	97
	syscall
	li	$v0	,	11
	li	$a0	,	95
	syscall
	li	$v0	,	11
	li	$a0	,	65
	syscall
	li	$v0	,	11
	li	$a0	,	45
	syscall
	li	$v0	,	11
	li	$a0	,	42
	syscall
	li	$v0	,	11
	li	$a0	,	48
	syscall
	li	$v0	,	4
	la	$a0	,	$Message17
	syscall
	li	$t0	,	3
	sw	$t0	,	-44($fp)
	lw	$t0	,	-44($fp)
	sw	$t0	,	268444096($zero)
	lw	$t0	,	268444096($zero)
	sw	$t0	,	-48($fp)
$label10:
	lw	$t0	,	-48($fp)
	sw	$t0	,	268444100($zero)
	lw	$t0	,	268444100($zero)
	li	$t1	,	0
	sub	$t0	,	$t0	,	$t1
	beq	$t0	,	$zero	,	$label11
	nop
	jal	printstar
	nop
	lw	$t0	,	-48($fp)
	sw	$t0	,	268444104($zero)
	lw	$t0	,	268444104($zero)
	li	$t1	,	1
	sub	$t0	,	$t0	,	$t1
	sw	$t0	,	268444104($zero)
	lw	$t0	,	268444104($zero)
	sw	$t0	,	-48($fp)
	j	$label10
	nop
$label11:
	li	$v0	,	4
	la	$a0	,	$Message18
	syscall
	li	$v0	,	5
	syscall
	add	$t0	,	$v0	,	$zero
	sw	$t0	,	-52($fp)
	li	$v0	,	12
	syscall
	add	$t0	,	$v0	,	$zero
	sw	$t0	,	-60($fp)
	lw	$t0	,	-60($fp)
	sw	$t0	,	268444108($zero)
	lw	$t0	,	268444108($zero)
	sw	$t0	,	0($sp)
	addi	$sp	,	$sp	,	-4
	lw	$t0	,	-44($fp)
	sw	$t0	,	268444112($zero)
	lw	$t0	,	268444112($zero)
	sw	$t0	,	0($sp)
	addi	$sp	,	$sp	,	-4
	jal	printchar
	nop
	li	$v0	,	4
	la	$a0	,	$Message19
	syscall
	lw	$t0	,	-52($fp)
	sw	$t0	,	268444116($zero)
	lw	$t0	,	268444116($zero)
	li	$t1	,	2
	sub	$t0	,	$t0	,	$t1
	bgez	$t0	,	$label12
	nop
	li	$v0	,	4
	la	$a0	,	$Message20
	syscall
	j	$label13
	nop
$label12:
	lw	$t0	,	-52($fp)
	sw	$t0	,	268444120($zero)
	lw	$t0	,	268444120($zero)
	li	$t1	,	45
	sub	$t0	,	$t0	,	$t1
	blez	$t0	,	$label14
	nop
	li	$v0	,	4
	la	$a0	,	$Message21
	syscall
	j	$label15
	nop
$label14:
	lw	$t0	,	-52($fp)
	sw	$t0	,	268444124($zero)
	lw	$t0	,	268444124($zero)
	sw	$t0	,	0($sp)
	addi	$sp	,	$sp	,	-4
	jal	_4fib
	nop
	li	$v0	,	4
	la	$a0	,	$Message22
	syscall
$label16:
	lw	$t0	,	-52($fp)
	sw	$t0	,	268444128($zero)
	lw	$t0	,	268444128($zero)
	li	$t1	,	0
	sub	$t0	,	$t0	,	$t1
	bltz	$t0	,	$label17
	nop
	li	$v0	,	4
	la	$a0	,	$Message23
	syscall
	lw	$t0	,	-52($fp)
	sw	$t0	,	268444132($zero)
	li	$v0	,	1
	lw	$a0	,	268444132($zero)
	syscall
	li	$v0	,	4
	la	$a0	,	$Message24
	syscall
	lw	$t0	,	-52($fp)
	sw	$t0	,	268444136($zero)
	lw	$t0	,	268444136($zero)
	addi	$t0	,	$t0	,	27
	li	$t1	,	4
	mul	$t0	,	$t0	,	$t1
	lw	$t0	,	268435856($t0)
	sw	$t0	,	268444140($zero)
	li	$t0	,	0
	lw	$t1	,	268444140($zero)
	sub	$t0	,	$t0	,	$t1
	sw	$t0	,	268444140($zero)
	li	$t0	,	0
	lw	$t1	,	268444140($zero)
	sub	$t0	,	$t0	,	$t1
	sw	$t0	,	268444140($zero)
	li	$v0	,	1
	lw	$a0	,	268444140($zero)
	syscall
	li	$v0	,	4
	la	$a0	,	$Message25
	syscall
	lw	$t0	,	-52($fp)
	sw	$t0	,	268444144($zero)
	lw	$t0	,	268444144($zero)
	li	$t1	,	1
	sub	$t0	,	$t0	,	$t1
	sw	$t0	,	268444144($zero)
	lw	$t0	,	268444144($zero)
	sw	$t0	,	-52($fp)
	j	$label16
	nop
$label17:
$label15:
$label13:
	li	$v0	,	4
	la	$a0	,	$Message26
	syscall
	lw	$t0	,	-44($fp)
	sw	$t0	,	268444148($zero)
	lw	$t0	,	268444148($zero)
	sw	$t0	,	-48($fp)
$label18:
	lw	$t0	,	-48($fp)
	sw	$t0	,	268444152($zero)
	lw	$t0	,	268444152($zero)
	li	$t1	,	0
	sub	$t0	,	$t0	,	$t1
	beq	$t0	,	$zero	,	$label19
	nop
	jal	returnstar
	nop
	jal	returnstar
	nop
	add	$t0	,	$v0	,	$zero
	sw	$t0	,	268444156($zero)
	li	$v0	,	11
	lw	$a0	,	268444156($zero)
	syscall
	lw	$t0	,	-48($fp)
	sw	$t0	,	268444160($zero)
	lw	$t0	,	268444160($zero)
	li	$t1	,	1
	sub	$t0	,	$t0	,	$t1
	sw	$t0	,	268444160($zero)
	lw	$t0	,	268444160($zero)
	sw	$t0	,	-48($fp)
	j	$label18
	nop
$label19:
	li	$v0	,	4
	la	$a0	,	$Message27
	syscall
	li	$v0	,	5
	syscall
	add	$t0	,	$v0	,	$zero
	sw	$t0	,	-52($fp)
	lw	$t0	,	-52($fp)
	sw	$t0	,	268444164($zero)
	li	$t0	,	0
	sw	$t0	,	268444168($zero)
	lw	$t0	,	268444168($zero)
	lw	$t1	,	268444164($zero)
	sub	$t0	,	$t0	,	$t1
	bne	$t0	,	$zero	,	$label21
	nop
	li	$v0	,	1
	li	$a0	,	0
	syscall
	j	$label20
	nop
$label21:
	li	$t0	,	1
	sw	$t0	,	268444172($zero)
	lw	$t0	,	268444172($zero)
	lw	$t1	,	268444164($zero)
	sub	$t0	,	$t0	,	$t1
	bne	$t0	,	$zero	,	$label22
	nop
	li	$v0	,	1
	li	$a0	,	1
	syscall
	j	$label20
	nop
$label22:
	li	$t0	,	2
	sw	$t0	,	268444176($zero)
	lw	$t0	,	268444176($zero)
	lw	$t1	,	268444164($zero)
	sub	$t0	,	$t0	,	$t1
	bne	$t0	,	$zero	,	$label23
	nop
	li	$v0	,	1
	li	$a0	,	2
	syscall
	j	$label20
	nop
$label23:
	li	$t0	,	3
	sw	$t0	,	268444180($zero)
	lw	$t0	,	268444180($zero)
	lw	$t1	,	268444164($zero)
	sub	$t0	,	$t0	,	$t1
	bne	$t0	,	$zero	,	$label24
	nop
	li	$v0	,	1
	li	$a0	,	3
	syscall
	j	$label20
	nop
$label24:
	li	$t0	,	4
	sw	$t0	,	268444184($zero)
	lw	$t0	,	268444184($zero)
	lw	$t1	,	268444164($zero)
	sub	$t0	,	$t0	,	$t1
	bne	$t0	,	$zero	,	$label25
	nop
	li	$v0	,	1
	li	$a0	,	4
	syscall
	j	$label20
	nop
$label25:
	li	$t0	,	5
	sw	$t0	,	268444188($zero)
	lw	$t0	,	268444188($zero)
	lw	$t1	,	268444164($zero)
	sub	$t0	,	$t0	,	$t1
	bne	$t0	,	$zero	,	$label26
	nop
	li	$v0	,	1
	li	$a0	,	5
	syscall
	j	$label20
	nop
$label26:
	li	$t0	,	6
	sw	$t0	,	268444192($zero)
	lw	$t0	,	268444192($zero)
	lw	$t1	,	268444164($zero)
	sub	$t0	,	$t0	,	$t1
	bne	$t0	,	$zero	,	$label27
	nop
	li	$v0	,	1
	li	$a0	,	6
	syscall
	j	$label20
	nop
$label27:
	li	$t0	,	7
	sw	$t0	,	268444196($zero)
	lw	$t0	,	268444196($zero)
	lw	$t1	,	268444164($zero)
	sub	$t0	,	$t0	,	$t1
	bne	$t0	,	$zero	,	$label28
	nop
	li	$v0	,	1
	li	$a0	,	7
	syscall
	j	$label20
	nop
$label28:
	li	$t0	,	8
	sw	$t0	,	268444200($zero)
	lw	$t0	,	268444200($zero)
	lw	$t1	,	268444164($zero)
	sub	$t0	,	$t0	,	$t1
	bne	$t0	,	$zero	,	$label29
	nop
	li	$v0	,	1
	li	$a0	,	8
	syscall
	j	$label20
	nop
$label29:
	li	$t0	,	9
	sw	$t0	,	268444204($zero)
	lw	$t0	,	268444204($zero)
	lw	$t1	,	268444164($zero)
	sub	$t0	,	$t0	,	$t1
	bne	$t0	,	$zero	,	$label30
	nop
	li	$v0	,	1
	li	$a0	,	9
	syscall
	j	$label20
	nop
$label30:
	li	$v0	,	4
	la	$a0	,	$Message28
	syscall
$label20:
	li	$v0	,	4
	la	$a0	,	$Message29
	syscall
	li	$v0	,	10
	syscall
