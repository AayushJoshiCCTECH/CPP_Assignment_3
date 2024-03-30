#pragma once
#include <vector>
#include "Triangle.h" // Include the header file for Triangle

using namespace std;

class Triangulation
{
public:
    // Default constructor
    Triangulation();
    // Destructor
    ~Triangulation();

    // Getter for triangles
    vector<Triangle> &triangles();
    // Getter for unique points
    vector<Point3D> &uniquePoints();

private:
    vector<Triangle> mTriangles;   // Vector to store triangles
    vector<Point3D> mUniquePoints; // Vector to store unique points
};
