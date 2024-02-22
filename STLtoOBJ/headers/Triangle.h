#pragma once

#include "Point3D.h" // Include the header file for Point3D

class Triangle
{
public:
    Triangle();                                   // Default constructor
    Triangle(Point3D p1, Point3D p2, Point3D p3); // Constructor with Point3D objects
    Triangle(int v1, int v2, int v3);             // Constructor with vertex indices
    ~Triangle();                                  // Destructor

    Point3D pointP1(); // Getter for Point P1
    Point3D pointP2(); // Getter for Point P2
    Point3D pointP3(); // Getter for Point P3

    void setPointP1(Point3D p1); // Setter for Point P1
    void setPointP2(Point3D p2); // Setter for Point P2
    void setPointP3(Point3D p3); // Setter for Point P3

    const int v1() const; // Getter for vertex index 1
    const int v2() const; // Getter for vertex index 2
    const int v3() const; // Getter for vertex index 3

private:
    int mV1;          // Vertex index 1
    int mV2;          // Vertex index 2
    int mV3;          // Vertex index 3
    Point3D mPointP1; // Point P1
    Point3D mPointP2; // Point P2
    Point3D mPointP3; // Point P3
};
