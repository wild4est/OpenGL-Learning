#pragma once

#include <GL/gl.h>
#include <GL/glu.h>
#include <GL/glx.h>
#include <X11/X.h>
#include <X11/Xlib.h>
#include <malloc.h>

struct WindowStuff {
	Display *dpy;
	Window win;
	XWindowAttributes gwa;
};

struct WindowStuff *CreateWindowStuff(const char *name_of_win);
