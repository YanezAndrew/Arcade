#include "background.h"

Background::Background() {
}
void Background::loadTexture(const char* filename) {
    backgroundTexture.loadTexture(filename);
}   

void Background::draw() {
    // Draw the background
    glEnable(GL_TEXTURE_2D);
    glBindTexture(GL_TEXTURE_2D, backgroundTexture.getID());


    
    glBegin(GL_QUADS);
    glColor4f(1.0, 1.0, 1.0, 1.0);

    glTexCoord2f(0.0f, 1.0f); // Bottom-left
    glVertex2f(-1.0, -1.0);
    glTexCoord2f(1.0f, 1.0f); // Bottom-right
    glVertex2f(1.0, -1.0);
    glTexCoord2f(1.0f, 0.0f); // Top-right
    glVertex2f(1.0, 1.0);
    glTexCoord2f(0.0f, 0.0f); // Top-left
    glVertex2f(-1.0, 1.0);
    glEnd();
    glDisable(GL_TEXTURE_2D);

}