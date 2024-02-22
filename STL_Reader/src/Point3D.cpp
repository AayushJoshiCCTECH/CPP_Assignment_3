#include "../headers/Point3D.h" // Include the header file for Point3D
using namespace geometry;       // Use the geometry namespace

// Default constructor
Point3D::Point3D() : mX(0), mY(0), mZ(0) {}

// Parameterized constructor
Point3D::Point3D(double x, double y, double z) : mX(x), mY(y), mZ(z) {}

// Destructor
Point3D::~Point3D() {}

// Getter for x coordinate
double Point3D::x() const
{
    return mX;
}

// Getter for y coordinate
double Point3D::y() const
{
    return mY;
}

// Getter for z coordinate
double Point3D::z() const
{
    return mZ;
}

// Setter for x coordinate
void Point3D ::setX(double x)
{
    mX = x;
}

// Setter for y coordinate
void Point3D ::setY(double y)
{
    mY = y;
}

// Setter for z coordinate
void Point3D ::setZ(double z)
{
    mZ = z;
}

// Less-than comparison operator
bool Point3D::operator<(const Point3D &other) const
{
    // Compare x coordinates first, then y coordinates, and finally z coordinates
    if (mX < other.mX)
        return true;
    if (mX > other.mX)
        return false;

    if (mY < other.mY)
        return true;
    if (mY > other.mY)
        return false;

    return mZ < other.mZ;
}
