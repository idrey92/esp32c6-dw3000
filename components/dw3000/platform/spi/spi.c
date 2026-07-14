#include "spi.h"

#include "driver/spi_master.h"
#include "spi.h"

#include "driver/spi_master.h"
#include "dw3000_config.h"

static spi_device_handle_t s_spi = NULL;

esp_err_t dw3000_spi_init(void)
{
    spi_bus_config_t buscfg =
    {
        .mosi_io_num = DW3000_PIN_MOSI,
        .miso_io_num = DW3000_PIN_MISO,
        .sclk_io_num = DW3000_PIN_SCK,

        .quadwp_io_num = -1,
        .quadhd_io_num = -1,

        .max_transfer_sz = 32
    };

    spi_device_interface_config_t devcfg =
    {
        .clock_speed_hz = DW3000_SPI_FREQ_HZ,

        .mode = 0,

        .spics_io_num = DW3000_PIN_CS,

        .queue_size = 1,
    };

    ESP_ERROR_CHECK(spi_bus_initialize(
        DW3000_SPI_HOST,
        &buscfg,
        SPI_DMA_DISABLED));

    ESP_ERROR_CHECK(spi_bus_add_device(
        DW3000_SPI_HOST,
        &devcfg,
        &s_spi));

    return ESP_OK;
}

esp_err_t dw3000_spi_transfer(const uint8_t *tx,
                              uint8_t *rx,
                              size_t len)
{
    return ESP_ERR_NOT_SUPPORTED;
}


esp_err_t dw3000_spi_deinit(void)
{
    return ESP_OK;
}