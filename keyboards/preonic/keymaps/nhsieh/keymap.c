/* Copyright 2015-2017 Jack Humbert
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
#include "muse.h"

enum preonic_layers {
  _QWERTY,
  _LOWER,
  _RAISE,
  _ADJUST
};

enum preonic_keycodes {
  QWERTY = SAFE_RANGE,
  VIM_MACRO,
  VIM_MACRO_REPLAY
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

/* Qwerty
 * ,-----------------------------------------------------------------------------------.
 * |   `  |   1  |   2  |   3  |   4  |   5  |   6  |   7  |   8  |   9  |   0  |  +   |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * | Tab  |   Q  |   W  |   E  |   R  |   T  |   Y  |   U  |   I  |   O  |   P  | Bksp |
 * |------+------+------+------+------+-------------+------+------+------+------+------|
 * | Esc  |   A  |   S  |   D  |   F  |   G  |   H  |   J  |   K  |   L  |   ;  |  "   |
 * |------+------+------+------+------+------|------+------+------+------+------+------|
 * | Shift|   Z  |   X  |   C  |   V  |   B  |   N  |   M  |   ,  |   .  |   /  |Return|
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * | Adj  | Ctrl | Alt  | GUI  |Lower |    Space    |Raise |   [  |   ]  |   \  |  -   |
 * `-----------------------------------------------------------------------------------'
 */
[_QWERTY] = LAYOUT_preonic_grid( \
  KC_GRV,  KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_EQL, \
  KC_TAB,  KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,    KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_BSPC,  \
  KC_ESC,  KC_A,    KC_S,    KC_D,    KC_F,    KC_G,    KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, KC_QUOT, \
  KC_LSFT, KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH, KC_ENT,  \
  TT(_ADJUST), KC_LCTL, KC_LALT, KC_LGUI, TT(_LOWER),   KC_SPC,  KC_SPC,  TT(_RAISE),   KC_LBRC, KC_RBRC, KC_BSLS, KC_MINS  \
),

/* Lower
 * ,-----------------------------------------------------------------------------------.
 * |      |      |      |      |      |      |      |      |      |      |      |      |
 * |------+------+------+------+------+-------------+------+------+------+------+------|
 * | Del  |      |      |      |      |      |      |      |      |      |      | Bksp |
 * |------+------+------+------+------+-------------+------+------+------+------+------|
 * |      |      |      |      |      |      |      |      |      |      |      | Del  |
 * |------+------+------+------+------+------|------+------+------+------+------+------|
 * |      |      |      |      |      |      |      |      |      |  ↑   |      |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |Keylck|      |      |      |      |             |      |  ←   |  ↓   |  →   |      |
 * `-----------------------------------------------------------------------------------'
 */
[_LOWER] = LAYOUT_preonic_grid( \
  _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,  \
  KC_DEL, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, KC_BSPC,  \
  _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,KC_DEL,  \
  _______, _______, _______, _______, _______, _______, _______, _______, _______, KC_UP, _______, _______,  \
  KC_LOCK, _______, _______, _______, _______, _______, _______, _______, KC_LEFT, KC_DOWN, KC_RGHT, _______ \
),

/* Raise
 * ,-----------------------------------------------------------------------------------.
 * |      |      |      |      |      |      |      |NumLck|   /  |   *  |   ,  |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * | Del  |      |      |      |      |      |      |   7  |   8  |   9  |   -  | Bksp |
 * |------+------+------+------+------+-------------+------+------+------+------+------|
 * |      |      |      |      |      |      |      |   4  |   5  |   6  |   +  | Del  |
 * |------+------+------+------+------+------|------+------+------+------+------+------|
 * |      |      |      |      |      |      |      |   1  |   2  |   3  |   =  |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |Keylck|VMacro|VMRply|      |      |             |      |   0  |   .  |Enter |      |
 * `-----------------------------------------------------------------------------------'
 */
[_RAISE] = LAYOUT_preonic_grid( \
  _______, _______, _______, _______, _______, _______, _______, KC_NLCK, KC_PSLS, KC_PAST, KC_PCMM, _______,  \
  KC_DEL, _______, _______, _______, _______, _______, _______, KC_P7, KC_P8, KC_P9, KC_PMNS, KC_BSPC,  \
  _______, _______, _______, _______, _______, _______, _______, KC_P4, KC_P5, KC_P6, KC_PPLS, KC_DEL,  \
  _______, _______, _______, _______, _______, _______, _______, KC_P1, KC_P2, KC_P3, KC_PEQL, _______,  \
  KC_LOCK, VIM_MACRO, VIM_MACRO_REPLAY, _______, _______, _______, _______, _______, KC_P0, KC_PDOT, KC_PENT, _______ \
),

/* Adjust
 * ,-----------------------------------------------------------------------------------.
 * |  F1  |  F2  |  F3  |  F4  |  F5  |  F6  |  F7  |  F8  |  F9  |  F10 |  F11 |  F12 |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |      |      |      |      |      |      |      |      |      |      |
 * |------+------+------+------+------+-------------+------+------+------+------+------|
 * |Sleep | Mute | Play |      |      |      |      |Qwerty|      |      |      |      |
 * |------+------+------+------+------+------|------+------+------+------+------+------|
 * |      | Vol- | Vol+ |      |      |      |      |      |      |      |      |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      | Brt- | Brt+ |      |      |             |      |      |      |      |      |
 * `-----------------------------------------------------------------------------------'
 */
[_ADJUST] = LAYOUT_preonic_grid( \
  KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,  KC_F12,  \
  _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,  \
  KC_SLEP, KC_MUTE, KC_MPLY,  _______, _______, _______, _______, QWERTY, _______, _______, _______, _______, \
  _______, KC_VOLD, KC_VOLU,  _______, _______, _______, _______, _______, _______, _______, _______, _______, \
  _______, KC_BRID, KC_BRIU, _______, _______, _______, _______, _______, _______, _______, _______, _______  \
)


};

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  switch (keycode) {
        case QWERTY:
          if (record->event.pressed) {
            set_single_persistent_default_layer(_QWERTY);
          }
          return false;
          break;
        case VIM_MACRO:
          if (record->event.pressed) {
            SEND_STRING(SS_TAP(X_Q)SS_TAP(X_Q));
          }
          break;
        case VIM_MACRO_REPLAY:
          if (record->event.pressed) {
            SEND_STRING(SS_LSFT("2")SS_TAP(X_Q));
          }
          break;
      }
    return true;
};
