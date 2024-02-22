#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include "../headers/Triangle.h"      // Include the header file for Triangle
#include "../headers/Triangulation.h" // Include the header file for Triangulation
#include "../headers/Point3D.h"       // Include the header file for Point3D
#include "../headers/StlWriter.h"     // Include the header file for ObjWriter

using namespace std;

// Method to write data from a Triangulation object to an OBJ file
void StlWriter::writeOBJ(Triangulation &triangulation)
{
    // Open the output file
    std::ofstream outFile("Cube1.stl");

    // Check if the file is successfully opened
    if (!outFile.is_open())
    {
        // Print an error message if the file opening fails
        cout << "Error while opening the file for writing." << endl;
    }

    // Get references to points and triangles from the triangulation object
    vector<Point3D> &points = triangulation.uniquePoints();
    vector<Triangle> &triangles = triangulation.triangles();

    // Write the header for the STL file
    outFile << "solid exported " << endl;

    // Iterate over each triangle and write its vertices to the file
    for (const Triangle &triangle : triangles)
    {
        // Write facet information
        outFile << "    "
                << "facet normal 0 0 0" << endl;
        outFile << "      "
                << "outer loop" << endl;

        // Write vertices of the triangle
        outFile << "         "
                << "vertex " << points[triangle.v1() - 1].x() << " " << points[triangle.v1() - 1].y() << " " << points[triangle.v1() - 1].z() << endl;
        outFile << "         "
                << "vertex " << points[triangle.v2() - 1].x() << " " << points[triangle.v2() - 1].y() << " " << points[triangle.v2() - 1].z() << endl;
        outFile << "         "
                << "vertex " << points[triangle.v3() - 1].x() << " " << points[triangle.v3() - 1].y() << " " << points[triangle.v3() - 1].z() << endl;

        // Write endloop and endfacet
        outFile << "      "
                << "endloop" << endl;
        outFile << "     "
                << "endfacet" << endl;
    }

    // Write end of file
    outFile << "End " << endl;

    // Close the output file
    outFile.close();
}
