//============================================================================
// Name        : qlib.cpp
// Author      : istvan
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include "qmatrix.h"
#include "list.h"
#include <iostream>

//using namespace QLib;
using namespace std;
using namespace Qlib;

int main() {
    QMatrix<float> mat1(3, 3, 1.0);
    QMatrix<float> mat2(10, 10, 2.0);


    Qlib::SL::List<int> list1;

    //QMatrix<float> mat3 = mat1 + mat2;

    float value = 0.0;

    for (unsigned int i=0; i<mat1.GetRows(); i++)
    {
      for (unsigned int j=0; j<mat1.GetCols(); j++)
      {
        mat1.Set(i,j, value++);
      }
    }
    for (unsigned int i=0; i<mat1.GetRows(); i++)
    {
      for (unsigned int j=0; j<mat1.GetCols(); j++)
      {
        cout << mat1(i,j) << ", ";
      }
      std::cout << std::endl;
    }
    std::cout << std::endl;
    QMatrix<float> mat3 = mat1.Transpose();

    for (unsigned int i=0; i<mat1.GetRows(); i++)
    {
      for (unsigned int j=0; j<mat1.GetCols(); j++)
      {
        cout << mat3(i,j) << ", ";
      }
      std::cout << std::endl;
    }

	return 0;
}
