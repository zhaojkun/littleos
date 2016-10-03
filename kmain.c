#include"framebuffer.h"
int strLen(const char * buf);

void kmain(){
  clean_screen();
  const char *str="Hi,I'am Zhao Jiangkun,I'm from Shanghai China.";
  write(str,strLen(str));
  return ;
}
int strLen(const char *buf){
  int i;
  for(i=0;buf[i]!='\0';i++);
  return i;
}
