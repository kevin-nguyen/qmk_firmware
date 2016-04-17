#include "atomic.h"
#include "action_layer.h"

#ifdef AUDIO_ENABLE
#include "audio.h"
#include "song_list.h"
#endif


#define _QW 0
#define _LW 1
#define _RS 2
#define _AD 3
#define _FN 4

#define M_QW 0
#define M_LW 1
#define M_RS 2
#define M_FN 3
#define M_T1 4
#define M_T2 5
#define M_T3 6
#define M_T4 7
#define M_TU 8
#define M_TD 9
#define M_DF 10


#define _______ KC_TRNS
#define ___T___ KC_TRNS
#define XXXXXXX KC_NO

/*
 * .---------------------------------------------------------------------------------------------------------------------- 2u ------------.
 * | ESC    | 1      | 2      | 3      | 4      | 5      | 6      | 7      | 8      | 9      | 0      | -      | =      | XXXXXX . BACKSP |
 * |--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+-----------------|
 * | TAB    | Q      | W      | E      | R      | T      | Y      | U      | I      | O      | P      | [      | ]      | \      | DEL    |
 * |--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+- 2u ------------+--------|
 * | CAPS   | A      | S      | D      | F      | G      | H      | J      | K      | L      | ;      | '      | XXXXXX . ENTER  | PG UP  |
 * |--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+- 2u ---------------------+--------|
 * | LSHIFT | Z      | X      | C      | V      | B      | N      | M      | ,      | .      | /      | XXXXXX . RSHIFT | UP     | PG DN  |
 * |--------+--------+--------+--------+--------+- 2u ------------+--------+--------+--------+--------+-----------------+--------+--------|
 * | LCTRL  | LWIN   | FN     | LALT   | RAISED | XXXXXX . SPACE  | LOWER  | RALT   | HOME   | END    | RCTRL  | LEFT   | DOWN   | RIGHT  |
 * '--------------------------------------------------------------------------------------------------------------------------------------'
 */

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
 [_QW] = { /* QWERTY */
  { KC_ESC,  KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_MINS, KC_EQL,  KC_BSPC, XXXXXXX  },
  { KC_TAB,  KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,    KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_LBRC, KC_RBRC, KC_BSLS, KC_DEL   },
  { KC_CAPS, KC_A,    KC_S,    KC_D,    KC_F,    KC_G,    KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, KC_QUOT, KC_ENT,  XXXXXXX, KC_PGUP  },
  { KC_LSFT, KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH, KC_RSFT, XXXXXXX, KC_UP,   KC_PGDN  },
  { KC_LCTL, KC_LGUI, M(M_FN), KC_LALT, M(M_RS), KC_SPC,  XXXXXXX, M(M_LW), KC_RALT, KC_HOME, KC_END,  KC_RCTL, KC_LEFT, KC_DOWN, KC_RGHT  },
 },
 [_LW] = { /* LOWERED */
  { KC_GRV,  KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,  KC_F12,  ___T___, ___T___  },
  { _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, KC_INS   },
  { _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, ___T___, ___T___, _______  },
  { _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, ___T___, ___T___, _______, _______  },
  { _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______  },
 },
 [_RS] = { /* RAISED */
  { KC_TILD, KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,  KC_F12,  ___T___, ___T___  },
  { _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, KC_INS   },
  { _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, ___T___, ___T___, _______  },
  { _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, ___T___, ___T___, _______, _______  },
  { _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______  },
 },
 [_FN] = { /* FUNCTION */
  { KC_NLCK, KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,  KC_F12,  ___T___, ___T___  },
  { KC_SLCK, KC_F13,  KC_F14,  KC_F15,  KC_F16,  KC_F17,  KC_F18,  KC_F19,  KC_F20,  KC_F21,  KC_F22,  KC_F23,  KC_F24,  KC_PAUS, KC_PSCR  },
  { KC_CAPS, KC_BTN5, KC_BTN4, KC_BTN3, KC_BTN2, KC_ACL0, KC_ACL2, KC_MNXT, KC_VOLD, KC_VOLU, KC_MPLY, _______, ___T___, ___T___, KC_WH_U  },
  { _______, M(M_T1), M(M_T2), M(M_T3), M(M_T4), M(M_TU), M(M_TD), M(M_DF), _______, _______, _______, ___T___, ___T___, KC_MS_U, KC_WH_D  },
  { _______, _______, _______, _______, _______, KC_BTN1, KC_BTN1, _______, _______, _______, _______, _______, KC_MS_L, KC_MS_D, KC_MS_R  },
 },
 [_AD] = { /* ADJUST */
  { _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, ___T___, ___T___  },
  { _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______  },
  { _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, ___T___, ___T___, _______  },
  { _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, ___T___, ___T___, _______, _______  },
  { _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______  },
 },
};



#ifdef AUDIO_ENABLE

float start_up[][2] = SONG(ODE_TO_JOY);

float tone_lw[][2] = {

	Q__NOTE(_C4   ) ,
	Q__NOTE(_CS4  ) ,
	Q__NOTE(_D4   ) ,
	Q__NOTE(_DS4  ) ,
	Q__NOTE(_E4   ) ,
	Q__NOTE(_F4   ) ,
	Q__NOTE(_FS4  ) ,
	Q__NOTE(_G4   ) ,
	Q__NOTE(_GS4  ) ,
	Q__NOTE(_A4   ) ,
	Q__NOTE(_AS4  ) ,

	Q__NOTE(_B1   ) ,

	Q__NOTE(_C2   ) ,
	Q__NOTE(_CS2  ) ,
	Q__NOTE(_D2   ) ,
	Q__NOTE(_DS2  ) ,
	Q__NOTE(_E2   ) ,
	Q__NOTE(_F2   ) ,
	Q__NOTE(_FS2  ) ,
	Q__NOTE(_G2   ) ,
	Q__NOTE(_GS2  ) ,
	Q__NOTE(_A2   ) ,
	Q__NOTE(_AS2  ) ,
	Q__NOTE(_B2   ) ,
	Q__NOTE(_C3   ) ,
	Q__NOTE(_CS3  ) ,
	Q__NOTE(_D3   ) ,
	Q__NOTE(_DS3  ) ,
	Q__NOTE(_E3   ) ,
	Q__NOTE(_F3   ) ,
	Q__NOTE(_FS3  ) ,
	Q__NOTE(_G3   ) ,
	Q__NOTE(_GS3  ) ,
	Q__NOTE(_A3   ) ,
	Q__NOTE(_AS3  ) ,
	Q__NOTE(_B3   ) ,
	Q__NOTE(_C4   ) ,
	Q__NOTE(_CS4  ) ,
	Q__NOTE(_D4   ) ,
	Q__NOTE(_DS4  ) ,
	Q__NOTE(_E4   ) ,
	Q__NOTE(_F4   ) ,
	Q__NOTE(_FS4  ) ,
	Q__NOTE(_G4   ) ,
	Q__NOTE(_GS4  ) ,
	Q__NOTE(_A4   ) ,
	Q__NOTE(_AS4  ) ,
	Q__NOTE(_B4   ) ,
	Q__NOTE(_C5   ) ,
	Q__NOTE(_CS5  ) ,
	Q__NOTE(_D5   ) ,
	Q__NOTE(_DS5  ) ,
	Q__NOTE(_E5   ) ,
	Q__NOTE(_F5   ) ,
	Q__NOTE(_FS5  ) ,
	Q__NOTE(_G5   ) ,
	Q__NOTE(_GS5  ) ,
	Q__NOTE(_A5   ) ,
	Q__NOTE(_AS5  ) ,
	Q__NOTE(_B5   ) ,
	Q__NOTE(_C6   ) ,
	Q__NOTE(_CS6  ) ,
	Q__NOTE(_D6   ) ,
	Q__NOTE(_DS6  ) ,
	Q__NOTE(_E6   ) ,
	Q__NOTE(_F6   ) ,
	Q__NOTE(_FS6  ) ,
	Q__NOTE(_G6   ) ,
	Q__NOTE(_GS6  ) ,
	Q__NOTE(_A6   ) ,
	Q__NOTE(_AS6  ) ,
	Q__NOTE(_B6   ) ,
	Q__NOTE(_C7   ) ,
	Q__NOTE(_CS7  ) ,
	Q__NOTE(_D7   ) ,
	Q__NOTE(_DS7  ) ,
	Q__NOTE(_E7   ) ,
	Q__NOTE(_F7   ) ,
	Q__NOTE(_FS7  ) ,
	Q__NOTE(_G7   ) ,
	Q__NOTE(_GS7  ) ,
	Q__NOTE(_A7   ) ,
	Q__NOTE(_AS7  ) ,
	Q__NOTE(_B7   ) ,
	Q__NOTE(_C8   ) ,
	Q__NOTE(_CS8  ) ,
	Q__NOTE(_D8   ) ,
	Q__NOTE(_DS8  ) ,
	Q__NOTE(_E8   ) ,
	Q__NOTE(_F8   ) ,
	Q__NOTE(_FS8  ) ,
	Q__NOTE(_G8   ) ,
	Q__NOTE(_GS8  ) ,
	Q__NOTE(_A8   ) ,
	Q__NOTE(_AS8  ) ,
	Q__NOTE(_B8   ) ,
};

float tone_rs[][2] = SONG(ROCK_A_BYE_BABY);

void matrix_init_user(void) {
	init_notes();
	PLAY_NOTE_ARRAY(start_up, false, STACCATO);
	println("Matrix Init");
}

#endif


void update_quad_layer(uint8_t layer1, uint8_t layer2, uint8_t layer3, uint8_t layer4, bool order)
{
	if (order)
	{
		if (IS_LAYER_ON(layer1) && IS_LAYER_ON(layer2))
		{
			layer_on(layer3);
		}
		else
		{
		    layer_off(layer3);
		    layer_off(layer4);
		}
	}
	else
	{
		if (IS_LAYER_ON(layer1) && IS_LAYER_ON(layer2))
		{
			layer_on(layer4);
		}
		else
		{
			layer_off(layer3);
		    layer_off(layer4);
		}
	}
}


const uint16_t PROGMEM fn_actions[] = {
};


const macro_t *action_get_macro(keyrecord_t *record, uint8_t id, uint8_t opt)
{

	// MACRODOWN only works in this function
	switch(id)
	{
		case M_LW:
			if (record->event.pressed) {
				#ifdef AUDIO_ENABLE
				PLAY_NOTE_ARRAY(tone_lw, false, STACCATO);
				#endif
				layer_on(_LW);
				update_tri_layer(_LW, _RS, _AD);
			} else {
				layer_off(_LW);
				update_tri_layer(_LW, _RS, _AD);
			}
			break;
		case M_RS:
			if (record->event.pressed) {
				#ifdef AUDIO_ENABLE
				PLAY_NOTE_ARRAY(tone_rs, false, LEGATO);
				#endif
				layer_on(_RS);
				update_tri_layer(_LW, _RS, _AD);
			} else {
				layer_off(_RS);
				update_tri_layer(_LW, _RS, _AD);
			}
			break;

		case M_FN:
			if (record->event.pressed) {
				layer_on(_FN);
			} else {
				layer_off(_FN);
			}
			break;

		case M_T1:
			if (record->event.pressed) set_timbre(TIMBRE_12);
			break;

		case M_T2:
			if (record->event.pressed) set_timbre(TIMBRE_25);
			break;

		case M_T3:
			if (record->event.pressed) set_timbre(TIMBRE_50);
			break;

		case M_T4:
			if (record->event.pressed) set_timbre(TIMBRE_75);
			break;


		case M_TU:
			if (record->event.pressed) increase_tempo(10);
			break;

		case M_TD:
			if (record->event.pressed) decrease_tempo(10);
			break;

		case M_DF:
			if (record->event.pressed)
			{
				set_timbre(TIMBRE_DEFAULT);
				set_tempo(TEMPO_DEFAULT);
			}
			break;

		default:
			break;

	}
	return MACRO_NONE;
};