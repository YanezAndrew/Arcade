#define GL_SILENCE_DEPRECATION
#include <GL/gl.h>
#include <GL/glut.h>
#include <GL/freeglut.h>
#include <SOIL.h>

void display() {
    glClear(GL_COLOR_BUFFER_BIT);
    // Your OpenGL code here
    glFlush();
}

void Initialize(int argc, char** argv) {
    glutInit(&argc, argv);
    glutInitWindowSize(800, 600);
    glutInitWindowPosition(300,150);
    glutCreateWindow("OpenGL Example");
}

int main(int argc, char** argv) {
    Initialize(argc, argv);
    glutDisplayFunc(display);
    glutMainLoop();
    return 0;
}
