# command
CC = riscv64-unknown-elf-gcc
OBJCOPY=riscv64-unknown-elf-objcopy

# args
CFLAGS=-c -march=rv32i -mabi=ilp32 -O0 -Wall -g
BINFLAGS=-S -O binary
ELFLAGS=-march=rv32i -mabi=ilp32

# files
ALLSFILE=$(wildcard *.S)
ALLCFILE=$(wildcard *.c)
ALLSOBJS=$(ALLSFILE:.S=.o)
ALLCOBJS=$(ALLCFILE:.c=.o)
ALLOBJS=$(ALLSOBJS) $(ALLCOBJS)
MAINELF=main.elf


all: clean build link binary

run: $(MAINELF)
	qemu-riscv32 -g 1234 $<

# build: product *.o
build: $(ALLOBJS)

# binary: product *.o->*.bin
binary: $(ALLOBJS:.o=.bin)

# link: product main.elf dependence *.o
link: $(MAINELF)

.S.o:  #.S文件编译成.o文件, 等价于.o: .S
	$(CC) $(CFLAGS) $< -o $@
	
.c.o:
	$(CC) $(CFLAGS) $< -o $@
	
%.bin: %.o
	$(OBJCOPY) $(BINFLAGS) $< $@

%.elf: 
	$(CC) $(ELFLAGS) $(ALLOBJS) -o $@

.PHONY: clean
clean:
	rm -rf $(ALLOBJS) *.i *.o *.bin *.elf *.dump