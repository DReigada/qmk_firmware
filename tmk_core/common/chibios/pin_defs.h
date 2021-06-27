/* Copyright 2021 QMK
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
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

// Defines mapping for Proton C replacement
#ifdef CONVERT_TO_PROTON_C
// Left side (front)
#    define D3 PAL_LINE(GPIOA, 9)
#    define D2 PAL_LINE(GPIOA, 10)
//      GND
//      GND
#    define D1 PAL_LINE(GPIOB, 7)
#    define D0 PAL_LINE(GPIOB, 6)
#    define D4 PAL_LINE(GPIOB, 5)
#    define C6 PAL_LINE(GPIOB, 4)
#    define D7 PAL_LINE(GPIOB, 3)
#    define E6 PAL_LINE(GPIOB, 2)
#    define B4 PAL_LINE(GPIOB, 1)
#    define B5 PAL_LINE(GPIOB, 0)

// Right side (front)
//      RAW
//      GND
//      RESET
//      VCC
#    define F4 PAL_LINE(GPIOA, 2)
#    define F5 PAL_LINE(GPIOA, 1)
#    define F6 PAL_LINE(GPIOA, 0)
#    define F7 PAL_LINE(GPIOB, 8)
#    define B1 PAL_LINE(GPIOB, 13)
#    define B3 PAL_LINE(GPIOB, 14)
#    define B2 PAL_LINE(GPIOB, 15)
#    define B6 PAL_LINE(GPIOB, 9)

// LEDs (only D5/C13 uses an actual LED)
#    ifdef CONVERT_TO_PROTON_C_RXLED
#        define D5 PAL_LINE(GPIOC, 14)
#        define B0 PAL_LINE(GPIOC, 13)
#    else
#        define D5 PAL_LINE(GPIOC, 13)
#        define B0 PAL_LINE(GPIOC, 14)
#    endif
#else
// Keyboards can `#define KEYBOARD_REQUIRES_GPIOK` if they need to access GPIO-K pins. These conflict with a whole
// bunch of layout definitions, so it's intentionally left out unless absolutely required -- in that case, the
// keyboard designer should use a different symbol when defining their layout macros.
#    ifdef KEYBOARD_REQUIRES_GPIOK
#        define K0 PAL_LINE(GPIOK, 0)
#        define K1 PAL_LINE(GPIOK, 1)
#        define K2 PAL_LINE(GPIOK, 2)
#        define K3 PAL_LINE(GPIOK, 3)
#        define K4 PAL_LINE(GPIOK, 4)
#        define K5 PAL_LINE(GPIOK, 5)
#        define K6 PAL_LINE(GPIOK, 6)
#        define K7 PAL_LINE(GPIOK, 7)
#        define K8 PAL_LINE(GPIOK, 8)
#        define K9 PAL_LINE(GPIOK, 9)
#        define K10 PAL_LINE(GPIOK, 10)
#        define K11 PAL_LINE(GPIOK, 11)
#        define K12 PAL_LINE(GPIOK, 12)
#        define K13 PAL_LINE(GPIOK, 13)
#        define K14 PAL_LINE(GPIOK, 14)
#        define K15 PAL_LINE(GPIOK, 15)
#    endif
#endif
