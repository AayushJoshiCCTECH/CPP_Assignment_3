#pragma once

// Class representing a point in 3D space
class Point3D
{
public:
    
    Point3D(); // Default constructor
    Point3D(double x, double y, double z); // Parameterized constructor

    // Destructor
    ~Point3D();

    // Getters for x, y, and z coordinates
    double x() const;
    double y() const;
    double z() const;

    // Setters for x, y, and z coordinates
    void setX(double x);
    void setY(double y);
    void setZ(double z);

    // Comparison operator for sorting points
    bool operator<(const Point3D &other) const;

private:
    // Private data members representing x, y, and z coordinates
    double mX;
    double mY;
    double mZ;
};
