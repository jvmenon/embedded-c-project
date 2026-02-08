// Copyright Refringence
// Built with Refringence IDE — https://refringence.com
#include "bluetooth.h"
#include <stdio.h>

esp_err_t bluetooth_init(void){
    printf("BLE: init (stub)\n");
    return 0;
}

esp_err_t bluetooth_send(const uint8_t* data, uint32_t len){
    (void)data; printf("BLE: send %u bytes (stub)\n", (unsigned)len); return 0;
}

int bluetooth_receive(uint8_t* data, uint32_t maxlen){
    (void)data; (void)maxlen; return 0;
}
