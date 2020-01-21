#include "vector.h"
#include "vertex.h"

class Camera{

    public:


    Vector direction;
    Vertex position;

    Vector camera_right;
    Vector camera_down;


    Camera();

    Camera(Vertex, Vector, Vector, Vector);
};


Camera::Camera(){
    position = Vertex(0, 0, 0);
    direction = Vector(0, 0, 1);
}

Camera::Camera(Vertex pos, Vector dir, Vector right, Vector down){
    position = pos;
    direction = dir;

    camera_right = right;
    camera_down = down;
}