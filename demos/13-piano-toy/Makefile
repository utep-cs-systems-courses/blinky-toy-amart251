all: toy.out

CPU             = msp430g2553
CFLAGS          = -mmcu=${CPU}

# switch the compiler (for the internal make rules)
CC              = msp430-elf-gcc
AS              = msp430-elf-as
AR              = msp430-elf-ar

# Object files for the toy
OBJS            = buttons.o leds.o sound.o stateMachine.o clocksTimer.o sr.o

toy.out: ${OBJS}
	$(CC) $(CFLAGS) -o $@ $^

libTimer.a: clocksTimer.o sr.o
	$(AR) crs $@ $^

install: libTimer.a
	mkdir -p ../h ../lib
	mv $^ ../lib
	cp *.h ../h

clean:
	rm -f toy.out libTimer.a *.o

