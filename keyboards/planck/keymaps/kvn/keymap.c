// This is the canonical layout file for the Quantum project. If you want to add another keyboard,
// this is the style you want to emulate.

#include "planck.h"
#ifdef BACKLIGHT_ENABLE
  #include "backlight.h"
#endif

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

static bool layer_tap_toggle = false;
// static bool reset_timer = true;
static uint16_t key_timer = 0;
static uint16_t current_time = 0;
static uint16_t tap_counter = 0;

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
[_QW] = { /* Qwerty */
  {F(0),	    KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,    KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_BSPC},
  {KC_TAB,	  KC_A,    KC_S,    KC_D,    KC_F,    KC_G,    KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, KC_QUOT},
  {KC_LSFT, 	KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH, KC_ENT },
  {KC_LCTL, 	KC_LGUI, KC_LALT, KC_DEL,  MO(_LW), KC_SPC,  KC_SPC,  M(1),    KC_LEFT, KC_DOWN, KC_UP,   KC_RGHT}
},
[_CM] = { /* Colemak */
  {F(0),  	KC_Q,    KC_W,    KC_F,    KC_P,    KC_G,    KC_J,    KC_L,    KC_U,    KC_Y,    KC_SCLN, KC_BSPC},
  {KC_TAB,  	KC_A,    KC_R,    KC_S,    KC_T,    KC_D,    KC_H,    KC_N,    KC_E,    KC_I,    KC_O,    KC_QUOT},
  {KC_LSFT, 	KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    KC_K,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH, KC_ENT },
  {KC_LCTL, 	KC_LGUI, KC_LALT, KC_DEL,  MO(_LW), KC_SPC,  KC_SPC,  MO(_RS), KC_LEFT, KC_DOWN, KC_UP,   KC_RGHT}
},
[_DV] = { /* Dvorak */
  {F(0),  	KC_QUOT, KC_COMM, KC_DOT,  KC_P,    KC_Y,    KC_F,    KC_G,    KC_C,    KC_R,    KC_L,    KC_BSPC},
  {KC_TAB,  	KC_A,    KC_O,    KC_E,    KC_U,    KC_I,    KC_D,    KC_H,    KC_T,    KC_N,    KC_S,    KC_SLSH},
  {KC_LSFT, 	KC_SCLN, KC_Q,    KC_J,    KC_K,    KC_X,    KC_B,    KC_M,    KC_W,    KC_V,    KC_Z,    KC_ENT },
  {KC_LCTL, 	KC_LGUI, KC_LALT, KC_DEL,  MO(_LW), KC_SPC,  KC_SPC,  MO(_RS), KC_LEFT, KC_DOWN, KC_UP,   KC_RGHT}
},
[_LW] = { /* LOWER */
  {KC_GRV,  KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_TRNS, KC_F11,  KC_F12,  KC_TRNS, M(0),    KC_BSPC},
  {KC_CAPS, KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_TRNS, KC_MINS, KC_EQL,  KC_LBRC, KC_RBRC, KC_BSLS},
  {KC_LSFT, KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_ENT},
  {KC_LCTL, KC_LGUI, KC_LALT, KC_INS,  KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, RESET}
},
[_RS] = { /* RAISE */
  {KC_NLCK, KC_P7,   KC_P8,   KC_P9,   KC_PSLS,  KC_TRNS, KC_PSCR, KC_SLCK, KC_PAUS, KC_TRNS, KC_TRNS, KC_BSPC},
  {KC_P0,   KC_P4,   KC_P5,   KC_P6,   KC_PAST,  KC_TRNS, KC_MUTE, KC_VOLD, KC_VOLU, KC_MPLY, KC_TRNS, KC_TRNS},
  {KC_PENT, KC_P1,   KC_P2,   KC_P3,   KC_PMNS,  KC_TRNS, KC_TRNS, DF(_QW), DF(_CM), DF(_DV), KC_TRNS, KC_LSFT},
  {KC_TRNS, KC_PEQL, KC_TRNS, KC_PDOT, KC_PPLS,  KC_TRNS, KC_TRNS, M(1),    KC_TRNS, KC_LALT, KC_LGUI, KC_LCTL}
},
[_RGB] = { /* RGBLIGHT */
  {KC_TRNS,  KC_PGUP,  KC_UP,    KC_PGDN,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_DEL},
  {KC_TRNS,  KC_LEFT,  KC_DOWN,  KC_RGHT,  KC_TRNS,  KC_HOME,  KC_LEFT,  KC_DOWN,  KC_UP,    KC_RGHT,  KC_END,   KC_TRNS},
  {KC_TRNS,  RGB_TOG,  RGB_MOD,  RGB_HUI,  RGB_HUD,  RGB_SAI,  RGB_SAD,  RGB_VAI,  RGB_VAD,  KC_TRNS,  KC_TRNS,  KC_TRNS},
  {KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_HOME,  KC_PGUP,  KC_PGDN,  KC_END}
}
};

/* enum function_id {
    
}; */

const uint16_t PROGMEM fn_actions[] = {
  [0]  = ACTION_LAYER_TAP_KEY(_RGB, KC_ESC),
  [1]  = ACTION_LAYER_TAP_TOGGLE(_RS)
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
        case 1:
          if (record->event.pressed) { 
            key_timer = timer_read();
            layer_tap_toggle = !layer_tap_toggle;
            layer_on(_RS);

            if ( (layer_tap_toggle && tap_counter == 0) || tap_counter == 1 ) {
              rgblight_toggle(); 
              // rgblight_setrgb_indicator_layer(0, 0, 0);
            } 
          } else { // keypress up
            layer_tap_toggle = !layer_tap_toggle;
            current_time = timer_elapsed(key_timer);
            timer_clear();

            if (current_time > 200) {
              tap_counter = 0;
              layer_tap_toggle = false;
              rgblight_toggle();
              layer_off(_RS);
            } else if (current_time <= 200) {
              ++tap_counter;

              if (tap_counter % 2 == 1) {
                layer_tap_toggle = !layer_tap_toggle; 
              }

              if (tap_counter == 1 || tap_counter == 4) {
                layer_off(_RS);
                rgblight_toggle();

                if (tap_counter == 4) {
                  tap_counter = 0;
                }
              }
            }
          }
        break;
      }
    return MACRO_NONE;
};

void action_function(keyrecord_t *record, uint8_t id, uint8_t opt) {
  switch (id) {
    
  }
}
