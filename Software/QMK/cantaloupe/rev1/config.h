#pragma once

/* USB Device descriptor parameter */
#define VENDOR_ID       0x1234
#define PRODUCT_ID      0x5678
#define DEVICE_VER      0x9ABC
#define MANUFACTURER    Aria
#define PRODUCT         Cantaloupe
#define DESCRIPTION     Split 60-key vertical stagger keyboard

/* key matrix size */
// Rows are doubled-up
#define MATRIX_ROWS 10
#define MATRIX_COLS 7

// wiring of each half
#define MATRIX_ROW_PINS         { D3, B6, B2, B3, B1 }
#define MATRIX_COL_PINS         { D4, C6, D7, E6, B4, B5, F5 }
#define MATRIX_ROW_PINS_RIGHT   { F4, B5, B4, E6, D7 }
#define MATRIX_COL_PINS_RIGHT   { F5, F6, F7, B1, B3, B2, D3 }

/* COL2ROW or ROW2COL */
#define DIODE_DIRECTION COL2ROW

/* Set 0 if debouncing isn't needed */
#define DEBOUNCE 5
#define SOFT_SERIAL_PIN D2
//#define USE_I2C

/* Mechanical locking support. Use KC_LCAP, KC_LNUM or KC_LSCR instead in keymap */
#define LOCKING_SUPPORT_ENABLE
/* Locking resynchronize hack */
#define LOCKING_RESYNC_ENABLE

#define ENCODERS_PAD_A { F6 }
#define ENCODERS_PAD_B { F7 }
#define ENCODERS_PAD_A_RIGHT { D4 }
#define ENCODERS_PAD_B_RIGHT { C6 }

/* Select hand configuration */
// #define MASTER_LEFT
// #define MASTER_RIGHT
#define EE_HANDS