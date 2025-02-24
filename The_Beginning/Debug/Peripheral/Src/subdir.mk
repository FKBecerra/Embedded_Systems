################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (12.3.rel1)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Peripheral/Src/RCC.c 

OBJS += \
./Peripheral/Src/RCC.o 

C_DEPS += \
./Peripheral/Src/RCC.d 


# Each subdirectory must supply rules for building sources it contributes
Peripheral/Src/%.o Peripheral/Src/%.su Peripheral/Src/%.cyclo: ../Peripheral/Src/%.c Peripheral/Src/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -g3 -DDEBUG -DSTM32F429xx -c -I"C:/Users/Engineering/GitHub/Embedded_Systems/The_Beginning/CMSIS/Include" -I"C:/Users/Engineering/GitHub/Embedded_Systems/The_Beginning/Core/Inc" -I"C:/Users/Engineering/GitHub/Embedded_Systems/The_Beginning/Peripheral/Inc" -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"

clean: clean-Peripheral-2f-Src

clean-Peripheral-2f-Src:
	-$(RM) ./Peripheral/Src/RCC.cyclo ./Peripheral/Src/RCC.d ./Peripheral/Src/RCC.o ./Peripheral/Src/RCC.su

.PHONY: clean-Peripheral-2f-Src

