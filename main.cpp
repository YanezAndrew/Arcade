#define GL_SILENCE_DEPRECATION
#include <GL/gl.h>
#include <GL/glut.h>
#include <GL/freeglut.h>
#include "npc.h"
#include <vector>
#include "Character.h"

Character player1(-0.5,-0.8);
std::vector<std::vector<Npc>> allBullets;
std::vector<Npc> warningStream;

//for testing purposes
int currStream = 1;

//initializes bullets in a [10][5] 2D vector and warnings in a [10] 1D vector
void setupNPCS(){
    warningStream= Npc::generate(10, WARNING, RIGHT, TOP, 0, -0.2);
    for(int i = 0; i< 10 ; i++){
        allBullets.push_back(Npc::generate(5, BULLET, RIGHT, TOP - i*0.2, -0.38));
    }
}

void activateBullets(int stream){
    for(int i = 0; i < allBullets[stream].size(); i++){
        Npc* bullet = &allBullets[stream][i];
        bullet->activate();
        bullet->move(-0.06,0);
        
    }
}

void Initialize(int argc, char** argv) {
    glutInit(&argc, argv);
    glutInitWindowSize(800, 600);
    glutInitWindowPosition(300,150);
    glutCreateWindow("OpenGL Example");
    glutFullScreen();
}

void display() {
    glClear(GL_COLOR_BUFFER_BIT);
    glColor3f(1.0,0.796,0.647);
    player1.draw();
  // Your OpenGL code here
    for(auto bulletStream: allBullets){
        for (auto bullet: bulletStream){
            bullet.draw();
        }
    }
    for(auto warning : warningStream){
        warning.activate();
        warning.draw();
    }
    glFlush();
}

// Calls our update function every 33 milliseconds to ensure smooth/updated movement
void update (int value) {
    activateBullets(currStream);
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
    setupNPCS();
    Initialize(argc, argv);
    glutDisplayFunc(display);
    glutSpecialFunc(keyboard);
    glutMouseFunc(mouse);
    glutTimerFunc(0, update, 0);
    glutMainLoop();
    return 0;
}