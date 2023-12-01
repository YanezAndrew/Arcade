#include "Character.h"

Character::Character(double initX, double initY) {
    xPosition = initX;
    yPosition = initY;
    isMovingUp = false;
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

void Character::setMovingUp(bool moveUp) {
    isMovingUp = moveUp;
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

    // Checks and ensures that our player doesn't go out of bounds
    if (isMovingUp && yPosition < 0.8f) {
        yPosition += 0.025f;
    }

    else if (!isMovingUp && yPosition > -0.8f) {
        yPosition -= 0.025f;
    }
}

void Character::moveKey(int key, int x, int y) {
    
    // Checks to see which key is clicked to set movingUp state
    switch (key) {
        case GLUT_KEY_UP:
            setMovingUp(true);
            break;
        case GLUT_KEY_DOWN:
            setMovingUp(false);
            break;
    }

    glutPostRedisplay();
}

void Character::moveMouse(int button, int state, int x, int y) {

    // Checks to ensure that mouse is clicked to set movingUp state to true
    if (button == GLUT_LEFT_BUTTON) {
        if (state == GLUT_DOWN) {
            setMovingUp(true);
        }

        else if (state == GLUT_UP) {
            setMovingUp(false);
        }
    }
}

