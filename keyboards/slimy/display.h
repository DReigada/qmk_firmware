#include "qp.h"

#include "arial.qff.h"

#pragma once

#define BACKGROUND_COLOR 0, 0, 0
#define TEXT_COLOR 0,0,255

class DisplayWidget {
    public:
        DisplayWidget(painter_device_t display, uint16_t left, uint16_t top, uint16_t right, uint16_t bottom){
            this->display = display;
            this->left = left;
            this->top = top;
            this->right = right;
            this->bottom = bottom;
        };

    protected:
        painter_device_t display;
        uint16_t         left, top, right, bottom;
        void             _draw();
};

class TextBox : DisplayWidget {
    public:
        TextBox(painter_device_t display, painter_font_handle_t font, uint16_t left, uint16_t top, uint16_t right, uint16_t bottom) : DisplayWidget(display, left, top, right, bottom) {
            this->font = font;
        }
        void updateText(char* text);
    private:
        painter_font_handle_t font;
};

#define WMPCounter_BUCKETS 4
class WMPCounter : TextBox {
    public:
        WMPCounter(painter_device_t display, painter_font_handle_t font, uint16_t left, uint16_t top, uint16_t right, uint16_t bottom) : TextBox(display, font, left, top, right, bottom) {
            last_print = timer_read32();
            for (size_t i = 0; i < WMPCounter_BUCKETS; i++){
                counter_buckets[i] = 0;
                elapsed_buckets[i] = 0;
            }
            current_counter = 0;

        }
        void count() {
            counter_buckets[current_counter]++;
        };
        void updateDisplay();

    private:
        uint16_t counter_buckets[WMPCounter_BUCKETS];
        uint32_t elapsed_buckets[WMPCounter_BUCKETS];
        uint8_t current_counter;
        uint32_t last_print;
};
