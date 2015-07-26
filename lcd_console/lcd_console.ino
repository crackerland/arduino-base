#include "lcd_console_main.h"


void setup(void) {
  main_setup();
}

void loop(void) {
  main_loop();
}

void serialEvent() {
    main_serialEvent();
}
