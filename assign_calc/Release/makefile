################################################################################
# Automatically-generated file. Do not edit!
################################################################################

-include ../makefile.init

RM := rm -rf

# All of the sources participating in the build are defined here
-include sources.mk
-include MCAL/DIO/subdir.mk
-include HAL/LCD/subdir.mk
-include HAL/KEYPAD/subdir.mk
-include APP/subdir.mk
-include subdir.mk
-include objects.mk

ifneq ($(MAKECMDGOALS),clean)
ifneq ($(strip $(ASM_DEPS)),)
-include $(ASM_DEPS)
endif
ifneq ($(strip $(S_DEPS)),)
-include $(S_DEPS)
endif
ifneq ($(strip $(S_UPPER_DEPS)),)
-include $(S_UPPER_DEPS)
endif
ifneq ($(strip $(C_DEPS)),)
-include $(C_DEPS)
endif
endif

-include ../makefile.defs

# Add inputs and outputs from these tool invocations to the build variables 
LSS += \
assign_calc.lss \

FLASH_IMAGE += \
assign_calc.hex \

EEPROM_IMAGE += \
assign_calc.eep \

SIZEDUMMY += \
sizedummy \


# All Target
all: assign_calc.elf secondary-outputs

# Tool invocations
assign_calc.elf: $(OBJS) $(USER_OBJS)
	@echo 'Building target: $@'
	@echo 'Invoking: AVR C Linker'
	avr-gcc -Wl,-Map,assign_calc.map -mmcu=atmega32 -o "assign_calc.elf" $(OBJS) $(USER_OBJS) $(LIBS)
	@echo 'Finished building target: $@'
	@echo ' '

assign_calc.lss: assign_calc.elf
	@echo 'Invoking: AVR Create Extended Listing'
	-avr-objdump -h -S assign_calc.elf  >"assign_calc.lss"
	@echo 'Finished building: $@'
	@echo ' '

assign_calc.hex: assign_calc.elf
	@echo 'Create Flash image (ihex format)'
	-avr-objcopy -R .eeprom -R .fuse -R .lock -R .signature -O ihex assign_calc.elf  "assign_calc.hex"
	@echo 'Finished building: $@'
	@echo ' '

assign_calc.eep: assign_calc.elf
	@echo 'Create eeprom image (ihex format)'
	-avr-objcopy -j .eeprom --no-change-warnings --change-section-lma .eeprom=0 -O ihex assign_calc.elf  "assign_calc.eep"
	@echo 'Finished building: $@'
	@echo ' '

sizedummy: assign_calc.elf
	@echo 'Invoking: Print Size'
	-avr-size --format=avr --mcu=atmega32 assign_calc.elf
	@echo 'Finished building: $@'
	@echo ' '

# Other Targets
clean:
	-$(RM) $(FLASH_IMAGE)$(ELFS)$(OBJS)$(ASM_DEPS)$(EEPROM_IMAGE)$(S_DEPS)$(SIZEDUMMY)$(S_UPPER_DEPS)$(LSS)$(C_DEPS) assign_calc.elf
	-@echo ' '

secondary-outputs: $(LSS) $(FLASH_IMAGE) $(EEPROM_IMAGE) $(SIZEDUMMY)

.PHONY: all clean dependents
.SECONDARY:

-include ../makefile.targets
