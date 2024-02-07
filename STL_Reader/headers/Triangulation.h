#pragma once

#include <vector>
#include <map>
#include "Triangle.h"

using namespace std;

namespace geometry
{
    // Class representing a triangulation
    class Triangulation
    {
    public:
        // Constructors and Destructor
        Triangulation();  // Default constructor
        ~Triangulation();  // Destructor

        // Getter for triangles
        vector<Triangle> &triangles();

        // Getter for unique points
        vector<Point3D> &uniquePoints();

    private:
        // Private data members representing triangles and unique points
        vector<Triangle> mTriangles;
        vector<Point3D> mUniquePoints;
    };
}
