.PHONY: all
all: nilblinky.bin

nilblinky.bin: nilblinky.elf
	arm-none-eabi-objcopy -O binary -S nilblinky.elf nilblinky.bin

nilblinky.elf: nilblinky.o
	arm-none-eabi-gcc nilblinky.o -mcpu=cortex-m0 -mthumb -nostartfiles -Wl,-Ttext=0x8000000 -o nilblinky.elf -g

nilblinky.o: nilblinky.S
	arm-none-eabi-gcc nilblinky.S -mcpu=cortex-m4 -mthumb -c -o nilblinky.o -g

.PHONY: clean
clean:
	rm -f nilblinky.o nilblinky.elf nilblinky.bin

.PHONY: upload
upload: nilblinky.bin
	cp nilblinky.bin /media/${USER}/NODE_L432KC

.PHONY: openocd
openocd: nilblinky.bin
	openocd -f nucleo-l4.cfg

.PHONY: GDB
GDB: nilblinky.bin
	gdb-multiarch nilblinky.elf -iex "target remote localhost:3333" -iex "monitor reset init" -iex "layout regs"