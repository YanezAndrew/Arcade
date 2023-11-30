#include <GL/gl.h>
#include <GL/glut.h>
#include <GL/freeglut.h>
#include <vector>

#ifndef NPC_H
#define NPC_H

enum Type{
    BULLET,
    WARNING,
    OBSTACLE
};

class Npc{
    double x, y;
    Type type;

    public:
        Npc(Type t, double x, double y);

        void draw();
            void drawBullet();
            void drawWarning();
            void drawObstacle();
        void move(double x, double y);
    //static methods
    public:
        static std::vector<Npc> generate(int n, Type t, double x, double y);
};
#endif