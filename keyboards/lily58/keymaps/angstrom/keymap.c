#include QMK_KEYBOARD_H
#include "keymap_swedish.h"

enum layer_number {
  _COLEMAK = 0,
  _RAISE
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

/* COLEMAK
 * ,-----------------------------------------.                    ,-----------------------------------------.
 * | ESC  |   1  |   2  |   3  |   4  |   5  |                    |   6  |   7  |   8  |   9  |   0  |  +   |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * | Tab  |   Q  |   W  |   F  |   P  |   G  |                    |   J  |   L  |   U  |   Y  |   Ö  |  Å   |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * |BackSP|   A  |   R  |   S  |   T  |   D  |-------.    ,-------|   H  |   N  |   E  |   I  |   O  |  Ä   |
 * |------+------+------+------+------+------|   [   |    |    ]  |------+------+------+------+------+------|
 * |  <   |   Z  |   X  |   C  |   V  |   B  |-------|    |-------|   K  |   M  |   ,  |   .  |   -  |  '   |
 * `-----------------------------------------/       /     \      \-----------------------------------------'
 *                   | LCtrl| LAlt | Cmd  | /Shift  /       \Space \  |RAISE | RAlt |ENTER |
 *                   |      |      |      |/       /         \      \ |      |      |      |
 *                   `----------------------------'           '------''--------------------'
 */

 [_COLEMAK] = LAYOUT( \
  KC_ESC,   SE_1,   SE_2,    SE_3,    SE_4,    SE_5,                     SE_6,    SE_7,    SE_8,    SE_9,    SE_0,    SE_PLUS, \
  KC_TAB,   SE_Q,   SE_W,    SE_F,    SE_P,    SE_G,					 SE_J,    SE_L,    SE_U,    SE_Y,    SE_ODIA, SE_ARNG,
  KC_BSPC,  SE_A,   SE_R,    SE_S,    SE_T,    SE_D,                     SE_H,    SE_N,    SE_E,    SE_I,    SE_O,    SE_ADIA, \
  SE_LABK,  SE_Z,   SE_X,    SE_C,    SE_V,    SE_B, SE_LBRC,  SE_RBRC,  SE_K,    SE_M,    SE_COMM, SE_DOT,  SE_MINS, SE_QUOT, \
                        KC_LCTL, KC_LALT, KC_LGUI,KC_LSFT,     KC_SPC, MO(_RAISE), KC_RALT, KC_ENT \
),
/* RAISE
 * ,-----------------------------------------.                    ,-----------------------------------------.
 * |      |  F1  |  F2  |  F3  |  F4  |  F5  |                    |  F6  |  F7  |  F8  |  F9  | F10  |  ´   |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * |      |  F11 |  F12 |      |      |      |                    | Home | PgDn | PgUp | End  |      |  ~   |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * |      |      |      |      |      |      |-------.    ,-------| Left | Down |  Up  |Right |      |      |
 * |------+------+------+------+------+------|       |    |       |------+------+------+------+------+------|
 * |      |      |      |      |      |      |-------|    |-------|      |      |      |      |      |  |   |
 * `-----------------------------------------/       /     \      \-----------------------------------------'
 *                   |      |      |      | /       /       \      \  |RAISE |      |      |
 *                   |      |      |      |/       /         \      \ |      |      |      |
 *                   `----------------------------'           '------''--------------------'
 */

[_RAISE] = LAYOUT( \
  _______, KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,                       KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  SE_ACUT,\
  _______, KC_F11,  KC_F12,  _______, _______, _______,                     KC_HOME, KC_PGDN, KC_PGUP, KC_END,  _______, SE_TILD,\
  _______, _______, _______, _______, _______, _______,                     KC_LEFT, KC_DOWN, KC_UP,   KC_RGHT, _______, SE_DIAE,\
  _______, _______, _______, _______, _______, _______,  _______, _______,  _______, _______, _______, _______, _______, SE_PIPE_MAC,\
                             _______, _______, _______,  _______, _______,  _______, _______, _______ \
)};


//SSD1306 OLED update loop, make sure to enable OLED_DRIVER_ENABLE=yes in rules.mk
#ifdef OLED_DRIVER_ENABLE

oled_rotation_t oled_init_user(oled_rotation_t rotation) {
  if (!is_keyboard_master())
    return OLED_ROTATION_180;  // flips the display 180 degrees if offhand
  return rotation;
}

// When you add source files to SRC in rules.mk, you can use functions.
const char *read_layer_state(void);
const char *read_logo(void);
void set_keylog(uint16_t keycode, keyrecord_t *record);
const char *read_keylog(void);
const char *read_keylogs(void);

// const char *read_mode_icon(bool swap);
// const char *read_host_led_state(void);
// void set_timelog(void);
// const char *read_timelog(void);

void oled_task_user(void) {
  if (is_keyboard_master()) {
    // If you want to change the display of OLED, you need to change here
    oled_write_ln(read_layer_state(), false);
    oled_write_ln(read_keylog(), false);
    oled_write_ln(read_keylogs(), false);
    //oled_write_ln(read_mode_icon(keymap_config.swap_lalt_lgui), false);
    //oled_write_ln(read_host_led_state(), false);
    //oled_write_ln(read_timelog(), false);
  } else {
    oled_write(read_logo(), false);
  }
}
#endif // OLED_DRIVER_ENABLE

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  if (record->event.pressed) {
#ifdef OLED_DRIVER_ENABLE
    set_keylog(keycode, record);
#endif
    // set_timelog();
  }
  return true;
}
