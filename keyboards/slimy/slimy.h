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

#include "quantum.h"

#define LAYOUT_ortho_1x1( \
    k00 \
) { \
    { k00 } \
}

#define TIME(a, x) \
  do { \
    uint32_t timer_123 = timer_read32(); \
    {x} \
    dprintf("%s, DEBUG TIME: %ld \n", a, timer_elapsed32(timer_123)); \
  } while(0);
