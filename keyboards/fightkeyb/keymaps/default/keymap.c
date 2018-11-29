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
#include QMK_KEYBOARD_H

// Defines the keycodes used by our macros in process_record_user
enum custom_keycodes {
  QMKBEST = SAFE_RANGE,
  MAIN,
  ARROW,
  JOY
};

#define _MAIN 0
#define _ARROW 1
#define _JOY 2
#define _ADJ 3

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

  // 'Main' layer
  // ,-----------------------------------------------,
  // | ENTER | 2 | 3 | 4 |                   | FN    |
  // |                                               |
  // |       | A | S |           | G | H | J | K     |
  // |               | D |       | B | N | M | ,     |
  // |                                               |
  // |               | W |                           |
  // `----------------------------------------------'

  [_MAIN] = LAYOUT( /* Base */
    KC_ENT,  KC_2, KC_3, KC_4,                        MO(_ADJ),  \
           KC_A, KC_S,            KC_G, KC_H, KC_J, KC_K,   \
                       KC_D,      KC_B, KC_N, KC_M, KC_COMMA, \
                       KC_W
  ),

  [_ADJ] = LAYOUT( /* FN 1 */
    MAIN,  ARROW, JOY, _______,                        _______,  \
           XXXXXXX, XXXXXXX,            XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,   \
                       XXXXXXX,      XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, \
                       RESET
  ),

  // 'Arrow keys' layer
  // ,------------------------------------------------------,
  // | ENTER | 2 | 3 | 4 |                              | FN    |
  // |                                                          |
  // |      | LEFT | DOWN |               | G | H | J | K     |
  // |                    | RIGHT |       | B | N | M | ,     |
  // |                                                     |
  // |                    | UP |                           |
  // `-----------------------------------------------------'

  [_ARROW] = LAYOUT(
    KC_ENT,  KC_2, KC_3, KC_4,                        MO(_ADJ),  \
           KC_LEFT, KC_DOWN,               KC_G, KC_H, KC_J, KC_K,   \
                            KC_RIGHT,      KC_B, KC_N, KC_M, KC_COMMA, \
                            KC_UP
  ),

  // 'Joystick' layer (experimental)
  // ,------------------------------------------------------,
  // | ENTER | 2 | 3 | 4 |                              | FN    |
  // |                                                          |
  // |      | LEFT | DOWN |               | G | H | J | K     |
  // |                    | RIGHT |       | B | N | M | ,     |
  // |                                                     |
  // |                    | UP |                           |
  // `-----------------------------------------------------'

  [_JOY] = LAYOUT( /* Base */
    KC_ENT,  KC_2, KC_3, KC_4,                        MO(_ADJ),  \
           KC_LEFT, KC_DOWN,               KC_G, KC_H, KC_J, KC_K,   \
                            KC_RIGHT,      KC_B, KC_N, KC_M, KC_COMMA, \
                            KC_UP
  ),
};

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  switch (keycode) {
    case MAIN:
      if (record->event.pressed) {
        set_single_persistent_default_layer(_MAIN);
      }
      return false;
      break;
    case ARROW:
      if (record->event.pressed) {
        set_single_persistent_default_layer(_ARROW);
      }
      return false;
      break;
    case JOY:
      if (record->event.pressed) {
        set_single_persistent_default_layer(_JOY);
      }
  }
  return true;
}

void matrix_init_user(void) {

}

void matrix_scan_user(void) {

}

void led_set_user(uint8_t usb_led) {

}
