#include "ergodox.h"
#include "debug.h"
#include "action_layer.h"
#include "version.h"

#define BASE 0 // default layer
#define SYMB 1 // symbols
#define META 2 // meta keys

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
/* Keymap 0: Basic layer
 *
 * ,--------------------------------------------------.           ,--------------------------------------------------.
 * |   1    |   2  |   3  |   4  |   5  |   6  |L2 TGL|           |L1 TGL|   7  |   8  |   9  |   0  |   -  |   ^    |
 * |--------+------+------+------+------+-------------|           |------+------+------+------+------+------+--------|
 * |  Tab   |   Q  |   W  |   E  |   R  |   T  |   [  |           |  ]   |   Y  |   U  |   I  |   O  |   P  |   @    |
 * |--------+------+------+------+------+------|   {  |           |  }   |------+------+------+------+------+--------|
 * |  Esc   |   A  |   S  |   D  |   F  |   G  |------|           |------|   H  |   J  |   K  |   L  |   ;  |   :    |
 * |--------+------+------+------+------+------|   (  |           |  )   |------+------+------+------+------+--------|
 * | LShift |   Z  |   X  |   C  |   V  |   B  |      |           |      |   N  |   M  |   ,  |   .  |   /  | \ / S  |
 * `--------+------+------+------+------+-------------'           `-------------+------+------+------+------+--------'
 *   | LCTL | LGUI |  Alt | Muhen| Henk |                                       | Left | Down |  Up  |Right |  \   |
 *   `----------------------------------'                                       `----------------------------------'
 *                                        ,-------------.       ,---------------.
 *                                        | ~L2  | ~L1  |       | ~L2  |  ~L1   |
 *                                 ,------|------|------|       |------+--------+------.
 *                                 |      |      | App  |       | Del  |        |      |
 *                                 | Space| Tab  |------|       |------| Back   |Enter |
 *                                 |      |      | Muhen|       | Henk | Space  |      |
 *                                 `--------------------'       `----------------------'
 */
// If it accepts an argument (i.e, is a function), it doesn't need KC_.
// Otherwise, it needs KC_*
[BASE] = KEYMAP(  // layer 0 : default
        // left hand
        KC_1,           KC_2,         KC_3,   KC_4,   KC_5,   KC_6,   TG(META),
        KC_TAB,         KC_Q,         KC_W,   KC_E,   KC_R,   KC_T,   KC_RBRC,
        KC_ESC,         KC_A,         KC_S,   KC_D,   KC_F,   KC_G,
        KC_LSFT,        KC_Z,         KC_X,   KC_C,   KC_V,   KC_B,   S(KC_8),
        KC_LCTL,        KC_LGUI,      KC_LALT,KC_MHEN,KC_HENK,
                                              MO(META),       MO(SYMB),
                                                              KC_APP,
                                              KC_SPC, KC_TAB, KC_MHEN,
        // right hand
             TG(SYMB),    KC_7,   KC_8,   KC_9,   KC_0,   KC_MINS,          KC_EQL,
             KC_BSLS,     KC_Y,   KC_U,   KC_I,   KC_O,   KC_P,             KC_LBRC,
                          KC_H,   KC_J,   KC_K,   KC_L,   KC_SCLN,          KC_QUOT,
             S(KC_9),     KC_N,   KC_M,   KC_COMM,KC_DOT, KC_SLSH,          SFT_T(KC_RO),
                                  KC_LEFT,KC_DOWN,KC_UP,  KC_RGHT,          KC_JYEN,
             MO(META),            MO(SYMB),
             KC_DELT,
             KC_HENK,     KC_BSPC,KC_ENT
    ),
/* Keymap 1: Symbol Layer
 *
 * ,--------------------------------------------------.           ,--------------------------------------------------.
 * |   F1   |  F2  |  F3  |  F4  |  F5  |  F6  |      |           |      |  F7  |  F8  |  F9  |  F10 |  F11 |   F12  |
 * |--------+------+------+------+------+-------------|           |------+------+------+------+------+------+--------|
 * |        |      |      | MsUp |      |      |      |           |      |   Up |   7  |   8  |   9  |   *  |        |
 * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * |        |      |MsLeft|MsDown|MsRght|      |------|           |------| Down |   4  |   5  |   6  |   +  |        |
 * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * |        |      |MsAcc0|MsAcc1|MsAcc2|      |      |           |      |   &  |   1  |   2  |   3  |   \  |        |
 * `--------+------+------+------+------+-------------'           `-------------+------+------+------+------+--------'
 *   |      |      |      |      |      |                                       |   0  |      |   .  |   =  |      |
 *   `----------------------------------'                                       `----------------------------------'
 *                                        ,-------------.       ,-------------.
 *                                        |WhLeft|WhRght|       |HOME  |END   |
 *                                 ,------|------|------|       |------+------+------.
 *                                 | Ms   | Ms   |WhUp  |       |PgUp  |      |      |
 *                                 | Left | Right|------|       |------|Back  |Enter |
 *                                 | Click| Click|WhDown|       |PgDw  |Space |      |
 *                                 `--------------------'       `--------------------'
 */
// SYMBOLS
[SYMB] = KEYMAP(
       // left hand
       KC_F1,  KC_F2,  KC_F3,  KC_F4,  KC_F5,  KC_F6,  KC_TRNS,
       KC_NO,  KC_NO,  KC_NO,  KC_MS_U,KC_NO,  KC_NO,  KC_TRNS,
       KC_NO,  KC_NO,  KC_MS_L,KC_MS_D,KC_MS_R,KC_NO,
       KC_NO,  KC_NO,  KC_ACL0,KC_ACL1,KC_ACL2,  KC_NO,  KC_TRNS,
       KC_NO,  KC_NO,  KC_LALT,  KC_NO,  KC_NO,
                                       KC_WH_L, KC_WH_R,
                                                KC_WH_U,
                              KC_BTN1, KC_BTN2, KC_WH_D,
       // right hand
       KC_TRNS, KC_F7,   KC_F8,  KC_F9,   KC_F10,  KC_F11,  KC_F12,
       KC_TRNS, KC_UP,   KC_7,   KC_8,    KC_9,    KC_ASTR, KC_NO,
                KC_DOWN, KC_4,   KC_5,    KC_6,    KC_PLUS, KC_NO,
       KC_TRNS, KC_AMPR, KC_1,   KC_2,    KC_3,    KC_BSLS, KC_NO,
                         KC_0,   KC_NO,   KC_DOT,  KC_EQL,  KC_NO,
       KC_HOME, KC_END,
       KC_PGUP,
       KC_PGDN, KC_TRNS, KC_TRNS
),
/* Keymap 2: Meta keys
 *
 * ,--------------------------------------------------.           ,--------------------------------------------------.
 * | Reset  |      |      |      |      |      |      |           |      |      |      |      |      |      | Sleep  |
 * |--------+------+------+------+------+-------------|           |------+------+------+------+------+------+--------|
 * |        |      |      |      |      |      |      |           |      |      |      |      |      |      |        |
 * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * |        |      |      |PrtSc | LGUI |      |------|           |------| Left | Down |  Up  | Right|      |        |
 * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * |        |      |      |      |      |      |      |           |      |      |      |      |      |      |        |
 * `--------+------+------+------+------+-------------'           `-------------+------+------+------+------+--------'
 *   |      |      | Alt  |      |      |                                       |      |      |      |      |      |
 *   `----------------------------------'                                       `----------------------------------'
 *                                        ,-------------.       ,-------------.
 *                                        |      |      |       |      |      |
 *                                 ,------|------|------|       |------+------+------.
 *                                 |      |      |      |       |      |      |      |
 *                                 |      |      |------|       |------|      |      |
 *                                 |      |      |      |       |      |      |      |
 *                                 `--------------------'       `--------------------'
 */
// META KEYS
[META] = KEYMAP(
       RESET,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_TRNS,
       KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_TRNS,
       KC_NO,   KC_NO,   KC_NO,   KC_PSCR, KC_LGUI, KC_NO,
       KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_TRNS,
       KC_NO,   KC_NO,   KC_NO,   KC_BTN1, KC_BTN2,
                                           KC_NO,   KC_NO,
                                                    KC_NO,
                                  KC_NO,   KC_NO,   KC_NO,
    // right hand
       KC_TRNS,  KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_SLEP,
       KC_TRNS,  KC_NO,   KC_NO,   KC_UP,   KC_NO,   KC_NO,   KC_NO,
                 KC_LEFT, KC_DOWN, KC_UP,   KC_RGHT, KC_NO,   KC_NO,
       KC_TRNS,  KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,
                          KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,
       KC_NO,   KC_NO,
       KC_NO,
       KC_NO,   KC_NO,   KC_NO
),
};

const uint16_t PROGMEM fn_actions[] = {
    [1] = ACTION_LAYER_TAP_TOGGLE(SYMB)                // FN1 - Momentary Layer 1 (Symbols)
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
        default:
            // none
            break;
    }

};
