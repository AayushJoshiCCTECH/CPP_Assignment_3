#include "../headers/Triangle.h" // Include the header file for Triangle

Triangle::Triangle() : mV1(), mV2(), mV3() {} // Default constructor initializes vertices to 0

Triangle::Triangle(int v1, int v2, int v3) // Parameterized constructor
{
    mV1 = v1;
    mV2 = v2;
    mV3 = v3;
}

const int Triangle::v1() const // Getter for vertex 1
{
    return mV1;
}

const int Triangle::v2() const // Getter for vertex 2
{
    return mV2;
}

const int Triangle::v3() const // Getter for vertex 3
{
    return mV3;
}

void Triangle::setV1(const int v1) // Setter for vertex 1
{
    mV1 = v1;
}

void Triangle::setV2(const int v2) // Setter for vertex 2
{
    mV2 = v2;
}

void Triangle::setV3(const int v3) // Setter for vertex 3
{
    mV3 = v3;
}
