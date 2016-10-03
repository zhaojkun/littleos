#ifndef INCLUDE_FRAME_BUFFER
#define INCLUDE_FRAME_BUFFER

#define FB_GREEN 2
#define FB_DARK_GRAY 8

#define FB_COMMAND_PORT 0x3d4
#define FB_DATA_PORT 0x3d5

#define FB_HIGH_BYTE_COMMAND 14
#define FB_LOW_BYTE_COMMAND 15

void clean_screen();
void fb_write_cell(unsigned int i,char c,unsigned char fg,unsigned char bg);
void fb_move_cursor(unsigned short pos);
void write(const char *buf,unsigned int len);
void show_write_byte(unsigned i,char c);
void show_hello_world();
#endif
