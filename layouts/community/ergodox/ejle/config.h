#ifndef CONFIG_H_
#define CONFIG_H_

#include QMK_KEYBOARD_CONFIG_H

#undef TAPPING_TERM
#define TAPPING_TERM 150

#define PREVENT_STUCK_MODIFIERS
#define IGNORE_MOD_TAP_INTERRUPT
#define TAPPING_FORCE_HOLD

// #define PERMISSIVE_HOLD

#endif
