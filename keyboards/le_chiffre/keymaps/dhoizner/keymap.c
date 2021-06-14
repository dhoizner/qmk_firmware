/* Copyright 2020 tominabox1
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

/* enum combo_events { */
/*   COMBO_BSPC, */
/*   COMBO_NUMBAK, */
/*   COMBO_TAB, */
/*   COMBO_ESC, */
/*   COMBO_DEL, */
/*   COMBO_LCBR, */
/*   COMBO_LBRC, */
/*   COMBO_LPRN, */
/*   COMBO_RCBR, */
/*   COMBO_RBRC, */
/*   COMBO_RPRN, */
/*   COMBO_MINUS, */
/*   COMBO_UNDERSCORE, */
/*   COMBO_SEMICOLON, */
/*   COMBO_COLON, */
/*   COMBO_LENGTH */
/* }; */
/* uint16_t COMBO_LEN = COMBO_LENGTH; */


const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  [_BASE] = LAYOUT(
    KC_Q,   KC_W,   KC_F,   KC_P,   KC_B,  KC_MPLY,  KC_J,   KC_L,    KC_U,   KC_Y,     KC_QUOT,
   KC_CA,  KC_AR,  KC_GS,  KC_ST,   KC_G,            KC_M,  KC_SN,   KC_GE,  KC_AI, KC_CO,
    KC_Z,   KC_X,   KC_C,   KC_D,   KC_V,            KC_K,   KC_H, KC_COMM, KC_DOT,  KC_SLSH,
                         KC_ENT, KC_NAV_BSPC,            KC_NUM_SPC, LT(_NAV, KC_ESC)
  ),

  [_NUM_SYM] = LAYOUT(
        KC_1,  KC_2,     KC_3,     KC_4,      KC_5,  KC_TRNS,     KC_6,     KC_7,     KC_8,     KC_9,     KC_0,
    KC_EXLM,  KC_AT,  KC_HASH,   KC_DLR,   KC_PERC,            KC_CIRC,  KC_AMPR,  KC_ASTR, KC_EQUAL,  KC_MINS,
    KC_BSLS,KC_LCBR,  KC_LBRC,  KC_LPRN,   KC_UNDS,            KC_RPRN,  KC_RBRC,  KC_RCBR,   KC_DOT,   KC_GRV,
                                KC_CAPS,   KC_TRNS,            KC_TRNS,  KC_TRNS
  ),
   /* [_NUM] = LAYOUT( */
   /*   _______, KC_N,    KC_E,    KC_PERC, _______,    _______, _______, _______, KC_DOT,  _______, KC_COMM, */
   /*   KC_6,    KC_4,    KC_0,    KC_2,    _______,          KC_J,    KC_3,    KC_1,    KC_5,    KC_7, */
   /*   KC_DQUO, _______, NUM_G,   KC_8,    _______,          KC_EQL,  KC_9,    KC_LPRN, KC_RPRN, KC_UNDS, */
   /*                              _______, _______,          CANCEL, _______ */
   /* ), */
   [_NUM] = LAYOUT(
     _______, KC_7,    KC_8,    KC_9,    _______,    _______, _______, _______, _______,  _______, _______,
     _______, KC_4,    KC_5,    KC_6,    NUM_G,               _______, _______,    _______,    _______,    _______,
     _______, KC_1,    KC_2,    KC_3,    _______,             _______,  _______,    _______, _______, _______,
                                KC_DOT, KC_0,                 _______, CANCEL
   ),
  [_NAV] = LAYOUT(
      RESET,  _______,  AG_NORM,  AG_SWAP,  DEBUG, KC_TRNS,   KC_GRV,  KC_PGDN,    KC_UP,  KC_PGUP,  KC_SCLN,
    RGB_TOG,  RGB_HUI,  RGB_SAI,  RGB_VAI,  KC_NO,           KC_LEFT,  KC_DOWN,  KC_UP,  KC_RGHT,   KC_END,
    RGB_MOD,  RGB_HUD,  RGB_SAD,  RGB_VAD,  KC_NO,           KC_MINS,    KC_RO,  KC_COMM,   KC_DOT,  KC_BSLS,
                                  KC_TRNS,KC_TRNS,           KC_ENT,  KC_TRNS
  ),
  /*
   [_BLANK] = LAYOUT(
     _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
     _______, _______, _______, _______, _______,          _______, _______, _______, _______, _______,
     _______, _______, _______, _______, _______,          _______, _______, _______, _______, _______,
                                _______, _______,          _______, _______
   ),
   */
};

bool encoder_update_user(uint8_t index, bool clockwise) {
    if (index == 0) {
        if (clockwise) {
            tap_code(KC_VOLU);
        } else {
            tap_code(KC_VOLD);
        }
    }

    return true;
}


/* #ifdef COMBO_ENABLE */
/* const uint16_t PROGMEM combo_bspc[] = {KC_Y, KC_QUOT, COMBO_END}; */
/* const uint16_t PROGMEM combo_numbak[] = {KC_0, KC_9, COMBO_END}; */
/* const uint16_t PROGMEM combo_tab[] = {KC_P, KC_L, COMBO_END}; */
/* const uint16_t PROGMEM combo_esc[] = {KC_ST, KC_SN, COMBO_END}; */
/* const uint16_t PROGMEM combo_del[] = {KC_MINS, KC_EQL, COMBO_END}; */
/* const uint16_t PROGMEM combo_lcbr[] = {KC_CA, KC_AR, COMBO_END}; */
/* const uint16_t PROGMEM combo_lbrc[] = {KC_AR, KC_GS, COMBO_END}; */
/* const uint16_t PROGMEM combo_lprn[] = {KC_GS, KC_ST, COMBO_END}; */
/* const uint16_t PROGMEM combo_rcbr[] = {KC_AI, KC_CO, COMBO_END}; */
/* const uint16_t PROGMEM combo_rbrc[] = {KC_GE, KC_AI, COMBO_END}; */
/* const uint16_t PROGMEM combo_rprn[] = {KC_SN, KC_GE, COMBO_END}; */
/* const uint16_t PROGMEM combo_minus[] = {KC_W, KC_F, COMBO_END}; */
/* const uint16_t PROGMEM combo_underscore[] = {KC_U, KC_Y, COMBO_END}; */
/* const uint16_t PROGMEM combo_semicolon[] = {KC_F, KC_P, COMBO_END}; */
/* const uint16_t PROGMEM combo_colon[] = {KC_L, KC_U, COMBO_END}; */


/* combo_t key_combos[] = { */
/*   [COMBO_BSPC] = COMBO(combo_bspc,KC_BSPC), */
/*   [COMBO_NUMBAK] = COMBO(combo_numbak,KC_BSPC), */
/*   [COMBO_TAB] = COMBO(combo_tab,KC_TAB), */
/*   [COMBO_ESC] = COMBO(combo_esc,KC_ESC), */
/*   [COMBO_DEL] = COMBO(combo_del,KC_DEL), */
/*   [COMBO_LCBR] = COMBO(combo_lcbr, KC_LCBR), */
/*   [COMBO_LBRC] = COMBO(combo_lbrc, KC_LBRC), */
/*   [COMBO_LPRN] = COMBO(combo_lprn, KC_LPRN), */
/*   [COMBO_RCBR] = COMBO(combo_rcbr, KC_RCBR), */
/*   [COMBO_RBRC] = COMBO(combo_rbrc, KC_RBRC), */
/*   [COMBO_RPRN] = COMBO(combo_rprn, KC_RPRN), */
/*   [COMBO_MINUS] = COMBO(combo_minus, KC_MINS), */
/*   [COMBO_UNDERSCORE] = COMBO(combo_underscore, KC_UNDS), */
/*   [COMBO_SEMICOLON] = COMBO(combo_semicolon, KC_SCLN), */
/*   [COMBO_COLON] = COMBO(combo_colon, KC_COLN), */

/* }; */
/* #endif */

#ifdef OLED_DRIVER_ENABLE  //Special thanks to Sickbabies for this great OLED widget!
oled_rotation_t oled_init_user(oled_rotation_t rotation) {
    return OLED_ROTATION_90;  // rotates for proper orientation
}

void render_lechiffre_logo(void) {
    static const char PROGMEM lechiffre_logo[] = {
	// 'lechiffre_logo', 32x20px
   0x00, 0x3e, 0x20, 0x20, 0x00, 0x18, 0x2c, 0xa8, 0x80, 0x00, 0x1c, 0x22, 0x22, 0x00, 0x3e, 0x08,
0x30, 0x00, 0x34, 0x00, 0x3c, 0x0a, 0x00, 0xbc, 0x8a, 0x00, 0x38, 0x08, 0x00, 0x18, 0x2c, 0x28,
0x00, 0xb6, 0xb6, 0x00, 0xdb, 0xdb, 0x00, 0x6d, 0x6d, 0x00, 0xdb, 0xdb, 0x00, 0xdb, 0xdb, 0x00,
0x00, 0xdb, 0xdb, 0x00, 0xdb, 0xdb, 0x00, 0x6d, 0x6d, 0x00, 0xdb, 0xdb, 0x00, 0xb6, 0xb6, 0x00,
0x00, 0x01, 0x01, 0x00, 0x00, 0x00, 0x06, 0x06, 0x06, 0x00, 0x06, 0x06, 0x06, 0x06, 0x06, 0x00,
0x00, 0x06, 0x06, 0x06, 0x06, 0x06, 0x00, 0x06, 0x06, 0x06, 0x00, 0x00, 0x00, 0x01, 0x01, 0x00
};

  oled_write_raw_P(lechiffre_logo, sizeof(lechiffre_logo));
}

static void render_layer_status(void) {
    oled_write_P(PSTR("-----"), false);
    switch (get_highest_layer(layer_state)) {
        case _BASE:
            oled_write_ln_P(PSTR("BASE"), false);
            break;
        case _NUM_SYM:
            oled_write_ln_P(PSTR(" SYM"), false);
            break;
        case _NAV:
            oled_write_ln_P(PSTR(" NAV"), false);
            break;
          case _NUM:
            oled_write_ln_P(PSTR(" NUM"), false);
            break;
        default:
            oled_write_ln_P(PSTR("?????"), false);
    }
}

#    define KEYLOG_LEN 11
char     keylog_str[KEYLOG_LEN] = {};
uint8_t  keylogs_str_idx        = 0;
uint16_t log_timer              = 0;

const char code_to_name[60] = {
    ' ', ' ', ' ', ' ', 'a', 'b', 'c', 'd', 'e', 'f',
    'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n', 'o', 'p',
    'q', 'r', 's', 't', 'u', 'v', 'w', 'x', 'y', 'z',
    '1', '2', '3', '4', '5', '6', '7', '8', '9', '0',
    'R', 'E', 'B', 'T', '_', '-', '=', '[', ']', '\\',
    '#', ';', '\'', '`', ',', '.', '/', ' ', ' ', ' '};

void add_keylog(uint16_t keycode) {
    if ((keycode >= QK_MOD_TAP && keycode <= QK_MOD_TAP_MAX) || (keycode >= QK_LAYER_TAP && keycode <= QK_LAYER_TAP_MAX)) {
        keycode = keycode & 0xFF;
    }

    for (uint8_t i = KEYLOG_LEN - 1; i > 0; i--) {
        keylog_str[i] = keylog_str[i - 1];
    }
    if (keycode < 60) {
        keylog_str[0] = code_to_name[keycode];
    }
    keylog_str[KEYLOG_LEN - 1] = 0;

    log_timer = timer_read();
}

void update_log(void) {
    if (timer_elapsed(log_timer) > 750) {
        add_keylog(0);
    }
}

//Text only renders
void render_keylogger_status(void) {
    oled_write_P(PSTR("-----"), false);
    oled_write(keylog_str, false);
}

void render_keylock_status(led_t led_state) {
    oled_write_P(PSTR("-----"), false);
    oled_write_P(PSTR("C"), led_state.caps_lock);
	oled_write_P(PSTR(" "), false);
    oled_write_P(PSTR("N"), led_state.num_lock);
	oled_write_P(PSTR(" "), false);
    oled_write_P(PSTR("S"), led_state.scroll_lock);
    //oled_write_ln_P(PSTR(" "), false);
}

void render_mod_status(uint8_t modifiers) {
       oled_write_P(PSTR("-----"), false);
    oled_write_ln_P(PSTR("SHFT"), (modifiers & MOD_MASK_SHIFT));
    oled_write_ln_P(PSTR("ALT"), (modifiers & MOD_MASK_ALT));
    oled_write_ln_P(PSTR("CTRL"), (modifiers & MOD_MASK_CTRL));
    oled_write_ln_P(PSTR("GUI"), (modifiers & MOD_MASK_GUI));
}

void oled_task_user(void) {
    render_lechiffre_logo();
    oled_set_cursor(0,3);
    render_layer_status();	// Renders the current keyboard state (layer, lock, caps, scroll, etc)
	render_mod_status(get_mods()|get_oneshot_mods());
	render_keylock_status(host_keyboard_led_state());
	render_keylogger_status();
}

#endif

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
  return true;
#endif
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
