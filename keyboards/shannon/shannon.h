#pragma once

#include "quantum.h"

// 38 keys, split, ortholinear, plus a dedicated palm key per hand.
//
//  X X X X X        X X X X X
//  X X X X X        X X X X X
//  X X X X X        X X X X X
//  P     T T T      T T T     P
//
// P = palm (its own row + column), T = thumb (outer/center/inner).
//
// Arguments are listed in visual reading order (left-to-right across the
// whole board), matching how each row looks physically. Internally they are
// placed into the true electrical matrix: 5 rows/hand (top, home, bottom,
// thumb, palm) x 6 cols/hand (pinky, ring, middle, index, inner, palm), with
// the right hand's rows offset by 5.
#define LAYOUT( \
    L00, L01, L02, L03, L04,      R04, R03, R02, R01, R00, \
    L10, L11, L12, L13, L14,      R14, R13, R12, R11, R10, \
    L20, L21, L22, L23, L24,      R24, R23, R22, R21, R20, \
         L32, L33, L34,                R34, R33, R32, \
    LP,                                                RP \
) { \
    { L00,    L01,    L02,    L03,    L04,    KC_NO }, \
    { L10,    L11,    L12,    L13,    L14,    KC_NO }, \
    { L20,    L21,    L22,    L23,    L24,    KC_NO }, \
    { KC_NO,  KC_NO,  L32,    L33,    L34,    KC_NO }, \
    { KC_NO,  KC_NO,  KC_NO,  KC_NO,  KC_NO,  LP    }, \
    { R00,    R01,    R02,    R03,    R04,    KC_NO }, \
    { R10,    R11,    R12,    R13,    R14,    KC_NO }, \
    { R20,    R21,    R22,    R23,    R24,    KC_NO }, \
    { KC_NO,  KC_NO,  R32,    R33,    R34,    KC_NO }, \
    { KC_NO,  KC_NO,  KC_NO,  KC_NO,  KC_NO,  RP    }, \
}
