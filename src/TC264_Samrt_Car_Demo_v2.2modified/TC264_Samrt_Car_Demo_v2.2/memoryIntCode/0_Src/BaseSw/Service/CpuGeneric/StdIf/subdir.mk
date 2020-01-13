################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../0_Src/BaseSw/Service/CpuGeneric/StdIf/IfxStdIf_DPipe.c \
../0_Src/BaseSw/Service/CpuGeneric/StdIf/IfxStdIf_Pos.c \
../0_Src/BaseSw/Service/CpuGeneric/StdIf/IfxStdIf_PwmHl.c \
../0_Src/BaseSw/Service/CpuGeneric/StdIf/IfxStdIf_Timer.c 

OBJS += \
./0_Src/BaseSw/Service/CpuGeneric/StdIf/IfxStdIf_DPipe.o \
./0_Src/BaseSw/Service/CpuGeneric/StdIf/IfxStdIf_Pos.o \
./0_Src/BaseSw/Service/CpuGeneric/StdIf/IfxStdIf_PwmHl.o \
./0_Src/BaseSw/Service/CpuGeneric/StdIf/IfxStdIf_Timer.o 

C_DEPS += \
./0_Src/BaseSw/Service/CpuGeneric/StdIf/IfxStdIf_DPipe.d \
./0_Src/BaseSw/Service/CpuGeneric/StdIf/IfxStdIf_Pos.d \
./0_Src/BaseSw/Service/CpuGeneric/StdIf/IfxStdIf_PwmHl.d \
./0_Src/BaseSw/Service/CpuGeneric/StdIf/IfxStdIf_Timer.d 


# Each subdirectory must supply rules for building sources it contributes
0_Src/BaseSw/Service/CpuGeneric/StdIf/%.o: ../0_Src/BaseSw/Service/CpuGeneric/StdIf/%.c
	@echo 'Building file: $<'
	@echo 'Invoking: TriCore C Compiler'
	"$(TRICORE_TOOLS)/bin/tricore-gcc" -c -I"../h" -fno-common -Os -g3 -W -Wall -Wextra -Wdiv-by-zero -Warray-bounds -Wcast-align -Wignored-qualifiers -Wformat -Wformat-security -pipe -DAPPKIT_TC265B -fshort-double -mcpu=tc26xx -mversion-info -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


