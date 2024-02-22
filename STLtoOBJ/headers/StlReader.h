#pragma once

#include "Triangulation.h" // Include the header file for Triangulation

class StlReader
{
public:
    StlReader();  // Default constructor
    ~StlReader(); // Destructor

    void readFile1(Triangulation &triangulation); // Method to read STL file and populate the triangulation
};
