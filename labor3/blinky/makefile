.PHONY: all
all: blinky.bin

blinky.bin: blinky.elf
	arm-none-eabi-objcopy -O binary -S blinky.elf blinky.bin

blinky.elf: blinky.o
	arm-none-eabi-gcc blinky.o -nostartfiles -Wl,-Ttext=0x8000000 -o blinky.elf -g

blinky.o: blinky.S
	arm-none-eabi-gcc blinky.S -mcpu=cortex-m4 -mthumb -c -o blinky.o -g

.PHONY: clean
clean:
	rm -f blinky.o blinky.elf blinky.bin

.PHONY: upload
upload: blinky.bin
	cp blinky.bin /media/$(USER)/NODE_L432KC

.PHONY: openocd
openocd: blinky.bin
	openocd -f nucleo-l4.cfg

.PHONY: GDB
GDB: blinky.bin
	gdb-multiarch blinky.elf -iex "target remote localhost:3333" -iex "monitor reset init" -iex "layout regs"

	
