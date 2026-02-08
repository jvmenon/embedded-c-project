// Copyright Refringence
// Built with Refringence IDE — https://refringence.com
#ifndef FREERTOS_FREERTOS_H
#define FREERTOS_FREERTOS_H

#include <stdint.h>

#define pdMS_TO_TICKS(ms) (ms)

typedef uint32_t TickType_t;

typedef void (*TaskFunction_t)(void*);

#endif // FREERTOS_FREERTOS_H
