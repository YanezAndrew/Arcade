#include "npc.h"
// #include "util.cpp"
#include <cmath>

Npc::Npc(Type t, double x, double y){
    this->x = x;
    this->y = y;
    this->type = t;
}

void Npc::draw(){
    if(type == BULLET){
        drawBullet();
    }else if(type == WARNING){
        drawWarning();
    }else if(type == OBSTACLE){
        drawObstacle();
    }
}

void Npc::move(double dx, double dy){
    x += dx;
    y += dy;

    if(x < -1){
        x = RIGHT-0.05;
    }
    else if(x > 1){
        x = LEFT;
    }
    if(y < -1){
        y = TOP;
    }
    else if(y > 1){
        y = BOTTOM;
    }
}

void Npc::drawBullet(){
    float height = 0.05;
    float width = height*1.375;
    glColor3f(0,0,0);
    drawRect(x, y, width, height);
    drawRect(x-width/2, y, height * 0.25, height * 0.75);
    drawRect(x-width/2 - (height * 0.25)/4, y, height * 0.25, height * 0.75*0.75);

    height /= 1.4;
    width = height*1.5;
    glColor3f(1,1,0);
    drawRect(x, y, width, height);
    drawRect(x-width/2, y, height * 0.25, height * 0.75);
    drawRect(x-width/2 - (height * 0.25)/4, y, height * 0.25, height * 0.75*0.75);
}

void Npc::drawWarning(){
    float width = 0.075;
    glColor3f(1,0,0);
    drawTriangle(x, y, width, width*1.4);
    glColor3f(0.0f, 0.0f, 0.0f);
    drawTriangle(x, y, width, width*1.4,false);
    width *= 0.75;
    glColor3f(1,1,0);
    drawTriangle(x, y-0.005, width, width*1.4);
    glColor3f(0.0f, 0.0f, 0.0f);
    drawTriangle(x, y-0.005, width, width*1.4,false);

    drawCircle(x, y- width/2, width *0.15);
    drawRect(x, y+width/16, width*0.1, width*0.75);
}

void Npc::drawObstacle(){
}

std::vector<Npc> Npc::generate(int n, Type t, double x, double y, double dx, double dy){
    std::vector<Npc> npcs;
    for(int i = 0; i < n; i++){
        npcs.push_back(Npc(t, x+dx*i, y+dy*i));
    }
    return npcs;
}