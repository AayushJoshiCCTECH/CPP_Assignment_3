#include "../headers/Point3D.h"

Point3D::Point3D() : mX(0.0), mY(0.0), mZ(0.0) {} // Default constructor

Point3D::Point3D(float x, float y, float z) : mX(x), mY(y), mZ(z) {} // Constructor with parameters

Point3D::~Point3D() {} // Destructor

float Point3D::x() { return mX; } // Getter for x coordinate

float Point3D::y() { return mY; } // Getter for y coordinate

float Point3D::z() { return mZ; } // Getter for z coordinate

void Point3D::setX(float x) { mX = x; } // Setter for x coordinate

void Point3D::setY(float y) { mY = y; } // Setter for y coordinate

void Point3D::setZ(float z) { mZ = z; } // Setter for z coordinate

bool Point3D::operator<(const Point3D &other) const // Overloaded less than operator
{
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
