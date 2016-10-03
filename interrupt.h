#ifndef INCLUDE_INTERRPUT
#define INCLUDE_INTERRUPT

struct IDT_entry{
  unsigned short int offset_lowerbits;
  unsigned short int selector;
  unsigned char zero;
  unsigned char type_attr;
  unsigned short int offset_higherbits;
};

#define IDT_SIZE 256
struct IDT_entry IDT[IDT_SIZE];

void insert_handler(unsigned int num,unsigned long handler,unsigned short int selector,unsigned char type_atrr);
void idt_init();


#endif
