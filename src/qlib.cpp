//============================================================================
// Name        : qlib.cpp
// Author      : istvan
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include "qmatrix.h"
#include <iostream>

//using namespace QLib;
using namespace std;

int main() {
    QMatrix<float> mat1(10, 10, 1.0);
    QMatrix<float> mat2(10, 10, 2.0);

    QMatrix<float> mat3 = mat1 + mat2;

    for (int i=0; i<mat3.GetRows(); i++)
    {
      for (int j=0; j<mat3.GetCols(); j++)
      {
        std::cout << mat3(i,j) << ", ";
      }
      std::cout << std::endl;
    }

	return 0;
}
