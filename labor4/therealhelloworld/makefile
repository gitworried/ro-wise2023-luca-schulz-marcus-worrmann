# Compiler and flags
CC = arm-none-eabi-gcc
OBJCOPY = arm-none-eabi-objcopy
CFLAGS = -mcpu=cortex-m4 -mthumb -c
LDFLAGS = -mcpu=cortex-m4 -mthumb -nostartfiles -Wl,-Ttext=0x8000000

# Source and object files
SRC = therealhelloworld.bin therealhelloworld.elf therealhelloworld.o usart.o head.o
OBJ = head.o usart.o therealhelloworld.o

# Phony targets
.PHONY: all clean upload doxygen

# Default target
all: $(SRC)

# Binary file generation
therealhelloworld.bin: therealhelloworld.elf
	$(OBJCOPY) -O binary -S $< $@

# ELF file generation
therealhelloworld.elf: $(OBJ)
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

# Rule therealhelloworld.c to therealhelloworld.o
therealhelloworld.elf: head.o usart.o therealhelloworld.o
	$(CC) head.o usart.o therealhelloworld.o -mcpu=cortex-m0 -mthumb -nostartfiles -Wl,-Ttext=0x8000000 -o $@

# Doxygen
doxygen:
	doxygen Doxyfile
	cd latex && $(MAKE)
	cp latex/refman.pdf ./Docu.pdf
# Clean up
clean:
	rm $(SRC)
	rm -rf latex html	

# Upload binary to the device
upload:
	cp therealhelloworld.bin /media/$(USER)/NODE_L432KC
