#include "gpio.h"

#include "driver/gpio.h"
#include "dw3000_config.h"
#include "esp_rom_sys.h"

esp_err_t dw3000_gpio_init(void)
{
    gpio_config_t io =
    {
        .pin_bit_mask =
            (1ULL << DW3000_DEFAULT_PIN_CS) |
            (1ULL << DW3000_DEFAULT_PIN_RST),

        .mode = GPIO_MODE_OUTPUT,

        .pull_up_en = GPIO_PULLUP_DISABLE,
        .pull_down_en = GPIO_PULLDOWN_DISABLE,

        .intr_type = GPIO_INTR_DISABLE
    };

    ESP_ERROR_CHECK(gpio_config(&io));

    gpio_set_level(DW3000_DEFAULT_PIN_CS, 1);
    gpio_set_level(DW3000_DEFAULT_PIN_RST, 1);

    return ESP_OK;
}

void dw3000_cs_low(void)
{
    gpio_set_level(DW3000_DEFAULT_PIN_CS, 0);
}

void dw3000_cs_high(void)
{
    gpio_set_level(DW3000_DEFAULT_PIN_CS, 1);
}

void dw3000_reset_low(void)
{
    gpio_set_level(DW3000_DEFAULT_PIN_RST, 0);
}

void dw3000_reset_high(void)
{
    gpio_set_level(DW3000_DEFAULT_PIN_RST, 1);
}

void dw3000_reset(void)
{
    dw3000_reset_low();

    esp_rom_delay_us(2000);

    dw3000_reset_high();

    esp_rom_delay_us(5000);
}