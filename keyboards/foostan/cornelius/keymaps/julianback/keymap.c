/* Copyright 2020 foostan
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

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
[0] = LAYOUT(
     KC_TAB,    KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,    KC_Y,    KC_U,    KC_I,    KC_O,     KC_P, KC_BSPC,
     KC_ESC,    KC_A,    KC_S,    KC_D,    KC_F,    KC_G,    KC_H,    KC_J,    KC_K,    KC_L,  KC_SCLN, KC_QUOT,
    KC_LSFT,    KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    KC_N,    KC_M, KC_COMM,  KC_DOT,  KC_SLSH, KC_RSFT,
    KC_HYPR, KC_LGUI, KC_LALT, KC_LCTL,  KC_ENT,   MO(2),   MO(1),  KC_SPC, KC_RCTL, KC_LALT,  KC_RGUI, KC_HYPR
  ),

[1] = LAYOUT(
    XXXXXXX, XXXXXXX,    KC_7,    KC_8,    KC_9, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,  XXXXXXX, XXXXXXX,
    XXXXXXX,    KC_0,    KC_4,    KC_5,    KC_6, XXXXXXX, KC_LEFT, KC_DOWN,   KC_UP, KC_RGHT,  XXXXXXX, XXXXXXX,
    XXXXXXX, XXXXXXX,    KC_1,    KC_2,    KC_3, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,  XXXXXXX, XXXXXXX,
    KC_HYPR, KC_LGUI, KC_LALT, KC_LCTL,  KC_ENT, XXXXXXX, _______, XXXXXXX, XXXXXXX, XXXXXXX,  XXXXXXX, XXXXXXX
  ),

[2] = LAYOUT(
     KC_TAB, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, KC_HASH, KC_PLUS, KC_PAST,  KC_EQL,  KC_MINS, KC_BSPC,
    XXXXXXX, KC_EXLM, KC_UNDS, KC_BSLS,  KC_GRV, KC_CIRC, KC_LPRN, KC_LCBR, KC_LBRC, KC_RBRC,  KC_RCBR, KC_RPRN,
    XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,   KC_AT,  KC_DLR, KC_AMPR, KC_PIPE,  KC_TILD, KC_PERC,
    XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, _______, XXXXXXX,  KC_SPC, KC_RCTL, KC_LALT,  KC_RGUI, KC_HYPR
  ),

[3] = LAYOUT(
    XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,  XXXXXXX, XXXXXXX,
    XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,  XXXXXXX, XXXXXXX,
    XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,  XXXXXXX, XXXXXXX,
    XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,  XXXXXXX, XXXXXXX
  ),
};
