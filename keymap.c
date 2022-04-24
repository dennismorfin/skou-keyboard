#include QMK_KEYBOARD_H

#include "keycodes.h"

#if defined(RGBLIGHT_ENABLE) || defined(RGB_MATRIX_ENABLE)
#    include "rgb.c"
#endif

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
                                KC_LGUI, LT(_LOWER,KC_ENT),  DOFUS,     KC_SPC, LT(_RAISE,KC_ENT), TD(TD_ALT)
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