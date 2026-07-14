#include "dw3000.h"

#include "spi.h"

esp_err_t dw3000_init(void)
{
    return dw3000_spi_init();
}