#pragma once


#include "vertex.h"
#include "vector.h"

class Object;

class Hit {
public:
	bool flag;
	float t;
	Object *what;
	Vertex position;
	Vector normal;
    
};