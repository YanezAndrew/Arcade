#include "texture.h"


Texture::Texture() {
    
}
Texture::Texture(const char* filename) {
    this->filename = filename;
    loadTexture(filename);
}

GLuint Texture::getID() {
    return textureID;
}
void Texture::loadTexture(const char* filename) {
    // Loads png file to a GLuint texture that can be used as a sprite
    this->filename = filename;
    png_image image;
    memset(&image, 0, sizeof(image));
    image.version = PNG_IMAGE_VERSION;

    if (png_image_begin_read_from_file(&image, filename) == 0) {
        printf("Error loading PNG image: %s\n", image.message);
        return;
    }

    image.format = PNG_FORMAT_RGBA;

    png_bytep buffer;
    buffer = (png_bytep)malloc(PNG_IMAGE_SIZE(image));

    if (png_image_finish_read(&image, NULL, buffer, 0, NULL) == 0) {
        printf("Error finishing PNG image read: %s\n", image.message);
        free(buffer);
        return;
    }

    glGenTextures(1, &textureID);
    glBindTexture(GL_TEXTURE_2D, textureID);
    glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, image.width, image.height, 0, GL_RGBA,
                 GL_UNSIGNED_BYTE, buffer);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);

    free(buffer);
}

