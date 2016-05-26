#ifndef KEVTRINO_H
#define KEVTRINO_H

#include "matrix.h"
#include "keymap_common.h"
#ifdef BACKLIGHT_ENABLE
	#include "backlight.h"
#endif
#include <avr/io.h>
#include <stddef.h>

// This a shortcut to help you visually see your layout.
// The following is an example using the Planck MIT layout
// The first section contains all of the arguements
// The second converts the arguments into a two-dimensional array
#define KEYMAP( \
    k00, k01, k02, k03, k04, k05, k06, k07, k08, k09, k0A, k0B, k0C, k0D,   k0E, \
      k10, k11, k12, k13, k14, k15, k16, k17, k18, k19, k1A, k1B, k1C, k1D, k1E, \
        k20, k21, k22, k23, k24, k25, k26, k27, k28, k29, k2A, k2B,  k2C,   k2E, \
         K30,  K32, K33, K34, K35, K36, K37, K38, K39, K3A, K3B, K3C,  K3D, K3E, \
    K40,  K41,  K42,           K45,                K49 ,K4A, K4B, K4C, K4D, K4E  \
) \
{ \
    { k00, k01, k02, k03, k04, k05, k06, k07, k08, k09, k0A, k0B, k0C, k0D, k0E }, \
    { k10, k11, k12, k13, k14, k15, k16, k17, k18, k19, k1A, k1B, k1C, k1D, k1E }, \
    { k20, k21, k22, k23, k24, k25, k26, k27, k28, k29, k2A, k2B, k2C, k2C, k2E }, \
    { K30, K31, K32, K33, K34, K35, K36, K37, K38, K39, K3A, K3B, K3B, K3D, K3E }, \
    { K40, K41, K42, K45, K45, K45, K45, K45, K45, K49, K4A, K4B, K4C, K4D, K4E }, \
}

void matrix_init_user(void);
void matrix_scan_user(void);
bool process_action_user(keyrecord_t *record);
void led_set_user(uint8_t usb_led);

#endif
