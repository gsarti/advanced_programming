/**
    Advanced Programming 2018-2019
    Purpose: Implement a matrix transpose operation

    @author Gabriele Sarti
    @version 27/10/18
*/

#include "matrix.hpp"
#include <iostream>

int main()
{
    const int SIZE = 16;

    // Squared matrix
    Matrix<SIZE> mat = Matrix<SIZE>(4, 4);
    std::cout << mat << std::endl;
    std::cout << "Performing transposition..." << std::endl;
    mat.transpose();
    std::cout << mat << std::endl;

    // Rectangular matrix
    Matrix<SIZE> mat2 = Matrix<SIZE>(8, 2);
    std::cout << mat2 << std::endl;
    std::cout << "Performing transposition..." << std::endl;
    mat2.transpose();
    std::cout << mat2 << std::endl; // TODO: Still not working
    return 0;
}