// config.h esta en lenguaje C

// kb: crkbd
// km: skou

#pragma once

#define EE_HANDS
#define SPLIT_USB_DETECT

#undef USE_I2C
#undef SSD1306OLED

#define USE_SERIAL_PD2

#define IGNORE_MOD_TAP_INTERRUPT
#define PERMISSIVE_HOLD
#define TAPPING_TERM 190

#define NO_ACTION_ONESHOT

#ifdef AUDIO_ENABLE
#    define AUDIO_PIN B5
#    define NO_MUSIC_MODE
#    define AUDIO_CLICKY
#endif

#define OLED_FONT_H "keyboards/crkbd/lib/glcdfont.c"

#define RGBLIGHT_SLEEP

#ifdef RGBLIGHT_ENABLE
#    undef RGBLED_NUM
#    define RGBLED_NUM 6
#    define RGBLIGHT_LIMIT_VAL 150
#    define RGBLIGHT_HUE_STEP 16
#    define RGBLIGHT_SAT_STEP 32
#    define RGBLIGHT_VAL_STEP 32
#endif

#ifdef RGB_MATRIX_ENABLE
    #   define RGBLED_NUM 54
    #   define RGB_MATRIX_KEYPRESSES RGB_MATRIX_MULTISPLASH // reacts to keypresses
    #   define RGB_DISABLE_AFTER_TIMEOUT 0 // number of ticks to wait until disabling effects
    #   define RGB_DISABLE_WHEN_USB_SUSPENDED true // turn off effects when suspended
    #   define RGB_MATRIX_LED_PROCESS_LIMIT (DRIVER_LED_TOTAL + 4) / 5 // limits the number of LEDs to process in an animation per task run (increases keyboard responsiveness)
    #   define RGB_MATRIX_LED_FLUSH_LIMIT 16 // limits in milliseconds how frequently an animation will update the LEDs. 16 (16ms) is equivalent to limiting to 60fps (increases keyboard responsiveness)
    #   define RGB_MATRIX_MAXIMUM_BRIGHTNESS 150 // limits maximum brightness of LEDs to 150 out of 255. Higher may cause the controller to crash.
    #   define RGB_MATRIX_HUE_STEP 8
    #   define RGB_MATRIX_SAT_STEP 8
    #   define RGB_MATRIX_VAL_STEP 8
    #   define RGB_MATRIX_SPD_STEP 10
    #   define RGB_MATRIX_SPLIT { 27, 27 }
    #   define RGB_MATRIX_STARTUP_MODE RGB_MATRIX_CYCLE_LEFT_RIGHT

    #   define ENABLE_RGB_MATRIX_CYCLE_LEFT_RIGHT
    #   define ENABLE_RGB_MATRIX_CYCLE_ALL
    #   define ENABLE_RGB_MATRIX_CYCLE_UP_DOWN
    #   define ENABLE_RGB_MATRIX_CYCLE_SPIRAL
    #   define ENABLE_RGB_MATRIX_DUAL_BEACON

    #   define ENABLE_RGB_MATRIX_MULTISPLASH

#endif

#define NO_ACTION_MACRO     // ya que tengo EXTRAFLAGS += -flto en rules.mk

#define NO_ACTION_FUNCTION  // ya que tengo EXTRAFLAGS += -flto en rules.mk