# Translator
This project aims to make a Translator which can convert 
- .stl to .txt file
- .obj to .txt file
- .stl to .obj file
- .obj to .stl file
## STL File Reader

This set of code is aimed at rendering 3D shapes from STL files. It includes classes for reading STL files, storing 3D triangles, and writing them back to an .txt file and then rendering the 3D object in GNU plot.

## Project Structure

- `Headers`: Contains header files for various classes.
- `Source`: Contains source files for the implementation of classes.
- `Output`: Default output directory for generated STL files.
- `README.md`: This file providing information about the project.

## Classes

### Point3D

Represents a point in 3D space.

### Triangle

Represents a triangle in 3D space, composed of three points (Point3D objects).

### Triangulation

Manages a collection of triangles and ensures unique vertices.

### STLReader

Reads triangles from an STL file and populates a Triangulation object.

### STLWriter

Writes triangles from a Triangulation object to an STL file.

## Usage

1. Place the input STL file in the project directory.
2. Update the `main.cpp` file with the correct input and output file paths.
3. Compile and run the program.

## Example

```cpp
#include <iostream>
#include "Headers/STLReader.h"
#include "Headers/STLWriter.h"
#include "Headers/Triangulation.h"

int main() {
    try {
        std::string inputFilePath = "input.stl";

        // Read triangles from STL file
        Triangulation triangulation;
        STLReader stlReader;
        stlReader.readSTLFromFile(inputFilePath, triangulation);

        // Write triangles to new STL file
        std::string outputFilePath = "output.stl";
        STLWriter stlWriter;
        stlWriter.writeSTLToFile(outputFilePath, triangulation.triangles());

        std::cout << "STL file written successfully!" << std::endl;
    } catch (const std::exception& e) {
        std::cerr << "Error: " << e.what() << std::endl;
    }

    return 0;
}
```
# OBJ File Reader and Writer

This set of code is aimed at reading and writing 3D models stored in OBJ file format. It includes classes for reading OBJ files, storing 3D vertices and faces, and writing them back to an .txt file and then rendering the 3D object in GNU plot.

## Project Structure

- `Headers`: Contains header files for various classes.
- `Source`: Contains source files for the implementation of classes.
- `Output`: Default output directory for generated OBJ files.
- `README.md`: This file providing information about the project.

## Classes

### Point3D

Represents a point in 3D space.

### Triangle

Represents a triangle in 3D space, composed of three points (Point3D objects).

### Triangulation

Manages a collection of triangles and ensures unique vertices.

### OBJReader

Reads vertices and faces from an OBJ file and populates a Model object.

### OBJWriter

Writes vertices and faces from a Model object to an OBJ file.

## Usage

1. Place the input OBJ file in the project directory.
2. Update the `main.cpp` file with the correct input and output file paths.
3. Compile and run the program.

## Example

```cpp
#include <iostream>
#include "./headers/Point3D.h"       // Include the header file for Point3D
#include "./headers/Triangulation.h" // Include the header file for Triangulation
#include "./headers/Triangle.h"      // Include the header file for Triangle
#include "./headers/ObjReader.h"     // Include the header file for ObjReader
#include "./headers/ObjWriter.h"     // Include the header file for ObjWriter

using namespace std;

int main()
{
    ObjReader reader;       // Create an ObjReader object
    Triangulation triangle; // Create a Triangulation object

    reader.readObj(triangle);  // Read the .obj file and populate the triangulation
    ObjWriter writer;          // Create an ObjWriter object
    writer.writeOBJ(triangle); // Write the triangulation to a file in .obj format

    return 1; // Return success
}
```
# OBJ to STL Translator

This set of code is designed to convert 3D models stored in OBJ file format to STL file format. It includes classes for reading OBJ files, converting them to STL format, and writing the converted STL files.

## Project Structure

- `Headers`: Contains header files for various classes.
- `Source`: Contains source files for the implementation of classes.
- `Output`: Default output directory for generated STL files.
- `README.md`: This file providing information about the project.

## Classes

### Point3D

Represents a point in 3D space.

### Triangle

Represents a triangle in 3D space, composed of three vertices.

### Triangulation

Manages a collection of triangles and ensures unique vertices.

### OBJReader

Reads vertices and faces from an OBJ file and converts them to a collection of triangles.

### ObjWriter

Writes triangles to an STL file.

## Usage

1. Place the input OBJ file in the project directory.
2. Update the `ObjReader.cpp` file and `ObjWriter.cpp` with the correct input and output file paths.
3. Compile and run the program.

## Example
### ObjReader
```cpp
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

```
### ObjWriter

```cpp
#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include "../headers/Triangle.h"      // Include the header file for Triangle
#include "../headers/Triangulation.h" // Include the header file for Triangulation
#include "../headers/Point3D.h"       // Include the header file for Point3D
#include "../headers/ObjWriter.h"     // Include the header file for ObjWriter

using namespace std;

// Method to write data from a Triangulation object to an OBJ file
void ObjWriter::writeOBJ(Triangulation &triangulation)
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
```
# STL to OBJ Translator

This set of code converts 3D models stored in STL file format to OBJ file format. It includes classes for reading STL files, converting them to OBJ format, and writing the converted OBJ files.

## Project Structure

- `Headers`: Contains header files for various classes.
- `Source`: Contains source files for the implementation of classes.
- `Output`: Default output directory for generated OBJ files.
- `README.md`: This file providing information about the project.

## Classes

### Point3D

Represents a point in 3D space.

### Triangle

Represents a triangle in 3D space, composed of three vertices.

### Triangulation

Manages a collection of triangles and ensures unique vertices.

### STLReader

Reads triangles from an STL file.

### OBJWriter

Writes triangles to an OBJ file.

## Usage

1. Place the input STL file in the project directory.
2. Update the `STLReader.cpp` file and `STltoOBJ.cpp` with the correct input and output file paths.
3. Compile and run the program.

## Example

### STL Reader
```cpp
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
    std::ifstream readFromFile("cube.stl");

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
```
### STL To OBJ Writer
```cpp
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
```
