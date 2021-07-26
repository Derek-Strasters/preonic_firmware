#pragma once

#define MOUSEKEY_DELAY 50
#define MOUSEKEY_INTERVAL 16
#define MOUSEKEY_MOVE_DELTA 3
#define MOUSEKEY_MAX_SPEED 5

#ifdef AUDIO_ENABLE
    #define STARTUP_SONG SONG(PREONIC_SOUND)
    // #define STARTUP_SONG SONG(NO_SOUND)

    #define DEFAULT_LAYER_SONGS { SONG(QWERTY_SOUND), \
                                  SONG(COLEMAK_SOUND), \
                                  SONG(DVORAK_SOUND) \
                                }
#endif

#define NO_ACTION_ONESHOT
#define NO_ACTION_MACRO
#define NO_ACTION_FUNCTION

#ifdef REV3_CONFIG_H
    #define MUSIC_MASK (keycode != KC_NO)

    #ifndef NO_DEBUG
        #define NO_DEBUG
    #endif
    #ifndef NO_PRINT
        #define NO_PRINT
    #endif

    #define RGBLIGHT_DISABLE_KEYCODES
    #define RGBLIGHT_SLEEP

    #define RGBLIGHT_DEFAULT_HUE 0
    #define RGBLIGHT_DEFAULT_SAT 0
    #define RGBLIGHT_DEFAULT_VAL 0
#endif
