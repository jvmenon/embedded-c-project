// Copyright Refringence
// Built with Refringence IDE — https://refringence.com
#include "wifi.h"
#include "../include/config.h"
#include <stdio.h>
#include <string.h>

esp_err_t wifi_init(void){
    printf("WiFi: Station init\n");
    printf("WiFi: Connecting to %s...\n", WIFI_SSID);
    // Deterministic success
    printf("WiFi: Connected (IP 192.168.1.100)\n");
    return 0;
}

esp_err_t wifi_send(const uint8_t* data, uint32_t len){
    printf("WiFi: send %u bytes\n", (unsigned)len);
    (void)data; return 0;
}

int wifi_receive(uint8_t* data, uint32_t maxlen){
    (void)data; (void)maxlen; return 0;
}

esp_err_t mqtt_publish_json(const char* topic,
                            float temp_c, float rh_pct,
                            float press_hpa, float altitude_m,
                            float co2_ppm, float voc_index,
                            int pm10, int pm25, int pm100)
{
    char json[256];
    snprintf(json, sizeof(json),
        "{\"t\":%.2f,\"rh\":%.2f,\"p\":%.2f,\"alt\":%.1f,\"co2\":%.0f,\"voc\":%.0f,\"pm1\":%d,\"pm25\":%d,\"pm10\":%d}",
        temp_c, rh_pct, press_hpa, altitude_m, co2_ppm, voc_index, pm10, pm25, pm100);
    printf("MQTT Publish [%s]: %s\n", topic?topic:MQTT_TOPIC, json);
    return 0;
}
