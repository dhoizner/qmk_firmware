#include "dhoizner.h"

__attribute__((weak)) bool process_record_keymap(uint16_t keycode, keyrecord_t *record) { return true; }

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  if (!process_num_word(keycode, record)) {
    switch (keycode) {
    }
    return false;
  }

  if (!process_case_modes(keycode, record)) {
    return false;
  }

  if (!(process_record_keymap(keycode, record))) {
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
      /* if (record->event.pressed) { */
        process_num_word_activation(record);
      /* } */
      return false;
    case CAPSWORD:
      if (record->event.pressed) {
        toggle_caps_word();
      }
      return false;
    case XCASE:
      if (record->event.pressed) {
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

bool use_default_xcase_separator(uint16_t keycode, keyrecord_t *record) {
  switch (keycode) {
    case KC_A ... KC_Z:
    case KC_1 ... KC_0:
      return true;
  }
  return false;
}
