#include "slimy.h"
#include "config.h"
#include "board.h"

#include "print.h"
#include "debug.h"

#include "spi_master.h"
#include "qp.h"
#include "qp_st7789.h"
#include "qp_comms_spi.h"

#include "gordo.qgf.h"

#define XSTR1(x) STR1(x)
#define STR1(x) #x
#pragma message "The value of A4: " XSTR1(PAL_MODE_OUTPUT_PUSHPULL)

#define FASTRUN  __attribute__ ((section(".fastrun"), noinline, noclone, optimize("Os") ))

painter_device_t screen;
bool on_off = true;


static painter_image_handle_t my_image;
static deferred_token my_anim;


FASTRUN void keyboard_post_init_kb(void) {
    // Customise these values to desired behaviour
    debug_enable=true;
    debug_matrix=true;
    debug_keyboard=true;
    debug_mouse=true;

    // Turn on boar LED
    // setPinOutput(LINE_PIN13);
    // writePinHigh(LINE_PIN13);
    //writePinLow(LINE_PIN13);

    wait_ms(100);

    screen = qp_st7789_make_spi_device(240, 240, SPI_CHIP_SELECT_PIN, SPI_DC_PIN, SPI_RESET_PIN, 2, 3);
    bool a = qp_init(screen, QP_ROTATION_0);
    dprintf("init: %d \n", a);

    qp_clear(screen);
    qp_power(screen, true);
    TIME("first_square",
    qp_rect(screen, 0, 0, 239, 239, 127, 255, 0, true);
    )

    // TIME("qp_line",
    // for (int i = 0; i < 239; ++i) {
    //     qp_line(screen, 0, i, 239, i, i , 255, 255);
    // }
    // )

    my_image = qp_load_image_mem(gfx_gordo);
    if (my_image != NULL) {
        my_anim = qp_drawimage(screen, 0,  0, my_image);
    }
}



// void housekeeping_task_user(void) {
//     static uint32_t last_draw = 0;
//     static uint32_t idk = 0;

//     if (timer_elapsed32(last_draw) > 1*1000) { // Throttle to 30fps

//         last_draw = timer_read32();
//         // Draw 8px-wide rainbow down the left side of the display
//         TIME("qp_line",
//         for (int i = 0; i < 239; ++i) {
//             qp_line(screen, 0, i, 239, i, (i + idk) % 255, 255, 255);
//         }
//         )
//         idk++;
//         dprintf("time: %d \n", timer_elapsed32(last_draw));
//     } else {

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
