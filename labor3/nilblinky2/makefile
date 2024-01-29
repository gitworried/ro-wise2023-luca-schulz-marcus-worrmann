.PHONY: all
all: nilblinky2.bin

nilblinky2.bin: nilblinky2.elf
	arm-none-eabi-objcopy -O binary -S nilblinky2.elf nilblinky2.bin

nilblinky2.elf: nilblinky2.o
	arm-none-eabi-gcc nilblinky2.o -mcpu=cortex-m0 -mthumb -nostartfiles -Wl,-Ttext=0x8000000 -o nilblinky2.elf -g

nilblinky2.o: nilblinky2.S
	arm-none-eabi-gcc nilblinky2.S -mcpu=cortex-m4 -mthumb -c -o nilblinky2.o -g

.PHONY: clean
clean:
	rm -f nilblinky2.o nilblinky2.elf nilblinky2.bin

.PHONY: upload
upload: nilblinky2.bin
	cp nilblinky2.bin /media/${USER}/NODE_L432KC

.PHONY: openocd
openocd: nilblinky2.bin
	openocd -f nucleo-l4.cfg

.PHONY: GDB
GDB: nilblinky2.bin
	gdb-multiarch nilblinky2.elf -iex "target remote localhost:3333" -iex "monitor reset init" -iex "layout regs"