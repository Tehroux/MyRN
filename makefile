#!MAKEFILE
CC=gcc
CFLAGS=-c -Wall -Wextra -ansi -g
LDFLAGS=-lm
SOURCES=main.c matrice.c network.c neuron.c list/list.c
OBJECTS=$(SOURCES:.c=.o)
EXE=prn

.PHONY: clean

all: $(SOURCES) $(EXE)

$(EXE): $(OBJECTS)
	@$(CC) -o $@ $^ $(LDFLAGS)
	
%.o: %.c
	@$(CC) -o $@ -c $< $(CFLAGS)
	
clean:
	rm -f $(OBJECTS) $(EXE)
