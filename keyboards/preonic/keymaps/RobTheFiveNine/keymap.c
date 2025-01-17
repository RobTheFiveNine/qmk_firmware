/* Copyright 2015-2021 Jack Humbert
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

enum preonic_layers {
  _QWERTY,
  _LOWER,
  _RAISE,
  _ADJUST,
  _FN
};

enum preonic_keycodes {
  QWERTY = SAFE_RANGE,
  LOWER,
  RAISE,
  PURPLE,
  GREEN,
  PINK
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

/* Qwerty
 * ,-----------------------------------------------------------------------------------.
 * |   `  |   1  |   2  |   3  |   4  |   5  |   6  |   7  |   8  |   9  |   0  |  -   |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * | Tab  |   Q  |   W  |   E  |   R  |   T  |   Y  |   U  |   I  |   O  |   P  | Bksp |
 * |------+------+------+------+------+-------------+------+------+------+------+------|
 * | Esc  |   A  |   S  |   D  |   F  |   G  |   H  |   J  |   K  |   L  |   ;  |  '   |
 * |------+------+------+------+------+------|------+------+------+------+------+------|
 * | Shift|   Z  |   X  |   C  |   V  |   B  |   N  |   M  |   ,  |   .  |   /  |Enter |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * | Ctrl | FN   | GUI  |  Alt |Lower |    Space    |Raise |  {   |   }  | Home | End  |
 * `-----------------------------------------------------------------------------------'
 */
[_QWERTY] = LAYOUT_preonic_grid(
  KC_GRV,   KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_6,    KC_7,    KC_8,     KC_9,    KC_0,     KC_MINUS,
  KC_TAB,   KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,    KC_Y,    KC_U,    KC_I,     KC_O,    KC_P,     KC_BSPC,
  KC_ESC,   KC_A,    KC_S,    KC_D,    KC_F,    KC_G,    KC_H,    KC_J,    KC_K,     KC_L,    KC_SCLN,  KC_QUOT,
  KC_LSFT,  KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    KC_N,    KC_M,    KC_COMM,  KC_DOT,  KC_SLSH,   KC_ENT,
  KC_LCTRL, MO(_FN), KC_LGUI, KC_LALT, LOWER,   KC_SPC,  KC_SPC,  RAISE,   KC_LCBR,  KC_RCBR, KC_HOME,   KC_END
),


/* Lower
 * ,-----------------------------------------------------------------------------------.
 * |   ~  |   !  |   @  |   #  | DK(4)|   %  |   ^  |   &  |   *  |   (  |   )  |  =   |
 * |------+------+------+------+------+-------------+------+------+------+------+------|
 * |   ~  |   !  |  Up  |   #  |   $  |   %  |   ^  |   &  |   *  |   {  |   }  | Del  |
 * |------+------+------+------+------+-------------+------+------+------+------+------|
 * | Del  |  Lft |  Dwn | Rght |  F4  |  F5  |  F6  |   _  |   +  |   [  |   ]  |  "   |
 * |------+------+------+------+------+------|------+------+------+------+------+------|
 * |      |  F7  |  F8  |  F9  |  F10 |  F11 |  F12 |ISO ~ |   <  |   >  |   \  |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |      |      |      |             |      |   [  |   ]  | Vol- | Vol+ |
 * `-----------------------------------------------------------------------------------'
 */
[_LOWER] = LAYOUT_preonic_grid(
  KC_TILD, KC_EXLM, KC_AT,   KC_HASH, RALT(LSFT(KC_4)),  KC_PERC, KC_CIRC, KC_AMPR, KC_ASTR, KC_LPRN, KC_RPRN, KC_EQL,
  KC_TILD, KC_EXLM, KC_UP,   KC_HASH,           KC_DLR,  KC_PERC, KC_CIRC, KC_AMPR, KC_ASTR, KC_LCBR, KC_RCBR, KC_DEL,
  KC_DEL,  KC_LEFT, KC_DOWN, KC_RGHT,            KC_F4,   KC_F5,   KC_F6,   KC_UNDS, KC_PLUS, KC_LBRC, KC_RBRC, S(KC_QUOT),
  _______, KC_F7,   KC_F8,   KC_F9,             KC_F10,  KC_F11,  KC_F12,S(KC_NUHS),S(KC_COMM),S(KC_DOT), KC_BSLASH, _______,
  _______, _______, _______, _______,          _______, _______, _______, _______, KC_LBRC,   KC_RBRC,  KC_VOLD, KC_VOLU
),

/* Raise
 * ,-----------------------------------------------------------------------------------.
 * |   `  |   1  |   2  |   3  |   4  |   5  |   6  |   7  |   8  |   9  |   0  | Bksp |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |   `  |   1  |   2  |   3  |   4  |   5  |   6  |   7  |   8  |   9  | ISO || Del  |
 * |------+------+------+------+------+-------------+------+------+------+------+------|
 * | Del  |  F1  |  F2  |  F3  |  F4  |  F5  |  F6  |   -  |   =  |   [  |   ]  |  \   |
 * |------+------+------+------+------+------|------+------+------+------+------+------|
 * |      |  F7  |  F8  |  F9  |  F10 |  F11 |  F12 |ISO # |ISO / | Pg Up| Pg Dn|      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |      |      |      |             |      | Next | Vol- | Vol+ | Play |
 * `-----------------------------------------------------------------------------------'
 */
[_RAISE] = LAYOUT_preonic_grid(
  KC_GRV,  KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_6,    KC_7,    KC_8,    KC_9,    KC_0,       KC_BSPC,
  KC_GRV,  KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_6,    KC_7,    KC_8,    KC_9,    S(KC_NUBS),  KC_DEL,
  KC_DEL,  KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,   KC_MINS, KC_EQL,  KC_LBRC, KC_RBRC,    KC_BSLS,
  _______, KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,  KC_F12,  KC_NUHS, KC_NUBS, KC_PGUP, KC_PGDN,    _______,
  _______, _______, _______, _______, _______, _______, _______, _______, KC_MNXT, KC_VOLD, KC_VOLU,    KC_MPLY
),

/* Adjust (Lower + Raise)
 * ,---------------------------------------------------------------------------------------.
 * |  F1  |  F2  |  F3  |  F4  |  F5  |  F6  |  F7  |  F8  |  F9  |  F10 |  F11  |  F12    |
 * |------+------+------+------+------+------+------+------+------+------+-------+---------|
 * |      | Reset| Debug|      |      |      |      |TermOf|TermOn|      |       |  Del    |
 * |------+------+------+------+------+-------------+------+------+------+-------+---------|
 * |      |      |Aud cy|Aud on|AudOff|AGnorm|AGswap|Qwerty|      |      |       |         |
 * |------+------+------+------+------+------|------+------+------+------+-------+---------|
 * |      |Voice-|Voice+|Mus on|MusOff|MidiOn|MidOff|      |      |      |       |         |
 * |------+------+------+------+------+------+------+------+------+------+-------+---------|
 * |Purple| Green| Pink |      |      | Toggle RGB  |      |      |      |RGB_HUD| RGB_HUI |
 * `---------------------------------------------------------------------------------------'
 */
[_ADJUST] = LAYOUT_preonic_grid(
  KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,   KC_F11,  KC_F12,
  _______, RESET,   DEBUG,   _______, _______, _______, _______, TERM_ON, TERM_OFF,_______, _______,  KC_DEL,
  _______, _______, MU_MOD,  AU_ON,   AU_OFF,  AG_NORM, AG_SWAP, QWERTY,  _______, _______, _______, _______,
  _______, MUV_DE,  MUV_IN,  MU_ON,   MU_OFF,  MI_ON,   MI_OFF,  _______, _______, _______, _______, _______,
   PURPLE,  GREEN, PINK, _______, _______, RGB_TOG, RGB_TOG, _______, _______, _______,  RGB_HUD, RGB_HUI
),

/* FN
 * ,--------------------------------------------------------------------------------------.
 * |      |      |      |      |      |      |      |      |  7   |  8   |  9   |    +    |
 * |------+------+------+------+------+------+------+------+------+------+------+---------|
 * |      |      |      |      |      |      |      |      |  4   |  5   |  6   |    -    |
 * |------+------+------+------+------+-------------+------+------+------+------+---------|
 * |      |      |      |      |      |      |      |      |  3   |  2   |  1   |    =    |
 * |------+------+------+------+------+------|------+------+------+------+------+---------|
 * |      |      |      |      |      |      |      |      |  0   |  .   |      |         |
 * |------+------+------+------+------+------+------+------+------+------+------+---------|
 * |      |      |      |      |      |             |      |      |      |      |         |
 * `--------------------------------------------------------------------------------------'
 */
[_FN] = LAYOUT_preonic_grid(
  _______, _______, _______, _______, _______, _______, _______, _______,    KC_7,    KC_8,    KC_9,  KC_PLUS,
  _______, _______, _______, _______, _______, _______, _______, _______,    KC_4,    KC_5,    KC_6, KC_MINUS,
  _______, _______, _______, _______, _______, _______, _______, _______,    KC_1,    KC_2,    KC_3,   KC_EQL,
  _______, _______, _______, _______, _______, _______, _______, _______,    KC_0,  KC_DOT, _______,  _______,
  _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,  _______
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
        case LOWER:
          if (record->event.pressed) {
            layer_on(_LOWER);
            update_tri_layer(_LOWER, _RAISE, _ADJUST);
          } else {
            layer_off(_LOWER);
            update_tri_layer(_LOWER, _RAISE, _ADJUST);
          }
          return false;
          break;
        case RAISE:
          if (record->event.pressed) {
            layer_on(_RAISE);
            update_tri_layer(_LOWER, _RAISE, _ADJUST);
          } else {
            layer_off(_RAISE);
            update_tri_layer(_LOWER, _RAISE, _ADJUST);
          }
          return false;
          break;
        case PURPLE:
          rgblight_sethsv_noeeprom(HSV_PURPLE);
          return false;
          break;

        case GREEN:
          rgblight_sethsv_noeeprom(HSV_GREEN);
          return false;
          break;

        case PINK:
          rgblight_sethsv_noeeprom(HSV_CUSTOM_PINK);
          return false;
          break;
      }
    return true;
};

#ifdef RGBLIGHT_ENABLE
void keyboard_post_init_user(void) {
  rgblight_enable_noeeprom(); // Enables RGB, without saving settings
  rgblight_sethsv_noeeprom(HSV_CUSTOM_PINK);
  rgblight_mode_noeeprom(RGBLIGHT_MODE_STATIC_LIGHT);
}
#endif