#pragma once

#include "dw3000_types.h"

#define DW3000_DEFAULT_SPI_HOST SPI2_HOST

#define DW3000_DEFAULT_PIN_SCK   GPIO_NUM_6
#define DW3000_DEFAULT_PIN_MOSI  GPIO_NUM_7
#define DW3000_DEFAULT_PIN_MISO  GPIO_NUM_2

#define DW3000_DEFAULT_PIN_CS    GPIO_NUM_3
#define DW3000_DEFAULT_PIN_RST   GPIO_NUM_11
#define DW3000_DEFAULT_PIN_IRQ   GPIO_NUM_10

#define DW3000_DEFAULT_SPI_SPEED 2000000U

static inline dw3000_config_t dw3000_default_config(void)
{
    dw3000_config_t cfg =
    {
        .spi_host = DW3000_DEFAULT_SPI_HOST,

        .sck  = DW3000_DEFAULT_PIN_SCK,
        .mosi = DW3000_DEFAULT_PIN_MOSI,
        .miso = DW3000_DEFAULT_PIN_MISO,

        .cs  = -1,
        .rst = DW3000_DEFAULT_PIN_RST,
        .irq = DW3000_DEFAULT_PIN_IRQ,

        .spi_speed_hz = DW3000_DEFAULT_SPI_SPEED,
    };

    return cfg;
}