#include QMK_KEYBOARD_H
#include "eeprom.h"

enum planck_keycodes {
  ST_MACRO_0 = EZ_SAFE_RANGE,
  ST_MACRO_1,
};

#define KC_SCR_SHOT LCTL(LSFT(KC_PSCR))

enum tap_dance_codes {
  DANCE_0,
  DANCE_1,
};

enum planck_layers {
  _BASE,
  _SYMBOL,
  _NUMPAD,
  _CONTROL,
  _GAME,
  _ARROW,
  _MOUSE,
  _FUNCTION,
  _WINDOW,
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  [_BASE] = LAYOUT_planck_grid(
    KC_TAB,         KC_Q,           KC_W,           KC_F,           KC_P,           KC_B,           KC_J,           KC_L,           KC_U,           KC_Y,           KC_QUOTE,       KC_BSPC,
    KC_MINUS,       KC_A,           KC_R,           KC_S,           KC_T,           KC_G,           KC_M,           KC_N,           KC_E,           KC_I,           KC_O,           KC_SCLN,
    TD(DANCE_0),    KC_Z,           KC_X,           KC_C,           KC_D,           KC_V,           KC_K,           KC_H,           KC_COMMA,       KC_DOT,         KC_SLASH,       MO(_ARROW),
    TD(DANCE_1),    TO(_GAME),      KC_LEFT_ALT,    KC_LEFT_CTRL,   OSL(_SYMBOL),   KC_SPACE,       KC_NO,          OSL(_NUMPAD),   KC_LEFT_GUI,    ST_MACRO_0,     ST_MACRO_1,     KC_ENTER
  ),

  [_SYMBOL] = LAYOUT_planck_grid(
    KC_SCR_SHOT,    KC_GRAVE,       KC_TRANSPARENT, KC_PIPE,        KC_ASTR,        KC_TRANSPARENT, KC_TRANSPARENT, KC_BSLS,        KC_CIRC,        KC_TRANSPARENT, KC_DQUO,        KC_TRANSPARENT,
    KC_UNDS,        KC_AT,          KC_AMPR,        KC_LCBR,        KC_RCBR,        KC_LBRC,        KC_RBRC,        KC_LPRN,        KC_RPRN,        KC_EQUAL,       KC_PLUS,        KC_COLN,
    KC_TRANSPARENT, KC_TILD,        KC_EXLM,        KC_PERC,        KC_DLR,         KC_TRANSPARENT, KC_TRANSPARENT, KC_HASH,        KC_LABK,        KC_RABK,        KC_QUES,        KC_TRANSPARENT,
    KC_TRANSPARENT, TO(_BASE),      KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_NO,          MO(_CONTROL),   KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT
  ),

  [_NUMPAD] = LAYOUT_planck_grid(
    KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_7,           KC_8,           KC_9,           KC_0,           KC_TRANSPARENT,
    KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_4,           KC_5,           KC_6,           KC_0,           KC_TRANSPARENT,
    KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_1,           KC_2,           KC_3,           KC_DOT,         MO(_FUNCTION),
    KC_TRANSPARENT, TO(_BASE),      KC_TRANSPARENT, KC_TRANSPARENT, MO(_CONTROL),   KC_TRANSPARENT, KC_NO,          KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT
  ),

  [_CONTROL] = LAYOUT_planck_grid(
    KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,      KC_AUDIO_VOL_UP,   KC_MEDIA_PLAY_PAUSE, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, QK_BOOT,
    KC_TRANSPARENT, KC_TRANSPARENT, KC_MEDIA_PREV_TRACK, KC_AUDIO_VOL_DOWN, KC_MEDIA_NEXT_TRACK, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,
    KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,      KC_TRANSPARENT,    KC_TRANSPARENT,      KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,
    KC_TRANSPARENT, TO(_BASE),      KC_TRANSPARENT,      KC_TRANSPARENT,    KC_TRANSPARENT,      KC_TRANSPARENT, KC_NO,          KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT
  ),

  [_GAME] = LAYOUT_planck_grid(
    KC_TRANSPARENT, KC_TILD,        KC_Q,           KC_W,           KC_E,           KC_R,           KC_T,           KC_Y,           KC_U,           KC_I,           KC_O,           KC_TRANSPARENT,
    KC_TRANSPARENT, KC_LEFT_SHIFT,  KC_A,           KC_S,           KC_D,           KC_F,           KC_G,           KC_H,           KC_J,           KC_K,           KC_L,           KC_TRANSPARENT,
    KC_TRANSPARENT, KC_LEFT_CTRL,   KC_Z,           KC_X,           KC_C,           KC_V,           KC_B,           KC_N,           KC_M,           KC_P,           KC_TRANSPARENT, KC_TRANSPARENT,
    KC_TRANSPARENT, TO(_BASE),      KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_NO,          OSL(_FUNCTION), KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT
  ),

  [_ARROW] = LAYOUT_planck_grid(
    KC_TRANSPARENT, KC_PAGE_UP,     KC_HOME,        KC_UP,          KC_END,         KC_PLUS,        KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,
    KC_TRANSPARENT, KC_PGDN,        KC_LEFT,        KC_DOWN,        KC_RIGHT,       KC_MINUS,       KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,
    KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,
    KC_TRANSPARENT, TO(_BASE),      KC_TRANSPARENT, KC_TRANSPARENT, MO(_WINDOW),    KC_TRANSPARENT, KC_NO,          MO(_MOUSE),     KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT
  ),

  [_MOUSE] = LAYOUT_planck_grid(
    KC_TRANSPARENT, KC_MS_WH_UP,    KC_MS_BTN2,     KC_MS_UP,       KC_MS_BTN1,     KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,
    KC_TRANSPARENT, KC_MS_WH_DOWN,  KC_MS_LEFT,     KC_MS_DOWN,     KC_MS_RIGHT,    KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,
    KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,
    KC_TRANSPARENT, TO(_BASE),      KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_NO,          KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT
  ),

  [_FUNCTION] = LAYOUT_planck_grid(
    KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_F7,          KC_F8,          KC_F9,          KC_F10,         KC_TRANSPARENT,
    KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_F4,          KC_F5,          KC_F6,          KC_F11,         KC_TRANSPARENT,
    KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_F1,          KC_F2,          KC_F3,          KC_F12,         KC_TRANSPARENT,
    KC_TRANSPARENT, TO(_BASE),      KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_NO,          KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT
  ),

  [_WINDOW] = LAYOUT_planck_grid(
    KC_TRANSPARENT, KC_TRANSPARENT, LALT(LCTL(KC_UP)), LGUI(KC_UP),    LALT(LCTL(KC_DOWN)), KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,
    KC_TRANSPARENT, KC_TRANSPARENT, LGUI(KC_LEFT),     LGUI(KC_DOWN),  LGUI(KC_RIGHT),      KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,
    KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,    KC_TRANSPARENT, KC_TRANSPARENT,      KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,
    KC_TRANSPARENT, TO(_BASE),      KC_TRANSPARENT,    KC_TRANSPARENT, KC_TRANSPARENT,      KC_TRANSPARENT, KC_NO,          KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT
  ),

};



extern rgb_config_t rgb_matrix_config;

void keyboard_post_init_user(void) {
  rgb_matrix_enable();
}


const uint8_t PROGMEM ledmap[][RGB_MATRIX_LED_COUNT][3] = {

    [_BASE] = {
      {0,0,255}, {0,0,255}, {0,0,255}, {0,0,255}, {0,0,255}, {0,0,255}, {0,0,255}, {0,0,255}, {0,0,255}, {0,0,255}, {0,0,255}, {0,0,255},
      {0,0,255}, {0,0,255}, {0,0,255}, {0,0,255}, {0,0,255}, {0,0,255}, {0,0,255}, {0,0,255}, {0,0,255}, {0,0,255}, {0,0,255}, {0,0,255},
      {0,0,255}, {0,0,255}, {0,0,255}, {0,0,255}, {0,0,255}, {0,0,255}, {0,0,255}, {0,0,255}, {0,0,255}, {0,0,255}, {0,0,255}, {0,0,255},
      {0,0,255}, {0,0,255}, {0,0,255}, {0,0,255}, {0,0,255}, {0,0,255},            {0,0,255}, {0,0,255}, {0,0,255}, {0,0,255}, {0,0,255}
    },

    [_SYMBOL] = {
      {0,0,0},   {0,0,0},   {0,0,0},   {0,0,0},     {0,0,0},   {0,0,0},   {0,0,0},   {0,0,0},   {0,0,0},   {0,0,0},   {0,0,0},   {0,0,0},
      {0,0,0},   {0,0,0},   {0,0,0},   {0,0,255},   {0,0,0},   {0,0,0},   {0,0,0},   {0,0,0},   {0,0,0},   {0,0,0},   {0,0,0},   {0,0,0},
      {0,0,0},   {0,0,0},   {0,0,0},   {0,0,0},     {0,0,0},   {0,0,0},   {0,0,0},   {0,0,0},   {0,0,0},   {0,0,0},   {0,0,0},   {0,0,0},
      {0,0,0},   {0,0,0},   {0,0,0},   {0,0,0},     {0,0,0},   {0,0,0},              {0,0,0},   {0,0,0},   {0,0,0},   {0,0,0},   {0,0,0}
    },

    [_NUMPAD] = {
      {0,0,0},   {0,0,0},   {0,0,0},   {0,0,0},     {0,0,0},   {0,0,0},   {0,0,0},   {0,0,0},   {0,0,0},   {0,0,0},   {0,0,0},   {0,0,0},
      {0,0,0},   {0,0,0},   {0,0,0},   {0,0,0},     {0,0,0},   {0,0,0},   {0,0,0},   {0,0,255}, {0,0,0},   {0,0,0},   {0,0,0},   {0,0,0},
      {0,0,0},   {0,0,0},   {0,0,0},   {0,0,0},     {0,0,0},   {0,0,0},   {0,0,0},   {0,0,0},   {0,0,0},   {0,0,0},   {0,0,0},   {0,0,0},
      {0,0,0},   {0,0,0},   {0,0,0},   {0,0,0},     {0,0,0},   {0,0,0},              {0,0,0},   {0,0,0},   {0,0,0},   {0,0,0},   {0,0,0}
    },

    [_CONTROL] = {
      {0,0,0},   {0,0,0},   {0,0,0},   {0,0,0},     {0,0,0},   {0,0,0},   {0,0,0},   {0,0,0},   {0,0,0},   {0,0,0},   {0,0,0},   {0,0,0},
      {0,0,0},   {0,0,0},   {0,0,0},   {0,0,0},     {0,0,0},   {0,0,0},   {0,0,0},   {0,0,0},   {0,0,0},   {0,0,0},   {0,0,0},   {0,0,0},
      {0,0,0},   {0,0,0},   {0,0,0},   {0,0,255},   {0,0,0},   {0,0,0},   {0,0,0},   {0,0,0},   {0,0,0},   {0,0,0},   {0,0,0},   {0,0,0},
      {0,0,0},   {0,0,0},   {0,0,0},   {0,0,0},     {0,0,0},   {0,0,0},              {0,0,0},   {0,0,0},   {0,0,0},   {0,0,0},   {0,0,0}
    },

    [_GAME] = {
      {0,0,0},   {0,0,0},   {0,0,0},   {0,0,0},     {0,0,0},   {0,0,0},   {0,0,0},   {0,0,0},   {0,0,0},   {0,0,0},   {0,0,0},   {0,0,0},
      {0,0,0},   {0,0,0},   {0,0,0},   {0,0,0},     {0,0,0},   {0,0,255}, {0,0,0},   {0,0,0},   {0,0,0},   {0,0,0},   {0,0,0},   {0,0,0},
      {0,0,0},   {0,0,0},   {0,0,0},   {0,0,0},     {0,0,0},   {0,0,0},   {0,0,0},   {0,0,0},   {0,0,0},   {0,0,0},   {0,0,0},   {0,0,0},
      {0,0,0},   {0,0,0},   {0,0,0},   {0,0,0},     {0,0,0},   {0,0,0},              {0,0,0},   {0,0,0},   {0,0,0},   {0,0,0},   {0,0,0}
    },

    [_ARROW] = {
      {0,0,0},   {0,0,0},   {0,0,0},   {0,0,0},     {0,0,0},   {0,0,0},   {0,0,0},   {0,0,0},   {0,0,0},   {0,0,0},   {0,0,0},   {0,0,0},
      {0,0,0},   {0,0,255}, {0,0,0},   {0,0,0},     {0,0,0},   {0,0,0},   {0,0,0},   {0,0,0},   {0,0,0},   {0,0,0},   {0,0,0},   {0,0,0},
      {0,0,0},   {0,0,0},   {0,0,0},   {0,0,0},     {0,0,0},   {0,0,0},   {0,0,0},   {0,0,0},   {0,0,0},   {0,0,0},   {0,0,0},   {0,0,0},
      {0,0,0},   {0,0,0},   {0,0,0},   {0,0,0},     {0,0,0},   {0,0,0},              {0,0,0},   {0,0,0},   {0,0,0},   {0,0,0},   {0,0,0}
    },

    [_MOUSE] = {
      {0,0,0},   {0,0,0},   {0,0,0},   {0,0,0},     {0,0,0},   {0,0,0},   {0,0,0},   {0,0,0},   {0,0,0},   {0,0,0},   {0,0,0},   {0,0,0},
      {0,0,0},   {0,0,0},   {0,0,0},   {0,0,0},     {0,0,0},   {0,0,0},   {0,0,255}, {0,0,0},   {0,0,0},   {0,0,0},   {0,0,0},   {0,0,0},
      {0,0,0},   {0,0,0},   {0,0,0},   {0,0,0},     {0,0,0},   {0,0,0},   {0,0,0},   {0,0,0},   {0,0,0},   {0,0,0},   {0,0,0},   {0,0,0},
      {0,0,0},   {0,0,0},   {0,0,0},   {0,0,0},     {0,0,0},   {0,0,0},              {0,0,0},   {0,0,0},   {0,0,0},   {0,0,0},   {0,0,0}
    },

    [_FUNCTION] = {
      {0,0,0},   {0,0,0},   {0,0,0},   {0,0,255},   {0,0,0},   {0,0,0},   {0,0,0},   {0,0,0},   {0,0,0},   {0,0,0},   {0,0,0},   {0,0,0},
      {0,0,0},   {0,0,0},   {0,0,0},   {0,0,0},     {0,0,0},   {0,0,0},   {0,0,0},   {0,0,0},   {0,0,0},   {0,0,0},   {0,0,0},   {0,0,0},
      {0,0,0},   {0,0,0},   {0,0,0},   {0,0,0},     {0,0,0},   {0,0,0},   {0,0,0},   {0,0,0},   {0,0,0},   {0,0,0},   {0,0,0},   {0,0,0},
      {0,0,0},   {0,0,0},   {0,0,0},   {0,0,0},     {0,0,0},   {0,0,0},              {0,0,0},   {0,0,0},   {0,0,0},   {0,0,0},   {0,0,0}
    },

    [_WINDOW] = {
      {0,0,0},   {0,0,0},   {0,0,255}, {0,0,0},     {0,0,0},   {0,0,0},   {0,0,0},   {0,0,0},   {0,0,0},   {0,0,0},   {0,0,0},   {0,0,0},
      {0,0,0},   {0,0,0},   {0,0,0},   {0,0,0},     {0,0,0},   {0,0,0},   {0,0,0},   {0,0,0},   {0,0,0},   {0,0,0},   {0,0,0},   {0,0,0},
      {0,0,0},   {0,0,0},   {0,0,0},   {0,0,0},     {0,0,0},   {0,0,0},   {0,0,0},   {0,0,0},   {0,0,0},   {0,0,0},   {0,0,0},   {0,0,0},
      {0,0,0},   {0,0,0},   {0,0,0},   {0,0,0},     {0,0,0},   {0,0,0},              {0,0,0},   {0,0,0},   {0,0,0},   {0,0,0},   {0,0,0}
    },

};

void set_layer_color(int layer) {
  for (int i = 0; i < RGB_MATRIX_LED_COUNT; i++) {
    HSV hsv = {
      .h = pgm_read_byte(&ledmap[layer][i][0]),
      .s = pgm_read_byte(&ledmap[layer][i][1]),
      .v = pgm_read_byte(&ledmap[layer][i][2]),
    };
    if (!hsv.h && !hsv.s && !hsv.v) {
        rgb_matrix_set_color( i, 0, 0, 0 );
    } else {
        RGB rgb = hsv_to_rgb( hsv );
        float f = (float)rgb_matrix_config.hsv.v / UINT8_MAX;
        rgb_matrix_set_color( i, f * rgb.r, f * rgb.g, f * rgb.b );
    }
  }
}

bool rgb_matrix_indicators_user(void) {
  if (rawhid_state.rgb_control) {
      return false;
  }
  if (keyboard_config.disable_layer_led) { return false; }
  switch (biton32(layer_state)) {
    case _BASE:
      set_layer_color(_BASE);
      break;
    case _SYMBOL:
      set_layer_color(_SYMBOL);
      break;
    case _NUMPAD:
      set_layer_color(_NUMPAD);
      break;
    case _CONTROL:
      set_layer_color(_CONTROL);
      break;
    case _GAME:
      set_layer_color(_GAME);
      break;
    case _ARROW:
      set_layer_color(_ARROW);
      break;
    case _MOUSE:
      set_layer_color(_MOUSE);
      break;
    case _FUNCTION:
      set_layer_color(_FUNCTION);
      break;
    case _WINDOW:
      set_layer_color(_WINDOW);
      break;
   default:
    if (rgb_matrix_get_flags() == LED_FLAG_NONE)
      rgb_matrix_set_color_all(0, 0, 0);
    break;
  }
  return true;
}

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  switch (keycode) {
    case ST_MACRO_0:
    if (record->event.pressed) {
      SEND_STRING(SS_LALT(SS_LCTL(SS_TAP(X_LEFT))));
    }
    break;
    case ST_MACRO_1:
    if (record->event.pressed) {
      SEND_STRING(SS_LALT(SS_LCTL(SS_TAP(X_RIGHT))));
    }
    break;
  }
  return true;
}

typedef struct {
    bool is_press_action;
    uint8_t step;
} tap;

enum {
    SINGLE_TAP = 1,
    SINGLE_HOLD,
    DOUBLE_TAP,
    DOUBLE_HOLD,
    DOUBLE_SINGLE_TAP,
    MORE_TAPS
};

static tap dance_state[2];

uint8_t dance_step(tap_dance_state_t *state);

uint8_t dance_step(tap_dance_state_t *state) {
    if (state->count == 1) {
        if (state->interrupted || !state->pressed) return SINGLE_TAP;
        else return SINGLE_HOLD;
    } else if (state->count == 2) {
        if (state->interrupted) return DOUBLE_SINGLE_TAP;
        else if (state->pressed) return DOUBLE_HOLD;
        else return DOUBLE_TAP;
    }
    return MORE_TAPS;
}


void on_dance_0(tap_dance_state_t *state, void *user_data);
void dance_0_finished(tap_dance_state_t *state, void *user_data);
void dance_0_reset(tap_dance_state_t *state, void *user_data);

void on_dance_0(tap_dance_state_t *state, void *user_data) {
    if(state->count == 3) {
        tap_code16(KC_LEFT_SHIFT);
        tap_code16(KC_LEFT_SHIFT);
        tap_code16(KC_LEFT_SHIFT);
    }
    if(state->count > 3) {
        tap_code16(KC_LEFT_SHIFT);
    }
}

void dance_0_finished(tap_dance_state_t *state, void *user_data) {
    dance_state[0].step = dance_step(state);
    switch (dance_state[0].step) {
        case SINGLE_TAP: register_code16(KC_LEFT_SHIFT); break;
        case SINGLE_HOLD: register_code16(KC_LEFT_SHIFT); break;
        case DOUBLE_TAP: register_code16(KC_CAPS); break;
        case DOUBLE_SINGLE_TAP: tap_code16(KC_LEFT_SHIFT); register_code16(KC_LEFT_SHIFT);
    }
}

void dance_0_reset(tap_dance_state_t *state, void *user_data) {
    wait_ms(10);
    switch (dance_state[0].step) {
        case SINGLE_TAP: unregister_code16(KC_LEFT_SHIFT); break;
        case SINGLE_HOLD: unregister_code16(KC_LEFT_SHIFT); break;
        case DOUBLE_TAP: unregister_code16(KC_CAPS); break;
        case DOUBLE_SINGLE_TAP: unregister_code16(KC_LEFT_SHIFT); break;
    }
    dance_state[0].step = 0;
}
void on_dance_1(tap_dance_state_t *state, void *user_data);
void dance_1_finished(tap_dance_state_t *state, void *user_data);
void dance_1_reset(tap_dance_state_t *state, void *user_data);

void on_dance_1(tap_dance_state_t *state, void *user_data) {
    if(state->count == 3) {
        tap_code16(KC_ESCAPE);
        tap_code16(KC_ESCAPE);
        tap_code16(KC_ESCAPE);
    }
    if(state->count > 3) {
        tap_code16(KC_ESCAPE);
    }
}

void dance_1_finished(tap_dance_state_t *state, void *user_data) {
    dance_state[1].step = dance_step(state);
    switch (dance_state[1].step) {
        case SINGLE_TAP: register_code16(KC_ESCAPE); break;
        case SINGLE_HOLD: register_code16(KC_ESCAPE); break;
        case DOUBLE_TAP: register_code16(KC_DELETE); break;
        case DOUBLE_SINGLE_TAP: tap_code16(KC_ESCAPE); register_code16(KC_ESCAPE);
    }
}

void dance_1_reset(tap_dance_state_t *state, void *user_data) {
    wait_ms(10);
    switch (dance_state[1].step) {
        case SINGLE_TAP: unregister_code16(KC_ESCAPE); break;
        case SINGLE_HOLD: unregister_code16(KC_ESCAPE); break;
        case DOUBLE_TAP: unregister_code16(KC_DELETE); break;
        case DOUBLE_SINGLE_TAP: unregister_code16(KC_ESCAPE); break;
    }
    dance_state[1].step = 0;
}

tap_dance_action_t tap_dance_actions[] = {
        [DANCE_0] = ACTION_TAP_DANCE_FN_ADVANCED(on_dance_0, dance_0_finished, dance_0_reset),
        [DANCE_1] = ACTION_TAP_DANCE_FN_ADVANCED(on_dance_1, dance_1_finished, dance_1_reset),
};
