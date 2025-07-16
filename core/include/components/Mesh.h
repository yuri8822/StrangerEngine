#pragma once

#include <vector>
#include <iostream>
#include "Component.h"

struct v
{
    double x;
    double y;
    double z;

    v(double x, double y, double z)
    {
        this->x = x;
        this->y = y;
        this->z = z;
    }
    void debug()
    {
        std::cout << x << ", " << y << ", " << z << std::endl;
    }
};
struct vt
{
    double x;
    double y;

    vt(double x, double y)
    {
        this->x = x;
        this->y = y;
    }
    void debug()
    {
        std::cout << x << ", " << y << std::endl;
    }
};
struct vn
{
    double x;
    double y;
    double z;

    vn(double x, double y, double z)
    {
        this->x = x;
        this->y = y;
        this->z = z;
    }
    void debug()
    {
        std::cout << x << ", " << y << ", " << z << std::endl;
    }
};
struct f
{
};

struct component_Mesh : public Component
{
    std::vector<v> vertices;
    std::vector<vt> textures;
    std::vector<vn> normals;
    std::vector<f> faces;

    std::string Identifier() override
    {
        return "Mesh Component";
    }
};