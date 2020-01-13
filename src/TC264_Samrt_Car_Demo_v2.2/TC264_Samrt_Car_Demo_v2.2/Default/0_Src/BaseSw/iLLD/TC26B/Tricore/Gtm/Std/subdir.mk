################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../0_Src/BaseSw/iLLD/TC26B/Tricore/Gtm/Std/IfxGtm.c \
../0_Src/BaseSw/iLLD/TC26B/Tricore/Gtm/Std/IfxGtm_Atom.c \
../0_Src/BaseSw/iLLD/TC26B/Tricore/Gtm/Std/IfxGtm_Cmu.c \
../0_Src/BaseSw/iLLD/TC26B/Tricore/Gtm/Std/IfxGtm_Dpll.c \
../0_Src/BaseSw/iLLD/TC26B/Tricore/Gtm/Std/IfxGtm_Tbu.c \
../0_Src/BaseSw/iLLD/TC26B/Tricore/Gtm/Std/IfxGtm_Tim.c \
../0_Src/BaseSw/iLLD/TC26B/Tricore/Gtm/Std/IfxGtm_Tom.c 

OBJS += \
./0_Src/BaseSw/iLLD/TC26B/Tricore/Gtm/Std/IfxGtm.o \
./0_Src/BaseSw/iLLD/TC26B/Tricore/Gtm/Std/IfxGtm_Atom.o \
./0_Src/BaseSw/iLLD/TC26B/Tricore/Gtm/Std/IfxGtm_Cmu.o \
./0_Src/BaseSw/iLLD/TC26B/Tricore/Gtm/Std/IfxGtm_Dpll.o \
./0_Src/BaseSw/iLLD/TC26B/Tricore/Gtm/Std/IfxGtm_Tbu.o \
./0_Src/BaseSw/iLLD/TC26B/Tricore/Gtm/Std/IfxGtm_Tim.o \
./0_Src/BaseSw/iLLD/TC26B/Tricore/Gtm/Std/IfxGtm_Tom.o 

C_DEPS += \
./0_Src/BaseSw/iLLD/TC26B/Tricore/Gtm/Std/IfxGtm.d \
./0_Src/BaseSw/iLLD/TC26B/Tricore/Gtm/Std/IfxGtm_Atom.d \
./0_Src/BaseSw/iLLD/TC26B/Tricore/Gtm/Std/IfxGtm_Cmu.d \
./0_Src/BaseSw/iLLD/TC26B/Tricore/Gtm/Std/IfxGtm_Dpll.d \
./0_Src/BaseSw/iLLD/TC26B/Tricore/Gtm/Std/IfxGtm_Tbu.d \
./0_Src/BaseSw/iLLD/TC26B/Tricore/Gtm/Std/IfxGtm_Tim.d \
./0_Src/BaseSw/iLLD/TC26B/Tricore/Gtm/Std/IfxGtm_Tom.d 


# Each subdirectory must supply rules for building sources it contributes
0_Src/BaseSw/iLLD/TC26B/Tricore/Gtm/Std/%.o: ../0_Src/BaseSw/iLLD/TC26B/Tricore/Gtm/Std/%.c
	@echo 'Building file: $<'
	@echo 'Invoking: TriCore C Compiler'
	"$(TRICORE_TOOLS)/bin/tricore-gcc" -c -I"../h" -fno-common -Os -g3 -W -Wall -Wextra -Wdiv-by-zero -Warray-bounds -Wcast-align -Wignored-qualifiers -Wformat -Wformat-security -pipe -DAPPKIT_TC265B -fshort-double -mcpu=tc26xx -mversion-info -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


