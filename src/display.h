// Copyright Refringence
// Built with Refringence IDE — https://refringence.com
#ifndef DRIVERS_DISPLAY_H
#define DRIVERS_DISPLAY_H

#include <stdint.h>
#include "../include/platform/esp_err.h"

esp_err_t display_init(void);
esp_err_t display_clear(void);
esp_err_t display_print(const char* line1, const char* line2);
esp_err_t display_update(void);

#endif // DRIVERS_DISPLAY_H
