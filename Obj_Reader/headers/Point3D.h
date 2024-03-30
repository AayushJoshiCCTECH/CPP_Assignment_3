#pragma once

class Point3D
{
public:
    // Default constructor
    Point3D();
    // Parameterized constructor
    Point3D(double x, double y, double z);
    // Destructor
    ~Point3D();

    // Getter for x coordinate
    double x() const;
    // Getter for y coordinate
    double y() const;
    // Getter for z coordinate
    double z() const;

    // Setter for x coordinate
    void setX(double x);
    // Setter for y coordinate
    void setY(double y);
    // Setter for z coordinate
    void setZ(double z);

    // Comparison operator for sorting points
    bool operator<(const Point3D &other) const;

private:
    double mX; // x coordinate
    double mY; // y coordinate
    double mZ; // z coordinate
};
