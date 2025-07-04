#include "core.h"
#include <iostream>
#include <fstream>

using namespace std;

// ~~~~~~~~~~~~~~~~~ Utility Functions --- START
string split(string &input, char delimiter)
{
    size_t pos = input.find(delimiter);
    string sub;
    if (pos != string::npos) {
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

    cout << "File Manager Initialized" << endl;
}

void FileManager::Demo_Load_3D_Models()
{
    cout << "Running Demo_Load_3D_Models()" << endl;

    ifstream fin;

    string line;

    string data;

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

void FileManager::SaveFile()
{
    
}