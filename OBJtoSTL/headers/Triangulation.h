#pragma once

#include <vector> // Include the header file for vector
#include "Triangle.h" // Include the header file for Triangle

using namespace std;

// Class representing a triangulation
class Triangulation
{
public:
    // Constructors and Destructor
    Triangulation(); // Default constructor
    ~Triangulation(); // Destructor

    // Getter for triangles
    vector<Triangle> &triangles();

    // Getter for unique points
    vector<Point3D> &uniquePoints();

private:
    // Private data members representing triangles and unique points
    vector<Triangle> mTriangles;
    vector<Point3D> mUniquePoints;
};
