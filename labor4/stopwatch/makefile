# Compiler and flags
CC = arm-none-eabi-gcc
OBJCOPY = arm-none-eabi-objcopy
CFLAGS = -mcpu=cortex-m4 -mthumb -c
LDFLAGS = -mcpu=cortex-m4 -mthumb -nostartfiles -Wl,-Ttext=0x8000000

# Source and object files
SRC = stopwatch.bin stopwatch.elf stopwatch.o usart.o head.o utils.o blinky.o
OBJ = utils.o blinky.o head.o usart.o stopwatch.o

# Phony targets
.PHONY: all clean upload doxygen

# Default target
all: $(SRC)

# Binary file generation
stopwatch.bin: stopwatch.elf
	$(OBJCOPY) -O binary -S $< $@

# ELF file generation
stopwatch.elf: $(OBJ)
	$(CC) $^ $(LDFLAGS) -o $@

# Object file generation from assembly or C source
%.o: %.S
	$(CC) $< $(CFLAGS) -o $@

%.o: %.c
	$(CC) $< $(CFLAGS) -o $@

# Doxygen
doxygen:
	doxygen Doxyfile
	cd latex && $(MAKE)
	cp latex/refman.pdf ./Docu.pdf
# Clean up
clean:
	rm $(SRC) *.pdf
	rm -rf latex html

# Upload binary to the device
upload:
	cp stopwatch.bin /media/$(USER)/NODE_L432KC
