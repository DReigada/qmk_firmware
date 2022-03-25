#include "slimy.h"
#include "board.h"


#include <Adafruit_GFX.h>    // Core graphics library
#include <Adafruit_ST7735.h> // Hardware-specific library for ST7735
#include <Adafruit_ST7789.h> // Hardware-specific library for ST7789
#include <SPI.h>


#ifdef ADAFRUIT_HALLOWING
  #define TFT_CS        39 // Hallowing display control pins: chip select
  #define TFT_RST       37 // Display reset
  #define TFT_DC        38 // Display data/command select
  #define TFT_BACKLIGHT  7 // Display backlight pin

#elif defined(ARDUINO_FEATHER_ESP32) // Feather Huzzah32
  #define TFT_CS         14
  #define TFT_RST        15
  #define TFT_DC         32

#elif defined(ESP8266)
  #define TFT_CS         4
  #define TFT_RST        16
  #define TFT_DC         5

#else
  // For the breakout board, you can use any 2 or 3 pins.
  // These pins will also work for the 1.8" TFT shield.
  #define TFT_CS        10
  #define TFT_RST        9 // Or set to -1 and connect to Arduino RESET pin
  #define TFT_DC         8
#endif


// OPTION 1 (recommended) is to use the HARDWARE SPI pins, which are unique
// to each board and not reassignable. For Arduino Uno: MOSI = pin 11 and
// SCLK = pin 13. This is the fastest mode of operation and is required if
// using the breakout board's microSD card.

// For 1.44" and 1.8" TFT with ST7735 (including HalloWing) use:
Adafruit_ST7735 tft = Adafruit_ST7735(TFT_CS, TFT_DC, TFT_RST);

// For 1.3", 1.54", and 2.0" TFT with ST7789:
//Adafruit_ST7789 tft = Adafruit_ST7789(TFT_CS, TFT_DC, TFT_RST);

// OPTION 2 lets you interface the display using ANY TWO or THREE PINS,
// tradeoff being that performance is not as fast as hardware SPI above.
//#define TFT_MOSI 11  // Data out
//#define TFT_SCLK 13  // Clock out
//Adafruit_ST7735 tft = Adafruit_ST7735(TFT_CS, TFT_DC, TFT_MOSI, TFT_SCLK, TFT_RST);

// connect a push button between ground and...
const uint8_t   Button_pin              = 2;

// color definitions
const uint16_t  Display_Color_Black        = 0x0000;
const uint16_t  Display_Color_Blue         = 0x001F;
const uint16_t  Display_Color_Red          = 0xF800;
const uint16_t  Display_Color_Green        = 0x07E0;
const uint16_t  Display_Color_Cyan         = 0x07FF;
const uint16_t  Display_Color_Magenta      = 0xF81F;
const uint16_t  Display_Color_Yellow       = 0xFFE0;
const uint16_t  Display_Color_White        = 0xFFFF;

// The colors we actually want to use
uint16_t        Display_Text_Color         = Display_Color_Black;
uint16_t        Display_Backround_Color    = Display_Color_Blue;

// assume the display is off until configured in setup()
bool            isDisplayVisible        = false;

// declare size of working string buffers. Basic strlen("d hh:mm:ss") = 10
const size_t    MaxString               = 16;

// the string being displayed on the SSD1331 (initially empty)
char oldTimeString[MaxString]           = { 0 };


// void displayUpTime() {

//     // calculate seconds, truncated to the nearest whole second
//     unsigned long upSeconds = millis() / 1000;

//     // calculate days, truncated to nearest whole day
//     unsigned long days = upSeconds / 86400;

//     // the remaining hhmmss are
//     upSeconds = upSeconds % 86400;

//     // calculate hours, truncated to the nearest whole hour
//     unsigned long hours = upSeconds / 3600;

//     // the remaining mmss are
//     upSeconds = upSeconds % 3600;

//     // calculate minutes, truncated to the nearest whole minute
//     unsigned long minutes = upSeconds / 60;

//     // the remaining ss are
//     upSeconds = upSeconds % 60;

//     // allocate a buffer
//     char newTimeString[MaxString] = { 0 };

//     // construct the string representation
//     sprintf(
//         newTimeString,
//         "%lu %02lu:%02lu:%02lu",
//         days, hours, minutes, upSeconds
//     );

//     // has the time string changed since the last tft update?
//     if (strcmp(newTimeString,oldTimeString) != 0) {

//         // yes! home the cursor
//         tft.setCursor(0,0);

//         // change the text color to the background color
//         tft.setTextColor(Display_Backround_Color);

//         // redraw the old value to erase
//         tft.print(oldTimeString);

//         // home the cursor
//         tft.setCursor(0,0);

//         // change the text color to foreground color
//         tft.setTextColor(Display_Text_Color);

//         // draw the new time value
//         tft.print(newTimeString);

//         // and remember the new value
//         strcpy(oldTimeString,newTimeString);
//     }
// }


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

    // Adafruit_ST7789 tft = Adafruit_ST7789(TFT_CS, TFT_DC, TFT_RST);

    // displayUpTime();

    while(1){
        yield();
    }

    // apply
    // tft.enableDisplay(isDisplayVisible);

}
