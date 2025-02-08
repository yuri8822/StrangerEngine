#pragma once

// this is my dedicated File Manager that will handle the Loading of all saved game objects
// and Saving of all loaded game objects, therefore allowing the engine/editor/runtime to make use of them.
// This is likely to be extended to offer more control and features as well, IA.

class FileManager
{
private:
public:
    FileManager();
    void Demo_Load_3D_Models();
    void LoadFile();
    void SaveFile();
};