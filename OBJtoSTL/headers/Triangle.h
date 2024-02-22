#pragma once

#include "Point3D.h" // Include the header file for Point3D

// Class representing a triangle
class Triangle
{
public:
   
    Triangle();                       // Default constructor
    Triangle(int v1, int v2, int v3); // Parameterized constructor

    // Getters for vertices
    const int v1() const;
    const int v2() const;
    const int v3() const;

    // Setters for vertices
    void setV1(const int v1);
    void setV2(const int v2);
    void setV3(const int v3);

private:
    // Private data members representing vertices
    int mV1;
    int mV2;
    int mV3;
};
