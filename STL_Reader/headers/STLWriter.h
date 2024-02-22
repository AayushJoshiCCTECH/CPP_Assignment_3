// STLWriter.h
#pragma once

#include <string>
#include <vector>
#include "Triangle.h"
#include "Triangulation.h"
#include <map>

namespace geometry
{
    // Class for writing STL files
    class STLWriter
    {
    public:
        // Method to write a Triangulation object to an STL file
        void writeSTLToFile(Triangulation &triangulationObj);
    };
}
