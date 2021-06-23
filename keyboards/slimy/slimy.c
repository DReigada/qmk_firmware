#include "slimy.h"
#include "pin_defs.h"
#include "print.h"
#include "board.h"
#include "trackball.h"
#include "i2c_master.h"

#define XSTR1(x) STR1(x)
#define STR1(x) #x

void keyboard_post_init_user(void) {
    // Customise these values to desired behaviour
    debug_enable=true;
    debug_matrix=true;
    debug_keyboard=true;
    debug_mouse=true;

    setPinOutput(LINE_PIN13);
    writePinHigh(LINE_PIN13);

    i2c_init();
}

// A  B  C  D  E  A  B  C  D  E  A  B  C  D  E
// 1  2  3  4  5  6  7  8  9  10 11 12 13 14 15

void housekeeping_task_kb(void) {
    trackball_set_rgbw(255, 0,0,0);
    // register_code(KC_A);
    // writePinHigh(13);

    // writePinHigh(A13);
}
