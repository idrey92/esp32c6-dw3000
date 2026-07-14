idf_component_register(
    SRCS
        "src/dw3000.c"
        "src/dw3000_regs.c"
        "src/dw3000_reg.c"
        "platform/spi/spi.c"
        "platform/gpio/gpio.c"

    INCLUDE_DIRS
        "include"
        "platform/spi"
        "platform/gpio"
    REQUIRES
        esp_driver_spi
        esp_driver_gpio    
)