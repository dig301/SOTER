################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (9-2020-q2-update)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
S_SRCS += \
../startup/startup_stm32.s 

OBJS += \
./startup/startup_stm32.o 

S_DEPS += \
./startup/startup_stm32.d 


# Each subdirectory must supply rules for building sources it contributes
startup/startup_stm32.o: ../startup/startup_stm32.s startup/subdir.mk
	arm-none-eabi-gcc -mcpu=cortex-m3 -g3 -c -I"M:/STM32CubeIDE_1.6.0/3SO_FreeRTOS.zip_expanded/3SO_FreeRTOS/StdPeriph_Driver/inc" -I"M:/STM32CubeIDE_1.6.0/3SO_FreeRTOS.zip_expanded/3SO_FreeRTOS/CMSIS/core" -I"M:/STM32CubeIDE_1.6.0/3SO_FreeRTOS.zip_expanded/3SO_FreeRTOS/inc" -I"M:/STM32CubeIDE_1.6.0/3SO_FreeRTOS.zip_expanded/3SO_FreeRTOS/CMSIS/device" -I"M:/STM32CubeIDE_1.6.0/3SO_FreeRTOS.zip_expanded/3SO_FreeRTOS/FreeRTOS/include" -x assembler-with-cpp -MMD -MP -MF"startup/startup_stm32.d" -MT"$@" --specs=nano.specs -mfloat-abi=soft -mthumb -o "$@" "$<"

