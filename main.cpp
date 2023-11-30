#define GL_SILENCE_DEPRECATION
#include <GL/gl.h>
#include <GL/glut.h>
#include <GL/freeglut.h>
#include "Character.h"

Character player1(-0.5,-0.8);

void Initialize(int argc, char** argv) {
    glutInit(&argc, argv);
    glutInitWindowSize(800, 600);
    glutInitWindowPosition(300,150);
    glutCreateWindow("OpenGL Example");
    glutFullScreen();
}

void display() {
    glClear(GL_COLOR_BUFFER_BIT);
    // Your OpenGL code here
    glColor3f(1.0,0.796,0.647);
    player1.draw();
    glFlush();
}

void update (int value) {
    player1.updateMovePosition();
    glutTimerFunc(33, update, 0);
    glutPostRedisplay();
}

void keyboard(int key, int x, int y) {
    player1.moveKey(key, x, y);
}

void mouse(int button, int state, int x, int y) {
    player1.moveMouse(button, state, x, y);
}

int main(int argc, char** argv) {
    Initialize(argc, argv);
    glutDisplayFunc(display);
    glutSpecialFunc(keyboard);
    glutMouseFunc(mouse);
    glutTimerFunc(0, update, 0);
    glutMainLoop();
    return 0;
}
