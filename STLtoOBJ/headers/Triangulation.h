#pragma once

#include "Triangle.h" // Include the header file for Triangle
#include <vector>
using namespace std;

class Triangulation
{
public:
    Triangulation();  // Default constructor
    ~Triangulation(); // Destructor

    vector<Triangle> &triangles();   // Getter for triangles
    vector<Point3D> &uniquePoints(); // Getter for unique points

private:
    vector<Triangle> mTriangles;   // Vector to store triangles
    vector<Point3D> mUniquePoints; // Vector to store unique points
};
