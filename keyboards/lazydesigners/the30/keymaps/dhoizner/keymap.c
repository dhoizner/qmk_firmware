/* Copyright 2019 Erovia
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
  NE_SPACE,
  YQUOT_BSPC,
  QW_ESC,
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
/* const uint16_t PROGMEM space_combo[] = {KC_N, KC_E, COMBO_END}; */
const uint16_t PROGMEM backspace_combo[] = {KC_Y, KC_QUOT, COMBO_END};
const uint16_t PROGMEM escape_combo[] = {KC_Q, KC_W, COMBO_END};

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
  /* [NE_SPACE] = COMBO(space_combo, KC_SPC), */
  [YQUOT_BSPC] = COMBO(backspace_combo, KC_BSPC),
  [QW_ESC] = COMBO(escape_combo, KC_ESC)
};

enum custom_layers {
	_COLEMAKDHM,
	_FN,
    _RAISE
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [_COLEMAKDHM] = LAYOUT_ortho_3x10(
        KC_Q,    KC_W,    KC_F,    LT(_RAISE, KC_P),    KC_B,    KC_J,    LT(_RAISE, KC_L),    KC_U,    KC_Y,    KC_QUOT,
        LCTL_T(KC_A),    LALT_T(KC_R),    LGUI_T(KC_S),    LSFT_T(KC_T),    KC_G,    KC_M,    LSFT_T(KC_N),    LGUI_T(KC_E),    LALT_T(KC_I),    LCTL_T(KC_O),
        KC_Z,    KC_X,    KC_C,    KC_D,    KC_V,    KC_K,    KC_H,    KC_COMM, KC_DOT,  LT(_FN, KC_SLSH)
    ),
    [_FN] = LAYOUT_ortho_3x10(
        KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_6,    KC_7,    KC_8,    KC_9,    KC_0,
        _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
        RESET,   EEP_RST, _______, _______, KC_SPC,  _______, _______, _______, _______, _______
    ),
    [_RAISE] = LAYOUT_ortho_3x10(
        KC_TAB,    KC_2,    KC_3,    KC_4,    KC_5,    KC_6,    KC_7,    KC_8,    KC_9,    KC_0,
        KC_ESC, _______, _______, KC_BSPC, _______, _______, KC_SPC, _______, _______, _______,
        RESET,   EEP_RST, _______, KC_BSPC, KC_BSPC,  KC_SPC, KC_SPC, _______, _______, _______
    ),
};
