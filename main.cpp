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
#include "util.h"

Character player1(-0.5,-0.8);
Background background;
Texture endScreen;
std::vector<std::vector<Npc> > allBullets;
std::vector<Npc> warningStream;
double points = 0;
std::vector<bool> active;
bool moving = false;
int difficulty = 0;
bool stop = false;  

//initializes bullets in a [10][5] 2D vector and warnings in a [10] 1D vector
void setupNPCS(){
    warningStream= Npc::generate(10, WARNING, RIGHT, TOP, 0, -0.2);
    for(int i = 0; i< 10 ; i++){
        allBullets.push_back(Npc::generate(5, BULLET, RIGHT-0.05, TOP - i*0.2, -0.38));
        active.push_back(false);
    }
}

void resetGame() {
    allBullets.clear();
    warningStream.clear();
    active.clear();
    points = 0;
    moving = false;
    difficulty = 0;
    stop = false;
    setupNPCS();
}

void activateBullets(){
    for (int i = 0; i<10; i++) {
        if(active.at(i)){
            for (auto& bullet : allBullets.at(i)) {
                bullet.move(-0.06 - difficulty*0.01 ,0);
            }
        }
    }
}

void Initialize(int argc, char** argv) {
    glutInit(&argc, argv);
    glutInitWindowSize(820, 600);
    glutInitWindowPosition(300, 150);
    glutCreateWindow("Justin Joyride");
    glutFullScreen();


    // Replace with the path to your PNG image
    background.loadTexture("images/sky.png");
    player1.loadTexture("images/amongus.png");
    endScreen.loadTexture("images/gameOver.png");
    srand(time(0));
}

void display() {
    // Sets the Color
    glClear(GL_COLOR_BUFFER_BIT);
    background.draw();
    player1.draw();
    
    for (int i = 0; i<10; i++) {
        if(active.at(i)){
            if(moving){
                for (auto bullet : allBullets.at(i)) {
                    bullet.draw();
                }
            }
            warningStream.at(i).draw();
        }
    }
    // Logic For When You Collide With Object
    if (stop) {
        drawEndScreen(endScreen, points, difficulty);
    } else { 
        renderText(points,difficulty, 0, 0.95);
    }

    glFlush();
}

void checkCollide(){
    for (int i = 0; i<10; i++) {
        if(active.at(i) && moving){
            for (auto bullet : allBullets.at(i)) {
                if(player1.checkCollision(bullet.getX(), bullet.getY(), bullet.getWidth(), bullet.getHeight())){
                    stop=true;
                }
            }
        }
    }

}

// Calls our update function every 33 milliseconds to ensure smooth/updated movement
void update (int value) {
    if(!stop){
        points += 0.25;
        //Draws Warning Sign
        if(int(points)%(30-difficulty) == 0){
            active = activateRandom(difficulty);
        }

        //Draws Bullets
        if(int(points)%(30-difficulty) == (10-difficulty)){
            moving = true;
        }
        //Stops Bullets
        if(int(points)%(30-difficulty) == (29-difficulty)){
            moving = false;
        }
        if(std::fmod(points,200) == 199 && difficulty < 5){
            difficulty++;
        }
        activateBullets();
        player1.updateMovePosition(difficulty);
        checkCollide();
    }
    glutTimerFunc(33, update, 0);
    glutPostRedisplay();
}

void specialKeyboard(int key, int x, int y) {
        player1.moveKey(key, x, y);
}

void regularKeyboard(unsigned char key, int x, int y){
    if (key == 'r' || key == 'R') {
        resetGame();
    } 
}

void mouse(int button, int state, int x, int y) {
    player1.moveMouse(button, state, x, y);
}

int main(int argc, char** argv) {
    setupNPCS();
    Initialize(argc, argv);
    glutDisplayFunc(display);
    glutSpecialFunc(specialKeyboard);
    glutKeyboardFunc(regularKeyboard);
    glutMouseFunc(mouse);
    glutTimerFunc(0, update, 0);
    glutMainLoop();
    return 0;
}