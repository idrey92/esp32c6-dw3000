#include "dw3000.h"
#include "spi.h"
#include "gpio.h"
#include "esp_log.h"
#include "dw3000_reg.h"

static const char *TAG = "DW3000";

esp_err_t dw3000_init(void)
{
    ESP_LOGI(TAG, "GPIO init");

    ESP_ERROR_CHECK(dw3000_gpio_init());

    ESP_LOGI(TAG, "Hardware reset");

    dw3000_reset();

    ESP_LOGI(TAG, "SPI init");

    ESP_ERROR_CHECK(dw3000_spi_init());

    ESP_LOGI(TAG, "Initialization OK");

    uint32_t devid = dw3000_read_devid();

    ESP_LOGI(TAG, "Chip ID: 0x%08" PRIX32, devid);

    return ESP_OK;
}