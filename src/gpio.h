// Copyright Refringence
// Built with Refringence IDE — https://refringence.com
#ifndef DRIVER_GPIO_H
#define DRIVER_GPIO_H

#include <stdint.h>
#include <stdio.h>

typedef int gpio_num_t;

typedef enum { GPIO_MODE_DISABLE=0, GPIO_MODE_INPUT=1, GPIO_MODE_OUTPUT=2 } gpio_mode_t;

typedef enum { GPIO_PULLUP_DISABLE=0, GPIO_PULLUP_ENABLE=1 } gpio_pullup_t;

typedef enum { GPIO_PULLDOWN_DISABLE=0, GPIO_PULLDOWN_ENABLE=1 } gpio_pulldown_t;

static inline void gpio_set_direction(gpio_num_t pin, gpio_mode_t mode){
    printf("GPIO: pin %d mode %d\n", pin, mode);
}
static inline void gpio_set_level(gpio_num_t pin, int level){
    printf("GPIO: pin %d level %d\n", pin, level);
}
static inline void gpio_pullup_en(gpio_num_t pin){ printf("GPIO: pin %d pullup on\n", pin); }
static inline void gpio_pulldown_en(gpio_num_t pin){ printf("GPIO: pin %d pulldown on\n", pin); }

static inline int gpio_get_level(gpio_num_t pin){ (void)pin; return 1; }

#endif // DRIVER_GPIO_H
