#include "V4N4G0N.h"

enum combo_events {
  AR_LEFT_BRACE,
  RS_LEFT_BRACKET,
  ST_LEFT_PAREN,
  IO_RIGHT_BRACE,
  EI_RIGHT_BRACKET,
  NE_RIGHT_PAREN,
  WF_MINUS,
  UY_UNDERSCORE,
  FP_SEMICOLON,
  LU_COLON,
  COMBO_LENGTH
};
uint16_t COMBO_LEN = COMBO_LENGTH;

const uint16_t PROGMEM left_brace_combo[] = {LCTL_T(KC_A), LALT_T(KC_R), COMBO_END};
const uint16_t PROGMEM left_bracket_combo[] = {LALT_T(KC_R), LGUI_T(KC_S), COMBO_END};
const uint16_t PROGMEM left_paren_combo[] = {LGUI_T(KC_S), LSFT_T(KC_T), COMBO_END};
const uint16_t PROGMEM right_brace_combo[] = {LALT_T(KC_I), LCTL_T(KC_O), COMBO_END};
const uint16_t PROGMEM right_bracket_combo[] = {LGUI_T(KC_E), LALT_T(KC_I), COMBO_END};
const uint16_t PROGMEM right_paren_combo[] = {LSFT_T(KC_N), LGUI_T(KC_E), COMBO_END};
const uint16_t PROGMEM minus_combo[] = {KC_W, KC_F, COMBO_END};
const uint16_t PROGMEM semicolon_combo[] = {KC_F, KC_P, COMBO_END};
const uint16_t PROGMEM underscore_combo[] = {KC_U, KC_Y, COMBO_END};
const uint16_t PROGMEM colon_combo[] = {KC_L, KC_U, COMBO_END};

combo_t key_combos[] = {
  [ST_LEFT_PAREN] = COMBO(left_paren_combo, LSFT(KC_9)),
  [RS_LEFT_BRACKET] = COMBO(left_bracket_combo, KC_LBRACKET),
  [AR_LEFT_BRACE] = COMBO(left_brace_combo, LSFT(KC_LBRACKET)),
  [NE_RIGHT_PAREN] = COMBO(right_paren_combo, LSFT(KC_0)),
  [EI_RIGHT_BRACKET] = COMBO(right_bracket_combo, KC_RBRACKET),
  [IO_RIGHT_BRACE] = COMBO(right_brace_combo, LSFT(KC_RBRACKET)),
  [WF_MINUS] = COMBO(minus_combo, KC_MINS),
  [FP_SEMICOLON] = COMBO(semicolon_combo, KC_SCLN),
  [UY_UNDERSCORE] = COMBO(underscore_combo, KC_UNDS),
  [LU_COLON] = COMBO(colon_combo, KC_COLN),
};

enum custom_keycodes {
  M_IME = SAFE_RANGE
};

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  if (record->event.pressed) {
    switch(keycode) {
      case M_IME:
        SEND_STRING(SS_DOWN(X_LSHIFT)SS_DOWN(X_LALT));
        return false;
    }
  }
  else {
    switch(keycode) {
      case M_IME:
        SEND_STRING(SS_UP(X_LSHIFT)SS_UP(X_LALT));
        return false;
    }
  }
  return true;
};
const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  [0] = LAYOUT(KC_1, KC_2, KC_3, KC_4, KC_5, KC_6, KC_TAB, KC_Q, KC_W, KC_F, KC_P, KC_B, KC_J, KC_L, KC_U, KC_Y, KC_QUOT, KC_BSPC, LT(1, KC_ESC), LCTL_T(KC_A), LALT_T(KC_R), LGUI_T(KC_S), LSFT_T(KC_T), KC_G, KC_M, LSFT_T(KC_N), LGUI_T(KC_E), LALT_T(KC_I), LCTL_T(KC_O), LT(1, KC_ENT), KC_LSFT, KC_Z, KC_X, KC_C, KC_D, KC_V, KC_K, KC_H, KC_COMM, KC_DOT, KC_SLSH, KC_TRNS, KC_LCTL, MO(2), KC_LALT, KC_LGUI, LT(2, KC_BSPC), LT(1, KC_SPC), KC_RALT, KC_RSFT, KC_RCTL, TG(3)),
  [1] = LAYOUT(KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_LBRC, KC_7, KC_8, KC_9, KC_RBRC, KC_LCBR, KC_AMPR, KC_ASTR, KC_LPRN, KC_RCBR, KC_TRNS, KC_TRNS, KC_SCLN, KC_4, KC_5, KC_6, KC_EQL, KC_COLN, KC_DLR, KC_PERC, KC_CIRC, KC_PLUS, KC_TRNS, KC_TRNS, KC_GRV, KC_1, KC_2, KC_3, KC_BSLS, KC_TILD, KC_EXLM, KC_AT, KC_HASH, KC_PIPE, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_DOT, LT(3, KC_0), KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, RESET),
  [2] = LAYOUT(KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_LCTL, KC_LALT, KC_LGUI, KC_LSFT, KC_TRNS, KC_LEFT, KC_DOWN, KC_UP, KC_RIGHT, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, MO(3), KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS),
  [3] = LAYOUT(KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_F10, KC_F7, KC_F8, KC_F9, KC_F11, KC_TRNS, KC_MUTE, KC_MPLY, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_F4, KC_F5, KC_F6, KC_TRNS, KC_MPRV, KC_VOLD, KC_VOLU, KC_MNXT, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_F1, KC_F2, KC_F3, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS)
};


void process_indicator_update(layer_state_t state, uint8_t usb_led) {

  if (state & (1<<3)) {
  writePinHigh(B5);
} else {
  writePinLow(B5);
}

  if (state & (1<<3)) {
  writePinHigh(B4);
} else {
  writePinLow(B4);
}

};

void keyboard_post_init_user(void) {

  setPinOutput(B6);
  writePinHigh(B6);


  setPinOutput(B5);



  setPinOutput(B4);



  process_indicator_update(layer_state, host_keyboard_leds());
};

void led_set_user(uint8_t usb_led) {
  process_indicator_update(layer_state, host_keyboard_leds());
};

layer_state_t layer_state_set_user(layer_state_t state) {
  process_indicator_update(state, host_keyboard_leds());
  return state;
};
