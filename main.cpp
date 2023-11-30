#define GL_SILENCE_DEPRECATION
#include <GL/gl.h>
#include <GL/glut.h>
#include <GL/freeglut.h>
#include "npc.h"
#include <vector>

std::vector<Npc> bulletStream;

void display() {
    glClear(GL_COLOR_BUFFER_BIT);
    // Your OpenGL code here
    bulletStream = Npc::generate(5, BULLET, 0.0, 0.0);
    for(int i = 0; i < bulletStream.size(); i++){
        glColor3f(1.0, 1.0, 1.0);
        bulletStream[i].draw();
        glColor3f(1.0, 1.0, 0.0);
        bulletStream[i].move(0.15*i,0);
        bulletStream[i].draw();
    }
    glFlush();
}

void Initialize(int argc, char** argv) {
    glutInit(&argc, argv);
    glutInitWindowSize(800, 600);
    glutInitWindowPosition(300,150);
    glutCreateWindow("OpenGL Example");
    // glutFullScreen();
}

int main(int argc, char** argv) {
    Initialize(argc, argv);
    glutDisplayFunc(display);
    glutMainLoop();
    return 0;
}
