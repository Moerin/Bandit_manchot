# Compilateur
CC=gcc -c -g -Wall

# Edition de lien
LD=gcc -o

all: main

main: main.o bandit.o
	$(LD) $@ $^

%.o: %.c %.h
	$(CC) $<

.PHONY: clean

clean:
	rm -rf *.o
