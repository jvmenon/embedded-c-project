// Copyright Refringence
// Built with Refringence IDE — https://refringence.com
#ifndef DRIVERS_BAROMETER_H
#define DRIVERS_BAROMETER_H

#include <stdint.h>
#include <stdbool.h>
#include "../include/platform/esp_err.h"

typedef struct {
    float temperature_c;
    float pressure_hpa;
    float altitude_m;
} barometer_data_t;

esp_err_t barometer_init(void);
esp_err_t barometer_read(barometer_data_t* out);

#endif // DRIVERS_BAROMOMETER_H
