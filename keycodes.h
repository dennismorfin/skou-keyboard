#pragma once

enum layers {
    _QWERTY,
    _LOWER,
    _RAISE,
};

enum {
    TD_PC,
    TD_COMI,
    TD_SLA,
    TD_CAPLOCK,
    TD_ALT,
    TD_LBRC,
    TD_RBRC,
    TD_BSLS,
    TD_MINS,
    TD_EQL,
    TD_GRV
};

enum custom_keycodes {
    QWERTY = SAFE_RANGE,
    LOWER,
    RAISE,
    RGBRST,
    DOFUS
};

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
   switch (keycode) {
      case DOFUS:
         if (record->event.pressed) {
            // when keycode DOFUS is pressed
            SEND_STRING(SS_DOWN(X_LGUI) SS_TAP(X_TAB) SS_TAP(X_TAB) SS_TAP(X_TAB) SS_TAP(X_TAB) SS_TAP(X_TAB) SS_TAP(X_TAB) SS_TAP(X_TAB) SS_TAP(X_TAB));
         } else {
            // when keycode DOFUS is released
            clear_keyboard();
         }
         break;
   }
   return true;
};

#define SFT_EQ MT(MOD_LSFT, KC_EQL)
#define SFT_QT MT(MOD_RSFT, KC_QUOT)

#define SFT_A MT(MOD_LSFT, KC_A)
#define CTL_Z MT(MOD_LCTL, KC_Z)

#define SFT_SCLN MT(MOD_RSFT, KC_SCLN)
#define CTL_SLSH MT(MOD_RCTL, KC_SLSH)

#define LOW_SPC LT(_LOWER, KC_SPC)
#define RAI_EQ LT(_RAISE, KC_EQL)
#define RAI_ENT LT(_RAISE, KC_ENT)
#define LOW_BSP LT(_LOWER, KC_BSPC)
#define LOW_DEL LT(_LOWER, KC_DEL)
#define ADJ_GRV LT(_ADJUST, KC_GRV)
#define KC_ANGL LSFT(KC_COMM)
#define KC_ANGR LSFT(KC_DOT)

// Tap Dance definitions
qk_tap_dance_action_t tap_dance_actions[] = {
    [TD_PC] = ACTION_TAP_DANCE_DOUBLE(KC_SCLN, LSFT(KC_SCLN)),
    [TD_COMI] = ACTION_TAP_DANCE_DOUBLE(KC_QUOT, LSFT(KC_QUOT)),
    [TD_SLA] = ACTION_TAP_DANCE_DOUBLE(KC_SLSH, LSFT(KC_SLSH)),
    [TD_CAPLOCK] = ACTION_TAP_DANCE_DOUBLE(KC_LSFT, KC_CAPS),
    [TD_ALT] = ACTION_TAP_DANCE_DOUBLE(KC_RALT, KC_LALT),
    [TD_LBRC] = ACTION_TAP_DANCE_DOUBLE(KC_LBRC, LSFT(KC_LBRC)),
    [TD_RBRC] = ACTION_TAP_DANCE_DOUBLE(KC_RBRC, LSFT(KC_RBRC)),
    [TD_BSLS] = ACTION_TAP_DANCE_DOUBLE(KC_BSLS, LSFT(KC_BSLS)),
    [TD_MINS] = ACTION_TAP_DANCE_DOUBLE(KC_MINS, LSFT(KC_MINS)),
    [TD_EQL] = ACTION_TAP_DANCE_DOUBLE(KC_EQL, LSFT(KC_EQL)),
    [TD_GRV] = ACTION_TAP_DANCE_DOUBLE(KC_GRV, LSFT(KC_GRV))
};