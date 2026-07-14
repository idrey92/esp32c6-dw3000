#pragma once

#include "esp_err.h"

esp_err_t dw3000_gpio_init(void);

void dw3000_cs_low(void);
void dw3000_cs_high(void);

void dw3000_reset_low(void);
void dw3000_reset_high(void);

void dw3000_reset(void);