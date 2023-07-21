COMMON_OBJECTS =
CPU = msp430g2553
CFLAGS = -mmcu=${CPU} -I../h -L/opt/ti/msp430_gcc/include
LDFLAGS		= -L/opt/ti/msp430_gcc/include

CC =msp430-elf-gcc
AS = msp430-elf-as

all: buzzer.elf

buzzer.elf: ${COMMON_OBJECTS} buzzer.o uimain.o lib/libTimer.a
	${CC} ${CFLAGS} -o $@ $^

load: buzzer.elf
	msp430loader.sh $^
clean: $^
	rm -f *.o *.elf

buzzer.c: buzzer.h
uimain.c: buzzer.h
