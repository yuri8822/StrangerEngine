#pragma once

#include "components/Mesh.h"
#include "components/Transform.h"

// the FATHER "Entity" class from which all game objects will potentially inherit from:
class Entity
{
private:
    // every component needs to be listed here
    Component *component_Transform;
    Component *component_Mesh;

public:
    Entity();
    Component *getComponent(std::string);
    ~Entity();
};

// the ECS itself:
// I need to decide whether i want to store the entities linearly or in a tree
class ECS
{
private:
public:
    ECS();
    ~ECS();
};
