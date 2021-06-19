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
#include "keycodes.h"
#include "casemodes.h"
#include "layermodes.h"
#include "g/keymap_combo.h"

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  [_BASE] = LAYOUT_all(
    KC_TAB,  KC_Q,    KC_W,    KC_F,    KC_P,    KC_B,    KC_J,    KC_L,    KC_U,    KC_Y,    KC_QUOT, KC_BSPC, KC_DEL,  KC_7,     KC_8,    KC_9,
    _______, KC_CA,   KC_AR,   KC_GS,   KC_ST,   KC_G,    KC_M,    KC_SN,   KC_GE,   KC_AI,   KC_CO,   _______,          KC_4,     KC_5,    KC_6,
    KC_LSFT, KC_Z,    KC_X,    KC_C,    KC_D,    KC_V,    KC_K,    KC_H,    KC_COMM, KC_DOT,  KC_SLSH, _______, KC_UP,   KC_1,     KC_2,    KC_3,
    _______, _______, LT_BSPC,                   LT_SPC,           LT_ESC,  _______,                   KC_LEFT, KC_DOWN, KC_RIGHT, KC_0,    KC_DOT
  ),
  [_SYM] = LAYOUT_all(
    _______, _______, KC_7,    KC_8,    KC_9,    _______, _______, _______, _______, _______, _______, _______, _______, _______,  _______, _______,
    _______, KC_0,    KC_1,    KC_2,    KC_3,    KC_EQL,  KC_COLN, _______, _______, _______, KC_PLUS, _______,          _______,  _______, _______,
    _______, KC_GRV,  KC_4,    KC_5,    KC_6,    KC_BSLS, KC_TILD, _______, _______, _______, KC_PIPE, _______, _______, _______,  _______, _______,
    _______, _______, _______,                   _______,          _______, _______,                   _______, _______, _______,  _______, _______
  ),
  [_NUM] = LAYOUT_all(
    _______, _______, KC_7,    KC_8,    KC_7,    KC_DOT,  _______, _______, _______, _______, _______, _______, _______, _______,  _______, _______,
    _______, KC_0,    KC_1,    KC_2,    KC_3,    NUM_G,   _______, _______, _______, _______, _______, _______, _______,           _______, _______,
    _______, KC_DOT,  KC_4,    KC_5,    KC_6,    _______, _______, _______, _______, _______, _______, _______, _______, _______,  _______, _______,
    _______, _______, _______,                   _______,          CANCEL,  _______,                   _______, _______, _______,  _______, _______
  ),
  //TODO fix layer taps and add in sym/num/nav layers
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

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  if (!process_num_word(keycode, record)) {
    switch (keycode) {
    }
    return false;
  }

  if (!process_case_modes(keycode, record)) {
    return false;
  }

  switch (keycode) {
    case SAVE_VIM:
      if (record->event.pressed) {
        tap_code(KC_ESC);
        tap_code16(KC_SPC);
        tap_code(KC_F);
        tap_code(KC_S);
      }
      return false;
    case NUMWORD:
      process_num_word_activation(record);
      return false;
    case CAPSWORD:
      if (record->event.pressed) {
        toggle_caps_word();
      }
      return false;
    case XCASE:
      if (record->event.pressed){
        toggle_xcase();
      }
      return false;
    case KC_N:
    case KC_E:
      if (record->event.pressed) {
        tap_code(keycode);
      }
      return false;
    case NUM_G:
      if (record->event.pressed) {
        tap_code16(S(KC_G));
      }
      return false;
    case CANCEL:
      layer_off(_NUM);
      disable_caps_word();
      disable_xcase();
      return false;
  }
#ifdef OLED_DRIVER_ENABLE
  if (record->event.pressed) {
    add_keylog(keycode);
  }
#endif
  return true;
}

bool terminate_case_modes(uint16_t keycode, const keyrecord_t *record) {
  switch (keycode) {
    // Keycodes to ignore (don't disable caps word)
    case KC_A ... KC_Z:
    case KC_1 ... KC_0:
    case KC_MINS:
    case KC_UNDS:
    case KC_BSPC:
      // If mod chording, disable the mods
      if (record->event.pressed && (get_mods() != 0)) {
        return true;
      }
      break;
    default:
      if (record->event.pressed) {
        return true;
      }
      break;
  }
  return false;
}

bool use_default_xcase_separator(uint16_t keycode, const keyrecord_t *record) {
  switch(keycode) {
    case KC_A ... KC_Z:
    case KC_1 ... KC_0:
      return true;
  }
  return false;
}
