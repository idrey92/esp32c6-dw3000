idf_component_register(
    SRCS
        "src/dw3000.c"
        "platform/spi/spi.c"

    INCLUDE_DIRS
        "include"
        "platform/spi"
    REQUIRES
        esp_driver_spi
        esp_driver_gpio    
)