#include "ray.h"
#include "hit.h"
#include "colour.h"
// #include "material.h"

class Object {
public:

	Object *next;
	Colour *material;

	Object()
	{
		next = (Object *)0;
	}
	
	Colour intersection(Ray, Hit);
};