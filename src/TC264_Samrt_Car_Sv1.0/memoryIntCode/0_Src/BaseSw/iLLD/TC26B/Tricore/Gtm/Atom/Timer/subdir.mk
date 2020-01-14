################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../0_Src/BaseSw/iLLD/TC26B/Tricore/Gtm/Atom/Timer/IfxGtm_Atom_Timer.c 

OBJS += \
./0_Src/BaseSw/iLLD/TC26B/Tricore/Gtm/Atom/Timer/IfxGtm_Atom_Timer.o 

C_DEPS += \
./0_Src/BaseSw/iLLD/TC26B/Tricore/Gtm/Atom/Timer/IfxGtm_Atom_Timer.d 


# Each subdirectory must supply rules for building sources it contributes
0_Src/BaseSw/iLLD/TC26B/Tricore/Gtm/Atom/Timer/%.o: ../0_Src/BaseSw/iLLD/TC26B/Tricore/Gtm/Atom/Timer/%.c
	@echo 'Building file: $<'
	@echo 'Invoking: TriCore C Compiler'
	"$(TRICORE_TOOLS)/bin/tricore-gcc" -c -I"../h" -fno-common -Os -g3 -W -Wall -Wextra -Wdiv-by-zero -Warray-bounds -Wcast-align -Wignored-qualifiers -Wformat -Wformat-security -pipe -DAPPKIT_TC265B -fshort-double -mcpu=tc26xx -mversion-info -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


