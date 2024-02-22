#include "../headers/Point3D.h" // Include the header file for Point3D

Point3D::Point3D() : mX(0), mY(0), mZ(0) {} // Default constructor initializes coordinates to 0

Point3D::Point3D(double x, double y, double z) : mX(x), mY(y), mZ(z) {} // Parameterized constructor

double Point3D::x() const // Getter for x coordinate
{
    return mX;
}

double Point3D::y() const // Getter for y coordinate
{
    return mY;
}

double Point3D::z() const // Getter for z coordinate
{
    return mZ;
}

void Point3D::setX(double x) // Setter for x coordinate
{
    mX = x;
}

void Point3D::setY(double y) // Setter for y coordinate
{
    mY = y;
}

void Point3D::setZ(double z) // Setter for z coordinate
{
    mZ = z;
}

bool Point3D::operator<(const Point3D &other) const // Less than operator for comparing points
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

Point3D::~Point3D() {} // Destructor
