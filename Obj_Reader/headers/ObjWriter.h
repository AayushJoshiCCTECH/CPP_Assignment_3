#pragma once
#include <vector>
#include "Triangle.h"      // Include the header file for Triangle
#include "Triangulation.h" // Include the header file for Triangulation

class ObjWriter
{
public:
    // Method to write data from a Triangulation object to an OBJ file
    void writeOBJ(Triangulation &triangulation);
};
