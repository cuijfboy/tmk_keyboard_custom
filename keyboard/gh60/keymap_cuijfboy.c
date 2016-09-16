#include "keymap_common.h"

/* top right corner
r/c 0123456789ABCDEF
00: 0000000000000000
01: 0000000000000000
02: 0000000000000000
03: 0000000000000000
04: 0000000001000000
*/

/* after right shift
r/c 0123456789ABCDEF
00: 0000000000000000
01: 0000000000000000
02: 0000000000000000
03: 0000000000001000
04: 0000000000000000
*/

// 15 + 14 + 13 + 13 + 8
#define KEYMAP_CUIJFBOY( \
    K00, K01, K02, K03, K04, K05, K06, K07, K08, K09, K0A, K0B, K0C, K0D, K49, \
    K10, K11, K12, K13, K14, K15, K16, K17, K18, K19, K1A, K1B, K1C,      K1D, \
    K20, K21, K22, K23, K24, K25, K26, K27, K28, K29, K2A, K2B,           K2D, \
    K30,      K32, K33, K34, K35, K36, K37, K38, K39, K3A, K3B,      K3D, K3C, \
    K40, K41, K42,           K45,                          K4A, K4B, K4C, K4D  \
) { \
    { KC_##K00, KC_##K01, KC_##K02, KC_##K03, KC_##K04, KC_##K05, KC_##K06, KC_##K07, KC_##K08, KC_##K09, KC_##K0A, KC_##K0B, KC_##K0C, KC_##K0D }, \
    { KC_##K10, KC_##K11, KC_##K12, KC_##K13, KC_##K14, KC_##K15, KC_##K16, KC_##K17, KC_##K18, KC_##K19, KC_##K1A, KC_##K1B, KC_##K1C, KC_##K1D }, \
    { KC_##K20, KC_##K21, KC_##K22, KC_##K23, KC_##K24, KC_##K25, KC_##K26, KC_##K27, KC_##K28, KC_##K29, KC_##K2A, KC_##K2B, KC_NO,    KC_##K2D }, \
    { KC_##K30, KC_NO,    KC_##K32, KC_##K33, KC_##K34, KC_##K35, KC_##K36, KC_##K37, KC_##K38, KC_##K39, KC_##K3A, KC_##K3B, KC_##K3C, KC_##K3D }, \
    { KC_##K40, KC_##K41, KC_##K42, KC_NO,    KC_NO,    KC_##K45, KC_NO,    KC_NO,    KC_NO,    KC_##K49, KC_##K4A, KC_##K4B, KC_##K4C, KC_##K4D }  \
}

// cuijfboy
#ifdef KEYMAP_SECTION_ENABLE
const uint8_t keymaps[KEYMAPS_COUNT][MATRIX_ROWS][MATRIX_COLS] __attribute__ ((section (".keymap.keymaps"))) = {
#else
const uint8_t keymaps[][MATRIX_ROWS][MATRIX_COLS] PROGMEM = {
#endif
    /* Keymap 0: Default Layer
     * ,-----------------------------------------------------------.
     * |Esc|  1|  2|  3|  4|  5|  6|  7|  8|  9|  0|  -|  =|  \|  ~|
     * |-----------------------------------------------------------|
     * |Tab  |  Q|  W|  E|  R|  T|  Y|  U|  I|  O|  P|  [|  ]|Bksp |
     * |-----------------------------------------------------------|
     * |Fn1   |  A|  S|  D|  F|  G|  H|  J|  K|  L|  ;|  '|Return  |
     * |-----------------------------------------------------------|
     * |Shift   |  Z|  X|  C|  V|  B|  N|  M|  ,|  .|  /|Fn2  |Del |
     * |-----------------------------------------------------------|
     * |Ctrl|Alt |Gui |      Space             |Fn0 |Lef |Dwn |Rig |
     * `-----------------------------------------------------------'
     */
    KEYMAP_CUIJFBOY(
        ESC, 1,   2,   3,   4,   5,   6,   7,   8,   9,   0,   MINS,EQL, BSLS,GRV,  \
        TAB, Q,   W,   E,   R,   T,   Y,   U,   I,   O,   P,   LBRC,RBRC,     BSPC, \
        FN1, A,   S,   D,   F,   G,   H,   J,   K,   L,   SCLN,QUOT,          ENT,  \
        LSFT,     Z,   X,   C,   V,   B,   N,   M,   COMM,DOT, SLSH,     FN2, DEL,  \
        LCTL,LALT,LGUI,          SPC,                          FN0, LEFT,DOWN,RGHT),
    /* Keymap 1: Fn Layer
     * ,-----------------------------------------------------------.
     * |   | F1| F2| F3| F4| F5| F6| F7| F8| F9|F10|F11|F12|   |   |
     * |-----------------------------------------------------------|
     * |Caps |PgU|Up |PgD|   |   |   |PgD|PgU|   |   |   |   |     |
     * |-----------------------------------------------------------|
     * |      |Lef|Dow|Rig|   |Hom|Lef|Dow|Up |Rig|End|   |        |
     * |-----------------------------------------------------------|
     * |       |Fn11|Fn10|Fn12|Prv|Ply|Nxt|Mut|VoD|VoU|   |PgU  |  |
     * |-----------------------------------------------------------|
     * |    |    |    |                        |    |Hom |PgD |End |
     * `-----------------------------------------------------------'
     */
    KEYMAP_CUIJFBOY(
        TRNS,F1,  F2,  F3,  F4,  F5,  F6,  F7,  F8,  F9,  F10, F11, F12, TRNS,TRNS, \
        CAPS,PGUP,UP,  PGDN,TRNS,TRNS,TRNS,PGDN,PGUP,TRNS,TRNS,SLCK,PAUS,     TRNS, \
        TRNS,LEFT,DOWN,RGHT,TRNS,HOME,LEFT,DOWN,UP  ,RGHT,END, TRNS,          TRNS, \
        TRNS,     FN11,FN10,FN12,MPRV,MPLY,MNXT,MUTE,VOLD,VOLU,TRNS,     PGUP,TRNS, \
        TRNS,TRNS,TRNS,          TRNS,                         TRNS,HOME,PGDN,END ),
};

/*
 * Fn action definition
 */
#ifdef KEYMAP_SECTION_ENABLE
const uint16_t fn_actions[FN_ACTIONS_COUNT] __attribute__ ((section (".keymap.fn_actions"))) = {
#else
const uint16_t fn_actions[] PROGMEM = {
#endif
    [0] = ACTION_LAYER_MOMENTARY(1),
    [1] = ACTION_LAYER_MOMENTARY(1),
    [2] = ACTION_MODS_TAP_KEY(MOD_RSFT, KC_UP),
    [10] = ACTION_BACKLIGHT_TOGGLE(),
    [11] = ACTION_BACKLIGHT_DECREASE(),
    [12] = ACTION_BACKLIGHT_INCREASE(),
};

#ifdef KEYMAP_IN_EEPROM_ENABLE
uint16_t keys_count(void) {
    return sizeof(keymaps) / sizeof(keymaps[0]) * MATRIX_ROWS * MATRIX_COLS;
}

uint16_t fn_actions_count(void) {
    return sizeof(fn_actions) / sizeof(fn_actions[0]);
}
#endif
