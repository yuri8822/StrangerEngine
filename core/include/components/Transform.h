#pragma once

#include <iostream>
#include "Component.h"

struct position
{
    double x;
    double y;
    double z;
};

struct rotation
{
};
struct scale
{
};

struct component_Transform : public Component
{
    position position;
    rotation rotation;
    scale scale;

    std::string Identifier() override
    {
        return "Transform Component";
    }
};