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
#include "status.h"
#include "oneshot.h"
#include "casemodes.h"
#include "layermodes.h"
#include "tap_hold.h"

#include "g/keymap_combo.h"

#ifdef ENCODER_ENABLE
#    include "encoder_utils.h"
#endif

#ifdef OLED_DRIVER_ENABLE
#    include "oled_utils.h"
#endif

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  [_BASE] = LAYOUT(
    KC_Q,     KC_W,    KC_F,    KC_P,    KC_B,    KC_MPLY, KC_J,    KC_L,    KC_U,    KC_Y,    KC_QUOT,
    KC_A,     KC_R,    KC_S,    KC_T,    KC_G,             KC_M,    KC_N,    KC_E,    KC_I,    KC_O,
    KC_Z,     KC_X,    KC_C,    KC_D,    KC_V,             KC_K,    KC_H,    KC_COMM, KC_DOT,  KC_SLSH,
                                LT(_LMOD, KC_ESC), MT_BSPC,          MT_SPC,  LT(_RMOD, KC_ESC)
  ),
   [_NUM] = LAYOUT(
     _______, _______, KC_K,    KC_PERC, KC_J,    _______, _______, _______, KC_DOT,  _______, KC_COMM,
     KC_6,    KC_4,    KC_0,    KC_2,    _______,          KC_J,    KC_3,    KC_1,    KC_5,    KC_7,
     KC_DQUO, _______, NUM_G,   KC_8,    _______,          KC_EQL,  KC_9,    KC_LPRN, KC_RPRN, KC_UNDS,
                                _______, _______,          CANCEL, _______
   ),
   [_NAV] = LAYOUT(
     SC_TAB , C_TAB,   KC_UP,   KC_PGUP, KC_HOME, _______, _______, _______, _______, _______, _______,
     _______, KC_LEFT, DN_CTRL, KC_RGHT, KC_ENT,           _______, KC_LEFT, KC_DOWN, KC_UP,   KC_RGHT,
     RESET,   _______, _______, KC_PGDN, KC_END,           _______, _______, _______, _______, _______,
                                _______, _______,          _______, _______
   ),
   // TODO implement WNAV?
   [_LMOD] = LAYOUT(
     OPT,     C(KC_A), C(KC_W), _______, _______, _______, _______, KC_HASH, KC_DOT, KC_AT,    KC_COMM,
     OS_CTRL, OS_ALT,  OS_GUI,  OS_SHFT, _______,          GRV,     KC_QUES, KC_LBRC, KC_RBRC, _______,
     C(KC_Z), C(KC_X), _______, _______, _______,          KC_EQL,  KC_AMPR, KC_LPRN, KC_RPRN, KC_UNDS,
                                _______, _______,          CLEAR,   FUN
   ),
   [_RMOD] = LAYOUT(
     TILD,    KC_PLUS, KC_ASTR, KC_PERC, _______, _______, _______, _______, _______, _______, _______,
     KC_PIPE, KC_LCBR, KC_RCBR, KC_MINS, KC_BSLS,          _______, OS_SHFT, OS_GUI,  OS_ALT,  OS_CTRL,
     KC_DQUO, KC_LABK, KC_RABK, KC_EXLM, _______,          _______, _______, _______, _______, MY_RALT,
                                FUN, _______,              _______, _______
   ),
   [_FUN] = LAYOUT(
     _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
     KC_F6,   KC_F4,   KC_F10,  KC_F2,   KC_F12,           KC_F11,  KC_F3,   KC_F1,   KC_F5,   KC_F7,
     _______, _______, _______, KC_F8,   _______,          _______, KC_F9,   _______, _______, _______,
                                _______, _______,          _______, CLEAR
   ),
   [_OPT] = LAYOUT(
     _______, TG_CAPS, _______, _______, _______, _______, _______, TG_NIX,  _______, _______, _______,
     _______, _______, KC_CAPS, _______, _______,          _______, TO_NUM, _______, _______, _______,
     _______, _______, _______, _______, _______,          _______, _______, _______, _______, _______,
                                _______, _______,          _______, _______
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

uint16_t get_combo_term(uint16_t index, combo_t *combo) {
  switch (index) {
    // Home-row and other tight combos
    case tab:
    case escape:
    case scln:
    case slsh:
    case coln:
    case enter:
    case quot:
    case circ:
    case dlr:
    case vsp:
      return COMBO_TERM;
    // Vertical combos, very relaxed
    case small_left_arrow:
    case lt_eq:
    case large_right_arrow:
    case small_right_arrow:
    case pipe_to:
    case sp:
    case gt_eq:
      return COMBO_TERM + 55;
    // Regular combos, slightly relaxed
    default:
      return COMBO_TERM + 35;
  }
}

bool get_combo_must_tap(uint16_t index, combo_t *combo) {
  switch(index) {
    case del:
    case backsp:
    case num:
    case sp_ampr:
    case sp_pipe:
    case sp_plus:
    case sp_astr:
    case sp_mins:
    case sp_unds:
    case sp_perc:
    case sp_grv:
    case sp_labk:
    case sp_rabk:
    case sp_lbrc:
    case sp_lprn:
    case sp_bsls:
    case sp_hash:
    case slsh:
      return false;
    default:
      return true;
  }
}

static bool linux_mode = true;
bool in_linux(void) {
  return linux_mode;
}

static bool swap_caps_escape = true;
bool is_caps_swapped(void) {
  return swap_caps_escape;
}

bool tap_undead_key(bool key_down, uint16_t code) {
  if (key_down) {
    tap_code16(code);
    tap_code16(KC_SPACE);
  }
  return false;
}

void swap_caps_esc(void) {
  swap_caps_escape = !swap_caps_escape;
# ifdef OLED_DRIVER_ENABLE
    oled_on();
# endif
}

void tg_nix(void) {
  linux_mode = !linux_mode;
# ifdef OLED_DRIVER_ENABLE
    oled_on();
# endif
}

bool process_caps(bool key_down) {
  if (swap_caps_escape) {
    if (key_down) {
      register_code(KC_ESC);
    } else {
      unregister_code(KC_ESC);
    }
    return false;
  }
  return true;
}

bool process_escape(bool key_down) {
  if (swap_caps_escape) {
    if (key_down) {
      register_code(KC_CAPS);
    } else {
      unregister_code(KC_CAPS);
    }
    return false;
  }
  return true;
}

void tap_escape(void) {
  tap_code(swap_caps_escape ? KC_CAPS : KC_ESC);
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

/* void enable_gaming(void) { */
/*   autoshift_disable(); */
/*   layer_on(_GAME); */
/* } */
/* void disable_gaming(void) { */
/*   autoshift_enable(); */
/*   layer_off(_GAME); */
/*   layer_off(_GAME2) */
/* } */

void tap_space_shift(uint16_t key, bool key_down) {
  if (key_down) {
    tap_code16(key);
    tap_code(KC_SPC);
    set_oneshot_mods(MOD_BIT(KC_LSFT));
  }
}

void double_tap(uint16_t keycode) {
  tap_code16(keycode);
  tap_code16(keycode);
}

void triple_tap(uint16_t keycode) {
  tap_code16(keycode);
  tap_code16(keycode);
  tap_code16(keycode);
}

void double_parens_left(uint16_t left, uint16_t right) {
  tap_code16(left);
  tap_code16(right);
  tap_code16(KC_LEFT);
}

bool is_oneshot_cancel_key(uint16_t keycode) {
  switch (keycode) {
    case CLEAR:
    case LMOD:
    case RMOD:
      return true;
    default:
      return false;
  }
}

bool is_oneshot_ignored_key(uint16_t keycode) {
  switch (keycode) {
    case CLEAR:
    case LMOD:
    case RMOD:
      return true;
    case OS_SHFT:
    case OS_CTRL:
    case OS_ALT:
    case OS_GUI:
      return false;
    default:
      return false;
  }
}

oneshot_state os_shft_state = os_up_unqueued;
oneshot_state os_ctrl_state = os_up_unqueued;
oneshot_state os_alt_state = os_up_unqueued;
oneshot_state os_gui_state = os_up_unqueued;

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  if (!process_num_word(keycode, record)) {
    return false;
  }
  /* if (!process_sym_word(keycode, record)) { */
  /*   return false */
  /* } */
  /* if(process_case_modes(keycode, recoooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooOoooooooooooooooooooooooooooo)) */

  update_oneshot(
    &os_shft_state, KC_LSFT, OS_SHFT,
    keycode, record
  );
  update_oneshot(
    &os_ctrl_state, KC_LCTL, OS_CTRL,
    keycode, record
  );
  update_oneshot(
    &os_alt_state, KC_LALT, OS_ALT,
    keycode, record
  );
  update_oneshot(
    &os_gui_state, KC_LGUI, OS_GUI,
    keycode, record
  );

  switch (keycode) {
    case KC_ESC:
      return process_escape(record->event.pressed);
    case KC_CAPS:
      return process_caps(record->event.pressed);
    case TG_NIX:
      if (record->event.pressed) {
        tg_nix();
      }
      return false;
    case TG_CAPS:
      if (record->event.pressed) {
        swap_caps_esc();
      }
      return false;
    case CLEAR:
      clear_oneshot_mods();
      if (get_oneshot_layer() != 0) {
        clear_oneshot_layer_state(ONESHOT_OTHER_KEY_PRESSED);
      }
      layer_move(_BASE);
      return false;
    case TILD:
      return tap_undead_key(record->event.pressed, KC_TILD);
    case CIRC:
      return tap_undead_key(record->event.pressed, KC_CIRC);
    case MY_000:
      if (record->event.pressed) {
        triple_tap(KC_0);
      }
      return false;
    case TO_NUM:
      layer_on(_NUM);
      return false;
    case NUMWORD:
      process_num_word_activation(record);
      return false;
    case CAPSWORD:
      if (record->event.pressed) {
        enable_caps_word();
      }
      return false;
    case CAPSWORD:
      if (record->event.pressed) {
        enable_caps_word();
      }
      return false;
    case SAVE_VIM:
      if (record->event.pressed) {
        tap_escape();
        tap_code16(KC_COLN);
        tap_code(KC_W);
        tap_code(KC_ENT);
      }
      return false;
    case CLOSE_VIM:
      if (record->event.pressed) {
        tap_escape();
        tap_code16(KC_COLN);
        tap_code(KC_Q);
        tap_code(KC_ENT);
      }
      return false;
    case VIM_SP:
      if (record->event.pressed) {
        tap_code16(C(KC_W));
        tap_code(KC_S);
      }
      return false;
    case VIM_VS:
      if (record->event.pressed) {
        tap_code16(C(KC_W));
        tap_code(KC_V);
      }
      return false;
    case NUM_G:
      if (record->event.pressed) {
        tap_code16(S(KC_G));
      }
      return false;
    case CANCEL:
      layer_off(_NUM);
      layer_off(_LMOD);
      layer_off(_RMOD);
      /* disable_gaming(); */
      return false;
    /* case TO_GAME: */
    /*   if (record->event.pressed) { */
    /*     enable_gaming(); */
    /*   } */
    /*   return false; */
    case KC_TAB:
      if (record->event.pressed) {
        switch (get_highest_layer(layer_state)) {
          case _LMOD:
          case _RMOD:
            tap_code16(C(S(KC_TAB)));
            break;
          case _NAV:
            tap_code16(C(KC_TAB));
            break;
        default:
          tap_code16(KC_TAB);
        }
      }
      return false;
    case KC_ENT:
      if (record->event.pressed) {
        switch (get_highest_layer(layer_state)) {
          case _NUM:
            tap_code(KC_PENT);
            break;
            /* case _WNAV: */
            /*   tap_code16(G(KC_ENT)); */
            /*   break; */
            default:
              tap_code(KC_ENT);
        }
      }
      return false;
    case KC_AMPR:
    case KC_PIPE:
    case KC_PLUS:
    case KC_ASTR:
    case KC_MINS:
    case KC_UNDS:
    case KC_LABK:
    case KC_RABK:
    case KC_HASH:
    case KC_BSLS:
    case KC_SLSH:
    case KC_DQUO:
    case KC_DOT:
    case KC_EQL:
    case KC_EXLM:
    case KC_PERC:
    case GRV:
    case KC_LPRN:
    case KC_LCBR:
    case KC_LBRC:
    case KC_0:
    case G(KC_0):
    case G(KC_1):
    case G(KC_2):
    case G(KC_3):
    case G(KC_4):
    case G(KC_5):
    case G(KC_6):
    case G(KC_7):
    case G(KC_8):
    case G(KC_9):
    case G(KC_K):
    case G(KC_J):
    case G(KC_W):
    case G(KC_E):
    case G(KC_R):
    case G(KC_C):
      process_tap_hold(keycode, record);
      return false;
  }

  return true;
}

void tap_hold_send_hold(uint16_t keycode) {
  switch (keycode) {
    case KC_AMPR:
    case KC_PIPE:
    case KC_PLUS:
    case KC_ASTR:
    case KC_MINS:
    case KC_UNDS:
    case KC_LABK:
    case KC_RABK:
    case KC_HASH:
    case KC_BSLS:
    case KC_SLSH:
      double_tap(keycode);
      return;
    case KC_DQUO:
    case KC_DOT:
    case KC_EQL:
    case KC_0:
      triple_tap(keycode);
      return;
    case KC_PERC:
      send_string("%{}");
      return;
    case GRV:
      tap_undead_key(true, KC_GRV);
      tap_undead_key(true, KC_GRV);
      tap_undead_key(true, KC_GRV);
      return;
    case KC_LPRN:
      double_parens_left(keycode, KC_RPRN);
      return;
    case KC_LCBR:
      double_parens_left(keycode, KC_RCBR);
      return;
    case KC_LBRC:
      double_parens_left(keycode, KC_RBRC);
      return;
    case G(KC_0):
    case G(KC_1):
    case G(KC_2):
    case G(KC_3):
    case G(KC_4):
    case G(KC_5):
    case G(KC_6):
    case G(KC_7):
    case G(KC_8):
    case G(KC_9):
    case G(KC_K):
    case G(KC_J):
    case G(KC_W):
    case G(KC_E):
    case G(KC_R):
    case G(KC_C):
      tap_code16(S(keycode));
      return;
  }
}

void tap_hold_send_tap(uint16_t keycode) {
  switch (keycode) {
    case GRV:
      tap_undead_key(true, KC_GRV);
      return;
    default:
      tap_code16(keycode);
  }
}

void matrix_scan_user(void) {
  tap_hold_matrix_scan();
}

#ifdef OLED_DRIVER_ENABLE
oled_rotation_t oled_init_user(oled_rotation_t rotation) {
  return OLED_ROTATION_90;
}

void oled_task_user(void) {
  render_status();
}
#endif

#ifdef ENCODER_ENABLE
bool encoder_update_user(uint8_t index, bool clockwise) {
  if (index == 0) {
    action_left_encoder(clockwise);
#  ifdef OLED_DRIVER_ENABLE
    oled_on();
#  endif
  } else if (index == 1) {
    action_right_encoder(clockwise);
#  ifdef OLED_DRIVER_ENABLE
    oled_on();
#  endif
  }
  return true;
}
#endif

#ifdef TAPPING_TERM_PER_KEY

#define THUMB_TERM 20
#define INDEX_TERM -20
#define MIDDLE_TERM 0
#define RING_TERM 80
#define PINKY_TERM 180

uint16_t get_tapping_term(uint16_t keycode, keyrecord_t *record) {
  switch (keycode) {
    case MT_SPC:
      return TAPPING_TERM + THUMB_TERM;
    case DN_CTRL:
      return TAPPING_TERM + MIDDLE_TERM;
    default:
      return TAPPING_TERM;
  }
}
#endif

/* void encoder_update_user(uint8_t index, bool clockwise) { */
/*     if (index == 0) { */
/*         if (clockwise) { */
/*             tap_code(KC_VOLU); */
/*         } else { */
/*             tap_code(KC_VOLD); */
/*         } */
/*     } */
/* } */

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

/* #ifdef OLED_DRIVER_ENABLE  //Special thanks to Sickbabies for this great OLED widget! */
/* oled_rotation_t oled_init_user(oled_rotation_t rotation) { */
/*     return OLED_ROTATION_90;  // rotates for proper orientation */
/* } */

/* void render_lechiffre_logo(void) { */
/*     static const char PROGMEM lechiffre_logo[] = { */
/* 	// 'lechiffre_logo', 32x20px */
/*    0x00, 0x3e, 0x20, 0x20, 0x00, 0x18, 0x2c, 0xa8, 0x80, 0x00, 0x1c, 0x22, 0x22, 0x00, 0x3e, 0x08, */
/* 0x30, 0x00, 0x34, 0x00, 0x3c, 0x0a, 0x00, 0xbc, 0x8a, 0x00, 0x38, 0x08, 0x00, 0x18, 0x2c, 0x28, */
/* 0x00, 0xb6, 0xb6, 0x00, 0xdb, 0xdb, 0x00, 0x6d, 0x6d, 0x00, 0xdb, 0xdb, 0x00, 0xdb, 0xdb, 0x00, */
/* 0x00, 0xdb, 0xdb, 0x00, 0xdb, 0xdb, 0x00, 0x6d, 0x6d, 0x00, 0xdb, 0xdb, 0x00, 0xb6, 0xb6, 0x00, */
/* 0x00, 0x01, 0x01, 0x00, 0x00, 0x00, 0x06, 0x06, 0x06, 0x00, 0x06, 0x06, 0x06, 0x06, 0x06, 0x00, */
/* 0x00, 0x06, 0x06, 0x06, 0x06, 0x06, 0x00, 0x06, 0x06, 0x06, 0x00, 0x00, 0x00, 0x01, 0x01, 0x00 */
/* }; */

/*   oled_write_raw_P(lechiffre_logo, sizeof(lechiffre_logo)); */
/* } */

/* static void render_layer_status(void) { */
/*     oled_write_P(PSTR("-----"), false); */
/*     switch (get_highest_layer(layer_state)) { */
/*         case _BASE: */
/*             oled_write_ln_P(PSTR("BASE"), false); */
/*             break; */
/*         case _NUM_SYM: */
/*             oled_write_ln_P(PSTR(" SYM"), false); */
/*             break; */
/*         case _NAV: */
/*             oled_write_ln_P(PSTR(" NAV"), false); */
/*             break; */
/*         default: */
/*             oled_write_ln_P(PSTR("?????"), false); */
/*     } */
/* } */

/* #    define KEYLOG_LEN 11 */
/* char     keylog_str[KEYLOG_LEN] = {}; */
/* uint8_t  keylogs_str_idx        = 0; */
/* uint16_t log_timer              = 0; */

/* const char code_to_name[60] = { */
/*     ' ', ' ', ' ', ' ', 'a', 'b', 'c', 'd', 'e', 'f', */
/*     'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n', 'o', 'p', */
/*     'q', 'r', 's', 't', 'u', 'v', 'w', 'x', 'y', 'z', */
/*     '1', '2', '3', '4', '5', '6', '7', '8', '9', '0', */
/*     'R', 'E', 'B', 'T', '_', '-', '=', '[', ']', '\\', */
/*     '#', ';', '\'', '`', ',', '.', '/', ' ', ' ', ' '}; */

/* void add_keylog(uint16_t keycode) { */
/*     if ((keycode >= QK_MOD_TAP && keycode <= QK_MOD_TAP_MAX) || (keycode >= QK_LAYER_TAP && keycode <= QK_LAYER_TAP_MAX)) { */
/*         keycode = keycode & 0xFF; */
/*     } */

/*     for (uint8_t i = KEYLOG_LEN - 1; i > 0; i--) { */
/*         keylog_str[i] = keylog_str[i - 1]; */
/*     } */
/*     if (keycode < 60) { */
/*         keylog_str[0] = code_to_name[keycode]; */
/*     } */
/*     keylog_str[KEYLOG_LEN - 1] = 0; */

/*     log_timer = timer_read(); */
/* } */

/* void update_log(void) { */
/*     if (timer_elapsed(log_timer) > 750) { */
/*         add_keylog(0); */
/*     } */
/* } */

/* //Text only renders */
/* void render_keylogger_status(void) { */
/*     oled_write_P(PSTR("-----"), false); */
/*     oled_write(keylog_str, false); */
/* } */

/* void render_keylock_status(led_t led_state) { */
/*     oled_write_P(PSTR("-----"), false); */
/*     oled_write_P(PSTR("C"), led_state.caps_lock); */
/* 	oled_write_P(PSTR(" "), false); */
/*     oled_write_P(PSTR("N"), led_state.num_lock); */
/* 	oled_write_P(PSTR(" "), false); */
/*     oled_write_P(PSTR("S"), led_state.scroll_lock); */
/*     //oled_write_ln_P(PSTR(" "), false); */
/* } */

/* void render_mod_status(uint8_t modifiers) { */
/*        oled_write_P(PSTR("-----"), false); */
/*     oled_write_ln_P(PSTR("SHFT"), (modifiers & MOD_MASK_SHIFT)); */
/*     oled_write_ln_P(PSTR("ALT"), (modifiers & MOD_MASK_ALT)); */
/*     oled_write_ln_P(PSTR("CTRL"), (modifiers & MOD_MASK_CTRL)); */
/*     oled_write_ln_P(PSTR("GUI"), (modifiers & MOD_MASK_GUI)); */
/* } */

/* void oled_task_user(void) { */
/*     render_lechiffre_logo(); */
/*     oled_set_cursor(0,3); */
/*     render_layer_status();	// Renders the current keyboard state (layer, lock, caps, scroll, etc) */
/* 	render_mod_status(get_mods()|get_oneshot_mods()); */
/* 	render_keylock_status(host_keyboard_led_state()); */
/* 	render_keylogger_status(); */
/* } */

/* bool process_record_user(uint16_t keycode, keyrecord_t *record) { */
/*     if (record->event.pressed) { */
/*       add_keylog(keycode); */
/*     } */
/*     return true; */
/*   } */
/* #endif */
