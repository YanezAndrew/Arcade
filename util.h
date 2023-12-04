#include <GL/gl.h>
#include <GL/glut.h>
#include <GL/freeglut.h>

#ifndef UTIL_H
#define UTIL_H

void drawRect(GLfloat x, GLfloat y, GLfloat w, GLfloat h);
void drawTriangle(GLfloat x, GLfloat y, GLfloat w, GLfloat h, bool filled = true);
void renderPoints(double pts);

#endif