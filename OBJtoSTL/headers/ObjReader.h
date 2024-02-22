#pragma once

#include "Triangulation.h" // Include the header file for Triangulation

// Class for reading OBJ files
class ObjReader
{
public:
    // Method to read data from an OBJ file
    void readObj(Triangulation &triangulation);
};
