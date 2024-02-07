#include "../headers/StlToObj.h"
#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include "../headers/Point3D.h"

using namespace std;

// Method to convert STL file to OBJ format
void StlToObj::writer(Triangulation &triangulation)
{
    // Open the output OBJ file for writing
    ofstream outFile("cube.obj");

    // Check if the file is open
    if (!outFile.is_open())
    {
        cout << "Error while opening text file." << endl;
        return;
    }

    // Get the unique points and triangles from the triangulation object
    vector<Point3D> &points = triangulation.uniquePoints();
    vector<Triangle> &triangles = triangulation.triangles();

    // Write the vertices (points) to the OBJ file
    for (size_t i = 0; i < points.size(); i++)
    {
        outFile << "v " << points[i].x() << " " << points[i].y() << " " << points[i].z() << endl;
    }

    // Write the triangles to the OBJ file
    for (const Triangle &triangle : triangles)
    {
        outFile << "f " << triangle.v1() << "/_/_ " << triangle.v2() << "/_/_ " << triangle.v3() << "/_/_ " << endl;
    }

    // Close the output file
    outFile.close();
}
