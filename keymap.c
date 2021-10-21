#include QMK_KEYBOARD_H
#include "muse.h"


// Key Map

enum preonic_layers {
    _QWERTY,
    _GAME,
    _SYMBOL,
    _NUMBERS,
    _MOVE,
    _ADJUST,
    _DYN
};

enum preonic_keycodes {
    QUADER = SAFE_RANGE
};

#define LCTRLSH (QK_LCTL | KC_LSFT)
#define RCTRLSH (QK_RCTL | KC_RSFT)
#define SYMBOL MO(_SYMBOL)
#define NUMBERS MO(_NUMBERS)
#define MOVE MO(_MOVE)
#define QWERTY DF(_QWERTY)
#define GAME DF(_GAME)
#define ADJUST MO(_ADJUST)
#define DYN MO(_DYN)

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

[_QWERTY] = LAYOUT_preonic_grid(
    KC_ESC,  KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_BSPC,
    KC_TAB,  KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,    KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_QUOT,
    ADJUST,  KC_A,    KC_S,    KC_D,    KC_F,    KC_G,    KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, KC_ENT,
    KC_LSFT, KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH, KC_RSFT,
    LCTRLSH, KC_LCTL, KC_LGUI, KC_LALT, SYMBOL,  NUMBERS, KC_SPC,  MOVE,    KC_RALT, KC_RCTL, KC_RCTL, RCTRLSH
),

[_GAME] = LAYOUT_preonic_grid(
    KC_ESC,  KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_BSPC,
    KC_TAB,  KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,    KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_QUOT,
    ADJUST,  KC_A,    KC_S,    KC_D,    KC_F,    KC_G,    KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, KC_ENT,
    KC_LSFT, KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH, KC_RSFT,
    KC_LCTL, KC_LCTL, KC_LGUI, KC_LALT, KC_SPC,  NUMBERS, KC_SPC,  MOVE,    KC_RALT, KC_RCTL, KC_RCTL, RCTRLSH
),

[_SYMBOL] = LAYOUT_preonic_grid(
    _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
    _______, KC_LABK, KC_RABK, KC_LCBR, KC_RCBR, KC_TILD, _______, KC_PLUS, KC_CIRC, KC_ASTR, KC_EXLM, _______,
    _______, KC_LBRC, KC_RBRC, KC_LPRN, KC_RPRN, KC_GRV,  KC_HASH, KC_MINS, KC_UNDS, KC_PERC, KC_EQL,  KC_AT,
    _______, KC_DQUO, KC_QUOT, KC_AMPR, KC_PIPE, _______, _______, KC_DLR,  KC_AT,   KC_BSLS, _______, _______,
    _______, _______, _______, _______, _______, _______, _______, _______, _______, KC_RGUI, _______, _______
),

[_NUMBERS] = LAYOUT_preonic_grid(
    _______, _______, _______, _______, _______, _______, KC_NLCK, KC_COLN, KC_PAST, KC_PSLS, _______, _______,
    _______, _______, _______, _______, _______, _______, KC_UNDS, KC_7,    KC_8,    KC_9,    KC_PMNS, _______,
    _______, _______, _______, _______, _______, _______, KC_COMM, KC_4,    KC_5,    KC_6,    KC_PPLS, _______,
    _______, _______, _______, _______, _______, _______, KC_SPC,  KC_1,    KC_2,    KC_3,    KC_DOT,  _______,
    _______, _______, _______, _______, _______, _______, KC_0,    _______, KC_SPC,  _______, _______, _______
),

[_MOVE] = LAYOUT_preonic_grid(
    _______, KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,
    _______, _______, _______, _______, _______, _______, KC_PGUP, KC_BSPC, KC_UP,   KC_DEL,  _______, KC_F12,
    _______, _______, _______, _______, _______, _______, KC_PGDN, KC_LEFT, KC_DOWN, KC_RIGHT,KC_APP,  QUADER,
    _______, _______, _______, _______, _______, _______, KC_PSCR, KC_HOME, KC_INS,  KC_END,  _______, _______,
    _______, _______, _______, _______, _______, _______, _______, XXXXXXX, _______, KC_RGUI, _______, _______
),

[_ADJUST] = LAYOUT_preonic_grid(
    QWERTY,  _______, _______, DM_PLY1, DM_PLY2, _______, _______, _______, _______, KC_BTN3, _______, KC_WAKE,
    GAME,    _______, _______, _______, _______, KC_VOLU, KC_WH_U, KC_BTN1, KC_MS_U, KC_BTN2, KC_BTN5, _______,
    _______, _______, MU_MOD,  AU_ON,   AU_OFF,  KC_VOLD, KC_WH_D, KC_MS_L, KC_MS_D, KC_MS_R, KC_BTN4, _______,
    _______, MUV_DE,  MUV_IN,  MU_ON,   MU_OFF,  _______, _______, KC_WH_L, _______, KC_WH_R, _______, KC_CAPS,
    _______, _______, _______, _______, DYN,     KC_BTN3, _______, _______, _______, _______, _______, _______
),

[_DYN] = LAYOUT_preonic_grid(
    _______, _______, _______, DM_REC1, DM_REC2, _______, _______, _______, _______, _______, _______, _______,
    _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
    _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
    _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
    _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______
)
};


// Settings

#define QUADER_WAIT_DOWN 10  // Milliseconds key is held
#define QUADER_WAIT_UP 10  // Milliseconds between taps
#define GLOW_DWELL_TIME 700  // Milliseconds before lights start to dim
#define RELEASE_PRESS_PREVENTION_TIME 32  // If a key is released and pressed again within this time, don't press
#define PRESS_RELEASE_PREVENTION_TIME 18  // If a key is pressed and released in this time, wait the rest of this time then release


// Lighting

static uint16_t glow = 0;
static uint32_t glow_dwell_timer = 0;

static inline uint16_t cie_lightness(uint16_t v) {
    if (v <= 5243)     // if below 8% of max
        return v / 9;  // same as dividing by 900%
    else {
        uint32_t y = (((uint32_t)v + 10486) << 8) / (10486 + 0xFFFFUL);  // add 16% of max and compare
        // to get a useful result with integer division, we shift left in the expression above
        // and revert what we've done again after squaring.
        y = y * y * y >> 8;
        if (y > 0xFFFFUL)  // prevent overflow
            return 0xFFFFU;
        else
            return (uint16_t)y;
    }
}

#ifdef REV3_CONFIG_H
static inline void set_all_rgb(uint16_t value) {
    uint16_t div = value / 0x0101U;
    uint8_t mod = value % 0x0101U;
    rgblight_setrgb(div + ((rand() % 0x0101U < mod) ? 1 : 0),
                    div + ((rand() % 0x0101U < mod) ? 1 : 0),
                    div + ((rand() % 0x0101U < mod) ? 1 : 0));
}

static  inline void heat_glow(void) {
    glow = (0xFFFFU - glow < 0x0900U) ? 0xFFFFU : glow + 0x0900U;
    set_all_rgb(cie_lightness(glow));
}

static inline void cool_glow(void) {
    if (glow == 0x0000U) {
        return;
    }
    uint16_t amount = (glow / 0x0400U) | (glow % 0x0400U != 0);
    glow = (glow > amount) ? glow - amount : 0x0000U;
    set_all_rgb(cie_lightness(glow));
}
#endif

#ifdef REV1_CONFIG_H
static inline void heat_glow(void) {
    glow = ((uint32_t)glow + 0x08FFUL > 0xFFFFUL) ? 0xFFFFU : glow + 0x08FFU;
    set_pwm(cie_lightness(glow));
}

static inline void cool_glow(void) {
    if (glow == 0x0000U) {
        return;
    }
    uint16_t amount = ((glow - 0x0001U) / 0x1000U) + 1;
    amount = (amount > 0x0001U) ? amount : 0x0001U;
    glow = (glow > amount) ? glow - amount : 0x0000U;
    set_pwm(cie_lightness(glow));
}
#endif


// Init

void keyboard_post_init_user(void) {
#ifdef REV3_CONFIG_H
    rgblight_setrgb(0, 0, 0);
#endif
#ifdef REV1_CONFIG_H
    if (!is_backlight_enabled()) {
        backlight_enable();
    }
#endif
    uprintf("Greetings Paracite!\n");
}


// Processing keys

static bool quad_presser = false;
static uint16_t quad_presser_key = 0;
static uint32_t quad_repeater_timer = 0;

// Goober Event
typedef struct {
    uint_16t keycode;
    bool     active;
    uint16_t time_first_pressed;
} goober_t;

static keyevent_t last_event = (keyevent_t) {.key = (keypos_t) {.col = 0,.row = 0} ,.pressed = false ,.time = 0};
static goober_t goober = (goober_t) {.keycode = 0,.active = false,.time_first_pressed = 0};


static float normal_song[4][2] = SONG(QWERTY_SOUND);
static float game_song[6][2] = SONG(COLEMAK_SOUND);

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    uint16_t macro_kc = (keycode == ADJUST && record->event.pressed ? DYN_REC_STOP : keycode);

//    Check for dynamic macro actions and run as needed.
    if (!process_dynamic_macro(macro_kc, record)) {
//        dprintf("what is this: 0x%04X\n", ADJUST);
//        dprintf("KL: kc: 0x%04X, col: %u, row: %u, pressed: %b, time: %u, interrupt: %b, count: %u\n",
//                keycode,
//                record->event.key.col,
//                record->event.key.row,
//                record->event.pressed,
//                record->event.time,
//                record->tap.interrupted,
//                record->tap.count);
        return false;
    }

//    Goober will be unset by the matrix scanner if the timer is up.
//    Goober keycode can only be set by a key un-pressed action, thus goober has been re-pressed within the bounce time.
//    This lets the matrix know that Goober, was in fact, a goober and should be kept down.
    if (goober.active) {
        if (keycode == goober.keycode) {
            uprintf("Key %04X is a confirmed Goober. Pressed again %u ms after release.",
                    keycode, TIMER_DIFF_16(record->event.time, last_event.time))
            goober.keycode = 0;
            return false;
        }
    }


//    TODO: Check against multiple records?
//    Check the record against that previous record to see if it is a bounce.
    if (IS_LAYER_OFF(_GAME)) {
        if (KEYEQ(record->event.key, last_event.key)) {
            uint16_t delta = TIMER_DIFF_16(record->event.time, last_event.time);
            if (record->event.pressed) {
//                Do not press key a second time if it was a bounce
                if (delta < RELEASE_PRiESS_PREVENTION_TIME) {
                    uprintf("Key %04X pressed a second time only %u ms after release.\n", keycode, delta);
                    return false;
                }
            } else {
//                Do not release a key if it was a bounce.  The name Goober is given to the offending key.
//                The matrix scanner will let go of the key if it is not really a goober.
                if (delta < PRESS_RELEASE_PREVENTION_TIME) {
                    uprintf("Key %04X released after only %u ms.\n", keycode, delta);
                    goober = (goober_t) {.keycode = keycode, .active = true, .time_first_pressed = last_event.time};
                    return false;
                }
            }
        }
    }

    switch (keycode) {
        case QWERTY:
            if (record->event.pressed) {
                PLAY_SONG(normal_song);
            }
            return true;
        case GAME:
            if (record->event.pressed) {
                PLAY_SONG(game_song);
            }
            return true;
        case QUADER:
            if (record->event.pressed) {
                quad_presser = true;
            } else {
                quad_presser     = false;
                quad_presser_key = 0;
            }
            return false;
    }

    return true;
};

void post_process_record_user(uint16_t keycode, keyrecord_t *record) {
//      Handle the back lighting
    if (record->event.pressed) {
        heat_glow();
        glow_dwell_timer = timer_read32();
    }

//      Record key release to prevent double tap
    if (IS_LAYER_OFF(_GAME)) {
        last_event = record->event;
    }

    if (quad_presser) {
        // Check that key is not a modifier (see keycode.h)
        if (!IS_MOD(keycode) && keycode != RCTRLSH && keycode != LCTRLSH) {
            if (record->event.pressed) {
                wait_ms(QUADER_WAIT_DOWN);
                unregister_code(keycode);
                wait_ms(QUADER_WAIT_UP);
                tap_code_delay(keycode, QUADER_WAIT_DOWN);
                wait_ms(QUADER_WAIT_UP);
                tap_code_delay(keycode, QUADER_WAIT_DOWN);
                wait_ms(QUADER_WAIT_UP);
                tap_code_delay(keycode, QUADER_WAIT_DOWN);
                quad_presser_key    = keycode;
                quad_repeater_timer = timer_read32();
            } else {
//                Let the matrix scan know that wer not repeating anymore
                quad_presser_key = 0;
            }
        }
    }
}

void dynamic_macro_record_start_user(void) {
//    TODO: Start blinking
}

void dynamic_macro_record_end_user(int8_t direction) {
//    TODO: Stop blinking
}


// Matrix scanning

bool     muse_mode      = false;
uint8_t  last_muse_note = 0;
uint16_t muse_counter   = 0;
uint8_t  muse_offset    = 70;
uint16_t muse_tempo     = 50;

//static keyevent_t last_event = {{0,0},false,0};
//static uint8_t goober_keycode = 0;
//static keyevent_t goober = {{0,0},false,0};

void matrix_scan_user(void) {
    if (goober.keycode) {
        if (timer_elapsed(goober.time) > RELEASE_PRESS_PREVENTION_TIME) {

        }
    }

    if (glow_dwell_timer != 0) {
        if (timer_elapsed32(glow_dwell_timer) > GLOW_DWELL_TIME) {
            cool_glow();
            if (glow == 0) {
                glow_dwell_timer = 0;
            }
        }
    }

    if (quad_presser_key) {
        if (timer_elapsed(quad_repeater_timer) > 400) {
            wait_ms(QUADER_WAIT_UP);
            tap_code_delay(quad_presser_key, QUADER_WAIT_DOWN);
        }
    }

#ifdef AUDIO_ENABLE
    if (muse_mode) {
        if (muse_counter == 0) {
            uint8_t muse_note = muse_offset + SCALE[muse_clock_pulse()];
            if (muse_note != last_muse_note) {
                stop_note(compute_freq_for_midi_note(last_muse_note));
                play_note(compute_freq_for_midi_note(muse_note), 0xF);
                last_muse_note = muse_note;
            }
        }
        muse_counter = (muse_counter + 1) % muse_tempo;
    } else {
        if (muse_counter) {
            stop_all_notes();
            muse_counter = 0;
        }
    }
#endif
}
