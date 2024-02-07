#include "../headers/Triangle.h" // Include the header file for Triangle

// Default constructor
Triangle::Triangle() : mV1(), mV2(), mV3() {}

// Parameterized constructor
Triangle::Triangle(int v1, int v2, int v3)
{
    mV1 = v1;
    mV2 = v2;
    mV3 = v3;
}

// Destructor
Triangle::~Triangle() {}

// Getter for vertex 1
const int Triangle::v1() const
{
    return mV1;
}

// Getter for vertex 2
const int Triangle::v2() const
{
    return mV2;
}

// Getter for vertex 3
const int Triangle::v3() const
{
    return mV3;
}

// Setter for vertex 1
void Triangle::setV1(const int v1)
{
    mV1 = v1;
}

// Setter for vertex 2
void Triangle::setV2(const int v2)
{
    mV2 = v2;
}

// Setter for vertex 3
void Triangle::setV3(const int v3)
{
    mV3 = v3;
}
