################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../0_Src/BaseSw/iLLD/TC26B/Tricore/Stm/Timer/IfxStm_Timer.c 

OBJS += \
./0_Src/BaseSw/iLLD/TC26B/Tricore/Stm/Timer/IfxStm_Timer.o 

C_DEPS += \
./0_Src/BaseSw/iLLD/TC26B/Tricore/Stm/Timer/IfxStm_Timer.d 


# Each subdirectory must supply rules for building sources it contributes
0_Src/BaseSw/iLLD/TC26B/Tricore/Stm/Timer/%.o: ../0_Src/BaseSw/iLLD/TC26B/Tricore/Stm/Timer/%.c
	@echo 'Building file: $<'
	@echo 'Invoking: TriCore C Compiler'
	"$(TRICORE_TOOLS)/bin/tricore-gcc" -c -I"../h" -fno-common -Os -g3 -W -Wall -Wextra -Wdiv-by-zero -Warray-bounds -Wcast-align -Wignored-qualifiers -Wformat -Wformat-security -pipe -DAPPKIT_TC265B -fshort-double -mcpu=tc26xx -mversion-info -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


