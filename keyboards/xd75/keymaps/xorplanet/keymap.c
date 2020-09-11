 /*Copyright 2017 Wunder
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

/*
 *                       _                  _
 * __  _____  _ __ _ __ | | __ _ _ __   ___| |_
 * \ \/ / _ \| '__| '_ \| |/ _` | '_ \ / _ \ __|
 *  >  < (_) | |  | |_) | | (_| | | | |  __/ |_
 * /_/\_\___/|_|  | .__/|_|\__,_|_| |_|\___|\__|
 *                |_|
 *
 * https://github.com/xorplanet
 *
 * version 0.9
 */

#include QMK_KEYBOARD_H

// Layer shorthand
#define _QW 0
#define _GAMES 1
#define _LOWER 2
#define _UPPER 3
#define _KEEB 4


// Defines the keycodes used by our macros in process_record_user
enum custom_keycodes {
  QMKBEST = SAFE_RANGE,
  QMKURL,
  BSPCDEL
};
#define KC_BSDEL BSPCDEL

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

/* QWERTY
 * .--------------------------------------------------------------------------------------------------------------------------------------.
 * | ESC    | 1      | 2      | 3      | 4      | 5      | -      | `      | =      | 6      | 7      | 8      | 9      | 0      | BACKSP |
 * |--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+-----------------|
 * | TAB    | Q      | W      | E      | R      | T      | [      | \      | ]      | Y      | U      | I      | O      | P      | '      |
 * |--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+-----------------+--------|
 * | ESC    | A      | S      | D      | F      | G      | HOME   | DEL    | PG UP  | H      | J      | K      | L      | ;      | ENTER  |
 * |--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------------------------+--------|
 * | LSHIFT | Z      | X      | C      | V      | B      | END    | UP     | PG DN  | N      | M      | ,      | .      | /      | RSHIFT |
 * |--------+--------+--------+--------+--------+-----------------+--------+--------+--------+--------+-----------------+--------+--------|
 * | LCTRL  | LGUI   |        | LALT   | LOWER  | SPACE  | LEFT   | DOWN   | RIGHT  | SPACE  | UPPER  |        | RALT   | RGUI   | RCTRL  |
 * '--------------------------------------------------------------------------------------------------------------------------------------'
 */

  [_QW] = LAYOUT_ortho_5x15( /* QWERTY */
    KC_ESC,  KC_1,    KC_2,  KC_3,       KC_4,    KC_5,    KC_MINS, KC_GRV,  KC_EQL,  KC_6,    KC_7,       KC_8,    KC_9,    KC_0,    KC_BSPC,
    KC_TAB,  KC_Q,    KC_W,  KC_E,       KC_R,    KC_T,    KC_LBRC, KC_BSLS, KC_RBRC, KC_Y,    KC_U,       KC_I,    KC_O,    KC_P,    KC_QUOT,
    KC_ESC,  KC_A,    KC_S,  KC_D,       KC_F,    KC_G,    KC_HOME, KC_DEL,  KC_PGUP, KC_H,    KC_J,       KC_K,    KC_L,    KC_SCLN, KC_ENT,
    KC_LSFT, KC_Z,    KC_X,  KC_C,       KC_V,    KC_B,    KC_END,  KC_UP,   KC_PGDN, KC_N,    KC_M,       KC_COMM, KC_DOT,  KC_SLSH, KC_RSFT,
    KC_LCTL, KC_LGUI, KC_NO, KC_LALT, MO(_LOWER), KC_SPC,  KC_LEFT, KC_DOWN, KC_RGHT, KC_SPC,  MO(_UPPER), KC_RALT, KC_NO,   KC_RGUI, KC_RCTL
  ),



 /* LOWER
  * .--------------------------------------------------------------------------------------------------------------------------------------.
  * | F1     | F2     | F3     | F4     | F5     | F6     | NUM LK | P/     | P*     | F7     | F8     | F9     | F10    | F11    | F12    |
  * |--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------|
  * | PR SCR |   !    |   @    |    #   |    $   |   %    | P7     | P8     | P9     |    ^   |    &   |    *   |    (   |    )   |        |
  * |--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------|
  * |        |        |  PLAY  |  VOL-  | BACKSP | DELETE | P4     | P5     | P6     |        |    +   |   -    |   [    |   ]    |   ~    |
  * |--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------|
  * |        |        |  PAUSE |  APP   | MYCOMP |        | P1     | P2     | P3     |        |    =   |   _    |   |    |   \    |   `    |
  * |--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------|
  * |        |        |        |        | LOWER  | SPACE  | P0     |        | P.     |        | UPPER  | ALT    |  KEEB  |        |        |
  * '--------------------------------------------------------------------------------------------------------------------------------------'
  */
     [_LOWER] = LAYOUT_ortho_5x15( /* FUNCTION */
      _______, KC_F1,   KC_F2,   KC_F3,   KC_F4,      KC_F5,   KC_NLCK, KC_SLSH, KC_ASTR, KC_F6,    KC_F7,       KC_F8,      KC_F9,     KC_F10,   KC_F11,
      KC_PSCR, KC_EXLM, KC_AT,   KC_HASH, KC_DLR,     KC_PERC, KC_7,    KC_P8,   KC_P9,   KC_CIRC,  KC_AMPR,     KC_ASTR,    KC_LPRN,   KC_RPRN,  KC_F12,
      _______, _______, KC_MPLY, KC_VOLD, KC_BSPACE,  KC_DEL,  KC_P4,   KC_P5,   KC_P6,   _______,  S(KC_EQL),	 KC_MINS,	   KC_LBRC,   KC_RBRC,  KC_TILD,
      _______, _______, KC_PAUS, KC_APP,  KC_MYCM,    _______, KC_P1,   KC_P2,   KC_P3,   KC_PLUS,  KC_EQL,      S(KC_MINS), KC_PIPE,   KC_BSLS,  KC_GRV,
      _______, _______, _______, _______, MO(_LOWER), _______, KC_P0, _______,   KC_PDOT, _______,  MO(_UPPER),  _______,    TG(_KEEB), _______,  _______
    ),

/* UPPER
 * .--------------------------------------------------------------------------------------------------------------------------------------.
 * | F1     | F2     | F3     | F4     | F5     | F6     | NUM LK | P/     | P*     | F7     | F8     | F9     | F10    | F11    | F12    |
 * |--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------|
 * |        | !      | @      | #      | $      | %      | P7     | P8     | P9     | ^      | &      | *      | (      | )      |        |
 * |--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------|
 * |        |        |        |        |        |        | P4     | P5     | P6     | +      |        |        |        |        |        |
 * |--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------|
 * |        |        |        |        |        |        | P1     | P2     | P3     | PENT   |        |        |        |        |        |
 * |--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------|
 * |        |        |        |        | LOWER  |        | P0     |        | P.     |        | UPPER  |  Vol-  |  Vol+  |        | GAMES  |
 * '--------------------------------------------------------------------------------------------------------------------------------------'
 */
 [_UPPER] = LAYOUT_ortho_5x15( /* FUNCTION */
   _______, KC_F1,     KC_F2,      KC_F3,      KC_F4,       KC_F5,     KC_NLCK, KC_SLSH, KC_ASTR, KC_F6,    KC_F7,        KC_F8,     KC_F9,     KC_F10,    KC_F11,
   _______, KC_EXLM,   KC_AT,      KC_HASH,    KC_DLR,      KC_PERC,   KC_P7,   KC_P8,   KC_P9,   KC_CIRC,  KC_AMPR,      KC_ASTR,   KC_LPRN,   KC_RPRN,   KC_F12,
   _______, _______,   _______,    _______,    _______,     _______,   KC_P4,   KC_P5,   KC_P6,   KC_LEFT,  KC_DOWN,      KC_UP,     KC_RGHT,   _______,   _______,
   _______, _______,   _______,    _______,    _______,     _______,   KC_P1,   KC_P2,   KC_P3,   KC_PENT,  _______,      _______,   _______,   _______,   _______,
   _______, _______,   _______,    _______,    MO(_LOWER),  _______,   KC_P0,   _______, KC_PDOT, _______,  MO(_UPPER),   KC_VOLD,   KC_VOLU,   KC_MUTE,   TG(_GAMES)
 ),
 /* GAMES
  * .--------------------------------------------------------------------------------------------------------------------------------------.
  * | ESC    | 1      | 2      | 3      | 4      | 5      | -      | `      | =      | 6      | 7      | 8      | 9      | 0      | BACKSP |
  * |--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+-----------------|
  * | TAB    | Q      | W      | E      | R      | T      | [      | \      | ]      | Y      | U      | I      | O      | P      | '      |
  * |--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+-----------------+--------|
  * | CAP LK | A      | S      | D      | F      | G      | HOME   | DEL    | PG UP  | H      | J      | K      | L      | ;      | ENTER  |
  * |--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------------------------+--------|
  * | LSHIFT | Z      | X      | C      | V      | B      | END    | UP     | PG DN  | N      | M      | ,      | .      | /      | RSHIFT |
  * |--------+--------+--------+--------+--------+-----------------+--------+--------+--------+--------+-----------------+--------+--------|
  * | LCTRL  | LGUI   | LALT   | FN     | SPACE  | SPACE  | LEFT   | DOWN   | RIGHT  | SPACE  | SPACE  | FN     | RALT   | RGUI   | RCTRL  |
  * '--------------------------------------------------------------------------------------------------------------------------------------'
  */

   [_GAMES] = LAYOUT_ortho_5x15( /* GAMES */
     KC_ESC,  KC_1,    KC_2,    KC_3,       KC_4,    KC_5,    KC_MINS, KC_GRV,  KC_EQL,  KC_6,    KC_7,      KC_8,    KC_9,    KC_0,    KC_BSDEL,
     KC_TAB,  KC_Q,    KC_W,    KC_E,       KC_R,    KC_T,    KC_LBRC, KC_BSLS, KC_RBRC, KC_Y,    KC_U,      KC_I,    KC_O,    KC_P,    KC_QUOT,
     KC_CAPS, KC_A,    KC_S,    KC_D,       KC_F,    KC_G,    KC_HOME, KC_DEL,  KC_PGUP, KC_H,    KC_J,      KC_K,    KC_L,    KC_SCLN, KC_ENT,
     KC_LSFT, KC_Z,    KC_X,    KC_C,       KC_V,    KC_B,    KC_END,  KC_UP,   KC_PGDN, KC_N,    KC_M,      KC_COMM, KC_DOT,  KC_SLSH, KC_RSFT,
     KC_LCTL, KC_LGUI, KC_LALT, MO(_LOWER), KC_SPC,  KC_SPC,  KC_LEFT, KC_DOWN, KC_RGHT, KC_SPC,  MO(_UPPER),_______, KC_RALT, KC_RGUI, KC_RCTL
   ),

 // RGB_HUD, RGB_HUI
 // RGB_SAD, RGB_SAI
 // RGB_VAD, RGB_VAI
 // RGB_RMOD,RGB_MOD
[_KEEB] = LAYOUT_ortho_5x15( /* NUM */
  RESET,   _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______ ,
  RGB_HUD, RGB_HUI, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______ ,
  RGB_SAD, RGB_SAI, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______ ,
  RGB_VAD, RGB_VAI, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______ ,
  RGB_RMOD,RGB_MOD, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______
)
};
bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  switch (keycode) {
    case QMKBEST:
      if (record->event.pressed) {
        // when keycode QMKBEST is pressed
        SEND_STRING("QMK is the best thing ever!");
      } else {
        // when keycode QMKBEST is released
      }
      break;
    case QMKURL:
      if (record->event.pressed) {
        // when keycode QMKURL is pressed
        SEND_STRING("https://qmk.fm/" SS_TAP(X_ENTER));
      } else {
        // when keycode QMKURL is released
      }
      break;
    static bool bsdel_mods = false;
    case BSPCDEL:
      if (record -> event.pressed){ // KC_BKSP pressed
        if (get_mods() & MOD_BIT(KC_LSFT)) { // KC_LSFT is pressed
          unregister_code(KC_LSFT);
          register_code(KC_DEL);
          bsdel_mods = true;
        }else{ // KC_LSFT not pressed
            register_code(KC_BSPC);
          }
      } else {// KC_BKSP released
          if (bsdel_mods) {
            unregister_code(KC_DEL);
            register_code(KC_LSFT);
            bsdel_mods = false;
          } else {
            unregister_code(KC_BSPC);
          }
      }

    return false;
    break;
  }
  return true;
}

void matrix_init_user(void) {

}

void matrix_scan_user(void) {

}

void led_set_user(uint8_t usb_led) {

}
