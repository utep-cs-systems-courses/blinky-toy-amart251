
# Variables
CC = msp430-gcc
CFLAGS = -mmcu=msp430g2553
SOURCES = main.c buzzer.c
OBJECTS = $(SOURCES:.c=.o)
TARGET = main.out

# Default target
all: $(TARGET)

# Compile source files into object files
%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

# Link object files to produce the executable
$(TARGET): $(OBJECTS)
	$(CC) $(CFLAGS) $(OBJECTS) -o $(TARGET)

# Clean generated files
clean:
	rm -f $(OBJECTS) $(TARGET)

.PHONY: all clean
