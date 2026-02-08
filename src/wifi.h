// Copyright Refringence
// Built with Refringence IDE — https://refringence.com
#ifndef DRIVERS_WIFI_H
#define DRIVERS_WIFI_H

#include <stdint.h>
#include <stdbool.h>
#include "../include/platform/esp_err.h"

esp_err_t wifi_init(void);
esp_err_t wifi_send(const uint8_t* data, uint32_t len);
int wifi_receive(uint8_t* data, uint32_t maxlen);

// MQTT helper
esp_err_t mqtt_publish_json(const char* topic,
                            float temp_c, float rh_pct,
                            float press_hpa, float altitude_m,
                            float co2_ppm, float voc_index,
                            int pm10, int pm25, int pm100);

#endif // DRIVERS_WIFI_H
