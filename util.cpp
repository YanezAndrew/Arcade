#include <GL/gl.h>
#include <GL/glut.h>
#include <GL/freeglut.h>
#include <vector>


void drawRect(GLfloat x, GLfloat y, GLfloat w, GLfloat h){
    
    glBegin(GL_POLYGON);
        glVertex2f(x-w/2, y-h/2);
        glVertex2f(x+w/2, y-h/2);
        glVertex2f(x+w/2, y+h/2);
        glVertex2f(x-w/2, y+h/2);
    glEnd();
    
}