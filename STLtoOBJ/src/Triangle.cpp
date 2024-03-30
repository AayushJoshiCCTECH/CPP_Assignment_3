#include "../headers/Triangle.h"

// Default constructor
Triangle::Triangle()
{
}

// Constructor with Point3D objects
Triangle::Triangle(Point3D p1, Point3D p2, Point3D p3)
{
    mPointP1 = p1;
    mPointP2 = p2;
    mPointP3 = p3;
}

// Destructor
Triangle::~Triangle()
{
}

// Getter for PointP1
Point3D Triangle::pointP1()
{
    return mPointP1;
}

// Getter for PointP2
Point3D Triangle::pointP2()
{
    return mPointP2;
}

// Getter for PointP3
Point3D Triangle::pointP3()
{
    return mPointP3;
}

// Setter for PointP1
void Triangle::setPointP1(Point3D p1)
{
    mPointP1 = p1;
}

// Setter for PointP2
void Triangle::setPointP2(Point3D p2)
{
    mPointP2 = p2;
}

// Setter for PointP3
void Triangle::setPointP3(Point3D p3)
{
    mPointP3 = p3;
}

// Getter for vertex index 1
const int Triangle::v1() const
{
    return mV1;
}

// Getter for vertex index 2
const int Triangle::v2() const
{
    return mV2;
}

// Getter for vertex index 3
const int Triangle::v3() const
{
    return mV3;
}

// Constructor with vertex indices
Triangle::Triangle(int v1, int v2, int v3)
{
    mV1 = v1;
    mV2 = v2;
    mV3 = v3;
}
