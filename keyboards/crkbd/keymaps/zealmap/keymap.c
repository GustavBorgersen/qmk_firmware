/*
Copyright 2019 @foostan
Copyright 2020 Drashna Jaelre <@drashna>

This program is free software: you can redistribute it and/or modify
it under the terms of the GNU General Public License as published by
the Free Software Foundation, either version 2 of the License, or
(at your option) any later version.

This program is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU General Public License for more details.

You should have received a copy of the GNU General Public License
along with this program.  If not, see <http://www.gnu.org/licenses/>.
*/

#include QMK_KEYBOARD_H


const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
	[0] = LAYOUT_split_3x6_3(	KC_ESC, KC_Q,   KC_W,   KC_E,       KC_R,   KC_T, 			KC_Y,       KC_U,   KC_I,   KC_O,   KC_P,       KC_LBRC,
								KC_TAB, KC_A,   KC_S,   KC_D,       KC_F,   KC_G,			KC_H,       KC_J,   KC_K,   KC_L,   KC_SCLN,    KC_QUOT,
								KC_LSFT,KC_Z,   KC_X,   KC_C,       KC_V,   KC_B,			KC_N,       KC_M,   KC_COMM,KC_DOT, KC_SLSH,    KC_ENT,
												        KC_LALT,    MO(1),  KC_SPC, 	    KC_BSPC,    TT(2),  KC_LGUI),

	[1] = LAYOUT_split_3x6_3(	KC_UNDS, 	KC_EXLM, 	KC_AT, 		KC_HASH,    KC_PERC,    KC_CIRC, 			    KC_AMPR, KC_PAST,   RALT(KC_MINS),  KC_ASTR,        KC_LPRN,    KC_RPRN,
								RALT(KC_2), KC_TRNS, 	KC_TRNS, 	KC_TRNS,    KC_TRNS,    RALT(KC_3), 	        KC_NUBS, KC_UP,     LSFT(KC_NUBS),  RALT(KC_7),     RALT(KC_0), RALT(KC_NUBS),
								KC_LCTL,    KC_TRNS,    KC_TRNS,    KC_TRNS,    KC_TRNS,    RALT(KC_4), 			KC_LEFT, KC_DOWN,   KC_RGHT,        RALT(KC_8),     RALT(KC_9), KC_ENT,
												                    KC_LALT,    KC_TRNS,    KC_SPC, 			    KC_BSPC, MO(3),     KC_LGUI),

	[2] = LAYOUT_split_3x6_3(   KC_NO,      KC_NO,  KC_NO,  KC_NO,      KC_NO,  KC_NO,              KC_PSLS,       KC_PAST,    KC_P7,  KC_P8,  KC_P9,  KC_PMNS,
                                KC_TAB,     KC_NO,  KC_NO,  KC_NO,      KC_NO,  KC_NO,              KC_BSLS,       KC_NO,      KC_P4,  KC_P5,  KC_P6,  KC_PPLS,
                                KC_LCTL,    KC_NO,  KC_NO,  KC_NO,      KC_NO,  KC_NO,              KC_PDOT,       KC_P0,      KC_P1,  KC_P2,  KC_P3,  KC_ENT,
                                                            KC_LALT,    MO(3),  KC_NO,              KC_DEL,        KC_TRNS,    KC_NO),

	[3] = LAYOUT_split_3x6_3(   QK_BOOT,    KC_NO,      KC_NO,      KC_NO,      KC_NO,      KC_NO,          KC_NO, KC_NO,   KC_NO, KC_NO, KC_NO, KC_NO,
                                RGB_TOG,    RGB_HUI,    RGB_SAI,    RGB_VAI,    KC_NO,      KC_NO,          KC_NO, KC_NO,   KC_NO, KC_NO, KC_NO, KC_NO,
                                RGB_MOD,    RGB_HUD,    RGB_SAD,    RGB_VAD,    KC_NO,      KC_NO,          KC_NO, KC_NO,   KC_NO, KC_NO, KC_NO, KC_NO,
                                                                    KC_NO,      KC_TRNS,    KC_NO,          KC_NO, KC_TRNS, KC_NO)
};


bool rgb_matrix_indicators_advanced_user(uint8_t led_min, uint8_t led_max) {
    for (uint8_t i = led_min; i < led_max; i++) {
        switch(get_highest_layer(layer_state|default_layer_state)) {
            case 3:
                rgb_matrix_set_color(i, RGB_PINK);
                break;
            case 2:
                rgb_matrix_set_color(i, RGB_BLUE);
                break;
            case 1:
                rgb_matrix_set_color(i, RGB_YELLOW);
                break;
            case 0:
                rgb_matrix_set_color(i, RGB_MAGENTA);
                break;
            default:
				rgb_matrix_set_color(i, RGB_RED);
                break;
        }
    }
    return false;
}
