CUBE_PROJECT_DIR = ../CubeProject

HAL_C_SOURCES = \
./Src/hal_main.c \
./Src/unused_int.c \
./Src/hal_uart.c \
./Src/system_stm32f7xx.c \
./Src/stm32f7xx_it.c \
./Src/stm32f7xx_hal_msp.c \
./Src/stm32f7xx_hal_timebase_TIM.c \
$(CUBE_PROJECT_DIR)/Drivers/STM32F7xx_HAL_Driver/Src/stm32f7xx_hal_pcd.c \
$(CUBE_PROJECT_DIR)/Drivers/STM32F7xx_HAL_Driver/Src/stm32f7xx_hal_pcd_ex.c \
$(CUBE_PROJECT_DIR)/Drivers/STM32F7xx_HAL_Driver/Src/stm32f7xx_ll_usb.c \
$(CUBE_PROJECT_DIR)/Drivers/STM32F7xx_HAL_Driver/Src/stm32f7xx_hal_cortex.c \
$(CUBE_PROJECT_DIR)/Drivers/STM32F7xx_HAL_Driver/Src/stm32f7xx_hal_dfsdm.c \
$(CUBE_PROJECT_DIR)/Drivers/STM32F7xx_HAL_Driver/Src/stm32f7xx_hal_i2c.c \
$(CUBE_PROJECT_DIR)/Drivers/STM32F7xx_HAL_Driver/Src/stm32f7xx_hal_i2c_ex.c \
$(CUBE_PROJECT_DIR)/Drivers/STM32F7xx_HAL_Driver/Src/stm32f7xx_hal_sai.c \
$(CUBE_PROJECT_DIR)/Drivers/STM32F7xx_HAL_Driver/Src/stm32f7xx_hal_sai_ex.c \
$(CUBE_PROJECT_DIR)/Drivers/STM32F7xx_HAL_Driver/Src/stm32f7xx_ll_sdmmc.c \
$(CUBE_PROJECT_DIR)/Drivers/STM32F7xx_HAL_Driver/Src/stm32f7xx_hal_mmc.c \
$(CUBE_PROJECT_DIR)/Drivers/STM32F7xx_HAL_Driver/Src/stm32f7xx_hal_tim.c \
$(CUBE_PROJECT_DIR)/Drivers/STM32F7xx_HAL_Driver/Src/stm32f7xx_hal_tim_ex.c \
$(CUBE_PROJECT_DIR)/Drivers/STM32F7xx_HAL_Driver/Src/stm32f7xx_hal_rcc.c \
$(CUBE_PROJECT_DIR)/Drivers/STM32F7xx_HAL_Driver/Src/stm32f7xx_hal_rcc_ex.c \
$(CUBE_PROJECT_DIR)/Drivers/STM32F7xx_HAL_Driver/Src/stm32f7xx_hal_flash.c \
$(CUBE_PROJECT_DIR)/Drivers/STM32F7xx_HAL_Driver/Src/stm32f7xx_hal_flash_ex.c \
$(CUBE_PROJECT_DIR)/Drivers/STM32F7xx_HAL_Driver/Src/stm32f7xx_hal_gpio.c \
$(CUBE_PROJECT_DIR)/Drivers/STM32F7xx_HAL_Driver/Src/stm32f7xx_hal_dma.c \
$(CUBE_PROJECT_DIR)/Drivers/STM32F7xx_HAL_Driver/Src/stm32f7xx_hal_dma_ex.c \
$(CUBE_PROJECT_DIR)/Drivers/STM32F7xx_HAL_Driver/Src/stm32f7xx_hal_pwr.c \
$(CUBE_PROJECT_DIR)/Drivers/STM32F7xx_HAL_Driver/Src/stm32f7xx_hal_pwr_ex.c \
$(CUBE_PROJECT_DIR)/Drivers/STM32F7xx_HAL_Driver/Src/stm32f7xx_hal.c \
./Src/usb_device.c \
./Src/usbd_desc.c \
./Src/usbd_cdc_if.c \
./Src/usbd_conf.c \
$(CUBE_PROJECT_DIR)/Middlewares/ST/STM32_USB_Device_Library/Core/Src/usbd_core.c \
$(CUBE_PROJECT_DIR)/Middlewares/ST/STM32_USB_Device_Library/Core/Src/usbd_ctlreq.c \
$(CUBE_PROJECT_DIR)/Middlewares/ST/STM32_USB_Device_Library/Core/Src/usbd_ioreq.c \
$(CUBE_PROJECT_DIR)/Middlewares/ST/STM32_USB_Device_Library/Class/CDC/Src/usbd_cdc.c \
$(CUBE_PROJECT_DIR)/Drivers/STM32F7xx_HAL_Driver/Src/stm32f7xx_hal_uart.c \
$(CUBE_PROJECT_DIR)/startup_stm32f769xx.s

HAL_C_INCLUDES = \
$(CUBE_PROJECT_DIR)/Drivers/CMSIS/Include \
$(CUBE_PROJECT_DIR)/Drivers/CMSIS/Device/ST/STM32F7xx/Include \
$(CUBE_PROJECT_DIR)/Drivers/STM32F7xx_HAL_Driver/Inc \
./Inc \
$(CUBE_PROJECT_DIR)/Middlewares/ST/STM32_USB_Device_Library/Core/Inc \
$(CUBE_PROJECT_DIR)/Middlewares/ST/STM32_USB_Device_Library/Class/CDC/Inc

PROJECT_C_SOURCES = \
./Src/main.cpp \
./Src/sketch.cpp \
./Src/BlinkerPanel.cpp

PROJECT_C_INCLUDES = \
./Inc
