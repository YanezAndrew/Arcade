#define GL_SILENCE_DEPRECATION
#include <GL/gl.h>
#include <GL/glut.h>
#include <GL/freeglut.h>
#include "npc.h"
#include <vector>

std::vector<std::vector<Npc>> allBullets;
std::vector<Npc> warningStream;

//for testing purposes
int currStream = 1;

void setupNPCS(){
    warningStream= Npc::generate(10, WARNING, RIGHT, TOP, 0, -0.2);
    for(int i = 0; i< 10 ; i++){
        allBullets.push_back(Npc::generate(5, BULLET, RIGHT, TOP - i*0.2, -0.38));
    }
}

void display() {
    glClear(GL_COLOR_BUFFER_BIT);
    // Your OpenGL code here
    for (auto bullet : allBullets[currStream]){
        bullet.draw();
    }
    for(auto warning : warningStream){
        warning.draw();
    }
    glFlush();
}

void update(int value) {
    for(int i = 0; i < allBullets[currStream].size(); i++){
        allBullets[currStream][i].move(-0.06,0);
    }
    glutTimerFunc(33, update, 0);
    glutPostRedisplay();
}

void Initialize(int argc, char** argv) {
    glutInit(&argc, argv);
    glutInitWindowSize(800, 600);
    glutInitWindowPosition(300,150);
    glutCreateWindow("OpenGL Example");
    // glutFullScreen();
}

int main(int argc, char** argv) {
    setupNPCS();
    Initialize(argc, argv);
    glutDisplayFunc(display);
    glutTimerFunc(0, update, 0);
    glutMainLoop();
    return 0;
}