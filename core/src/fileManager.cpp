#include "core.h"

#include <iostream>
#include <fstream>

// ~~~~~~~~~~~~~~~~~ Utility Functions --- START
std::string split(std::string &input, char delimiter)
{
    size_t pos = input.find(delimiter);
    std::string sub;
    if (pos != std::string::npos)
    {
        sub = input.substr(0, pos);
        input = input.substr(pos + 1, input.length());
        return sub;
    }
    else
    {
        return input;
    }
}
// ~~~~~~~~~~~~~~~~~ Utility Functions --- END

FileManager::FileManager()
{
    logger.log("--(File Manager) Initializing:");
    
    // Startup tasks of the File Manager when the Engine starts:
    Demo_Load_3D_Models();

    logger.log("--(File Manager) Initialized");
}

void FileManager::Demo_Load_3D_Models()
{
    logger.log("Running Demo_Load_3D_Models()");

    std::string OBJ_File = "m4a1_s.obj";
    std::string OBJ_Directory = "../../assets/";

    std::ifstream fin;

    std::string line;

    std::string data;

    fin.open(OBJ_File + OBJ_Directory);

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

    logger.log("Successfully Loaded file: " + OBJ_File);
}

void FileManager::LoadFile()
{
}

// This function will Save the entity instance into a ".strange file" using binary serialization
void FileManager::SaveFile()
{
}