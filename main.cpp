#define GL_SILENCE_DEPRECATION
#include <GL/gl.h>
#include <GL/glut.h>
#include <GL/freeglut.h>
#include "npc.h"
#include <vector>
#include "Character.h"
#include "background.h"
#include <png.h>  // Include libpng header
#include <string>

Character player1(-0.5,-0.8);
Background background;
std::vector<std::vector<Npc> > allBullets;
std::vector<Npc> warningStream;
double points = 0;

//for testing purposes
int currStream = 9;

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
    glutInitWindowPosition(300, 150);
    glutCreateWindow("OpenGL Example");
    glutFullScreen();

    //FIXME uncomment at end, just for testing
    // glEnable(GL_TEXTURE_2D);
    // // Replace with the path to your PNG image
    // background.loadTexture("images/blue.png");
    // player1.loadTexture("images/green.png");


}

void display() {
    // Sets the Color
    glClear(GL_COLOR_BUFFER_BIT);
    renderPoints(points);
    // background.draw(); //FIXME uncomment at end, just for testing
    player1.draw();
    
    for (auto bulletStream : allBullets) {
        for (auto bullet : bulletStream) {
            bullet.draw();
        }
    }
    for (auto warning : warningStream) {
        warning.activate();
        warning.draw();
    }
    
    glFlush();
}

// Calls our update function every 33 milliseconds to ensure smooth/updated movement
void update (int value) {
    points +=0.25;
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