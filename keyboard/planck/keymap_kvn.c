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
#define _LW 3
#define _RS 4
#define _RGB 5

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
[_QW] = { /* Qwerty */
  {KC_ESC,  KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,    KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_BSPC},
  {KC_TAB,  KC_A,    KC_S,    KC_D,    KC_F,    KC_G,    KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, KC_QUOT},
  {SFT_T(KC_PGUP), KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH, KC_ENT },
  {CTL_T(KC_PGDN), KC_LGUI, ALT_T(KC_HOME), KC_DEL,  F(10), F(0),    F(0),  F(9), KC_LEFT, KC_DOWN, KC_UP,   KC_RGHT}
},
[_CM] = { /* Colemak */
  {KC_ESC,  KC_Q,    KC_W,    KC_F,    KC_P,    KC_G,    KC_J,    KC_L,    KC_U,    KC_Y,    KC_SCLN, KC_BSPC},
  {KC_TAB,  KC_A,    KC_R,    KC_S,    KC_T,    KC_D,    KC_H,    KC_N,    KC_E,    KC_I,    KC_O,    KC_QUOT},
  {SFT_T(KC_PGUP), KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    KC_K,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH, KC_ENT },
  {CTL_T(KC_PGDN), KC_LGUI, ALT_T(KC_HOME), KC_DEL,  F(10), F(0),    F(0),  MO(_RS), KC_LEFT, KC_DOWN, KC_UP,   KC_RGHT}
},
[_DV] = { /* Dvorak */
  {KC_ESC,  KC_QUOT, KC_COMM, KC_DOT,  KC_P,    KC_Y,    KC_F,    KC_G,    KC_C,    KC_R,    KC_L,    KC_BSPC},
  {KC_TAB,  KC_A,    KC_O,    KC_E,    KC_U,    KC_I,    KC_D,    KC_H,    KC_T,    KC_N,    KC_S,    KC_SLSH},
  {SFT_T(KC_PGUP), KC_SCLN, KC_Q,    KC_J,    KC_K,    KC_X,    KC_B,    KC_M,    KC_W,    KC_V,    KC_Z,    KC_ENT },
  {CTL_T(KC_PGDN), KC_LGUI, ALT_T(KC_HOME), KC_DEL,  F(10), F(0),    F(0),  MO(_RS), KC_LEFT, KC_DOWN, KC_UP,   KC_RGHT}
},
[_LW] = { /* LOWER */
  {KC_GRV,  KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_BSPC},
  {KC_CAPS, M(0),    KC_TRNS, KC_TRNS, KC_TRNS, KC_F11,  KC_F12,  KC_MINS, KC_EQL,  KC_LBRC, KC_RBRC, KC_BSLS},
  {KC_LSFT, KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_TRNS},
  {KC_LCTL, KC_LGUI, KC_LALT, KC_INS,  KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, RESET}
},
[_RS] = { /* RAISE */
  {KC_NLCK, KC_P7,   KC_P8,   KC_P9,   KC_PSLS,  KC_TRNS, KC_PSCR, KC_SLCK, KC_PAUS, KC_TRNS, KC_TRNS, KC_BSPC},
  {KC_P0,   KC_P4,   KC_P5,   KC_P6,   KC_PAST,  KC_TRNS, KC_MUTE, KC_VOLD, KC_VOLU, KC_MPLY, KC_TRNS, KC_TRNS},
  {KC_PENT, KC_P1,   KC_P2,   KC_P3,   KC_PMNS,  KC_TRNS, KC_TRNS, DF(_QW), DF(_CM), DF(_DV), KC_TRNS,   KC_LSFT},
  {KC_TRNS, KC_PEQL, KC_TRNS, KC_PDOT, KC_PPLS,  KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_LALT, KC_LGUI, KC_LCTL}
},
[_RGB] = { /* RGBLIGHT */
  {KC_TRNS,  KC_PGUP,  KC_UP,    KC_PGDN,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_DEL},
  {KC_TRNS,  KC_LEFT,  KC_DOWN,  KC_RGHT,  KC_TRNS,  KC_HOME,  KC_LEFT,  KC_DOWN,  KC_UP,    KC_RGHT,  KC_END,   KC_TRNS},
  {KC_TRNS,  F(1),     F(2),     F(3),     F(4),     F(5),     F(6),     F(7),     F(8),     KC_TRNS,  KC_TRNS,  KC_TRNS},
  {KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS}
}
};

enum function_id {
    RGBLED_TOGGLE,
    RGBLED_STEP_MODE,
    RGBLED_INCREASE_HUE,
    RGBLED_DECREASE_HUE,
    RGBLED_INCREASE_SAT,
    RGBLED_DECREASE_SAT,
    RGBLED_INCREASE_VAL,
    RGBLED_DECREASE_VAL,
};

const uint16_t PROGMEM fn_actions[] = {
  [0]  = ACTION_LAYER_TAP_KEY(_RGB, KC_SPC),
  [1]  = ACTION_FUNCTION(RGBLED_TOGGLE),
  [2]  = ACTION_FUNCTION(RGBLED_STEP_MODE),
  [3]  = ACTION_FUNCTION(RGBLED_INCREASE_HUE),
  [4]  = ACTION_FUNCTION(RGBLED_DECREASE_HUE),
  [5]  = ACTION_FUNCTION(RGBLED_INCREASE_SAT),
  [6]  = ACTION_FUNCTION(RGBLED_DECREASE_SAT),
  [7]  = ACTION_FUNCTION(RGBLED_INCREASE_VAL),
  [8]  = ACTION_FUNCTION(RGBLED_DECREASE_VAL),
  [9]  = ACTION_LAYER_TAP_TOGGLE(_RS),
  [10] = ACTION_LAYER_TAP_KEY(_LW, KC_END)
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

void action_function(keyrecord_t *record, uint8_t id, uint8_t opt) {
  switch (id) {
    case RGBLED_TOGGLE:
      //led operations
      if (record->event.pressed) {
        rgblight_toggle();
      }

      break;
    case RGBLED_INCREASE_HUE:
      if (record->event.pressed) {
        rgblight_increase_hue();
      }
      break;
    case RGBLED_DECREASE_HUE:
      if (record->event.pressed) {
        rgblight_decrease_hue();
      }
      break;
    case RGBLED_INCREASE_SAT:
      if (record->event.pressed) {
        rgblight_increase_sat();
      }
      break;
    case RGBLED_DECREASE_SAT:
      if (record->event.pressed) {
        rgblight_decrease_sat();
      }
      break;
    case RGBLED_INCREASE_VAL:
      if (record->event.pressed) {
        rgblight_increase_val();
      }
      break;
    case RGBLED_DECREASE_VAL:
      if (record->event.pressed) {
        rgblight_decrease_val();
      }
      break;
    case RGBLED_STEP_MODE:
      if (record->event.pressed) {
        rgblight_step();
      }
      break;
  }
}
