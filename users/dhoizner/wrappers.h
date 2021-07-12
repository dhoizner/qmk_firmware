#pragma once
#include "dhoizner.h"

// clang--ormat off
#define _________________QWERTY_L1_________________       KC_Q ,     KC_W,     KC_E ,    KC_R ,    KC_T
#define _________________QWERTY_L2_________________       KC_CA,     KC_AS,    KC_GD,    KC_SF,    KC_G
#define _________________QWERTY_L3_________________       KC_Z ,     KC_X,     KC_C ,    KC_V ,    KC_B

#define _________________QWERTY_R1_________________       KC_Y,      KC_U,     KC_I,     KC_O,    KC_P
#define _________________QWERTY_R2_________________       KC_SH,     KC_GJ,    KC_AK,    KC_CL,   KC_SCLN
#define _________________QWERTY_R3_________________       KC_N,      KC_M,     KC_COMM,  KC_DOT,  KC_SLSH


#define _________________COLEMAK_L1________________       KC_Q,      KC_W,     KC_F,     KC_P,     KC_G
#define _________________COLEMAK_L2________________       KC_CA,     KC_AR,    KC_GS,    KC_ST,    KC_D
#define _________________COLEMAK_L3________________       KC_Z,      KC_X,     KC_C,     KC_V,     KC_B

#define _________________COLEMAK_R1________________       KC_J,      KC_L,     KC_U,     KC_Y,     KC_SCLN
#define _________________COLEMAK_R2________________       KC_SH,     KC_GN,    KC_AE,    KC_CI,    KC_O
#define _________________COLEMAK_R3________________       KC_K,      KC_M,     KC_COMM,  KC_DOT,   KC_SLSH

#define ______________COLEMAK_MOD_DH_L1____________       KC_Q,      KC_W,     KC_F,     KC_P,     KC_B
#define ______________COLEMAK_MOD_DH_L2____________       KC_CA,     KC_AR,    KC_GS,    KC_ST,    KC_G
#define ______________COLEMAK_MOD_DH_L3____________       KC_Z,      KC_X,     KC_C,     KC_D,     KC_V

#define ______________COLEMAK_MOD_DH_R1____________       KC_J,     KC_L,     KC_U,     KC_Y,     KC_QUOT
#define ______________COLEMAK_MOD_DH_R2____________       KC_M,     KC_SN,    KC_GE,    KC_AI,    KC_CO
#define ______________COLEMAK_MOD_DH_R3____________       KC_K,     KC_H,     KC_COMM,  KC_DOT,   KC_SLASH


#define _________________DVORAK_L1_________________       KC_QUOT,  KC_COMM,  KC_DOT,  KC_P,      KC_Y
#define _________________DVORAK_L2_________________       KC_CA,    KC_AO,    KC_GE,   KC_SU,     KC_I
#define _________________DVORAK_L3_________________       KC_SCLN,  KC_Q,     KC_J,    KC_K,      KC_X

#define _________________DVORAK_R1_________________       KC_F,     KC_G,     KC_C,     KC_R,     KC_L
#define _________________DVORAK_R2_________________       KC_SD,    KC_GH,    KC_AT,    KC_CN,    KC_S
#define _________________DVORAK_R3_________________       KC_B,     KC_M,     KC_W,     KC_V,     KC_Z


#define _________________WORKMAN_L1________________       KC_Q,     KC_D,     KC_R,    KC_W,      KC_B
#define _________________WORKMAN_L2________________       KC_CA,    KC_AS,    KC_GH,   KC_ST,     KC_G
#define _________________WORKMAN_L3________________       KC_Z,     KC_X,     KC_M,    KC_C,      KC_V

#define _________________WORKMAN_R1________________       KC_J,     KC_F,     KC_U,     KC_P,     KC_SCLN
#define _________________WORKMAN_R2________________       KC_SY,    KC_GN,    KC_AE,    KC_CO,    KC_I
#define _________________WORKMAN_R3________________       KC_K,     KC_L,     KC_COMM,  KC_DOT,   KC_SLSH


#define _________________NORMAN_L1_________________       KC_Q,     KC_W,     KC_D,     KC_F,     KC_K
#define _________________NORMAN_L2_________________       KC_CA,    KC_AS,    KC_GE,    KC_ST,    KC_G
#define _________________NORMAN_L3_________________       KC_Z,     KC_X,     KC_C,     KC_V,     KC_B

#define _________________NORMAN_R1_________________       KC_J,     KC_U,     KC_R,     KC_L,     KC_SCLN
#define _________________NORMAN_R2_________________       KC_SY,    KC_GN,    KC_AI,    KC_CO,    KC_U
#define _________________NORMAN_R3_________________       KC_P,     KC_M,     KC_COMM,  KC_DOT,   KC_SLSH


#define ________________NUMBER_LEFT________________       KC_1,    KC_2,    KC_3,    KC_4,    KC_5
#define ________________NUMBER_RIGHT_______________       KC_6,    KC_7,    KC_8,    KC_9,    KC_0
#define ________________NUMBER_1___________________       KC_7,    KC_8,    KC_9
#define ________________NUMBER_2___________________       KC_1,    KC_2,    KC_3
#define ________________NUMBER_3___________________       KC_4,    KC_5,    KC_6
#define _________________FUNC_LEFT_________________       KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5
#define _________________FUNC_RIGHT________________       KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10

#define ___________________BLANK___________________       _______, _______, _______, _______, _______


#define _________________LOWER_L1__________________       KC_EXLM, KC_AT,   KC_HASH, KC_DLR,  KC_PERC
#define _________________LOWER_L2__________________       _________________FUNC_LEFT_________________
#define _________________LOWER_L3__________________       _________________FUNC_RIGHT________________

#define _________________LOWER_R1__________________       KC_CIRC, KC_AMPR, KC_ASTR, KC_LPRN, KC_RPRN
#define _________________LOWER_R2__________________       _______, KC_UNDS, KC_PLUS, KC_LCBR, KC_RCBR
#define _________________LOWER_R3__________________       _______, KC_HOME, KC_PGDN, KC_PGUP, KC_END



#define _________________RAISE_L1__________________       ________________NUMBER_LEFT________________
#define _________________RAISE_L2__________________       ___________________BLANK___________________
#define _________________RAISE_L3__________________       ___________________BLANK___________________

#define _________________RAISE_R1__________________       ________________NUMBER_RIGHT_______________
#define _________________RAISE_R2__________________       _______, KC_MINS, KC_EQL,  KC_LBRC, KC_RBRC
#define _________________RAISE_R3__________________       _______, KC_LEFT, KC_DOWN, KC_UP,   KC_RGHT



#define _________________ADJUST_L1_________________       RGB_MOD, RGB_HUI, RGB_SAI, RGB_VAI, RGB_TOG
#define _________________ADJUST_L2_________________       MU_TOG , CK_TOGG, AU_ON,   AU_OFF,  CG_NORM
#define _________________ADJUST_L3_________________       RGB_RMOD,RGB_HUD,RGB_SAD, RGB_VAD, KC_RGB_T

#define _________________ADJUST_R1_________________       KC_SEC1, KC_SEC2, KC_SEC3, KC_SEC4, KC_SEC5
#define _________________ADJUST_R2_________________       CG_SWAP, QWERTY,  COLEMAK, DVORAK,  WORKMAN
#define _________________ADJUST_R3_________________       MG_NKRO, KC_MUTE, KC_VOLD, KC_VOLU, KC_MNXT

// clang-format on
