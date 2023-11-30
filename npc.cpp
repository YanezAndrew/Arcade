#include "npc.h"
#include "util.cpp"

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

void Npc::move(double x, double y){
    this->x += x;
    this->y += y;
    //FIXME Delete old object
}

void Npc::drawBullet(){
    float height = 0.05;
    float width = height*1.375;
    drawRect(x, y, width, height);
    drawRect(x-width/2, y, height * 0.25, height * 0.75);
    drawRect(x-width/2 - (height * 0.25)/4, y, height * 0.25, height * 0.75*0.75);
}

void Npc::drawWarning(){
}

void Npc::drawObstacle(){
}

std::vector<Npc> Npc::generate(int n, Type t, double x, double y){
    std::vector<Npc> npcs;
    for(int i = 0; i < n; i++){
        npcs.push_back(Npc(t, 0.0, 0.0));
    }
    return npcs;
}