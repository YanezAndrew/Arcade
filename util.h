#include <GL/gl.h>
#include <GL/glut.h>
#include <GL/freeglut.h>
#include <vector>
#include <random>
#include <ctime>

#ifndef UTIL_H
#define UTIL_H

void drawRect(GLfloat x, GLfloat y, GLfloat w, GLfloat h);
void drawTriangle(GLfloat x, GLfloat y, GLfloat w, GLfloat h, bool filled = true);
void renderText(double pts,int dif, double x, double y);
void drawCircle(GLfloat x, GLfloat y, GLfloat r);
std::vector<bool> activateRandom(int difficulty);

#endif