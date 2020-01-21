#include "vector.h"
#include "vertex.h"
#include "colour.h"

#pragma once

class Light{

    public:

    Vertex position;
    Vector direction;
    Colour colour;


    Light();

    Light(Vertex, Vector, Colour); 
};

Light::Light()
{
    position = Vertex(0, 0, 0);
    direction = Vector(0, 0, 1);

    colour = Colour(1, 1, 1);
}

Light::Light(Vertex pos, Vector dir, Colour col)
{
    position = pos;
    direction = dir;

    colour = col;
}