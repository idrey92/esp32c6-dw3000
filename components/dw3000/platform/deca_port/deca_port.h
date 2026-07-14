#pragma once

#include <stdint.h>
#include "deca_interface.h"
#include "deca_device_api.h"
#include "spi.h"

#ifdef __cplusplus
extern "C" {
#endif


extern dwchip_t g_dw;
extern struct dwt_spi_s g_dwt_spi;

int32_t readfromspi(
    uint16_t headerLength,
    uint8_t *headerBuffer,
    uint16_t readLength,
    uint8_t *readBuffer);

int32_t writetospi(
    uint16_t headerLength,
    const uint8_t *headerBuffer,
    uint16_t bodyLength,
    const uint8_t *bodyBuffer);

void deca_sleep(unsigned int time_ms);

void deca_usleep(unsigned long time_us);

void reset_DWIC(void);

uint32_t portGetTickCnt(void);

#ifdef __cplusplus
}
#endif