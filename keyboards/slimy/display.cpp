#ifdef __cplusplus
extern "C" {
#endif

#include "display.h"

#include "quantum.h"
#include "config.h"
#include "board.h"

#include "debug.h"

#include "spi_master.h"
#include "qp.h"
#include "qp_st7789.h"
#include "qp_comms_spi.h"

void WMPCounter::updateDisplay() {

    elapsed_buckets[current_counter] = timer_elapsed32(last_print);

    int16_t sum = 0;
    int32_t elapsed_sum = 0;
    for (size_t i = 0; i < WMPCounter_BUCKETS; i++){
        sum += counter_buckets[i];
        elapsed_sum += elapsed_buckets[i];
    }
    current_counter = (current_counter + 1) % WMPCounter_BUCKETS;
    counter_buckets[current_counter] = 0;
    elapsed_buckets[current_counter] = 0;


    dprintf("(%d * 60000) / %d;\n", sum, elapsed_sum);
    int wpm    = (sum * 60000) / elapsed_sum;
    last_print = timer_read32();

    char text[10];
    snprintf(text, 10, "WMP: %d", wpm);
    updateText(text);
}

void TextBox::updateText(char* text) {
    int16_t width = qp_textwidth(font, text);
    if (width > right - left) {
        qp_rect(display, left, top, right, bottom, BACKGROUND_COLOR, true);
        char* text = "too big";
        qp_drawtext_recolor(display, left, top, font, text, TEXT_COLOR, BACKGROUND_COLOR);
    } else {
        qp_rect(display, left, top + font->line_height, right, bottom, BACKGROUND_COLOR, true);
        qp_rect(display, left + width, top, right, bottom, BACKGROUND_COLOR, true);
        qp_drawtext_recolor(display, left, top, font, text, TEXT_COLOR, BACKGROUND_COLOR);
    }
}

#ifdef __cplusplus
} /* extern "C" */
#endif
