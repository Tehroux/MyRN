CC=gcc
CCFLAGS=-c -Wall -Wextra -ansi -g
LDFLAGS=-lm
SOURCES=list_template.c
OBJECTS=$(SOURCES:.c=.o)
EXECUTABLE=list_template

all: $(SOUCES) $(EXECUTABLE)

$(EXECUTABLE): $(OBJECTS)
	  $(CC) $(LDFLAGS) $(OBJECTS) -o $@
	    
.c.o:
	  $(CC) $(CCFLAGS) $< -o $@

clear:
	  rm *.o
	    
clean:
	rm *.o $(EXECUTABLE)
