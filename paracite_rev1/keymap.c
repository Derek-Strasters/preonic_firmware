#include QMK_KEYBOARD_H
#include "muse.h"
//#include "backlight_avr.h"


enum preonic_layers {
    _QWERTY,
    _GAME,
    _SYMBOL,
    _NUMBERS,
    _MOVE,
    _ADJUST
};

enum preonic_keycodes {
    QWERTY = SAFE_RANGE,
    GAME,
    QUADER,
    THREE_0,
    TWO_0,
    ADJUST
};

#define LCTRLSH (QK_LCTL | KC_LSFT)
#define RCTRLSH (QK_RCTL | KC_RSFT)
#define SYMBOL MO(_SYMBOL)
#define NUMBERS MO(_NUMBERS)
#define MOVE MO(_MOVE)


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
    _______, KC_LABK, KC_RABK, KC_LCBR, KC_RCBR, KC_TILD, _______, KC_PLUS, KC_CIRC, KC_ASTR, KC_EXLM, _______,
    _______, KC_LBRC, KC_RBRC, KC_LPRN, KC_RPRN, KC_GRV,  KC_HASH, KC_MINS, KC_UNDS, KC_PERC, KC_EQL,  KC_AT,
    _______, KC_DQUO, KC_QUOT, KC_AMPR, KC_PIPE, _______, _______, KC_DLR,  KC_AT,   KC_BSLS, _______, _______,
    _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______
),

[_NUMBERS] = LAYOUT_preonic_grid(
    _______, _______, _______, _______, _______, _______, _______, KC_NLCK, KC_PSLS, KC_PAST, _______, _______,
    _______, _______, _______, _______, _______, _______, _______, KC_7,    KC_8,    KC_9,    KC_PMNS, _______,
    _______, _______, _______, _______, _______, _______, THREE_0, KC_4,    KC_5,    KC_6,    KC_PPLS, _______,
    _______, _______, _______, _______, _______, _______, TWO_0,   KC_1,    KC_2,    KC_3,    KC_SPC,  _______,
    _______, _______, _______, _______, _______, _______, KC_0,    _______, KC_COMM, KC_DOT,  KC_COLN, _______
),

[_MOVE] = LAYOUT_preonic_grid(
    _______, KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,
    _______, _______, _______, _______, _______, _______, KC_PGUP, KC_BSPC, KC_UP,   KC_DEL,  _______, KC_F12,
    _______, _______, _______, _______, _______, _______, KC_PGDN, KC_LEFT, KC_DOWN, KC_RIGHT,KC_APP,  QUADER,
    _______, _______, _______, _______, _______, _______, KC_PSCR, KC_HOME, KC_INS,  KC_END,  _______, _______,
    _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______
),

[_ADJUST] = LAYOUT_preonic_grid(
    QWERTY,  _______, _______, _______, _______, _______, _______, _______, _______, KC_BTN3, _______, _______,
    GAME,    RESET,   _______, _______, _______, _______, KC_WH_U, KC_BTN1, KC_MS_U, KC_BTN2, KC_BTN5, _______,
    _______, _______, MU_MOD,  AU_ON,   AU_OFF,  _______, KC_WH_D, KC_MS_L, KC_MS_D, KC_MS_R, KC_BTN4, _______,
    _______, MUV_DE,  MUV_IN,  MU_ON,   MU_OFF,  _______, _______, KC_WH_L, _______, KC_WH_R, _______, KC_CAPS,
    _______, _______, _______, _______, _______, KC_BTN3, _______, _______, _______, _______, _______, _______
)
};

void keyboard_post_init_user(void) {
    if (!is_backlight_enabled()) {
        backlight_enable();
    }
}

static bool quad_presser = false;
static uint16_t quad_presser_key = 0;
static uint16_t quad_repeater_timer = 0;

static uint16_t glow = 0;
static bool glow_cooling = false;
static uint16_t glow_dwell_timer = 0;

uint16_t heat_glow(uint16_t value) {
    return ((uint32_t)value + 0x08FFUL > 0xFFFFUL) ? 0xFFFFU : value + 0x08FFU;
}

uint16_t cool_glow(uint16_t value) {
    if (value == 0x0000U) return 0x0000U;
    uint16_t amount = ((value - 0x0001U) / 0x1FFFU) + 1;
    amount = (amount > 0x000FU) ? amount : 0x000FU;
    return (value > amount) ? value - amount : 0x0000U;
}

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    if (record->event.pressed) {
        glow = heat_glow(glow);
        glow_dwell_timer = timer_read();
        glow_cooling = false;
        set_pwm(cie_lightness(glow));
    }

    switch (keycode) {
        case QWERTY:
            if (record->event.pressed) {
                set_single_persistent_default_layer(_QWERTY);
            }
            return false;
            break;
        case GAME:
            if (record->event.pressed) {
                set_single_persistent_default_layer(_GAME);
            }
            return false;
            break;
        case QUADER:
            if (record->event.pressed) {
                quad_presser = true;
            } else {
                quad_presser     = false;
                quad_presser_key = 0;
            }
            return false;
        case THREE_0:
            if (record->event.pressed) {
                SEND_STRING("000");
            }
            return false;
        case TWO_0:
            if (record->event.pressed) {
                SEND_STRING("00");
            }
            return false;
        case ADJUST:
            if (record->event.pressed) {
                layer_on(_ADJUST);
            } else {
                layer_off(_ADJUST);
            }
            return false;
            break;
    }

    return true;
};

void post_process_record_user(uint16_t keycode, keyrecord_t *record) {
    if (quad_presser) {
        // Check that key is not a modifier (see keycode.h)
        if (!IS_MOD(keycode) && keycode != RCTRLSH && keycode != LCTRLSH) {
            if (record->event.pressed) {
                tap_code_delay(keycode, 10);
                tap_code_delay(keycode, 10);
                tap_code_delay(keycode, 10);
                quad_presser_key    = keycode;
                quad_repeater_timer = timer_read();
            } else {
                quad_presser_key = 0;
                quad_repeater_timer = 0;
            }
        }
    }
}

bool muse_mode = false;
uint8_t last_muse_note = 0;
uint16_t muse_counter = 0;
uint8_t muse_offset = 70;
uint16_t muse_tempo = 50;

void matrix_scan_user(void) {
    if (timer_elapsed(glow_dwell_timer) > 700 || glow_cooling) {
        if (!glow_cooling) {
            glow_cooling = true;
            glow_dwell_timer = 0;
        }
        else if (glow == 0) {
            glow_cooling = false;
        }
        glow = cool_glow(glow);
        set_pwm(cie_lightness(glow));
    }

    if (quad_presser_key) {
        if (timer_elapsed(quad_repeater_timer) > 400) {
            tap_code_delay(quad_presser_key, 10);
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