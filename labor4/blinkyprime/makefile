# Compiler and flags
CC = arm-none-eabi-gcc
OBJCOPY = arm-none-eabi-objcopy
CFLAGS = -mcpu=cortex-m4 -mthumb -c
LDFLAGS = -mcpu=cortex-m4 -mthumb -nostartfiles -Wl,-Ttext=0x8000000

# Source and object files
SRC = blinkyprime.bin blinkyprime.elf blinkyprime.o usart.o head.o
OBJ = head.o usart.o blinkyprime.o

# Phony targets
.PHONY: all clean upload doxygen

# Default target
all: $(SRC)

# Binary file generation
blinkyprime.bin: blinkyprime.elf
	$(OBJCOPY) -O binary -S $< $@

# ELF file generation
blinkyprime.elf: $(OBJ)
	$(CC) $^ $(LDFLAGS) -o $@

# Object file generation from assembly or C source
%.o: %.S
	$(CC) $< $(CFLAGS) -o $@

%.o: %.c
	$(CC) $< $(CFLAGS) -o $@

# Rules

# Rule head.s to head.o
head.o: head.S
	arm-none-eabi-gcc $< -mcpu=cortex-m0 -mthumb -c -o $@

# Rule usart.c to usart.o
usart.o: usart.c
	arm-none-eabi-gcc $< -mcpu=cortex-m4 -mthumb -c -o $@

# Rule blinkyprime.c to blinkyprime.o
blinkyprime.elf: head.o usart.o blinkyprime.o
	$(CC) head.o usart.o blinkyprime.o -mcpu=cortex-m0 -mthumb -nostartfiles -Wl,-Ttext=0x8000000 -o $@

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
	cp blinkyprime.bin /media/$(USER)/NODE_L432KC
