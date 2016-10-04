#include"keyboard.h"
#include"basic.h"
#include"const.h"

void kb_init(){
  outb(0x21,0xfd);
}

void keyboard_handler_main(){
  static unsigned int current_loc=0;
  unsigned char status;
  unsigned int index;
  char keycode;
  outb(0x20,0x20);
  status=inb(KEYBOARD_STATUS_PORT);
  if(status&0x01){
    keycode=inb(KEYBOARD_DATA_PORT);
    if(keycode<0){
      return;
    }
    index=keycode;
    vidptr[current_loc++]=keyboard_map[index];
    vidptr[current_loc++]=0x07;
  }
}
