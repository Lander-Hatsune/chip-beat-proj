################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../0_Src/BaseSw/iLLD/TC26B/Tricore/I2c/I2c/IfxI2c_I2c.c 

OBJS += \
./0_Src/BaseSw/iLLD/TC26B/Tricore/I2c/I2c/IfxI2c_I2c.o 

C_DEPS += \
./0_Src/BaseSw/iLLD/TC26B/Tricore/I2c/I2c/IfxI2c_I2c.d 


# Each subdirectory must supply rules for building sources it contributes
0_Src/BaseSw/iLLD/TC26B/Tricore/I2c/I2c/%.o: ../0_Src/BaseSw/iLLD/TC26B/Tricore/I2c/I2c/%.c
	@echo 'Building file: $<'
	@echo 'Invoking: TriCore C Compiler'
	"$(TRICORE_TOOLS)/bin/tricore-gcc" -c -I"../h" -fno-common -Os -g3 -W -Wall -Wextra -Wdiv-by-zero -Warray-bounds -Wcast-align -Wignored-qualifiers -Wformat -Wformat-security -pipe -DAPPKIT_TC265B -fshort-double -mcpu=tc26xx -mversion-info -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


