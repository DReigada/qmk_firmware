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
#include "arial.qff.h"

#define XSTR1(x) STR1(x)
#define STR1(x) #x
#pragma message "The value of A4: " XSTR1(PAL_MODE_OUTPUT_PUSHPULL)

#define FASTRUN  __attribute__ ((section(".fastrun"), noinline, noclone, optimize("Os") ))

painter_device_t screen;
bool on_off = true;


static painter_image_handle_t my_image;

static painter_font_handle_t my_font;


void keyboard_post_init_kb(void) {
    // Customise these values to desired behaviour
    debug_enable=true;
    debug_matrix=true;
    debug_keyboard=true;
    debug_mouse=true;

    // Turn on boar LED
    setPinOutput(LINE_PIN13);
    writePinHigh(LINE_PIN13);
    writePinLow(LINE_PIN13);

    screen = qp_st7789_make_spi_device(240, 240, SPI_CHIP_SELECT_PIN, SPI_DC_PIN, SPI_RESET_PIN, 2, 3);
    qp_init(screen, QP_ROTATION_0);

    qp_clear(screen);
    qp_power(screen, true);
    TIME("first_square",
    qp_rect(screen, 0, 0, 239, 239, 127, 255, 0, true);
    )

    my_image = qp_load_image_mem(gfx_gordo);
    if (my_image != NULL) {
        qp_drawimage(screen, 0,  0, my_image);
    }

    my_font = qp_load_font_mem(font_arial);
    if (my_font != NULL) {
        static const char *text = "Hello from Gordo!";
        int16_t width = qp_textwidth(my_font, text);
        qp_drawtext(screen, (239 - width), (239 - my_font->line_height), my_font, text);
    }

    backlight_set(31);
}

void housekeeping_task_user(void) {
    static uint32_t last_exec = 0;

    if (timer_elapsed32(last_exec) > 1*1000) {
        last_exec = timer_read32();
    }
}
