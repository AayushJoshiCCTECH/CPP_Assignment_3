#include "..\headers\Triangulation.h"
#include <map>
#include <vector>
#include <iostream>

using namespace std;
// Default constructor
Triangulation::Triangulation()
{
}

// Destructor
Triangulation::~Triangulation()
{
}

// Getter for triangles vector
vector<Triangle> &Triangulation::triangles()
{
    return mTriangles;
}

// Getter for uniquePoints vector
vector<Point3D> &Triangulation::uniquePoints()
{
    return mUniquePoints;
}
