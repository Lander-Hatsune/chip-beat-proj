################################################################################
# Automatically-generated file. Do not edit!
################################################################################

-include ../makefile.init

RM := rm -rf

# All of the sources participating in the build are defined here
-include sources.mk
-include 0_Src/BaseSw/iLLD/TC26B/Tricore/_PinMap/subdir.mk
-include 0_Src/BaseSw/iLLD/TC26B/Tricore/_Lib/InternalMux/subdir.mk
-include 0_Src/BaseSw/iLLD/TC26B/Tricore/_Lib/DataHandling/subdir.mk
-include 0_Src/BaseSw/iLLD/TC26B/Tricore/_Impl/subdir.mk
-include 0_Src/BaseSw/iLLD/TC26B/Tricore/Vadc/Std/subdir.mk
-include 0_Src/BaseSw/iLLD/TC26B/Tricore/Vadc/Adc/subdir.mk
-include 0_Src/BaseSw/iLLD/TC26B/Tricore/Stm/Timer/subdir.mk
-include 0_Src/BaseSw/iLLD/TC26B/Tricore/Stm/Std/subdir.mk
-include 0_Src/BaseSw/iLLD/TC26B/Tricore/Src/Std/subdir.mk
-include 0_Src/BaseSw/iLLD/TC26B/Tricore/Scu/Std/subdir.mk
-include 0_Src/BaseSw/iLLD/TC26B/Tricore/Port/Std/subdir.mk
-include 0_Src/BaseSw/iLLD/TC26B/Tricore/Port/Io/subdir.mk
-include 0_Src/BaseSw/iLLD/TC26B/Tricore/I2c/Std/subdir.mk
-include 0_Src/BaseSw/iLLD/TC26B/Tricore/I2c/I2c/subdir.mk
-include 0_Src/BaseSw/iLLD/TC26B/Tricore/Gtm/Trig/subdir.mk
-include 0_Src/BaseSw/iLLD/TC26B/Tricore/Gtm/Tom/Timer/subdir.mk
-include 0_Src/BaseSw/iLLD/TC26B/Tricore/Gtm/Tom/PwmHl/subdir.mk
-include 0_Src/BaseSw/iLLD/TC26B/Tricore/Gtm/Tom/Pwm/subdir.mk
-include 0_Src/BaseSw/iLLD/TC26B/Tricore/Gtm/Tim/In/subdir.mk
-include 0_Src/BaseSw/iLLD/TC26B/Tricore/Gtm/Std/subdir.mk
-include 0_Src/BaseSw/iLLD/TC26B/Tricore/Gtm/Atom/Timer/subdir.mk
-include 0_Src/BaseSw/iLLD/TC26B/Tricore/Gtm/Atom/PwmHl/subdir.mk
-include 0_Src/BaseSw/iLLD/TC26B/Tricore/Gtm/Atom/Pwm/subdir.mk
-include 0_Src/BaseSw/iLLD/TC26B/Tricore/Dma/Std/subdir.mk
-include 0_Src/BaseSw/iLLD/TC26B/Tricore/Dma/Dma/subdir.mk
-include 0_Src/BaseSw/iLLD/TC26B/Tricore/Cpu/Trap/subdir.mk
-include 0_Src/BaseSw/iLLD/TC26B/Tricore/Cpu/Std/subdir.mk
-include 0_Src/BaseSw/iLLD/TC26B/Tricore/Cpu/Irq/subdir.mk
-include 0_Src/BaseSw/iLLD/TC26B/Tricore/Cpu/CStart/subdir.mk
-include 0_Src/BaseSw/iLLD/TC26B/Tricore/Ccu6/TimerWithTrigger/subdir.mk
-include 0_Src/BaseSw/iLLD/TC26B/Tricore/Ccu6/Timer/subdir.mk
-include 0_Src/BaseSw/iLLD/TC26B/Tricore/Ccu6/TPwm/subdir.mk
-include 0_Src/BaseSw/iLLD/TC26B/Tricore/Ccu6/Std/subdir.mk
-include 0_Src/BaseSw/iLLD/TC26B/Tricore/Ccu6/PwmHl/subdir.mk
-include 0_Src/BaseSw/iLLD/TC26B/Tricore/Ccu6/PwmBc/subdir.mk
-include 0_Src/BaseSw/iLLD/TC26B/Tricore/Ccu6/Icu/subdir.mk
-include 0_Src/BaseSw/iLLD/TC26B/Tricore/Asclin/Std/subdir.mk
-include 0_Src/BaseSw/iLLD/TC26B/Tricore/Asclin/Spi/subdir.mk
-include 0_Src/BaseSw/iLLD/TC26B/Tricore/Asclin/Lin/subdir.mk
-include 0_Src/BaseSw/iLLD/TC26B/Tricore/Asclin/Asc/subdir.mk
-include 0_Src/BaseSw/Service/CpuGeneric/SysSe/Time/subdir.mk
-include 0_Src/BaseSw/Service/CpuGeneric/SysSe/Math/subdir.mk
-include 0_Src/BaseSw/Service/CpuGeneric/SysSe/General/subdir.mk
-include 0_Src/BaseSw/Service/CpuGeneric/SysSe/Comm/subdir.mk
-include 0_Src/BaseSw/Service/CpuGeneric/SysSe/Bsp/subdir.mk
-include 0_Src/BaseSw/Service/CpuGeneric/StdIf/subdir.mk
-include 0_Src/BaseSw/Service/CpuGeneric/If/subdir.mk
-include 0_Src/BaseSw/Infra/Platform/Tricore/Compilers/subdir.mk
-include 0_Src/AppSw/Tricore/Main/subdir.mk
-include 0_Src/AppSw/CpuGeneric/Config/subdir.mk
-include subdir.mk
-include objects.mk

ifneq ($(MAKECMDGOALS),clean)
ifneq ($(strip $(I_DEPS)),)
-include $(I_DEPS)
endif
ifneq ($(strip $(C_DEPS)),)
-include $(C_DEPS)
endif
ifneq ($(strip $(CPCP_DEPS)),)
-include $(CPCP_DEPS)
endif
endif

-include ../makefile.defs

# Add inputs and outputs from these tool invocations to the build variables 

#rebuild target
rebuild: clean all

# All Target
all: TC264_Samrt_Car_Demo_v2.2.elf

# Tool invocations
TC264_Samrt_Car_Demo_v2.2.elf: $(OBJS) $(USER_OBJS) $(ASM)
	@echo 'Building target: $@'
	@echo 'Invoking: TriCore C Linker'
	"$(TRICORE_TOOLS)/bin/tricore-gcc" -o  "TC264_Samrt_Car_Demo_v2.2.elf" -nocrt0 -T"C:\Users\kuaile\Documents\TC264_Samrt_Car_Demo_v2.0\1_ToolEnv\0_Build\1_Config\Lcf_Gnuc.lsl" "0_Src\AppSw\CpuGeneric\Config\Ifx_InterfaceConst.o" "0_Src\AppSw\Tricore\Main\AsclinApp.o" "0_Src\AppSw\Tricore\Main\CameraOV7620.o" "0_Src\AppSw\Tricore\Main\Cpu0_Main.o" "0_Src\AppSw\Tricore\Main\Cpu1_Main.o" "0_Src\AppSw\Tricore\Main\Mpu6050.o" "0_Src\AppSw\Tricore\Main\PwmDemo.o" "0_Src\AppSw\Tricore\Main\ServeSource.o" "0_Src\AppSw\Tricore\Main\StmDemo.o" "0_Src\AppSw\Tricore\Main\TimDemo.o" "0_Src\AppSw\Tricore\Main\UserSource.o" "0_Src\AppSw\Tricore\Main\VadcApp.o" "0_Src\BaseSw\Infra\Platform\Tricore\Compilers\CompilerDcc.o" "0_Src\BaseSw\Infra\Platform\Tricore\Compilers\CompilerGhs.o" "0_Src\BaseSw\Infra\Platform\Tricore\Compilers\CompilerGnuc.o" "0_Src\BaseSw\Infra\Platform\Tricore\Compilers\CompilerTasking.o" "0_Src\BaseSw\Service\CpuGeneric\If\SpiIf.o" "0_Src\BaseSw\Service\CpuGeneric\StdIf\IfxStdIf_DPipe.o" "0_Src\BaseSw\Service\CpuGeneric\StdIf\IfxStdIf_Pos.o" "0_Src\BaseSw\Service\CpuGeneric\StdIf\IfxStdIf_PwmHl.o" "0_Src\BaseSw\Service\CpuGeneric\StdIf\IfxStdIf_Timer.o" "0_Src\BaseSw\Service\CpuGeneric\SysSe\Bsp\Assert.o" "0_Src\BaseSw\Service\CpuGeneric\SysSe\Bsp\Bsp.o" "0_Src\BaseSw\Service\CpuGeneric\SysSe\Comm\Ifx_Console.o" "0_Src\BaseSw\Service\CpuGeneric\SysSe\Comm\Ifx_Shell.o" "0_Src\BaseSw\Service\CpuGeneric\SysSe\General\Ifx_GlobalResources.o" "0_Src\BaseSw\Service\CpuGeneric\SysSe\Math\Ifx_AngleTrkF32.o" "0_Src\BaseSw\Service\CpuGeneric\SysSe\Math\Ifx_Cf32.o" "0_Src\BaseSw\Service\CpuGeneric\SysSe\Math\Ifx_Crc.o" "0_Src\BaseSw\Service\CpuGeneric\SysSe\Math\Ifx_FftF32.o" "0_Src\BaseSw\Service\CpuGeneric\SysSe\Math\Ifx_FftF32_BitReverseTable.o" "0_Src\BaseSw\Service\CpuGeneric\SysSe\Math\Ifx_FftF32_TwiddleTable.o" "0_Src\BaseSw\Service\CpuGeneric\SysSe\Math\Ifx_IntegralF32.o" "0_Src\BaseSw\Service\CpuGeneric\SysSe\Math\Ifx_LowPassPt1F32.o" "0_Src\BaseSw\Service\CpuGeneric\SysSe\Math\Ifx_LutAtan2F32.o" "0_Src\BaseSw\Service\CpuGeneric\SysSe\Math\Ifx_LutAtan2F32_Table.o" "0_Src\BaseSw\Service\CpuGeneric\SysSe\Math\Ifx_LutLSincosF32.o" "0_Src\BaseSw\Service\CpuGeneric\SysSe\Math\Ifx_LutLinearF32.o" "0_Src\BaseSw\Service\CpuGeneric\SysSe\Math\Ifx_LutSincosF32.o" "0_Src\BaseSw\Service\CpuGeneric\SysSe\Math\Ifx_LutSincosF32_Table.o" "0_Src\BaseSw\Service\CpuGeneric\SysSe\Math\Ifx_RampF32.o" "0_Src\BaseSw\Service\CpuGeneric\SysSe\Math\Ifx_WndF32_BlackmanHarrisTable.o" "0_Src\BaseSw\Service\CpuGeneric\SysSe\Math\Ifx_WndF32_HannTable.o" "0_Src\BaseSw\Service\CpuGeneric\SysSe\Time\Ifx_DateTime.o" "0_Src\BaseSw\iLLD\TC26B\Tricore\Asclin\Asc\IfxAsclin_Asc.o" "0_Src\BaseSw\iLLD\TC26B\Tricore\Asclin\Lin\IfxAsclin_Lin.o" "0_Src\BaseSw\iLLD\TC26B\Tricore\Asclin\Spi\IfxAsclin_Spi.o" "0_Src\BaseSw\iLLD\TC26B\Tricore\Asclin\Std\IfxAsclin.o" "0_Src\BaseSw\iLLD\TC26B\Tricore\Ccu6\Icu\IfxCcu6_Icu.o" "0_Src\BaseSw\iLLD\TC26B\Tricore\Ccu6\PwmBc\IfxCcu6_PwmBc.o" "0_Src\BaseSw\iLLD\TC26B\Tricore\Ccu6\PwmHl\IfxCcu6_PwmHl.o" "0_Src\BaseSw\iLLD\TC26B\Tricore\Ccu6\Std\IfxCcu6.o" "0_Src\BaseSw\iLLD\TC26B\Tricore\Ccu6\TPwm\IfxCcu6_TPwm.o" "0_Src\BaseSw\iLLD\TC26B\Tricore\Ccu6\Timer\IfxCcu6_Timer.o" "0_Src\BaseSw\iLLD\TC26B\Tricore\Ccu6\TimerWithTrigger\IfxCcu6_TimerWithTrigger.o" "0_Src\BaseSw\iLLD\TC26B\Tricore\Cpu\CStart\IfxCpu_CStart0.o" "0_Src\BaseSw\iLLD\TC26B\Tricore\Cpu\CStart\IfxCpu_CStart1.o" "0_Src\BaseSw\iLLD\TC26B\Tricore\Cpu\Irq\IfxCpu_Irq.o" "0_Src\BaseSw\iLLD\TC26B\Tricore\Cpu\Std\IfxCpu.o" "0_Src\BaseSw\iLLD\TC26B\Tricore\Cpu\Trap\IfxCpu_Trap.o" "0_Src\BaseSw\iLLD\TC26B\Tricore\Dma\Dma\IfxDma_Dma.o" "0_Src\BaseSw\iLLD\TC26B\Tricore\Dma\Std\IfxDma.o" "0_Src\BaseSw\iLLD\TC26B\Tricore\Gtm\Atom\Pwm\IfxGtm_Atom_Pwm.o" "0_Src\BaseSw\iLLD\TC26B\Tricore\Gtm\Atom\PwmHl\IfxGtm_Atom_PwmHl.o" "0_Src\BaseSw\iLLD\TC26B\Tricore\Gtm\Atom\Timer\IfxGtm_Atom_Timer.o" "0_Src\BaseSw\iLLD\TC26B\Tricore\Gtm\Std\IfxGtm.o" "0_Src\BaseSw\iLLD\TC26B\Tricore\Gtm\Std\IfxGtm_Atom.o" "0_Src\BaseSw\iLLD\TC26B\Tricore\Gtm\Std\IfxGtm_Cmu.o" "0_Src\BaseSw\iLLD\TC26B\Tricore\Gtm\Std\IfxGtm_Dpll.o" "0_Src\BaseSw\iLLD\TC26B\Tricore\Gtm\Std\IfxGtm_Tbu.o" "0_Src\BaseSw\iLLD\TC26B\Tricore\Gtm\Std\IfxGtm_Tim.o" "0_Src\BaseSw\iLLD\TC26B\Tricore\Gtm\Std\IfxGtm_Tom.o" "0_Src\BaseSw\iLLD\TC26B\Tricore\Gtm\Tim\In\IfxGtm_Tim_In.o" "0_Src\BaseSw\iLLD\TC26B\Tricore\Gtm\Tom\Pwm\IfxGtm_Tom_Pwm.o" "0_Src\BaseSw\iLLD\TC26B\Tricore\Gtm\Tom\PwmHl\IfxGtm_Tom_PwmHl.o" "0_Src\BaseSw\iLLD\TC26B\Tricore\Gtm\Tom\Timer\IfxGtm_Tom_Timer.o" "0_Src\BaseSw\iLLD\TC26B\Tricore\Gtm\Trig\IfxGtm_Trig.o" "0_Src\BaseSw\iLLD\TC26B\Tricore\I2c\I2c\IfxI2c_I2c.o" "0_Src\BaseSw\iLLD\TC26B\Tricore\I2c\Std\IfxI2c.o" "0_Src\BaseSw\iLLD\TC26B\Tricore\Port\Io\IfxPort_Io.o" "0_Src\BaseSw\iLLD\TC26B\Tricore\Port\Std\IfxPort.o" "0_Src\BaseSw\iLLD\TC26B\Tricore\Scu\Std\IfxScuCcu.o" "0_Src\BaseSw\iLLD\TC26B\Tricore\Scu\Std\IfxScuEru.o" "0_Src\BaseSw\iLLD\TC26B\Tricore\Scu\Std\IfxScuWdt.o" "0_Src\BaseSw\iLLD\TC26B\Tricore\Src\Std\IfxSrc.o" "0_Src\BaseSw\iLLD\TC26B\Tricore\Stm\Std\IfxStm.o" "0_Src\BaseSw\iLLD\TC26B\Tricore\Stm\Timer\IfxStm_Timer.o" "0_Src\BaseSw\iLLD\TC26B\Tricore\Vadc\Adc\IfxVadc_Adc.o" "0_Src\BaseSw\iLLD\TC26B\Tricore\Vadc\Std\IfxVadc.o" "0_Src\BaseSw\iLLD\TC26B\Tricore\_Impl\IfxAsclin_cfg.o" "0_Src\BaseSw\iLLD\TC26B\Tricore\_Impl\IfxCcu6_cfg.o" "0_Src\BaseSw\iLLD\TC26B\Tricore\_Impl\IfxCif_cfg.o" "0_Src\BaseSw\iLLD\TC26B\Tricore\_Impl\IfxCpu_cfg.o" "0_Src\BaseSw\iLLD\TC26B\Tricore\_Impl\IfxDma_cfg.o" "0_Src\BaseSw\iLLD\TC26B\Tricore\_Impl\IfxEmem_cfg.o" "0_Src\BaseSw\iLLD\TC26B\Tricore\_Impl\IfxEray_cfg.o" "0_Src\BaseSw\iLLD\TC26B\Tricore\_Impl\IfxFft_cfg.o" "0_Src\BaseSw\iLLD\TC26B\Tricore\_Impl\IfxFlash_cfg.o" "0_Src\BaseSw\iLLD\TC26B\Tricore\_Impl\IfxGtm_cfg.o" "0_Src\BaseSw\iLLD\TC26B\Tricore\_Impl\IfxHssl_cfg.o" "0_Src\BaseSw\iLLD\TC26B\Tricore\_Impl\IfxI2c_cfg.o" "0_Src\BaseSw\iLLD\TC26B\Tricore\_Impl\IfxMsc_cfg.o" "0_Src\BaseSw\iLLD\TC26B\Tricore\_Impl\IfxMtu_cfg.o" "0_Src\BaseSw\iLLD\TC26B\Tricore\_Impl\IfxMultican_cfg.o" "0_Src\BaseSw\iLLD\TC26B\Tricore\_Impl\IfxPort_cfg.o" "0_Src\BaseSw\iLLD\TC26B\Tricore\_Impl\IfxPsi5_cfg.o" "0_Src\BaseSw\iLLD\TC26B\Tricore\_Impl\IfxPsi5s_cfg.o" "0_Src\BaseSw\iLLD\TC26B\Tricore\_Impl\IfxQspi_cfg.o" "0_Src\BaseSw\iLLD\TC26B\Tricore\_Impl\IfxScu_cfg.o" "0_Src\BaseSw\iLLD\TC26B\Tricore\_Impl\IfxSent_cfg.o" "0_Src\BaseSw\iLLD\TC26B\Tricore\_Impl\IfxSmu_cfg.o" "0_Src\BaseSw\iLLD\TC26B\Tricore\_Impl\IfxSrc_cfg.o" "0_Src\BaseSw\iLLD\TC26B\Tricore\_Impl\IfxStm_cfg.o" "0_Src\BaseSw\iLLD\TC26B\Tricore\_Impl\IfxVadc_cfg.o" "0_Src\BaseSw\iLLD\TC26B\Tricore\_Lib\DataHandling\Ifx_CircularBuffer.asm.o" "0_Src\BaseSw\iLLD\TC26B\Tricore\_Lib\DataHandling\Ifx_CircularBuffer.o" "0_Src\BaseSw\iLLD\TC26B\Tricore\_Lib\DataHandling\Ifx_Fifo.o" "0_Src\BaseSw\iLLD\TC26B\Tricore\_Lib\InternalMux\Ifx_InternalMux.o" "0_Src\BaseSw\iLLD\TC26B\Tricore\_PinMap\IfxAsclin_PinMap.o" "0_Src\BaseSw\iLLD\TC26B\Tricore\_PinMap\IfxCcu6_PinMap.o" "0_Src\BaseSw\iLLD\TC26B\Tricore\_PinMap\IfxCif_PinMap.o" "0_Src\BaseSw\iLLD\TC26B\Tricore\_PinMap\IfxDsadc_PinMap.o" "0_Src\BaseSw\iLLD\TC26B\Tricore\_PinMap\IfxEray_PinMap.o" "0_Src\BaseSw\iLLD\TC26B\Tricore\_PinMap\IfxEth_PinMap.o" "0_Src\BaseSw\iLLD\TC26B\Tricore\_PinMap\IfxGpt12_PinMap.o" "0_Src\BaseSw\iLLD\TC26B\Tricore\_PinMap\IfxGtm_PinMap.o" "0_Src\BaseSw\iLLD\TC26B\Tricore\_PinMap\IfxI2c_PinMap.o" "0_Src\BaseSw\iLLD\TC26B\Tricore\_PinMap\IfxMsc_PinMap.o" "0_Src\BaseSw\iLLD\TC26B\Tricore\_PinMap\IfxMultican_PinMap.o" "0_Src\BaseSw\iLLD\TC26B\Tricore\_PinMap\IfxPort_PinMap.o" "0_Src\BaseSw\iLLD\TC26B\Tricore\_PinMap\IfxPsi5_PinMap.o" "0_Src\BaseSw\iLLD\TC26B\Tricore\_PinMap\IfxPsi5s_PinMap.o" "0_Src\BaseSw\iLLD\TC26B\Tricore\_PinMap\IfxQspi_PinMap.o" "0_Src\BaseSw\iLLD\TC26B\Tricore\_PinMap\IfxScu_PinMap.o" "0_Src\BaseSw\iLLD\TC26B\Tricore\_PinMap\IfxSent_PinMap.o" "0_Src\BaseSw\iLLD\TC26B\Tricore\_PinMap\IfxSmu_PinMap.o" "0_Src\BaseSw\iLLD\TC26B\Tricore\_PinMap\IfxVadc_PinMap.o" -Wl,--gc-sections -mcpu=tc26xx -Wl,--mem-holes -Wl,--no-warn-flags -Wl,-Map="$(basename $(notdir $@)).map" -Wl,--cref -fshort-double -Wl,-n -Wl,--extmap="a"
	@echo 'Finished building target: $@'
	@echo ' '

# Other Targets
clean:
	-$(RM) $(I_DEPS)$(PCP_S)$(EXECUTABLES)$(OBJS)$(C_DEPS)$(CPCP_DEPS) TC264_Samrt_Car_Demo_v2.2.elf
	-@echo ' '

.PHONY: all clean dependents

-include ../makefile.targets
