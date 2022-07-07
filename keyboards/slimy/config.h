/*
Copyright 2015 Jun Wako <wakojun@gmail.com>

This program is free software: you can redistribute it and/or modify
it under the terms of the GNU General Public License as published by
the Free Software Foundation, either version 2 of the License, or
(at your option) any later version.

This program is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU General Public License for more details.

You should have received a copy of the GNU General Public License
along with this program.  If not, see <http://www.gnu.org/licenses/>.
*/

#pragma once

/* USB Device descriptor parameter */
#define VENDOR_ID       0xFEED
#define PRODUCT_ID      0x6465
#define DEVICE_VER      0x0001
#define MANUFACTURER    none
#define PRODUCT         slimy

#define LINE_PIN0 PAL_LINE(TEENSY_PIN0_IOPORT, TEENSY_PIN0)
/* key matrix size */
#define MATRIX_ROWS 4
#define MATRIX_COLS 12
#define MATRIX_ROW_PINS { LINE_PIN3, LINE_PIN2, LINE_PIN1, LINE_PIN0 }
#define MATRIX_COL_PINS { LINE_PIN11, LINE_PIN8, LINE_PIN7, LINE_PIN6, LINE_PIN5, LINE_PIN4, LINE_PIN12, LINE_PIN17, LINE_PIN20, LINE_PIN21, LINE_PIN22, LINE_PIN23 }
#define UNUSED_PINS

#define DIODE_DIRECTION COL2ROW

/* define if matrix has ghost */
//#define MATRIX_HAS_GHOST

/* Set 0 if debouncing isn't needed */
#define DEBOUNCE    5

#define TAPPING_TERM 500

/* Mechanical locking support. Use KC_LCAP, KC_LNUM or KC_LSCR instead in keymap */
#define LOCKING_SUPPORT_ENABLE
/* Locking resynchronize hack */
#define LOCKING_RESYNC_ENABLE

/*
 * Feature disable options
 *  These options are also useful to firmware size reduction.
 */

/* disable debug print */
//#define NO_DEBUG

/* disable print */
//#define NO_PRINT

/* disable action features */
//#define NO_ACTION_LAYER
//#define NO_ACTION_TAPPING
//#define NO_ACTION_ONESHOT
//#define NO_ACTION_MACRO
//#define NO_ACTION_FUNCTION

/*
 * I2C defines (trackball)
 */
#define I2C1_SCL_PIN        LINE_PIN19
#define I2C1_SDA_PIN        LINE_PIN18
#define I2C1_SCL_PAL_MODE   PAL_MODE_ALTERNATIVE_2
#define I2C1_SDA_PAL_MODE   PAL_MODE_ALTERNATIVE_2
// #define PIMORONI_TRACKBALL_DEBUG_INTERVAL 1000

/*
 * SPI defines (Display)
 */
#define SPI_DRIVER SPID1
#define SPI_SCK_PIN LINE_PIN14
#define SPI_MOSI_PIN LINE_PIN11
#define SPI_MISO_PIN LINE_PIN32 // Set to unused pin
#define SPI_CHIP_SELECT_PIN LINE_PIN10
#define SPI_RESET_PIN LINE_PIN16
#define SPI_DC_PIN LINE_PIN15
#define SPI_DIVISOR 2

#define PAL_MODE_ALTERNATE_PUSHPULL PAL_MODE_ALTERNATIVE_2


/*
 * Quantum painter config
 */
// #define QUANTUM_PAINTER_DEBUG TRUE
#define QP_PIXDATA_BUFFER_SIZE 1024*30
#define QUANTUM_PAINTER_SUPPORTS_256_PALETTE TRUE


/*
 * Backlight config
 */
#define BACKLIGHT_PIN LINE_PIN9
#define BACKLIGHT_LEVELS 31
#define BACKLIGHT_PWM_DRIVER PWMD1
#define BACKLIGHT_PWM_CHANNEL 3
