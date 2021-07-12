/*
Copyright 2012,2013 Jun Wako <wakojun@gmail.com>

This program is free software: you can redistribute it and/or modify
it under the terms of the GNU General Public License as published by
the Free Software Foundation, either version 2 of the License, or
(at your option) any later version.

This program is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU General Public License for more details.

You should have received a copy of the GNU General Public License
along with this program.  If not, see <http://www.gnu.org/licenses/>.
*/
#include "dhoizner.h"
#include "g/keymap_combo.h"

#define LAYOUT_wrapper(...)        LAYOUT_ortho_5x12_2x2uC(__VA_ARGS__)
#define LAYOUT_atlas_base(                            \
    K01, K02, K03, K04, K05, K06, K07, K08, K09, K0A, \
    K11, K12, K13, K14, K15, K16, K17, K18, K19, K1A, \
    K21, K22, K23, K24, K25, K26, K27, K28, K29, K2A  \
  ) \
  LAYOUT_wrapper( \
    ________________NUMBER_LEFT________________, _______, _______, ________________NUMBER_RIGHT_______________, \
    K01, K02, K03, K04, K05, _______, _______, K06, K07, K08, K09, K0A, \
    K11, K12, K13, K14, K15, _______, _______, K16, K17, K18, K19, K1A, \
    K21, K22, K23, K24, K25, _______, _______, K26, K27, K28, K29, K2A, \
    RGB_TOG, RGB_MOD, _______, _______, LT_BSPC, LT_SPC, _______, _______, _______, _______ \
  )
#define LAYOUT_atlas_base_wrapper(...) LAYOUT_atlas_base(__VA_ARGS__)


const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  [_BASE] = LAYOUT_atlas_base_wrapper(
    ______________COLEMAK_MOD_DH_L1____________, ______________COLEMAK_MOD_DH_R1____________,
    ______________COLEMAK_MOD_DH_L2____________, ______________COLEMAK_MOD_DH_R2____________,
    ______________COLEMAK_MOD_DH_L3____________, ______________COLEMAK_MOD_DH_R3____________
  ),
[_SYM] = LAYOUT_wrapper(
  _______, _______,    _______,    _______,    _______,    _______,    _______,    _______,    _______, _______,  _______, _______,
  _______, ________________NUMBER_1___________________, _______,    _______,    _______,    _______,    _______,    _______,    _______,    _______,
  KC_0,    ________________NUMBER_2___________________, KC_EQL,    KC_COLN,    _______,    _______,    _______,    _______,    _______,    KC_PLUS,
  KC_GRV,  ________________NUMBER_3___________________, KC_BSLS,    KC_TILD,    _______,    _______,    _______,    _______,    _______, KC_PIPE,
  _______, _______, _______, _______, _______,   _______,  _______,   _______,   _______, _______
),
[_NUM] = LAYOUT_wrapper( \
  _______, _______,    _______,    _______,    _______,    _______,    _______,    _______,    _______, _______,  _______, _______,
  _______, ________________NUMBER_1___________________, KC_DOT,    _______,    _______,    _______,    _______,    _______,    _______,    _______,
  KC_0,    ________________NUMBER_2___________________, NUM_G,    _______,    _______,    _______,    _______,    _______,    _______,    _______,
  KC_GRV,  ________________NUMBER_3___________________, _______,    _______,    _______,    _______,    _______,    _______,    _______, _______,
  _______, _______, _______, _______, _______,   CANCEL,  _______,   _______,   _______, _______
),
[_NAV] = LAYOUT_wrapper( \
  RESET,   _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
  _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
  _______, _______, _______, _______, _______, _______, _______, KC_LEFT, KC_DOWN, KC_UP,   KC_RGHT, _______,
  _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
  _______, _______, _______, _______, _______, _______, _______, _______, _______, _______
)
/* [_BLANK] = LAYOUT_ortho_5x12( \ */
/*   _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,  \ */
/*   _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, \ */
/*   _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,    \ */
/*   _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, \ */
/*   _______, _______, _______, _______, _______, _______, _______, _______, _______, _______ \ */
/* ), */
}
;
