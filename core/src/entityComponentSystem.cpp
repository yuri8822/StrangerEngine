#include "core.h"

Entity::Entity()
{
}

Component *Entity::getComponent(std::string component)
{
    if (component == "Mesh")
    {
        return component_Mesh;
    }
    else if (component == "Transform")
    {
        return component_Transform;
    }
    
    return nullptr;
}

Entity::~Entity()
{
}

ECS::ECS()
{
}

ECS::~ECS()
{
}