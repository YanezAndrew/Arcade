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

const double RIGHT = 0.9;
const double LEFT = -0.9;
const double TOP = 0.9;
const double BOTTOM = -0.9;

class Npc{
    double x, y;
    Type type;
    bool active = false;

    public:
        Npc(Type t, double x, double y);

        void draw();
            void drawBullet();
            void drawWarning();
            void drawObstacle();
        void move(double x, double y);
        void activate();
        void deactivate();
    //static methods
    public:
        static std::vector<Npc> generate(int n, Type t, double x, double y, double dx = 0, double dy = 0);
};
#endif