#include <GL/gl.h>
#include <GL/glut.h>
#include <GL/freeglut.h>
#include <vector>
#include <string>
#include <iostream>
#include <cmath>

#ifndef UTIL_CPP
#define UTIL_CPP
//Draws a rectangle
void drawRect(GLfloat x, GLfloat y, GLfloat w, GLfloat h){
    glBegin(GL_POLYGON);
        glVertex2f(x-w/2, y-h/2);
        glVertex2f(x+w/2, y-h/2);
        glVertex2f(x+w/2, y+h/2);
        glVertex2f(x-w/2, y+h/2);
    glEnd();
}

//Draws a triangle
void drawTriangle(GLfloat x, GLfloat y, GLfloat w, GLfloat h, bool filled=true){
    if(filled){
        glBegin(GL_POLYGON);
    }
    else {
        glBegin(GL_LINE_LOOP);
    }
        glVertex2f(x-w/2, y-h/2);
        glVertex2f(x+w/2, y-h/2);
        glVertex2f(x, y+h/2);
    glEnd();
}

//Draws a circle
void drawCircle(GLfloat x, GLfloat y, GLfloat r){
    glBegin(GL_POLYGON);
        glBegin(GL_POLYGON);
        for(int i=0;i<360;i++){
            glVertex2f(x+r/2*cos(i), y+r/2*sin(i)*16/9);
        }
    glEnd();
}


//Writes text to screen
void renderText(double pts,int dif){
    glColor3f(1,1,1);
    std::string text = "Points: ";
    text += std::to_string(int(pts));
    text += "                      Difficulty: ";
    text += std::to_string(dif);
    glRasterPos2f(0, 0.95);
    for(char c : text){
        glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18, c);
    }
}


//Randomly activates a number of streams based on difficulty
std::vector<bool> activateRandom(int difficulty){
    std::vector<bool> active(10, false);
    // int numActives = 1 + difficulty + std::rand() / ((RAND_MAX + 1u) / (5+difficulty));
    int numActives = difficulty + 2;
    for(int i = 0; i <numActives; i++){
        int index = std::rand() / ((RAND_MAX + 1u) / 10);
        active.at(index) = true;
    }
    return active;
}
#endif
