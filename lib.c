#include"lib.h"
int strLen(const char *buf){
  int i;
  for(i=0;buf[i]!='\0';i++);
  return i;
}
