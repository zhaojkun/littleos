#include"basic.h"
#include"io.h"
#include"interrupt.h"
#include"keyboard.h"
#include"lib.h"

void kmain(){
  clean_screen();
  idt_init();
  kb_init();
  while(1);
  return ;
}
