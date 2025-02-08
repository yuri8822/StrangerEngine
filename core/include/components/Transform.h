#pragma once

struct position
{
    float x;
    float y;
    float z;
};

struct rotation
{
};
struct scale
{
};

struct component_Transform
{
    position position;
    rotation rotation;
    scale scale;
};