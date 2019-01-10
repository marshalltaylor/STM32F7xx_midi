CUBE_PROJECT_DIR = ../CubeProject

HAL_C_SOURCES = \
./Src/hal_main.c \
./Src/hal_uart.c \
./Src/stm32f4xx_it.c \
./Src/stm32f4xx_hal_msp.c \
$(CUBE_PROJECT_DIR)/Drivers/STM32F4xx_HAL_Driver/Src/stm32f4xx_hal_tim.c \
$(CUBE_PROJECT_DIR)/Drivers/STM32F4xx_HAL_Driver/Src/stm32f4xx_hal_tim_ex.c \
$(CUBE_PROJECT_DIR)/Drivers/STM32F4xx_HAL_Driver/Src/stm32f4xx_hal_uart.c \
$(CUBE_PROJECT_DIR)/Drivers/STM32F4xx_HAL_Driver/Src/stm32f4xx_hal_rcc.c \
$(CUBE_PROJECT_DIR)/Drivers/STM32F4xx_HAL_Driver/Src/stm32f4xx_hal_rcc_ex.c \
$(CUBE_PROJECT_DIR)/Drivers/STM32F4xx_HAL_Driver/Src/stm32f4xx_hal_flash.c \
$(CUBE_PROJECT_DIR)/Drivers/STM32F4xx_HAL_Driver/Src/stm32f4xx_hal_flash_ex.c \
$(CUBE_PROJECT_DIR)/Drivers/STM32F4xx_HAL_Driver/Src/stm32f4xx_hal_flash_ramfunc.c \
$(CUBE_PROJECT_DIR)/Drivers/STM32F4xx_HAL_Driver/Src/stm32f4xx_hal_gpio.c \
$(CUBE_PROJECT_DIR)/Drivers/STM32F4xx_HAL_Driver/Src/stm32f4xx_hal_dma_ex.c \
$(CUBE_PROJECT_DIR)/Drivers/STM32F4xx_HAL_Driver/Src/stm32f4xx_hal_dma.c \
$(CUBE_PROJECT_DIR)/Drivers/STM32F4xx_HAL_Driver/Src/stm32f4xx_hal_pwr.c \
$(CUBE_PROJECT_DIR)/Drivers/STM32F4xx_HAL_Driver/Src/stm32f4xx_hal_pwr_ex.c \
$(CUBE_PROJECT_DIR)/Drivers/STM32F4xx_HAL_Driver/Src/stm32f4xx_hal_cortex.c \
$(CUBE_PROJECT_DIR)/Drivers/STM32F4xx_HAL_Driver/Src/stm32f4xx_hal.c \
./Src/system_stm32f4xx.c

HAL_C_INCLUDES = \
$(CUBE_PROJECT_DIR)/Drivers/CMSIS/Include \
$(CUBE_PROJECT_DIR)/Drivers/CMSIS/Device/ST/STM32F4xx/Include \
$(CUBE_PROJECT_DIR)/Drivers/STM32F4xx_HAL_Driver/Inc \
./Inc


PROJECT_C_SOURCES = \
./Src/main.cpp \
./Src/sketch.cpp \
./Src/BlinkerPanel.cpp

PROJECT_C_INCLUDES = \
./Inc
