#include QMK_KEYBOARD_H

#include "keycodes.h"

#if defined(RGBLIGHT_ENABLE) || defined(RGB_MATRIX_ENABLE)
#    include "rgb.c"
#endif

enum custom_keycodes {
   DOFUS = SAFE_RANGE,
};

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
   switch (keycode) {
      case DOFUS:
         if (record->event.pressed) {
            // when keycode DOFUS is pressed
            SEND_STRING( SS_DOWN(KC_LGUI) SS_TAP(KC_TAB) SS_TAP(KC_TAB) SS_TAP(KC_TAB) SS_TAP(KC_TAB) SS_TAP(KC_TAB) SS_TAP(KC_TAB) SS_TAP(KC_TAB) SS_TAP(KC_TAB) );
         } else {
            // when keycode DOFUS is released
            clear_keyboard();
         }
         break;
   }
   return true;
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [0] = {
        {QMKBEST, KC_ESC},
        // ...
    },
};

// clang-format off
const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  [_QWERTY] = LAYOUT_split_3x6_3(
  //|-----------------------------------------------------|                    |-----------------------------------------------------|
     KC_TAB,  KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,                         KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_BSPC,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
     LCTL_T(KC_ESC),KC_A, KC_S,  KC_D,    KC_F,    KC_G,                         KC_H,    KC_J,    KC_K,    KC_L,  TD(TD_PC), TD(TD_COMI),
  //---------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
     TD(TD_CAPLOCK), KC_Z,   KC_X,    KC_C,    KC_V,    KC_B,                 KC_N,    KC_M,      KC_COMM, KC_DOT,  TD(TD_SLA), RGB_MOD,
  //---------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                     KC_LGUI, LT(_LOWER,KC_ENT), LT(KC_LSFT,DOFUS),   KC_SPC, LT(_RAISE,KC_ENT), TD(TD_ALT)
                                      //|--------------------------|  |--------------------------|
  ),

  [_LOWER] = LAYOUT_split_3x6_3(
   //|-----------------------------------------------------|                    |-----------------------------------------------------|
     XXXXXXX,   KC_1,   KC_2,    KC_3,     KC_4,   KC_5,                         KC_6,     KC_7,   KC_8,   KC_9,    KC_0,    KC_BSPC,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
     XXXXXXX, KC_LCTL, KC_F5,  KC_LSFT, KC_VOLU,  KC_COPY,                       KC_PASTE,  KC_UP,  KC_MPRV, KC_MPLY, KC_MNXT, XXXXXXX,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
     XXXXXXX, XXXXXXX, XXXXXXX, TD(TD_ALT), KC_VOLD, XXXXXXX,                    KC_LEFT, KC_DOWN, KC_RIGHT, XXXXXXX, XXXXXXX, XXXXXXX,
  //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                                         KC_LGUI, XXXXXXX, KC_LSFT,    KC_SPC,  XXXXXXX, TD(TD_ALT)
                                      //|--------------------------|  |--------------------------|
  ),

  [_RAISE] = LAYOUT_split_3x6_3(
   //|-----------------------------------------------------|                    |-----------------------------------------------------|
     KC_ESC, TD(TD_LBRC), TD(TD_RBRC), TD(TD_BSLS), XXXXXXX, XXXXXXX,           TD(TD_MINS), TD(TD_EQL), TD(TD_GRV), XXXXXXX, XXXXXXX, XXXXXXX,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
     RGB_HUI, RGB_SAI, RGB_VAI, KC_LSFT, XXXXXXX, RGB_TOG,                      RGB_SPI, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, BL_TOGG,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
     RGB_HUD, RGB_SAD, RGB_VAD, XXXXXXX, XXXXXXX, RGB_MOD,                      RGB_SPD, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
  //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                                          KC_LGUI, LOWER, KC_LSFT,    KC_SPC, KC_TRNS, KC_RALT
                                      //|--------------------------|  |--------------------------|
  ),

};
// clang-format off

#if defined(RGBLIGHT_ENABLE) || defined(RGB_MATRIX_ENABLE)
layer_state_t layer_state_set_user(layer_state_t state) {
    /* For any layer other than default, save current RGB state and switch to layer-based RGB */
    if (layer_state_cmp(state, 0)) {
        restore_rgb_config();
    } else {
        uint8_t layer = get_highest_layer(state);
        if (layer_state_cmp(layer_state, 0)) save_rgb_config();
        rgb_by_layer(layer);
    }
    return state;
}
#endif

// #ifdef OLED_ENABLE
// oled_rotation_t oled_init_user(oled_rotation_t rotation) {
//   if (!is_keyboard_master()) {
//     return OLED_ROTATION_180;  // flips the display 180 degrees if offhand
//   }
//   return rotation;
// }

// #define L_BASE 0
// #define L_LOWER 2
// #define L_RAISE 4

// void oled_render_layer_state(void) {
//     oled_write_P(PSTR("Skou: "), false);
//     switch (layer_state) {
//         case L_BASE:
//             oled_write_ln_P(PSTR("QWERTY"), false);
//             break;
//         case L_LOWER:
//             oled_write_ln_P(PSTR("Numeros"), false);
//             break;
//         case L_RAISE:
//             oled_write_ln_P(PSTR("Simbolos/RGB"), false);
//             break;
//     }
// }


// char keylog_str[24] = {};

// const char code_to_name[60] = {
//     ' ', ' ', ' ', ' ', 'a', 'b', 'c', 'd', 'e', 'f',
//     'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n', 'o', 'p',
//     'q', 'r', 's', 't', 'u', 'v', 'w', 'x', 'y', 'z',
//     '1', '2', '3', '4', '5', '6', '7', '8', '9', '0',
//     'R', 'E', 'B', 'T', '_', '-', '=', '[', ']', '\\',
//     '#', ';', '\'', '`', ',', '.', '/', ' ', ' ', ' '};

// void set_keylog(uint16_t keycode, keyrecord_t *record) {
//   char name = ' ';
//     if ((keycode >= QK_MOD_TAP && keycode <= QK_MOD_TAP_MAX) ||
//         (keycode >= QK_LAYER_TAP && keycode <= QK_LAYER_TAP_MAX)) { keycode = keycode & 0xFF; }
//   if (keycode < 60) {
//     name = code_to_name[keycode];
//   }

//   // update keylog
//   snprintf(keylog_str, sizeof(keylog_str), "%dx%d, k%2d : %c",
//            record->event.key.row, record->event.key.col,
//            keycode, name);
// }

// void oled_render_keylog(void) {
//     oled_write(keylog_str, false);
// }

// void render_bootmagic_status(bool status) {
//     /* Show Ctrl-Gui Swap options */
//     static const char PROGMEM logo[][2][3] = {
//         {{0x97, 0x98, 0}, {0xb7, 0xb8, 0}},
//         {{0x95, 0x96, 0}, {0xb5, 0xb6, 0}},
//     };
//     if (status) {
//         oled_write_ln_P(logo[0][0], false);
//         oled_write_ln_P(logo[0][1], false);
//     } else {
//         oled_write_ln_P(logo[1][0], false);
//         oled_write_ln_P(logo[1][1], false);
//     }
// }

// void oled_render_logo(void) {
//     static const char PROGMEM crkbd_logo[] = {
//         0x80, 0x81, 0x82, 0x83, 0x84, 0x85, 0x86, 0x87, 0x88, 0x89, 0x8a, 0x8b, 0x8c, 0x8d, 0x8e, 0x8f, 0x90, 0x91, 0x92, 0x93, 0x94,
//         0xa0, 0xa1, 0xa2, 0xa3, 0xa4, 0xa5, 0xa6, 0xa7, 0xa8, 0xa9, 0xaa, 0xab, 0xac, 0xad, 0xae, 0xaf, 0xb0, 0xb1, 0xb2, 0xb3, 0xb4,
//         0xc0, 0xc1, 0xc2, 0xc3, 0xc4, 0xc5, 0xc6, 0xc7, 0xc8, 0xc9, 0xca, 0xcb, 0xcc, 0xcd, 0xce, 0xcf, 0xd0, 0xd1, 0xd2, 0xd3, 0xd4,
//         0};
//     oled_write_P(crkbd_logo, false);
// }

// bool oled_task_user(void) {
//     if (is_keyboard_master()) {
//         oled_render_layer_state();
//         oled_render_keylog();
//     } else {
//         oled_render_logo();
//     }
//     return false;
// }

// bool process_record_user(uint16_t keycode, keyrecord_t *record) {
//   if (record->event.pressed) {
//     set_keylog(keycode, record);
//   }
//   return true;
// }
// #endif // OLED_ENABLE