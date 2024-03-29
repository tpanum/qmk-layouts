#include QMK_KEYBOARD_H
#include "version.h"

#define BASE 0 // Base (Colemak)
#define SYMB 1 // Easy access to symbols
#define NUMS 2 // Easy access to numbers

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [BASE] = LAYOUT_ergodox_pretty(
				    KC_GRAVE,       KC_1,           KC_2,           KC_3,           KC_4,           KC_5,           KC_LBRC,                                    KC_RBRC,    KC_6,           KC_7,           KC_8,           KC_9,           KC_0,           KC_BSLS,
				 KC_LCTL,       KC_Q,           KC_W,           KC_F,           KC_P,           KC_G,           KC_EQUAL,                                       KC_MINUS,       KC_J,           KC_L,           KC_U,           KC_Y,           KC_SCLN,      KC_LCTL,
				 KC_LSFT,      KC_A,           KC_R,           KC_S,           KC_T,           KC_D,                                                                           KC_H,           KC_N,           KC_E,           KC_I,           KC_O,            KC_LSFT,
				 KC_LGUI,        KC_Z,           KC_X,           KC_C,           KC_V,           KC_B,           KC_TAB,                                         KC_TAB,         KC_K,           KC_M,           KC_COMMA,       KC_DOT,         KC_SLASH,       KC_LGUI,
				 KC_HOME,        KC_END,         KC_LEFT,        KC_RALT,       MO(1),                                                                                                          MO(1),          KC_RALT,          KC_DOWN,        KC_LEFT,        KC_RIGHT,
				 QK_BOOTLOADER,          MO(2),          KC_LALT,        KC_DELETE,
				 KC_HOME,        KC_HOME,
				 KC_SPACE,       LT(NUMS,KC_TAB),         KC_LALT,        KC_LALT,        KC_BSPC,      KC_ENTER
				 ),
  [SYMB] = LAYOUT_ergodox_pretty(
				 KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,                                 KC_TRANSPARENT, KC_TRANSPARENT, KC_MEDIA_PREV_TRACK,KC_MEDIA_PLAY_PAUSE,KC_MEDIA_NEXT_TRACK,KC_TRANSPARENT, KC_TRANSPARENT,
				 KC_TRANSPARENT, KC_EXLM,        KC_AT,          KC_HASH,        KC_DLR,         KC_PERC,        KC_TRANSPARENT,                                 KC_TRANSPARENT, KC_CIRC,        KC_AMPR,        KC_ASTR,        KC_KP_MINUS,    KC_GRAVE,       KC_TRANSPARENT,
				 KC_TRANSPARENT, KC_QUOTE,       KC_DQUO,        KC_LCBR,        KC_RCBR,        KC_EQUAL,                                                                       KC_MINUS,       KC_LPRN,        KC_RPRN,        KC_LBRC,    KC_RBRC,    KC_TRANSPARENT,
				 KC_TRANSPARENT, KC_PIPE,        KC_BSLS,      KC_TRANSPARENT, KC_BSPC,      KC_PPLS,      KC_TRANSPARENT,                                 KC_TRANSPARENT, KC_UNDS,        KC_DOWN,        KC_UP,          KC_LEFT,        KC_RIGHT,       KC_TRANSPARENT,
				 KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,                                                                                                 KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,
				 KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,
				 KC_TRANSPARENT, KC_TRANSPARENT,
				 KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT
  ),
  [NUMS] = LAYOUT_ergodox_pretty(
				 KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,                                 KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,
				 KC_TRANSPARENT, KC_F9,          KC_F10,         KC_F11,         KC_F12,         KC_AUDIO_VOL_UP,KC_TRANSPARENT,                                 KC_TRANSPARENT, KC_TRANSPARENT, KC_7,           KC_8,           KC_9,           KC_TRANSPARENT, KC_TRANSPARENT,
				 KC_TRANSPARENT, KC_F5,          KC_F6,          KC_F7,          KC_F8,          KC_AUDIO_VOL_DOWN,                                                                KC_TRANSPARENT, KC_4,           KC_5,           KC_6,           KC_0,           KC_TRANSPARENT,
				 KC_TRANSPARENT, KC_F1,          KC_F2,          KC_F3,          KC_F4,          KC_AUDIO_MUTE,  KC_TRANSPARENT,                                 KC_TRANSPARENT, KC_TRANSPARENT, KC_1,           KC_2,           KC_3,           KC_TRANSPARENT, KC_TRANSPARENT,
				 KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,                                                                                                 KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,
				 KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,
				 KC_TRANSPARENT, KC_TRANSPARENT,
				 KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT
  ),
};

static uint16_t last_keycode = 0;

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  switch (keycode) {
  case KC_LSFT:
    if (!record->event.pressed && last_keycode == keycode) {
      unregister_code(KC_LSFT);
      wait_ms(20);
      register_code(KC_ESC);
      unregister_code(KC_ESC);
      return false;
    }
  }

  last_keycode = keycode;
  return true;
}
