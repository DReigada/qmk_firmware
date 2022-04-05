#include "slimy.h"
#include "config.h"
#include "board.h"

#include "print.h"
#include "debug.h"

#include "spi_master.h"
#include "qp.h"
#include "qp_st7789.h"
#include "qp_comms_spi.h"

#define XSTR1(x) STR1(x)
#define STR1(x) #x
#pragma message "The value of A4: " XSTR1(PAL_MODE_OUTPUT_PUSHPULL)


painter_device_t screen;
bool on_off = true;

void keyboard_post_init_kb(void) {
    // Customise these values to desired behaviour
    debug_enable=true;
    debug_matrix=true;
    debug_keyboard=true;
    debug_mouse=true;

    // Turn on boar LED
    // setPinOutput(LINE_PIN13);
    // writePinHigh(LINE_PIN13);
    //writePinLow(LINE_PIN13);


    screen = qp_st7789_make_spi_device(240, 240, SPI_CHIP_SELECT_PIN, SPI_DC_PIN, SPI_RESET_PIN, 2, 3);
    bool a = qp_init(screen, QP_ROTATION_0);
    dprintf("init: %d \n", a);

    qp_clear(screen);

    a = qp_power(screen, false);
    dprintf("power: %d \n", a);

    wait_ms(10);

    a = qp_power(screen, true);
    dprintf("power: %d \n", a);

    a = qp_rect(screen, 0, 0, 10, 10, 127, 255, 255, true);
    dprintf("rect: %d \n", a);

    a = qp_flush(screen);
    dprintf("flush: %d \n", a);

    a = qp_clear(screen);
    dprintf("qp_clear: %d \n", a);

    a = qp_flush(screen);
    dprintf("flush: %d \n", a);

}

void housekeeping_task_user(void) {
     static uint32_t last_draw = 0;
     static bool bla = false;
    if (timer_elapsed32(last_draw) > 2000) {
        last_draw = timer_read32();
        qp_power(screen, bla);
        bla = !bla;
    }
}

// void housekeeping_task_user(void) {
//     static uint32_t last_draw = 0;
//     static uint32_t idk = 0;
//     if (timer_elapsed32(last_draw) > 33) { // Throttle to 30fps
//         dprintf("beep\n");
//         last_draw = timer_read32();
//         // Draw 8px-wide rainbow down the left side of the display
//         for (int i = 0; i < 240; ++i) {
//             qp_line(screen, 0, i, 100, i, (i + idk) % 255, 255, 255);
//         }
//         idk++;
//         qp_flush(screen);
//         dprintf("time: %d \n", timer_elapsed32(last_draw));
//     } else {
//         dprintf("boop\n");
//     }
// }

// void housekeeping_task_user(void) {
//     static uint16_t d_timer;
//     if (timer_elapsed(d_timer) > 1000) {
//         // bool power = qp_power(screen, on_off);


//         writePinHigh(SPI_RESET_PIN);
//         wait_ms(20);
//         writePinLow(SPI_RESET_PIN);
//         wait_ms(20);

//         dprintf("bla: \n");


//         on_off = !on_off;
//         d_timer = timer_read();
//     }
// }
