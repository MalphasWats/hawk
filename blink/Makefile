LDSCRIPT = lib/linker_scripts/samd10c14a_flash.ld
BOOTUP = lib/startup_samd10.o lib/system_samd10.o
MCUTYPE=__SAMD10C14A__

OBJS=$(BOOTUP) blink.o

# Tools
CC=arm-none-eabi-gcc
LD=arm-none-eabi-gcc

ELF=blink.elf

LDFLAGS+= -T$(LDSCRIPT) -mcpu=cortex-m0 -Wl,--gc-sections
CFLAGS+= -mcpu=cortex-m0 -g
CFLAGS+= -Ilib/ -I.
CFLAGS+= -D$(MCUTYPE)

$(ELF):		$(OBJS)
	$(LD) $(LDFLAGS) -o $@ $(OBJS) $(LDLIBS)

# compile
%.o:	%.c
	$(CC) -c $(CFLAGS) $< -o $@

%.o:	%.s
	$(AS) $< -o $@

clean:
	rm -f $(OBJS) $(OBJS:.o=.d) $(ELF)
