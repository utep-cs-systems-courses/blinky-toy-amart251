# makfile configuration

COMMON_OBJECTS  = buzzer.o led.o p2_interrupt_handler.o switches.o wdInterruptHandler.o p2_interrupt_handler.o stateMachines.o
CPU             = msp430g2553
CFLAGS          = -mmcu=${CPU} -I../h
LDFLAGS		= -L/opt/ti/msp430_gcc/include
FNCALLS		= buzzer.h led.h stateMachines.h switches.h tune.h 

#switch the compiler (for the internal make rules)
CC              = msp430-elf-gcc
AS              = msp430-elf-as

all: toy.elf 

#additional rules for files

toy.elf: ${COMMON_OBJECTS} main.o ../lib/libTimer.a
	${CC} ${CFLAGS} ${LDFLAGS} -o $@ $^

load: toy.elf
	msp430loader.sh toy.elf

# started getting annoying to rm so added ~ and #
clean:
	rm -f *.o *.elf *~ *#

main.o: buzzer.h led.h stateMachines.h switches.h


led.o: led.c led.h

buzzer.o: buzzer.h

switches.o: led.h switches.h

dim_sequence.o: led.h state_machines.h

wdInterruptHandler.o: stateMachines.h buzzer.h led.h switches.h

stateMachines.o: led.h stateMachines.h buzzer.h notes.h switches.h

p2_interrupt_handler.o: switches.h
