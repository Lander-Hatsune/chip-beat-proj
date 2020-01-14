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
all: TC264_Samrt_Car_Demo_v2.0.elf

# Tool invocations
TC264_Samrt_Car_Demo_v2.0.elf: $(OBJS) $(USER_OBJS) $(ASM)
	@echo 'Building target: $@'
	@echo 'Invoking: TriCore C Linker'
	"$(TRICORE_TOOLS)/bin/tricore-gcc" -o  "TC264_Samrt_Car_Demo_v2.0.elf" @"Default.objectlist" -Wl,--gc-sections -mcpu=tc26xx -Wl,--mem-holes -Wl,-Map="$(basename $(notdir $@)).map" -Wl,--cref -fshort-double -Wl,-n -Wl,--extmap="a"
	@echo 'Finished building target: $@'
	@echo ' '

# Other Targets
clean:
	-$(RM) $(I_DEPS)$(PCP_S)$(EXECUTABLES)$(OBJS)$(C_DEPS)$(CPCP_DEPS) TC264_Samrt_Car_Demo_v2.0.elf
	-@echo ' '

.PHONY: all clean dependents

-include ../makefile.targets
