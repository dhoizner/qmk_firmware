#include "layermodes.h"
#include "keycodes.h"

/*
static uint16_t sym_word_timer;
static bool _sym_word_enabled = false;
bool sym_word_enabled(void) {
    return _sym_word_enabled;
}
void disable_sym_word(void) {
    _sym_word_enabled = false;
    layer_off(_SYM);
}
void process_sym_word_activation(const keyrecord_t *record) {
    if (record->event.pressed) {
        layer_on(_SYM);
        sym_word_timer = timer_read();
    } else {
        if (timer_elapsed(sym_word_timer) < TAPPING_TERM) {
            // Tapping enables SYMWORD
            _sym_word_enabled = true;
        } else {
            // Holding turns off SYM when released
            layer_off(_SYM);
        }
    }
}
bool process_sym_word(uint16_t keycode, const keyrecord_t *record) {
    if (!_sym_word_enabled) return true;
    switch (keycode) {
        case QK_MOD_TAP ... QK_MOD_TAP_MAX:
        case QK_LAYER_TAP ... QK_LAYER_TAP_MAX:
        case QK_TAP_DANCE ... QK_TAP_DANCE_MAX:
            if (record->tap.count == 0)
                return true;
            keycode = keycode & 0xFF;
    }
    switch (keycode) {
        case GRV:
        case KC_LCBR:
        case KC_RCBR:
        case KC_PERC:
        case KC_HASH:
        case TILD:
        case KC_PLUS:
        case KC_ASTR:
        case KC_MINS:
        case KC_EQL:
        case KC_PIPE:
        case KC_AT:
        case KC_QUES:
        case KC_RBRC:
        case KC_LBRC:
        case KC_AMPR:
        case KC_LABK:
        case KC_RABK:
        case KC_BSLS:
        case KC_EXLM:
        case KC_COMM:
        case KC_DOT:
        case KC_UNDS:
        case KC_RPRN:
        case KC_LPRN:
        case KC_SLSH:
        case CIRC:
        case KC_DLR:
        case KC_BSPC:
        case KC_SCLN:
        case KC_COLN:
        case xxxxxxx:
            // Don't disable for the above keycodes
            break;
        case CANCEL:
            if (record->event.pressed) {
                disable_sym_word();
            }
            return false;
        default:
            if (record->event.pressed) {
                disable_sym_word();
            }
    }
    return true;
}
*/


static uint16_t num_word_timer;
static bool _num_word_enabled = false;
bool num_word_enabled(void) {
    return _num_word_enabled;
}
void enable_num_word(void) {
    _num_word_enabled = true;
    layer_on(_NUM);
}
void disable_num_word(void) {
    _num_word_enabled = false;
    layer_off(_NUM);
}
void process_num_word_activation(const keyrecord_t *record) {
    if (record->event.pressed) {
        layer_on(_NUM);
        num_word_timer = timer_read();
    } else {
        if (timer_elapsed(num_word_timer) < TAPPING_TERM) {
            // Tapping enables NUMWORD
            _num_word_enabled = true;
        } else {
            // Holding turns off NUM when released
            layer_off(_NUM);
        }
    }
}
bool process_num_word(uint16_t keycode, const keyrecord_t *record) {
    if (!_num_word_enabled) return true;

    switch (keycode) {
        case QK_MOD_TAP ... QK_MOD_TAP_MAX:
        case QK_LAYER_TAP ... QK_LAYER_TAP_MAX:
        case QK_TAP_DANCE ... QK_TAP_DANCE_MAX:
            if (record->tap.count == 0)
                return true;
            keycode = keycode & 0xFF;
    }
    switch (keycode) {
        case KC_1 ... KC_0:
        case MY_000:
        case KC_PERC:
        case KC_COMM:
        case KC_DOT:
        case KC_SLSH:
        case KC_MINS:
        case KC_ASTR:
        case KC_PLUS:
        case KC_EQL:
        case KC_UNDS:
        case KC_BSPC:
        case xxxxxxx:
            // Don't disable for above keycodes
            break;
        case CANCEL:
            if (record->event.pressed) {
                disable_num_word();
            }
            return false;
        default:
            if (record->event.pressed) {
                disable_num_word();
            }
    }
    return true;
}
