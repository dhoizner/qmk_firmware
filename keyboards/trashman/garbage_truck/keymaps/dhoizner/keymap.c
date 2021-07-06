/* Copyright 2021 Dan Hoizner
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
#include "dhoizner.h"
#include "g/keymap_combo.h"

#define LAYOUT_wrapper(...)            LAYOUT_all(__VA_ARGS__)
#define LAYOUT_garbage_truck_base(                    \
    K01, K02, K03, K04, K05, K06, K07, K08, K09, K0A, \
    K11, K12, K13, K14, K15, K16, K17, K18, K19, K1A, \
    K21, K22, K23, K24, K25, K26, K27, K28, K29, K2A  \
  ) \
  LAYOUT_wrapper( \
    _______, K01, K02, K03, K04, K05, K06, K07, K08, K09, K0A, _______, _______,          ________________NUMBER_1___________________, \
    _______, K11, K12, K13, K14, K15, K16, K17, K18, K19, K1A, _______,                   ________________NUMBER_2___________________, \
    _______, K21, K22, K23, K24, K25, K26, K27, K28, K29, K2A, _______,          KC_UP,   ________________NUMBER_3___________________, \
    _______, _______, LT_BSPC, LT_SPC, LT_ESC, _______,                 KC_LEFT, KC_DOWN, KC_RIGHT,  KC_0, KC_DOT  \
  )

#define LAYOUT_garbage_truck_base_wrapper(...) LAYOUT_garbage_truck_base(__VA_ARGS__)

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  [_BASE] = LAYOUT_garbage_truck_base_wrapper(
    ______________COLEMAK_MOD_DH_L1____________, ______________COLEMAK_MOD_DH_R1____________,
    ______________COLEMAK_MOD_DH_L2____________, ______________COLEMAK_MOD_DH_R2____________,
    ______________COLEMAK_MOD_DH_L3____________, ______________COLEMAK_MOD_DH_R3____________
  ),
  [_SYM] = LAYOUT_wrapper(
    _______, _______, ________________NUMBER_1___________________, _______, _______, _______, _______, _______, _______, _______, _______, _______,  _______, _______,
    _______, KC_0,    ________________NUMBER_2___________________,    KC_EQL,  KC_COLN, _______, _______, _______, KC_PLUS, _______,          _______,  _______, _______,
    _______, KC_GRV,  ________________NUMBER_3___________________,    KC_BSLS, KC_TILD, _______, _______, _______, KC_PIPE, _______, _______, _______,  _______, _______,
    _______, _______, _______,                   _______,          _______, _______,                   _______, _______, _______,  _______, _______
  ),
  [_NUM] = LAYOUT_wrapper(
    _______, _______, ________________NUMBER_1___________________,    KC_DOT,  _______, _______, _______, _______, _______, _______, _______, _______,  _______, _______,
    _______, KC_0,    ________________NUMBER_2___________________,    NUM_G,   _______, _______, _______, _______, _______, _______, _______,           _______, _______,
    _______, KC_DOT,  ________________NUMBER_3___________________,    _______, _______, _______, _______, _______, _______, _______, _______, _______,  _______, _______,
    _______, _______, _______,                   _______,          CANCEL,  _______,                   _______, _______, _______,  _______, _______
  ),
  /* //TODO fix layer taps and add in sym/num/nav layers */
  [_NAV] = LAYOUT_all(
    RESET,   _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,  _______, _______,
    _______, _______, _______, _______, _______, _______, KC_LEFT, KC_DOWN, KC_UP,   KC_RGHT, _______, _______,          _______,  _______, _______,
    _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,  _______, _______,
    _______, _______, _______,                   _______,          _______, _______,                   _______, _______, _______,  _______, _______
  )
  /*[_BLANK] = LAYOUT_all(
    _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,  _______, _______,
    _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,          _______,  _______, _______,
    _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,  _______, _______,
    _______, _______, _______,                   _______,          _______, _______,                   _______, _______, _______,  _______, _______
  )*/
};

void process_indicator_update(layer_state_t state, uint8_t usb_led) {

  if (state & (1<<1)) {
  writePinHigh(D6);
} else {
  writePinLow(D6);
}

  if (state & (1<<2)) {
  writePinHigh(D4);
} else {
  writePinLow(D4);
}

};

void keyboard_post_init_user(void) {
  setPinOutput(D7);
  writePinHigh(D7);
  setPinOutput(D6);
  setPinOutput(D4);
  process_indicator_update(layer_state, host_keyboard_leds());
};

void led_set_user(uint8_t usb_led) {
  process_indicator_update(layer_state, host_keyboard_leds());
};

layer_state_t layer_state_set_user(layer_state_t state) {
  process_indicator_update(state, host_keyboard_leds());
  return state;
};

void encoder_update_user(uint8_t index, bool clockwise) {
  if (index == 0) {
    if (clockwise) {
      tap_code(KC_VOLU);
    } else {
      tap_code(KC_VOLD);
    }
  }
}
