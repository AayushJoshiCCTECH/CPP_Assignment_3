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

// Method to read data from an OBJ file and populate a Triangulation object
void ObjReader::readObj(Triangulation &triangulation)
{
    vector<Point3D> points;     // Vector to store points
    vector<Triangle> triangles; // Vector to store triangles

    ifstream inputfile("Cube.obj"); // Open the input file
    string line;

    // Read the file line by line
    while (getline(inputfile, line))
    {
        // Check if the line contains vertex data
        if (line.find("v") != string::npos)
        {
            double x, y, z;
            istringstream singleline(line);
            string keyword;
            singleline >> keyword >> x >> y >> z;

            if (keyword == "v")
            {
                // Create a Point3D object and add it to the points vector
                Point3D P1(x, y, z);
                points.push_back(P1);
            }
        }

        // Check if the line contains face data

        if (line.find("f") != string::npos)
        {
            string x, y, z;
            istringstream singleLine(line);
            string keyword;
            singleLine >> keyword >> x >> y >> z;

            if (keyword == "f")
            {

                int v1, v2, v3;
                v1 = x[0];
                v1 -= 48;
                v2 = y[0];
                v2 -= 48;
                v3 = z[0];
                v3 -= 48;

                Triangle T(v1, v2, v3);
                triangles.push_back(T);
            }
        }
    }

    triangulation.triangles() = triangles;
    triangulation.uniquePoints() = points;

    inputfile.close();
}