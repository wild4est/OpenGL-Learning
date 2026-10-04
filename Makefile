CC=gcc
CFLAGS=-c -Wall -Werror

window_stuff:
	cd WindowStuff && $(MAKE)

window_stuff_clean:
	cd WindowStuff && $(MAKE) clean

task1: window_stuff
	cd 1.opening_window && $(MAKE)

task1_clean: window_stuff_clean
	cd 1.opening_window && $(MAKE) clean
