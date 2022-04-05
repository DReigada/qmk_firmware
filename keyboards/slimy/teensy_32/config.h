/* Copyright 2019
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */

#pragma once

// TODO: including this causes "error: expected identifier before '(' token" errors
//#include "config_common.h"

#define MATRIX_COL_PINS { LINE_PIN30 }
#define MATRIX_ROW_PINS { LINE_PIN31 }
#define UNUSED_PINS

// i2c_master defines
#define I2C1_SCL_PIN        LINE_PIN19
#define I2C1_SDA_PIN        LINE_PIN18
#define I2C1_SCL_PAL_MODE   PAL_MODE_ALTERNATIVE_2
#define I2C1_SDA_PAL_MODE   PAL_MODE_ALTERNATIVE_2

// SPI defines
#define SPI_DRIVER SPID1


#define SPI_SCK_PIN LINE_PIN14
// define SPI_SCK_PAL_MODE PAL_MODE_ALTERNATIVE_2

#define SPI_MOSI_PIN LINE_PIN11
// define SPI_MOSI_PAL_MODE PAL_MODE_ALTERNATIVE_2

#define SPI_MISO_PIN LINE_PIN12
// define SPI_MISO_PAL_MODE PAL_MODE_ALTERNATIVE_2


#define PAL_MODE_ALTERNATE_PUSHPULL PAL_MODE_ALTERNATIVE_2


#define SPI_CHIP_SELECT_PIN LINE_PIN10
#define SPI_RESET_PIN LINE_PIN16
#define SPI_DC_PIN LINE_PIN15
#define SPI_DIVISOR 2 //idk ??

// #define QUANTUM_PAINTER_DEBUG TRUE
