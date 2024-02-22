#pragma once

class Point3D
{
public:
    Point3D();                          // Default constructor
    Point3D(float x, float y, float z); // Parameterized constructor
    ~Point3D();                         // Destructor

    float x(); // Getter for x coordinate
    float y(); // Getter for y coordinate
    float z(); // Getter for z coordinate

    void setX(float x); // Setter for x coordinate
    void setY(float y); // Setter for y coordinate
    void setZ(float z); // Setter for z coordinate

    bool operator<(const Point3D &other) const; // Less than operator for comparing points

private:
    float mX; // x coordinate
    float mY; // y coordinate
    float mZ; // z coordinate
};
