#include <cmath>
#include <vector>
#include <fstream>
#include <sstream>
#include <iostream>
#include <map>
#include "../headers/Point3D.h"
#include "../headers/StlReader.h"
#include "../headers/Triangle.h"
#include "../headers/Triangulation.h"

using namespace std;

// Default constructor for StlReader class
StlReader::StlReader() {}

// Destructor for StlReader class
StlReader::~StlReader() {}

// Method to read STL file and populate a Triangulation object
void StlReader::readFile1(Triangulation &triangulation)
{
    // Open the STL file for reading
    std::ifstream readFromFile("Sphere3.stl");

    // Initialize vectors and maps to store vertex and triangle data
    vector<Triangle> vertexData;
    vector<Point3D> different;
    map<Point3D, int> mp;
    string line;
    vector<Triangle> tri;

    // Check if the file is open
    if (readFromFile.is_open())
    {
        int count = 1;
        int v1;
        int v2;
        int v3;

        // Read each line from the file
        while (getline(readFromFile, line))
        {
            // Check if the line contains vertex information
            if (line.find("vertex") != std::string::npos)
            {
                istringstream iss(line);
                string keyword;
                double x, y, z;

                // Parse the line to extract vertex coordinates
                iss >> keyword >> x >> y >> z;

                // Create a Point3D object for the vertex
                Point3D point(x, y, z);

                // Check if the vertex is already in the map
                auto it = mp.find(point);

                // If the vertex is not in the map, add it to the vector and map
                if (it == mp.end())
                {
                    different.push_back(point);
                    mp[point] = different.size();
                }

                // Assign vertex indices based on the map
                if (count == 1)
                {
                    v1 = mp[point];
                    count++;
                }
                else if (count == 2)
                {
                    v2 = mp[point];
                    count++;
                }
                else if (count == 3)
                {
                    v3 = mp[point];
                    count++;
                }

                // If all vertices of a triangle are read, create a Triangle object and add it to the vector
                if (count == 4)
                {
                    Triangle T(v1, v2, v3);
                    tri.push_back(T);
                    count = 1;
                }
            }
        }

        // Assign the triangles and unique points to the input Triangulation object
        triangulation.triangles() = tri;
        triangulation.uniquePoints() = different;

        // Close the file
        readFromFile.close();
    }
    else
    {
        // Print an error message if the file cannot be opened
        std::cerr << "Error opening file!" << std::endl;
    }
}
