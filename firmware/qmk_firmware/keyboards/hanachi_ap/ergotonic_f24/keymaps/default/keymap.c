/* Copyright 2022 hanachi-ap
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
#ifdef CONSOLE_ENABLE
  #include <print.h>
#endif
// Defines names for use in layer keycodes and the keymap
enum layer_names {
    _BASE,
    _L1,
    _L2,
    _L3,
};

// Defines the keycodes used by our macros in process_record_user
enum custom_keycodes {
    QMKBEST = SAFE_RANGE,
    QMKURL
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    /* Base */
    [_BASE] = LAYOUT( 
	KC_ESC,	   KC_Q,   KC_W,   KC_E,   KC_R,   KC_T,                     KC_Y,   KC_U,   KC_I,   KC_O,   KC_P,     KC_LBRC,
	KC_TAB,    KC_A,   KC_S,   KC_D,   KC_F,   KC_G,                     KC_H,   KC_J,   KC_K,   KC_L,   KC_SCLN,  KC_QUOT,
	KC_LSFT,   KC_Z,   KC_X,   KC_C,   KC_V,    KC_B,  KC_DEL,   KC_LGUI,KC_N,   KC_M,   KC_COMM,KC_DOT, KC_SLSH,  KC_SLSH,
    KC_LALT,                   KC_LEFT,KC_RIGHT,KC_SPC,KC_LCTL,  KC_BSPC,KC_ENT, KC_DOWN, KC_UP,                    KC_ENT,
     KC_A, KC_B,                         KC_D, KC_E, KC_F,                               KC_G, KC_H, KC_I,                  KC_J, KC_K 
    )    ,


        [_L1] = LAYOUT(
	KC_ESC,	   KC_Q,   KC_W,   KC_E,   KC_R,   KC_T,                     KC_Y,   KC_U,   KC_I,   KC_O,   KC_P,     KC_LBRC,
	KC_TAB,    KC_A,   KC_S,   KC_D,   KC_F,   KC_G,                     KC_H,   KC_J,   KC_K,   KC_L,   KC_SCLN,  KC_QUOT,
	KC_LSFT,   KC_Z,   KC_X,   KC_C,   KC_V,   KC_B,  KC_DEL,    KC_LGUI,KC_N,   KC_M,   KC_COMM,KC_DOT, KC_SLSH, KC_SLSH,
    KC_LGUI,                   KC_LEFT,KC_RIGHT,KC_SPC,KC_LCTL,  KC_BSPC,KC_ENT, KC_DOWN, KC_UP,                      KC_ENT,
     KC_A, KC_B,  KC_D, KC_E, KC_F,               KC_G, KC_H, KC_I, KC_J, KC_K 
    )    ,


        [_L2] = LAYOUT(
	KC_ESC,	   KC_Q,   KC_W,   KC_E,   KC_R,   KC_T,                     KC_Y,   KC_U,   KC_I,   KC_O,   KC_P,     KC_LBRC,
	KC_TAB,    KC_A,   KC_S,   KC_D,   KC_F,   KC_G,                     KC_H,   KC_J,   KC_K,   KC_L,   KC_SCLN,  KC_QUOT,
	KC_LSFT,   KC_Z,   KC_X,   KC_C,   KC_V,   KC_B,  KC_DEL,    KC_LGUI,KC_N,   KC_M,   KC_COMM,KC_DOT, KC_SLSH, KC_SLSH,
    KC_LGUI,                   KC_LEFT,KC_RIGHT,KC_SPC,KC_LCTL,  KC_BSPC,KC_ENT, KC_DOWN, KC_UP,                      KC_ENT,
     KC_A, KC_B,  KC_D, KC_E, KC_F,               KC_G, KC_H, KC_I, KC_J, KC_K 
    )    ,


        [_L3] = LAYOUT(
		KC_ESC,	   KC_Q,   KC_W,   KC_E,   KC_R,   KC_T,                     KC_Y,   KC_U,   KC_I,   KC_O,   KC_P,     KC_LBRC,
	KC_TAB,    KC_A,   KC_S,   KC_D,   KC_F,   KC_G,                     KC_H,   KC_J,   KC_K,   KC_L,   KC_SCLN,  KC_QUOT,
	KC_LSFT,   KC_Z,   KC_X,   KC_C,   KC_V,   KC_B,  KC_DEL,    KC_LGUI,KC_N,   KC_M,   KC_COMM,KC_DOT, KC_SLSH, KC_SLSH,
    KC_LGUI,                   KC_LEFT,KC_RIGHT,KC_SPC,KC_LCTL,  KC_BSPC,KC_ENT, KC_DOWN, KC_UP,                      KC_ENT,
     KC_A, KC_B,  KC_D, KC_E, KC_F,               KC_G, KC_H, KC_I, KC_J, KC_K 
    )    


};


void keyboard_post_init_user(void) {
  //  rgblight_mode_noeeprom(RGBLIGHT_MODE_RGB_TEST);
#ifdef CONSOLE_ENABLE
    debug_enable = true;
    debug_matrix = true;
#endif
}

#ifdef ENCODER_ENABLE
const uint8_t rt_matrix[][4][2] = {
    {{3,1},{3,2}},
    {{0,6},{1,6}},
    {{7,4},{7,5}},
    {{4,0},{5,0}},
};

bool encoder_update_user(uint8_t index, bool clockwise) {
    keypos_t key;

    int      cw = 0;
    if (clockwise) cw = 1;
    key.row          = rt_matrix[index][cw][0];
    key.col          = rt_matrix[index][cw][1];

    action_exec((keyevent_t){.key = key, .pressed = true, .time = (timer_read() | 1)});
    action_exec((keyevent_t){.key = key, .pressed = false, .time = (timer_read() | 1)});

    return false;
}
#endif
