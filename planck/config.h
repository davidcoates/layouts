#pragma once

#ifdef AUDIO_ENABLE
#define STARTUP_SONG SONG(PLANCK_SOUND)
#endif

#define MIDI_BASIC

#define ENCODER_RESOLUTION 4

/*
  Set any config.h overrides for your specific keymap here.
  See config.h options at https://docs.qmk.fm/#/config_options?id=the-configh-file
*/

#define ORYX_CONFIGURATOR
#undef RGB_MATRIX_TIMEOUT
#define RGB_MATRIX_TIMEOUT 600000

#define USB_SUSPEND_WAKEUP_DELAY 0
#undef MOUSEKEY_INTERVAL
#define MOUSEKEY_INTERVAL 10

#undef MOUSEKEY_DELAY
#define MOUSEKEY_DELAY 15

#undef MOUSEKEY_MAX_SPEED
#define MOUSEKEY_MAX_SPEED 10

#define FIRMWARE_VERSION u8"eqnJJ/B5pgw"
#define RAW_USAGE_PAGE 0xFF60
#define RAW_USAGE_ID 0x61
#define LAYER_STATE_16BIT

#define RGB_MATRIX_STARTUP_SPD 60

