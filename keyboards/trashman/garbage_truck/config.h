/*
Copyright 2021 Dan Hoizner

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

#pragma once

#include "config_common.h"

#define VENDOR_ID     0xFEAE
#define PRODUCT_ID    0x8849
#define DEVICE_VER    0x0001
#define MANUFACTURER  TheVan Keyboards
#define PRODUCT       Garbage Truck
#define DESCRIPTION   It is garbage

#define MATRIX_ROWS 8
#define MATRIX_COLS 8
#define MATRIX_ROW_PINS { F0, F1, F4, F5, B7, D2, D3, B4 }
#define MATRIX_COL_PINS { B2, B3, D5, B5, B6, C6, F7, F6 }
#define DIODE_DIRECTION COL2ROW
#define DEBOUNCE 5

#define ENCODERS_PAD_A { B0 }
#define ENCODERS_PAD_B { B1 }

#define BACKLIGHT_PIN B7
#define BACKLIGHT_LEVELS 1


#define LOCKING_SUPPORT_ENABLE
#define LOCKING_RESYNC_ENABLE

#define NO_ACTION_MACRO
#define NO_ACTION_FUNCTION

#define TAPPING_TERM 175

#define USB_MAX_POWER_CONSUMPTION 100
#define IS_COMMAND() ( keyboard_report->mods == (MOD_BIT(KC_LSHIFT) | MOD_BIT(KC_RSHIFT)) )
