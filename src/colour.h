#pragma once

class Colour{

    public:

    float r,g,b;


    Colour();

    Colour(float, float, float);
};


Colour::Colour(){
    r = 0;
    g = 0;
    b = 0;
}

Colour::Colour(float pr, float pg, float pb){
    r = pr;
    g = pg;
    b = pb;
}