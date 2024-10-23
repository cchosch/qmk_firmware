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
#include "5x6_right_colin.h"
// Defines names for use in layer keycodes and the keymap
enum layer_names {
    _BASE,
    _FN,
    _RS
};

// Defines the keycodes used by our macros in process_record_user

const uint16_t PROGMEM keymaps[3][MATRIX_ROWS][MATRIX_COLS] = {
    /* Base */
    [_BASE] = COLIN_RIGHT_DACTYL_LAYOUT(
        KC_6, KC_7, KC_8, KC_9, KC_0, KC_BSPC,
        KC_Y, KC_U, KC_I, KC_O, KC_P, KC_QUOT,
        KC_H, KC_J, KC_K, KC_L, KC_SCLN, KC_ENT,
        KC_N, KC_M, KC_COMM, KC_DOT, KC_SLSH, KC_BSLS,
                  KC_PMNS, KC_PPLS,
          KC_SPC, MO(_FN),
    KC_NO, KC_NO,
    KC_NO, KC_NO
),
    [_FN] = COLIN_RIGHT_DACTYL_LAYOUT(
        KC_F6, KC_F7, KC_F8, KC_F9, KC_F10, KC_F11, 
        _______, KC_MINS, KC_EQL, KC_LBRC, KC_RBRC, KC_F12, 
        KC_LEFT, KC_DOWN, KC_UP, KC_RGHT, KC_INSERT, KC_DEL, 
        _______, KC_MPRV, KC_MPLY, KC_MNXT, _______, MO(_RS), 
                  _______, _______, 
          _______, _______, 
    _______, _______, 
    _______, _______  
),
    [_RS] = COLIN_RIGHT_DACTYL_LAYOUT(
        _______, _______, _______, _______, _______, _______,
        _______, _______, _______, _______, _______, _______,
        _______, QK_BOOT, _______, _______, _______, _______,
        _______, _______, _______, _______, _______, _______,
                  _______, _______,
          _______, _______,
    _______, _______,
    _______, _______
    ),
};

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    return true;
}
