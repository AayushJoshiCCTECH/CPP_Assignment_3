#include "..\headers\Triangulation.h" // Include the header file for Triangulation
#include <map>
#include <vector>
#include <iostream>

using namespace geometry; // Using the geometry namespace

// Default constructor
Triangulation::Triangulation()
{
}

// Destructor
Triangulation::~Triangulation()
{
}

// Getter for triangles
vector<Triangle> &Triangulation::triangles()
{
    return mTriangles; // Return a reference to the triangles vector
}

// Getter for unique points
vector<Point3D> &Triangulation::uniquePoints()
{
    return mUniquePoints; // Return a reference to the uniquePoints vector
}
