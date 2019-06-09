#include QMK_KEYBOARD_H
#include "keymap_uk.h"

extern keymap_config_t keymap_config;

enum planck_layers {
	_BASE,
	_SPECIAL
};

// shift on hold, caps lock on tap
#define L_SHIFT MT(MOD_LSFT, KC_CAPS)
#define R_SHIFT MT(MOD_RSFT, KC_CAPS)

// special layer on hold
#define SPECIAL MO(_SPECIAL)

// special layer + shift on hol1d
//#define SPE_SFT LM(_SPECIAL, MOD_LSFT)

#define PIPE  LSFT(KC_NUBS)

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
	
	[_BASE] = LAYOUT_planck_grid(
		KC_TAB,  KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,    KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_BSPC,
		KC_ESC,  KC_A,    KC_S,    KC_D,    KC_F,    KC_G,    KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, KC_ENT,
		L_SHIFT, KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH, R_SHIFT,
		KC_LCTL, _______, KC_LGUI, KC_LALT, SPECIAL, KC_SPC,  KC_SPC,  SPECIAL, KC_LEFT, KC_DOWN, KC_UP,   KC_RGHT
	),
	
	[_SPECIAL] = LAYOUT_planck_grid(
		KC_GRV,  KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_DEL,
		_______, KC_EXLM, UK_DQUO, UK_PND,  KC_DLR,  KC_PERC, KC_CIRC, KC_AMPR, KC_ASTR, KC_LPRN, KC_RPRN, UK_HASH,
		UK_AT,   KC_MINS, KC_EQL,  XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, UK_BSLS, KC_LBRC, KC_RBRC, UK_TILD,
		UK_QUOT, KC_UNDS, KC_PLUS, XXXXXXX, XXXXXXX, _______, _______, XXXXXXX, UK_PIPE, KC_LCBR, KC_RCBR, XXXXXXX
	),
	
};

/*
enum custom_keycodes {
	DUMMY = SAFE_RANGE,
	
	// hold-tap
	Q_1, W_2, E_3, R_4, T_5, Y_6, U_7, I_8, O_9, P_0,
	A_AT, S_HASH, D_POUND, F_UNDER, G_AND, H_MINUS, J_PLUS, K_PAREN, L_PAREN,
	Z_STAR, X_DQUOT, C_QUOT, V_COLON, B_SEMI, N_EXCLA, M_QUEST,
};


// handle custom keycodes
bool process_record_user(uint16_t keycode, keyrecord_t *record) {
	static uint16_t hold_timer;
	
	switch (keycode) {
		// hold-tap keycodes (e.g. Q_1 is "q" when tapped but "1" when held)
		case Q_1: case W_2: case E_3: case R_4: case T_5: case Y_6: case U_7: case I_8: case O_9: case P_0:
			if (record->event.pressed) {
				// press begin
				hold_timer = timer_read();
			} else if (timer_elapsed(hold_timer) < TAPPING_TERM) {
				// tap
				switch (keycode) {
					case Q_1: SEND_STRING("q"); break;
					case W_2: SEND_STRING("w"); break;
					case E_3: SEND_STRING("e"); break;
					case R_4: SEND_STRING("r"); break;
					case T_5: SEND_STRING("t"); break;
					case Y_6: SEND_STRING("y"); break;
					case U_7: SEND_STRING("u"); break;
					case I_8: SEND_STRING("i"); break;
					case O_9: SEND_STRING("o"); break;
					case P_0: SEND_STRING("p"); break;
}
			} else {
				// hold
				switch (keycode) {
					case Q_1: SEND_STRING("1"); break;
					case W_2: SEND_STRING("2"); break;
					case E_3: SEND_STRING("3"); break;
					case R_4: SEND_STRING("4"); break;
					case T_5: SEND_STRING("5"); break;
					case Y_6: SEND_STRING("6"); break;
					case U_7: SEND_STRING("7"); break;
					case I_8: SEND_STRING("8"); break;
					case O_9: SEND_STRING("9"); break;
					case P_0: SEND_STRING("0"); break;
				}
			}
			return false; // handled
		
		// unhandled
		default:
			return true;
	}
}
*/
