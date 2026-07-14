#pragma once

#include <stddef.h>
#include <stdint.h>

#include "esp_err.h"

esp_err_t dw3000_spi_init(void);
esp_err_t dw3000_spi_deinit(void);

esp_err_t dw3000_spi_transfer(
    const uint8_t *tx,
    uint8_t *rx,
    size_t len);