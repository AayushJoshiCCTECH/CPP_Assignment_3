#pragma once

#include <map>
#include <string>
#include <vector>
#include "Triangulation.h"

namespace geometry
{
    // Class for reading STL files
    class STLReader
    {
    public:
        // Method to read an STL file and populate a Triangulation object
        void readSTL(Triangulation &triangulation);
    };

}
