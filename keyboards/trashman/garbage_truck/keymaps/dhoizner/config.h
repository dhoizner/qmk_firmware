// Prevent normal rollover on alphas from accidentally triggering mods.
#define IGNORE_MOD_TAP_INTERRUPT
// Enable rapid switch from tap to hold, disables double tap hold auto-repeat
#define TAPPING_FORCE_HOLD
// Apply the modifier on keys that are tapped during a short hold of a modtap
#define PERMISSIVE_HOLD
// Immediately turn on layer if key is pressed quickly
#define HOLD_ON_OTHER_KEY_PRESS
// Don't fire mods on the same side
// #define BILATERAL_COMBINATIONS 400

/* #define COMBO_COUNT 5 */
#define COMBO_TERM 30
#define COMBO_VARIABLE_LEN

#define NO_AUTO_SHIFT_ALPHA
#define AUTO_SHIFT_TIMEOUT 125

#define DEFAULT_XCASE_SEPARATOR KC_UNDS
#define XCASE_DELIMITER_KEY KC_SPC
