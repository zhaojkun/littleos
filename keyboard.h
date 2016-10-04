#ifndef INCLUDE_KEYBOARD
#define INCLUDE_KEYBOARD

#define KEYBOARD_DATA_PORT 0x60
#define KEYBOARD_STATUS_PORT 0x64

void kb_init();
void keyboard_handler_main();
#endif
