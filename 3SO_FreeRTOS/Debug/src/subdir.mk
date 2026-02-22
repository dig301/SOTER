################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (9-2020-q2-update)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../src/lcd.c \
../src/main.c \
../src/stm32f10x_it.c \
../src/syscalls.c 

OBJS += \
./src/lcd.o \
./src/main.o \
./src/stm32f10x_it.o \
./src/syscalls.o 

C_DEPS += \
./src/lcd.d \
./src/main.d \
./src/stm32f10x_it.d \
./src/syscalls.d 


# Each subdirectory must supply rules for building sources it contributes
src/lcd.o: ../src/lcd.c src/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m3 -std=gnu11 -g3 -DSTM32F1 -DSTM32F103RBTx -DSTM32 -DDEBUG -DUSE_STDPERIPH_DRIVER -DSTM32F10X_MD -c -I"M:/STM32CubeIDE_1.6.0/3SO_FreeRTOS.zip_expanded/3SO_FreeRTOS/inc" -I"M:/STM32CubeIDE_1.6.0/3SO_FreeRTOS.zip_expanded/3SO_FreeRTOS/StdPeriph_Driver/inc" -I"M:/STM32CubeIDE_1.6.0/3SO_FreeRTOS.zip_expanded/3SO_FreeRTOS/CMSIS/core" -I"M:/STM32CubeIDE_1.6.0/3SO_FreeRTOS.zip_expanded/3SO_FreeRTOS/CMSIS/device" -I"M:/STM32CubeIDE_1.6.0/3SO_FreeRTOS.zip_expanded/3SO_FreeRTOS/FreeRTOS/include" -Os -ffunction-sections -Wall -fstack-usage -MMD -MP -MF"src/lcd.d" -MT"$@" --specs=nano.specs -mfloat-abi=soft -mthumb -o "$@"
src/main.o: ../src/main.c src/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m3 -std=gnu11 -g3 -DSTM32F1 -DSTM32F103RBTx -DSTM32 -DDEBUG -DUSE_STDPERIPH_DRIVER -DSTM32F10X_MD -c -I"M:/STM32CubeIDE_1.6.0/3SO_FreeRTOS.zip_expanded/3SO_FreeRTOS/inc" -I"M:/STM32CubeIDE_1.6.0/3SO_FreeRTOS.zip_expanded/3SO_FreeRTOS/StdPeriph_Driver/inc" -I"M:/STM32CubeIDE_1.6.0/3SO_FreeRTOS.zip_expanded/3SO_FreeRTOS/CMSIS/core" -I"M:/STM32CubeIDE_1.6.0/3SO_FreeRTOS.zip_expanded/3SO_FreeRTOS/CMSIS/device" -I"M:/STM32CubeIDE_1.6.0/3SO_FreeRTOS.zip_expanded/3SO_FreeRTOS/FreeRTOS/include" -Os -ffunction-sections -Wall -fstack-usage -MMD -MP -MF"src/main.d" -MT"$@" --specs=nano.specs -mfloat-abi=soft -mthumb -o "$@"
src/stm32f10x_it.o: ../src/stm32f10x_it.c src/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m3 -std=gnu11 -g3 -DSTM32F1 -DSTM32F103RBTx -DSTM32 -DDEBUG -DUSE_STDPERIPH_DRIVER -DSTM32F10X_MD -c -I"M:/STM32CubeIDE_1.6.0/3SO_FreeRTOS.zip_expanded/3SO_FreeRTOS/inc" -I"M:/STM32CubeIDE_1.6.0/3SO_FreeRTOS.zip_expanded/3SO_FreeRTOS/StdPeriph_Driver/inc" -I"M:/STM32CubeIDE_1.6.0/3SO_FreeRTOS.zip_expanded/3SO_FreeRTOS/CMSIS/core" -I"M:/STM32CubeIDE_1.6.0/3SO_FreeRTOS.zip_expanded/3SO_FreeRTOS/CMSIS/device" -I"M:/STM32CubeIDE_1.6.0/3SO_FreeRTOS.zip_expanded/3SO_FreeRTOS/FreeRTOS/include" -Os -ffunction-sections -Wall -fstack-usage -MMD -MP -MF"src/stm32f10x_it.d" -MT"$@" --specs=nano.specs -mfloat-abi=soft -mthumb -o "$@"
src/syscalls.o: ../src/syscalls.c src/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m3 -std=gnu11 -g3 -DSTM32F1 -DSTM32F103RBTx -DSTM32 -DDEBUG -DUSE_STDPERIPH_DRIVER -DSTM32F10X_MD -c -I"M:/STM32CubeIDE_1.6.0/3SO_FreeRTOS.zip_expanded/3SO_FreeRTOS/inc" -I"M:/STM32CubeIDE_1.6.0/3SO_FreeRTOS.zip_expanded/3SO_FreeRTOS/StdPeriph_Driver/inc" -I"M:/STM32CubeIDE_1.6.0/3SO_FreeRTOS.zip_expanded/3SO_FreeRTOS/CMSIS/core" -I"M:/STM32CubeIDE_1.6.0/3SO_FreeRTOS.zip_expanded/3SO_FreeRTOS/CMSIS/device" -I"M:/STM32CubeIDE_1.6.0/3SO_FreeRTOS.zip_expanded/3SO_FreeRTOS/FreeRTOS/include" -Os -ffunction-sections -Wall -fstack-usage -MMD -MP -MF"src/syscalls.d" -MT"$@" --specs=nano.specs -mfloat-abi=soft -mthumb -o "$@"

