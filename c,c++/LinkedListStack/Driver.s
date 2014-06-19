	.file	"Driver.c"
	.section	.rodata
.LC0:
	.string	"%d"
	.text
	.globl	main
	.type	main, @function
main:
.LFB0:
	.cfi_startproc
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6
	subq	$16, %rsp
	movl	$0, %eax
	call	create
	movq	%rax, -8(%rbp)
	movl	$5, -12(%rbp)
	movl	$0, -16(%rbp)
	jmp	.L2
.L3:
	movq	-8(%rbp), %rdx
	movl	-16(%rbp), %eax
	movq	%rdx, %rsi
	movl	%eax, %edi
	call	push
	addl	$1, -16(%rbp)
.L2:
	movl	-16(%rbp), %eax
	cmpl	-12(%rbp), %eax
	jl	.L3
	movl	$0, -16(%rbp)
	jmp	.L4
.L5:
	movq	-8(%rbp), %rax
	movq	%rax, %rdi
	call	pop
	movl	%eax, %esi
	movl	$.LC0, %edi
	movl	$0, %eax
	call	printf
	addl	$1, -16(%rbp)
.L4:
	movl	-16(%rbp), %eax
	cmpl	-12(%rbp), %eax
	jl	.L5
	movq	-8(%rbp), %rax
	movq	%rax, %rdi
	call	deleteStack
	movl	$0, %eax
	leave
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE0:
	.size	main, .-main
	.ident	"GCC: (Ubuntu/Linaro 4.8.1-10ubuntu9) 4.8.1"
	.section	.note.GNU-stack,"",@progbits
