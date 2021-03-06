CC=gcc
CCFLAGS=-c -Wall -Wextra -ansi -g
LDFLAGS=-lm
SOURCES=main.c matrice.c network.c neuron.c list/list.c
OBJECTS=$(SOURCES:.c=.o)
EXECUTABLE=prn

all: $(SOUCES) $(EXECUTABLE)

$(EXECUTABLE): $(OBJECTS)
	$(CC) $(LDFLAGS) $(OBJECTS) -o $@
	    
.c.o:
	$(CC) $(CCFLAGS) $< -o $@

clear:
	rm *.o
	    
clean:
	rm *.o $(EXECUTABLE)
