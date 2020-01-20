#include "vector.h"
#include "vertex.h"

#pragma once

class Ray{
    Vector direction;
    Vertex position;

    public:

    Ray();

    Ray(Vertex, Vector);

    //methids
    Vertex getRayPosition(){return position;}
    Vector getRayDirection(){return direction;}
};

Ray::Ray(){
    position = Vertex(0,0,0);
    direction = Vector(1,0,0);
}

Ray::Ray(Vertex pos, Vector dir){
    position = pos;
    direction = dir;
}