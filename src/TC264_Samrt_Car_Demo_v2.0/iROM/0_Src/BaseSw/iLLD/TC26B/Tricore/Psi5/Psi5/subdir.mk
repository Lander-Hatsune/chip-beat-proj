################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../0_Src/BaseSw/iLLD/TC26B/Tricore/Psi5/Psi5/IfxPsi5_Psi5.c 

OBJS += \
./0_Src/BaseSw/iLLD/TC26B/Tricore/Psi5/Psi5/IfxPsi5_Psi5.o 

C_DEPS += \
./0_Src/BaseSw/iLLD/TC26B/Tricore/Psi5/Psi5/IfxPsi5_Psi5.d 


# Each subdirectory must supply rules for building sources it contributes
0_Src/BaseSw/iLLD/TC26B/Tricore/Psi5/Psi5/%.o: ../0_Src/BaseSw/iLLD/TC26B/Tricore/Psi5/Psi5/%.c
	@echo 'Building file: $<'
	@echo 'Invoking: TriCore C Compiler'
	"$(TRICORE_TOOLS)/bin/tricore-gcc" -c -I"C:\Users\chenhan\mywork\software\Hightec\AURIX_1G\TC264_Samrt_Car_Demo\0_Src\AppSw" -I"C:\Users\chenhan\mywork\software\Hightec\AURIX_1G\TC264_Samrt_Car_Demo\0_Src\AppSw\CpuGeneric" -I"C:\Users\chenhan\mywork\software\Hightec\AURIX_1G\TC264_Samrt_Car_Demo\0_Src\AppSw\CpuGeneric\Config" -I"C:\Users\chenhan\mywork\software\Hightec\AURIX_1G\TC264_Samrt_Car_Demo\0_Src\AppSw\Tricore" -I"C:\Users\chenhan\mywork\software\Hightec\AURIX_1G\TC264_Samrt_Car_Demo\0_Src\AppSw\Tricore\Main" -I"C:\Users\chenhan\mywork\software\Hightec\AURIX_1G\TC264_Samrt_Car_Demo\0_Src\BaseSw" -I"C:\Users\chenhan\mywork\software\Hightec\AURIX_1G\TC264_Samrt_Car_Demo\0_Src\BaseSw\iLLD" -I"C:\Users\chenhan\mywork\software\Hightec\AURIX_1G\TC264_Samrt_Car_Demo\0_Src\BaseSw\iLLD\TC26B" -I"C:\Users\chenhan\mywork\software\Hightec\AURIX_1G\TC264_Samrt_Car_Demo\0_Src\BaseSw\iLLD\TC26B\Tricore" -I"C:\Users\chenhan\mywork\software\Hightec\AURIX_1G\TC264_Samrt_Car_Demo\0_Src\BaseSw\iLLD\TC26B\Tricore\_Build" -I"C:\Users\chenhan\mywork\software\Hightec\AURIX_1G\TC264_Samrt_Car_Demo\0_Src\BaseSw\iLLD\TC26B\Tricore\_Impl" -I"C:\Users\chenhan\mywork\software\Hightec\AURIX_1G\TC264_Samrt_Car_Demo\0_Src\BaseSw\iLLD\TC26B\Tricore\_Lib" -I"C:\Users\chenhan\mywork\software\Hightec\AURIX_1G\TC264_Samrt_Car_Demo\0_Src\BaseSw\iLLD\TC26B\Tricore\_Lib\DataHandling" -I"C:\Users\chenhan\mywork\software\Hightec\AURIX_1G\TC264_Samrt_Car_Demo\0_Src\BaseSw\iLLD\TC26B\Tricore\_Lib\InternalMux" -I"C:\Users\chenhan\mywork\software\Hightec\AURIX_1G\TC264_Samrt_Car_Demo\0_Src\BaseSw\iLLD\TC26B\Tricore\_PinMap" -I"C:\Users\chenhan\mywork\software\Hightec\AURIX_1G\TC264_Samrt_Car_Demo\0_Src\BaseSw\iLLD\TC26B\Tricore\Asclin" -I"C:\Users\chenhan\mywork\software\Hightec\AURIX_1G\TC264_Samrt_Car_Demo\0_Src\BaseSw\iLLD\TC26B\Tricore\Asclin\Asc" -I"C:\Users\chenhan\mywork\software\Hightec\AURIX_1G\TC264_Samrt_Car_Demo\0_Src\BaseSw\iLLD\TC26B\Tricore\Asclin\Lin" -I"C:\Users\chenhan\mywork\software\Hightec\AURIX_1G\TC264_Samrt_Car_Demo\0_Src\BaseSw\iLLD\TC26B\Tricore\Asclin\Spi" -I"C:\Users\chenhan\mywork\software\Hightec\AURIX_1G\TC264_Samrt_Car_Demo\0_Src\BaseSw\iLLD\TC26B\Tricore\Asclin\Std" -I"C:\Users\chenhan\mywork\software\Hightec\AURIX_1G\TC264_Samrt_Car_Demo\0_Src\BaseSw\iLLD\TC26B\Tricore\Ccu6" -I"C:\Users\chenhan\mywork\software\Hightec\AURIX_1G\TC264_Samrt_Car_Demo\0_Src\BaseSw\iLLD\TC26B\Tricore\Ccu6\Icu" -I"C:\Users\chenhan\mywork\software\Hightec\AURIX_1G\TC264_Samrt_Car_Demo\0_Src\BaseSw\iLLD\TC26B\Tricore\Ccu6\PwmBc" -I"C:\Users\chenhan\mywork\software\Hightec\AURIX_1G\TC264_Samrt_Car_Demo\0_Src\BaseSw\iLLD\TC26B\Tricore\Ccu6\PwmHl" -I"C:\Users\chenhan\mywork\software\Hightec\AURIX_1G\TC264_Samrt_Car_Demo\0_Src\BaseSw\iLLD\TC26B\Tricore\Ccu6\Std" -I"C:\Users\chenhan\mywork\software\Hightec\AURIX_1G\TC264_Samrt_Car_Demo\0_Src\BaseSw\iLLD\TC26B\Tricore\Ccu6\Timer" -I"C:\Users\chenhan\mywork\software\Hightec\AURIX_1G\TC264_Samrt_Car_Demo\0_Src\BaseSw\iLLD\TC26B\Tricore\Ccu6\TimerWithTrigger" -I"C:\Users\chenhan\mywork\software\Hightec\AURIX_1G\TC264_Samrt_Car_Demo\0_Src\BaseSw\iLLD\TC26B\Tricore\Ccu6\TPwm" -I"C:\Users\chenhan\mywork\software\Hightec\AURIX_1G\TC264_Samrt_Car_Demo\0_Src\BaseSw\iLLD\TC26B\Tricore\Cif" -I"C:\Users\chenhan\mywork\software\Hightec\AURIX_1G\TC264_Samrt_Car_Demo\0_Src\BaseSw\iLLD\TC26B\Tricore\Cif\Cam" -I"C:\Users\chenhan\mywork\software\Hightec\AURIX_1G\TC264_Samrt_Car_Demo\0_Src\BaseSw\iLLD\TC26B\Tricore\Cif\Std" -I"C:\Users\chenhan\mywork\software\Hightec\AURIX_1G\TC264_Samrt_Car_Demo\0_Src\BaseSw\iLLD\TC26B\Tricore\Cpu" -I"C:\Users\chenhan\mywork\software\Hightec\AURIX_1G\TC264_Samrt_Car_Demo\0_Src\BaseSw\iLLD\TC26B\Tricore\Cpu\CStart" -I"C:\Users\chenhan\mywork\software\Hightec\AURIX_1G\TC264_Samrt_Car_Demo\0_Src\BaseSw\iLLD\TC26B\Tricore\Cpu\Irq" -I"C:\Users\chenhan\mywork\software\Hightec\AURIX_1G\TC264_Samrt_Car_Demo\0_Src\BaseSw\iLLD\TC26B\Tricore\Cpu\Std" -I"C:\Users\chenhan\mywork\software\Hightec\AURIX_1G\TC264_Samrt_Car_Demo\0_Src\BaseSw\iLLD\TC26B\Tricore\Cpu\Trap" -I"C:\Users\chenhan\mywork\software\Hightec\AURIX_1G\TC264_Samrt_Car_Demo\0_Src\BaseSw\iLLD\TC26B\Tricore\Dma" -I"C:\Users\chenhan\mywork\software\Hightec\AURIX_1G\TC264_Samrt_Car_Demo\0_Src\BaseSw\iLLD\TC26B\Tricore\Dma\Dma" -I"C:\Users\chenhan\mywork\software\Hightec\AURIX_1G\TC264_Samrt_Car_Demo\0_Src\BaseSw\iLLD\TC26B\Tricore\Dma\Std" -I"C:\Users\chenhan\mywork\software\Hightec\AURIX_1G\TC264_Samrt_Car_Demo\0_Src\BaseSw\iLLD\TC26B\Tricore\Dsadc" -I"C:\Users\chenhan\mywork\software\Hightec\AURIX_1G\TC264_Samrt_Car_Demo\0_Src\BaseSw\iLLD\TC26B\Tricore\Dsadc\Dsadc" -I"C:\Users\chenhan\mywork\software\Hightec\AURIX_1G\TC264_Samrt_Car_Demo\0_Src\BaseSw\iLLD\TC26B\Tricore\Dsadc\Rdc" -I"C:\Users\chenhan\mywork\software\Hightec\AURIX_1G\TC264_Samrt_Car_Demo\0_Src\BaseSw\iLLD\TC26B\Tricore\Dsadc\Std" -I"C:\Users\chenhan\mywork\software\Hightec\AURIX_1G\TC264_Samrt_Car_Demo\0_Src\BaseSw\iLLD\TC26B\Tricore\Dts" -I"C:\Users\chenhan\mywork\software\Hightec\AURIX_1G\TC264_Samrt_Car_Demo\0_Src\BaseSw\iLLD\TC26B\Tricore\Dts\Dts" -I"C:\Users\chenhan\mywork\software\Hightec\AURIX_1G\TC264_Samrt_Car_Demo\0_Src\BaseSw\iLLD\TC26B\Tricore\Dts\Std" -I"C:\Users\chenhan\mywork\software\Hightec\AURIX_1G\TC264_Samrt_Car_Demo\0_Src\BaseSw\iLLD\TC26B\Tricore\Emem" -I"C:\Users\chenhan\mywork\software\Hightec\AURIX_1G\TC264_Samrt_Car_Demo\0_Src\BaseSw\iLLD\TC26B\Tricore\Emem\Std" -I"C:\Users\chenhan\mywork\software\Hightec\AURIX_1G\TC264_Samrt_Car_Demo\0_Src\BaseSw\iLLD\TC26B\Tricore\Eray" -I"C:\Users\chenhan\mywork\software\Hightec\AURIX_1G\TC264_Samrt_Car_Demo\0_Src\BaseSw\iLLD\TC26B\Tricore\Eray\Eray" -I"C:\Users\chenhan\mywork\software\Hightec\AURIX_1G\TC264_Samrt_Car_Demo\0_Src\BaseSw\iLLD\TC26B\Tricore\Eray\Std" -I"C:\Users\chenhan\mywork\software\Hightec\AURIX_1G\TC264_Samrt_Car_Demo\0_Src\BaseSw\iLLD\TC26B\Tricore\Eth" -I"C:\Users\chenhan\mywork\software\Hightec\AURIX_1G\TC264_Samrt_Car_Demo\0_Src\BaseSw\iLLD\TC26B\Tricore\Eth\Phy_Pef7071" -I"C:\Users\chenhan\mywork\software\Hightec\AURIX_1G\TC264_Samrt_Car_Demo\0_Src\BaseSw\iLLD\TC26B\Tricore\Eth\Std" -I"C:\Users\chenhan\mywork\software\Hightec\AURIX_1G\TC264_Samrt_Car_Demo\0_Src\BaseSw\iLLD\TC26B\Tricore\Fce" -I"C:\Users\chenhan\mywork\software\Hightec\AURIX_1G\TC264_Samrt_Car_Demo\0_Src\BaseSw\iLLD\TC26B\Tricore\Fce\Crc" -I"C:\Users\chenhan\mywork\software\Hightec\AURIX_1G\TC264_Samrt_Car_Demo\0_Src\BaseSw\iLLD\TC26B\Tricore\Fce\Std" -I"C:\Users\chenhan\mywork\software\Hightec\AURIX_1G\TC264_Samrt_Car_Demo\0_Src\BaseSw\iLLD\TC26B\Tricore\Fft" -I"C:\Users\chenhan\mywork\software\Hightec\AURIX_1G\TC264_Samrt_Car_Demo\0_Src\BaseSw\iLLD\TC26B\Tricore\Fft\Fft" -I"C:\Users\chenhan\mywork\software\Hightec\AURIX_1G\TC264_Samrt_Car_Demo\0_Src\BaseSw\iLLD\TC26B\Tricore\Fft\Std" -I"C:\Users\chenhan\mywork\software\Hightec\AURIX_1G\TC264_Samrt_Car_Demo\0_Src\BaseSw\iLLD\TC26B\Tricore\Flash" -I"C:\Users\chenhan\mywork\software\Hightec\AURIX_1G\TC264_Samrt_Car_Demo\0_Src\BaseSw\iLLD\TC26B\Tricore\Flash\Std" -I"C:\Users\chenhan\mywork\software\Hightec\AURIX_1G\TC264_Samrt_Car_Demo\0_Src\BaseSw\iLLD\TC26B\Tricore\Gpt12" -I"C:\Users\chenhan\mywork\software\Hightec\AURIX_1G\TC264_Samrt_Car_Demo\0_Src\BaseSw\iLLD\TC26B\Tricore\Gpt12\IncrEnc" -I"C:\Users\chenhan\mywork\software\Hightec\AURIX_1G\TC264_Samrt_Car_Demo\0_Src\BaseSw\iLLD\TC26B\Tricore\Gpt12\Std" -I"C:\Users\chenhan\mywork\software\Hightec\AURIX_1G\TC264_Samrt_Car_Demo\0_Src\BaseSw\iLLD\TC26B\Tricore\Gtm" -I"C:\Users\chenhan\mywork\software\Hightec\AURIX_1G\TC264_Samrt_Car_Demo\0_Src\BaseSw\iLLD\TC26B\Tricore\Gtm\Atom" -I"C:\Users\chenhan\mywork\software\Hightec\AURIX_1G\TC264_Samrt_Car_Demo\0_Src\BaseSw\iLLD\TC26B\Tricore\Gtm\Atom\Pwm" -I"C:\Users\chenhan\mywork\software\Hightec\AURIX_1G\TC264_Samrt_Car_Demo\0_Src\BaseSw\iLLD\TC26B\Tricore\Gtm\Atom\PwmHl" -I"C:\Users\chenhan\mywork\software\Hightec\AURIX_1G\TC264_Samrt_Car_Demo\0_Src\BaseSw\iLLD\TC26B\Tricore\Gtm\Atom\Timer" -I"C:\Users\chenhan\mywork\software\Hightec\AURIX_1G\TC264_Samrt_Car_Demo\0_Src\BaseSw\iLLD\TC26B\Tricore\Gtm\Std" -I"C:\Users\chenhan\mywork\software\Hightec\AURIX_1G\TC264_Samrt_Car_Demo\0_Src\BaseSw\iLLD\TC26B\Tricore\Gtm\Tim" -I"C:\Users\chenhan\mywork\software\Hightec\AURIX_1G\TC264_Samrt_Car_Demo\0_Src\BaseSw\iLLD\TC26B\Tricore\Gtm\Tim\In" -I"C:\Users\chenhan\mywork\software\Hightec\AURIX_1G\TC264_Samrt_Car_Demo\0_Src\BaseSw\iLLD\TC26B\Tricore\Gtm\Tom" -I"C:\Users\chenhan\mywork\software\Hightec\AURIX_1G\TC264_Samrt_Car_Demo\0_Src\BaseSw\iLLD\TC26B\Tricore\Gtm\Tom\Pwm" -I"C:\Users\chenhan\mywork\software\Hightec\AURIX_1G\TC264_Samrt_Car_Demo\0_Src\BaseSw\iLLD\TC26B\Tricore\Gtm\Tom\PwmHl" -I"C:\Users\chenhan\mywork\software\Hightec\AURIX_1G\TC264_Samrt_Car_Demo\0_Src\BaseSw\iLLD\TC26B\Tricore\Gtm\Tom\Timer" -I"C:\Users\chenhan\mywork\software\Hightec\AURIX_1G\TC264_Samrt_Car_Demo\0_Src\BaseSw\iLLD\TC26B\Tricore\Gtm\Trig" -I"C:\Users\chenhan\mywork\software\Hightec\AURIX_1G\TC264_Samrt_Car_Demo\0_Src\BaseSw\iLLD\TC26B\Tricore\Hssl" -I"C:\Users\chenhan\mywork\software\Hightec\AURIX_1G\TC264_Samrt_Car_Demo\0_Src\BaseSw\iLLD\TC26B\Tricore\Hssl\Hssl" -I"C:\Users\chenhan\mywork\software\Hightec\AURIX_1G\TC264_Samrt_Car_Demo\0_Src\BaseSw\iLLD\TC26B\Tricore\Hssl\Std" -I"C:\Users\chenhan\mywork\software\Hightec\AURIX_1G\TC264_Samrt_Car_Demo\0_Src\BaseSw\iLLD\TC26B\Tricore\I2c" -I"C:\Users\chenhan\mywork\software\Hightec\AURIX_1G\TC264_Samrt_Car_Demo\0_Src\BaseSw\iLLD\TC26B\Tricore\I2c\I2c" -I"C:\Users\chenhan\mywork\software\Hightec\AURIX_1G\TC264_Samrt_Car_Demo\0_Src\BaseSw\iLLD\TC26B\Tricore\I2c\Std" -I"C:\Users\chenhan\mywork\software\Hightec\AURIX_1G\TC264_Samrt_Car_Demo\0_Src\BaseSw\iLLD\TC26B\Tricore\Iom" -I"C:\Users\chenhan\mywork\software\Hightec\AURIX_1G\TC264_Samrt_Car_Demo\0_Src\BaseSw\iLLD\TC26B\Tricore\Iom\Driver" -I"C:\Users\chenhan\mywork\software\Hightec\AURIX_1G\TC264_Samrt_Car_Demo\0_Src\BaseSw\iLLD\TC26B\Tricore\Iom\Std" -I"C:\Users\chenhan\mywork\software\Hightec\AURIX_1G\TC264_Samrt_Car_Demo\0_Src\BaseSw\iLLD\TC26B\Tricore\Msc" -I"C:\Users\chenhan\mywork\software\Hightec\AURIX_1G\TC264_Samrt_Car_Demo\0_Src\BaseSw\iLLD\TC26B\Tricore\Msc\Msc" -I"C:\Users\chenhan\mywork\software\Hightec\AURIX_1G\TC264_Samrt_Car_Demo\0_Src\BaseSw\iLLD\TC26B\Tricore\Msc\Std" -I"C:\Users\chenhan\mywork\software\Hightec\AURIX_1G\TC264_Samrt_Car_Demo\0_Src\BaseSw\iLLD\TC26B\Tricore\Mtu" -I"C:\Users\chenhan\mywork\software\Hightec\AURIX_1G\TC264_Samrt_Car_Demo\0_Src\BaseSw\iLLD\TC26B\Tricore\Mtu\Std" -I"C:\Users\chenhan\mywork\software\Hightec\AURIX_1G\TC264_Samrt_Car_Demo\0_Src\BaseSw\iLLD\TC26B\Tricore\Multican" -I"C:\Users\chenhan\mywork\software\Hightec\AURIX_1G\TC264_Samrt_Car_Demo\0_Src\BaseSw\iLLD\TC26B\Tricore\Multican\Can" -I"C:\Users\chenhan\mywork\software\Hightec\AURIX_1G\TC264_Samrt_Car_Demo\0_Src\BaseSw\iLLD\TC26B\Tricore\Multican\Std" -I"C:\Users\chenhan\mywork\software\Hightec\AURIX_1G\TC264_Samrt_Car_Demo\0_Src\BaseSw\iLLD\TC26B\Tricore\Port" -I"C:\Users\chenhan\mywork\software\Hightec\AURIX_1G\TC264_Samrt_Car_Demo\0_Src\BaseSw\iLLD\TC26B\Tricore\Port\Io" -I"C:\Users\chenhan\mywork\software\Hightec\AURIX_1G\TC264_Samrt_Car_Demo\0_Src\BaseSw\iLLD\TC26B\Tricore\Port\Std" -I"C:\Users\chenhan\mywork\software\Hightec\AURIX_1G\TC264_Samrt_Car_Demo\0_Src\BaseSw\iLLD\TC26B\Tricore\Psi5" -I"C:\Users\chenhan\mywork\software\Hightec\AURIX_1G\TC264_Samrt_Car_Demo\0_Src\BaseSw\iLLD\TC26B\Tricore\Psi5\Psi5" -I"C:\Users\chenhan\mywork\software\Hightec\AURIX_1G\TC264_Samrt_Car_Demo\0_Src\BaseSw\iLLD\TC26B\Tricore\Psi5\Std" -I"C:\Users\chenhan\mywork\software\Hightec\AURIX_1G\TC264_Samrt_Car_Demo\0_Src\BaseSw\iLLD\TC26B\Tricore\Psi5s" -I"C:\Users\chenhan\mywork\software\Hightec\AURIX_1G\TC264_Samrt_Car_Demo\0_Src\BaseSw\iLLD\TC26B\Tricore\Psi5s\Psi5s" -I"C:\Users\chenhan\mywork\software\Hightec\AURIX_1G\TC264_Samrt_Car_Demo\0_Src\BaseSw\iLLD\TC26B\Tricore\Psi5s\Std" -I"C:\Users\chenhan\mywork\software\Hightec\AURIX_1G\TC264_Samrt_Car_Demo\0_Src\BaseSw\iLLD\TC26B\Tricore\Qspi" -I"C:\Users\chenhan\mywork\software\Hightec\AURIX_1G\TC264_Samrt_Car_Demo\0_Src\BaseSw\iLLD\TC26B\Tricore\Qspi\SpiMaster" -I"C:\Users\chenhan\mywork\software\Hightec\AURIX_1G\TC264_Samrt_Car_Demo\0_Src\BaseSw\iLLD\TC26B\Tricore\Qspi\SpiSlave" -I"C:\Users\chenhan\mywork\software\Hightec\AURIX_1G\TC264_Samrt_Car_Demo\0_Src\BaseSw\iLLD\TC26B\Tricore\Qspi\Std" -I"C:\Users\chenhan\mywork\software\Hightec\AURIX_1G\TC264_Samrt_Car_Demo\0_Src\BaseSw\iLLD\TC26B\Tricore\Scu" -I"C:\Users\chenhan\mywork\software\Hightec\AURIX_1G\TC264_Samrt_Car_Demo\0_Src\BaseSw\iLLD\TC26B\Tricore\Scu\Std" -I"C:\Users\chenhan\mywork\software\Hightec\AURIX_1G\TC264_Samrt_Car_Demo\0_Src\BaseSw\iLLD\TC26B\Tricore\Sent" -I"C:\Users\chenhan\mywork\software\Hightec\AURIX_1G\TC264_Samrt_Car_Demo\0_Src\BaseSw\iLLD\TC26B\Tricore\Sent\Sent" -I"C:\Users\chenhan\mywork\software\Hightec\AURIX_1G\TC264_Samrt_Car_Demo\0_Src\BaseSw\iLLD\TC26B\Tricore\Sent\Std" -I"C:\Users\chenhan\mywork\software\Hightec\AURIX_1G\TC264_Samrt_Car_Demo\0_Src\BaseSw\iLLD\TC26B\Tricore\Smu" -I"C:\Users\chenhan\mywork\software\Hightec\AURIX_1G\TC264_Samrt_Car_Demo\0_Src\BaseSw\iLLD\TC26B\Tricore\Smu\Std" -I"C:\Users\chenhan\mywork\software\Hightec\AURIX_1G\TC264_Samrt_Car_Demo\0_Src\BaseSw\iLLD\TC26B\Tricore\Src" -I"C:\Users\chenhan\mywork\software\Hightec\AURIX_1G\TC264_Samrt_Car_Demo\0_Src\BaseSw\iLLD\TC26B\Tricore\Src\Std" -I"C:\Users\chenhan\mywork\software\Hightec\AURIX_1G\TC264_Samrt_Car_Demo\0_Src\BaseSw\iLLD\TC26B\Tricore\Stm" -I"C:\Users\chenhan\mywork\software\Hightec\AURIX_1G\TC264_Samrt_Car_Demo\0_Src\BaseSw\iLLD\TC26B\Tricore\Stm\Std" -I"C:\Users\chenhan\mywork\software\Hightec\AURIX_1G\TC264_Samrt_Car_Demo\0_Src\BaseSw\iLLD\TC26B\Tricore\Stm\Timer" -I"C:\Users\chenhan\mywork\software\Hightec\AURIX_1G\TC264_Samrt_Car_Demo\0_Src\BaseSw\iLLD\TC26B\Tricore\Vadc" -I"C:\Users\chenhan\mywork\software\Hightec\AURIX_1G\TC264_Samrt_Car_Demo\0_Src\BaseSw\iLLD\TC26B\Tricore\Vadc\Adc" -I"C:\Users\chenhan\mywork\software\Hightec\AURIX_1G\TC264_Samrt_Car_Demo\0_Src\BaseSw\iLLD\TC26B\Tricore\Vadc\Std" -I"C:\Users\chenhan\mywork\software\Hightec\AURIX_1G\TC264_Samrt_Car_Demo\0_Src\BaseSw\Infra" -I"C:\Users\chenhan\mywork\software\Hightec\AURIX_1G\TC264_Samrt_Car_Demo\0_Src\BaseSw\Infra\Platform" -I"C:\Users\chenhan\mywork\software\Hightec\AURIX_1G\TC264_Samrt_Car_Demo\0_Src\BaseSw\Infra\Platform\Tricore" -I"C:\Users\chenhan\mywork\software\Hightec\AURIX_1G\TC264_Samrt_Car_Demo\0_Src\BaseSw\Infra\Platform\Tricore\Compilers" -I"C:\Users\chenhan\mywork\software\Hightec\AURIX_1G\TC264_Samrt_Car_Demo\0_Src\BaseSw\Infra\Sfr" -I"C:\Users\chenhan\mywork\software\Hightec\AURIX_1G\TC264_Samrt_Car_Demo\0_Src\BaseSw\Infra\Sfr\TC26B" -I"C:\Users\chenhan\mywork\software\Hightec\AURIX_1G\TC264_Samrt_Car_Demo\0_Src\BaseSw\Infra\Sfr\TC26B\_Reg" -I"C:\Users\chenhan\mywork\software\Hightec\AURIX_1G\TC264_Samrt_Car_Demo\0_Src\BaseSw\Service" -I"C:\Users\chenhan\mywork\software\Hightec\AURIX_1G\TC264_Samrt_Car_Demo\0_Src\BaseSw\Service\CpuGeneric" -I"C:\Users\chenhan\mywork\software\Hightec\AURIX_1G\TC264_Samrt_Car_Demo\0_Src\BaseSw\Service\CpuGeneric\_Utilities" -I"C:\Users\chenhan\mywork\software\Hightec\AURIX_1G\TC264_Samrt_Car_Demo\0_Src\BaseSw\Service\CpuGeneric\If" -I"C:\Users\chenhan\mywork\software\Hightec\AURIX_1G\TC264_Samrt_Car_Demo\0_Src\BaseSw\Service\CpuGeneric\If\Ccu6If" -I"C:\Users\chenhan\mywork\software\Hightec\AURIX_1G\TC264_Samrt_Car_Demo\0_Src\BaseSw\Service\CpuGeneric\StdIf" -I"C:\Users\chenhan\mywork\software\Hightec\AURIX_1G\TC264_Samrt_Car_Demo\0_Src\BaseSw\Service\CpuGeneric\SysSe" -I"C:\Users\chenhan\mywork\software\Hightec\AURIX_1G\TC264_Samrt_Car_Demo\0_Src\BaseSw\Service\CpuGeneric\SysSe\Bsp" -I"C:\Users\chenhan\mywork\software\Hightec\AURIX_1G\TC264_Samrt_Car_Demo\0_Src\BaseSw\Service\CpuGeneric\SysSe\Comm" -I"C:\Users\chenhan\mywork\software\Hightec\AURIX_1G\TC264_Samrt_Car_Demo\0_Src\BaseSw\Service\CpuGeneric\SysSe\General" -I"C:\Users\chenhan\mywork\software\Hightec\AURIX_1G\TC264_Samrt_Car_Demo\0_Src\BaseSw\Service\CpuGeneric\SysSe\Math" -I"C:\Users\chenhan\mywork\software\Hightec\AURIX_1G\TC264_Samrt_Car_Demo\0_Src\BaseSw\Service\CpuGeneric\SysSe\Time" -fno-common -Os -g3 -W -Wall -Wextra -Wdiv-by-zero -Warray-bounds -Wcast-align -Wignored-qualifiers -Wformat -Wformat-security -pipe -DAPPKIT_TC265B -fshort-double -mcpu=tc26xx -mversion-info -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


