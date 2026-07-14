#include "deca_port.h"
#include "spi.h"
#include "esp_err.h"
#include "esp_log.h"

static const char *TAG = "DECA_PORT";

int readfromspi(
    uint16_t headerLength,
    const uint8_t *headerBuffer,
    uint32_t readLength,
    uint8_t *readBuffer)
{
    return (dw3000_spi_read(
        headerBuffer,
        headerLength,
        readBuffer,
        readLength) == ESP_OK) ? 0 : -1;
}
int writetospi(
    uint16_t headerLength,
    const uint8_t *headerBuffer,
    uint32_t bodyLength,
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