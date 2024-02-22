#pragma once

#include <vector>          // Include the header file for vector
#include "Triangle.h"      // Include the header file for Triangle
#include "Triangulation.h" // Include the header file for Triangulation

// Class for writing OBJ files
class StlWriter
{
public:
    // Method to write data from a Triangulation object to an OBJ file
    void writeOBJ(Triangulation &triangulation);
};
