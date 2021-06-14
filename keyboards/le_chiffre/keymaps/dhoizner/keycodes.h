#pragma once

#include "quantum.h"
/* #include "oneshot.h" */

enum layers {
  _BASE,
  _NUM_SYM,
  _NUM,
  _NAV
};

enum custom_keycodes {
    // Direct dead keys ~`^
    TILD = SAFE_RANGE,
    GRV,
    CIRC,

    MY_000,
    SAVE_VIM,
    CLOSE_VIM,
    VIM_VS,
    VIM_SP,

    // Custom keycodes for instant processing for NUMWORD
    NUM_G,

    // Instant oneshot mods
    OS_SHFT,
    OS_CTRL,
    OS_ALT,
    OS_GUI,

    // Smart caps lock and layers that turn off on certain keys
    CAPSWORD,
    NUMWORD,
    XCASE,

    // Layer management
    CANCEL, // Cancel SYMWORD and NUMWORD
    CLEAR, // Clear all WORD, one-shots and reset to BASE

    TO_GAME,
    TO_NUM,

    // Smileys
    // SHRUGIE,        // ┐(°‿°)┌ (nicer) or 乁(ツ)ㄏ (whatever)
    // TABLE_F,        // (╯°□°)╯ ︵ ┻━┻ or (ノಠ益ಠ)ノ彡┻━┻
    // FACE_1,         // ✖‿✖ (excited) or (╯︵╰,) (crying)
    // FACE_2,         // (¬‿¬) (skeptical) or ಠ_ಠ (disapproval)

    // Runtime options
    TG_NIX,
    TG_CAPS,
};

#define xxxxxxx KC_NO

// #define HOME_LINDEX(kc)         (LSFT_T(kc))
// #define HOME_RINDEX(kc)         (LSFT_T(kc))
//
// #define HOME_LMIDDLE(kc)        (LCTL_T(kc))
// #define HOME_RMIDDLE(kc)        (RCTL_T(kc))
//
// #define HOME_LRING(kc)          (LGUI_T(kc))
// #define HOME_RRING(kc)          (RGUI_T(kc))
//
// #define HOME_LPINKY(kc)         (LALT_T(kc))
// #define HOME_RPINKY(kc)         (LALT_T(kc))

#define KC_NUM_SPC LT(_NUM_SYM, KC_SPC)
#define KC_NAV_BSPC LT(_NAV, KC_BSPC)
#define KC_CA LCTL_T(KC_A)
#define KC_AR LALT_T(KC_R)
#define KC_GS LGUI_T(KC_S)
#define KC_ST LSFT_T(KC_T)
#define KC_SN LSFT_T(KC_N)
#define KC_GE LGUI_T(KC_E)
#define KC_AI LALT_T(KC_I)
#define KC_CO LCTL_T(KC_O)
// --- mine above ---
#define MT_BTN1 LGUI_T(KC_BTN1)
#define MT_SPC LT(_NAV, KC_SPC)
#define MT_BSPC MO(_NAV)
#define SFT OSM(MOD_LSFT)
#define ALT OSM(MOD_LALT)
#define MY_RALT OSM(MOD_RALT)
#define CTRL OSM(MOD_LCTL)
#define GUI OSM(MOD_LGUI)
#define DN_CTRL LCTL_T(KC_DOWN)

#define C_TAB C(KC_TAB)
#define SC_TAB S(C(KC_TAB))

#define LMOD OSL(_LMOD)
#define RMOD OSL(_RMOD)
// #define NUM MO(_NUM)
// #define TG_NUM TG(_NUM)
// #define G_WNAV LM(_WNAV, MOD_LGUI)
#define WNAV MO(_WNAV)
#define TG_WNAV TG(_WNAV)
#define TG_SWE TG(_SWE)
#define OPT OSL(_OPT)
#define FUN OSL(_FUN)

#define GAME2 OSL(_GAME2)
