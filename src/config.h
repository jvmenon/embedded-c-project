// Copyright Refringence
// Built with Refringence IDE — https://refringence.com
#ifndef CONFIG_H
#define CONFIG_H

#include <stdio.h>
#include <stdint.h>
#include <stdbool.h>

// ===== Pin assignments (ESP32-S3 suggested) =====
// I2C0 bus (sensors + OLED)
#define I2C0_SDA_GPIO   8
#define I2C0_SCL_GPIO   9
#define I2C0_FREQ_HZ    100000

// SPI (SD card over SPI)
#define SPI_SCLK_GPIO   36
#define SPI_MISO_GPIO   37
#define SPI_MOSI_GPIO   35
#define SPI_CS_SD_GPIO  34

// UART2 for PMS5003 (sensor to ESP32 RX)
#define UART_PMS_RX_GPIO 18
#define UART_PMS_TX_GPIO 17
#define UART_PMS_BAUD    9600

// WS2812 LED and Buzzer PWM
#define WS2812_GPIO     16
#define BUZZER_GPIO     15

// Button (active low, with internal pull-up)
#define BUTTON_GPIO     0

// ===== Device I2C addresses =====
#define I2C_ADDR_SCD41  0x62
#define I2C_ADDR_SGP40  0x59
#define I2C_ADDR_SHT40  0x44
#define I2C_ADDR_BMP280 0x76
#define I2C_ADDR_SH1106 0x3C

// ===== WiFi/MQTT Settings =====
#define WIFI_SSID       "YOUR_SSID"
#define WIFI_PASS       "YOUR_PASSWORD"

#define MQTT_BROKER     "mqtt.example.com"
#define MQTT_PORT       1883
#define MQTT_TOPIC      "room/air_quality"

// ===== Misc constants =====
#define SEA_LEVEL_HPA   1013.25f

#endif // CONFIG_H
