#pragma once

#include <stdint.h>

#include "driver/gpio.h"
#include "driver/spi_master.h"

typedef struct
{
    spi_host_device_t spi_host;

    gpio_num_t sck;
    gpio_num_t mosi;
    gpio_num_t miso;

    gpio_num_t cs;
    gpio_num_t rst;
    gpio_num_t irq;

    uint32_t spi_speed_hz;

} dw3000_config_t;