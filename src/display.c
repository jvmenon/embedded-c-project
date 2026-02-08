// Copyright Refringence
// Built with Refringence IDE — https://refringence.com
#include "display.h"
#include <stdio.h>
#include <string.h>

static char g_buf1[64];
static char g_buf2[64];

esp_err_t display_init(void){
    printf("SH1106: init ok 128x64 I2C @0x3C\n");
    return 0;
}

esp_err_t display_clear(void){
    g_buf1[0] = '\0';
    g_buf2[0] = '\0';
    printf("DISPLAY: clear\n");
    return 0;
}

esp_err_t display_print(const char* line1, const char* line2){
    strncpy(g_buf1, line1?line1:"", sizeof(g_buf1)-1); g_buf1[sizeof(g_buf1)-1]='\0';
    strncpy(g_buf2, line2?line2:"", sizeof(g_buf2)-1); g_buf2[sizeof(g_buf2)-1]='\0';
    return 0;
}

esp_err_t display_update(void){
    printf("DISPLAY: %s | %s\n", g_buf1, g_buf2);
    return 0;
}
