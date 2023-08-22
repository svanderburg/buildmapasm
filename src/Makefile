CC = gcc -ansi -Wall -pedantic
CFLAGS := $(shell pkg-config --cflags libxml-2.0)
LIBS := $(shell pkg-config --libs libxml-2.0)
PREFIX = /usr/local
BINDIR = $(PREFIX)/bin

# Enable this line to build on big endian systems
#CFLAGS += -DBUILD_BIG_ENDIAN

.c.o:
	$(CC) $(CFLAGS) -c $< -o $@

buildmapasm: io.o sector.o wall.o sprite.o map.o main.o
	$(CC) $(CFLAGS) $(LIBS) -o $@ $^

install: buildmapasm
	mkdir -p $(BINDIR)
	cp $^ $(BINDIR)

clean:
	rm -f *.o
	rm -f buildmapasm
