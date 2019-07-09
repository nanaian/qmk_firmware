#include QMK_KEYBOARD_H
#include "keymap_uk.h"

// layers
#define _BASE 0
#define _SHFT 1
#define _FUNC 2

// leftshift key. activates shifted layer for special overides eg. ` -> Esc
#define L_SHIFT LM(_SHFT, MOD_LSFT)

// rightshift key. but when tapped, emits Home
#define R_SHIFT MT(MOD_RSFT, UK_HOME)

// Fn key
#define FN MO(_FUNC)

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  // base layer
  [_BASE] = LAYOUT_ansi(
    UK_GRV,  UK_1,    UK_2,    UK_3,    UK_4,    UK_5,    UK_6,    UK_7,    UK_8,    UK_9,    UK_0,    UK_MINS, UK_EQL,  UK_BSPC, UK_DEL,  \
    UK_TAB,  UK_Q,    UK_W,    UK_E,    UK_R,    UK_T,    UK_Y,    UK_U,    UK_I,    UK_O,    UK_P,    UK_LBRC, UK_RBRC, UK_HASH, UK_PGUP, \
    KC_CAPS, UK_A,    UK_S,    UK_D,    UK_F,    UK_G,    UK_H,    UK_J,    UK_K,    UK_L,    UK_SCLN, UK_QUOT, UK_ENT,           UK_PGDN, \
    L_SHIFT,          UK_Z,    UK_X,    UK_C,    UK_V,    UK_B,    UK_N,    UK_M,    UK_COMM, UK_DOT,  UK_SLSH, R_SHIFT, UK_UP,   UK_END,  \
    UK_LCTL, UK_LGUI, UK_LALT, UK_SPC,                                               KC_ALGR, FN,      UK_BSLS, UK_LEFT, UK_DOWN, UK_RGHT  ),
  
  // faux-shift layer
  [_SHFT] = LAYOUT_ansi(
    UK_ESC,  _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, \
    _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, \
    _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,          _______, \
    _______,          _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, UK_HOME, \
    _______, _______, _______, _______,                                              _______, _______, _______, _______, _______, _______  ),
  
  // function layer
  [_FUNC] = LAYOUT_ansi(
    RESET,   KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,  KC_F12,  _______, BL_TOGG, \
    _______, _______, _______, UK_EURO, _______, _______, _______, _______, _______, _______, KC_PSCR, _______, _______, _______, BL_INC,  \
    _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, KC_MPLY,          BL_DEC,  \
    _______,          _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, KC_VOLU, BL_BRTG, \
    _______, _______, _______, _______,                                              _______, _______, _______, KC_MPRV, KC_VOLD, KC_MNXT  )
};
