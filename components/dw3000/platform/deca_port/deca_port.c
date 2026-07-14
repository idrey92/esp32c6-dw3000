#include "deca_port.h"
#include "spi.h"
#include "esp_err.h"
#include "esp_log.h"
#include "deca_interface.h"
#include "freertos/FreeRTOS.h"
#include "freertos/task.h"



static const char *TAG = "DECA_PORT";

dwchip_t g_dw = {0};

int32_t readfromspi(
    uint16_t headerLength,
    uint8_t *headerBuffer,
    uint16_t readLength,
    uint8_t *readBuffer)
{
    return (dw3000_spi_read(
        headerBuffer,
        headerLength,
        readBuffer,
        readLength) == ESP_OK) ? 0 : -1;
}
int32_t writetospi(
    uint16_t headerLength,
    const uint8_t *headerBuffer,
    uint16_t bodyLength,
    const uint8_t *bodyBuffer)
{
    return dw3000_spi_write(
        headerBuffer,
        headerLength,
        bodyBuffer,
        bodyLength
    ) == ESP_OK ? 0 : -1;
}

void deca_sleep(unsigned int time_ms)
{
    (void)time_ms;
}

void deca_usleep(unsigned long time_us)
{
    (void)time_us;
}

void reset_DWIC(void)
{
}

uint32_t portGetTickCnt(void)
{
    return 0;
}

static void spi_set_slow_rate(void)
{
    dw3000_spi_set_speed(2000000);
}

static void spi_set_fast_rate(void)
{
    dw3000_spi_set_speed(20000000);
}

static int32_t writetospiwithcrc(
    uint16_t headerLength,
    const uint8_t *headerBuffer,
    uint16_t bodyLength,
    const uint8_t *bodyBuffer,
    uint8_t crc8)
{
    (void)crc8;

    return writetospi(
        headerLength,
        headerBuffer,
        bodyLength,
        bodyBuffer);
}

struct dwt_spi_s g_dwt_spi =
{
    .readfromspi      = readfromspi,
    .writetospi       = writetospi,
    .writetospiwithcrc= writetospiwithcrc,
    .setslowrate      = spi_set_slow_rate,
    .setfastrate      = spi_set_fast_rate,
};


static portMUX_TYPE dw3000_mux = portMUX_INITIALIZER_UNLOCKED;

decaIrqStatus_t decamutexon(void)
{
    taskENTER_CRITICAL(&dw3000_mux);
    return 0;
}

void decamutexoff(decaIrqStatus_t s)
{
    (void)s;
    taskEXIT_CRITICAL(&dw3000_mux);
}