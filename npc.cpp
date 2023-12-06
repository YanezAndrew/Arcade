#include "npc.h"
// #include "util.cpp"
#include <cmath>

Npc::Npc(Type t, double x, double y){
    this->x = x;
    this->y = y;
    this->type = t;
}

double Npc::getX() {
    return this->x;
}

double Npc::getY() {
    return this->y;
}

float Npc::getWidth() {
    return this->width;
}

float Npc::getHeight() {
    return this->height;
}


void Npc::draw(){
    if(!active){
        return;
    }

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
        x = RIGHT;
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
    glColor3f(1,1,0);
    float height = 0.05;
    float width = height*1.375;
    drawRect(x, y, width, height);
    drawRect(x-width/2, y, height * 0.25, height * 0.75);
    drawRect(x-width/2 - (height * 0.25)/4, y, height * 0.25, height * 0.75*0.75);
}

void Npc::drawWarning(){
    glColor3f(1,0.5,0);
    float width = 0.075;
    drawTriangle(x, y, width, width*1.4);
    glColor3f(1,0,0);
    drawTriangle(x, y, width, width*1.4,false);
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

void Npc::activate(){
    active = true;
}

void Npc::deactivate(){
    active = false;
}