#pragma once

#include <stdint.h>
#include "spi.h"

#ifdef __cplusplus
extern "C" {
#endif

int readfromspi(
    uint16_t headerLength,
    const uint8_t *headerBuffer,
    uint32_t readLength,
    uint8_t *readBuffer);

int writetospi(
    uint16_t headerLength,
    const uint8_t *headerBuffer,
    uint32_t bodyLength,
    const uint8_t *bodyBuffer);

void deca_sleep(unsigned int time_ms);

void deca_usleep(unsigned long time_us);

void reset_DWIC(void);

uint32_t portGetTickCnt(void);

#ifdef __cplusplus
}
#endif