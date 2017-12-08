	.data
#³õÊ¼»¯×Ö·û´®
$Message0:	.asciiz	"*"
$Message1:	.asciiz	" "
$Message2:	.asciiz	" "
$Message3:	.asciiz	" "
$Message4:	.asciiz	" "
$Message5:	.asciiz	" "
$Message6:	.asciiz	" "
$Message7:	.asciiz	" "
$Message8:	.asciiz	" "
$Message9:	.asciiz	" "
$Message10:	.asciiz	" "
$Message11:	.asciiz	" "
$Message12:	.asciiz	" "
$Message13:	.asciiz	" "
$Message14:	.asciiz	" "
$Message15:	.asciiz	" "
$Message16:	.asciiz	" "
$Message17:	.asciiz	"  "
$Message18:	.asciiz	"  "
$Message19:	.asciiz	"  "
$Message20:	.asciiz	"num is less than 2!"
$Message21:	.asciiz	"num is more than 45!"
$Message22:	.asciiz	"the fib is : "
$Message23:	.asciiz	"no."
$Message24:	.asciiz	" is "
$Message25:	.asciiz	" "
$Message26:	.asciiz	"  "
$Message27:	.asciiz	"please input a number from 0 to 4: "
$Message28:	.asciiz	"out of range!"
	.text
	li	$t0	,	95
	sw	$t0	,	1000($zero)
	li	$t0	,	43
	sw	$t0	,	1004($zero)
	li	$t0	,	45
	sw	$t0	,	1008($zero)
	li	$t0	,	42
	sw	$t0	,	1012($zero)
	li	$t0	,	47
	sw	$t0	,	1016($zero)
	li	$t0	,	97
	sw	$t0	,	1020($zero)
	li	$t0	,	48
	sw	$t0	,	1024($zero)
	li	$t0	,	0
	sw	$t0	,	1028($zero)
	li	$t0	,	4
	sw	$t0	,	1032($zero)
	li	$t0	,	3
	sw	$t0	,	1036($zero)
	li	$t0	,	-9
	sw	$t0	,	1040($zero)
	li	$t0	,	20
	sw	$t0	,	1044($zero)
	li	$t0	,	56
	sw	$t0	,	1048($zero)
	li	$t0	,	-78
	sw	$t0	,	1052($zero)
	li	$t0	,	5783
	sw	$t0	,	1056($zero)
	li	$t0	,	326
	sw	$t0	,	1060($zero)
	li	$t0	,	-111
	sw	$t0	,	1064($zero)
	li	$t0	,	0
	sw	$t0	,	1068($zero)
	li	$t0	,	100
	sw	$t0	,	1072($zero)
	li	$t0	,	-1000
	sw	$t0	,	1076($zero)
	li	$t0	,	97
	sw	$t0	,	1080($zero)
	li	$t0	,	95
	sw	$t0	,	1084($zero)
	li	$t0	,	65
	sw	$t0	,	1088($zero)
	li	$t0	,	45
	sw	$t0	,	1092($zero)
	li	$t0	,	42
	sw	$t0	,	1096($zero)
	li	$t0	,	48
	sw	$t0	,	1100($zero)
	add	$fp	,	$sp	,	$zero
	j	main
	nop
_4fib:
	addi	$sp	,	$sp	,	4
	sw	$fp	,	-20($sp)
	sw	$ra	,	-24($sp)
	li	$t0	,	95
	sw	$t0	,	-4($sp)
	add	$fp	,	$sp	,	$zero
	addi	$sp	,	$sp	,	-28
	lw	$t0	,	0($fp)
	sw	$t0	,	9112($zero)
	lw	$t0	,	9112($zero)
	sub	$t0	,	$zero	,	$t0
	sw	$t0	,	9112($zero)
	li	$t0	,	1
	sw	$t0	,	9116($zero)
	lw	$t0	,	9116($zero)
	sub	$t0	,	$zero	,	$t0
	sw	$t0	,	9116($zero)
	lw	$t0	,	9112($zero)
	lw	$t1	,	9116($zero)
	sub	$t0	,	$t0	,	$t1
	bgez	$t0	,	$label0
	nop
	lw	$t0	,	0($fp)
	sw	$t0	,	9120($zero)
	li	$t0	,	1
	sw	$t0	,	9124($zero)
	lw	$t0	,	9120($zero)
	lw	$t1	,	9124($zero)
	sub	$t0	,	$t0	,	$t1
	sw	$t0	,	9120($zero)
	lw	$t0	,	9120($zero)
	addi	$t0	,	$t0	,	27
	li	$t1	,	4
	mul	$t0	,	$t0	,	$t1
	lw	$t0	,	1000($t0)
	sw	$t0	,	9128($zero)
	lw	$t0	,	9128($zero)
	sw	$t0	,	9132($zero)
	li	$t0	,	1
	sw	$t0	,	9136($zero)
	lw	$t0	,	9136($zero)
	sub	$t0	,	$zero	,	$t0
	sw	$t0	,	9136($zero)
	lw	$t0	,	9132($zero)
	lw	$t1	,	9136($zero)
	sub	$t0	,	$t0	,	$t1
	bgtz	$t0	,	$label2
	nop
	lw	$t0	,	0($fp)
	sw	$t0	,	9140($zero)
	li	$t0	,	1
	sw	$t0	,	9144($zero)
	lw	$t0	,	9140($zero)
	lw	$t1	,	9144($zero)
	sub	$t0	,	$t0	,	$t1
	sw	$t0	,	9140($zero)
	lw	$t0	,	9140($zero)
	sw	$t0	,	0($sp)
	addi	$sp	,	$sp	,	-4
	jal	_4fib
	nop
	add	$t0	,	$v0	,	$zero
	sw	$t0	,	9148($zero)
	lw	$t0	,	9148($zero)
	sw	$t0	,	-12($fp)
	j	$label3
	nop
$label2:
	lw	$t0	,	0($fp)
	sw	$t0	,	9152($zero)
	li	$t0	,	1
	sw	$t0	,	9156($zero)
	lw	$t0	,	9152($zero)
	lw	$t1	,	9156($zero)
	sub	$t0	,	$t0	,	$t1
	sw	$t0	,	9152($zero)
	lw	$t0	,	9152($zero)
	addi	$t0	,	$t0	,	27
	li	$t1	,	4
	mul	$t0	,	$t0	,	$t1
	lw	$t0	,	1000($t0)
	sw	$t0	,	9160($zero)
	lw	$t0	,	9160($zero)
	sw	$t0	,	9164($zero)
	lw	$t0	,	9164($zero)
	sw	$t0	,	-12($fp)
$label3:
	lw	$t0	,	0($fp)
	sw	$t0	,	9168($zero)
	li	$t0	,	2
	sw	$t0	,	9172($zero)
	lw	$t0	,	9168($zero)
	lw	$t1	,	9172($zero)
	sub	$t0	,	$t0	,	$t1
	sw	$t0	,	9168($zero)
	lw	$t0	,	9168($zero)
	addi	$t0	,	$t0	,	27
	li	$t1	,	4
	mul	$t0	,	$t0	,	$t1
	lw	$t0	,	1000($t0)
	sw	$t0	,	9176($zero)
	lw	$t0	,	9176($zero)
	sw	$t0	,	9180($zero)
	lw	$t0	,	9180($zero)
	sw	$t0	,	-16($fp)
	lw	$t0	,	-12($fp)
	sw	$t0	,	9184($zero)
	lw	$t0	,	-16($fp)
	sw	$t0	,	9188($zero)
	lw	$t0	,	9184($zero)
	lw	$t1	,	9188($zero)
	add	$t0	,	$t0	,	$t1
	sw	$t0	,	9184($zero)
	lw	$t0	,	9184($zero)
	sw	$t0	,	-8($fp)
	lw	$t0	,	0($fp)
	sw	$t0	,	9192($zero)
	lw	$t0	,	-8($fp)
	sw	$t0	,	9196($zero)
	lw	$t1	,	9192($zero)
	addi	$t1	,	$t1	,	27
	li	$t0	,	4
	mul	$t0	,	$t0	,	$t1
	lw	$t1	,	9196($zero)
	sw	$t1	,	1000($t0)
	lw	$t0	,	-8($fp)
	sw	$t0	,	9200($zero)
	lw	$t0	,	9200($zero)
	add	$v0	,	$t0	,	$zero
	j	$label1
	nop
$label0:
	lw	$t0	,	1032($zero)
	sw	$t0	,	9204($zero)
	lw	$t0	,	9204($zero)
	li	$t1	,	0
	sub	$t0	,	$t0	,	$t1
	beq	$t0	,	$zero	,	$label4
	nop
	li	$t0	,	1
	sw	$t0	,	9208($zero)
	li	$t0	,	1
	sw	$t0	,	9212($zero)
	lw	$t1	,	9208($zero)
	addi	$t1	,	$t1	,	27
	li	$t0	,	4
	mul	$t0	,	$t0	,	$t1
	lw	$t1	,	9212($zero)
	sw	$t1	,	1000($t0)
	li	$t0	,	1
	sw	$t0	,	9216($zero)
	lw	$t0	,	9216($zero)
	add	$v0	,	$t0	,	$zero
	j	$label5
	nop
$label4:
	li	$t0	,	0
	sw	$t0	,	9220($zero)
	li	$t0	,	0
	sw	$t0	,	9224($zero)
	lw	$t1	,	9220($zero)
	addi	$t1	,	$t1	,	27
	li	$t0	,	4
	mul	$t0	,	$t0	,	$t1
	lw	$t1	,	9224($zero)
	sw	$t1	,	1000($t0)
	li	$t0	,	0
	sw	$t0	,	9228($zero)
	lw	$t0	,	9228($zero)
	sub	$t0	,	$zero	,	$t0
	sw	$t0	,	9228($zero)
	lw	$t0	,	9228($zero)
	add	$v0	,	$t0	,	$zero
$label5:
$label1:
	lw	$ra	,	4($sp)
	lw	$fp	,	8($sp)
	addi	$sp	,	$sp	,	28
	jr	$ra
	nop
printStar:
	addi	$sp	,	$sp	,	0
	sw	$fp	,	0($sp)
	sw	$ra	,	-4($sp)
	add	$fp	,	$sp	,	$zero
	addi	$sp	,	$sp	,	-8
	li	$v0	,		,	4
	la	$a0	,	$Message0
	syscall
	lw	$ra	,	4($sp)
	lw	$fp	,	8($sp)
	addi	$sp	,	$sp	,	8
	jr	$ra
	nop
printChar:
	addi	$sp	,	$sp	,	8
	sw	$fp	,	-8($sp)
	sw	$ra	,	-12($sp)
	add	$fp	,	$sp	,	$zero
	addi	$sp	,	$sp	,	-16
	lw	$t0	,	-4($fp)
	sw	$t0	,	9232($zero)
	li	$t0	,	0
	sw	$t0	,	9236($zero)
	lw	$t0	,	9232($zero)
	lw	$t1	,	9236($zero)
	sub	$t0	,	$t0	,	$t1
	bne	$t0	,	$zero	,	$label6
	nop
	j	$label7
	nop
$label6:
	lw	$t0	,	0($fp)
	sw	$t0	,	9240($zero)
	li	$v0	,	11
	lw	$a0	,	9240($zero)
	syscall
	lw	$t0	,	0($fp)
	sw	$t0	,	9244($zero)
	lw	$t0	,	9244($zero)
	sw	$t0	,	0($sp)
	addi	$sp	,	$sp	,	-4
	lw	$t0	,	-4($fp)
	sw	$t0	,	9248($zero)
	li	$t0	,	1
	sw	$t0	,	9252($zero)
	lw	$t0	,	9248($zero)
	lw	$t1	,	9252($zero)
	sub	$t0	,	$t0	,	$t1
	sw	$t0	,	9248($zero)
	lw	$t0	,	9248($zero)
	sw	$t0	,	0($sp)
	addi	$sp	,	$sp	,	-4
	jal	printChar
	nop
$label7:
	lw	$ra	,	4($sp)
	lw	$fp	,	8($sp)
	addi	$sp	,	$sp	,	16
	jr	$ra
	nop
returnStar:
	addi	$sp	,	$sp	,	0
	sw	$fp	,	0($sp)
	sw	$ra	,	-4($sp)
	add	$fp	,	$sp	,	$zero
	addi	$sp	,	$sp	,	-8
	li	$t0	,	42
	sw	$t0	,	9256($zero)
	li	$v0	,	11
	lw	$a0	,	9256($zero)
	syscall
	li	$t0	,	42
	sw	$t0	,	9260($zero)
	lw	$t0	,	9260($zero)
	add	$v0	,	$t0	,	$zero
	lw	$ra	,	4($sp)
	lw	$fp	,	8($sp)
	addi	$sp	,	$sp	,	8
	jr	$ra
	nop
main:
	addi	$sp	,	$sp	,	0
	sw	$fp	,	-64($sp)
	sw	$ra	,	-68($sp)
	li	$t0	,	95
	sw	$t0	,	0($sp)
	add	$fp	,	$sp	,	$zero
	addi	$sp	,	$sp	,	-72
	li	$t0	,	0
	sw	$t0	,	9264($zero)
	lw	$t0	,	9264($zero)
	sw	$t0	,	-48($fp)
$label8:
	lw	$t0	,	-48($fp)
	sw	$t0	,	9268($zero)
	li	$t0	,	999
	sw	$t0	,	9272($zero)
	lw	$t0	,	9268($zero)
	lw	$t1	,	9272($zero)
	sub	$t0	,	$t0	,	$t1
	bgtz	$t0	,	$label9
	nop
	lw	$t0	,	-48($fp)
	sw	$t0	,	9276($zero)
	lw	$t0	,	-48($fp)
	sw	$t0	,	9280($zero)
	lw	$t0	,	9280($zero)
	sub	$t0	,	$zero	,	$t0
	sw	$t0	,	9280($zero)
	lw	$t1	,	9276($zero)
	addi	$t1	,	$t1	,	27
	li	$t0	,	4
	mul	$t0	,	$t0	,	$t1
	lw	$t1	,	9280($zero)
	sw	$t1	,	1000($t0)
	lw	$t0	,	-48($fp)
	sw	$t0	,	9284($zero)
	li	$t0	,	1
	sw	$t0	,	9288($zero)
	lw	$t0	,	9284($zero)
	lw	$t1	,	9288($zero)
	add	$t0	,	$t0	,	$t1
	sw	$t0	,	9284($zero)
	lw	$t0	,	9284($zero)
	sw	$t0	,	-48($fp)
	j	$label8
	nop
$label9:
	lw	$t0	,	1000($zero)
	sw	$t0	,	9292($zero)
	li	$v0	,	11
	lw	$a0	,	9292($zero)
	syscall
	li	$v0	,		,	4
	la	$a0	,	$Message1
	syscall
	lw	$t0	,	1028($zero)
	sw	$t0	,	9296($zero)
	lw	$t0	,	9296($zero)
	addi	$t0	,	$t0	,	27
	li	$t1	,	4
	mul	$t0	,	$t0	,	$t1
	lw	$t0	,	1000($t0)
	sw	$t0	,	9300($zero)
	lw	$t0	,	9300($zero)
	sw	$t0	,	9304($zero)
	lw	$t0	,	9304($zero)
	sub	$t0	,	$zero	,	$t0
	sw	$t0	,	9304($zero)
	li	$v0	,	1
	lw	$a0	,	9304($zero)
	syscall
	li	$v0	,		,	4
	la	$a0	,	$Message2
	syscall
	li	$t0	,	-9
	sw	$t0	,	9308($zero)
	lw	$t0	,	9308($zero)
	sub	$t0	,	$zero	,	$t0
	sw	$t0	,	9308($zero)
	lw	$t0	,	9308($zero)
	addi	$t0	,	$t0	,	27
	li	$t1	,	4
	mul	$t0	,	$t0	,	$t1
	lw	$t0	,	1000($t0)
	sw	$t0	,	9312($zero)
	lw	$t0	,	9312($zero)
	sw	$t0	,	9316($zero)
	li	$v0	,	1
	lw	$a0	,	9316($zero)
	syscall
	li	$v0	,		,	4
	la	$a0	,	$Message3
	syscall
	lw	$t0	,	1056($zero)
	sw	$t0	,	9320($zero)
	lw	$t0	,	9320($zero)
	sub	$t0	,	$zero	,	$t0
	sw	$t0	,	9320($zero)
	lw	$t0	,	9320($zero)
	sw	$t0	,	9324($zero)
	li	$v0	,	1
	lw	$a0	,	9324($zero)
	syscall
	li	$v0	,		,	4
	la	$a0	,	$Message4
	syscall
	li	$t0	,	100
	sw	$t0	,	9328($zero)
	lw	$t0	,	9328($zero)
	sw	$t0	,	9332($zero)
	lw	$t0	,	9332($zero)
	sub	$t0	,	$zero	,	$t0
	sw	$t0	,	9332($zero)
	li	$v0	,	1
	lw	$a0	,	9332($zero)
	syscall
	li	$v0	,		,	4
	la	$a0	,	$Message5
	syscall
	li	$t0	,	23
	sw	$t0	,	9336($zero)
	lw	$t0	,	9336($zero)
	sub	$t0	,	$zero	,	$t0
	sw	$t0	,	9336($zero)
	li	$v0	,	1
	lw	$a0	,	9336($zero)
	syscall
	li	$v0	,		,	4
	la	$a0	,	$Message6
	syscall
	li	$t0	,	97
	sw	$t0	,	9340($zero)
	lw	$t0	,	9340($zero)
	sub	$t0	,	$zero	,	$t0
	sw	$t0	,	9340($zero)
	li	$v0	,	1
	lw	$a0	,	9340($zero)
	syscall
	li	$v0	,		,	4
	la	$a0	,	$Message7
	syscall
	lw	$t0	,	1032($zero)
	sw	$t0	,	9344($zero)
	lw	$t0	,	9344($zero)
	sw	$t0	,	0($sp)
	addi	$sp	,	$sp	,	-4
	jal	_4fib
	nop
	add	$t0	,	$v0	,	$zero
	sw	$t0	,	9348($zero)
	lw	$t0	,	9348($zero)
	sw	$t0	,	0($sp)
	addi	$sp	,	$sp	,	-4
	jal	_4fib
	nop
	add	$t0	,	$v0	,	$zero
	sw	$t0	,	9352($zero)
	lw	$t0	,	9352($zero)
	sub	$t0	,	$zero	,	$t0
	sw	$t0	,	9352($zero)
	li	$v0	,	1
	lw	$a0	,	9352($zero)
	syscall
	li	$v0	,		,	4
	la	$a0	,	$Message8
	syscall
	li	$t0	,	97
	sw	$t0	,	9356($zero)
	lw	$t0	,	9356($zero)
	sub	$t0	,	$zero	,	$t0
	sw	$t0	,	9356($zero)
	lw	$t0	,	9356($zero)
	sw	$t0	,	9360($zero)
	li	$t0	,	98
	sw	$t0	,	9364($zero)
	lw	$t0	,	9360($zero)
	lw	$t1	,	9364($zero)
	mul	$t0	,	$t0	,	$t1
	sw	$t0	,	9360($zero)
	li	$v0	,	1
	lw	$a0	,	9360($zero)
	syscall
	li	$v0	,		,	4
	la	$a0	,	$Message9
	syscall
	lw	$t0	,	1044($zero)
	sw	$t0	,	9368($zero)
	lw	$t0	,	9368($zero)
	sw	$t0	,	0($sp)
	addi	$sp	,	$sp	,	-4
	jal	_4fib
	nop
	add	$t0	,	$v0	,	$zero
	sw	$t0	,	9372($zero)
	li	$t0	,	6
	sw	$t0	,	9376($zero)
	lw	$t0	,	9376($zero)
	sw	$t0	,	0($sp)
	addi	$sp	,	$sp	,	-4
	jal	_4fib
	nop
	lw	$t0	,	9372($zero)
	add	$t1	,	$v0	,	$zero
	div	$t0	,	$t1
	mflo	$t0
	sw	$t0	,	9372($zero)
	li	$v0	,	1
	lw	$a0	,	9372($zero)
	syscall
	li	$v0	,		,	4
	la	$a0	,	$Message10
	syscall
	lw	$t0	,	1068($zero)
	sw	$t0	,	9380($zero)
	lw	$t0	,	9380($zero)
	lw	$t1	,	1072($zero)
	mul	$t0	,	$t0	,	$t1
	sw	$t0	,	9380($zero)
	li	$v0	,	1
	lw	$a0	,	9380($zero)
	syscall
	li	$v0	,		,	4
	la	$a0	,	$Message11
	syscall
	lw	$t0	,	1068($zero)
	sw	$t0	,	9384($zero)
	lw	$t0	,	9384($zero)
	lw	$t1	,	1072($zero)
	div	$t0	,	$t1
	mflo	$t0
	sw	$t0	,	9384($zero)
	li	$v0	,	1
	lw	$a0	,	9384($zero)
	syscall
	li	$v0	,		,	4
	la	$a0	,	$Message12
	syscall
	li	$t0	,	97
	sw	$t0	,	9388($zero)
	lw	$t0	,	9388($zero)
	sub	$t0	,	$zero	,	$t0
	sw	$t0	,	9388($zero)
	lw	$t0	,	9388($zero)
	sw	$t0	,	9392($zero)
	li	$t0	,	98
	sw	$t0	,	9396($zero)
	lw	$t0	,	9392($zero)
	lw	$t1	,	9396($zero)
	mul	$t0	,	$t0	,	$t1
	sw	$t0	,	9392($zero)
	lw	$t0	,	1044($zero)
	sw	$t0	,	9400($zero)
	lw	$t0	,	9400($zero)
	sw	$t0	,	0($sp)
	addi	$sp	,	$sp	,	-4
	jal	_4fib
	nop
	add	$t0	,	$v0	,	$zero
	sw	$t0	,	9404($zero)
	li	$t0	,	6
	sw	$t0	,	9408($zero)
	lw	$t0	,	9408($zero)
	sw	$t0	,	0($sp)
	addi	$sp	,	$sp	,	-4
	jal	_4fib
	nop
	lw	$t0	,	9404($zero)
	add	$t1	,	$v0	,	$zero
	div	$t0	,	$t1
	mflo	$t0
	sw	$t0	,	9404($zero)
	lw	$t0	,	9392($zero)
	lw	$t1	,	9404($zero)
	add	$t0	,	$t0	,	$t1
	sw	$t0	,	9392($zero)
	li	$v0	,	1
	lw	$a0	,	9392($zero)
	syscall
	li	$v0	,		,	4
	la	$a0	,	$Message13
	syscall
	lw	$t0	,	1068($zero)
	sw	$t0	,	9412($zero)
	lw	$t0	,	9412($zero)
	lw	$t1	,	1072($zero)
	mul	$t0	,	$t0	,	$t1
	sw	$t0	,	9412($zero)
	lw	$t0	,	1068($zero)
	sw	$t0	,	9416($zero)
	lw	$t0	,	9416($zero)
	lw	$t1	,	1072($zero)
	div	$t0	,	$t1
	mflo	$t0
	sw	$t0	,	9416($zero)
	lw	$t0	,	9412($zero)
	lw	$t1	,	9416($zero)
	sub	$t0	,	$t0	,	$t1
	sw	$t0	,	9412($zero)
	li	$v0	,	1
	lw	$a0	,	9412($zero)
	syscall
	li	$v0	,		,	4
	la	$a0	,	$Message14
	syscall
	lw	$t0	,	1072($zero)
	sw	$t0	,	9420($zero)
	lw	$t0	,	9420($zero)
	sub	$t0	,	$zero	,	$t0
	sw	$t0	,	9420($zero)
	lw	$t0	,	1076($zero)
	sw	$t0	,	9424($zero)
	lw	$t0	,	1076($zero)
	sw	$t0	,	9428($zero)
	lw	$t0	,	9424($zero)
	lw	$t1	,	9428($zero)
	add	$t0	,	$t0	,	$t1
	sw	$t0	,	9424($zero)
	lw	$t0	,	9424($zero)
	sw	$t0	,	9432($zero)
	lw	$t0	,	9420($zero)
	lw	$t1	,	9432($zero)
	add	$t0	,	$t0	,	$t1
	sw	$t0	,	9420($zero)
	li	$v0	,	1
	lw	$a0	,	9420($zero)
	syscall
	li	$v0	,		,	4
	la	$a0	,	$Message15
	syscall
	lw	$t0	,	1076($zero)
	sw	$t0	,	9436($zero)
	lw	$t0	,	1068($zero)
	sw	$t0	,	9440($zero)
	li	$t0	,	-9
	sw	$t0	,	9444($zero)
	lw	$t0	,	9444($zero)
	sub	$t0	,	$zero	,	$t0
	sw	$t0	,	9444($zero)
	lw	$t0	,	9444($zero)
	addi	$t0	,	$t0	,	27
	li	$t1	,	4
	mul	$t0	,	$t0	,	$t1
	lw	$t0	,	1000($t0)
	sw	$t0	,	9448($zero)
	lw	$t0	,	9448($zero)
	sw	$t0	,	9452($zero)
	lw	$t0	,	9440($zero)
	lw	$t1	,	9452($zero)
	add	$t0	,	$t0	,	$t1
	sw	$t0	,	9440($zero)
	lw	$t0	,	9436($zero)
	lw	$t1	,	9440($zero)
	mul	$t0	,	$t0	,	$t1
	sw	$t0	,	9436($zero)
	li	$v0	,	1
	lw	$a0	,	9436($zero)
	syscall
	li	$v0	,		,	4
	la	$a0	,	$Message16
	syscall
	lw	$t0	,	1080($zero)
	sw	$t0	,	9456($zero)
	li	$v0	,	11
	lw	$a0	,	9456($zero)
	syscall
	lw	$t0	,	1084($zero)
	sw	$t0	,	9460($zero)
	li	$v0	,	11
	lw	$a0	,	9460($zero)
	syscall
	lw	$t0	,	1088($zero)
	sw	$t0	,	9464($zero)
	li	$v0	,	11
	lw	$a0	,	9464($zero)
	syscall
	lw	$t0	,	1092($zero)
	sw	$t0	,	9468($zero)
	li	$v0	,	11
	lw	$a0	,	9468($zero)
	syscall
	lw	$t0	,	1096($zero)
	sw	$t0	,	9472($zero)
	li	$v0	,	11
	lw	$a0	,	9472($zero)
	syscall
	lw	$t0	,	1100($zero)
	sw	$t0	,	9476($zero)
	li	$v0	,	11
	lw	$a0	,	9476($zero)
	syscall
	li	$v0	,		,	4
	la	$a0	,	$Message17
	syscall
	li	$t0	,	3
	sw	$t0	,	9480($zero)
	lw	$t0	,	9480($zero)
	sw	$t0	,	-44($fp)
	lw	$t0	,	-44($fp)
	sw	$t0	,	9484($zero)
	lw	$t0	,	9484($zero)
	sw	$t0	,	-48($fp)
$label10:
	lw	$t0	,	-48($fp)
	sw	$t0	,	9488($zero)
	lw	$t0	,	9488($zero)
	li	$t1	,	0
	sub	$t0	,	$t0	,	$t1
	beq	$t0	,	$zero	,	$label11
	nop
	jal	printStar
	nop
	lw	$t0	,	-48($fp)
	sw	$t0	,	9492($zero)
	li	$t0	,	1
	sw	$t0	,	9496($zero)
	lw	$t0	,	9492($zero)
	lw	$t1	,	9496($zero)
	sub	$t0	,	$t0	,	$t1
	sw	$t0	,	9492($zero)
	lw	$t0	,	9492($zero)
	sw	$t0	,	-48($fp)
	j	$label10
	nop
$label11:
	li	$v0	,		,	4
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
	sw	$t0	,	9500($zero)
	lw	$t0	,	9500($zero)
	sw	$t0	,	0($sp)
	addi	$sp	,	$sp	,	-4
	lw	$t0	,	-44($fp)
	sw	$t0	,	9504($zero)
	lw	$t0	,	9504($zero)
	sw	$t0	,	0($sp)
	addi	$sp	,	$sp	,	-4
	jal	printChar
	nop
	li	$v0	,		,	4
	la	$a0	,	$Message19
	syscall
	lw	$t0	,	-52($fp)
	sw	$t0	,	9508($zero)
	li	$t0	,	2
	sw	$t0	,	9512($zero)
	lw	$t0	,	9508($zero)
	lw	$t1	,	9512($zero)
	sub	$t0	,	$t0	,	$t1
	bgez	$t0	,	$label12
	nop
	li	$v0	,		,	4
	la	$a0	,	$Message20
	syscall
	j	$label13
	nop
$label12:
	lw	$t0	,	-52($fp)
	sw	$t0	,	9516($zero)
	li	$t0	,	45
	sw	$t0	,	9520($zero)
	lw	$t0	,	9516($zero)
	lw	$t1	,	9520($zero)
	sub	$t0	,	$t0	,	$t1
	blez	$t0	,	$label14
	nop
	li	$v0	,		,	4
	la	$a0	,	$Message21
	syscall
	j	$label15
	nop
$label14:
	lw	$t0	,	-52($fp)
	sw	$t0	,	9524($zero)
	lw	$t0	,	9524($zero)
	sw	$t0	,	0($sp)
	addi	$sp	,	$sp	,	-4
	jal	_4fib
	nop
	li	$v0	,		,	4
	la	$a0	,	$Message22
	syscall
$label16:
	lw	$t0	,	-52($fp)
	sw	$t0	,	9528($zero)
	li	$t0	,	0
	sw	$t0	,	9532($zero)
	lw	$t0	,	9528($zero)
	lw	$t1	,	9532($zero)
	sub	$t0	,	$t0	,	$t1
	bltz	$t0	,	$label17
	nop
	li	$v0	,		,	4
	la	$a0	,	$Message23
	syscall
	lw	$t0	,	-52($fp)
	sw	$t0	,	9536($zero)
	li	$v0	,	1
	lw	$a0	,	9536($zero)
	syscall
	li	$v0	,		,	4
	la	$a0	,	$Message24
	syscall
	lw	$t0	,	-52($fp)
	sw	$t0	,	9540($zero)
	lw	$t0	,	9540($zero)
	addi	$t0	,	$t0	,	27
	li	$t1	,	4
	mul	$t0	,	$t0	,	$t1
	lw	$t0	,	1000($t0)
	sw	$t0	,	9544($zero)
	lw	$t0	,	9544($zero)
	sw	$t0	,	9548($zero)
	lw	$t0	,	9548($zero)
	sub	$t0	,	$zero	,	$t0
	sw	$t0	,	9548($zero)
	lw	$t0	,	9548($zero)
	sw	$t0	,	9552($zero)
	lw	$t0	,	9552($zero)
	sub	$t0	,	$zero	,	$t0
	sw	$t0	,	9552($zero)
	li	$v0	,	1
	lw	$a0	,	9552($zero)
	syscall
	li	$v0	,		,	4
	la	$a0	,	$Message25
	syscall
	lw	$t0	,	-52($fp)
	sw	$t0	,	9556($zero)
	li	$t0	,	1
	sw	$t0	,	9560($zero)
	lw	$t0	,	9556($zero)
	lw	$t1	,	9560($zero)
	sub	$t0	,	$t0	,	$t1
	sw	$t0	,	9556($zero)
	lw	$t0	,	9556($zero)
	sw	$t0	,	-52($fp)
	j	$label16
	nop
$label17:
$label15:
$label13:
	li	$v0	,		,	4
	la	$a0	,	$Message26
	syscall
	lw	$t0	,	-44($fp)
	sw	$t0	,	9564($zero)
	lw	$t0	,	9564($zero)
	sw	$t0	,	-48($fp)
$label18:
	lw	$t0	,	-48($fp)
	sw	$t0	,	9568($zero)
	li	$t0	,	0
	sw	$t0	,	9572($zero)
	lw	$t0	,	9568($zero)
	lw	$t1	,	9572($zero)
	sub	$t0	,	$t0	,	$t1
	beq	$t0	,	$zero	,	$label19
	nop
	jal	returnStar
	nop
	jal	returnStar
	nop
	add	$t0	,	$v0	,	$zero
	sw	$t0	,	9576($zero)
	li	$v0	,	11
	lw	$a0	,	9576($zero)
	syscall
	lw	$t0	,	-48($fp)
	sw	$t0	,	9580($zero)
	li	$t0	,	1
	sw	$t0	,	9584($zero)
	lw	$t0	,	9580($zero)
	lw	$t1	,	9584($zero)
	sub	$t0	,	$t0	,	$t1
	sw	$t0	,	9580($zero)
	lw	$t0	,	9580($zero)
	sw	$t0	,	-48($fp)
	j	$label18
	nop
$label19:
	li	$v0	,		,	4
	la	$a0	,	$Message27
	syscall
	li	$v0	,	5
	syscall
	add	$t0	,	$v0	,	$zero
	sw	$t0	,	-52($fp)
	lw	$t0	,	-52($fp)
	sw	$t0	,	9588($zero)
	li	$t0	,	0
	sw	$t0	,	9592($zero)
	lw	$t0	,	9592($zero)
	lw	$t1	,	9588($zero)
	sub	$t0	,	$t0	,	$t1
	bne	$t0	,	$zero	,	$label21
	nop
	li	$t0	,	0
	sw	$t0	,	9596($zero)
	li	$v0	,	1
	lw	$a0	,	9596($zero)
	syscall
	j	$label20
	nop
$label21:
	li	$t0	,	1
	sw	$t0	,	9600($zero)
	lw	$t0	,	9600($zero)
	lw	$t1	,	9588($zero)
	sub	$t0	,	$t0	,	$t1
	bne	$t0	,	$zero	,	$label22
	nop
	li	$t0	,	1
	sw	$t0	,	9604($zero)
	li	$v0	,	1
	lw	$a0	,	9604($zero)
	syscall
	j	$label20
	nop
$label22:
	li	$t0	,	2
	sw	$t0	,	9608($zero)
	lw	$t0	,	9608($zero)
	lw	$t1	,	9588($zero)
	sub	$t0	,	$t0	,	$t1
	bne	$t0	,	$zero	,	$label23
	nop
	li	$t0	,	2
	sw	$t0	,	9612($zero)
	li	$v0	,	1
	lw	$a0	,	9612($zero)
	syscall
	j	$label20
	nop
$label23:
	li	$t0	,	3
	sw	$t0	,	9616($zero)
	lw	$t0	,	9616($zero)
	lw	$t1	,	9588($zero)
	sub	$t0	,	$t0	,	$t1
	bne	$t0	,	$zero	,	$label24
	nop
	li	$t0	,	3
	sw	$t0	,	9620($zero)
	li	$v0	,	1
	lw	$a0	,	9620($zero)
	syscall
	j	$label20
	nop
$label24:
	li	$t0	,	4
	sw	$t0	,	9624($zero)
	lw	$t0	,	9624($zero)
	lw	$t1	,	9588($zero)
	sub	$t0	,	$t0	,	$t1
	bne	$t0	,	$zero	,	$label25
	nop
	li	$t0	,	4
	sw	$t0	,	9628($zero)
	li	$v0	,	1
	lw	$a0	,	9628($zero)
	syscall
	j	$label20
	nop
$label25:
	li	$v0	,		,	4
	la	$a0	,	$Message28
	syscall
$label20:
	li	$v0	,	10
	syscall
