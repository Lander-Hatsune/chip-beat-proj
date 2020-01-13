################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../0_Src/BaseSw/Infra/Platform/Tricore/Compilers/CompilerDcc.c \
../0_Src/BaseSw/Infra/Platform/Tricore/Compilers/CompilerGhs.c \
../0_Src/BaseSw/Infra/Platform/Tricore/Compilers/CompilerGnuc.c \
../0_Src/BaseSw/Infra/Platform/Tricore/Compilers/CompilerTasking.c 

OBJS += \
./0_Src/BaseSw/Infra/Platform/Tricore/Compilers/CompilerDcc.o \
./0_Src/BaseSw/Infra/Platform/Tricore/Compilers/CompilerGhs.o \
./0_Src/BaseSw/Infra/Platform/Tricore/Compilers/CompilerGnuc.o \
./0_Src/BaseSw/Infra/Platform/Tricore/Compilers/CompilerTasking.o 

C_DEPS += \
./0_Src/BaseSw/Infra/Platform/Tricore/Compilers/CompilerDcc.d \
./0_Src/BaseSw/Infra/Platform/Tricore/Compilers/CompilerGhs.d \
./0_Src/BaseSw/Infra/Platform/Tricore/Compilers/CompilerGnuc.d \
./0_Src/BaseSw/Infra/Platform/Tricore/Compilers/CompilerTasking.d 


# Each subdirectory must supply rules for building sources it contributes
0_Src/BaseSw/Infra/Platform/Tricore/Compilers/%.o: ../0_Src/BaseSw/Infra/Platform/Tricore/Compilers/%.c
	@echo 'Building file: $<'
	@echo 'Invoking: TriCore C Compiler'
	"$(TRICORE_TOOLS)/bin/tricore-gcc" -c -I"../h" -fno-common -Os -g3 -W -Wall -Wextra -Wdiv-by-zero -Warray-bounds -Wcast-align -Wignored-qualifiers -Wformat -Wformat-security -pipe -DAPPKIT_TC265B -fshort-double -mcpu=tc26xx -mversion-info -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


