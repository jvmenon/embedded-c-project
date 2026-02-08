// Copyright Refringence
// Built with Refringence IDE — https://refringence.com
#ifndef FREERTOS_TASK_H
#define FREERTOS_TASK_H

#include "FreeRTOS.h"
#include <stdio.h>

static inline int xTaskCreate(TaskFunction_t pxTaskCode,
                              const char * const pcName,
                              uint16_t usStackDepth,
                              void *pvParameters,
                              uint32_t uxPriority,
                              void *pvCreatedTask)
{
    (void)pxTaskCode; (void)pcName; (void)usStackDepth; (void)pvParameters; (void)uxPriority; (void)pvCreatedTask;
    // In this mock, tasks are not created; main() will call functions directly
    return 1; // pdPASS
}

static inline void vTaskDelay(TickType_t xTicksToDelay) {
    (void)xTicksToDelay;
}

#endif // FREERTOS_TASK_H
