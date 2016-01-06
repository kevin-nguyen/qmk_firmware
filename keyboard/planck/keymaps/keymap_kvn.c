// This is the canonical layout file for the Quantum project. If you want to add another keyboard,
// this is the style you want to emulate.

#include "planck.h"
#include "backlight.h"

// Each layer gets a name for readability, which is then used in the keymap matrix below.
// The underscores don't mean anything - you can have a layer called STUFF or any other name.
// Layer names don't all need to be of the same length, obviously, and you can also skip them
// entirely and just use numbers.
#define _QW 0
#define _CM 1
#define _DV 2
#define _RS1 3
#define _RS2 4
#define _LW1 5
#define _LW2 6

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
[_QW] = { /* Qwerty */
  {KC_TAB,  KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,    KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_BSPC},
  {KC_ESC,  KC_A,    KC_S,    KC_D,    KC_F,    KC_G,    KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, KC_QUOT},
  {KC_LSFT, KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH, KC_ENT },
  {KC_LCTL, KC_LGUI, KC_LALT, TG(_LW1), MO(_RS1), KC_SPC, KC_SPC, MO(_RS2), TG(_LW2), KC_CAPS, M(0),  KC_DELT}
},
[_CM] = { /* Colemak */
  {KC_TAB,  KC_Q,    KC_W,    KC_F,    KC_P,    KC_G,    KC_J,    KC_L,    KC_U,    KC_Y,    KC_SCLN, KC_BSPC},
  {KC_ESC,  KC_A,    KC_R,    KC_S,    KC_T,    KC_D,    KC_H,    KC_N,    KC_E,    KC_I,    KC_O,    KC_QUOT},
  {KC_LSFT, KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    KC_K,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH, KC_ENT },
  {KC_LCTL, KC_LGUI, KC_LALT, TG(_LW1), MO(_RS1), KC_SPC, KC_SPC, MO(_RS2), TG(_LW2), KC_CAPS, M(0),  KC_DELT}
},
[_DV] = { /* Dvorak */
  {KC_TAB,  KC_QUOT, KC_COMM, KC_DOT,  KC_P,    KC_Y,    KC_F,    KC_G,    KC_C,    KC_R,    KC_L,    KC_BSPC},
  {KC_ESC,  KC_A,    KC_O,    KC_E,    KC_U,    KC_I,    KC_D,    KC_H,    KC_T,    KC_N,    KC_S,    KC_SLSH},
  {KC_LSFT, KC_SCLN, KC_Q,    KC_J,    KC_K,    KC_X,    KC_B,    KC_M,    KC_W,    KC_V,    KC_Z,    KC_ENT },
  {KC_LCTL, KC_LGUI, KC_LALT, TG(_LW1), MO(_RS1), KC_SPC, KC_SPC, MO(_RS2), TG(_LW2), KC_CAPS, M(0),  KC_DELT}
},
[_RS1] = { /* RAISE 1 */
  {KC_GRV,  KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_BSPC},
  {KC_TRNS, KC_F13,  KC_F14,  KC_F15,  KC_F16,  KC_F17,  KC_F18,  KC_MINS, KC_EQL,  KC_LBRC, KC_RBRC, KC_BSLS},
  {KC_LSFT, KC_F19,  KC_F20,  KC_F21,  KC_F22,  KC_F23,  KC_F24,  DF(_QW), DF(_CM), DF(_DV), RESET,   KC_TRNS},
  {KC_LCTL, KC_TRNS, KC_LALT, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS}
},
[_RS2] = { /* RAISE 2 */
  {KC_TILD, KC_EXLM, KC_AT,   KC_HASH, KC_DLR,  KC_PERC, KC_CIRC, KC_AMPR, KC_ASTR, KC_LPRN, KC_RPRN, KC_BSPC},
  {KC_TRNS, KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,   KC_UNDS, KC_PLUS, KC_LCBR, KC_RCBR, KC_PIPE},
  {KC_LSFT, KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,  KC_F12,  DF(_QW), DF(_CM), DF(_DV), RESET,   KC_TRNS},
  {KC_LCTL, KC_TRNS, KC_LALT, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_MNXT, KC_VOLD, KC_VOLU, KC_MPLY}
},
[_LW1] = { /* LOWER 1 */
  {KC_TRNS, F(0),    F(1),    F(2),    F(3),    F(4),    KC_TRNS, KC_TRNS, KC_7,    KC_8,    KC_9,    KC_BSPC},
  {KC_TRNS, KC_SLSH, KC_ASTR, KC_MINS, KC_PLUS, KC_EQL,  KC_TRNS, KC_TRNS, KC_4,    KC_5,    KC_6,    KC_0},
  {KC_TRNS, F(5),    F(6),    F(7),    F(8),    F(9),    KC_TRNS, KC_TRNS, KC_1,    KC_2,    KC_3,    KC_ENT},
  {KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_SPC,  KC_SPC,  KC_SLSH, KC_ASTR, KC_MINS, KC_PLUS, KC_EQL}
},
[_LW2] = { /* LOWER 2 */
  {DF(_QW), F(10),  F(11),   F(12),   F(13),   F(14),   KC_MUTE, KC_VOLD, KC_VOLU, KC_MPRV, KC_MNXT, KC_MPLY},
  {DF(_CM), F(15),  F(16),   F(17),   F(18),   F(19),   KC_LEFT, KC_DOWN, KC_UP,   KC_RIGHT, KC_HOME, KC_PGUP},   
  {DF(_DV),  F(20),  F(21),   F(22),   F(23),   F(24),   KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,  KC_END,  KC_PGDOWN},
  {KC_LCTL, KC_LSFT, KC_LALT, KC_TRNS, KC_TRNS, RESET,   RESET,   KC_TRNS, KC_TRNS, KC_TRNS, KC_INS,  KC_PSCR}
}
};

const uint16_t PROGMEM fn_actions[] = {

};

const macro_t *action_get_macro(keyrecord_t *record, uint8_t id, uint8_t opt)
{
  // MACRODOWN only works in this function
      switch(id) {
        case 0:
          if (record->event.pressed) {
            register_code(KC_RSFT);
            backlight_step();
          } else {
            unregister_code(KC_RSFT);
          }
        break;
      }
    return MACRO_NONE;
};
