#include QMK_KEYBOARD_H

#define BASE 0 // Base (Colemak)
#define SYMB 1 // Easy access to symbols
#define NUMS 2 // Easy access to numbers


/****************************************************************************************************
*
* Keymap: Default Layer in tpanum
*
* ,-------------------------------------------------------------------------------------------------------------------.
* | Esc    |  F1  |  F2  |  F3  |  F4  |  F5  |  F6  |  F8  |  F9  |  F10 |  F12 | PSCR | SLCK | PAUS |  FN0 |  BOOT  |
* |--------+------+------+------+------+------+---------------------------+------+------+------+------+------+--------|
* | =+     |  1!  |  2@  |  3#  |  4$  |  5%  |                           |  6^  |  7&  |  8*  |  9(  |  0)  | -_     |
* |--------+------+------+------+------+------|                           +------+------+------+------+------+--------|
* | Tab    |   Q  |   W  |   E  |   R  |   T  |                           |   Y  |   U  |   I  |   O  |   P  | \|     |
* |--------+------+------+------+------+------|                           |------+------+------+------+------+--------|
* | Caps   |   A  |   S  |   D  |   F  |   G  |                           |   H  |   J  |   K  |   L  |  ;:  | '"     |
* |--------+------+------+------+------+------|                           |------+------+------+------+------+--------|
* | Shift  |   Z  |   X  |   C  |   V  |   B  |                           |   N  |   M  |  ,.  |  .>  |  /?  | Shift  |
* `--------+------+------+------+------+-------                           `------+------+------+------+------+--------'
*          | `~   | INS  | Left | Right|                                         | Up   | Down |  [{  |  ]}  |
*          `---------------------------'                                         `---------------------------'
*                                        ,-------------.         ,-------------.
*                                        | Ctrl | Alt  |         | Gui  | Ctrl |
*                                 ,------|------|------|         |------+------+------.
*                                 |      |      | Home |         | PgUp |      |      |
*                                 | SPC  | Del  |------|         |------|Return| Space|
*                                 |      |      | End  |         | PgDn |      |      |
*                                 `--------------------'         `--------------------'
*/

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
[BASE] = LAYOUT(
           KC_ESC ,KC_F1  ,KC_F2  ,KC_F3  ,KC_F4  ,KC_F5  ,KC_F6  ,KC_F7  ,KC_F8,
           KC_GRV,KC_1   ,KC_2   ,KC_3   ,KC_4   ,KC_5   ,
           KC_LCTL,KC_Q  ,KC_W   ,KC_F   ,KC_P   ,KC_G   ,
           KC_LSFT, KC_A   ,KC_R   ,KC_S   ,KC_T   ,KC_D   ,
           KC_RGUI,KC_Z   ,KC_X   ,KC_C   ,KC_V   ,KC_B   ,
	   KC_HOME,KC_END ,KC_RALT,MO(SYMB),
	   KC_LCTL,KC_LALT,
	   KC_HOME,
	   KC_SPC,LT(NUMS,KC_TAB),KC_LALT ,

	   KC_F9  ,KC_F10 ,KC_F11 ,KC_F12 ,KC_PSCR ,KC_SLCK  ,KC_PAUS, KC_FN0, RESET,
	   KC_6   ,KC_7   ,KC_8   ,KC_9   ,KC_0   , KC_MINS,
	   KC_J   ,KC_L   ,KC_U   ,KC_Y   ,KC_SCLN, KC_RCTL,
	   KC_H   ,KC_N   ,KC_E   ,KC_I   ,KC_O   , KC_LSFT,
	   KC_K   ,KC_M   ,KC_COMM,KC_DOT ,KC_SLSH,KC_RGUI,
	   MO(SYMB),KC_RALT,KC_PGDN,KC_PGUP,
           KC_RGUI,KC_RCTL,
           KC_PGUP,
           KC_LALT,KC_BSPC ,KC_ENTER
		),

[SYMB] = LAYOUT(
	   _______,_______,_______,_______,_______,_______,_______,_______,_______,
           _______,_______,_______,_______,_______,_______,
           _______,KC_EXLM,KC_AT  ,KC_HASH,KC_DLR ,KC_PERC,
           _______,KC_QUOT,KC_DQUO,KC_LCBR,KC_RCBR,KC_PEQL,
           _______,KC_PIPE,KC_BSLS,_______,_______,KC_PPLS,
	   _______,_______,_______,_______,
	   _______,_______,
	   _______,
	   _______,_______,_______,

	   _______,_______,_______,_______,_______,_______,_______,_______,_______,
           _______,KC_MPRV,KC_MPLY,KC_MNXT,_______,_______,
	   KC_CIRC,KC_AMPR,KC_ASTR,KC_MINS,KC_GRV ,_______,
	   KC_MINS,KC_LPRN,KC_RPRN,KC_LBRC,KC_RBRC,_______,
	   KC_UNDS,KC_DOWN,KC_UP  ,KC_LEFT,KC_RGHT,_______,
	   _______,_______,_______,_______,
	   _______,_______,
	   _______,
	   _______,_______,_______
		),

[NUMS] = LAYOUT(
	   _______,_______,_______,_______,_______,_______,_______,_______,_______,
           _______,_______,_______,_______,_______,_______,
           _______,_______,_______,_______,_______,KC_VOLU,
           _______,_______,_______,_______,_______,KC_VOLD,
           _______,_______,_______,_______,_______,KC_MUTE,
	   _______,_______,_______,_______,
	   _______,_______,
	   _______,
	   _______,_______,_______,

	   _______,_______,_______,_______,_______,_______,_______,_______,_______,
           _______,_______,_______,_______,_______,_______,
	   _______,KC_7   ,KC_8   ,KC_9   ,_______,_______,
	   _______,KC_4   ,KC_5   ,KC_6   ,KC_0   ,_______,
	   _______,KC_1   ,KC_2   ,KC_3   ,_______,_______,
	   _______,_______,_______,_______,
	   _______,_______,
	   _______,
	   _______,_______,_______
    )
};


static uint16_t last_keycode = 0;

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  switch (keycode) {
  case KC_LSFT:
    if (!record->event.pressed && last_keycode == keycode) {
      unregister_code(KC_LSFT);
      register_code(KC_ESC);
      unregister_code(KC_ESC);
      return false;
    }
  }

  last_keycode = keycode;
  return true;
}
