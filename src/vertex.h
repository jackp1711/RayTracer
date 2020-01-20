#pragma once

class Vertex{
    float x, y, z, w;


    public:
        Vertex();

        Vertex(float, float, float);

    //methods
    
};

Vertex::Vertex(){
    x = 0;
    y = 0;
    z = 0;
}

Vertex::Vertex(float a, float b, float c){
    x = a;
    y = b;
    z = c;

    w = 1;
};