#include <GL/gl.h>
#include <GL/glut.h>
#include <GL/freeglut.h>
#include <vector>
#include <string>
#include <iostream>
#include <cmath>    
#include "texture.h"
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
void renderText(double pts,int dif, double x, double y){
    glColor3f(1,1,1);
    std::string text = "Points: ";
    text += std::to_string(int(pts));
    text += "                      Difficulty: ";
    text += std::to_string(dif);
    // 0 0.95
    glRasterPos2f(x, y);
    for(char c : text){
        glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18, c);
    }
}

void renderLine(const std::string& displayText, double x, double y) {
    glColor3f(1, 1, 1);
    
    // Set the position for rendering the text
    glRasterPos2f(x, y);

    // Render each character in the input string
    for (char c : displayText) {
        glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18, c);
    }
}

void drawEndScreen(Texture texture, double score, double difficulty) {
    glEnable(GL_TEXTURE_2D);
    glBindTexture(GL_TEXTURE_2D, texture.getID());
    glEnable(GL_BLEND);
    glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);

    glBegin(GL_QUADS);
    glColor4f(1.0, 1.0, 1.0, 1.0);
    glTexCoord2f(0.0f, 1.0f);
    glVertex2f(-0.5, -0.5);  // Bottom-left corner
    glTexCoord2f(1.0f, 1.0f);
    glVertex2f(0.5, -0.5);   // Bottom-right corner
    glTexCoord2f(1.0f, 0.0f);
    glVertex2f(0.5, 0.5);    // Top-right corner
    glTexCoord2f(0.0f, 0.0f);
    glVertex2f(-0.5, 0.5);   // Top-left corner
    glEnd();

    glDisable(GL_BLEND);
    glDisable(GL_TEXTURE_2D);
    // Draw a smaller black rectangle below the game over screen
    glColor3f(0.0, 0.0, 0.0);  // Set color to black

    glBegin(GL_QUADS);
    glVertex2f(-0.5, -0.5);  // Bottom-left corner
    glVertex2f(0.5, -0.5);   // Bottom-right corner
    glVertex2f(0.5, -0.2);   // Top-right corner
    glVertex2f(-0.5, -0.2);  // Top-left corner
    glEnd();
    // Render the score and text inside the black rectangle
    renderText(score, difficulty, -0.4, -0.3); 
    renderLine("Click R to Restart", 0.1, -0.3);
    renderLine("Click Q to Exit", 0.1, -0.35);
}

void printStart() {
    glColor3f(1, 1, 1);
    drawRect(0, 0, 1, 1);
    glColor3f(0, 0, 0);
    drawRect(0, 0, 0.9, 0.9);
    renderLine("Click Enter to Start", -0.1, 0.0);
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
