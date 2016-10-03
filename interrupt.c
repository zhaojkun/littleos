#include"interrupt.h"
#include"const.h"
#include"basic.h"

void idt_init(){
  unsigned long keyboard_address;
  unsigned long idt_address;
  unsigned long idt_ptr[2];
  
  keyboard_address=(unsigned long)keyboard_handler;
  insert_handler(0x21,keyboard_address,0x08,0x8e);
  outb(0x20,0x11);
  outb(0xA0,0x11);
  
  outb(0x21,0x20);
  outb(0xa1,0x28);
  
  outb(0x21,0x00);
  outb(0xa1,0x00);

  outb(0x21,0x01);
  outb(0xa1,0x01);

  outb(0x21,0xff);
  outb(0xa1,0xff);

  idt_address=(unsigned long)IDT;
  idt_ptr[0]=(sizeof(struct IDT_entry)*IDT_SIZE)+((idt_address&0xffff)<<16);
  idt_ptr[1]=idt_address>>16;
  load_idt(idt_ptr);
  
}
void insert_handler(unsigned int num,unsigned long handler,unsigned short int selector,unsigned char type_attr){
  IDT[num].offset_lowerbits=handler&0xffff;
  IDT[num].selector=selector;
  IDT[num].zero=0;
  IDT[num].type_attr=type_attr;
  IDT[num].offset_higherbits=(handler&0xffff0000)>>16;
}
