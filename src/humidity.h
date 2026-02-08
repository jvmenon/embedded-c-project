// Copyright Refringence
// Built with Refringence IDE — https://refringence.com
#ifndef DRIVERS_HUMIDITY_H
#define DRIVERS_HUMIDITY_H

#include <stdint.h>
#include <stdbool.h>
#include "../include/platform/esp_err.h"

typedef struct {
    float temperature_c;
    float humidity_rh;
} humidity_data_t;

esp_err_t humidity_init(void);
esp_err_t humidity_read(humidity_data_t* out);

#endif // DRIVERS_HUMIDITY_H
