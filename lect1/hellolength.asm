	;; Hello World Program (Calculating string length)
	;; 

	;; Compile with: nasm -f elf hellolength.asm
	;; Link with (64 bit systems require elf_i386 option): ld -m elf_i386 hellolength.o -o hellolength
	;; Run with: ./hellolength
 
SECTION .data
msg     db      'Hello, brave new world!', 0Ah, 0Ah ; we can mxodify this now without having to update anywhere else in the program
 
SECTION .text
global  _start
 
_start:
 
    mov     ebx, msg        ; ebx ha il puntatore al primo carattere
    mov     eax, ebx        ; eax=ebx
 
nextchar:
    cmp     byte [eax], 0   ; Confronta il byte puntato in RAM da eax con 0
    jz      finished        ; Salta se lo zero flag è settato all'indirizzo finished
    inc     eax             ; eax++
    jmp     nextchar        ; Salta all'indirizzo nextchar
 
finished:
    sub     eax, ebx        ; Calcola la lunghezza della stringa sottraendo da eax, ebx
 
    mov     edx, eax        ; Da qui in poi puoi riferirti al precedente programma
    mov     ecx, msg        ; 
    mov     ebx, 1
    mov     eax, 4
    int     80h
 
    mov     ebx, 0
    mov     eax, 1
    int     80h
