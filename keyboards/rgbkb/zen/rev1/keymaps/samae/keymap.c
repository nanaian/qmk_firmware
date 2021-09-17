 /* Copyright 2020 Martin J. Potier
  *
  * This program is free software: you can redistribute it and/or modify
  * it under the terms of the GNU General Public License as published by
  * the Free Software Foundation, either version 3 of the License, or
  * (at your option) any later version.
  *
  * This program is distributed in the hope that it will be useful,
  * but WITHOUT ANY WARRANTY; without even the implied warranty of
  * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
  * GNU General Public License for more details.
  *
  * You should have received a copy of the GNU General Public License
  * along with this program.  If not, see <https://www.gnu.org/licenses/>.
  */

#include QMK_KEYBOARD_H

// Each layer gets a name for readability, which is then used in the keymap matrix below.
// The underscores don't mean anything - you can have a layer called STUFF or any other name.
// Layer names don't all need to be of the same length, obviously, and you can also skip them
// entirely and just use numbers.
enum layer_number {
    _QWERTY = 0,
    _NAV
};


enum custom_keycodes {
  QWERTY = SAFE_RANGE,
  NAV,

};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

  /* Qwerty
   * ,-----------------------------------------.                              .-----------------------------------------.
   * |   `  |   1  |   2  |   3  |   4  |   5  |                              |   6  |   7  |   8  |   9  |   0  | Bksp |
   * |------+------+------+------+------+------|                              |------+------+------+------+------+------|
   * | Tab  |   Q  |   W  |   E  |   R  |   T  |                              |   Y  |   U  |   I  |   O  |   P  |   \  |
   * |------+------+------+------+------+------|                              |------+------+------+------+------+------|
   * |DELETE|   A  |   S  |   D  |   F  |   G  |                              |   H  |   J  |   K  |   L  |   ;  |  "   |
   * |------+------+------+------+------+------|                              |------+------+------+------+------+------|
   * | Shift|   Z  |   X  |   C  |   V  |   B  |                              |   N  |   M  |   ,  |   .  |   /  |RGBMOD|
   * |------+------+------+------+------+------+------.              .--------+------+------+------+------+------+------|
   * | Ctrl | GUI  | Alt  |RGBTOG| NAV  |Space | ESC  |              |Enter|Space/NAV| AltGr|  NAV |      |   -  |   =  |
   * `------------------------------------------------'              '--------------------------------------------------'
   */
  [_QWERTY] = LAYOUT(
    KC_GRV,   KC_1,    KC_2,    KC_3,    KC_4,     KC_5,                      KC_6,               KC_7,     KC_8,    KC_9,    KC_0,    KC_BSPC,
    KC_TAB,   KC_Q,    KC_W,    KC_E,    KC_R,     KC_T,                      KC_Y,               KC_U,     KC_I,    KC_O,    KC_P,    KC_BSLS,
    KC_DEL,   KC_A,    KC_S,    KC_D,    KC_F,     KC_G,                      KC_H,               KC_J,     KC_K,    KC_L,    KC_SCLN, KC_QUOT,
    KC_LSFT,  KC_Z,    KC_X,    KC_C,    KC_V,     KC_B,                      KC_N,               KC_M,     KC_COMM, KC_DOT,  KC_SLSH, RGB_MOD,
    KC_LCTL,  KC_LGUI, KC_LALT, RGB_TOG, MO(_NAV), KC_SPC, KC_GESC,  KC_ENT,  LT(_NAV, KC_SPACE), KC_RALT, MO(_NAV), _______, KC_MINS, KC_EQL
  ),

  /* NAV
   * ,-----------------------------------------.                            .-----------------------------------------.
   * |  F1  |  F2  |  F3  |  F4  |  F5  |  F6  |                            |  F7  |  F8  |  F9  |  F10 |  F11 | F12  |
   * |------+------+------+------+------+------|                            |------+------+------+------+------+------|
   * |      |RGBSAI|RGBVAI|RGBSAD|      |  [   |                            |   ]  | Pgup |  Up  | Pgdn |Insert| Home |
   * |------+------+------+------+------+------|                            |------+------+------+------+------+------|
   * |      |RGBHUD|RGBVAD|RGBHUI|      |      |                            |      | Left | Down | Right|Delete| End  |
   * |------+------+------+------+------+------|                            |------+------+------+------+------+------|
   * |Shift |      |      |      |      |      |                            |      |      |      | Pause| Back | Next |
   * |------+------+------+------+------+------+------.              .------+------+------+------+------+------+------|
   * | Ctrl | GUI  | Alt  |RGBMOD|      |      |      |              | RESET|      |      |      | Mute | VOLUP| VOLDN|
   * `------------------------------------------------'              '------------------------------------------------'
   */
  [_NAV] = LAYOUT(
    KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,                     KC_F7,   KC_F8,    KC_F9,   KC_F10,  KC_F11,  KC_F12,
    _______, RGB_SAI, RGB_VAI, RGB_SAD, _______, KC_LBRC,                   KC_RBRC, KC_PGUP,  KC_UP,   KC_PGDN, KC_INS,  KC_HOME,
    _______, RGB_HUD, RGB_VAD, RGB_HUI, _______, _______,                   _______, KC_LEFT,  KC_DOWN, KC_RGHT, KC_DEL,  KC_END,
    KC_LSFT, _______, _______, _______, _______, _______,                   _______, _______,  _______, KC_MPLY, KC_MPRV, KC_MNXT,
    KC_LCTL, KC_LGUI, KC_LALT, RGB_MOD, _______, _______, _______, RESET,   _______, _______,  _______, KC_MUTE, KC_VOLU, KC_VOLD
  ),

};
