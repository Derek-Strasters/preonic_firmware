#include QMK_KEYBOARD_H
#include "muse.h"


// Key Map.

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
#define ADJUST MO(_ADJUST)
#define DYN MO(_DYN)
#define QWERTY DF(_QWERTY)
#define GAME DF(_GAME)

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

[_QWERTY] = LAYOUT_preonic_grid(
    KC_ESC,  KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_BSPC,
    KC_TAB,  KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,    KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_QUOT,
    ADJUST,  KC_A,    KC_S,    KC_D,    KC_F,    KC_G,    KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, KC_ENT,
    KC_LSFT, KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH, KC_RSFT,
    LCTRLSH, KC_LCTL, KC_LGUI, KC_LALT, SYMBOL,  NUMBERS, KC_SPC,  MOVE,    KC_RALT, KC_RGUI, KC_RCTL, RCTRLSH
),

[_GAME] = LAYOUT_preonic_grid(
    KC_ESC,  KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_BSPC,
    KC_TAB,  KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,    KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_QUOT,
    ADJUST,  KC_A,    KC_S,    KC_D,    KC_F,    KC_G,    KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, KC_ENT,
    KC_LSFT, KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH, KC_RSFT,
    KC_LCTL, KC_LCTL, KC_LGUI, KC_LALT, KC_SPC,  NUMBERS, KC_SPC,  MOVE,    KC_RALT, KC_RGUI, KC_RCTL, RCTRLSH
),

[_SYMBOL] = LAYOUT_preonic_grid(
    _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
    _______, KC_LABK, KC_RABK, KC_LCBR, KC_RCBR, KC_TILD, _______, KC_PLUS, KC_ASTR, KC_CIRC, KC_EXLM, _______,
    _______, KC_LBRC, KC_RBRC, KC_LPRN, KC_RPRN, KC_GRV,  KC_HASH, KC_MINS, KC_UNDS, KC_PERC, KC_EQL,  _______,
    _______, KC_DQUO, KC_QUOT, KC_AMPR, KC_PIPE, _______, _______, KC_DLR,  KC_AT,   KC_BSLS, _______, _______,
    _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______
),

[_NUMBERS] = LAYOUT_preonic_grid(
    _______, _______, _______, _______, _______, _______, KC_NLCK, KC_COLN, KC_PAST, KC_PSLS, _______, _______,
    _______, _______, _______, _______, _______, _______, KC_UNDS, KC_7,    KC_8,    KC_9,    KC_PMNS, _______,
    _______, _______, _______, _______, _______, _______, KC_COMM, KC_4,    KC_5,    KC_6,    KC_PPLS, _______,
    _______, _______, _______, _______, _______, _______, KC_SPC,  KC_1,    KC_2,    KC_3,    KC_DOT,  _______,
    _______, _______, _______, _______, _______, _______, KC_0,    _______, KC_SPC,  _______, KC_BSLS, _______
),

[_MOVE] = LAYOUT_preonic_grid(
    _______, KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,
    _______, _______, _______, _______, _______, _______, KC_PGUP, KC_BSPC, KC_UP,   KC_DEL,  _______, KC_F12,
    _______, _______, _______, _______, _______, _______, KC_PGDN, KC_LEFT, KC_DOWN, KC_RIGHT,KC_APP,  QUADER,
    _______, _______, _______, _______, _______, _______, KC_PSCR, KC_HOME, KC_INS,  KC_END,  _______, _______,
    _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______
),

[_ADJUST] = LAYOUT_preonic_grid(
    QWERTY,  _______, _______, DM_PLY1, DM_PLY2, _______, _______, _______, _______, KC_BTN3, _______, KC_POWER,
    GAME,    _______, _______, _______, _______, KC_VOLU, KC_WH_U, KC_BTN1, KC_MS_U, KC_BTN2, KC_BTN5, KC_WAKE,
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

#define QUADER_WAIT_DOWN 10               // Milliseconds key is held.
#define QUADER_WAIT_UP 10                 // Milliseconds between taps.
#define GLOW_DWELL_TIME 700               // Milliseconds before lights start to dim.
#define RELEASE_PRESS_PREVENTION_TIME 24  // If a key is released and pressed again within this time, don't press.
#define PRESS_RELEASE_PREVENTION_TIME 18  // If a key is pressed and released in this time, wait .
#define BUFLEN 6                          // Number of possible goobers to ring buffer. 8 max.
#define BLINK_TIME 60                     // Time the blinking backlights are on and off for.

// Lighting

static uint16_t glow             = 0;
static uint32_t glow_dwell_timer = 0;
static uint32_t blink_timer      = 0;
static bool     blinking         = false;

static inline uint16_t cie_lightness(uint16_t v) {
    if (v <= 5243)     // if below 8% of max
        return v / 9;  // same as dividing by 900%
    else {
        uint32_t y = (((uint32_t)v + 10486) << 8) / (10486 + 0xFFFFUL);
        // Add 16% of max and compare to get a useful result with
        // integer division, we shift left in the expression above
        // and revert what we've done again after squaring.
        y = y * y * y >> 8;
        if (y > 0xFFFFUL)  // prevent overflow.
            return 0xFFFFU;
        else
            return (uint16_t)y;
    }
}

#ifdef REV3_CONFIG_H
static inline void set_all_rgb(uint16_t value) {
    uint16_t div = value / 0x0101U;
    uint8_t  mod = value % 0x0101U;
    rgblight_setrgb(div + ((rand() % 0x0101U < mod) ? 1 : 0), div + ((rand() % 0x0101U < mod) ? 1 : 0), div + ((rand() % 0x0101U < mod) ? 1 : 0));
}

static inline void heat_glow(void) {
    glow = (0xFFFFU - glow < 0x0900U) ? 0xFFFFU : glow + 0x0900U;
    set_all_rgb(cie_lightness(glow));
}

static inline void cool_glow(void) {
    if (glow == 0x0000U) {
        return;
    }
    uint16_t amount = (glow / 0x0400U) | (glow % 0x0400U != 0);
    glow            = (glow > amount) ? glow - amount : 0x0000U;
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
    amount          = (amount > 0x0001U) ? amount : 0x0001U;
    glow            = (glow > amount) ? glow - amount : 0x0000U;
    set_pwm(cie_lightness(glow));
}
#endif


// Processing keys.

/* Last Event. */
typedef struct {
    keypos_t key;
    uint16_t time;
} last_event_t;

/* Goober Event. */
typedef struct {
    uint16_t keycode;
    keypos_t key;
    bool     active;
    uint16_t time_unpressed;
} goober_t;

static float normal_song[4][2] = SONG(QWERTY_SOUND);
static float game_song[6][2]   = SONG(COLEMAK_SOUND);

static bool     quad_presser        = false;
static uint16_t quad_presser_key    = 0;
static uint32_t quad_repeater_timer = 0;

static last_event_t last_events[BUFLEN];
static uint8_t last_event_i = 0;
static goober_t goober = {.keycode = 0, .key = (keypos_t){.col = 0, .row = 0}, .active = false, .time_unpressed = 0};

void keyboard_post_init_user(void) {
#ifdef REV3_CONFIG_H
    rgblight_setrgb(0, 0, 0);
#endif
#ifdef REV1_CONFIG_H
    if (!is_backlight_enabled()) {
        backlight_enable();
    }
#endif
    wait_ms(2500);
    uprintf("Greetings Paracite!\n");

    for (uint8_t i = 0; i < BUFLEN; i++) {
        last_events[i] = (last_event_t){.key = (keypos_t){.col = 0, .row = 0}, .time = 0};
    }
}

typedef uint8_t MatTrans[10][6][2];
const MatTrans mat_trans = {
    {{ 1, 1}, { 2, 1}, { 3, 1}, { 4, 1}, { 5, 1}, { 6, 1}},
    {{ 1, 2}, { 2, 2}, { 3, 2}, { 4, 2}, { 5, 2}, { 6, 2}},
    {{ 1, 3}, { 2, 3}, { 3, 3}, { 4, 3}, { 5, 3}, { 6, 3}},
    {{ 1, 4}, { 2, 4}, { 3, 4}, { 4, 4}, { 5, 4}, { 6, 4}},
    {{ 7, 1}, { 8, 1}, { 9, 1}, {10, 1}, {11, 1}, {12, 1}},
    {{ 7, 2}, { 8, 2}, { 9, 2}, {10, 2}, {11, 2}, {12, 2}},
    {{ 7, 3}, { 8, 3}, { 9, 3}, {10, 3}, {11, 3}, {12, 3}},
    {{ 7, 4}, { 8, 4}, { 9, 4}, {10, 4}, {11, 4}, {12, 4}},
    {{ 1, 5}, { 2, 5}, { 3, 5}, {10, 5}, {11, 5}, {12, 5}},
    {{ 7, 5}, { 8, 5}, { 9, 5}, { 4, 5}, { 5, 5}, { 6, 5}}
};

void update_last_event(keyevent_t event) {
    last_event_i = (last_event_i == (BUFLEN - 1)) ? 0 : last_event_i + 1;
    last_events[last_event_i] = (last_event_t){.key = event.key, .time = event.time};
}

static inline bool has_goobers(uint16_t keycode, keyevent_t event) {
    // Goober will be unset by the matrix scanner if the timer is up.
    // Goober keycode can only be set by a key un-pressed action, thus goober has been re-pressed within the bounce time.
    // This lets the matrix know that Goober, was in fact, a goober and should be kept down.
    if (goober.active) {
        if (KEYEQ(event.key,  goober.key)) {
            uint16_t delta = TIMER_DIFF_16(event.time, goober.time_unpressed);
            uint8_t mcol = mat_trans[event.key.row][event.key.col][0];
            uint8_t mrow = mat_trans[event.key.row][event.key.col][1];
            uprintf("\033[0;31m%02huX%02hu is a confirmed Goober. Pressed again %u ms after release.\033[0m\n", mcol, mrow, delta);
            goober.active = false;
            update_last_event(event);
            return true;
        }
    }

    // Check the event against the previous events to see if it is a bounce.
    dprint("ring buffer lookup: ");
    bool first_run = true;
    for (uint8_t i = last_event_i; i != last_event_i || first_run; i = (i == 0) ? BUFLEN - 1 : (i - 1)) {
        first_run = false;
        dprintf("%u ", i);
        if (KEYEQ(event.key, last_events[i].key)) {
            uint8_t mcol = mat_trans[event.key.row][event.key.col][0];
            uint8_t mrow = mat_trans[event.key.row][event.key.col][1];
            uint16_t delta = TIMER_DIFF_16(event.time, last_events[i].time);

            if (event.pressed) {
                // Do not press key a second time if it was pressed again within time limit (results in two un-presses).
                if (delta < RELEASE_PRESS_PREVENTION_TIME) {
                    dprint("\n");
                    uprintf("\033[0;31m%02huX%02hu pressed again %u ms after release.\033[0m", mcol, mrow, delta);
                    if (!IS_LAYER_ON(_GAME)) {
                        uprint("  A second key register was blocked.\n");
                        return true;
                    }
                    uprint("\n");
                }
            } else {
                // Do not release a key if it was a bounce.  The name Goober is given to the offending key.
                // The matrix scanner will let go of the key if it is not really a goober.
                if (delta < PRESS_RELEASE_PREVENTION_TIME) {
                    dprint("\n");
                    uprintf("%02huX%02hu pressed for only %u ms.\n", mcol, mrow, delta);
                    goober = (goober_t){.keycode = keycode, .key = event.key, .active = true, .time_unpressed = event.time};
                    return true;
                }
                dprint("\n");
                dprintf("%02huX%02hu  pressed for %u ms.\n", mcol, mrow, delta);
                return false;
            }
            break;
        }
    }
    dprint("\n");
    return false;
}

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    if (has_goobers(keycode, record->event)) {
        return false;
    }

    // Check for dynamic macro actions and run as needed.
    uint16_t macro_kc = (keycode == ADJUST && record->event.pressed ? DYN_REC_STOP : keycode);
    if (!process_dynamic_macro(macro_kc, record)) {
        return false;
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
        default:
            return true;
    }
};

void tap_code_delay16(uint16_t code, uint16_t delay) {
    register_code16(code);
    for (uint16_t i = delay; i > 0; i--) {
        wait_ms(1);
    }
    unregister_code16(code);
}

void post_process_record_user(uint16_t keycode, keyrecord_t *record) {
    // Handle the back lighting.
    if (record->event.pressed) {
        heat_glow();
        glow_dwell_timer = timer_read32();
    }

    // Record last key to the buffer to inspect for double taps on next press.
    update_last_event(record->event);

    // Process the quad presser.
    if (quad_presser) {
        // Check that key is not a modifier (see keycode.h)
        // Don't execute for special functions or mod keys, but do for left shift combos.
        if ((keycode < QK_MODS && !IS_MOD(keycode)) || (keycode > QK_LCTL && keycode < QK_LALT)) {
            if (record->event.pressed) {
                wait_ms(QUADER_WAIT_DOWN);
                unregister_code16(keycode);
                wait_ms(QUADER_WAIT_UP);
                tap_code_delay16(keycode, QUADER_WAIT_DOWN);
                wait_ms(QUADER_WAIT_UP);
                tap_code_delay16(keycode, QUADER_WAIT_DOWN);
                wait_ms(QUADER_WAIT_UP);
                tap_code_delay16(keycode, QUADER_WAIT_DOWN);
                quad_presser_key    = keycode;
                quad_repeater_timer = timer_read32();
            } else {
                // Let the matrix scan know that wer not repeating anymore.
                quad_presser_key = 0;
            }
        }
    }
}

void dynamic_macro_record_start_user(void) {
    blinking  = true;
}

void dynamic_macro_record_end_user(int8_t direction) {
    blinking  = false;
}


// Matrix scanning.

bool     muse_mode      = false;
uint8_t  last_muse_note = 0;
uint16_t muse_counter   = 0;
uint8_t  muse_offset    = 70;
uint16_t muse_tempo     = 50;

void matrix_scan_user(void) {
    static bool blink_state = false;

    // The key was released for longer than the limit.  Key is not a goober, so we register the un-press.
    if (goober.active) {
        uint16_t delta = timer_elapsed(goober.time_unpressed);
        if (delta > RELEASE_PRESS_PREVENTION_TIME) {
            uint8_t mcol = mat_trans[goober.key.row][goober.key.col][0];
            uint8_t mrow = mat_trans[goober.key.row][goober.key.col][1];
            uprintf("%02huX%02hu was not a goober and was still released %u ms after release.\n", mcol, mrow, delta);
            // If the offender is a layer mod, just turn that layer off (I guess?)
            if (goober.keycode >= QK_MOMENTARY && goober.keycode <= QK_TOGGLE_LAYER_MAX) {
                layer_off(goober.keycode & 0xFF);  // TODO: should probably toggle
            }
            unregister_code16(goober.keycode);
            goober.active = false;
        }
    }

    if (blinking) {
        if (timer_elapsed32(blink_timer) > BLINK_TIME) {
            if (blink_state) {
                rgblight_setrgb(0, 0, 0);
                blink_state = false;
            } else {
                rgblight_setrgb(255, 255, 255);
                blink_state = true;
            }
            blink_timer = timer_read32();
        }
    } else if (glow_dwell_timer != 0) {
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
            tap_code_delay16(quad_presser_key, QUADER_WAIT_DOWN);
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
