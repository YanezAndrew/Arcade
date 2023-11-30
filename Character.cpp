#include "Character.h"
#define GL_SILENCE_DEPRECATION
#include <GL/gl.h>
#include <GL/glut.h>
#include <GL/freeglut.h>

Character::Character(double initX, double initY) {
    xPosition = initX;
    yPosition = initY;
    isMoving = false;
}

double Character::getXPosition() {
    return xPosition;
}

double Character::getYPosition() {
    return yPosition;
}

void Character::setPosition(double newX, double newY) {
    xPosition = newX;
    yPosition = newY;
}

void Character::setMoving(bool move) {
    isMoving = move;
}

void Character::draw() {
    glBegin(GL_QUADS);
    glVertex2f(xPosition - 0.1, yPosition - 0.1);
    glVertex2f(xPosition + 0.1, yPosition - 0.1);
    glVertex2f(xPosition + 0.1, yPosition + 0.1);
    glVertex2f(xPosition - 0.1, yPosition + 0.1);
    glEnd();
}

void Character::updateMovePosition() {
    if (isMoving && yPosition < 0.8f) {
        yPosition += 0.025f;
    }

    else if (!isMoving && yPosition > -0.8f) {
        yPosition -= 0.025f;
    }
}

void Character::moveKey(int key, int x, int y) {
    
    switch (key) {
        case GLUT_KEY_UP:
            setMoving(true);
            break;
        case GLUT_KEY_DOWN:
            setMoving(false);
            break;
    }

    glutPostRedisplay();
}

void Character::moveMouse(int button, int state, int x, int y) {
    if (button == GLUT_LEFT_BUTTON) {
        if (state == GLUT_DOWN) {
            setMoving(true);
        }

        else if (state == GLUT_UP) {
            setMoving(false);
        }
    }
}

