#pragma once

#include <vector>
#include <iostream>

struct v
{
    float x;
    float y;
    float z;

    v(float x, float y, float z)
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
    float x;
    float y;

    vt(float x, float y)
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
    float x;
    float y;
    float z;

    vn(float x, float y, float z)
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

struct component_Mesh
{
    std::vector<v> vertices;
    std::vector<vt> textures;
    std::vector<vn> normals;
    std::vector<f> faces;
};