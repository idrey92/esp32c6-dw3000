idf_component_register(
    SRCS
        "src/dw3000.c"
        "src/dw3000_regs.c"
        "src/dw3000_reg.c"
        "platform/spi/spi.c"
        "platform/gpio/gpio.c"
        "driver/deca_interface.c"
        "driver/dw3000_device.c"
        "platform/deca_port/deca_port.c"
        "driver/deca_compat.c"
        "driver/deca_rsl.c"

    INCLUDE_DIRS
        "include"
        "driver"
        "platform/spi"
        "platform/gpio"
        "platform/deca_port"
        
    REQUIRES
        esp_driver_spi
        esp_driver_gpio
        qmath    
)

target_compile_options(${COMPONENT_LIB} PRIVATE
    -Wno-error=maybe-uninitialized
)