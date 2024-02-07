#pragma once
#include "Triangulation.h" // Include the header file for Triangulation

class ObjReader
{
public:
    // Method to read data from an OBJ file and populate a Triangulation object
    void readObj(Triangulation &triangulation);
};
