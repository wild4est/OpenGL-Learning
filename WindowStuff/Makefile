CC=gcc
CFLAGS=-c -Wall -Werror
LIBS=-lX11 -lGL -lGLU

SOURCE=WindowStuff.c
OBJECTS=$(SOURCE:%.c=obj/%.o)

all: objdir libdir libwindowstuff

objdir:
ifeq ("$(wildcard obj)","")
	mkdir obj
endif

libdir:
ifeq ("$(wildcard ../lib)","")
	mkdir ../lib
endif


libwindowstuff: $(OBJECTS)
	ar rcs ../lib/libWindowStuff.a $^ 

obj/%.o: %.c
	$(CC) $(CFLAGS) $(LIBS) $^ -o $@

clean:
	rm -rf ../lib/*.a ../lib obj/*.o obj
