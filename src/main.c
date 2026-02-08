// Copyright Refringence
// Built with Refringence IDE — https://refringence.com
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#include "../include/config.h"
#include "../drivers/humidity.h"
#include "../drivers/barometer.h"
#include "../drivers/display.h"
#include "../drivers/wifi.h"
#include "../drivers/bluetooth.h"
#include "../include/platform/freertos/FreeRTOS.h"
#include "../include/platform/freertos/task.h"
#include "../include/platform/driver/i2c.h"
#include "../include/platform/driver/gpio.h"

static void platform_init(void){
    // Mock I2C init
    i2c_config_t cfg = {
        .mode = 1,
        .sda_io_num = I2C0_SDA_GPIO,
        .scl_io_num = I2C0_SCL_GPIO,
        .sda_pullup_en = 1,
        .scl_pullup_en = 1,
        .master_clk_speed = I2C0_FREQ_HZ
    };
    i2c_param_config(I2C_NUM_0, &cfg);
    i2c_driver_install(I2C_NUM_0, 1, 0, 0, 0);

    // Mock GPIO init
    gpio_set_direction(WS2812_GPIO, GPIO_MODE_OUTPUT);
    gpio_set_direction(BUZZER_GPIO, GPIO_MODE_OUTPUT);
    gpio_set_direction(BUTTON_GPIO, GPIO_MODE_INPUT);
    gpio_pullup_en(BUTTON_GPIO);
}

int main(){
    printf("System initialized\n");

    platform_init();

    // Init peripherals
    humidity_init();
    barometer_init();
    display_init();
    bluetooth_init();
    wifi_init();

    // Simulated Sensor Task
    humidity_data_t h; barometer_data_t b;
    humidity_read(&h);
    barometer_read(&b);

    float co2_ppm = 650.0f; // Placeholder CO2
    float voc_index = 120.0f; // Placeholder VOC index
    int pm1 = 8, pm25 = 12, pm10 = 15; // Placeholder particulate

    printf("Sensor data: T=%.2f RH=%.2f P=%.2f Alt=%.1f CO2=%.0f VOC=%.0f PM1=%d PM2.5=%d PM10=%d\n",
           h.temperature_c, h.humidity_rh, b.pressure_hpa, b.altitude_m,
           co2_ppm, voc_index, pm1, pm25, pm10);

    // Display Task
    char l1[64], l2[64];
    snprintf(l1, sizeof(l1), "T%.1f H%.0f%% P%.0f", h.temperature_c, h.humidity_rh, b.pressure_hpa);
    snprintf(l2, sizeof(l2), "CO2 %.0f VOC %.0f", co2_ppm, voc_index);
    display_clear();
    display_print(l1, l2);
    display_update();

    // MQTT Task
    mqtt_publish_json(MQTT_TOPIC, h.temperature_c, h.humidity_rh, b.pressure_hpa, b.altitude_m,
                      co2_ppm, voc_index, pm1, pm25, pm10);

    // Logging Task (stub)
    printf("LOG: SD write ok (stub)\n");

    // Indicators
    gpio_set_level(WS2812_GPIO, 1);
    gpio_set_level(BUZZER_GPIO, 0);

    printf("Main loop complete\n");
    return 0;
}
