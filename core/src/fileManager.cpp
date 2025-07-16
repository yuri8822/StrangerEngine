#include "core.h"

#include <iostream>
#include <fstream>

// ~~~~~~~~~~~~~~~~~ Utility Functions --- START
std::string split(std::string &input, char delimiter)
{
    size_t pos = input.find(delimiter);
    std::string sub;
    if (pos != std::string::npos) {
        sub = input.substr(0, pos);
        input = input.substr(pos + 1, input.length());
        return sub;
    } else {
        return input;
    }
}
// ~~~~~~~~~~~~~~~~~ Utility Functions --- END

FileManager::FileManager()
{
    // Startup tasks of the File Manager when the Engine starts:
    Demo_Load_3D_Models();

    std::cout << "File Manager Initialized" << std::endl;
}

void FileManager::Demo_Load_3D_Models()
{
    std::cout << "Running Demo_Load_3D_Models()" << std::endl;

    std::ifstream fin;

    std::string line;

    std::string data;

    fin.open("../../assets/m4a1_s.obj");

    component_Mesh *mesh = new component_Mesh();    

    // debug:
    int count = 0;
    int lineLimit = 10;
    // debug;

    while (getline(fin, line)) 
    {
        // debug:
        if (count >= lineLimit)
        {
            break;
        }
        // debug;

        if (line.substr(0, 2) == "v ")
        {
            data = line.substr(3, line.length());

            double x = stod(split(data, ' '));
            double y = stod(split(data, ' '));
            double z = stod(split(data, ' '));
            mesh->vertices.push_back(v(x, y, z));
        }
        else if (line.substr(0, 2) == "vn")
        {
            data = line.substr(3, line.length());

            double x = stod(split(data, ' '));
            double y = stod(split(data, ' '));
            double z = stod(split(data, ' '));
            mesh->normals.push_back(vn(x, y, z));
        }
        else if (line.substr(0, 2) == "vt")
        {
            data = line.substr(3, line.length());

            double x = stod(split(data, ' '));
            double y = stod(split(data, ' '));
            mesh->textures.push_back(vt(x, y));
        }
        else if (line.substr(0, 2) == "f ")
        {

        }

        count++;
    }

    // Close the file
    fin.close();
}

void FileManager::LoadFile()
{

}

// This function will Save the entity instance into a ".strange file" using binary serialization
void FileManager::SaveFile()
{
    
}