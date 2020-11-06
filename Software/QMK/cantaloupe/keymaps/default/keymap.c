#include QMK_KEYBOARD_H

/* Define layers */
#define _QWERTY 0
#define _FN 1

bool is_alt_tab_active = false;
uint16_t alt_tab_timer = 0;

/* Preparation for macros */
enum custom_keycodes {
  PRINTS = SAFE_RANGE,
  ALT_TAB,
  SHIFT_ALT_TAB,
};

/* Keymap configuration */
const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

/* QWERTY
* ,-----------------------------------------.     ,------.        ,------.    ,-----------------------------------------.
* |  Esc |   1  |   2  |   3  |   4  |   5  |     |PageUp| Up  Lt | Prev |    |   6  |   7  |   8  |   9  |   0  |   -  |
* |------+------+------+------+------+------|     |------|        |------|    |------+------+------+------+------+------|
* |  Tab |   Q  |   W  |   E  |   R  |   T  |     |  Ins | Ce  Dn | VolDn|    |   Y  |   U  |   I  |   O  |   P  |   =  |
* |------+------+------+------+------+------|     |------|        |------|    |------+------+------+------+------+------|
* |   \  |   A  |   S  |   D  |   F  |   G  |     |  End | Rt  Rt | Next |    |   H  |   J  |   K  |   L  |   ;  |   '  |
* |------+------+------+------+------+------|     |------|        |------|    |------+------+------+------+------+------|
* | Ctrl |   Z  |   X  |   C  |   V  |   B  |     |PageDn| Dn  Ce |Ply/Ps|    |   N  |   M  |   ,  |   .  |  Up  |   ?  |
* |------+------+------+------+------+----------. |------|        |------| ,-----------------------+------+------+------|
* |  Del |  GUI |  Alt |   |Lower | Shift| Back | | Home | Lt  Up | VolUp| | Enter| Space| Raise|  | Left | Down | Right|
* `--------------------'   `--------------------' `------'        `------' `--------------------'  `--------------------'
*
*/
  [_QWERTY] = LAYOUT_split_5x14( \
    KC_GESC, KC_1   , KC_2   , KC_3   , KC_4   , KC_5   ,      KC_PGUP,      KC_MPRV,      KC_6   , KC_7   , KC_8   , KC_9   , KC_0   , KC_MINS,\
    KC_TAB , KC_Q   , KC_W   , KC_E   , KC_R   , KC_T   ,      KC_INS ,      KC_VOLD,      KC_Y   , KC_U   , KC_I   , KC_O   , KC_P   , KC_EQL ,\
    KC_BSLS, KC_A   , KC_S   , KC_D   , KC_F   , KC_G   ,      KC_END ,      KC_MNXT,      KC_H   , KC_J   , KC_K   , KC_L   , KC_SCLN, KC_QUOT,\
    KC_LCTL, KC_Z   , KC_X   , KC_C   , KC_V   , KC_B   ,      KC_PGDN,      KC_MPLY,      KC_N   , KC_M   , KC_COMM, KC_DOT , KC_UP  , KC_SLSH,\
    KC_DEL , KC_LGUI, KC_LALT,    MO(1)  , KC_LSFT, KC_BSPC,   KC_HOME,      KC_VOLU,   KC_ENT , KC_SPC , MO(1)     , KC_LEFT, KC_DOWN, KC_RGHT \
),

/* Fn
* ,-----------------------------------------.     ,------.        ,------.    ,-----------------------------------------.
* |  F12 |  F1  |  F2  |  F3  |  F4  |  F5  |     |      | F1  F3 |      |    |  F6  |  F7  |  F8  |  F9  | F10  | F11  |
* |------+------+------+------+------+------|     |------|        |------|    |------+------+------+------+------+------|
* |      |      |      |      |      |      |     |      | F4  F4 |      |    |      |      |      |      |      |      |
* |------+------+------+------+------+------|     |------|        |------|    |------+------+------+------+------+------|
* |      |      |      |      |   [  |      |     |      | F3  F1 |      |    |      |   ]  |      |      |      |   `  |
* |------+------+------+------+------+------|     |------|        |------|    |------+------+------+------+------+------|
* |      |      |      |      |   {  |      |     |      | F5  F2 |      |    |      |   }  |      |      |      |      |
* |------+------+------+------+------+----------. |------|        |------| ,-----------------------+------+------+------|
* |PRINTS|      |      |   |      |      |      | |      | F2  F5 |      | |      |      |      |  |      |      |      |
* `--------------------'   `--------------------' `------'        `------' `--------------------'  `--------------------'
*
*/
  [_FN] = LAYOUT_split_5x14(
    KC_F12 , KC_F1  , KC_F2  , KC_F3  , KC_F4  , KC_F5  ,      _______,     _______,      KC_F6  , KC_F7  , KC_F8  , KC_F9  , KC_F10 , KC_F11 ,\
    _______, _______, KC_PGUP, _______, _______, _______,      _______,     _______,      _______, _______, _______, KC_PGUP, _______, _______,\
    _______, KC_HOME, KC_PGDN, KC_END , KC_LBRC, _______,      _______,     _______,      _______, KC_RBRC, KC_HOME, KC_PGDN, KC_END , KC_GRV ,\
    _______, _______, _______, _______, KC_LCBR, _______,      _______,     _______,      _______, KC_RCBR, _______, _______, _______, _______,\
    PRINTS , _______, _______,    _______, _______, _______,   _______,     _______,   _______, _______, _______,    _______, _______, _______ \
  ),
};

bool process_record_user(uint16_t keycode, keyrecord_t *record) {

  switch (keycode) {
    case PRINTS:
      if (record->event.pressed) {
        register_code(KC_LGUI);
        register_code(KC_LSFT);
        tap_code(KC_S);
        unregister_code(KC_LSFT);
        unregister_code(KC_LGUI);
      }
      break;
  }
  return true;
}

void matrix_scan_user(void) {
  if (is_alt_tab_active) {
    if (timer_elapsed(alt_tab_timer) > 500) {
      unregister_code(KC_LALT);
      is_alt_tab_active = false;
    }
  }
}

/* Code for encoders */
void encoder_update_user(uint8_t index, bool clockwise) {
    if (index == 0) { // First encoder switches between tabs
      if (!is_alt_tab_active) {
        is_alt_tab_active = true;
        register_code(KC_LALT);
      }
      if (clockwise) {
        alt_tab_timer = timer_read();
        tap_code16(KC_TAB);
      } else {
        alt_tab_timer = timer_read();
        tap_code16(LSFT(KC_TAB));
      }
    } else if (index == 1) { // Second encoder moves through music tracks
        if (clockwise) {
            tap_code(KC_MNXT);
        } else {
            tap_code(KC_MPRV);
        }
    }
}