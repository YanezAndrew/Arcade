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
#include <iostream>

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
    // glutFullScreen();


    // Replace with the path to your PNG image
    background.loadTexture("images/background.png");
    player1.loadTexture("images/amongus.png");


}

void display() {
    // Sets the Color
    glColor4f(1.0, 1.0, 1.0, 1.0);
    glClear(GL_COLOR_BUFFER_BIT);

    background.draw();
    renderPoints(points);

    player1.draw();
    
    for (auto bulletStream : allBullets) {
        for (auto bullet : bulletStream) {
            // This Here Temporarily Before we have start screen
            if (points >= 10) {
                double bulletWidth = bullet.getWidth();  // Adjust the bullet size accordingly
                double bulletHeight = bullet.getHeight(); // Adjust the bullet size accordingly

                // Check for collision with the player
                if (player1.checkCollision(bullet.getX(), bullet.getY(), bulletWidth, bulletHeight)) {
                    // Collision detected, take appropriate actions (e.g., stop the game or reduce player's health)
                    // For now, let's stop the game by printing a message and exiting
                    std::cout << "Game Over! You collided with a bullet." << std::endl;
                    exit(0);
                }
            }
            






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