#pragma once

#define MASTER_LEFT
// #define MASTER_RIGHT

#undef USE_I2C
#undef SSD1306OLED

#define USE_SERIAL_PD2

#define TAPPING_TERM 190
#define IGNORE_MOD_TAP_INTERRUPT

#define OLED_FONT_H "keyboards/crkbd/lib/glcdfont.c"

#ifdef RGB_MATRIX_ENABLE
    #   define  RGBLED_NUM 54
    #   define RGB_MATRIX_KEYPRESSES RGB_MATRIX_MULTISPLASH // reacts to keypresses
    // #   define RGB_MATRIX_KEYRELEASES RGB_MATRIX_SPLASH// reacts to keyreleases (instead of keypresses)
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