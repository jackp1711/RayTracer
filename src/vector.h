#include "math.h"
#pragma once

class Vector{

    float x, y ,z;

    public:

    Vector();

    Vector(float, float, float);

    //method functions
    float getVectorX() {return x;}
    float getVectorY() {return y;}
    float getVectorZ() {return z;}

    void normalize();
    void negate();
    float dot(Vector&);
    void cross(Vector&, Vector&);

};

Vector::Vector(){
    x = 0;
    y = 0;
    z = 0;
}

Vector::Vector(float a, float b, float c){
    x = a;
    y = b;
    z = c;
};

void Vector::normalize(){
    float len = (float)sqrt((double)(x*x + y*y + z*z));
    x = x / len;
    y = y / len;
    z = z / len;
}

float Vector::dot(Vector &other)
{
    return x*other.x + y*other.y + z*other.z;
}

void Vector::negate()
{
    x = -x;
    y = -y;
    z = -z;
}

void Vector::cross(Vector &other, Vector &result)
{
    result.x = y*other.z - z*other.y;
    result.y = z*other.x - x*other.z;
    result.z = x*other.y - y*other.x;
}