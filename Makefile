#!/usb/bin/env make
CC=/usr/bin/gcc
ASM=/usr/bin/fasm
CFLAGS=-O2 -march=native -nostdlib -m32 -pie -g -I"./src/" -fno-stack-protector -Wno-builtin-declaration-mismatch
C_FILES= $(wildcard src/*.c)
AS_FILES= $(wildcard src/*.s)

C_LIBS= $(wildcard src/lib/*.c)
AS_LIBS=$(wildcard src/lib/*.s)

LIBS= $(wildcard libs/*.o)

LDFLAGS=-m elf_i386 -e _start -T src/link.ld
LD=/usr/bin/ld
OBJECTS=$(addsuffix .o, $(basename $(AS_FILES) $(C_FILES) $(C_LIBS) $(AS_LIBS) ) )

$(addsuffix .o, $(basename $(AS_FILES) ) ):
	@$(ASM) $(addsuffix .s, $(basename $@ ) ) obj/$(notdir $@ )

$(addsuffix .o, $(basename $(AS_LIBS) ) ):
	@$(ASM) $(addsuffix .s, $(basename $@ ) ) obj/$(notdir $@)

$(addsuffix .o, $(basename $(C_FILES) ) ):
	@$(CC) -c $(CFLAGS) $(addsuffix .c, $(basename $@) )
	@mv $(notdir $@) obj/

$(addsuffix .o, $(basename $(C_LIBS) ) ):
	@$(CC) -c $(CFLAGS) $(addsuffix .c, $(basename $@) )
	@mv $(notdir $@) obj/

all: $(OBJECTS)
	@echo 	LINKING		
	$(LD) $(wildcard obj/*.o) $(LIBS) $(LDFLAGS) -o bin/main

clean:
	@rm -f obj/*
	@rm -f bin/*
	@rm -f src/*.o

run:
	qemu-system-x86_64 -kernel bin/main

debug:
	qemu-system-i386 -kernel bin/main -S -s &
	sleep 5
	gdb bin/main -iex "target remote localhost:1234" -iex "set disassebly-flavor intel"
