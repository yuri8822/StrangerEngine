#pragma once

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

struct component_Transform
{
    position position;
    rotation rotation;
    scale scale;
};