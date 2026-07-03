// Copyright 2023 QMK
// SPDX-License-Identifier: GPL-2.0-or-later

#include QMK_KEYBOARD_H

// --- Added: configure B1 as input with pull-up ---
void keyboard_pre_init_user(void) {
    setPinInputHigh(B1);   // B1 → switch → GND
}

static bool b1_last = false;

void matrix_scan_user(void) {
    bool b1 = !readPin(B1);   // active low: switch ON when grounded

    // If the switch changed position…
    if (b1 != b1_last) {
        if (b1) {
            // Switch moved to ON → force Caps Lock ON
            if (!host_keyboard_led_state().caps_lock) {
                tap_code(KC_CAPS);
            }
        } else {
            // Switch moved to OFF → force Caps Lock OFF
            if (host_keyboard_led_state().caps_lock) {
                tap_code(KC_CAPS);
            }
        }
    }

    b1_last = b1;
}



const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [0] = LAYOUT_m3501(
        // Row 0
        KC_ESC,  KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,  KC_F12,  KC_BSPC, KC_PRINT_SCREEN,  KC_SCROLL_LOCK,  KC_PAUSE, 
        // Row 1
        KC_GRV,  KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_MINS, KC_EQL,  KC_INS,  KC_HOME, KC_PGUP, KC_NUM_LOCK, KC_PEQL, KC_PSLS, KC_MUTE,
        // Row 2
        KC_TAB,  KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,    KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_LBRC, KC_RBRC, KC_DEL,  KC_END,  KC_PGDN, KC_P7,   KC_P8,   KC_P9,   KC_PAST,
        // Row 3
        KC_A,    KC_S,    KC_D,    KC_F,    KC_G,    KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, KC_QUOT, KC_ENT,  KC_BSLS, KC_P4,   KC_P5,   KC_P6,   KC_PMNS,
        // Row 4
        KC_LSFT, KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH, KC_RSFT, KC_UP,  KC_P1,   KC_P2,   KC_P3,   KC_PPLS,
        // Row 5
        KC_LCTL, KC_LALT, KC_LGUI, KC_SPC, KC_RGUI, KC_RALT, KC_RCTL, KC_LEFT, KC_DOWN, KC_RGHT, KC_P0, KC_PDOT, KC_PENT
    )
};
