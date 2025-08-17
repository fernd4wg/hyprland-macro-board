#include QMK_KEYBOARD_H
#include "timer.h"

// #define OLED_TIMEOUT 10000

uint16_t last_input_time = 0;
layer_state_t last_layer_state = 0;

enum layerNames {
  _HYPRLAND,
  _VIM,
  _GENERAL, // general & browser
  _FN,
  _NUMPAD,
  _NUM_LAYERS
};

// cusotm keycode for cycling through layers
enum custom_keycodes {
    CYCLE_LAYER = SAFE_RANGE,
};

layer_state_t layer_state_set_user(layer_state_t state) {
    if (get_highest_layer(state) != get_highest_layer(last_layer_state)) {
        last_input_time = timer_read();
        last_layer_state = state;
    }
    return state;
}

#if defined(ENCODER_MAP_ENABLE)
    const uint16_t PROGMEM encoder_map[][NUM_ENCODERS][NUM_DIRECTIONS] = {
        [0] = { ENCODER_CCW_CW(KC_VOLD, KC_VOLU) },
        [1] = { ENCODER_CCW_CW(KC_VOLD, KC_VOLU) },
        [2] = { ENCODER_CCW_CW(KC_VOLD, KC_VOLU) },
        [3] = { ENCODER_CCW_CW(KC_VOLD, KC_VOLU) },
        [4] = { ENCODER_CCW_CW(KC_VOLD, KC_VOLU) },
    };
#endif

#ifdef OLED_ENABLE
// rotate led because its upside down
oled_rotation_t oled_init_user(oled_rotation_t rotation) {
    return OLED_ROTATION_180;
}

bool oled_task_user(void) {
    oled_write_ln_P(PSTR("Hello, OLED!"), false);
    return false;
}
#endif

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  // HYPRLAND LAYOUT
  [_HYPRLAND] = LAYOUT(
    CYCLE_LAYER, XXXXXXX, XXXXXXX, // cycle to next layer
    G(KC_F), G(KC_SPC), G(KC_C),
    G(KC_Q), G(KC_B), G(KC_D),
    G(KC_COMM), G(KC_UP), G(KC_DOT),
    G(KC_LEFT), G(KC_DOWN), G(KC_RIGHT)
  ),
  // VIM LAYOUT
  [_VIM] = LAYOUT(
    CYCLE_LAYER, XXXXXXX, XXXXXXX, // cycle to next layer
    KC_ESC, KC_V, KC_I, // modes: normal, visual, insert
    KC_D, KC_G, KC_SPACE,
    KC_QUOTE, KC_K, KC_RIGHT_BRACKET,
    KC_H, KC_K, KC_L
  ),
  // GENERAL & BROWSER LAYOUT
  [_GENERAL] = LAYOUT(
    CYCLE_LAYER, XXXXXXX, XXXXXXX, // cycle to next layer
    C(KC_C), C(KC_V), C(KC_Z),
    C(KC_T), C(KC_W), C(KC_L),
    C(KC_TAB), C(S(KC_TAB)), C(KC_R),
    C(S(KC_T)),A(KC_LEFT), A(KC_RIGHT)
  ),
  // FUNCTION
  [_FN] = LAYOUT(
    CYCLE_LAYER, XXXXXXX, XXXXXXX, // cycle to next layer
    KC_F1, KC_F2, KC_F3,
    KC_F4, KC_F5, KC_F6,
    KC_F7, KC_F8, KC_F9,
    KC_F10, KC_F11, KC_F12

  ),
  // NUMPAD
  [_NUMPAD] = LAYOUT(
    CYCLE_LAYER, XXXXXXX, XXXXXXX, // cycle to next layer
    KC_1, KC_2, KC_3,
    KC_4, KC_5, KC_6,
    KC_7, KC_8, KC_9,
    KC_0, KC_DOT, KC_MINS

  )
};

// function to cycle through layers
bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        case CYCLE_LAYER:
            if (record->event.pressed) {
                static uint8_t current_layer = _HYPRLAND;
                current_layer = (current_layer + 1) % _NUM_LAYERS;
                layer_move(current_layer);
            }
        return false;
    }
    return true;
}

