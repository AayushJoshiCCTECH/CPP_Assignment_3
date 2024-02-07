#include "..\headers\Triangulation.h" // Include the header file for Triangulation
#include <map>
#include <vector>
#include <iostream>

Triangulation::Triangulation() {} // Default constructor

Triangulation::~Triangulation() {} // Destructor

vector<Triangle> &Triangulation::triangles() // Getter for triangles
{
    return mTriangles;
}

vector<Point3D> &Triangulation::uniquePoints() // Getter for unique points
{
    return mUniquePoints;
}
