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
#include QMK_KEYBOARD_H

#define LT_ESC  LT(1, KC_ESC)
#define LT_QUOT LT(1, KC_QUOT)
#define LT_ENT  LT(2, KC_ENT)

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  [0] = LAYOUT_all(
    KC_TAB,  KC_Q,    KC_W,    KC_F,    KC_P,    KC_B,    KC_J,    KC_L,    KC_U,    KC_Y,    KC_QUOT, KC_BSPC, KC_DEL,  KC_7,     KC_8,    KC_9,
    LT_ESC,  KC_A,    KC_R,    KC_S,    KC_T,    KC_G,    KC_M,    KC_N,    KC_E,    KC_I,    KC_O,    LT_QUOT,          KC_4,     KC_5,    KC_6,
    KC_LSFT, KC_Z,    KC_X,    KC_C,    KC_D,    KC_V,    KC_K,    KC_H,    KC_COMM, KC_DOT,  KC_SLSH, LT_ENT,  KC_UP,   KC_1,     KC_2,    KC_3,
    KC_LCTL, MO(2),   KC_LGUI,                   KC_SPC,           KC_LALT, KC_RSFT,                   KC_LEFT, KC_DOWN, KC_RIGHT, KC_0,    KC_DOT
  ),
  [1] = LAYOUT_all(
    RESET,   _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,  _______, _______,
    _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,          _______,  _______, _______,
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
