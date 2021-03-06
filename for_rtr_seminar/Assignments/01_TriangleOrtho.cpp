#include "gwm.h"

void main (void)
{
    // declarations
    void keyboardFunc(unsigned int);
    void displayFunc(void);
    void reshapeFunc(int, int);

    // code
    gwmKeyboardCallback(keyboardFunc);
    gwmDisplayCallback(displayFunc);
    gwmReshapeCallback(reshapeFunc);

    gwmCreateWindow("OpenGL | FFP | GWM", 100, 100, 800, 600);
    gwmEventLoop();
}

void keyboardFunc(unsigned int key)
{
    // VK_ESCAPE
    if(key == 0x1B)
    {
        gwmExitEventLoop();
    }
}

void reshapeFunc(int width, int height)
{
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();

    glViewport(0, 0, width, height);
    glOrtho(-2, 2, -2, 2, -1, 1);
}

void displayFunc(void)
{
    // code
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
	glBegin(GL_TRIANGLES);

	glColor3f(1.0f, 0.0f, 0.0f);
	glVertex2f(0.0f, 1.0f);
	glColor3f(0.0f, 1.0f, 0.0f);
	glVertex2f(-1.0f, -1.0f);
	glColor3f(0.0f, 0.0f, 1.0f);
	glVertex2f(1.0f, -1.0f);
	
	glEnd();

    gwmSwapBuffers();
}

