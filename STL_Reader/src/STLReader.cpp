#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <map>
#include <unordered_map>
#include <algorithm>
#include "../headers/STLReader.h" // Include the header file for STLReader

using namespace std;
using namespace geometry;

// Method to read an STL file and populate a Triangulation object
void STLReader::readSTL(Triangulation &triangulation)
{
    // Open the input file
    std::ifstream inputFile("Cube10.stl");

    // Map to store mapped coordinates
    map<Point3D, int> nMapedCoordinates;
    // Vector to store points
    vector<Point3D> points;

    // Read the file line by line
    std::string line;
    while (std::getline(inputFile, line))
    {
        // Check if the line contains "vertex"
        if (line.find("vertex") != std::string::npos)
        {
            // Extract coordinates from the line
            double x, y, z;
            istringstream iss(line);
            string keyword;
            iss >> keyword >> x >> y >> z;
            // Create a Point3D object
            Point3D p1(x, y, z);

            // Check if the point already exists in the map
            auto iterator = nMapedCoordinates.find(p1);
            if (iterator == nMapedCoordinates.end())
            {
                // If not found, add it to the map and uniquePoints vector
                nMapedCoordinates.insert(pair<Point3D, int>(p1, triangulation.uniquePoints().size()));
                triangulation.uniquePoints().push_back(p1);
            }

            // Get the index of the point
            int index1 = nMapedCoordinates[p1];
            int index2 = nMapedCoordinates[p1];
            int index3 = nMapedCoordinates[p1];

            // Add a triangle to the triangles vector
            triangulation.triangles().push_back(Triangle(index1, index2, index3));
        }
    }
    // Close the input file
    inputFile.close();
}
