#include <GL/gl.h>
#include <GL/glu.h>
#include <GL/glx.h>
#include <X11/X.h>
#include <X11/Xlib.h>
#include <malloc.h>

#include "../WindowStuff/WindowStuff.h"

void DrawStuff(float angle) {
	glClearColor(0.7, 1.0, 0.7, 1.0);
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	glPushMatrix();
	glRotatef(angle, 0.0, 0.0, 1.0);
	glBegin(GL_TRIANGLES);

	glColor3f(1.0, 0.0, 0.0);
	glVertex2f(0, 1);
	glColor3f(0.0, 1.0, 0.0);
	glVertex2f(0.9, -0.5);
	glColor3f(0.0, 0.0, 1.0);
	glVertex2f(-0.9, -0.5);

	glEnd();
	glPopMatrix();
}

int main() {
	struct WindowStuff* ws = CreateWindowStuff("Task1");

	float angle = 0.0;
	glEnable(GL_DEPTH_TEST);
	while (1) {
		// Block until it gets a event
		// XNextEvent(dpy, &xev);

		// If content of window should be updated
		// ( for example window has resized )
		// if (xev.type == Expose) {
		XGetWindowAttributes(ws->dpy, ws->win, &ws->gwa);
		glViewport(0, 0, ws->gwa.width, ws->gwa.height);
		DrawStuff(angle);
		glXSwapBuffers(ws->dpy, ws->win);
		angle += 1;
		if (angle >= 360) {
			angle = 0;
		}
	}

	return 0;
}
