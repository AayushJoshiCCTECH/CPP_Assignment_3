#include "..\headers\Triangulation.h" // Include the header file for Triangulation

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
    return mTriangles;
}

// Getter for unique points
vector<Point3D> &Triangulation::uniquePoints()
{
    return mUniquePoints;
}
