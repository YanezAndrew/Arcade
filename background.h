#include "texture.h"
#include <string>


#ifndef BACKGROUND_H
#define BACKGROUND_H


class Background{
    Texture backgroundTexture;
    public:
        Background();
        void loadTexture(const char* filename);
        void draw();
};
#endif