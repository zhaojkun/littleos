OUTPUT_FORMAT(elf32-i386)
ENTRY(loader)
SECTIONS{
        . =0x00100000;
        .text ALIGN(0x1000):
        {
                *(.text)
        }
        .data ALIGN(0x1000):
        {
                *(.data)
        }
        .bss ALIGN(0x1000):
        {
         
                *(.bss)
        }
}
