/* Copyright 2018 REPLACE_WITH_YOUR_NAME
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
#ifndef FIGHTKEYB_H
#define FIGHTKEYB_H

#include "quantum.h"

/* This a shortcut to help you visually see your layout.
 *
 * The first section contains all of the arguments representing the physical
 * layout of the board and position of the keys.
 *
 * The second converts the arguments into a two-dimensional array which
 * represents the switch matrix.
 *
 *,----------------------
 *| k00 | k01 | k02 | k03|                       | k04 |
 *| NO | k10 | k11 |           | k12 | k13 | k14 | k15 |
 *| NO | NO | NO   | k20 |     | k21 | k22 | k23 | k24 |
 *| NO | NO | NO   | k30 |                                    |
 */
#define LAYOUT( \
    K00, K01, K02, K03,                   K04, \
         K10, K11,         K12, K13, K14, K15,   \
                   K20,    K21, K22, K23, K24, \
                   K30 \
) \
{ \
    { K00,   K01,   K02,   K03,   KC_NO, KC_NO, KC_NO, K04 }, \
    { KC_NO, K10,   K11,   KC_NO, K12,   K13,   K14,   K15 }, \
    { KC_NO, KC_NO, KC_NO, K20,   K21,   K22,   K23,   K24 }, \
    { KC_NO, KC_NO, KC_NO, K30,   KC_NO, KC_NO, KC_NO, KC_NO } \
}

#endif
