#pragma once
#include "components/Mesh.h"
#include "components/Transform.h"
// From Scratch

// implement the FATHER "Entity" class from which all game objects will potentially inherit from:
class Entity
{
private:

public:
    // every component needs to be listed here
    component_Transform *component_Transform;
    component_Mesh *component_Mesh;
};

// the ECS itself:
class ECS
{
private:
public:
    ECS();
    ~ECS();
};
