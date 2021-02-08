// Copyright (C) 2019, 2020  Keyboard.io, Inc
//
// this is the style you want to emulate.
// This is the canonical layout file for the Quantum project. If you want to add another keyboard,

#include QMK_KEYBOARD_H

enum layer_names {
    _BASE,
    _NAV,
    _PUNC,
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  [_BASE] = LAYOUT( /* Qwerty */
    KC_Q,             KC_W,            KC_F,            KC_P,            KC_B,                                      KC_J,              KC_L,              KC_U,            KC_Y,            KC_SCLN    ,
    KC_A,             KC_R,            KC_S,            KC_T,            KC_G,                                      KC_M,              KC_N,              KC_E,            KC_I,            KC_O ,
    LCTL_T(KC_Z),     LALT_T(KC_X),    LGUI_T(KC_C),    LSFT_T(KC_D),    KC_V,                 KC_TAB,   KC_NO,     KC_K,              RSFT_T(KC_H),      RGUI_T(KC_COMM), LALT_T(KC_DOT),  LCTL_T(KC_SLSH) ,
    KC_NO,            KC_NO,           KC_NO,           KC_NO,           LT(_NAV, KC_BSPC),    KC_NO,    KC_ENT,    LT(_NAV, KC_SPC),  KC_NO,             KC_MINS,         KC_QUOT,         KC_NO ),

  [_NAV] = LAYOUT(
    KC_1,             KC_2,            KC_3,            KC_4,            KC_5,                                      KC_6,              KC_7,              KC_8,            KC_9,            KC_0,
    KC_LSFT,          LSFT(KC_9),      LALT_T(KC_LBRC), LGUI_T(KC_RBRC), LSFT(KC_0),                                KC_LEFT,           KC_DOWN,           KC_UP,           KC_RIGHT,        KC_GRV,
    KC_NO,            KC_NO,           KC_NO,           KC_NO,           KC_NO,                KC_NO,   KC_NO,      KC_NO,             KC_NO,             KC_NO,           KC_NO,           KC_BSLS,
    KC_TRNS,          KC_TRNS,         KC_TRNS,         KC_TRNS,         MO(_PUNC),            KC_BSPC, KC_ESC,     MO(_PUNC),         KC_TRNS,           KC_TRNS,         KC_TRNS,         KC_TRNS ),

  [_PUNC] = LAYOUT(
    LSFT(KC_1),       LSFT(KC_2),      LSFT(KC_3),      LSFT(KC_4),      LSFT(KC_5),                                LSFT(KC_6),        LSFT(KC_7),        LSFT(KC_8),      LSFT(KC_9),      LSFT(KC_0),
    KC_TRNS,          KC_TRNS,         KC_TRNS,         KC_TRNS,         KC_TRNS,                                   KC_TRNS,           KC_BSLS,           LSFT(KC_EQL),    LSFT(KC_QUOT),   LSFT(KC_MINS),
    KC_TRNS,          KC_TRNS,         KC_TRNS,         KC_TRNS,         KC_TRNS,              KC_TRNS, KC_TRNS,    KC_TRNS,           KC_SLSH,           KC_EQL,          KC_QUOT,         KC_MINS,
    RESET,            KC_TRNS,         KC_TRNS,         KC_TRNS,         KC_TRNS,              KC_TRNS, KC_TRNS,    KC_TRNS,           KC_TRNS,           KC_TRNS,         KC_TRNS,         KC_TRNS ),

  /*
   *  !       @     up     {    }        ||     pgup    7     8     9    *
   *  #     left   down  right  $        ||     pgdn    4     5     6    +
   *  [       ]      (     )    &        ||       `     1     2     3    \
   * lower  insert super shift bksp ctrl || alt space   fn    .     0    =
   */
  /*[_RS] = LAYOUT(
    KC_EXLM, KC_AT,   KC_UP,   KC_DLR,  KC_PERC,                  KC_PGUP, KC_7,    KC_8,   KC_9, KC_BSPC,
    KC_LPRN, KC_LEFT, KC_DOWN, KC_RGHT, KC_RPRN,                  KC_PGDN, KC_4,    KC_5,   KC_6, KC_BSLS,
    KC_LBRC, KC_RBRC, KC_HASH, KC_LCBR, KC_RCBR, KC_CIRC, KC_AMPR,KC_ASTR, KC_1,    KC_2,   KC_3, KC_PLUS,
    TG(_LW), KC_INS,  KC_LGUI, KC_LSFT, KC_BSPC, KC_LCTL, KC_LALT,KC_SPC,  KC_TRNS, KC_DOT, KC_0, KC_EQL ),*/
  /*
   * insert home   up  end   pgup       ||      up     F7    F8    F9   F10
   *  del   left  down right pgdn       ||     down    F4    F5    F6   F11
   *       volup             reset      ||             F1    F2    F3   F12
   *       voldn  super shift bksp ctrl || alt space   L0  prtsc scroll pause
   */
  /*[_LW] = LAYOUT(
    KC_INS,  KC_HOME, KC_UP,   KC_END,  KC_PGUP,                   KC_UP,   KC_F7,   KC_F8,   KC_F9,   KC_F10  ,
    KC_DEL,  KC_LEFT, KC_DOWN, KC_RGHT, KC_PGDN,                   KC_DOWN, KC_F4,   KC_F5,   KC_F6,   KC_F11  ,
    KC_NO,   KC_VOLU, KC_NO,   KC_NO,   RESET,   _______, _______, KC_NO,   KC_F1,   KC_F2,   KC_F3,   KC_F12  ,
    KC_NO,   KC_VOLD, KC_LGUI, KC_LSFT, KC_BSPC, KC_LCTL, KC_LALT, KC_SPC,  TO(_QW), KC_PSCR, KC_SLCK, KC_PAUS )*/
};
