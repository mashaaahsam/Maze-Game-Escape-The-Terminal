.SILENT:

CC = gcc
CFLAGS = -Wall -std=c11 -g 

outName = game
SRC = $(wildcard *.c)
OBJ = $(SRC:.c=.o)
HDR = $(wildcard *.h)

# Key Commands
all: clean compile run

compile: $(OBJ)
	$(CC) $(CFLAGS) $^ -o $(outName) -lncurses

%.o: %.c %.h
	$(CC) $(CFLAGS) -c $< -o $@

run: $(outName)
	./$(outName)

# Clean-Up Crew
.Phony: clean

clean:
	rm -f $(outName) *.o

