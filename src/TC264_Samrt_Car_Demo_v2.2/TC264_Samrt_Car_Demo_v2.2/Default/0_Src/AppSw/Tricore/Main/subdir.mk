################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../0_Src/AppSw/Tricore/Main/AsclinApp.c \
../0_Src/AppSw/Tricore/Main/CameraOV7620.c \
../0_Src/AppSw/Tricore/Main/Cpu0_Main.c \
../0_Src/AppSw/Tricore/Main/Cpu1_Main.c \
../0_Src/AppSw/Tricore/Main/Mpu6050.c \
../0_Src/AppSw/Tricore/Main/PwmDemo.c \
../0_Src/AppSw/Tricore/Main/ServeSource.c \
../0_Src/AppSw/Tricore/Main/StmDemo.c \
../0_Src/AppSw/Tricore/Main/TimDemo.c \
../0_Src/AppSw/Tricore/Main/UserSource.c \
../0_Src/AppSw/Tricore/Main/VadcApp.c 

OBJS += \
./0_Src/AppSw/Tricore/Main/AsclinApp.o \
./0_Src/AppSw/Tricore/Main/CameraOV7620.o \
./0_Src/AppSw/Tricore/Main/Cpu0_Main.o \
./0_Src/AppSw/Tricore/Main/Cpu1_Main.o \
./0_Src/AppSw/Tricore/Main/Mpu6050.o \
./0_Src/AppSw/Tricore/Main/PwmDemo.o \
./0_Src/AppSw/Tricore/Main/ServeSource.o \
./0_Src/AppSw/Tricore/Main/StmDemo.o \
./0_Src/AppSw/Tricore/Main/TimDemo.o \
./0_Src/AppSw/Tricore/Main/UserSource.o \
./0_Src/AppSw/Tricore/Main/VadcApp.o 

C_DEPS += \
./0_Src/AppSw/Tricore/Main/AsclinApp.d \
./0_Src/AppSw/Tricore/Main/CameraOV7620.d \
./0_Src/AppSw/Tricore/Main/Cpu0_Main.d \
./0_Src/AppSw/Tricore/Main/Cpu1_Main.d \
./0_Src/AppSw/Tricore/Main/Mpu6050.d \
./0_Src/AppSw/Tricore/Main/PwmDemo.d \
./0_Src/AppSw/Tricore/Main/ServeSource.d \
./0_Src/AppSw/Tricore/Main/StmDemo.d \
./0_Src/AppSw/Tricore/Main/TimDemo.d \
./0_Src/AppSw/Tricore/Main/UserSource.d \
./0_Src/AppSw/Tricore/Main/VadcApp.d 


# Each subdirectory must supply rules for building sources it contributes
0_Src/AppSw/Tricore/Main/%.o: ../0_Src/AppSw/Tricore/Main/%.c
	@echo 'Building file: $<'
	@echo 'Invoking: TriCore C Compiler'
	"$(TRICORE_TOOLS)/bin/tricore-gcc" -c -I"../h" -fno-common -Os -g3 -W -Wall -Wextra -Wdiv-by-zero -Warray-bounds -Wcast-align -Wignored-qualifiers -Wformat -Wformat-security -pipe -DAPPKIT_TC265B -fshort-double -mcpu=tc26xx -mversion-info -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


