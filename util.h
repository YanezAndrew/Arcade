#include <GL/gl.h>
#include <GL/glut.h>
#include <GL/freeglut.h>
#include <vector>
#include <random>
#include <ctime>
#include "texture.h"
#ifndef UTIL_H
#define UTIL_H

void drawRect(GLfloat x, GLfloat y, GLfloat w, GLfloat h);
void drawTriangle(GLfloat x, GLfloat y, GLfloat w, GLfloat h, bool filled = true);
void renderText(double pts,int dif, double x, double y);
void renderLine(const std::string& displayText, double x, double y);
void drawCircle(GLfloat x, GLfloat y, GLfloat r);
void drawEndScreen(Texture texture, double score, double difficulty);
void printStart();

std::vector<bool> activateRandom(int difficulty);

#endif