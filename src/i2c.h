// Copyright Refringence
// Built with Refringence IDE — https://refringence.com
#ifndef DRIVER_I2C_H
#define DRIVER_I2C_H

#include <stdint.h>
#include <stdio.h>
#include "../esp_err.h"

#define I2C_NUM_0 0

typedef int i2c_port_t;

typedef struct {
    int mode;
    int sda_io_num;
    int scl_io_num;
    int sda_pullup_en;
    int scl_pullup_en;
    uint32_t master_clk_speed;
} i2c_config_t;

static inline esp_err_t i2c_param_config(i2c_port_t port, const i2c_config_t* conf){
    (void)port; (void)conf; printf("I2C: param config\n"); return ESP_OK;
}
static inline esp_err_t i2c_driver_install(i2c_port_t port, int mode, int a, int b, int c){
    (void)port; (void)mode; (void)a; (void)b; (void)c; printf("I2C: driver install\n"); return ESP_OK;
}

static inline esp_err_t i2c_master_write_read_device(i2c_port_t port, uint8_t address,
                                                     const uint8_t* write_buffer, size_t write_size,
                                                     uint8_t* read_buffer, size_t read_size,
                                                     uint32_t timeout_ms)
{
    (void)port; (void)address; (void)write_buffer; (void)write_size; (void)timeout_ms;
    // Fill read buffer with deterministic bytes for mocking
    for (size_t i=0; i<read_size; ++i) read_buffer[i] = (uint8_t)(i + 1);
    printf("I2C: W%zu R%zu @0x%02X\n", write_size, read_size, address);
    return ESP_OK;
}

static inline esp_err_t i2c_master_write_to_device(i2c_port_t port, uint8_t address,
                                                   const uint8_t* write_buffer, size_t write_size,
                                                   uint32_t timeout_ms)
{
    (void)port; (void)address; (void)timeout_ms; (void)write_buffer; printf("I2C: W%zu @0x%02X\n", write_size, address);
    return ESP_OK;
}

#endif // DRIVER_I2C_H
