#include "dw3000_reg.h"

#include <string.h>

#include "esp_log.h"
#include "spi.h"

#include <inttypes.h>

static const char *TAG = "DW3000";

uint32_t dw3000_read_devid(void)
{
    uint8_t tx[5] = {0};
    uint8_t rx[5] = {0};

    /* Первый байт заголовка:
       бит7 = 0 (чтение)
       бит6 = 0 (без sub-address)
       адрес = 0x00
    */
    tx[0] = 0x00;

    ESP_ERROR_CHECK(dw3000_spi_transfer(tx, rx, sizeof(tx)));

    uint32_t devid =
          ((uint32_t)rx[1]      )
        | ((uint32_t)rx[2] << 8 )
        | ((uint32_t)rx[3] << 16)
        | ((uint32_t)rx[4] << 24);

    ESP_LOGI(TAG, "DEV_ID = 0x%08" PRIX32, devid);

    return devid;
}