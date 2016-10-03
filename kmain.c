#include"basic.h"
#include"io.h"
#include"interrupt.h"
#include"keyboard.h"
int strLen(const char * buf);

void kmain(){
  clean_screen();
  idt_init();
  kb_init();
  while(1);
  return ;
}
int strLen(const char *buf){
  int i;
  for(i=0;buf[i]!='\0';i++);
  return i;
}
