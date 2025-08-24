# Target
TARGET = main
BUILD  = build

# Toolchain
CC     = arm-none-eabi-gcc
OBJCOPY= arm-none-eabi-objcopy
SIZE   = arm-none-eabi-size
OBJDUMP= arm-none-eabi-objdump
NM     = arm-none-eabi-nm

# Compiler flags
CFLAGS = -mcpu=cortex-m4 -mthumb -O2 -Wall -Wextra -ffreestanding \
         -Istm32f4_prj/core/inc \
         -Istm32f4_prj/drivers/cmsis/core/CMSIS/Core/Include \
         -Istm32f4_prj/drivers/cmsis/device/Include \
         -Istm32f4_prj/drivers/stm32f4xx-hal-driver/Inc \
         -DSTM32F407xx

# Linker flags
LDFLAGS= -T stm32f4_prj/STM32F407VGTX_FLASH.ld -nostartfiles -Wl,-Map=$(BUILD)/$(TARGET).map

# Source files
SRC = stm32f4_prj/core/src/startup_stm32f407vgtx.s
SRC += $(shell find stm32f4_prj/core/src/ -name '*.c')
# SRC += $(wildcard stm32f4_prj/drivers/stm32f4xx-hal-driver/Src/*.c)
SRC += \
    stm32f4_prj/drivers/stm32f4xx-hal-driver/Src/stm32f4xx_hal.c \
    stm32f4_prj/drivers/stm32f4xx-hal-driver/Src/stm32f4xx_hal_dma.c \
    stm32f4_prj/drivers/stm32f4xx-hal-driver/Src/stm32f4xx_hal_tim_ex.c \
    stm32f4_prj/drivers/stm32f4xx-hal-driver/Src/stm32f4xx_hal_gpio.c \
    stm32f4_prj/drivers/stm32f4xx-hal-driver/Src/stm32f4xx_hal_rcc.c \
    stm32f4_prj/drivers/stm32f4xx-hal-driver/Src/stm32f4xx_hal_tim.c \
    stm32f4_prj/drivers/stm32f4xx-hal-driver/Src/stm32f4xx_hal_cortex.c

# Add UNIT_TEST define and include path if requested
ifeq ($(UNIT_TEST),1)
    CFLAGS += -DUNIT_TEST -Istm32f4_prj/tests/unity/src -Istm32f4_prj/tests
    SRC += stm32f4_prj/tests/unity/src/unity.c \
           stm32f4_prj/tests/test_runner.c \
           stm32f4_prj/tests/test_bsp.c
endif

# Object files
OBJ = $(SRC:%.c=$(BUILD)/%.o)
OBJ := $(OBJ:%.s=$(BUILD)/%.o)

# Compile C files
$(BUILD)/%.o: %.c
	@mkdir -p $(dir $@)
	$(CC) $(CFLAGS) -c $< -o $@

# Compile ASM files
$(BUILD)/%.o: %.s
	@mkdir -p $(dir $@)
	$(CC) $(CFLAGS) -c $< -o $@

# Default target
all: $(BUILD)/$(TARGET).elf

# Link and generate binary
$(BUILD)/$(TARGET).elf: $(OBJ)
	@mkdir -p $(dir $@)
	$(CC) $(CFLAGS) $(OBJ) $(LDFLAGS) -o $@
	$(OBJCOPY) -O binary $@ $(BUILD)/$(TARGET).bin
#	@echo "===== Memory Usage ====="
#	$(SIZE) -A $@
#	@echo "===== Section Dump ====="
#	$(OBJDUMP) -h $@
#	@echo "===== Symbols by Size ====="
#	$(NM) -S --size-sort $@
	@echo "===== Quick Memory Summary ====="
	$(SIZE) build/$(TARGET).elf
	@echo "Flash used: $(shell arm-none-eabi-size -A build/$(TARGET).elf | grep FLASH | awk '{print $$2}') bytes"
	@echo "RAM used:   $(shell arm-none-eabi-size -A build/$(TARGET).elf | grep RAM | awk '{print $$2}') bytes"

# Flash via OpenOCD
flash: all
	openocd -f interface/stlink.cfg -f target/stm32f4x.cfg \
	        -c "program $(BUILD)/$(TARGET).elf verify reset"

# Start OpenOCD server
# start:
#	openocd -f interface/stlink.cfg -f target/stm32f4x.cfg

# Debug with GDB
debug: all
	gdb-multiarch $(BUILD)/$(TARGET).elf \
		-ex "target remote localhost:3333" \
		-ex "monitor reset" \
		-ex "continue"

# Clean build files
clean:
	rm -rf $(BUILD)

# Combined rule: clean, build and flash
do: clean all flash

# Run unit tests build
test: clean
	$(MAKE) UNIT_TEST=1
	$(MAKE) flash
