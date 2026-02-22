################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (9-2020-q2-update)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../FreeRTOS/croutine.c \
../FreeRTOS/event_groups.c \
../FreeRTOS/heap_2.c \
../FreeRTOS/list.c \
../FreeRTOS/port.c \
../FreeRTOS/queue.c \
../FreeRTOS/stream_buffer.c \
../FreeRTOS/tasks.c \
../FreeRTOS/timers.c 

OBJS += \
./FreeRTOS/croutine.o \
./FreeRTOS/event_groups.o \
./FreeRTOS/heap_2.o \
./FreeRTOS/list.o \
./FreeRTOS/port.o \
./FreeRTOS/queue.o \
./FreeRTOS/stream_buffer.o \
./FreeRTOS/tasks.o \
./FreeRTOS/timers.o 

C_DEPS += \
./FreeRTOS/croutine.d \
./FreeRTOS/event_groups.d \
./FreeRTOS/heap_2.d \
./FreeRTOS/list.d \
./FreeRTOS/port.d \
./FreeRTOS/queue.d \
./FreeRTOS/stream_buffer.d \
./FreeRTOS/tasks.d \
./FreeRTOS/timers.d 


# Each subdirectory must supply rules for building sources it contributes
FreeRTOS/croutine.o: ../FreeRTOS/croutine.c FreeRTOS/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m3 -std=gnu11 -g3 -DSTM32F1 -DSTM32F103RBTx -DSTM32 -DDEBUG -DUSE_STDPERIPH_DRIVER -DSTM32F10X_MD -c -I"M:/STM32CubeIDE_1.6.0/3SO_FreeRTOS.zip_expanded/3SO_FreeRTOS/inc" -I"M:/STM32CubeIDE_1.6.0/3SO_FreeRTOS.zip_expanded/3SO_FreeRTOS/StdPeriph_Driver/inc" -I"M:/STM32CubeIDE_1.6.0/3SO_FreeRTOS.zip_expanded/3SO_FreeRTOS/CMSIS/core" -I"M:/STM32CubeIDE_1.6.0/3SO_FreeRTOS.zip_expanded/3SO_FreeRTOS/CMSIS/device" -I"M:/STM32CubeIDE_1.6.0/3SO_FreeRTOS.zip_expanded/3SO_FreeRTOS/FreeRTOS/include" -Os -ffunction-sections -Wall -fstack-usage -MMD -MP -MF"FreeRTOS/croutine.d" -MT"$@" --specs=nano.specs -mfloat-abi=soft -mthumb -o "$@"
FreeRTOS/event_groups.o: ../FreeRTOS/event_groups.c FreeRTOS/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m3 -std=gnu11 -g3 -DSTM32F1 -DSTM32F103RBTx -DSTM32 -DDEBUG -DUSE_STDPERIPH_DRIVER -DSTM32F10X_MD -c -I"M:/STM32CubeIDE_1.6.0/3SO_FreeRTOS.zip_expanded/3SO_FreeRTOS/inc" -I"M:/STM32CubeIDE_1.6.0/3SO_FreeRTOS.zip_expanded/3SO_FreeRTOS/StdPeriph_Driver/inc" -I"M:/STM32CubeIDE_1.6.0/3SO_FreeRTOS.zip_expanded/3SO_FreeRTOS/CMSIS/core" -I"M:/STM32CubeIDE_1.6.0/3SO_FreeRTOS.zip_expanded/3SO_FreeRTOS/CMSIS/device" -I"M:/STM32CubeIDE_1.6.0/3SO_FreeRTOS.zip_expanded/3SO_FreeRTOS/FreeRTOS/include" -Os -ffunction-sections -Wall -fstack-usage -MMD -MP -MF"FreeRTOS/event_groups.d" -MT"$@" --specs=nano.specs -mfloat-abi=soft -mthumb -o "$@"
FreeRTOS/heap_2.o: ../FreeRTOS/heap_2.c FreeRTOS/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m3 -std=gnu11 -g3 -DSTM32F1 -DSTM32F103RBTx -DSTM32 -DDEBUG -DUSE_STDPERIPH_DRIVER -DSTM32F10X_MD -c -I"M:/STM32CubeIDE_1.6.0/3SO_FreeRTOS.zip_expanded/3SO_FreeRTOS/inc" -I"M:/STM32CubeIDE_1.6.0/3SO_FreeRTOS.zip_expanded/3SO_FreeRTOS/StdPeriph_Driver/inc" -I"M:/STM32CubeIDE_1.6.0/3SO_FreeRTOS.zip_expanded/3SO_FreeRTOS/CMSIS/core" -I"M:/STM32CubeIDE_1.6.0/3SO_FreeRTOS.zip_expanded/3SO_FreeRTOS/CMSIS/device" -I"M:/STM32CubeIDE_1.6.0/3SO_FreeRTOS.zip_expanded/3SO_FreeRTOS/FreeRTOS/include" -Os -ffunction-sections -Wall -fstack-usage -MMD -MP -MF"FreeRTOS/heap_2.d" -MT"$@" --specs=nano.specs -mfloat-abi=soft -mthumb -o "$@"
FreeRTOS/list.o: ../FreeRTOS/list.c FreeRTOS/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m3 -std=gnu11 -g3 -DSTM32F1 -DSTM32F103RBTx -DSTM32 -DDEBUG -DUSE_STDPERIPH_DRIVER -DSTM32F10X_MD -c -I"M:/STM32CubeIDE_1.6.0/3SO_FreeRTOS.zip_expanded/3SO_FreeRTOS/inc" -I"M:/STM32CubeIDE_1.6.0/3SO_FreeRTOS.zip_expanded/3SO_FreeRTOS/StdPeriph_Driver/inc" -I"M:/STM32CubeIDE_1.6.0/3SO_FreeRTOS.zip_expanded/3SO_FreeRTOS/CMSIS/core" -I"M:/STM32CubeIDE_1.6.0/3SO_FreeRTOS.zip_expanded/3SO_FreeRTOS/CMSIS/device" -I"M:/STM32CubeIDE_1.6.0/3SO_FreeRTOS.zip_expanded/3SO_FreeRTOS/FreeRTOS/include" -Os -ffunction-sections -Wall -fstack-usage -MMD -MP -MF"FreeRTOS/list.d" -MT"$@" --specs=nano.specs -mfloat-abi=soft -mthumb -o "$@"
FreeRTOS/port.o: ../FreeRTOS/port.c FreeRTOS/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m3 -std=gnu11 -g3 -DSTM32F1 -DSTM32F103RBTx -DSTM32 -DDEBUG -DUSE_STDPERIPH_DRIVER -DSTM32F10X_MD -c -I"M:/STM32CubeIDE_1.6.0/3SO_FreeRTOS.zip_expanded/3SO_FreeRTOS/inc" -I"M:/STM32CubeIDE_1.6.0/3SO_FreeRTOS.zip_expanded/3SO_FreeRTOS/StdPeriph_Driver/inc" -I"M:/STM32CubeIDE_1.6.0/3SO_FreeRTOS.zip_expanded/3SO_FreeRTOS/CMSIS/core" -I"M:/STM32CubeIDE_1.6.0/3SO_FreeRTOS.zip_expanded/3SO_FreeRTOS/CMSIS/device" -I"M:/STM32CubeIDE_1.6.0/3SO_FreeRTOS.zip_expanded/3SO_FreeRTOS/FreeRTOS/include" -Os -ffunction-sections -Wall -fstack-usage -MMD -MP -MF"FreeRTOS/port.d" -MT"$@" --specs=nano.specs -mfloat-abi=soft -mthumb -o "$@"
FreeRTOS/queue.o: ../FreeRTOS/queue.c FreeRTOS/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m3 -std=gnu11 -g3 -DSTM32F1 -DSTM32F103RBTx -DSTM32 -DDEBUG -DUSE_STDPERIPH_DRIVER -DSTM32F10X_MD -c -I"M:/STM32CubeIDE_1.6.0/3SO_FreeRTOS.zip_expanded/3SO_FreeRTOS/inc" -I"M:/STM32CubeIDE_1.6.0/3SO_FreeRTOS.zip_expanded/3SO_FreeRTOS/StdPeriph_Driver/inc" -I"M:/STM32CubeIDE_1.6.0/3SO_FreeRTOS.zip_expanded/3SO_FreeRTOS/CMSIS/core" -I"M:/STM32CubeIDE_1.6.0/3SO_FreeRTOS.zip_expanded/3SO_FreeRTOS/CMSIS/device" -I"M:/STM32CubeIDE_1.6.0/3SO_FreeRTOS.zip_expanded/3SO_FreeRTOS/FreeRTOS/include" -Os -ffunction-sections -Wall -fstack-usage -MMD -MP -MF"FreeRTOS/queue.d" -MT"$@" --specs=nano.specs -mfloat-abi=soft -mthumb -o "$@"
FreeRTOS/stream_buffer.o: ../FreeRTOS/stream_buffer.c FreeRTOS/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m3 -std=gnu11 -g3 -DSTM32F1 -DSTM32F103RBTx -DSTM32 -DDEBUG -DUSE_STDPERIPH_DRIVER -DSTM32F10X_MD -c -I"M:/STM32CubeIDE_1.6.0/3SO_FreeRTOS.zip_expanded/3SO_FreeRTOS/inc" -I"M:/STM32CubeIDE_1.6.0/3SO_FreeRTOS.zip_expanded/3SO_FreeRTOS/StdPeriph_Driver/inc" -I"M:/STM32CubeIDE_1.6.0/3SO_FreeRTOS.zip_expanded/3SO_FreeRTOS/CMSIS/core" -I"M:/STM32CubeIDE_1.6.0/3SO_FreeRTOS.zip_expanded/3SO_FreeRTOS/CMSIS/device" -I"M:/STM32CubeIDE_1.6.0/3SO_FreeRTOS.zip_expanded/3SO_FreeRTOS/FreeRTOS/include" -Os -ffunction-sections -Wall -fstack-usage -MMD -MP -MF"FreeRTOS/stream_buffer.d" -MT"$@" --specs=nano.specs -mfloat-abi=soft -mthumb -o "$@"
FreeRTOS/tasks.o: ../FreeRTOS/tasks.c FreeRTOS/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m3 -std=gnu11 -g3 -DSTM32F1 -DSTM32F103RBTx -DSTM32 -DDEBUG -DUSE_STDPERIPH_DRIVER -DSTM32F10X_MD -c -I"M:/STM32CubeIDE_1.6.0/3SO_FreeRTOS.zip_expanded/3SO_FreeRTOS/inc" -I"M:/STM32CubeIDE_1.6.0/3SO_FreeRTOS.zip_expanded/3SO_FreeRTOS/StdPeriph_Driver/inc" -I"M:/STM32CubeIDE_1.6.0/3SO_FreeRTOS.zip_expanded/3SO_FreeRTOS/CMSIS/core" -I"M:/STM32CubeIDE_1.6.0/3SO_FreeRTOS.zip_expanded/3SO_FreeRTOS/CMSIS/device" -I"M:/STM32CubeIDE_1.6.0/3SO_FreeRTOS.zip_expanded/3SO_FreeRTOS/FreeRTOS/include" -Os -ffunction-sections -Wall -fstack-usage -MMD -MP -MF"FreeRTOS/tasks.d" -MT"$@" --specs=nano.specs -mfloat-abi=soft -mthumb -o "$@"
FreeRTOS/timers.o: ../FreeRTOS/timers.c FreeRTOS/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m3 -std=gnu11 -g3 -DSTM32F1 -DSTM32F103RBTx -DSTM32 -DDEBUG -DUSE_STDPERIPH_DRIVER -DSTM32F10X_MD -c -I"M:/STM32CubeIDE_1.6.0/3SO_FreeRTOS.zip_expanded/3SO_FreeRTOS/inc" -I"M:/STM32CubeIDE_1.6.0/3SO_FreeRTOS.zip_expanded/3SO_FreeRTOS/StdPeriph_Driver/inc" -I"M:/STM32CubeIDE_1.6.0/3SO_FreeRTOS.zip_expanded/3SO_FreeRTOS/CMSIS/core" -I"M:/STM32CubeIDE_1.6.0/3SO_FreeRTOS.zip_expanded/3SO_FreeRTOS/CMSIS/device" -I"M:/STM32CubeIDE_1.6.0/3SO_FreeRTOS.zip_expanded/3SO_FreeRTOS/FreeRTOS/include" -Os -ffunction-sections -Wall -fstack-usage -MMD -MP -MF"FreeRTOS/timers.d" -MT"$@" --specs=nano.specs -mfloat-abi=soft -mthumb -o "$@"

