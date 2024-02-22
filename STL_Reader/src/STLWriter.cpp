#include <fstream>
#include <stdexcept>
#include <iostream>
#include <map>
#include <vector>
// Include necessary header files
#include "../headers/STLWriter.h"
#include "../headers/Triangulation.h"

// Using standard namespaces
using namespace std;
using namespace geometry;

// Method to write a Triangulation object to an STL file
void STLWriter::writeSTLToFile(Triangulation &triangulationObj)
{
    // Open the output file for writing
    std::ofstream outFile("Cube1.txt");

    // Check if the file is opened successfully
    if (!outFile.is_open())
    {
        cout << "Error while opening the file for writing." << endl;
        // Throw an exception if file opening fails
        throw std::runtime_error("Failed to open file for writing.");
    }

    // Get references to the unique points and triangles from the Triangulation object
    vector<Point3D> &points = triangulationObj.uniquePoints();
    vector<Triangle> &triangles = triangulationObj.triangles();

    // Iterate over each triangle
    for (const Triangle &triangle : triangles)
    {
        // Write the coordinates of each vertex of the triangle to the output file
        outFile << points[triangle.v1()].x() << " " << points[triangle.v1()].y() << " " << points[triangle.v1()].z() << endl;
    }

    // Close the output file
    outFile.close();
}
