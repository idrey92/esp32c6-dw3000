#pragma once

#include "esp_err.h"
#include "dw3000_types.h"

#ifdef __cplusplus
extern "C" {
#endif

//esp_err_t dw3000_init(const dw3000_config_t *cfg);
esp_err_t dw3000_init(void);

#ifdef __cplusplus
}
#endif