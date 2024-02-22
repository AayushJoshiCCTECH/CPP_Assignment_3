#include <fstream>
#include <iostream>
#include <cmath>
#include "headers/StlReader.h"
#include "headers/STLtoOBj.h"

using namespace std;

int main()
{
  StlReader st;
  Triangulation triangualtion;
  st.readFile1(triangualtion);

  StlToObj obj;
  obj.writer(triangualtion);
  return 0;
}
