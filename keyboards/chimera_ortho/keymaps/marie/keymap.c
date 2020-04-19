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
#define KC_ESC_NAV LT(_NAV, KC_ESC)
#define KC_ENTER_NUM LT(_NUMPAD_SYMBOLS, KC_ENT)
#define KC_CAD LALT(LCTL(KC_DEL))
#define LCTL_C LCTL_T(KC_MINS)
#define RCTL_C RCTL_T(KC_QUOT)
#define KC_PTAB LCTL(KC_PGUP)
#define KC_NTAB LCTL(KC_PGDN)
#define KC_PWRD LCTL(KC_LEFT)
#define KC_NWRD LCTL(KC_RGHT)
#define ALT_TAB LALT(KC_TAB)
#define ALT_LPR ALT_T(KC_LPRN)
#define ALT_RPR ALGR_T(KC_RPRN)

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

  [_QWERTY] = LAYOUT(
  //,-------+-------+-------+-------+-------+-------+-------.     ,-------+-------+-------+-------+-------+-------+-------.
    KC_GRAVE, KC_Q  , KC_W  , KC_E  , KC_R  , KC_T  ,KC_LBRC,      KC_SCTR, KC_Y  , KC_U  , KC_I  , KC_O  , KC_P  ,KC_RBRC,
  //|-------+-------+-------+-------+-------+-------+-------|     |-------+-------+-------+-------+-------+-------+-------|
     KC_TAB , KC_A  , KC_S  , KC_D  , KC_F  , KC_G  ,KC_LGUI,      KC_DEL , KC_H  , KC_J  , KC_K  , KC_L  ,KC_SCLN,KC_ENT ,
  //|-------+-------+-------+-------+-------+-------+-------|     |-------+-------+-------+-------+-------+-------+-------|
     LCTL_C , KC_Z  , KC_X  , KC_C  , KC_V  , KC_B  ,ALT_LPR,      ALT_RPR, KC_N , KC_M,  KC_SLSH, KC_COMM, KC_DOT,RCTL_C ,
  //|-------+-------+-------+-------+-------+-------+-------|     |-------+-------+-------+-------+-------+-------+-------|
                                  KC_ESC_NAV,KC_BSPC,                   KC_SP_SHIFT,KC_ENTER_NUM
  // \------------------------------+-------+-------+------/       \------+-------+-------+------------------------------/
  ),

  [_NUMPAD_SYMBOLS] = LAYOUT(
  //,-------+-------+-------+-------+-------+-------+-------.     ,-------+-------+-------+-------+-------+-------+-------.
     _______,KC_AMPR,KC_7   ,KC_8   ,KC_9   ,KC_DQUO,_______,      _______,KC_CIRC,KC_LPRN,KC_RPRN,_______,_______,_______,
  //|-------+-------+-------+-------+-------+-------+-------|     |-------+-------+-------+-------+-------+-------+-------|
     _______,KC_HASH,KC_4   ,KC_5   ,KC_6   ,KC_QUES,_______,      _______,KC_ASTR,KC_PLUS,KC_MINS,_______,_______,_______,
  //|-------+-------+-------+-------+-------+-------+-------|     |-------+-------+-------+-------+-------+-------+-------|
     _______,KC_PIPE,KC_1   ,KC_2   ,KC_3   ,KC_EXLM,_______,      _______,KC_COLN,KC_DLR ,_______,_______,_______,_______,
  //|-------+-------+-------+-------+-------+-------+-------|     |-------+-------+-------+-------+-------+-------+-------|
                                     KC_0   ,_______,                      _______,_______
  // \------------------------------+-------+-------+------/       \------+-------+-------+------------------------------/
  ),

  [_NAV] = LAYOUT(
  //,-------+-------+-------+-------+-------+-------+-------.     ,-------+-------+-------+-------+-------+-------+-------.
     _______,KC_F9  ,KC_F10 ,KC_F11 ,KC_F12 ,KC_PGUP,_______,      _______,KC_HOME,KC_END ,KC_PTAB,KC_NTAB,_______,_______,
  //|-------+-------+-------+-------+-------+-------+-------|     |-------+-------+-------+-------+-------+-------+-------|
     _______,KC_F5  ,KC_F6  ,KC_F7  ,KC_F8  ,KC_PGDN,_______,      _______,KC_LEFT,KC_DOWN, KC_UP ,KC_RGHT,_______,_______,
  //|-------+-------+-------+-------+-------+-------+-------|     |-------+-------+-------+-------+-------+-------+-------|
     _______,KC_F1,  KC_F2  ,KC_F3  ,KC_F4  ,_______,_______,      _______,ALT_TAB,KC_PWRD,KC_NWRD,KC_PSCR,KC_CAD ,_______,
  //|-------+-------+-------+-------+-------+-------+-------|     |-------+-------+-------+-------+-------+-------+-------|
                                     _______,_______,                      _______,_______
  // \------------------------------+-------+-------+------/       \------+-------+-------+------------------------------/
  )
};


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
