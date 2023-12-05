#ifndef CHARACTER_H
#define CHARACTER_H

#define GL_SILENCE_DEPRECATION
#include <GL/gl.h>
#include <GL/glut.h>
#include <GL/freeglut.h>
#include <png.h>
#include <string>

#include "texture.h"

class Character {
    double xPosition;
    double yPosition;
    bool isMovingUp;
    Texture characterTexture;

    public:
        Character(double initX, double initY);
        double getXPosition();
        double getYPosition();
        void setPosition(double newX, double newY);
        void setMovingUp(bool moveUp);
        void draw();
        void loadTexture(const char* filename);
        void updateMovePosition();
        void moveKey(int key, int x, int y);
        void moveMouse(int button, int state, int x, int y);
};

#endif