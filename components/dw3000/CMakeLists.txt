idf_component_register(
    SRCS
        "src/dw3000.c"
        "src/dw3000_regs.c"
        "src/dw3000_reg.c"
        "platform/spi/spi.c"
        "platform/gpio/gpio.c"
        "driver/deca_interface.c"
        "driver/dw3000_device.c"

    INCLUDE_DIRS
        "include"
        "driver"
        "platform/spi"
        "platform/gpio"
    REQUIRES
        esp_driver_spi
        esp_driver_gpio    
)

target_compile_options(${COMPONENT_LIB} PRIVATE
    -Wno-error=maybe-uninitialized
)