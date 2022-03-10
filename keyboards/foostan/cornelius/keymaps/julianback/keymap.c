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

// https://github.com/qmk/qmk_firmware/blob/master/docs/feature_advanced_keycodes.md#shift--backspace-for-delete-idshift-backspace-for-delete
// Initialize variable holding the binary
// representation of active modifiers.
uint8_t mod_state;
bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    // Store the current modifier state in the variable for later reference
    mod_state = get_mods();
    switch (keycode) {

        case KC_BSPC:
        {
            // Initialize a boolean variable that keeps track
            // of the delete key status: registered or not?
            static bool delkey_registered;
            if (record->event.pressed) {
                // Detect the activation of either shift keys
                if (mod_state & MOD_MASK_SHIFT) {
                    // First temporarily canceling both shifts so that
                    // shift isn't applied to the KC_DEL keycode
                    del_mods(MOD_MASK_SHIFT);
                    register_code(KC_DEL);
                    // Update the boolean variable to reflect the status of KC_DEL
                    delkey_registered = true;
                    // Reapplying modifier state so that the held shift key(s)
                    // still work even after having tapped the Backspace/Delete key.
                    set_mods(mod_state);
                    return false;
                }
            } else { // on release of KC_BSPC
                // In case KC_DEL is still being sent even after the release of KC_BSPC
                if (delkey_registered) {
                    unregister_code(KC_DEL);
                    delkey_registered = false;
                    return false;
                }
            }
            // Let QMK process the KC_BSPC keycode as usual outside of shift
            return true;
        }

    }
    return true;
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
[0] = LAYOUT(
     KC_TAB,    KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,    KC_Y,    KC_U,    KC_I,      KC_O,    KC_P, KC_BSPC,
     KC_ESC,    KC_A,    KC_S,    KC_D,    KC_F,    KC_G,    KC_H,    KC_J,    KC_K,      KC_L, KC_SCLN, KC_QUOT,
    KC_LSFT,    KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    KC_N,    KC_M, KC_COMM,    KC_DOT, KC_SLSH, KC_RSFT,
    _______, KC_LGUI, KC_LALT, KC_LCTL,  KC_ENT,   MO(2),   MO(1),  KC_SPC, KC_RCTL,   KC_LALT, KC_RGUI,   MO(3)
  ),

[1] = LAYOUT(
    XXXXXXX, XXXXXXX,   KC_P7,   KC_P8,   KC_P9, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,   XXXXXXX, XXXXXXX, KC_BSPC,
    XXXXXXX,   KC_P0,   KC_P4,   KC_P5,   KC_P6, XXXXXXX, KC_LEFT, KC_DOWN,   KC_UP,   KC_RGHT, XXXXXXX, XXXXXXX,
    KC_LSFT, XXXXXXX,   KC_P1,   KC_P2,   KC_P3, XXXXXXX, XXXXXXX, XXXXXXX, KC_COMM, KC_KP_DOT, XXXXXXX, KC_RSFT,
    XXXXXXX, KC_LGUI, KC_LALT, KC_LCTL,  KC_ENT, XXXXXXX, _______,  KC_SPC, KC_RCTL,   KC_LALT, KC_RGUI, XXXXXXX
  ),

[2] = LAYOUT(
     KC_TAB, XXXXXXX, XXXXXXX,  KC_DLR, XXXXXXX, XXXXXXX, KC_HASH, KC_PLUS, KC_PAST,   KC_MINS,  KC_EQL, KC_BSPC,
    XXXXXXX, KC_CIRC, KC_UNDS, KC_BSLS,  KC_GRV, KC_EXLM, KC_LPRN, KC_LCBR, KC_LBRC,   KC_RBRC, KC_RCBR, KC_RPRN,
    XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, KC_PERC,   KC_AT, KC_AMPR,   KC_PIPE, KC_TILD, KC_PERC,
    XXXXXXX, KC_LGUI, KC_LALT, KC_LCTL,  KC_ENT, _______, XXXXXXX,  KC_SPC, KC_RCTL,   KC_LALT, KC_RGUI, XXXXXXX
  ),

[3] = LAYOUT(
    XXXXXXX,  KC_F12,   KC_F7,   KC_F8,   KC_F9, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,   XXXXXXX, XXXXXXX, XXXXXXX,
    XXXXXXX,  KC_F11,   KC_F4,   KC_F5,   KC_F6, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,   XXXXXXX, XXXXXXX, XXXXXXX,
    XXXXXXX,  KC_F10,   KC_F1,   KC_F2,   KC_F3, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,   XXXXXXX, XXXXXXX, XXXXXXX,
    XXXXXXX, KC_LGUI, KC_LALT, KC_LCTL,  KC_ENT, XXXXXXX, XXXXXXX,  KC_SPC, KC_RCTL,   KC_LALT, KC_RGUI, _______
  ),

[4] = LAYOUT(
    XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,   XXXXXXX, XXXXXXX, XXXXXXX,
    XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,   XXXXXXX, XXXXXXX, XXXXXXX,
    XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,   XXXXXXX, XXXXXXX, XXXXXXX,
    XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,   XXXXXXX, XXXXXXX, XXXXXXX
  ),
};
