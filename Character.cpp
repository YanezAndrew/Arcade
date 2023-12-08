#include "Character.h"
#include "util.h"

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

void Character::updateMovePosition(int scalar) {

    // Checks and ensures that our player doesn't go out of bounds
    if (isMovingUp) {
        yPosition += 0.025 + 0.005 * (1+scalar);
        if(yPosition >1){
            yPosition = -1;
        }
    }
    else if (!isMovingUp) {
        yPosition -= 0.025 + 0.005 * (1+scalar);
        if(yPosition < -1){
            yPosition = 1;
        }
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


bool Character::checkCollision(double npcX, double npcY, double npcWidth, double npcHeight) {
    // Check if the character collides with the npc
    if(abs(npcY - yPosition) < (npcHeight) && abs(npcX - xPosition) < (npcWidth)){
        return true;
    }
    // No collision
    return false;
}