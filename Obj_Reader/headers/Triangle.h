#pragma once
#include "Point3D.h" // Include the header file for Point3D

class Triangle
{
public:
    // Default constructor
    Triangle();
    // Parameterized constructor
    Triangle(int v1, int v2, int v3);

    // Getter for vertex 1
    const int v1() const;
    // Getter for vertex 2
    const int v2() const;
    // Getter for vertex 3
    const int v3() const;

    // Setter for vertex 1
    void setV1(const int v1);
    // Setter for vertex 2
    void setV2(const int v2);
    // Setter for vertex 3
    void setV3(const int v3);

private:
    int mV1; // Vertex 1
    int mV2; // Vertex 2
    int mV3; // Vertex 3
};
