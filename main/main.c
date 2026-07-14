#include "freertos/FreeRTOS.h"
#include "freertos/task.h"

#include "esp_log.h"
#include "esp_err.h"

#include "dw3000.h"

#include "deca_device_api.h"
#include "deca_interface.h"
#include "deca_port.h"

#include "gpio.h"

static const char *TAG = "MAIN";

extern const struct dwt_driver_s dw3000_driver;
extern struct dwt_spi_s g_dwt_spi;

static struct dwt_driver_s *driver_list[] =
{
    (struct dwt_driver_s *)&dw3000_driver
};

void app_main(void)
{
    ESP_ERROR_CHECK(dw3000_init());

    struct dwt_probe_s probe =
    {
        .dw = NULL,
        .spi = &g_dwt_spi,
        .wakeup_device_with_io = dw3000_reset,
        .driver_list = driver_list,
        .dw_driver_num = 1,
    };

    int32_t rc = dwt_probe(&probe);

    ESP_LOGI(TAG, "dwt_probe() = %ld", (long)rc);

    if (rc == DWT_SUCCESS)
    {
        uint32_t id = dwt_readdevid();
        ESP_LOGI(TAG, "DEV_ID = 0x%08lX", (unsigned long)id);
    }

    while (1)
    {
        vTaskDelay(pdMS_TO_TICKS(1000));
    }
}