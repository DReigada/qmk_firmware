#include "slimy.h"
#include "board.h"
#include "print.h"
#include "debug.h"

#define XSTR1(x) STR1(x)
#define STR1(x) #x

void keyboard_post_init_kb(void) {
    // Customise these values to desired behaviour
    debug_enable=true;
    debug_matrix=true;
    debug_keyboard=true;
    debug_mouse=true;

    // Turn on boar LED
    setPinOutput(LINE_PIN13);
    writePinHigh(LINE_PIN13);
    //writePinLow(LINE_PIN13);
}
