#ifdef __cplusplus
extern "C" {
#endif

#include "slimy.h"
#include "config.h"
#include "board.h"

#include "debug.h"

#include "spi_master.h"
#include "qp.h"
#include "qp_st7789.h"
#include "qp_comms_spi.h"

#include "gordo.qgf.h"
#include "arial.qff.h"

#include "display.h"
#include "hal_spi.h"

#define XSTR1(x) STR1(x)
#define STR1(x) #x
// #pragma message "The value of A4: " XSTR1(HAL_SPI_V2_H)

#define FASTRUN  __attribute__ ((section(".fastrun"), noinline, noclone, optimize("Os") ))

static inline void col1_set_matrix(void) {
    ATOMIC_BLOCK_FORCEON {
        setPinInputHigh(LINE_PIN11);
    }
}

static inline void col1_set_display(void) {
    ATOMIC_BLOCK_FORCEON {
        setPinInput(LINE_PIN11);
        palSetPadMode(PAL_PORT(SPI_MOSI_PIN), PAL_PAD(SPI_MOSI_PIN), SPI_MOSI_PAL_MODE);
    }
}

FASTRUN void matrix_scan_kb(void) {
    col1_set_matrix();
}

painter_device_t screen;
bool on_off = true;


static painter_image_handle_t my_image;

static painter_font_handle_t my_font;
WMPCounter *counter;
TextBox *ramUsage;
TextBox *elapsed;

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

    screen = qp_st7789_make_spi_device(240, 240, SPI_CHIP_SELECT_PIN, SPI_DC_PIN, SPI_RESET_PIN, SPI_DIVISOR, SPI_MODE);
    qp_init(screen, QP_ROTATION_0);

    qp_clear(screen);
    qp_power(screen, true);
    TIME("first_square",
    qp_rect(screen, 0, 0, 239, 239, 127, 255, 0, true);
    )

    my_image = qp_load_image_mem(gfx_gordo);
    if (my_image != NULL) {
        qp_drawimage(screen, 0,  50, my_image);
    }

    my_font = qp_load_font_mem(font_arial);
    if (my_font != NULL) {
        static const char *text = "Hello from Gordo!";
        int16_t width = qp_textwidth(my_font, text);
        qp_drawtext(screen, (239 - width), (239 - my_font->line_height), my_font, text);
    }

    backlight_set(15);


    counter = new WMPCounter(screen, my_font, 0, 0, 150, 29);
    ramUsage = new TextBox(screen, my_font, 0, 30, 239, 59);
    elapsed = new TextBox(screen, my_font, 0, 60, 239, 89);

    srand(timer_read32());
}

void housekeeping_task_user(void) {
    static uint32_t last_exec = 0;

    uint32_t elapsed_t = timer_elapsed32(last_exec);

    // if (elapsed_t > 1*1000) {
    //     col1_set_display();

    //     last_exec = timer_read32();
    //     dprintf("elapsed: %d\n", elapsed_t);

    //     for (size_t i = 0; i < rand() % 5; i++){
    //         counter->count();
    //     }

    //     dprintf("Free usage: %d\n", chCoreGetStatusX());

    //     char text[30];
    //     snprintf(text, 30, "RAM: %d", chCoreGetStatusX());

    //     counter->updateDisplay();
    //     ramUsage->updateText(text);

    //     elapsed_t = timer_elapsed32(last_exec);
    //     snprintf(text, 30, "time: %d", elapsed_t);
    //     elapsed->updateText(text);

    //     last_exec = timer_read32();
    // }
}

#ifdef __cplusplus
} /* extern "C" */
#endif
