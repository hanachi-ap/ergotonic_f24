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
#include <stdio.h>
#include "quantum.h"
#ifdef CONSOLE_ENABLE
  #include <print.h>
#endif
#include "via.h"

// Defines names for use in layer keycodes and the keymap
enum layer_names {
    _BASE,
    _L1,
    _L2,
    _L3,
};

// Defines the keycodes used by our macros in process_record_user
enum custom_keycodes {
    QMKBEST = SAFE_RANGE

};

#define CPI_SW USER00
#define SCRL_SW USER01
#define ROT_R15 USER02
#define ROT_L15 USER03
#define SCRL_MO USER04
#define SCRL_TO USER05
#define SCRL_IN USER06


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
	XXXXXXX,   XXXXXXX,XXXXXXX,XXXXXXX,XXXXXXX,RGB_TOG,                  SCRL_TO,CPI_SW, SCRL_SW,ROT_L15,ROT_R15, XXXXXXX,
	XXXXXXX,   XXXXXXX,RGB_VAI,RGB_SAI,RGB_HUI,RGB_MOD,                  SCRL_MO,XXXXXXX,XXXXXXX,XXXXXXX,XXXXXXX, XXXXXXX,
	XXXXXXX,   XXXXXXX,RGB_VAD,RGB_SAD,RGB_HUD,RGB_RMOD,KC_DEL, KC_LGUI, SCRL_IN,XXXXXXX,XXXXXXX,XXXXXXX,XXXXXXX, XXXXXXX,
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


typedef union {
    uint32_t raw;
    struct {
        uint8_t cpi_idx;
        uint8_t scrl_div;
        uint8_t rotation_angle;
        int8_t scrl_inv;
        bool scrl_mode;
        report_mouse_t last_mouse;
    };
} cocot_config_t;


extern cocot_config_t cocot_config;


bool cocot_get_scroll_mode(void) {
    return cocot_config.scrl_mode;
}

void cocot_set_scroll_mode(bool mode) {
    cocot_config.scrl_mode = mode;
}


// Invert vertical scroll direction
#ifndef COCOT_SCROLL_INV_DEFAULT
#    define COCOT_SCROLL_INV_DEFAULT 1
#endif

#ifndef COCOT_CPI_OPTIONS
#    define COCOT_CPI_OPTIONS { 250, 500, 750, 1000, 1250 }
#    ifndef COCOT_CPI_DEFAULT
#       define COCOT_CPI_DEFAULT 4
#    endif
#endif
#ifndef COCOT_CPI_DEFAULT
#    define COCOT_CPI_DEFAULT 4
#endif

#ifndef COCOT_SCROLL_DIVIDERS
#    define COCOT_SCROLL_DIVIDERS { 1, 2, 3, 4, 5, 6 }
#    ifndef COCOT_SCROLL_DIV_DEFAULT
#       define COCOT_SCROLL_DIV_DEFAULT 4
#    endif
#endif
#ifndef COCOT_SCROLL_DIV_DEFAULT
#    define COCOT_SCROLL_DIV_DEFAULT 4
#endif


#ifndef COCOT_ROTATION_ANGLE
#    define COCOT_ROTATION_ANGLE { -60, -45, -30, -15, 0, 15, 30, 45, 60 }
#    ifndef COCOT_ROTATION_DEFAULT
#       define COCOT_ROTATION_DEFAULT 2
#    endif
#endif
#ifndef COCOT_ROTATION_DEFAULT
#    define COCOT_ROTATION_DEFAULT 2
#endif


cocot_config_t cocot_config;
uint16_t cpi_array[] = COCOT_CPI_OPTIONS;
uint16_t scrl_div_array[] = COCOT_SCROLL_DIVIDERS;
uint16_t angle_array[] = COCOT_ROTATION_ANGLE;
#define CPI_OPTION_SIZE (sizeof(cpi_array) / sizeof(uint16_t))
#define SCRL_DIV_SIZE (sizeof(scrl_div_array) / sizeof(uint16_t))
#define ANGLE_SIZE (sizeof(angle_array) / sizeof(uint16_t))


void eeconfig_init_user(void) {
    cocot_config.cpi_idx = COCOT_CPI_DEFAULT;
    cocot_config.scrl_div = COCOT_SCROLL_DIV_DEFAULT;
    cocot_config.rotation_angle = COCOT_ROTATION_DEFAULT;
    cocot_config.scrl_inv = COCOT_SCROLL_INV_DEFAULT;
    cocot_config.scrl_mode = false;
    eeconfig_update_user(cocot_config.raw);
}


void matrix_init_user(void) {
    // is safe to just read CPI setting since matrix init
    // comes before pointing device init.
    cocot_config.raw = eeconfig_read_user();
    if (cocot_config.cpi_idx > CPI_OPTION_SIZE) // || cocot_config.scrl_div > SCRL_DIV_SIZE || cocot_config.rotation_angle > ANGLE_SIZE)
    {
        eeconfig_init_user();
    }
}


layer_state_t layer_state_set_user(layer_state_t state) {

//#ifdef POINTING_DEVICE_ENABLE
    switch (get_highest_layer(state)) {
    case _L1:
        cocot_set_scroll_mode(true);
        break;
    case _L2:
        cocot_set_scroll_mode(true);
        break;
    default:
        cocot_set_scroll_mode(false);
        break;
    }
//#endif

    return state;
};


bool process_record_user(uint16_t keycode, keyrecord_t* record) {
    // xprintf("KL: kc: %u, col: %u, row: %u, pressed: %u\n", keycode, record->event.key.col, record->event.key.row, record->event.pressed);

    switch (keycode) {
#if defined(MOUSEKEY_ENABLE) || defined(POINTING_DEVICE_ENABLE)
        // process KC_MS_BTN1~8 by myself
        // See process_action() in quantum/action.c for details.
        case KC_MS_BTN1 ... KC_MS_BTN8: {
            extern void register_button(bool, enum mouse_buttons);
            register_button(record->event.pressed, MOUSE_BTN_MASK(keycode - KC_MS_BTN1));
            return false;
        }
#endif
    }

#ifdef POINTING_DEVICE_ENABLE
    if (keycode == CPI_SW && record->event.pressed) {
        cocot_config.cpi_idx = (cocot_config.cpi_idx + 1) % CPI_OPTION_SIZE;
        eeconfig_update_user(cocot_config.raw);
        pointing_device_set_cpi(cpi_array[cocot_config.cpi_idx]);
    }

    if (keycode == SCRL_SW && record->event.pressed) {
        cocot_config.scrl_div = (cocot_config.scrl_div + 1) % SCRL_DIV_SIZE;
        eeconfig_update_user(cocot_config.raw);
    }

    if (keycode == ROT_R15 && record->event.pressed) {
        cocot_config.rotation_angle = (cocot_config.rotation_angle + 1) % ANGLE_SIZE;
        eeconfig_update_user(cocot_config.raw);
    }

    if (keycode == ROT_L15 && record->event.pressed) {
        cocot_config.rotation_angle = (ANGLE_SIZE + cocot_config.rotation_angle - 1) % ANGLE_SIZE;
        eeconfig_update_user(cocot_config.raw);
    }

    if (keycode == SCRL_IN && record->event.pressed) {
        cocot_config.scrl_inv = - cocot_config.scrl_inv;
        eeconfig_update_user(cocot_config.raw);
    }

    if (keycode == SCRL_TO && record->event.pressed) {
        { cocot_config.scrl_mode ^= 1; }
    }

    if (keycode == SCRL_MO) {
        { cocot_config.scrl_mode ^= 1; }
    }
#endif

    return true;
}



#ifdef POINTING_DEVICE_ENABLE

// Scroll Accumulation
static int16_t h_acm       = 0;
static int16_t v_acm       = 0;


void pointing_device_init_user(void) {
    // set the CPI.
    pointing_device_set_cpi(cpi_array[cocot_config.cpi_idx]);
}


report_mouse_t pointing_device_task_user(report_mouse_t mouse_report) {

    double rad = angle_array[cocot_config.rotation_angle] * (M_PI / 180) * -1;
    int8_t x_rev =  + mouse_report.x * cos(rad) - mouse_report.y * sin(rad);
    int8_t y_rev =  + mouse_report.x * sin(rad) + mouse_report.y * cos(rad);

    if (cocot_get_scroll_mode()) {
        // rock scroll direction
        if (abs(x_rev) > abs(y_rev)) {
            y_rev = 0;
        } else {
            x_rev = 0;
        }

        // accumulate scroll
        h_acm += x_rev * cocot_config.scrl_inv;
        v_acm += y_rev * cocot_config.scrl_inv * -1;

        int8_t h_rev = h_acm >> scrl_div_array[cocot_config.scrl_div];
        int8_t v_rev = v_acm >> scrl_div_array[cocot_config.scrl_div];

        // clear accumulated scroll on assignment

        if (h_rev != 0) {
            if (mouse_report.h + h_rev > 127) {
                h_rev = 127 - mouse_report.h;
            } else if (mouse_report.h + h_rev < -127) {
                h_rev = -127 - mouse_report.h;
            }
            mouse_report.h += h_rev;
            h_acm -= h_rev << scrl_div_array[cocot_config.scrl_div];
        }
        if (v_rev != 0) {
            if (mouse_report.v + v_rev > 127) {
                v_rev = 127 - mouse_report.v;
            } else if (mouse_report.v + v_rev < -127) {
                v_rev = -127 - mouse_report.v;
            }
            mouse_report.v += v_rev;
            v_acm -= v_rev << scrl_div_array[cocot_config.scrl_div];
        }

        mouse_report.x = 0;
        mouse_report.y = 0;
    } else {
        mouse_report.x = x_rev;
        mouse_report.y = y_rev;
    }

    return mouse_report;
}
#endif

