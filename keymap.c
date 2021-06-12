#include QMK_KEYBOARD_H
#include "muse.h"

#define RCTRLSH RCTL(KC_RSFT)
#define LCTRLSH LCTL(KC_LSFT)

enum preonic_layers {
    _QWERTY,
    _SYMBOL,
    _NUMBERS,
    _MOVE,
    _ADJUST
};

enum preonic_keycodes {
    QWERTY = SAFE_RANGE,
    SYMBOL,
    NUMBERS,
    MOVE,
    ADJUST,
    BACKLIT,
    QUADER,
    THREE_0,
    TWO_0
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
/* Qwerty
 * ,-----------------------------------------------------------------------------------.
 * | Esc  |   1  |   2  |   3  |   4  |   5  |   6  |   7  |   8  |   9  |   0  | Bksp |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * | Tab  |   Q  |   W  |   E  |   R  |   T  |   Y  |   U  |   I  |   O  |   P  | Del  |
 * |------+------+------+------+------+-------------+------+------+------+------+------|
 * | Mouse|   A  |   S  |   D  |   F  |   G  |   H  |   J  |   K  |   L  |   ;  | Enter|
 * |------+------+------+------+------+------|------+------+------+------+------+------|
 * | Shift|   Z  |   X  |   C  |   V  |   B  |   N  |   M  |   ,  |   .  |   /  |Shift |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * | Brite| Ctrl | GUI  | Alt  |Lower |Numpad|Space |Raise | Left | Down |  Up  |Right |
 * `-----------------------------------------------------------------------------------'
 */
[_QWERTY] = LAYOUT_preonic_grid(
    KC_ESC,  KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_BSPC,
    KC_TAB,  KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,    KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_QUOT,
    ADJUST,  KC_A,    KC_S,    KC_D,    KC_F,    KC_G,    KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, KC_ENT,
    KC_LSFT, KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH, KC_RSFT,
    LCTRLSH, KC_LCTL, KC_LGUI, KC_LALT, SYMBOL,  NUMBERS, KC_SPC,  MOVE,    KC_RALT, KC_RGUI, KC_RCTL, RCTRLSH
),

/* Symbols
 * ,-----------------------------------------------------------------------------------.
 * |   ~  |   !  |   @  |   #  |   $  |   %  |   ^  |   &  |   *  |   (  |   )  | Bksp |
 * |------+------+------+------+------+-------------+------+------+------+------+------|
 * |   ~  |   !  |   @  |   #  |   $  |   %  |   ^  |   &  |   *  |   (  |   )  | Del  |
 * |------+------+------+------+------+-------------+------+------+------+------+------|
 * | Del  |  F1  |  F2  |  F3  |  F4  |  F5  |  F6  |   _  |   +  |   {  |   }  |  |   |
 * |------+------+------+------+------+------|------+------+------+------+------+------|
 * |      |  F7  |  F8  |  F9  |  F10 |  F11 |  F12 |ISO ~ |ISO | | Home | End  |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |      |      |      |             |      | Next | Vol- | Vol+ | Play |
 * `-----------------------------------------------------------------------------------'
 */
[_SYMBOL] = LAYOUT_preonic_grid(
    _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
    _______, KC_LABK, KC_RABK, KC_LCBR, KC_RCBR, KC_TILD, _______, KC_PLUS, KC_CIRC, KC_ASTR, KC_EXLM, _______,
    _______, KC_LBRC, KC_RBRC, KC_LPRN, KC_RPRN, KC_GRV,  KC_HASH, KC_MINS, KC_UNDS, KC_PERC, KC_EQL,  KC_AT,
    _______, KC_DQUO, KC_QUOT, KC_AMPR, KC_PIPE, _______, _______, KC_DLR,  KC_AT,   KC_BSLS, _______, _______,
    _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______
),

/* Numbers
 * ,-----------------------------------------------------------------------------------.
 * |   ~  |   !  |   @  |   #  |   $  |   %  |   ^  |   &  |   *  |   (  |   )  | Bksp |
 * |------+------+------+------+------+-------------+------+------+------+------+------|
 * |   ~  |   !  |   @  |   #  |   $  |   %  |   ^  |   &  |   *  |   (  |   )  | Del  |
 * |------+------+------+------+------+-------------+------+------+------+------+------|
 * | Del  |  F1  |  F2  |  F3  |  F4  |  F5  |  F6  |   _  |   +  |   {  |   }  |  |   |
 * |------+------+------+------+------+------|------+------+------+------+------+------|
 * |      |  F7  |  F8  |  F9  |  F10 |  F11 |  F12 |ISO ~ |ISO | | Home | End  |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |      |      |      |             |      | Next | Vol- | Vol+ | Play |
 * `-----------------------------------------------------------------------------------'
 */
[_NUMBERS] = LAYOUT_preonic_grid(
    _______, _______, _______, _______, _______, _______, _______, KC_NLCK, KC_PSLS, KC_PAST, _______, _______,
    _______, _______, _______, _______, _______, _______, _______, KC_7,    KC_8,    KC_9,    KC_PMNS, _______,
    _______, _______, _______, _______, _______, _______, THREE_0, KC_4,    KC_5,    KC_6,    KC_PPLS, _______,
    _______, _______, _______, _______, _______, _______, TWO_0,   KC_1,    KC_2,    KC_3,    KC_SPC,  _______,
    _______, _______, _______, _______, _______, _______, KC_0,    _______, KC_COMM, KC_DOT,  KC_COLN, _______
),

/* Raise
 * ,-----------------------------------------------------------------------------------.
 * |   `  |   1  |   2  |   3  |   4  |   5  |   6  |   7  |   8  |   9  |   0  | Bksp |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |   `  |   1  |   2  |   3  |   4  |   5  |   6  |   7  |   8  |   9  |   0  | Del  |
 * |------+------+------+------+------+-------------+------+------+------+------+------|
 * | Del  |  F1  |  F2  |  F3  |  F4  |  F5  |  F6  |   -  |   =  |   [  |   ]  |  \   |
 * |------+------+------+------+------+------|------+------+------+------+------+------|
 * |      |  F7  |  F8  |  F9  |  F10 |  F11 |  F12 |ISO # |ISO / | Pg Up| Pg Dn|      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |      |      |      |             |      | Next | Vol- | Vol+ | Play |
 * `-----------------------------------------------------------------------------------'
 */
[_MOVE] = LAYOUT_preonic_grid(
    _______, KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,
    _______, _______, _______, _______, _______, _______, KC_PGUP, KC_BSPC, KC_UP,   KC_DEL,  _______, KC_F12,
    _______, _______, _______, _______, _______, _______, KC_PGDN, KC_LEFT, KC_DOWN, KC_RIGHT,KC_MENU, QUADER,
    _______, _______, _______, _______, _______, _______, KC_PSCR, KC_HOME, KC_INS,  KC_END,  _______, _______,
    _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______
),

/* Adjust (Lower + Raise)
 * ,-----------------------------------------------------------------------------------.
 * |  F1  |  F2  |  F3  |  F4  |  F5  |  F6  |  F7  |  F8  |  F9  |  F10 |  F11 |  F12 |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      | Reset| Debug|      |      |      |      |TermOf|TermOn|      |      |  Del |
 * |------+------+------+------+------+-------------+------+------+------+------+------|
 * |      |      |Aud cy|Aud on|AudOff|      |      |Qwerty|Colemk|Dvorak|      |      |
 * |------+------+------+------+------+------|------+------+------+------+------+------|
 * |      |Voice-|Voice+|Mus on|MusOff|MidiOn|MidOff|      |      |      |      |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |      |      |      |             |      |      |      |      |      |
 * `-----------------------------------------------------------------------------------'
 */
[_ADJUST] = LAYOUT_preonic_grid(
    _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
    _______, RESET,   DEBUG,   _______, _______, _______, _______, _______, _______, _______, _______, _______,
    _______, _______, MU_MOD,  AU_ON,   AU_OFF,  _______, _______, _______, _______, _______, _______, _______,
    _______, MUV_DE,  MUV_IN,  MU_ON,   MU_OFF,  _______, _______, _______, _______, _______, _______, _______,
    BACKLIT, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______
)


};

bool quad_presser = false;

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        case QWERTY:
            if (record->event.pressed) {
                set_single_persistent_default_layer(_QWERTY);
            }
            return false;
            break;
        case SYMBOL:
            if (record->event.pressed) {
                layer_on(_SYMBOL);
            } else {
                layer_off(_SYMBOL);
            }
            return false;
            break;
        case NUMBERS:
            if (record->event.pressed) {
                layer_on(_NUMBERS);
            } else {
                layer_off(_NUMBERS);
            }
            return false;
            break;
        case MOVE:
            if (record->event.pressed) {
                layer_on(_MOVE);
            } else {
                layer_off(_MOVE);
            }
            return false;
            break;
        case ADJUST:
            if (record->event.pressed) {
                layer_on(_ADJUST);
            } else {
                layer_off(_ADJUST);
            }
            return false;
            break;
        case BACKLIT:
            if (record->event.pressed) {
                register_code(KC_RSFT);
                #ifdef BACKLIGHT_ENABLE
                    backlight_step();
                #endif
                #ifdef __AVR__
                    writePinLow(E6);
                #endif
            } else {
                unregister_code(KC_RSFT);
                #ifdef __AVR__
                    writePinHigh(E6);
                #endif
            }
            return false;
            break;
        case QUADER:
            if (record->event.pressed) {
                quad_presser = true;
            } else {
                quad_presser = false;
            }
            return false;
            break;
        case THREE_0:
            if (record->event.pressed) {
                SEND_STRING("000");
            }
            return false;
            break;
        case TWO_0:
            if (record->event.pressed) {
                SEND_STRING("00");
            }
            return false;
            break;
    }
    if (quad_presser) {
        if (record->event.pressed) {
            tap_code_delay(keycode, 10);
            tap_code_delay(keycode, 10);
            tap_code_delay(keycode, 10);
            tap_code_delay(keycode, 10);
            return false;
        }
    }

    return true;
};

bool muse_mode = false;
uint8_t last_muse_note = 0;
uint16_t muse_counter = 0;
uint8_t muse_offset = 70;
uint16_t muse_tempo = 50;


void matrix_scan_user(void) {
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

bool music_mask_user(uint16_t keycode) {
    switch (keycode) {
        case MOVE:
        case SYMBOL:
            return false;
        default:
            return true;
    }
}
