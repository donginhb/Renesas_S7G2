################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../synergy/ssp/src/driver/r_cgc/hw/target/hw_cgc_target.c 

OBJS += \
./synergy/ssp/src/driver/r_cgc/hw/target/hw_cgc_target.o 

C_DEPS += \
./synergy/ssp/src/driver/r_cgc/hw/target/hw_cgc_target.d 


# Each subdirectory must supply rules for building sources it contributes
synergy/ssp/src/driver/r_cgc/hw/target/%.o: ../synergy/ssp/src/driver/r_cgc/hw/target/%.c
	@echo 'Building file: $<'
	@echo 'Invoking: Cross ARM C Compiler'
	C:\Renesas\e2_studio\eclipse\../Utilities/isdebuild arm-none-eabi-gcc -mcpu=cortex-m4 -mthumb -mfloat-abi=hard -mfpu=fpv4-sp-d16 -O2 -fmessage-length=0 -fsigned-char -ffunction-sections -fdata-sections -Wunused -Wuninitialized -Wall -Wextra -Wmissing-declarations -Wconversion -Wpointer-arith -Wshadow -Wlogical-op -Waggregate-return -Wfloat-equal  -g3 -D_RENESAS_SYNERGY_ -I"C:\Users\Kirti\e2_studio\workspace\UARTPrint\src" -I"C:\Users\Kirti\e2_studio\workspace\UARTPrint\src\synergy_gen" -I"C:\Users\Kirti\e2_studio\workspace\UARTPrint\synergy_cfg\ssp_cfg\bsp" -I"C:\Users\Kirti\e2_studio\workspace\UARTPrint\synergy_cfg\ssp_cfg\driver" -I"C:\Users\Kirti\e2_studio\workspace\UARTPrint\synergy\ssp\inc" -I"C:\Users\Kirti\e2_studio\workspace\UARTPrint\synergy\ssp\inc\bsp" -I"C:\Users\Kirti\e2_studio\workspace\UARTPrint\synergy\ssp\inc\bsp\cmsis\Include" -I"C:\Users\Kirti\e2_studio\workspace\UARTPrint\synergy\ssp\inc\driver\api" -I"C:\Users\Kirti\e2_studio\workspace\UARTPrint\synergy\ssp\inc\driver\instances" -I"C:\Users\Kirti\e2_studio\workspace\UARTPrint\synergy_cfg\ssp_cfg\framework\el" -I"C:\Users\Kirti\e2_studio\workspace\UARTPrint\synergy\ssp\inc\framework\el" -I"C:\Users\Kirti\e2_studio\workspace\UARTPrint\synergy\ssp\src\framework\el\tx" -std=c99 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -c -o "$@" -x c "$<"
	@echo 'Finished building: $<'
	@echo ' '


