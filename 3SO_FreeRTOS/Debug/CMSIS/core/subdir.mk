################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (9-2020-q2-update)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../CMSIS/core/core_cm3.c 

OBJS += \
./CMSIS/core/core_cm3.o 

C_DEPS += \
./CMSIS/core/core_cm3.d 


# Each subdirectory must supply rules for building sources it contributes
CMSIS/core/core_cm3.o: ../CMSIS/core/core_cm3.c CMSIS/core/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m3 -std=gnu11 -g3 -DSTM32F1 -DSTM32F103RBTx -DSTM32 -DDEBUG -DUSE_STDPERIPH_DRIVER -DSTM32F10X_MD -c -I"M:/STM32CubeIDE_1.6.0/3SO_FreeRTOS.zip_expanded/3SO_FreeRTOS/inc" -I"M:/STM32CubeIDE_1.6.0/3SO_FreeRTOS.zip_expanded/3SO_FreeRTOS/StdPeriph_Driver/inc" -I"M:/STM32CubeIDE_1.6.0/3SO_FreeRTOS.zip_expanded/3SO_FreeRTOS/CMSIS/core" -I"M:/STM32CubeIDE_1.6.0/3SO_FreeRTOS.zip_expanded/3SO_FreeRTOS/CMSIS/device" -I"M:/STM32CubeIDE_1.6.0/3SO_FreeRTOS.zip_expanded/3SO_FreeRTOS/FreeRTOS/include" -Os -ffunction-sections -Wall -fstack-usage -MMD -MP -MF"CMSIS/core/core_cm3.d" -MT"$@" --specs=nano.specs -mfloat-abi=soft -mthumb -o "$@"

