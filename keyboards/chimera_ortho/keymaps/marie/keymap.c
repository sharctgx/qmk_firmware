// this is the style you want to emulate.
// This is the canonical layout file for the Quantum project. If you want to add another keyboard,

#include QMK_KEYBOARD_H

// Each layer gets a name for readability, which is then used in the keymap matrix below.
// The underscores don't mean anything - you can have a layer called STUFF or any other name.
// Layer names don't all need to be of the same length, obviously, and you can also skip them
// entirely and just use numbers.
enum chimera_ortho_layers {
  _QWERTY,
  _NUMPAD_SYMBOLS,
  _NAV
};

#define KC_SP_SHIFT SFT_T(KC_SPC)
#define KC_BS_SHIFT SFT_T(KC_BSPC)
#define KC_ESC_NAV LT(_NAV, KC_ESC)
#define KC_ENTER_NUM LT(_NUMPAD_SYMBOLS, KC_ENT)
#define KC_CAD LALT(LCTL(KC_DEL))
#define LCTL_C LCTL_T(KC_MINS)
#define RCTL_C RCTL_T(KC_RBRC)
#define LGUI_C LGUI_T(KC_QUOT)
#define KC_PTAB LCTL(KC_PGUP)
#define KC_NTAB LCTL(KC_PGDN)
#define KC_LDSK LCTL(LALT(KC_LEFT))
#define KC_RDSK LCTL(LALT(KC_RGHT))

// Set a default OS
void matrix_init_user(){
  set_unicode_input_mode(UC_LNX);
}

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

  [_QWERTY] = LAYOUT(
  //,-------+-------+-------+-------+-------+-------+-------.     ,-------+-------+-------+-------+-------+-------+-------.
    KC_GRAVE, KC_Q  , KC_W  , KC_E  , KC_R  , KC_T ,UC(0x2014),   KC_CAPS, KC_Y  , KC_U  , KC_I  , KC_O  , KC_P  ,KC_LBRC,
  //|-------+-------+-------+-------+-------+-------+-------|     |-------+-------+-------+-------+-------+-------+-------|
     KC_TAB , KC_A  , KC_S  , KC_D  , KC_F  , KC_G  ,KC_ENT ,      KC_DEL , KC_H  , KC_J  , KC_K  , KC_L  ,KC_SCLN,LGUI_C,
  //|-------+-------+-------+-------+-------+-------+-------|     |-------+-------+-------+-------+-------+-------+-------|
     LCTL_C , KC_Z  , KC_X  , KC_C  , KC_V  , KC_B  ,KC_LAPO,      KC_RAPC, KC_N  , KC_M  ,KC_COMM,KC_DOT ,KC_SLSH,RCTL_C ,
  //|-------+-------+-------+-------+-------+-------+-------|     |-------+-------+-------+-------+-------+-------+-------|
                                  KC_ESC_NAV,KC_BS_SHIFT,                  KC_SP_SHIFT,KC_ENTER_NUM
  // \------------------------------+-------+-------+------/       \------+-------+-------+------------------------------/
  ),

  [_NUMPAD_SYMBOLS] = LAYOUT(
  //,-------+-------+-------+-------+-------+-------+-------.     ,-------+-------+-------+-------+-------+-------+-------.
     _______,KC_PSLS,KC_7   ,KC_8   ,KC_9   ,KC_PPLS,_______,      _______,_______,KC_CIRC,KC_BSLS,KC_AT  ,KC_PERC,_______,
  //|-------+-------+-------+-------+-------+-------+-------|     |-------+-------+-------+-------+-------+-------+-------|
     _______,KC_PAST,KC_4   ,KC_5   ,KC_6   ,KC_PMNS,_______,      _______,_______,KC_UNDS,KC_EXLM,KC_HASH,KC_AMPR,_______,
  //|-------+-------+-------+-------+-------+-------+-------|     |-------+-------+-------+-------+-------+-------+-------|
     _______,KC_PEQL,KC_1   ,KC_2   ,KC_3   ,KC_PDOT,_______,      _______,_______,KC_COLN,KC_DLR ,KC_PIPE,_______,_______,
  //|-------+-------+-------+-------+-------+-------+-------|     |-------+-------+-------+-------+-------+-------+-------|
                                     KC_0   ,_______,                      _______,_______
  // \------------------------------+-------+-------+------/       \------+-------+-------+------------------------------/
  ),

  [_NAV] = LAYOUT(
  //,-------+-------+-------+-------+-------+-------+-------.     ,-------+-------+-------+-------+-------+-------+-------.
     KC_VOLU,KC_F9  ,KC_F10 ,KC_F11 ,KC_F12 ,KC_BRIU,_______,      _______,KC_HOME,KC_END ,KC_PTAB,KC_NTAB,KC_PGUP,_______,
  //|-------+-------+-------+-------+-------+-------+-------|     |-------+-------+-------+-------+-------+-------+-------|
     KC_VOLD,KC_F5  ,KC_F6  ,KC_F7  ,KC_F8  ,KC_BRID,_______,      _______,KC_LEFT,KC_DOWN, KC_UP ,KC_RGHT,KC_PGDN,_______,
  //|-------+-------+-------+-------+-------+-------+-------|     |-------+-------+-------+-------+-------+-------+-------|
     KC_MUTE,KC_F1,  KC_F2  ,KC_F3  ,KC_F4  ,_______,_______,      _______,KC_INS ,KC_PSCR,KC_LDSK,KC_RDSK,KC_CAD ,_______,
  //|-------+-------+-------+-------+-------+-------+-------|     |-------+-------+-------+-------+-------+-------+-------|
                                     _______,_______,                      _______,_______
  // \------------------------------+-------+-------+------/       \------+-------+-------+------------------------------/
  )
};

// Идеи:
// 2) em-dash
// 3) совместить по максимуму спец. символы для двух раскладок (поместить их в одно место, но под разные модификаторы)
// 4) есть проблема с тем, что нельзя нажимать стрелки одной рукой((

void matrix_scan_user(void) {
    uint8_t layer = biton32(layer_state);

    switch (layer) {
        case _QWERTY:
            set_led_green;
            break;
        case _NUMPAD_SYMBOLS:
            set_led_red;
            break;
        case _NAV:
            set_led_magenta;
            break;
       default:
            set_led_green;
            break;
    }
};
