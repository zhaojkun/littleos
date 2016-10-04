global outb,inb,load_idt,keyboard_handler
outb:
        mov al,[esp+8]
        mov dx,[esp+4]
        out dx,al
        ret
inb:
        mov dx,[esp+4]
        in al,dx
        ret
load_idt:
        mov edx,[esp+4]
        lidt [edx]
        sti
        ret
keyboard_handler:
        extern keyboard_handler_main
        call keyboard_handler_main
        iretd
