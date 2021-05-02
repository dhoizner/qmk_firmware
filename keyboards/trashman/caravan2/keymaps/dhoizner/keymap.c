#include "caravan2.h"
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
  [0] = LAYOUT(
      KC_TAB, KC_Q, KC_W, KC_F, KC_P, KC_B, KC_J, KC_L, KC_U, KC_Y, KC_QUOT, KC_BSPC,
      LT(4, KC_ESC), LCTL_T(KC_A), LALT_T(KC_R), LGUI_T(KC_S), LSFT_T(KC_T), KC_G, KC_M, RSFT_T(KC_N), RGUI_T(KC_E), LALT_T(KC_I), RCTL_T(KC_O), LT(4, KC_ENT),
      KC_LSFT, KC_Z, KC_X, KC_C, KC_D, KC_V, KC_K, KC_H, KC_COMM, KC_DOT, KC_SLSH, MO(2),
      KC_LCTL, MO(2), KC_NO, KC_LGUI, LT(2, KC_BSPC), LT(1, KC_SPC), KC_RALT, KC_RSFT, KC_RCTL, TG(3)
      ),
  [1] = LAYOUT(
      KC_GRV, KC_LBRC, KC_7, KC_8, KC_9, KC_RBRC, KC_LCBR, KC_AMPR, KC_ASTR, KC_LPRN, KC_RCBR, KC_DEL,
      KC_TRNS, KC_SCLN, KC_4, KC_5, KC_6, KC_EQL, KC_COLN, KC_DLR, KC_PERC, KC_CIRC, KC_PLUS, KC_TRNS,
      KC_TRNS, KC_GRV, KC_1, KC_2, KC_3, KC_BSLS, KC_TILD, KC_EXLM, KC_AT, KC_HASH, KC_PIPE, KC_TRNS,
      KC_TRNS, KC_TRNS, KC_NO, KC_DOT, KC_0, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, RESET
      ),
  [2] = LAYOUT(
      KC_TILD, KC_TRNS,         KC_LPRN,        KC_LBRC,        KC_LCBR,        KC_TRNS, KC_TRNS, KC_RCBR, KC_RBRC, KC_RPRN, KC_TRNS, KC_TRNS,
      KC_ESC,  KC_LCTL,         KC_LALT,        KC_LGUI,        LSFT_T(KC_MINS), KC_UNDS, KC_TRNS, KC_LEFT, KC_DOWN, KC_UP, KC_RIGHT, KC_TRNS,
      KC_TRNS, KC_RPRN,         KC_RBRC,        KC_LCBR,        KC_TRNS, KC_TRNS, KC_0, KC_1, KC_2, KC_3, KC_VOLD, KC_TRNS,
      KC_TRNS, KC_TRNS,         KC_NO,          KC_TRNS,        KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS
      ),
  [3] = LAYOUT(
      KC_TRNS, KC_F1, KC_F2, KC_F3, KC_F4, KC_TRNS, KC_TRNS, KC_F1, KC_F2, KC_F3, KC_F4, KC_TRNS,
      KC_ESC, LCTL_T(KC_F5), LALT(KC_F6), LGUI_T(KC_F7), LSFT_T(KC_F8), KC_TRNS, KC_TRNS, LSFT_T(KC_LEFT), LGUI_T(KC_DOWN), LALT_T(KC_UP), LCTL_T(KC_RIGHT), KC_TRNS,
      KC_LSFT, KC_F9, KC_F10, KC_F11, KC_F12, KC_5, KC_6, KC_F9, KC_F10, KC_F11, KC_F12, KC_TRNS,
      KC_TRNS, KC_LALT, KC_NO, KC_B, KC_SPC, KC_C, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS
      ),
  [4] = LAYOUT(
      KC_TILD, KC_7, KC_8, KC_LPRN, KC_RPRN, KC_5, KC_6, KC_7, KC_8, KC_9, KC_0, RGB_TOG,
      KC_ESC, KC_COLN, KC_EQL, KC_LBRC, KC_RBRC, KC_LCBR, KC_RCBR, RGB_HUD, RGB_HUI, RGB_RMOD, RGB_MOD, RGB_TOG,
      KC_TRNS, KC_TRNS, KC_TRNS, KC_LCBR, KC_RCBR, KC_TRNS, KC_0, KC_1, KC_2, KC_3, KC_VOLD, KC_TRNS,
      KC_TRNS, KC_TRNS, KC_NO, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS
      )
};
