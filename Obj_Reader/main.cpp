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
