// Copyright Refringence
// Built with Refringence IDE — https://refringence.com
#ifndef DRIVERS_BLUETOOTH_H
#define DRIVERS_BLUETOOTH_H

#include <stdint.h>
#include <stdbool.h>
#include "../include/platform/esp_err.h"

esp_err_t bluetooth_init(void);
esp_err_t bluetooth_send(const uint8_t* data, uint32_t len);
int bluetooth_receive(uint8_t* data, uint32_t maxlen);

#endif // DRIVERS_BLUETOOTH_H
