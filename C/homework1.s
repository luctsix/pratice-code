	.file	"homework1.c"
	.def	___main;	.scl	2;	.type	32;	.endef
	.section .rdata,"dr"
LC0:
	.ascii "my name is: \301\267\277\241\317\351\0"
LC1:
	.ascii "pause\0"
LC2:
	.ascii "nodepad++\0"
	.text
	.globl	_main
	.def	_main;	.scl	2;	.type	32;	.endef
_main:
	pushl	%ebp
	movl	%esp, %ebp
	andl	$-16, %esp
	subl	$16, %esp
	call	___main
	movl	$LC0, (%esp)
	call	_puts
	movl	$LC1, (%esp)
	call	_system
	movl	$LC2, (%esp)
	call	_system
	movl	$0, %eax
	leave
	ret
	.def	_puts;	.scl	2;	.type	32;	.endef
	.def	_system;	.scl	2;	.type	32;	.endef
