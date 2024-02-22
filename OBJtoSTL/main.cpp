#include <iostream>
#include "./headers/Point3D.h"       // Include the header file for Point3D
#include "./headers/Triangulation.h" // Include the header file for Triangulation
#include "./headers/Triangle.h"      // Include the header file for Triangle
#include "./headers/ObjReader.h"     // Include the header file for ObjReader
#include "./headers/ObjWriter.h"     // Include the header file for ObjWriter

using namespace std;

int main()
{
    // Create an ObjReader object
    ObjReader reader;
    // Create a Triangulation object
    Triangulation tri;

    // Read data from an OBJ file and populate the Triangulation object
    reader.readObj(tri);

    // Create an ObjWriter object
    ObjWriter writer;
    // Write triangulation data to another file using the ObjWriter object
    writer.writeOBJ(tri);

    // Return 0 to indicate successful execution
    return 0;
}
