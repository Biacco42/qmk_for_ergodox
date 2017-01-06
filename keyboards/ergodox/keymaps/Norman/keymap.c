#include "ergodox.h"
#include "debug.h"
#include "action_layer.h"
#include "version.h"

#define BASE 0 // default layer
#define META 1 // meta keys
#define GAME 2 // game layer
#define QWER 3 // QWERTY layer

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
/* Keymap 0: Basic layer
 *
 * ,--------------------------------------------------.           ,--------------------------------------------------.
 * |   1    |   2  |   3  |   4  |   5  |   6  |=>GAME|           |=>QWER|   7  |   8  |   9  |   0  |   -  |   ^    |
 * |--------+------+------+------+------+-------------|           |------+------+------+------+------+------+--------|
 * |  Tab   |   Q  |   W  |   D  |   F  |   K  |   [  |           |  ]   |   J  |   U  |   R  |   L  |   ;  |   @    |
 * |--------+------+------+------+------+------|   {  |           |  }   |------+------+------+------+------+--------|
 * |  Alt   |   A  |   S  |   E  |   T  |   G  |------|           |------|   Y  |   N  |   I  |   O  |   H  |   :    |
 * |--------+------+------+------+------+------|   (  |           |  )   |------+------+------+------+------+--------|
 * | LShift |   Z  |   X  |   C  |   V  |   B  |      |           |      |   P  |   M  |   ,  |   .  |   /  | \ / S  |
 * `--------+------+------+------+------+-------------'           `-------------+------+------+------+------+--------'
 *   | LCTL | LGUI |  App | Muhen| Henk |                                       | Left | Down |  Up  |Right |  \   |
 *   `----------------------------------'                                       `----------------------------------'
 *                                        ,-------------.       ,---------------.
 *                                        |~META |~META |       |~META | ~META  |
 *                                 ,------|------|------|       |------+--------+------.
 *                                 |      |      | Esc  |       | Del  | Back   |      |
 *                                 |Space/| Tab/ |------|       |------| Space  |Enter/|
 *                                 | Ctrl | Shift| Esc  |       | Del  |        |~META |
 *                                 `--------------------'       `----------------------'
 */
// If it accepts an argument (i.e, is a function), it doesn't need KC_.
// Otherwise, it needs KC_*
[BASE] = KEYMAP(  // layer 0 : default
        // left hand
        KC_1,           KC_2,         KC_3,   KC_4,   KC_5,   KC_6,   TG(GAME),
        KC_TAB,         KC_Q,         KC_W,   KC_D,   KC_F,   KC_K,   KC_RBRC,
        KC_LALT,        KC_A,         KC_S,   KC_E,   KC_T,   KC_G,
        KC_LSFT,        KC_Z,         KC_X,   KC_C,   KC_V,   KC_B,   S(KC_8),
        KC_LCTL,        KC_LGUI,      KC_APP ,KC_MHEN,KC_HENK,
                                              MO(META),       MO(META),
                                                              KC_ESC,
                                  CTL_T(KC_SPC),SFT_T(KC_TAB),KC_ESC,
        // right hand
             TG(QWER),    KC_7,   KC_8,   KC_9,   KC_0,   KC_MINS,          KC_EQL,
             KC_BSLS,     KC_J,   KC_U,   KC_R,   KC_L,   KC_SCLN,          KC_LBRC,
                          KC_Y,   KC_N,   KC_I,   KC_O,   KC_H,             KC_QUOT,
             S(KC_9),     KC_P,   KC_M,   KC_COMM,KC_DOT, KC_SLSH,          SFT_T(KC_RO),
                                  KC_LEFT,KC_DOWN,KC_UP,  KC_RGHT,          KC_JYEN,
             MO(META),            MO(META),
             KC_DELT,
             KC_DELT,     KC_BSPC,LT(META, KC_ENT)
),
/* Keymap 1: Meta keys
 *
 * ,--------------------------------------------------.           ,--------------------------------------------------.
 * | Reset  |      |      |      |      |      |      |           |      |      |      |      |PrtSc |      | Sleep  |
 * |--------+------+------+------+------+-------------|           |------+------+------+------+------+------+--------|
 * |   1    |   2  |   3  |   4  |   5  |   6  |      |           |      |   7  |   8  |   9  |   0  |   -  |   ^    |
 * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * |  Alt   |      |      | Muhen| Henk |      |------|           |------| Left | Down |  Up  | Right|      |        |
 * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * | LShift |  F2  |  F3  |  F4  |  F5  |  F6  |      |           |      |  F7  |  F8  |  F9  | F10  | F11  |  F12   |
 * `--------+------+------+------+------+-------------'           `-------------+------+------+------+------+--------'
 *   | LCTL | LGUI |  App | Muhen| Henk |                                       |      |      |      |      |      |
 *   `----------------------------------'                                       `----------------------------------'
 *                                        ,-------------.       ,---------------.
 *                                        |~META |~META |       |~META | ~META  |
 *                                 ,------|------|------|       |------+--------+------.
 *                                 |      |      | Esc  |       | Del  | Back   |      |
 *                                 |Space/| Tab/ |------|       |------| Space  |Enter/|
 *                                 | Ctrl | Shift| Esc  |       | Del  |        |~META |
 *                                 `--------------------'       `----------------------'
 */
// Meta keys
[META] = KEYMAP(
       RESET,     KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_TRNS,
       KC_1,      KC_2,    KC_3,    KC_4,    KC_5,    KC_6,    KC_TRNS,
       KC_TRNS,   KC_NO,   KC_NO,   KC_MHEN, KC_HENK, KC_NO,
       KC_TRNS,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,   KC_TRNS,
       KC_TRNS,   KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
                                           KC_TRNS, KC_TRNS,
                                                    KC_TRNS,
                                  KC_TRNS, KC_TRNS, KC_TRNS,
    // right hand
       KC_TRNS,  KC_NO,   KC_NO,   KC_NO,   KC_PSCR, KC_NO,   KC_SLEP,
       KC_TRNS,  KC_7,    KC_8,    KC_9,    KC_0,    KC_MINS, KC_EQL,
                 KC_LEFT, KC_DOWN, KC_UP,   KC_RGHT, KC_NO,   KC_NO,
       KC_TRNS,  KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,  KC_F1,
                          KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,
       KC_TRNS,  KC_TRNS,
       KC_TRNS,
       KC_TRNS,  KC_TRNS, KC_TRNS
),

/* Keymap 2: game layer
 *
 * ,--------------------------------------------------.           ,--------------------------------------------------.
 * |   1    |   2  |   3  |   4  |   5  |   6  |=>GAME|           |=>QWER|   7  |   8  |   9  |   0  |   -  |   ^    |
 * |--------+------+------+------+------+-------------|           |------+------+------+------+------+------+--------|
 * |  Tab   |   Q  |   W  |   E  |   R  |   T  |   [  |           |  ]   |   Y  |   U  |   I  |   O  |   P  |   @    |
 * |--------+------+------+------+------+------|   {  |           |  }   |------+------+------+------+------+--------|
 * |  Alt   |   A  |   S  |   D  |   F  |   G  |------|           |------|   H  |   J  |   K  |   L  |   ;  |   :    |
 * |--------+------+------+------+------+------|   (  |           |  )   |------+------+------+------+------+--------|
 * | LShift |   Z  |   X  |   C  |   V  |   B  |      |           |      |   N  |   M  |   ,  |   .  |   /  | \ / S  |
 * `--------+------+------+------+------+-------------'           `-------------+------+------+------+------+--------'
 *   | LCTL | LGUI |  App | Muhen| Henk |                                       | Left | Down |  Up  |Right |  \   |
 *   `----------------------------------'                                       `----------------------------------'
 *                                        ,-------------.       ,---------------.
 *                                        |~META |~META |       |~META | ~META  |
 *                                 ,------|------|------|       |------+--------+------.
 *                                 |      |      | Esc  |       | Del  | Back   |      |
 *                                 |Space | Tab  |------|       |------| Space  |Enter |
 *                                 |      |      | Esc  |       | Del  |        |      |
 *                                 `--------------------'       `----------------------'
 */
// If it accepts an argument (i.e, is a function), it doesn't need KC_.
// Otherwise, it needs KC_*
[GAME] = KEYMAP(  // layer 2: game layer
        // left hand
        KC_1,           KC_2,         KC_3,   KC_4,   KC_5,   KC_6,   KC_TRNS,
        KC_TAB,         KC_Q,         KC_W,   KC_E,   KC_R,   KC_T,   KC_RBRC,
        KC_LALT,        KC_A,         KC_S,   KC_D,   KC_F,   KC_G,
        KC_LSFT,        KC_Z,         KC_X,   KC_C,   KC_V,   KC_B,   S(KC_8),
        KC_LCTL,        KC_LGUI,      KC_APP ,KC_MHEN,KC_HENK,
                                              MO(META),       MO(META),
                                                              KC_ESC,
                                                KC_SPC,KC_TAB,KC_ESC,
        // right hand
             KC_TRNS,     KC_7,   KC_8,   KC_9,   KC_0,   KC_MINS,          KC_EQL,
             KC_BSLS,     KC_Y,   KC_U,   KC_I,   KC_O,   KC_P,             KC_LBRC,
                          KC_H,   KC_J,   KC_K,   KC_L,   KC_SCLN,          KC_QUOT,
             S(KC_9),     KC_N,   KC_M,   KC_COMM,KC_DOT, KC_SLSH,          SFT_T(KC_RO),
                                  KC_LEFT,KC_DOWN,KC_UP,  KC_RGHT,          KC_JYEN,
             MO(META),            MO(META),
             KC_DELT,
             KC_DELT,     KC_BSPC,KC_ENT
),

/* Keymap 3: QWERTY layer
 *
 * ,--------------------------------------------------.           ,--------------------------------------------------.
 * |   1    |   2  |   3  |   4  |   5  |   6  |=>GAME|           |=>QWER|   7  |   8  |   9  |   0  |   -  |   ^    |
 * |--------+------+------+------+------+-------------|           |------+------+------+------+------+------+--------|
 * |  Tab   |   Q  |   W  |   E  |   R  |   T  |   [  |           |  ]   |   Y  |   U  |   I  |   O  |   P  |   @    |
 * |--------+------+------+------+------+------|   {  |           |  }   |------+------+------+------+------+--------|
 * |  Alt   |   A  |   S  |   D  |   F  |   G  |------|           |------|   H  |   J  |   K  |   L  |   ;  |   :    |
 * |--------+------+------+------+------+------|   (  |           |  )   |------+------+------+------+------+--------|
 * | LShift |   Z  |   X  |   C  |   V  |   B  |      |           |      |   N  |   M  |   ,  |   .  |   /  | \ / S  |
 * `--------+------+------+------+------+-------------'           `-------------+------+------+------+------+--------'
 *   | LCTL | LGUI |  App | Muhen| Henk |                                       | Left | Down |  Up  |Right |  \   |
 *   `----------------------------------'                                       `----------------------------------'
 *                                        ,-------------.       ,---------------.
 *                                        |~META |~META |       |~META | ~META  |
 *                                 ,------|------|------|       |------+--------+------.
 *                                 |      |      | Esc  |       | Del  | Back   |      |
 *                                 |Space/| Tab/ |------|       |------| Space  |Enter/|
 *                                 | Ctrl | Shift| Esc  |       | Del  |        |~META |
 *                                 `--------------------'       `----------------------'
 */
// If it accepts an argument (i.e, is a function), it doesn't need KC_.
// Otherwise, it needs KC_*
[QWER] = KEYMAP(  // layer 0 : default
        // left hand
        KC_1,           KC_2,         KC_3,   KC_4,   KC_5,   KC_6,   KC_TRNS,
        KC_TAB,         KC_Q,         KC_W,   KC_E,   KC_R,   KC_T,   KC_RBRC,
        KC_LALT,        KC_A,         KC_S,   KC_D,   KC_F,   KC_G,
        KC_LSFT,        KC_Z,         KC_X,   KC_C,   KC_V,   KC_B,   S(KC_8),
        KC_LCTL,        KC_LGUI,      KC_APP ,KC_MHEN,KC_HENK,
                                              MO(META),       MO(META),
                                                              KC_ESC,
                                  CTL_T(KC_SPC),SFT_T(KC_TAB),KC_ESC,
        // right hand
             KC_TRNS,    KC_7,   KC_8,   KC_9,   KC_0,   KC_MINS,          KC_EQL,
             KC_BSLS,     KC_Y,   KC_U,   KC_I,   KC_O,   KC_P,             KC_LBRC,
                          KC_H,   KC_J,   KC_K,   KC_L,   KC_SCLN,          KC_QUOT,
             S(KC_9),     KC_N,   KC_M,   KC_COMM,KC_DOT, KC_SLSH,          SFT_T(KC_RO),
                                  KC_LEFT,KC_DOWN,KC_UP,  KC_RGHT,          KC_JYEN,
             MO(META),            MO(META),
             KC_DELT,
             KC_DELT,     KC_BSPC,LT(META, KC_ENT)
),
};

const uint16_t PROGMEM fn_actions[] = {
    [1] = ACTION_LAYER_TAP_TOGGLE(META)                // FN1 - Momentary Layer 1 (Symbols)
};

const macro_t *action_get_macro(keyrecord_t *record, uint8_t id, uint8_t opt)
{
  // MACRODOWN only works in this function
      switch(id) {
        case 0:
        if (record->event.pressed) {
          SEND_STRING (QMK_KEYBOARD "/" QMK_KEYMAP " @ " QMK_VERSION);
        }
        break;
      }
    return MACRO_NONE;
};

// Runs just one time when the keyboard initializes.
void matrix_init_user(void) {

};

// Runs constantly in the background, in a loop.
void matrix_scan_user(void) {

    uint8_t layer = biton32(layer_state);

    ergodox_board_led_off();
    ergodox_right_led_1_off();
    ergodox_right_led_2_off();
    ergodox_right_led_3_off();
    switch (layer) {
      // TODO: Make this relevant to the ErgoDox EZ.
        case 1:
            ergodox_right_led_1_on();
            break;
        case 2:
            ergodox_right_led_2_on();
            break;
        case 3:
            ergodox_right_led_3_on();
        default:
            // none
            break;
    }

};
