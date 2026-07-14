#pragma once

#include <stddef.h>
#include <stdint.h>
#include "esp_err.h"

esp_err_t dw3000_spi_init(void);

esp_err_t dw3000_spi_write(
    const uint8_t *header,
    size_t header_len,
    const uint8_t *body,
    size_t body_len);

esp_err_t dw3000_spi_read(
    const uint8_t *header,
    size_t header_len,
    uint8_t *body,
    size_t body_len);

esp_err_t dw3000_spi_deinit(void);

esp_err_t dw3000_spi_transfer(
    const uint8_t *tx,
    uint8_t *rx,
    size_t len);

esp_err_t dw3000_spi_set_speed(uint32_t hz);