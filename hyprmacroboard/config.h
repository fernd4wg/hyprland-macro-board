#pragma once

// matrix size
#define MATRIX_ROWS 5
#define MATRIX_COLS 3

#define DIODE_DIRECTION COL2ROW

// encoder details
#define NUM_ENCODERS 1
#define NUM_ENCODERS_PER_SIDE 1
#define ENCODERS_A_PINS { F6 }
#define ENCODERS_B_PINS { F7 }
#define ENCODER_RESOLUTION 4

// oled display
#define OLED_DISPLAY_128x32
#define OLED_SDA_PIN D1
#define OLED_SCL_PIN D0

#define MATRIX_ROW_PINS {B1, B3, B2, B6, B5}
#define MATRIX_COL_PINS {F4, F5, B4}

