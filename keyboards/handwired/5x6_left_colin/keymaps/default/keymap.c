/* Copyright 2021 Colin
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
#include "5x6_left_colin.h"

// Defines names for use in layer keycodes and the keymap
enum layer_names {
    _BASE,
    _GM,
    _FN,
    _RS
};


// Defines the keycodes used by our macros in process_record_user
enum custom_keycodes {
    ALTTAB = SAFE_RANGE
};

const uint16_t PROGMEM keymaps[4][MATRIX_ROWS][MATRIX_COLS] = {
    /* Base */
    [_BASE] = COLIN_RIGHT_DACTYL_LAYOUT(
    KC_GRV, KC_1, KC_2, KC_3, KC_4, KC_5,  
    KC_TAB, KC_Q, KC_W, KC_E, KC_R, KC_T,  
    KC_ESC, KC_A, KC_S, KC_D, KC_F, KC_G, 
    KC_LCTL, KC_Z, KC_X, KC_C, KC_V, KC_B,  
                    KC_LALT, KC_LGUI,  
                            MO(_FN), KC_LSFT, 
                                XXXXXXX, KC_SPACE, 
                                XXXXXXX, TG(_GM)  
),
    [_GM] = COLIN_RIGHT_DACTYL_LAYOUT(
    _______, _______, _______, _______, _______, _______,  
    _______, KC_T, KC_Q, KC_W, KC_E, KC_R,   
    _______, KC_G, KC_A, KC_S, KC_D, KC_F,  
    _______, KC_B, KC_Z, KC_X, KC_C, KC_V,   
                    _______, _______,  
                            _______, KC_SPACE, 
                                _______, KC_LSFT, 
                                _______, _______  
),
    [_FN] = COLIN_RIGHT_DACTYL_LAYOUT(
    _______, KC_F1, KC_F2, KC_F3, KC_F4, KC_F5,  
    MO(_RS), _______, _______, _______, _______, _______,  
    KC_CAPS, _______, _______, _______, _______, _______,  
    ALTTAB, _______, _______, _______, _______, _______,  
                    KC_PGUP, KC_PGDN,  
                            _______, _______, 
                                _______, _______, 
                                _______, _______  
),
    [_RS] = COLIN_RIGHT_DACTYL_LAYOUT(
    _______, _______, _______, _______, _______, _______,  
    _______, QK_BOOT, _______, _______, _______, _______,  
    _______, _______, _______, _______, _______, _______,  
    _______, _______, _______, _______, _______, _______,  
                    _______, _______,  
                            _______, _______, 
                                _______, _______, 
                                _______, _______  
),
};
bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    switch(keycode){
        case ALTTAB:
            if (record->event.pressed) { //keydown
                SEND_STRING(SS_DOWN(X_LALT));
                SEND_STRING(SS_TAP(X_TAB));
                SEND_STRING(SS_UP(X_LALT));
            }
            return false;
        default: return true;
    }
}
/**/