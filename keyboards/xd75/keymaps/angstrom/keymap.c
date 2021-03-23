/* Copyright 2017 Wunder
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
#include "keymap_swedish.h"

// Layers
enum angstrom_layers {
	_COLEMAK,
	_RAISE
};

#define RAISE   MO(_RAISE)

enum custom_keycodes {
    LBRACK = SAFE_RANGE,
	RBRACK
};


const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

/* COLEMAK SE SPLIT
 * .--------------------------------------------------------------------------------------------------------------------------------------,
 * | Esc    | 1      | 2      | 3      | 4      | 5      |        |        |        | 6      | 7      | 8      | 9      | 0      | +      |
 * |--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+
 * | TAB    | Q      | W      | F      | P      | G      |        |        |        | J      | L      | U      | Y      | Ö      | Å      |
 * |--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+-----------------+
 * | Backsp | A      | R      | S      | T      | D      | [      |        | ]      | H      | N      | E      | I      | O      | Ä      |
 * |--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------------------------+
 * |        | Z      | X      | C      | V      | B      |        |        |        | K      | M      | ,      | .      | -      | '      |
 * |--------+--------+--------+--------+--------+-----------------+--------+--------+--------+--------+--------+-----------------+--------+
 * |        |        |        | Ctrl   | LAlt   | Cmd    | Shift  |        | SPACE  | Raise  | RAlt   | ENTER  |        |        |        |
 * '--------------------------------------------------------------------------------------------------------------------------------------'
 */

[_COLEMAK] = LAYOUT_ortho_5x15(
    KC_ESC,  KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    _______, _______, _______, KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    SE_PLUS,
    KC_TAB,  KC_Q,    KC_W,    KC_F,    KC_P,    KC_G,	  _______, _______, _______, KC_J,    KC_L,    KC_U,    KC_Y,    SE_ODIA, SE_ARNG,
    KC_BSPC, KC_A,    KC_R,    KC_S,    KC_T,    KC_D,    SE_LBRC, _______, SE_RBRC, KC_H,    KC_N,    KC_E,    KC_I,    KC_O,    SE_ADIA,
    SE_LABK, KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    _______, _______, _______, KC_K,    KC_M,    KC_COMM, KC_DOT,  SE_MINS, SE_QUOT,
    _______, _______, _______, KC_LCTL, KC_LALT, KC_LCMD, KC_LSFT , _______, KC_SPC, RAISE,   KC_RALT, KC_ENT,  _______, _______, _______
  ),

/* RAISE
 * .--------------------------------------------------------------------------------------------------------------------------------------.
 * |        |        |        |        |        |        | F1     | F2     | F3     |        |        |        |        | §      | ~      |
 * |--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------|
 * |        |        |        |        |        |        | F4     | F5     | F6     | Home   | PgDn   | PgUp   | End    |        | ^      |
 * |--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------|
 * |        |        |        |        |        |        | F7     | F8     | F9     | Left   | Down   | Up     | Right  |        | ¨      |
 * |--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------|
 * | DEBUG  |        |        |        |        |        | F10    | F11    | F12    |        |        |        |        |        | ´      |
 * |--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------|
 * | RESET  |        |        |        |        |        |        |        |        |        |        |        |        |        |        |
 * '--------------------------------------------------------------------------------------------------------------------------------------'
 */
	
  [_RAISE] = LAYOUT_ortho_5x15(
    _______, _______, _______, _______, _______, _______, KC_F1,   KC_F2,   KC_F3,   _______, _______, _______, _______,  SE_SECT, SE_TILD,
    _______, _______, _______, _______, _______, _______, KC_F4,   KC_F5,   KC_F6,   KC_HOME, KC_PGDN, KC_PGUP, KC_END,   _______, SE_CIRC,
    _______, _______, _______, _______, _______, _______, KC_F7,   KC_F8,   KC_F9,   KC_LEFT, KC_DOWN, KC_UP,   KC_RIGHT, _______, SE_DIAE,
    DEBUG,   _______, _______, _______, _______, _______, KC_F10,  KC_F11,  KC_F12,  _______, _______, _______, _______,  _______, SE_ACUT,
    RESET,   _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,  _______, _______
  )
};

void matrix_init_user(void) {

}

void matrix_scan_user(void) {

}

void led_set_user(uint8_t usb_led) {

}

layer_state_t layer_state_set_user(layer_state_t state) {
    switch (get_highest_layer(state)) {
    case _RAISE:
        rgblight_setrgb (0x00,  0x00, 0xFF);
        break;
    default: //  for any other layers, or the default layer
        rgblight_setrgb (0x00,  0xFF, 0xFF);
        break;
    }
  return state;
}

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
    case RESET:
        if (record->event.pressed) {
        	rgblight_setrgb (0xFF,  0x00, 0x00);
        }
        break;
    }
    return true;
};
