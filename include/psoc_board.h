#pragma once

#ifdef __cplusplus
extern "C" {
#endif

#include "stdbool.h"

#include "psoc_ic.h"
#include "psoc_i2s.h"

#define PSOC_BTN_L   GPIO10
#define PSOC_BTN_U   GPIO11
#define PSOC_BTN_D   GPIO12
#define PSOC_BTN_R   GPIO13
#define PSOC_BTN_C   GPIO14
#define PSOC_BTN_SW1 GPIO15

#define PSOC_LED2    GPIO20
#define PSOC_LED3    GPIO21

bool psoc_board_setup(bool force);

#ifdef __cplusplus
}
#endif