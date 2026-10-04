CC=gcc
CFLAGS=-Wall -Werror
LIBS=-lX11 -lGL -lGLU

all:
	$(CC) $(CFLAGS) main.c -o main  -L../lib -lWindowStuff $(LIBS)

clean:
	rm -rf main
