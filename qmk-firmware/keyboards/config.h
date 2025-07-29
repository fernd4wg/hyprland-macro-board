#pragma once

// hardware options
#define VENDOR_ID 0x0002
#define PRODUCT_ID 0x0001
#define DEVICE_VER 0x0000
#define MANUFACTURER "Me"
#define PRODUCT "Board"

// matrix size
#define MATRIX_ROWS 5
#define MATRIX_COLS 3

#define DIODE_PROTECTION COL2ROW

// oled display 
#define OLED_DISPLAY_128x32
// #define OLED_TIMEOUT 60000

#define OLED_SDA_PIN D1
#define OLED_SCL_PIN D0

#define MATRIX_ROW_PINS {B1, B3, B2, B6, B5}
#define MATRIX_COLS_PINS {F4, F5, B4}


