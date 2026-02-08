// Copyright Refringence
// Built with Refringence IDE — https://refringence.com
#include "barometer.h"
#include "../include/platform/driver/i2c.h"
#include "../include/config.h"
#include <stdio.h>
#include <math.h>

// Minimal BMP280 mock: produce deterministic values and compute altitude

esp_err_t barometer_init(void){
    printf("BMP280: init ok @0x%02X\n", I2C_ADDR_BMP280);
    return ESP_OK;
}

esp_err_t barometer_read(barometer_data_t* out){
    if (!out) return ESP_FAIL;
    // Deterministic mock values
    float temp_c = 24.50f;
    float press_hpa = 1008.30f; // slightly below sea level
    // Barometric formula (approx): h = 44330 * (1 - (P/Po)^(1/5.255))
    float altitude = 44330.0f * (1.0f - powf(press_hpa / SEA_LEVEL_HPA, 0.19029495f));

    out->temperature_c = temp_c;
    out->pressure_hpa = press_hpa;
    out->altitude_m = altitude;

    printf("BMP280: T=%.2fC P=%.2fhPa Alt=%.1fm\n", temp_c, press_hpa, altitude);
    return ESP_OK;
}
