#include"framebuffer.h"
#include"io.h"
void clean_screen(){
  char *fb=(char *)0xb8000;
  unsigned int i=0;
  while(i<80*25*2){
    fb[i]=' ';
    fb[i+1]=0x07;
    i=i+1;
  }
  return;
}
void fb_write_cell(unsigned int i,char c,unsigned char fg,unsigned char bg){
  char *fb=(char *)0x000b8000;
  fb[i]=c;
  fb[i+1]=((fg&0x0f)<<4|(bg &0x0f));
}
void fb_move_cursor(unsigned short pos){
  outb(FB_COMMAND_PORT,FB_HIGH_BYTE_COMMAND);
  outb(FB_DATA_PORT,((pos>>8)&0x00ff));
  outb(FB_COMMAND_PORT,FB_LOW_BYTE_COMMAND);
  outb(FB_DATA_PORT,pos&0x00ff);
}
void write(const char *buf,unsigned int len){
  unsigned int i;
  for(i=0;i<len;i++){
    fb_write_cell(i<<1,buf[i],FB_GREEN,FB_DARK_GRAY);
  }
}
void show_write_byte(unsigned int i,char c){
  fb_write_cell(i,c,FB_GREEN,FB_DARK_GRAY);
}
void show_hello_world(){
  show_write_byte(0,'H');
  show_write_byte(2,'e');
  show_write_byte(4,'l');
  show_write_byte(6,'l');
  show_write_byte(8,'o');
}
