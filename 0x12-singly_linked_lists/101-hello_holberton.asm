section		.text
	extern	printf
	global	main

main:
	mov		edi, message
	mov		eax, 0
	call	printf


section		.data
	message db 'Hello, Holberton', 0xa, 0
