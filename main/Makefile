# Define variables
CC = gcc
CFLAGS = -Wall -g
LDFLAGS =
LIBS =

# Define the executable name and source files
TARGET = sillymud
SOURCES = comm.c act.comm.c act.info.c act.move.c act.obj1.c \
	act.obj2.c act.off.c act.other.c act.social.c act.wizard.c handler.c \
	db.c interpreter.c utility.c spec_assign.c shop.c limits.c mobact.c \
	fight.c modify.c weather.c spells1.c spells2.c spell_parser.c \
	reception.c constants.c spec_procs.c signals.c board.c magic.c \
	magic2.c skills.c Opinion.c Trap.c magicutils.c multiclass.c hash.c \
	Sound.c Heap.c spec_procs2.c magic3.c security.c spec_procs3.c \
    create.c parser.c intrinsics.c main.c

OBJECTS = $(SOURCES:.c=.o)

# Default target: builds the executable
all: $(TARGET)

# Rule to link the executable
$(TARGET): $(OBJECTS)
	$(CC) $(LDFLAGS) $(OBJECTS) -o $(TARGET) $(LIBS)

# Rule to compile C source files into object files
%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

# Clean target: removes generated files
clean:
	rm -f $(TARGET) $(OBJECTS)
