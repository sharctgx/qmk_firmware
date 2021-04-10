
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
#define KC_MDSH UC(0x2014)

// Set a default OS
void matrix_init_user(){
  set_unicode_input_mode(UC_LNX);
}

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

  [_QWERTY] = LAYOUT(
  //,-------+-------+-------+-------+-------+-------+-------.     ,-------+-------+-------+-------+-------+-------+-------.
    KC_GRAVE, KC_Q  , KC_W  , KC_E  , KC_R  , KC_T  ,KC_NLCK,      KC_CAPS, KC_Y  , KC_U  , KC_I  , KC_O  , KC_P  ,KC_LBRC,
  //|-------+-------+-------+-------+-------+-------+-------|     |-------+-------+-------+-------+-------+-------+-------|
     KC_TAB , KC_A  , KC_S  , KC_D  , KC_F  , KC_G  ,KC_ENT ,      KC_DEL , KC_H  , KC_J  , KC_K  , KC_L  ,KC_SCLN, LGUI_C,
  //|-------+-------+-------+-------+-------+-------+-------|     |-------+-------+-------+-------+-------+-------+-------|
     LCTL_C , KC_Z  , KC_X  , KC_C  , KC_V  , KC_B  ,KC_RALT,      KC_LALT, KC_N  , KC_M  ,KC_COMM,KC_DOT ,KC_SLSH, RCTL_C,
  //|-------+-------+-------+-------+-------+-------+-------|     |-------+-------+-------+-------+-------+-------+-------|
                                  KC_ESC_NAV,KC_SP_SHIFT,                KC_BS_SHIFT,KC_ENTER_NUM
  // \------------------------------+-------+-------+------/       \------+-------+-------+------------------------------/
  ),

  [_NUMPAD_SYMBOLS] = LAYOUT(
  //,-------+-------+-------+-------+-------+-------+-------.     ,-------+-------+-------+-------+-------+-------+-------.
     _______,KC_PSLS,KC_P7  ,KC_P8  ,KC_P9  ,KC_PPLS,_______,      _______,_______,KC_HOME,KC_END ,KC_PTAB,KC_NTAB,_______,
  //|-------+-------+-------+-------+-------+-------+-------|     |-------+-------+-------+-------+-------+-------+-------|
     _______,KC_PAST,KC_P4  ,KC_P5  ,KC_P6  ,KC_PMNS,_______,      _______,KC_LEFT,KC_DOWN, KC_UP ,KC_RGHT,KC_INS ,_______,
  //|-------+-------+-------+-------+-------+-------+-------|     |-------+-------+-------+-------+-------+-------+-------|
     _______,KC_COLN,KC_P1  ,KC_P2  ,KC_P3  ,KC_EQL ,_______,      _______,_______,KC_LDSK,KC_RDSK,KC_PSCR,KC_CAD ,_______,
  //|-------+-------+-------+-------+-------+-------+-------|     |-------+-------+-------+-------+-------+-------+-------|
                                     KC_P0  ,_______,                      _______,_______
  // \------------------------------+-------+-------+------/       \------+-------+-------+------------------------------/
  ),                                                                       // we can put more symbols here if needed
                                                                           // |
  [_NAV] = LAYOUT(                                                         // V
  //,-------+-------+-------+-------+-------+-------+-------.     ,-------+-------+-------+-------+-------+-------+-------.
     KC_VOLU,KC_F9  ,KC_F10 ,KC_F11 ,KC_F12 ,KC_BRIU,_______,      _______,KC_MDSH,KC_UNDS,KC_AMPR,KC_PIPE,KC_CIRC,_______,
  //|-------+-------+-------+-------+-------+-------+-------|     |-------+-------+-------+-------+-------+-------+-------|
     KC_VOLD,KC_F5  ,KC_F6  ,KC_F7  ,KC_F8  ,KC_BRID,_______,      _______,KC_BSLS,KC_EXLM,KC_EQL, KC_AT  ,KC_PERC,_______,
  //|-------+-------+-------+-------+-------+-------+-------|     |-------+-------+-------+-------+-------+-------+-------|
     KC_MUTE,KC_F1,  KC_F2  ,KC_F3  ,KC_F4  ,_______,_______,      _______,_______,KC_LPRN,KC_RPRN,KC_DLR ,KC_HASH,_______,
  //|-------+-------+-------+-------+-------+-------+-------|     |-------+-------+-------+-------+-------+-------+-------|
                                     _______,_______,                      _______,_______
  // \------------------------------+-------+-------+------/       \------+-------+-------+------------------------------/
  )
};

// Идеи:
// 3) протестить спец. символы для двух раскладок
// 5) сделать возможность залипания слоев


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
