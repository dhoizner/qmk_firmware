#pragma once
#include QMK_KEYBOARD_H

#include "keycodes.h"
#include "wrappers.h"
#include "casemodes.h"
#include "layermodes.h"

bool process_record_keymap(uint16_t keycode, keyrecord_t *record);
