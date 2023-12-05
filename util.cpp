#include <GL/gl.h>
#include <GL/glut.h>
#include <GL/freeglut.h>
#include <vector>
#include <string>
#include <iostream>

#ifndef UTIL_CPP
#define UTIL_CPP
void drawRect(GLfloat x, GLfloat y, GLfloat w, GLfloat h){
    glBegin(GL_POLYGON);
        glVertex2f(x-w/2, y-h/2);
        glVertex2f(x+w/2, y-h/2);
        glVertex2f(x+w/2, y+h/2);
        glVertex2f(x-w/2, y+h/2);
    glEnd();
}

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

void renderPoints(double pts){
    glColor3f(1,1,1);
    std::string points = "Points: ";
    points += std::to_string(int(pts));
    glRasterPos2f(0, 0.95);
    for(char c : points){
        glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18, c);
    }
}
#endif
