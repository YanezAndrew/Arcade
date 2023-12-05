#define GL_SILENCE_DEPRECATION


#ifndef TEXTURE_H
#define TEXTURE_H
#include <GL/gl.h>
#include <GL/glut.h>
#include <GL/freeglut.h>
#include <png.h>
#include <string>
#include <cstring>

class Texture {
    const char* filename;
    GLuint textureID;
    public:
        Texture();
        Texture(const char* filename);
        void loadTexture(const char* filename);
        GLuint getID();
        // void updateFilename(const char* newFileName);




};
#endif