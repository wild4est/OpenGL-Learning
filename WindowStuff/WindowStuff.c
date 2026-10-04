#include "WindowStuff.h"

struct WindowStuff *CreateWindowStuff(const char *name_of_win) {
	struct WindowStuff *window_stuff = malloc(sizeof(struct WindowStuff));
	// Open connection to X server
	window_stuff->dpy = XOpenDisplay(NULL);
	if (window_stuff->dpy == NULL) {
		free(window_stuff);
		return NULL;
	}

	// Root window of the deafault screen
	Window root = DefaultRootWindow(window_stuff->dpy);

	// Attr for XChooseVisual
	GLint att[] = {GLX_RGBA, GLX_DEPTH_SIZE, 24, GLX_DOUBLEBUFFER, None};
	// Get a XVisualInfo for OpenGL
	XVisualInfo *vi = glXChooseVisual(window_stuff->dpy, 0, att);
	if (vi == NULL) {
		free(window_stuff);
		return NULL;
	}

	// Create a colormap of the OpenGL visual
	Colormap cmap =
	    XCreateColormap(window_stuff->dpy, root, vi->visual, AllocNone);

	// Window attribures
	XSetWindowAttributes swa;
	swa.colormap = cmap;
	swa.event_mask = ExposureMask | KeyPressMask;

	// Create window
	window_stuff->win = XCreateWindow(
	    window_stuff->dpy, root, 0, 0, 600, 600, 0, vi->depth, InputOutput,
	    vi->visual, CWColormap | CWEventMask, &swa);

	XMapWindow(window_stuff->dpy, window_stuff->win);
	XStoreName(window_stuff->dpy, window_stuff->win, name_of_win);

	// Create a GLX rendering contex and replace current context with this
	GLXContext glc = glXCreateContext(window_stuff->dpy, vi, NULL, GL_TRUE);
	glXMakeCurrent(window_stuff->dpy, window_stuff->win, glc);

	return window_stuff;
}
