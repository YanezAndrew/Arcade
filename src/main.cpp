#define GL_SILENCE_DEPRECATION
#include <GL/gl.h>
#include <GL/glut.h>
#include <GL/freeglut.h>

void display() {
    glClear(GL_COLOR_BUFFER_BIT);
    // Your OpenGL code here
    glBegin(GL_TRIANGLES);
    glVertex2f(-0.5, -0.5);
    glVertex2f(0.5, -0.5);
    glVertex2f(0.0, 0.5);
    glEnd();
    glFlush();
}

void Initialize(int argc, char** argv) {
    glutInit(&argc, argv);
    // glutInitContextVersion(4,3);
    // glutInitContextFlags(GLUT_FORWARD_COMPATIBLE);
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
