	.file	"main.c"
	.text
	.section	.rodata
.LC0:
	.string	"cal %d %d"
	.text
	.globl	make_string_cal
	.type	make_string_cal, @function
make_string_cal:
.LFB6:
	.cfi_startproc
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6
	subq	$16, %rsp
	movq	%rdi, -8(%rbp)
	movl	%esi, -12(%rbp)
	movl	%edx, -16(%rbp)
	movl	-16(%rbp), %ecx
	movl	-12(%rbp), %edx
	movq	-8(%rbp), %rax
	movl	$.LC0, %esi
	movq	%rax, %rdi
	movl	$0, %eax
	call	sprintf
	movq	-8(%rbp), %rax
	movq	%rax, %rdi
	call	system
	nop
	leave
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE6:
	.size	make_string_cal, .-make_string_cal
	.section	.rodata
.LC1:
	.string	"Calendario by: Jakepys"
.LC2:
	.string	"Ingresa el mes: "
.LC3:
	.string	"%d"
.LC4:
	.string	"\nIngrea el anho: "
.LC5:
	.string	"\n%s Se guardo en el puntero?\n"
	.text
	.globl	main
	.type	main, @function
main:
.LFB7:
	.cfi_startproc
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6
	addq	$-128, %rsp
	movl	$.LC1, %edi
	call	puts
	movl	$.LC2, %edi
	movl	$0, %eax
	call	printf
	leaq	-116(%rbp), %rax
	movq	%rax, %rsi
	movl	$.LC3, %edi
	movl	$0, %eax
	call	__isoc99_scanf
	movl	$.LC4, %edi
	movl	$0, %eax
	call	printf
	leaq	-120(%rbp), %rax
	movq	%rax, %rsi
	movl	$.LC3, %edi
	movl	$0, %eax
	call	__isoc99_scanf
	movl	$10, %edi
	call	putchar
	movl	-120(%rbp), %edx
	movl	-116(%rbp), %ecx
	leaq	-112(%rbp), %rax
	movl	%ecx, %esi
	movq	%rax, %rdi
	call	make_string_cal
	leaq	-112(%rbp), %rax
	movq	%rax, %rsi
	movl	$.LC5, %edi
	movl	$0, %eax
	call	printf
	movl	$0, %eax
	leave
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE7:
	.size	main, .-main
	.ident	"GCC: (GNU) 14.2.1 20240912 (Red Hat 14.2.1-3)"
	.section	.note.GNU-stack,"",@progbits
