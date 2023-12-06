#include "Character.h"
#include "util.h"
#include <iostream>

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
void Character::loadTexture(const char* filename) {
    characterTexture.loadTexture(filename);
}


void Character::draw() {
    glEnable(GL_TEXTURE_2D);
    glBindTexture(GL_TEXTURE_2D, characterTexture.getID());
    glEnable(GL_BLEND);
    glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
    
    glBegin(GL_QUADS);
    glColor4f(1.0, 1.0, 1.0, 1.0);
    glTexCoord2f(0.0f, 1.0f);
    glVertex2f(xPosition - 0.1, yPosition - 0.1);
    glTexCoord2f(1.0f, 1.0f);
    glVertex2f(xPosition + 0.1, yPosition - 0.1);
    glTexCoord2f(1.0f, 0.0f);
    glVertex2f(xPosition + 0.1, yPosition + 0.1);
    glTexCoord2f(0.0f, 0.0f);
    glVertex2f(xPosition - 0.1, yPosition + 0.1);
    glEnd();
    glDisable(GL_BLEND);
    glDisable(GL_TEXTURE_2D);

    // drawRect(xPosition, yPosition, 0.2, 0.2);
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


bool Character::checkCollision(double objectX, double objectY, double objectWidth, double objectHeight) {
    // Check if the character collides with the object
    if (xPosition - 0.1 < objectX + objectWidth &&
        xPosition + 0.1 > objectX &&
        yPosition - 0.1 < objectY + objectHeight &&
        yPosition + 0.1 > objectY) {
        // Collision detected
        // std::cout << "true" << std::endl;
        return true;
    }

    // No collision
    return false;
}