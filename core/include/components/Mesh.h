#include <vector>

struct v
{
    float x;
    float y;
    float z;
};
struct vt
{
    float x;
    float y;
};
struct vn
{
    float x;
    float y;
    float z;
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