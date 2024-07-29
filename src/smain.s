format ELF

public _start

section '.text' executable
extrn	kmain
_start:
	cli
	lea	esp,	[stck]
	jmp	far	kmain
	hlt
ret

section '.bss'	writeable
rb 8192
stck:
