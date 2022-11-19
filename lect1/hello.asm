; Compile with: nasm -f elf hello.asm
; Link with (64 bit systems require elf_i386 option): ld -m elf_i386 hello.o -o hello
; Run with: ./hello
 
SECTION .data
msg     db      'Hello World!', 0Ah, 0Ah
 
SECTION .text
global  _start
 
_start:
 
    mov     edx, 14     ; Lunghezza del messaggio da stampare
    mov     ecx, msg	; indirizzo/puntatore al primo carattere della stringa
    mov     ebx, 1	; standard output
    mov     eax, 4	; l'interrupt  80 ha diverse funzionalità. Ponendo eax=4 ho una stampa a video
    int     80h 	; Chiamata al linux kernel. Si chiamano interrupt perchè interrompono il flusso del programma, ed eseguono un codice in LM del SO.
	
    mov     ebx, 0      ; Chiudiamo il processo ->return 0 (nessun errore)
    mov     eax, 1      ; eax=1 con interrupt 80 ho la chiamata di sistema che chiude il processo
    int     80h		; Altrimenti rimarrebbe in vita occupando memoria RAM!
