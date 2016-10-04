#ifndef INCLUDE_BASIC_H
#define INCLUDE_BASIC_H
void outb(unsigned short port,unsigned char data);
char inb(unsigned short port);
void load_idt(unsigned long *idt_ptr);
void keyboard_handler();
#endif
