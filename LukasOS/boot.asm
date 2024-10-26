; boot.asm
[BITS 16]       ; 16-bit code
[ORG 0x7C00]    ; Origin address for bootloader

start:
    mov si, message
    call print_string
    jmp $

print_string:
    mov ah, 0x0E  ; BIOS teletype output
.next_char:
    lodsb          ; Load byte from DS:SI into AL
    test al, al    ; Check if we reached null terminator
    jz .done
    int 0x10      ; Print character in AL
    jmp .next_char
.done:
    ret

message db 'Hello World!', 0

times 510 - ($ - $$) db 0 ; Fill with zeros
dw 0xAA55                  ; Boot signature
