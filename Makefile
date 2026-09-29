CC = gcc
CFLAGS = -Wall -Wextra -std=c11
PREFIX = $(HOME)/conway-install
BINDIR = $(PREFIX)/bin

conway: main.o conway.o
	$(CC) $(CFLAGS) -o conway main.o conway.o

main.o: main.c conway.h
	$(CC) $(CFLAGS) -c main.c

conway.o: conway.c conway.h
	$(CC) $(CFLAGS) -c conway.c

clean:
	rm -f conway main.o conway.o

install: conway
	mkdir -p $(BINDIR)
	cp conway $(BINDIR)/conway

.PHONY: clean install
