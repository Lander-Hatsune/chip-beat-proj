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
	"$(TRICORE_TOOLS)/bin/tricore-gcc" -c -I"D:\THU\Business\CHIPBEAT\hightec\TC264_Samrt_Car_Sv1.0\0_Src\AppSw" -I"D:\THU\Business\CHIPBEAT\hightec\TC264_Samrt_Car_Sv1.0\0_Src\AppSw\CpuGeneric" -I"D:\THU\Business\CHIPBEAT\hightec\TC264_Samrt_Car_Sv1.0\0_Src\AppSw\CpuGeneric\Config" -I"D:\THU\Business\CHIPBEAT\hightec\TC264_Samrt_Car_Sv1.0\0_Src\AppSw\Tricore" -I"D:\THU\Business\CHIPBEAT\hightec\TC264_Samrt_Car_Sv1.0\0_Src\AppSw\Tricore\Main" -I"D:\THU\Business\CHIPBEAT\hightec\TC264_Samrt_Car_Sv1.0\0_Src\BaseSw" -I"D:\THU\Business\CHIPBEAT\hightec\TC264_Samrt_Car_Sv1.0\0_Src\BaseSw\iLLD" -I"D:\THU\Business\CHIPBEAT\hightec\TC264_Samrt_Car_Sv1.0\0_Src\BaseSw\iLLD\TC26B" -I"D:\THU\Business\CHIPBEAT\hightec\TC264_Samrt_Car_Sv1.0\0_Src\BaseSw\iLLD\TC26B\Tricore" -I"D:\THU\Business\CHIPBEAT\hightec\TC264_Samrt_Car_Sv1.0\0_Src\BaseSw\iLLD\TC26B\Tricore\_Impl" -I"D:\THU\Business\CHIPBEAT\hightec\TC264_Samrt_Car_Sv1.0\0_Src\BaseSw\iLLD\TC26B\Tricore\_Lib" -I"D:\THU\Business\CHIPBEAT\hightec\TC264_Samrt_Car_Sv1.0\0_Src\BaseSw\iLLD\TC26B\Tricore\_Lib\DataHandling" -I"D:\THU\Business\CHIPBEAT\hightec\TC264_Samrt_Car_Sv1.0\0_Src\BaseSw\iLLD\TC26B\Tricore\_Lib\InternalMux" -I"D:\THU\Business\CHIPBEAT\hightec\TC264_Samrt_Car_Sv1.0\0_Src\BaseSw\iLLD\TC26B\Tricore\_PinMap" -I"D:\THU\Business\CHIPBEAT\hightec\TC264_Samrt_Car_Sv1.0\0_Src\BaseSw\iLLD\TC26B\Tricore\Asclin" -I"D:\THU\Business\CHIPBEAT\hightec\TC264_Samrt_Car_Sv1.0\0_Src\BaseSw\iLLD\TC26B\Tricore\Asclin\Asc" -I"D:\THU\Business\CHIPBEAT\hightec\TC264_Samrt_Car_Sv1.0\0_Src\BaseSw\iLLD\TC26B\Tricore\Asclin\Lin" -I"D:\THU\Business\CHIPBEAT\hightec\TC264_Samrt_Car_Sv1.0\0_Src\BaseSw\iLLD\TC26B\Tricore\Asclin\Spi" -I"D:\THU\Business\CHIPBEAT\hightec\TC264_Samrt_Car_Sv1.0\0_Src\BaseSw\iLLD\TC26B\Tricore\Asclin\Std" -I"D:\THU\Business\CHIPBEAT\hightec\TC264_Samrt_Car_Sv1.0\0_Src\BaseSw\iLLD\TC26B\Tricore\Ccu6" -I"D:\THU\Business\CHIPBEAT\hightec\TC264_Samrt_Car_Sv1.0\0_Src\BaseSw\iLLD\TC26B\Tricore\Ccu6\Icu" -I"D:\THU\Business\CHIPBEAT\hightec\TC264_Samrt_Car_Sv1.0\0_Src\BaseSw\iLLD\TC26B\Tricore\Ccu6\PwmBc" -I"D:\THU\Business\CHIPBEAT\hightec\TC264_Samrt_Car_Sv1.0\0_Src\BaseSw\iLLD\TC26B\Tricore\Ccu6\PwmHl" -I"D:\THU\Business\CHIPBEAT\hightec\TC264_Samrt_Car_Sv1.0\0_Src\BaseSw\iLLD\TC26B\Tricore\Ccu6\Std" -I"D:\THU\Business\CHIPBEAT\hightec\TC264_Samrt_Car_Sv1.0\0_Src\BaseSw\iLLD\TC26B\Tricore\Ccu6\Timer" -I"D:\THU\Business\CHIPBEAT\hightec\TC264_Samrt_Car_Sv1.0\0_Src\BaseSw\iLLD\TC26B\Tricore\Ccu6\TimerWithTrigger" -I"D:\THU\Business\CHIPBEAT\hightec\TC264_Samrt_Car_Sv1.0\0_Src\BaseSw\iLLD\TC26B\Tricore\Ccu6\TPwm" -I"D:\THU\Business\CHIPBEAT\hightec\TC264_Samrt_Car_Sv1.0\0_Src\BaseSw\iLLD\TC26B\Tricore\Cpu" -I"D:\THU\Business\CHIPBEAT\hightec\TC264_Samrt_Car_Sv1.0\0_Src\BaseSw\iLLD\TC26B\Tricore\Cpu\CStart" -I"D:\THU\Business\CHIPBEAT\hightec\TC264_Samrt_Car_Sv1.0\0_Src\BaseSw\iLLD\TC26B\Tricore\Cpu\Irq" -I"D:\THU\Business\CHIPBEAT\hightec\TC264_Samrt_Car_Sv1.0\0_Src\BaseSw\iLLD\TC26B\Tricore\Cpu\Std" -I"D:\THU\Business\CHIPBEAT\hightec\TC264_Samrt_Car_Sv1.0\0_Src\BaseSw\iLLD\TC26B\Tricore\Cpu\Trap" -I"D:\THU\Business\CHIPBEAT\hightec\TC264_Samrt_Car_Sv1.0\0_Src\BaseSw\iLLD\TC26B\Tricore\Dma" -I"D:\THU\Business\CHIPBEAT\hightec\TC264_Samrt_Car_Sv1.0\0_Src\BaseSw\iLLD\TC26B\Tricore\Dma\Dma" -I"D:\THU\Business\CHIPBEAT\hightec\TC264_Samrt_Car_Sv1.0\0_Src\BaseSw\iLLD\TC26B\Tricore\Dma\Std" -I"D:\THU\Business\CHIPBEAT\hightec\TC264_Samrt_Car_Sv1.0\0_Src\BaseSw\iLLD\TC26B\Tricore\Gtm" -I"D:\THU\Business\CHIPBEAT\hightec\TC264_Samrt_Car_Sv1.0\0_Src\BaseSw\iLLD\TC26B\Tricore\Gtm\Atom" -I"D:\THU\Business\CHIPBEAT\hightec\TC264_Samrt_Car_Sv1.0\0_Src\BaseSw\iLLD\TC26B\Tricore\Gtm\Atom\Pwm" -I"D:\THU\Business\CHIPBEAT\hightec\TC264_Samrt_Car_Sv1.0\0_Src\BaseSw\iLLD\TC26B\Tricore\Gtm\Atom\PwmHl" -I"D:\THU\Business\CHIPBEAT\hightec\TC264_Samrt_Car_Sv1.0\0_Src\BaseSw\iLLD\TC26B\Tricore\Gtm\Atom\Timer" -I"D:\THU\Business\CHIPBEAT\hightec\TC264_Samrt_Car_Sv1.0\0_Src\BaseSw\iLLD\TC26B\Tricore\Gtm\Std" -I"D:\THU\Business\CHIPBEAT\hightec\TC264_Samrt_Car_Sv1.0\0_Src\BaseSw\iLLD\TC26B\Tricore\Gtm\Tim" -I"D:\THU\Business\CHIPBEAT\hightec\TC264_Samrt_Car_Sv1.0\0_Src\BaseSw\iLLD\TC26B\Tricore\Gtm\Tim\In" -I"D:\THU\Business\CHIPBEAT\hightec\TC264_Samrt_Car_Sv1.0\0_Src\BaseSw\iLLD\TC26B\Tricore\Gtm\Tom" -I"D:\THU\Business\CHIPBEAT\hightec\TC264_Samrt_Car_Sv1.0\0_Src\BaseSw\iLLD\TC26B\Tricore\Gtm\Tom\Pwm" -I"D:\THU\Business\CHIPBEAT\hightec\TC264_Samrt_Car_Sv1.0\0_Src\BaseSw\iLLD\TC26B\Tricore\Gtm\Tom\PwmHl" -I"D:\THU\Business\CHIPBEAT\hightec\TC264_Samrt_Car_Sv1.0\0_Src\BaseSw\iLLD\TC26B\Tricore\Gtm\Tom\Timer" -I"D:\THU\Business\CHIPBEAT\hightec\TC264_Samrt_Car_Sv1.0\0_Src\BaseSw\iLLD\TC26B\Tricore\Gtm\Trig" -I"D:\THU\Business\CHIPBEAT\hightec\TC264_Samrt_Car_Sv1.0\0_Src\BaseSw\iLLD\TC26B\Tricore\I2c" -I"D:\THU\Business\CHIPBEAT\hightec\TC264_Samrt_Car_Sv1.0\0_Src\BaseSw\iLLD\TC26B\Tricore\I2c\I2c" -I"D:\THU\Business\CHIPBEAT\hightec\TC264_Samrt_Car_Sv1.0\0_Src\BaseSw\iLLD\TC26B\Tricore\I2c\Std" -I"D:\THU\Business\CHIPBEAT\hightec\TC264_Samrt_Car_Sv1.0\0_Src\BaseSw\iLLD\TC26B\Tricore\Port" -I"D:\THU\Business\CHIPBEAT\hightec\TC264_Samrt_Car_Sv1.0\0_Src\BaseSw\iLLD\TC26B\Tricore\Port\Io" -I"D:\THU\Business\CHIPBEAT\hightec\TC264_Samrt_Car_Sv1.0\0_Src\BaseSw\iLLD\TC26B\Tricore\Port\Std" -I"D:\THU\Business\CHIPBEAT\hightec\TC264_Samrt_Car_Sv1.0\0_Src\BaseSw\iLLD\TC26B\Tricore\Scu" -I"D:\THU\Business\CHIPBEAT\hightec\TC264_Samrt_Car_Sv1.0\0_Src\BaseSw\iLLD\TC26B\Tricore\Scu\Std" -I"D:\THU\Business\CHIPBEAT\hightec\TC264_Samrt_Car_Sv1.0\0_Src\BaseSw\iLLD\TC26B\Tricore\Src" -I"D:\THU\Business\CHIPBEAT\hightec\TC264_Samrt_Car_Sv1.0\0_Src\BaseSw\iLLD\TC26B\Tricore\Src\Std" -I"D:\THU\Business\CHIPBEAT\hightec\TC264_Samrt_Car_Sv1.0\0_Src\BaseSw\iLLD\TC26B\Tricore\Stm" -I"D:\THU\Business\CHIPBEAT\hightec\TC264_Samrt_Car_Sv1.0\0_Src\BaseSw\iLLD\TC26B\Tricore\Stm\Std" -I"D:\THU\Business\CHIPBEAT\hightec\TC264_Samrt_Car_Sv1.0\0_Src\BaseSw\iLLD\TC26B\Tricore\Stm\Timer" -I"D:\THU\Business\CHIPBEAT\hightec\TC264_Samrt_Car_Sv1.0\0_Src\BaseSw\iLLD\TC26B\Tricore\Vadc" -I"D:\THU\Business\CHIPBEAT\hightec\TC264_Samrt_Car_Sv1.0\0_Src\BaseSw\iLLD\TC26B\Tricore\Vadc\Adc" -I"D:\THU\Business\CHIPBEAT\hightec\TC264_Samrt_Car_Sv1.0\0_Src\BaseSw\iLLD\TC26B\Tricore\Vadc\Std" -I"D:\THU\Business\CHIPBEAT\hightec\TC264_Samrt_Car_Sv1.0\0_Src\BaseSw\Infra" -I"D:\THU\Business\CHIPBEAT\hightec\TC264_Samrt_Car_Sv1.0\0_Src\BaseSw\Infra\Platform" -I"D:\THU\Business\CHIPBEAT\hightec\TC264_Samrt_Car_Sv1.0\0_Src\BaseSw\Infra\Platform\Tricore" -I"D:\THU\Business\CHIPBEAT\hightec\TC264_Samrt_Car_Sv1.0\0_Src\BaseSw\Infra\Platform\Tricore\Compilers" -I"D:\THU\Business\CHIPBEAT\hightec\TC264_Samrt_Car_Sv1.0\0_Src\BaseSw\Infra\Sfr" -I"D:\THU\Business\CHIPBEAT\hightec\TC264_Samrt_Car_Sv1.0\0_Src\BaseSw\Infra\Sfr\TC26B" -I"D:\THU\Business\CHIPBEAT\hightec\TC264_Samrt_Car_Sv1.0\0_Src\BaseSw\Infra\Sfr\TC26B\_Reg" -I"D:\THU\Business\CHIPBEAT\hightec\TC264_Samrt_Car_Sv1.0\0_Src\BaseSw\Service" -I"D:\THU\Business\CHIPBEAT\hightec\TC264_Samrt_Car_Sv1.0\0_Src\BaseSw\Service\CpuGeneric" -I"D:\THU\Business\CHIPBEAT\hightec\TC264_Samrt_Car_Sv1.0\0_Src\BaseSw\Service\CpuGeneric\_Utilities" -I"D:\THU\Business\CHIPBEAT\hightec\TC264_Samrt_Car_Sv1.0\0_Src\BaseSw\Service\CpuGeneric\If" -I"D:\THU\Business\CHIPBEAT\hightec\TC264_Samrt_Car_Sv1.0\0_Src\BaseSw\Service\CpuGeneric\If\Ccu6If" -I"D:\THU\Business\CHIPBEAT\hightec\TC264_Samrt_Car_Sv1.0\0_Src\BaseSw\Service\CpuGeneric\StdIf" -I"D:\THU\Business\CHIPBEAT\hightec\TC264_Samrt_Car_Sv1.0\0_Src\BaseSw\Service\CpuGeneric\SysSe" -I"D:\THU\Business\CHIPBEAT\hightec\TC264_Samrt_Car_Sv1.0\0_Src\BaseSw\Service\CpuGeneric\SysSe\Bsp" -I"D:\THU\Business\CHIPBEAT\hightec\TC264_Samrt_Car_Sv1.0\0_Src\BaseSw\Service\CpuGeneric\SysSe\Comm" -I"D:\THU\Business\CHIPBEAT\hightec\TC264_Samrt_Car_Sv1.0\0_Src\BaseSw\Service\CpuGeneric\SysSe\General" -I"D:\THU\Business\CHIPBEAT\hightec\TC264_Samrt_Car_Sv1.0\0_Src\BaseSw\Service\CpuGeneric\SysSe\Math" -I"D:\THU\Business\CHIPBEAT\hightec\TC264_Samrt_Car_Sv1.0\0_Src\BaseSw\Service\CpuGeneric\SysSe\Time" -fno-common -Os -g3 -W -Wall -Wextra -Wdiv-by-zero -Warray-bounds -Wcast-align -Wignored-qualifiers -Wformat -Wformat-security -pipe -DAPPKIT_TC265B -fshort-double -mcpu=tc26xx -mversion-info -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


