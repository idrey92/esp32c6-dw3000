#include "spi.h"

#include "driver/spi_master.h"
#include "spi.h"

#include "driver/spi_master.h"
#include "dw3000_config.h"
#include <string.h>
#include "gpio.h"

static spi_device_handle_t s_spi = NULL;

esp_err_t dw3000_spi_init(void)
{
    spi_bus_config_t buscfg =
    {
        .mosi_io_num = DW3000_DEFAULT_PIN_MOSI,
        .miso_io_num = DW3000_DEFAULT_PIN_MISO,
        .sclk_io_num = DW3000_DEFAULT_PIN_SCK,

        .quadwp_io_num = -1,
        .quadhd_io_num = -1,

        .max_transfer_sz = 32
    };

    spi_device_interface_config_t devcfg =
    {
        .clock_speed_hz = DW3000_DEFAULT_SPI_SPEED,

        .mode = 0,

        .spics_io_num = -1,

        .queue_size = 1,
    };

    ESP_ERROR_CHECK(spi_bus_initialize(
        DW3000_DEFAULT_SPI_HOST,
        &buscfg,
        SPI_DMA_DISABLED));

    ESP_ERROR_CHECK(spi_bus_add_device(
        DW3000_DEFAULT_SPI_HOST,
        &devcfg,
        &s_spi));

    return ESP_OK;
}

esp_err_t dw3000_spi_transfer(
    const uint8_t *tx,
    uint8_t *rx,
    size_t len)
{
    spi_transaction_t t = {0};

    t.length = len * 8;
    t.tx_buffer = tx;
    t.rx_buffer = rx;

    dw3000_cs_low();

    esp_err_t ret = spi_device_transmit(s_spi, &t);

    dw3000_cs_high();

    return ret;
}


esp_err_t dw3000_spi_deinit(void)
{
    return ESP_OK;
}

esp_err_t dw3000_spi_write(
    const uint8_t *header,
    size_t header_len,
    const uint8_t *body,
    size_t body_len)
{
    spi_transaction_t t = {0};

    size_t len = header_len + body_len;

    uint8_t tx[512];

    memcpy(tx, header, header_len);

    if (body_len)
    {
        memcpy(tx + header_len, body, body_len);
    }

    t.length = len * 8;
    t.tx_buffer = tx;

    dw3000_cs_low();

    esp_err_t ret = spi_device_transmit(s_spi, &t);

    dw3000_cs_high();

    return ret;
}

esp_err_t dw3000_spi_read(
    const uint8_t *header,
    size_t header_len,
    uint8_t *body,
    size_t body_len)
{
    spi_transaction_t t = {0};

    size_t len = header_len + body_len;

    uint8_t tx[512] = {0};
    uint8_t rx[512] = {0};

    memcpy(tx, header, header_len);

    t.length = len * 8;
    t.tx_buffer = tx;
    t.rx_buffer = rx;

    dw3000_cs_low();

    esp_err_t ret = spi_device_transmit(s_spi, &t);

    dw3000_cs_high();

    if (ret == ESP_OK)
    {
        memcpy(body, rx + header_len, body_len);
    }

    return ret;
}

esp_err_t dw3000_spi_set_speed(uint32_t hz)
{
    (void)hz;
    return ESP_OK;
}