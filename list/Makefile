CC=gcc
CCFLAGS=-c -Wall -Wextra -ansi -g
LDFLAGS=-lm
SOURCES=main.c list.c
OBJECTS=$(SOURCES:.c=.o)
EXECUTABLE=list

all: $(SOUCES) $(EXECUTABLE)

$(EXECUTABLE): $(OBJECTS)
	  $(CC) $(LDFLAGS) $(OBJECTS) -o $@
	    
.c.o:
	  $(CC) $(CCFLAGS) $< -o $@

clear:
	  rm *.o
	    
clean:
	rm *.o $(EXECUTABLE)
