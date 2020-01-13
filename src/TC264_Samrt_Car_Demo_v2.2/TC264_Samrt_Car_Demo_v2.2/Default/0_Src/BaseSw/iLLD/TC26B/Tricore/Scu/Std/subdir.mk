################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../0_Src/BaseSw/iLLD/TC26B/Tricore/Scu/Std/IfxScuCcu.c \
../0_Src/BaseSw/iLLD/TC26B/Tricore/Scu/Std/IfxScuEru.c \
../0_Src/BaseSw/iLLD/TC26B/Tricore/Scu/Std/IfxScuWdt.c 

OBJS += \
./0_Src/BaseSw/iLLD/TC26B/Tricore/Scu/Std/IfxScuCcu.o \
./0_Src/BaseSw/iLLD/TC26B/Tricore/Scu/Std/IfxScuEru.o \
./0_Src/BaseSw/iLLD/TC26B/Tricore/Scu/Std/IfxScuWdt.o 

C_DEPS += \
./0_Src/BaseSw/iLLD/TC26B/Tricore/Scu/Std/IfxScuCcu.d \
./0_Src/BaseSw/iLLD/TC26B/Tricore/Scu/Std/IfxScuEru.d \
./0_Src/BaseSw/iLLD/TC26B/Tricore/Scu/Std/IfxScuWdt.d 


# Each subdirectory must supply rules for building sources it contributes
0_Src/BaseSw/iLLD/TC26B/Tricore/Scu/Std/%.o: ../0_Src/BaseSw/iLLD/TC26B/Tricore/Scu/Std/%.c
	@echo 'Building file: $<'
	@echo 'Invoking: TriCore C Compiler'
	"$(TRICORE_TOOLS)/bin/tricore-gcc" -c -I"../h" -fno-common -Os -g3 -W -Wall -Wextra -Wdiv-by-zero -Warray-bounds -Wcast-align -Wignored-qualifiers -Wformat -Wformat-security -pipe -DAPPKIT_TC265B -fshort-double -mcpu=tc26xx -mversion-info -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


