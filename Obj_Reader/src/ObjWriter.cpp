#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include "../headers/Triangle.h"      // Include the header file for Triangle
#include "../headers/Triangulation.h" // Include the header file for Triangulation
#include "../headers/Point3D.h"       // Include the header file for Point3D
#include "../headers/ObjWriter.h"     // Include the header file for ObjWriter

using namespace std;

void ObjWriter::writeOBJ(Triangulation &triangulation)
{
    std::ofstream outFile("Cube1.txt"); // Open the output file

    if (!outFile.is_open()) // Check if the file is successfully opened
    {
        cout << "Error while opening the file for writing." << endl; // Display error message if file cannot be opened
    }

    vector<Point3D> &points = triangulation.uniquePoints();  // Get the vector of unique points
    vector<Triangle> &triangles = triangulation.triangles(); // Get the vector of triangles

    // Iterate over each triangle
    for (const Triangle &triangle : triangles)
    {
        // Write the coordinates of the vertices of the triangle to the file
        outFile << points[triangle.v1() - 1].x() << " " << points[triangle.v1() - 1].y() << " " << points[triangle.v1() - 1].z() << endl;
        outFile << points[triangle.v2() - 1].x() << " " << points[triangle.v2() - 1].y() << " " << points[triangle.v2() - 1].z() << endl;
        outFile << points[triangle.v3() - 1].x() << " " << points[triangle.v3() - 1].y() << " " << points[triangle.v3() - 1].z() << endl;
    }
    outFile.close(); // Close the file
}
