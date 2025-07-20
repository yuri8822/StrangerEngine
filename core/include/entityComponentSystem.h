#pragma once

#include "components/Mesh.h"
#include "components/Transform.h"

#include <vector>

class FileManager;

// the FATHER "Entity" class from which all game objects will potentially inherit from:
class Entity
{
private:
    std::string _id;
    // every component needs to be listed here (will be assigned memory in the addComponent function if user needs it)
    Component *Transform;
    Component *Mesh;

public:
    Entity();
    Entity(bool *, int);
    Component *getComponent(int);
    void addComponent(int);
    void removeComponent(int);
    ~Entity();
};

// the ECS itself:
// I need to decide whether i want to store the entities linearly or in a tree
class ECS
{
private:
    FileManager *fileManager;
    std::vector<Entity> ObjectList; // linearly for now

public:
    ECS();
    ECS(FileManager *);
    int CreateEntity(); // As the Engine develops, i intend to add parameters to customize the intial state of the intended Entity/GameObject so the user can skip adding/removing components each time
    int DestroyEntity();
    ~ECS();
};
