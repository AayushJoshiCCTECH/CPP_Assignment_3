#include <iostream>
#include <fstream>
#include <sstream>
#include <unordered_map>
#include <map>
#include <algorithm>
#include "../headers/ObjReader.h"     // Include the header file for ObjReader
#include "../headers/Triangulation.h" // Include the header file for Triangulation
#include "../headers/Triangle.h"      // Include the header file for Triangle

using namespace std;

void ObjReader::readObj(Triangulation &triangulation)
{
    vector<Point3D> points;     // Vector to store points
    vector<Triangle> triangles; // Vector to store triangles

    ifstream inputfile("Cube.obj"); // Open the OBJ file
    string line;

    while (getline(inputfile, line)) // Read each line of the file
    {
        if (line.find("v") != string::npos) // Check if the line contains vertex information
        {
            double x, y, z;
            istringstream iss(line);
            string keyword;
            iss >> keyword >> x >> y >> z;

            if (keyword == "v")
            {
                // Create a Point3D object and add it to the points vector
                Point3D P1(x, y, z);
                points.push_back(P1);
            }
        }

        if (line.find("f") != string::npos) // Check if the line contains face information
        {
            string x, y, z;
            istringstream iss(line);
            string keyword;
            iss >> keyword >> x >> y >> z;

            if (keyword == "f")
            {
                int v1, v2, v3;  // Initialize variables to store vertex indices
                v1 = x[0] - '0'; // Convert char to int
                v2 = y[0] - '0';
                v3 = z[0] - '0';

                // Create a Triangle object and add it to the triangles vector
                Triangle T(v1, v2, v3);
                triangles.push_back(T);
            }
        }
    }

    // Assign the triangles and points vectors to the triangulation object
    triangulation.triangles() = triangles;
    triangulation.uniquePoints() = points;

    inputfile.close(); // Close the file
}
