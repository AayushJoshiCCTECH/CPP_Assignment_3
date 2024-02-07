#include <iostream>
#include <set>
#include "./headers/STLReader.h"     
#include "./headers/STLWriter.h"     
#include "./headers/Triangle.h"      
#include "./headers/Triangulation.h" 

using namespace geometry; 

typedef vector<Triangle> Triangles; // Define an alias for vector of Triangle objects

int main()
{
    try
    {
        // Specify the path to the input STL file
        std::string inputFilePath = "D:\\Aayush_Joshi\\C++\\Assignment 3\\3D Shapes Rendering\\cube.stl";

        // Create an instance of STLReader
        STLReader stlReader;
        // Create a Triangulation object
        Triangulation triangulation;

        // Read the contents of the STL file and populate the triangulation object
        stlReader.readSTL(triangulation);

        // Output the number of unique points in the triangulation
        cout << triangulation.uniquePoints().size();

        // Specify the path to the output file
        std::string outputFilePath = "D:\\Aayush_Joshi\\C++\\Assignment 3\\3D Shapes Rendering\\Cube1.txt";

        // Create an instance of STLWriter
        STLWriter stlWriter;
        // Write the triangulation object to an STL file
        stlWriter.writeSTLToFile(triangulation);

        // Output a success message
        std::cout << "STL file written successfully!" << std::endl;
    }
    catch (const std::exception &e)
    {
        // Output an error message if an exception occurs
        std::cerr << "Error: " << e.what() << std::endl;
    }

    return 0;
}
