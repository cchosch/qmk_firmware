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

// Defines names for use in layer keycodes and the keymap
enum layer_names {
    _BASE,
    _FN,
    _GM
};


// Defines the keycodes used by our macros in process_record_user
enum custom_keycodes {
    ALTTAB = SAFE_RANGE
};

/*
 *
 *                 +------+------+------+------+
 *   +------+------|  2   |  3   |  4   |  5   |
 *   |  `   |  1   |------+------+------+------|
 *   +------+------|  W   |  E   |  R   |  T   |
 *   | TAB  |  Q   |------+------+------+------|
 *   +------+------|  S   |  D   |  F   |  G   |
 *   | ESC  |  A   |------+------+------+------|
 *   +------+------|  X   |  C   |  V   |  B   |
 *   | CTRL |  Z   |------+------+------+------|
 *   +------+------| ALT  |ALTTAB|
 *                 +------+------+
 *                                +------+------+
 *                                |  FN  | SHIFT|
 *                                +------+------+
 *                                       +------+------+
 *                                       |  XXX | SPACE|
 *                                       +------+------+
 *                                       |  XXX |  XXX |
 *                                       +------+------+
 *
 */
const uint16_t PROGMEM keymaps[3][MATRIX_ROWS][MATRIX_COLS] = {
    /* Base */
    [_BASE] = LAYOUT_DACTYL_LEFT(
    KC_GRV, KC_1, KC_2, KC_3, KC_4, KC_5,
    KC_TAB, KC_Q, KC_W, KC_E, KC_R, KC_T,
    KC_ESC, KC_A, KC_S, KC_D, KC_F, KC_G,
    KC_LCTRL, KC_Z, KC_X, KC_C, KC_V, KC_B,
                    KC_LALT, ALTTAB,
                            TG(_FN), KC_LSHIFT,
                                XXXXXXX, KC_SPACE,
                                XXXXXXX, TG(_GM)
    ),
    [_GM] = LAYOUT_DACTYL_LEFT(
    KC_GRV, _______, _______, _______, _______, _______,
    KC_TAB, KC_T, KC_Q, KC_W, KC_E, KC_R,
    _______, KC_G, KC_A, KC_S, KC_D, KC_F,
    KC_LCTRL, KC_B, KC_Z, KC_X, KC_C, KC_V,
                    _______, KC_SPACE,
                            _______, KC_LSHIFT,
                                _______, _______,
                                _______, _______
    ),
    [_FN] = LAYOUT_DACTYL_LEFT(
    _______, KC_F1, KC_F2, KC_F3, KC_F4, KC_F5,
    _______, _______, _______, _______, _______, _______,
    KC_CLCK, _______, _______, _______, _______, _______,
    _______, _______, _______, _______, _______, _______,
                    KC_PGUP, KC_PGDOWN,
                            _______, _______,
                                _______, _______,
                                _______, _______
    )
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
