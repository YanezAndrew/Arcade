#include <GL/gl.h>
#include <GL/glut.h>
#include <GL/freeglut.h>
#include <vector>

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
#endif
