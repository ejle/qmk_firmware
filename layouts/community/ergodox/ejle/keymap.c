#include QMK_KEYBOARD_H
#include "debug.h"
#include "action_layer.h"
#include "version.h"

#define BASE 0 // default layer
#define SYMB 1 // symbol layer
#define MDIA 2 // media and movement layer
#define JEN_BASE 3
#define JEN_SYMB 4
#define JEN_MDIA 5

// NOTE: Cells marked with ACCESS must remain transparent, they're the keys that actually get to that layer

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
/* Keymap 0: Basic layer
 *
 * ,--------------------------------------------------.           ,--------------------------------------------------.
 * |   L3   |   1  |   2  |   3  |   4  |   5  |      |           |Sleep |   6  |   7  |   8  |   9  |   0  |        |
 * |--------+------+------+------+------+-------------|           |------+------+------+------+------+------+--------|
 * |        |   Q  |   W  |   E  |   R  |   T  |      |           |      |   Y  |   U  |   I  |   O  |   P  |        |
 * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * | tab/ctl| A/L2 |   S  |   D  |   F  |   G  |------|           |------|   H  |   J  |   K  |   L  | ;/L2 | '/ctl  |
 * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * | LS/PO  |   Z  |   X  |   C  |   V  |   B  |      |           |      |   N  |   M  |   ,  |   .  |   /  | RS/PC  |
 * `--------+------+------+------+------+-------------'           `-------------+------+------+------+------+--------' 
 *   |      |      |      |      |  ~L1 |                                       |  ~L1 | Left | Down |  Up  |Right |
 *   `----------------------------------'                                       `----------------------------------'
 *                                        ,-------------.       ,--------------.
 *                                        |      |      |       |      |       |
 *                                 ,------|------|------|       |------+-------+------.
 *                                 |      |      |      |       |      |       |      |
 *                                 |bkspc/| esc  |------|       |------| enter/|space/| 
 *                                 | L2   | alt  |      |       |      | gui   |  L2  |
 *                                 `--------------------'       `---------------------'    
 */


// If it accepts an argument (i.e, is a function), it doesn't need KC_. 
// Otherwise, it needs KC_*
[BASE] = LAYOUT_ergodox(  // layer 0 : default
        // left hand
        TO(JEN_BASE), KC_1,  KC_2,  KC_3,  KC_4,     KC_5,  KC_SYSTEM_SLEEP,
        KC_NO,        KC_Q,  KC_W,  KC_E,  KC_R,     KC_T,  KC_NO,
        CTL_T(KC_TAB),KC_A,  KC_S,  KC_D,  KC_F,     KC_G,
        KC_LSPO,      KC_Z,  KC_X,  KC_C,  KC_V,     KC_B,  KC_NO,
        KC_NO,        KC_NO, KC_NO, KC_NO, MO(SYMB),

                                                      KC_LALT, KC_NO,
                                                               KC_NO,
                             LT(MDIA, KC_BSPC), ALT_T(KC_ESC), KC_NO,
        // right hand
   KC_SYSTEM_SLEEP, KC_6,    KC_7,     KC_8,    KC_9,    KC_0,    KC_NO,
             KC_NO, KC_Y,    KC_U,     KC_I,    KC_O,    KC_P,    KC_NO,
                    KC_H,    KC_J,     KC_K,    KC_L,    KC_SCLN, CTL_T(KC_QUOT),
             KC_NO, KC_N,    KC_M,     KC_COMM, KC_DOT,  KC_SLSH, KC_RSPC,
                             MO(SYMB), KC_LEFT, KC_DOWN, KC_UP,   KC_RIGHT,

             KC_NO, KC_LCTL,
             KC_NO,
             KC_NO, GUI_T(KC_ENT), LT(MDIA, KC_SPC)
    ),
/* Keymap 1: Symbol Layer
 *
 * ,--------------------------------------------------.           ,--------------------------------------------------.
 * |        |      |      |      |      |      |      |           |      |      |      |      |      |      |        |
 * |--------+------+------+------+------+-------------|           |------+------+------+------+------+------+--------|
 * |        |   !  |   @  |   #  |   $  |   %  |      |           |      |   ^  |   &  |   *  |   {  |   }  |        |
 * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * |        |   1  |   2  |   3  |   4  |   5  |------|           |------|   6  |   7  |   8  |   9  |   0  |        |
 * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * |        |   |  |   \  |   `  |   _  |   ~  |      |           |      |   =  |   -  |   +  |   [  |   ]  |        |
 * `--------+------+------+------+------+-------------'           `-------------+------+------+------+------+--------'
 *   |      |      |      |      |      |                                       |      |      |      |      |      |
 *   `----------------------------------'                                       `----------------------------------'
 *                                        ,-------------.       ,-------------.
 *                                        |      |      |       |      |      |
 *                                 ,------|------|------|       |------+------+------.
 *                                 |      |      |      |       |      |      |      |
 *                                 |      |      |------|       |------|      |      |
 *                                 |      |      |      |       |      |      |      |
 *                                 `--------------------'       `--------------------'
 */
// SYMBOLS
[SYMB] = LAYOUT_ergodox(
       // left hand
       KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
       KC_TRNS, KC_EXLM, KC_AT,   KC_HASH, KC_DLR,  KC_PERC, KC_TRNS,
       KC_TRNS, KC_1,    KC_2,    KC_3  ,  KC_4   , KC_5   ,
       KC_TRNS, KC_PIPE, KC_BSLS, KC_GRV,  KC_UNDS, KC_TILD, KC_TRNS,
       KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,

                                       KC_TRNS, KC_TRNS,
                                                KC_TRNS,
                              KC_TRNS, KC_TRNS, KC_TRNS,
       // right hand
       KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
       KC_TRNS, KC_CIRC, KC_AMPR, KC_ASTR, KC_LCBR, KC_RCBR, KC_TRNS,
                KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_TRNS,
       KC_TRNS, KC_EQL,  KC_MINS, KC_PLUS, KC_LBRC, KC_RBRC, KC_TRNS,
                         KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,

       KC_TRNS, KC_TRNS,
       KC_TRNS,
       KC_TRNS, KC_TRNS, KC_TRNS
),
/* Keymap 2: Media and mouse keys
 *
 * ,--------------------------------------------------.           ,--------------------------------------------------.
 * |        |      |      |      |      |      | Flash|           | Flash|      |      |      |      |      |        |
 * |--------+------+------+------+------+-------------|           |------+------+------+------+------+------+--------|
 * |        |      | Btn1 | MsUp | Btn2 |ScrlUp|      |           |      | end  | pgdn | pgup | home |      |        |
 * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * |        |      |MsLeft|MsDown|MsRght|ScrlDn|------|           |------| left | down |  up  | down |      |        |
 * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * |        |      |      |      |      |      |      |           |      | play | Voldn|Volup | mute |      |        |
 * `--------+------+------+------+------+-------------'           `-------------+------+------+------+------+--------'
 *   |      |      |      |      |      |                                       |      |      |      |      |      |
 *   `----------------------------------'                                       `----------------------------------'
 *                                        ,-------------.       ,-------------.
 *                                        |      |      |       |      |      |
 *                                 ,------|------|------|       |------+------+------.
 *                                 |      |      |      |       |      |      |      |
 *                                 |      |      |------|       |------|      |      |
 *                                 |      |      |      |       |      |      |      |
 *                                 `--------------------'       `--------------------'
 */
// MEDIA AND MOUSE
[MDIA] = LAYOUT_ergodox(
       KC_TRNS, KC_TRNS, KC_TRNS,    KC_TRNS,    KC_TRNS,    KC_TRNS, RESET,
       KC_TRNS, KC_TRNS, KC_BTN1,    KC_MS_U,    KC_BTN2,    KC_WH_U, KC_TRNS,
       KC_TRNS, KC_TRNS, KC_MS_L,    KC_MS_D,    KC_MS_R,    KC_WH_D,
       KC_TRNS, KC_TRNS, KC_TRNS,    KC_TRNS,    KC_TRNS,    KC_TRNS, KC_TRNS,
       KC_TRNS, KC_TRNS, KC_TRNS,    KC_TRNS,    KC_TRNS,
                                           KC_TRNS, KC_TRNS,
                                                    KC_TRNS,
                                  KC_TRNS, KC_TRNS, KC_TRNS,
    // right hand
       RESET,    KC_TRNS, KC_TRNS,   KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
       KC_TRNS,  KC_END,  KC_PGDOWN, KC_PGUP, KC_HOME, KC_TRNS, KC_TRNS,
                 KC_LEFT, KC_DOWN,   KC_UP,   KC_RIGHT,KC_TRNS, KC_TRNS,
       KC_TRNS,  KC_MPLY, KC_VOLD,   KC_VOLU, KC_MUTE, KC_TRNS, KC_TRNS,
                          KC_TRNS,   KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
       KC_TRNS, KC_TRNS,
       KC_TRNS,
       KC_TRNS, KC_TRNS, KC_TRNS
),
/* Keymap 3: Jen Basic layer
 *
 * ,--------------------------------------------------.           ,--------------------------------------------------.
 * |    L0  |      |      |      |      |      |      |           |Sleep |      |      |      |      |      |        |
 * |--------+------+------+------+------+-------------|           |------+------+------+------+------+------+--------|
 * |        |   Q  |   W  |   E  |   R  |   T  |      |           |      |   Y  |   U  |   I  |   O  |   P  |        |
 * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * |tab/alt | A/L2 |   S  |   D  |   F  |   G  |------|           |------|   H  |   J  |   K  |   L  | ;/L2 |'       |
 * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * | LS/PO  |   Z  |   X  |   C  |   V  |   B  |      |           |      |   N  |   M  |   ,  |   .  |   /  | RS/PC  |
 * `--------+------+------+------+------+-------------'           `-------------+------+------+------+------+--------'
 *   |      |      |      |      |  ~L4 |                                       |  ~L4 |      |      |      |      |
 *   `----------------------------------'                                       `----------------------------------'
 *                                        ,-------------.       ,---------------.
 *                                        |      |      |       |      |        |
 *                                 ,------|------|------|       |------+--------+------.
 *                                 |      |      |      |       |      | ctrl/  |      |
 *                                 |bkspc | esc/ |------|       |------| enter  |space | (tapdance: ?)
 *                                 |      | lgui |      |       |  L4  |        |      |
 *                                 `--------------------'       `----------------------'
 */

// If it accepts an argument (i.e, is a function), it doesn't need KC_.
// Otherwise, it needs KC_*
[JEN_BASE] = LAYOUT_ergodox(  // layer 0 : default
        // left hand
        TO(BASE),      KC_1,           KC_2,  KC_3,  KC_4,     KC_5, KC_SYSTEM_SLEEP,
        KC_NO,         KC_Q,               KC_W,  KC_E,  KC_R,         KC_T,  KC_NO,
        ALT_T(KC_TAB), LT(JEN_MDIA, KC_A), KC_S,  KC_D,  KC_F,         KC_G,
        KC_LSPO,       KC_Z,               KC_X,  KC_C,  KC_V,         KC_B,  KC_NO,
        KC_NO,         KC_NO,              KC_NO, KC_NO, MO(JEN_SYMB),
                                                         TG(JEN_MDIA), KC_NO,
                                                                       KC_NO,
                                              KC_BSPC, LGUI_T(KC_ESC), KC_NO,
        // right hand
   KC_SYSTEM_SLEEP, KC_6,    KC_7,    KC_8,    KC_9,   KC_0,                      KC_NO,
             KC_NO, KC_Y,  KC_U,         KC_I,    KC_O,    KC_P,                  KC_NO,
                    KC_H,  KC_J,         KC_K,    KC_L,    LT(JEN_MDIA, KC_SCLN), CTL_T(KC_QUOT),
             KC_NO, KC_N,  KC_M,         KC_COMM, KC_DOT,  KC_SLSH,               KC_RSPC,
                           MO(JEN_SYMB), KC_NO,   KC_NO,   KC_NO,                 KC_NO,

             KC_NO, TG(JEN_SYMB),
             KC_NO,
             KC_NO, CTL_T(KC_ENT), KC_SPC
    ),
/* Keymap 4: JEN Symbol Layer
 *
 * ,--------------------------------------------------.           ,--------------------------------------------------.
 * |        |      |      |      |      |      |      |           |      |      |      |      |      |      |        |
 * |--------+------+------+------+------+-------------|           |------+------+------+------+------+------+--------|
 * |        |   !  |   @  |   #  |   $  |   %  |      |           |      |   ^  |   &  |   *  |   {  |   }  |        |
 * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * |        |   1  |   2  |   3  |   4  |   5  |------|           |------|   6  |   7  |   8  |   9  |   0  |        |
 * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * |        |   |  |   \  |   `  |   _  |   ~  |      |           |      |   =  |   -  |   +  |   [  |   ]  |        |
 * `--------+------+------+------+------+-------------'           `-------------+------+------+------+------+--------'
 *   |      |      |      |      |      |                                       |      |      |      |      |      |
 *   `----------------------------------'                                       `----------------------------------'
 *                                        ,-------------.       ,-------------.
 *                                        |      |      |       |      |      |
 *                                 ,------|------|------|       |------+------+------.
 *                                 |      |      |      |       |      |      |      |
 *                                 | del  | lgui |------|       |------| ctrl |      |
 *                                 |      |      |      |       |      |      |      |
 *                                 `--------------------'       `--------------------'
 */
// SYMBOLS
[JEN_SYMB] = LAYOUT_ergodox(
       // left hand
       KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
       KC_TRNS, KC_EXLM, KC_AT,   KC_HASH, KC_DLR,  KC_PERC, KC_TRNS,
       KC_TRNS, KC_1,    KC_2,    KC_3  ,  KC_4   , KC_5   ,
       KC_TRNS, KC_PIPE, KC_BSLS, KC_GRV,  KC_UNDS, KC_TILD, KC_TRNS,
       KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,

                                       KC_TRNS, KC_TRNS,
                                                KC_TRNS,
                               KC_DEL, KC_LGUI, KC_TRNS,
       // right hand
       KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
       KC_TRNS, KC_CIRC, KC_AMPR, KC_ASTR, KC_LCBR, KC_RCBR, KC_TRNS,
                KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_TRNS,
       KC_TRNS, KC_EQL,  KC_MINS, KC_PLUS, KC_LBRC, KC_RBRC, KC_TRNS,
                         KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,

       KC_TRNS, KC_TRNS,
       KC_TRNS,
       KC_TRNS, KC_RCTL, KC_TRNS
),
/* Keymap 5: Media and mouse keys
 *
 * ,--------------------------------------------------.           ,--------------------------------------------------.
 * |        |      |      |      |      |      | Flash|           | Flash|      |      |      |      |      |        |
 * |--------+------+------+------+------+-------------|           |------+------+------+------+------+------+--------|
 * |        |      | Btn1 | MsUp | Btn2 |ScrlUp|      |           |      | end  | pgdn | pgup | home |      |        |
 * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * |        |      |MsLeft|MsDown|MsRght|ScrlDn|------|           |------| left | down |  up  | down |      |        |
 * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * |        |      |      |      |      |      |      |           |      | play | Volup|Voldn | mute |      |        |
 * `--------+------+------+------+------+-------------'           `-------------+------+------+------+------+--------'
 *   |      |      |      |      |      |                                       |      |      |      |      |      |
 *   `----------------------------------'                                       `----------------------------------'
 *                                        ,-------------.       ,-------------.
 *                                        |      |      |       |      |      |
 *                                 ,------|------|------|       |------+------+------.
 *                                 |      |      |      |       |      |      |      |
 *                                 |      |      |------|       |------|      |      |
 *                                 |      |      |      |       |      |      |      |
 *                                 `--------------------'       `--------------------'
 */
// MEDIA AND MOUSE
[JEN_MDIA] = LAYOUT_ergodox(
       KC_TRNS, KC_TRNS, KC_TRNS,    KC_TRNS,    KC_TRNS,    KC_TRNS, RESET,
       KC_TRNS, KC_TRNS, KC_BTN1,    KC_MS_U,    KC_BTN2,    KC_WH_U, KC_TRNS,
       KC_TRNS, KC_TRNS, KC_MS_L,    KC_MS_D,    KC_MS_R,    KC_WH_D,
       KC_TRNS, KC_TRNS, BL_STEP,    BL_DEC,     BL_INC,     BL_TOGG, KC_TRNS,
       KC_TRNS, KC_TRNS, KC_TRNS,    KC_TRNS,    KC_TRNS,
                                           KC_TRNS, KC_TRNS,
                                                    KC_TRNS,
                                  KC_TRNS, KC_TRNS, KC_TRNS,
    // right hand
       RESET,    KC_TRNS, KC_TRNS,   KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
       KC_TRNS,  KC_END,  KC_PGDOWN, KC_PGUP, KC_HOME, KC_TRNS, KC_TRNS,
                 KC_LEFT, KC_DOWN,   KC_UP,   KC_RIGHT,KC_TRNS, KC_MPLY,
       KC_TRNS,  KC_MPLY, KC_VOLU,   KC_VOLD, KC_MUTE, KC_TRNS, KC_TRNS,
                          KC_TRNS,   KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
       KC_TRNS, KC_TRNS,
       KC_TRNS,
       KC_TRNS, KC_TRNS, KC_TRNS
)
};

const uint16_t PROGMEM fn_actions[] = {
    // [1] = ACTION_LAYER_TAP_TOGGLE(SYMB)                // FN1 - Momentary Layer 1 (Symbols)
};

const macro_t *action_get_macro(keyrecord_t *record, uint8_t id, uint8_t opt)
{
  // MACRODOWN only works in this function
    return MACRO_NONE;
};

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  return true;
}

// Runs just one time when the keyboard initializes.
void matrix_init_user(void) {

};


// Runs constantly in the background, in a loop.
void matrix_scan_user(void) {
    ergodox_board_led_on();
    // ergodox_led_all_on();
};

