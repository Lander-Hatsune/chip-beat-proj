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
	"$(TRICORE_TOOLS)/bin/tricore-gcc" -c -I"C:\Users\kuaile\htc-workspace\TC264_Samrt_Car_Demo_v2.2\0_Src\AppSw" -I"C:\Users\kuaile\htc-workspace\TC264_Samrt_Car_Demo_v2.2\0_Src\AppSw\CpuGeneric" -I"C:\Users\kuaile\htc-workspace\TC264_Samrt_Car_Demo_v2.2\0_Src\AppSw\CpuGeneric\Config" -I"C:\Users\kuaile\htc-workspace\TC264_Samrt_Car_Demo_v2.2\0_Src\AppSw\Tricore" -I"C:\Users\kuaile\htc-workspace\TC264_Samrt_Car_Demo_v2.2\0_Src\AppSw\Tricore\Main" -I"C:\Users\kuaile\htc-workspace\TC264_Samrt_Car_Demo_v2.2\0_Src\BaseSw" -I"C:\Users\kuaile\htc-workspace\TC264_Samrt_Car_Demo_v2.2\0_Src\BaseSw\iLLD" -I"C:\Users\kuaile\htc-workspace\TC264_Samrt_Car_Demo_v2.2\0_Src\BaseSw\iLLD\TC26B" -I"C:\Users\kuaile\htc-workspace\TC264_Samrt_Car_Demo_v2.2\0_Src\BaseSw\iLLD\TC26B\Tricore" -I"C:\Users\kuaile\htc-workspace\TC264_Samrt_Car_Demo_v2.2\0_Src\BaseSw\iLLD\TC26B\Tricore\_Impl" -I"C:\Users\kuaile\htc-workspace\TC264_Samrt_Car_Demo_v2.2\0_Src\BaseSw\iLLD\TC26B\Tricore\_Lib" -I"C:\Users\kuaile\htc-workspace\TC264_Samrt_Car_Demo_v2.2\0_Src\BaseSw\iLLD\TC26B\Tricore\_Lib\DataHandling" -I"C:\Users\kuaile\htc-workspace\TC264_Samrt_Car_Demo_v2.2\0_Src\BaseSw\iLLD\TC26B\Tricore\_Lib\InternalMux" -I"C:\Users\kuaile\htc-workspace\TC264_Samrt_Car_Demo_v2.2\0_Src\BaseSw\iLLD\TC26B\Tricore\_PinMap" -I"C:\Users\kuaile\htc-workspace\TC264_Samrt_Car_Demo_v2.2\0_Src\BaseSw\iLLD\TC26B\Tricore\Asclin" -I"C:\Users\kuaile\htc-workspace\TC264_Samrt_Car_Demo_v2.2\0_Src\BaseSw\iLLD\TC26B\Tricore\Asclin\Asc" -I"C:\Users\kuaile\htc-workspace\TC264_Samrt_Car_Demo_v2.2\0_Src\BaseSw\iLLD\TC26B\Tricore\Asclin\Lin" -I"C:\Users\kuaile\htc-workspace\TC264_Samrt_Car_Demo_v2.2\0_Src\BaseSw\iLLD\TC26B\Tricore\Asclin\Spi" -I"C:\Users\kuaile\htc-workspace\TC264_Samrt_Car_Demo_v2.2\0_Src\BaseSw\iLLD\TC26B\Tricore\Asclin\Std" -I"C:\Users\kuaile\htc-workspace\TC264_Samrt_Car_Demo_v2.2\0_Src\BaseSw\iLLD\TC26B\Tricore\Ccu6" -I"C:\Users\kuaile\htc-workspace\TC264_Samrt_Car_Demo_v2.2\0_Src\BaseSw\iLLD\TC26B\Tricore\Ccu6\Icu" -I"C:\Users\kuaile\htc-workspace\TC264_Samrt_Car_Demo_v2.2\0_Src\BaseSw\iLLD\TC26B\Tricore\Ccu6\PwmBc" -I"C:\Users\kuaile\htc-workspace\TC264_Samrt_Car_Demo_v2.2\0_Src\BaseSw\iLLD\TC26B\Tricore\Ccu6\PwmHl" -I"C:\Users\kuaile\htc-workspace\TC264_Samrt_Car_Demo_v2.2\0_Src\BaseSw\iLLD\TC26B\Tricore\Ccu6\Std" -I"C:\Users\kuaile\htc-workspace\TC264_Samrt_Car_Demo_v2.2\0_Src\BaseSw\iLLD\TC26B\Tricore\Ccu6\Timer" -I"C:\Users\kuaile\htc-workspace\TC264_Samrt_Car_Demo_v2.2\0_Src\BaseSw\iLLD\TC26B\Tricore\Ccu6\TimerWithTrigger" -I"C:\Users\kuaile\htc-workspace\TC264_Samrt_Car_Demo_v2.2\0_Src\BaseSw\iLLD\TC26B\Tricore\Ccu6\TPwm" -I"C:\Users\kuaile\htc-workspace\TC264_Samrt_Car_Demo_v2.2\0_Src\BaseSw\iLLD\TC26B\Tricore\Cpu" -I"C:\Users\kuaile\htc-workspace\TC264_Samrt_Car_Demo_v2.2\0_Src\BaseSw\iLLD\TC26B\Tricore\Cpu\CStart" -I"C:\Users\kuaile\htc-workspace\TC264_Samrt_Car_Demo_v2.2\0_Src\BaseSw\iLLD\TC26B\Tricore\Cpu\Irq" -I"C:\Users\kuaile\htc-workspace\TC264_Samrt_Car_Demo_v2.2\0_Src\BaseSw\iLLD\TC26B\Tricore\Cpu\Std" -I"C:\Users\kuaile\htc-workspace\TC264_Samrt_Car_Demo_v2.2\0_Src\BaseSw\iLLD\TC26B\Tricore\Cpu\Trap" -I"C:\Users\kuaile\htc-workspace\TC264_Samrt_Car_Demo_v2.2\0_Src\BaseSw\iLLD\TC26B\Tricore\Dma" -I"C:\Users\kuaile\htc-workspace\TC264_Samrt_Car_Demo_v2.2\0_Src\BaseSw\iLLD\TC26B\Tricore\Dma\Dma" -I"C:\Users\kuaile\htc-workspace\TC264_Samrt_Car_Demo_v2.2\0_Src\BaseSw\iLLD\TC26B\Tricore\Dma\Std" -I"C:\Users\kuaile\htc-workspace\TC264_Samrt_Car_Demo_v2.2\0_Src\BaseSw\iLLD\TC26B\Tricore\Gtm" -I"C:\Users\kuaile\htc-workspace\TC264_Samrt_Car_Demo_v2.2\0_Src\BaseSw\iLLD\TC26B\Tricore\Gtm\Atom" -I"C:\Users\kuaile\htc-workspace\TC264_Samrt_Car_Demo_v2.2\0_Src\BaseSw\iLLD\TC26B\Tricore\Gtm\Atom\Pwm" -I"C:\Users\kuaile\htc-workspace\TC264_Samrt_Car_Demo_v2.2\0_Src\BaseSw\iLLD\TC26B\Tricore\Gtm\Atom\PwmHl" -I"C:\Users\kuaile\htc-workspace\TC264_Samrt_Car_Demo_v2.2\0_Src\BaseSw\iLLD\TC26B\Tricore\Gtm\Atom\Timer" -I"C:\Users\kuaile\htc-workspace\TC264_Samrt_Car_Demo_v2.2\0_Src\BaseSw\iLLD\TC26B\Tricore\Gtm\Std" -I"C:\Users\kuaile\htc-workspace\TC264_Samrt_Car_Demo_v2.2\0_Src\BaseSw\iLLD\TC26B\Tricore\Gtm\Tim" -I"C:\Users\kuaile\htc-workspace\TC264_Samrt_Car_Demo_v2.2\0_Src\BaseSw\iLLD\TC26B\Tricore\Gtm\Tim\In" -I"C:\Users\kuaile\htc-workspace\TC264_Samrt_Car_Demo_v2.2\0_Src\BaseSw\iLLD\TC26B\Tricore\Gtm\Tom" -I"C:\Users\kuaile\htc-workspace\TC264_Samrt_Car_Demo_v2.2\0_Src\BaseSw\iLLD\TC26B\Tricore\Gtm\Tom\Pwm" -I"C:\Users\kuaile\htc-workspace\TC264_Samrt_Car_Demo_v2.2\0_Src\BaseSw\iLLD\TC26B\Tricore\Gtm\Tom\PwmHl" -I"C:\Users\kuaile\htc-workspace\TC264_Samrt_Car_Demo_v2.2\0_Src\BaseSw\iLLD\TC26B\Tricore\Gtm\Tom\Timer" -I"C:\Users\kuaile\htc-workspace\TC264_Samrt_Car_Demo_v2.2\0_Src\BaseSw\iLLD\TC26B\Tricore\Gtm\Trig" -I"C:\Users\kuaile\htc-workspace\TC264_Samrt_Car_Demo_v2.2\0_Src\BaseSw\iLLD\TC26B\Tricore\I2c" -I"C:\Users\kuaile\htc-workspace\TC264_Samrt_Car_Demo_v2.2\0_Src\BaseSw\iLLD\TC26B\Tricore\I2c\I2c" -I"C:\Users\kuaile\htc-workspace\TC264_Samrt_Car_Demo_v2.2\0_Src\BaseSw\iLLD\TC26B\Tricore\I2c\Std" -I"C:\Users\kuaile\htc-workspace\TC264_Samrt_Car_Demo_v2.2\0_Src\BaseSw\iLLD\TC26B\Tricore\Port" -I"C:\Users\kuaile\htc-workspace\TC264_Samrt_Car_Demo_v2.2\0_Src\BaseSw\iLLD\TC26B\Tricore\Port\Io" -I"C:\Users\kuaile\htc-workspace\TC264_Samrt_Car_Demo_v2.2\0_Src\BaseSw\iLLD\TC26B\Tricore\Port\Std" -I"C:\Users\kuaile\htc-workspace\TC264_Samrt_Car_Demo_v2.2\0_Src\BaseSw\iLLD\TC26B\Tricore\Scu" -I"C:\Users\kuaile\htc-workspace\TC264_Samrt_Car_Demo_v2.2\0_Src\BaseSw\iLLD\TC26B\Tricore\Scu\Std" -I"C:\Users\kuaile\htc-workspace\TC264_Samrt_Car_Demo_v2.2\0_Src\BaseSw\iLLD\TC26B\Tricore\Src" -I"C:\Users\kuaile\htc-workspace\TC264_Samrt_Car_Demo_v2.2\0_Src\BaseSw\iLLD\TC26B\Tricore\Src\Std" -I"C:\Users\kuaile\htc-workspace\TC264_Samrt_Car_Demo_v2.2\0_Src\BaseSw\iLLD\TC26B\Tricore\Stm" -I"C:\Users\kuaile\htc-workspace\TC264_Samrt_Car_Demo_v2.2\0_Src\BaseSw\iLLD\TC26B\Tricore\Stm\Std" -I"C:\Users\kuaile\htc-workspace\TC264_Samrt_Car_Demo_v2.2\0_Src\BaseSw\iLLD\TC26B\Tricore\Stm\Timer" -I"C:\Users\kuaile\htc-workspace\TC264_Samrt_Car_Demo_v2.2\0_Src\BaseSw\iLLD\TC26B\Tricore\Vadc" -I"C:\Users\kuaile\htc-workspace\TC264_Samrt_Car_Demo_v2.2\0_Src\BaseSw\iLLD\TC26B\Tricore\Vadc\Adc" -I"C:\Users\kuaile\htc-workspace\TC264_Samrt_Car_Demo_v2.2\0_Src\BaseSw\iLLD\TC26B\Tricore\Vadc\Std" -I"C:\Users\kuaile\htc-workspace\TC264_Samrt_Car_Demo_v2.2\0_Src\BaseSw\Infra" -I"C:\Users\kuaile\htc-workspace\TC264_Samrt_Car_Demo_v2.2\0_Src\BaseSw\Infra\Platform" -I"C:\Users\kuaile\htc-workspace\TC264_Samrt_Car_Demo_v2.2\0_Src\BaseSw\Infra\Platform\Tricore" -I"C:\Users\kuaile\htc-workspace\TC264_Samrt_Car_Demo_v2.2\0_Src\BaseSw\Infra\Platform\Tricore\Compilers" -I"C:\Users\kuaile\htc-workspace\TC264_Samrt_Car_Demo_v2.2\0_Src\BaseSw\Infra\Sfr" -I"C:\Users\kuaile\htc-workspace\TC264_Samrt_Car_Demo_v2.2\0_Src\BaseSw\Infra\Sfr\TC26B" -I"C:\Users\kuaile\htc-workspace\TC264_Samrt_Car_Demo_v2.2\0_Src\BaseSw\Infra\Sfr\TC26B\_Reg" -I"C:\Users\kuaile\htc-workspace\TC264_Samrt_Car_Demo_v2.2\0_Src\BaseSw\Service" -I"C:\Users\kuaile\htc-workspace\TC264_Samrt_Car_Demo_v2.2\0_Src\BaseSw\Service\CpuGeneric" -I"C:\Users\kuaile\htc-workspace\TC264_Samrt_Car_Demo_v2.2\0_Src\BaseSw\Service\CpuGeneric\_Utilities" -I"C:\Users\kuaile\htc-workspace\TC264_Samrt_Car_Demo_v2.2\0_Src\BaseSw\Service\CpuGeneric\If" -I"C:\Users\kuaile\htc-workspace\TC264_Samrt_Car_Demo_v2.2\0_Src\BaseSw\Service\CpuGeneric\If\Ccu6If" -I"C:\Users\kuaile\htc-workspace\TC264_Samrt_Car_Demo_v2.2\0_Src\BaseSw\Service\CpuGeneric\StdIf" -I"C:\Users\kuaile\htc-workspace\TC264_Samrt_Car_Demo_v2.2\0_Src\BaseSw\Service\CpuGeneric\SysSe" -I"C:\Users\kuaile\htc-workspace\TC264_Samrt_Car_Demo_v2.2\0_Src\BaseSw\Service\CpuGeneric\SysSe\Bsp" -I"C:\Users\kuaile\htc-workspace\TC264_Samrt_Car_Demo_v2.2\0_Src\BaseSw\Service\CpuGeneric\SysSe\Comm" -I"C:\Users\kuaile\htc-workspace\TC264_Samrt_Car_Demo_v2.2\0_Src\BaseSw\Service\CpuGeneric\SysSe\General" -I"C:\Users\kuaile\htc-workspace\TC264_Samrt_Car_Demo_v2.2\0_Src\BaseSw\Service\CpuGeneric\SysSe\Math" -I"C:\Users\kuaile\htc-workspace\TC264_Samrt_Car_Demo_v2.2\0_Src\BaseSw\Service\CpuGeneric\SysSe\Time" -fno-common -Os -g3 -W -Wall -Wextra -Wdiv-by-zero -Warray-bounds -Wcast-align -Wignored-qualifiers -Wformat -Wformat-security -pipe -DAPPKIT_TC265B -fshort-double -mcpu=tc26xx -mversion-info -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


