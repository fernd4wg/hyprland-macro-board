#include QMK_KEYBOARD_H

enum layerNames {
  _HYPERLAND,
  _VIM,
  _GENERAL, // general & browser
  _FN,
  _NUMPAD
};

#ifdef OLED_ENABLE
static void first(void) {
    static const char PROGMEM hypr[] = {
        // 128 x 32 bit map for hyprland logo or word
    };
  oled_write_P(hypr, false);
}

static void second(void) {
  static const char PROGMEM vim[] = {
      // 128 x 32 bit map for vim logo or word
  };
  oled_write_P(vim, false);
}

static void third(void) {
  static const char PROGMEM general[] = {
      // 128 x 32 bit map for general logo or word
  };
  oled_write_P(third, false);
}

static void fourth(void) {
  static const char PROGMEM fn[] = {
      // 128 x 32 bit map for fn logo or word
  };
  oled_write_P(fn, false);
}

  static void fifth(void) {
  static const char PROGMEM numpad[] = {
      // 128 x 32 bit map for numpad logo or word
  };

    oled_write_P(numpad, true);
}

bool oled_task_user(void) {
  switch (get_highest_layer(layer_state)) {
        case _HYPERLAND:
            // call function to display hypr
            break;
        case _VIM:
            // call function to display vim
            break;
        case _GENERAL:
            // call function to diisplay general
            break;
        case _FN:
            // call function to display fn
            break;
        case _NUMPAD:
            // call function to display numpad
            break;
        default:
            // call function to display idle screen
      return false;
    }
}
#endif

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  // HYPRLAND LAYOUT
  [_HYPERLAND] = LAYOUT(
    TG(_VIM), XXXXXXX, XXXXXXX //toggle next layer
    LGUI(KC_COMM), LGUI(KC_SPC), LGUI(KC_DOT),
    LGUI(KC_Q), LGUI(KC_B), LGUI(KC_D),
    LGUI(KC_COMM), LGUI(KC_UP), LGUI(KC_DOT),
    LGUI(KC_LEFT), LGUI(KC_DOWN), LGUI(KC_RIGHT),
  ),
  // VIM LAYOUT
  [_VIM] = LAYOUT(
    TG(_GENERAL), XXXXXXX, XXXXXXX // toggle next layer
    LCTRL(KC_T), LCTRL(KC_W), LCTRL(),
    LCTL(), LCTL(), LCTRL(),
    LCTRL(), LCTL(), LCTL(),
    LCTL(), LCTL(), LCTL(), 
  )
  // GENERAL & BROWSER LAYOUT
  [_GENERAL] = LAYOUT(
    TG(_FN), XXXXXXX, XXXXXXX // toggle next layer
    _______, _______, _______, 
    _______, _______, _______, 
    _______, _______, _______, 
    _______, _______, _______, 
  )
  // FUNCTION
  [_FN] = LAYOUT(
    TG(_NUMPAD), XXXXXXX, XXXXXXX // toggle next layer
    KC_F1, KC_F2, KC_F3, 
    KC_F4, KC_F5, KC_F6, 
    KC_F7, KC_F8, KC_F9, 
    KC_F10, KC_11, KC_F12, 

  )
  // NUMPAD
  [_NUMPAD] = LAYOUT(
    TG(_HYPERLAND), XXXXXXX, XXXXXXX // toggle next layer
    KC_1, KC_2, KC_3, 
    KC_4, KC_5, KC_6, 
    KC_7, KC_8, KC_9, 
    KC_0, KC_DOT, KC_MINS, 

  )
};
