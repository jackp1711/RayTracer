#pragma once

#include "vector.h"
#include "colour.h"
#include "ray.h"
#include "hit.h"
#include "object.h"
#include "light.h"


class Scene
{
    public:
    std::vector<Object> object_list;
    std::vector<Light> light_list;
    
    Colour trace(Ray, Hit);

    void add_object_to_list(Object);
    void add_light_to_list(Light);
};

Colour Scene::trace(Ray r, Hit h)
{
    return Colour(0, 0, 0);
}

void Scene::add_object_to_list(Object o)
{
    object_list.push_back(o);
}

void Scene::add_light_to_list(Light l)
{
    light_list.push_back(l);
}