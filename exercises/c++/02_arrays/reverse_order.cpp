/**
    Advanced Programming 2018-2019
    Purpose: Creates an array from stdin and print in reverse order.

    @author Gabriele Sarti
    @version 11/10/18
*/

#include<iostream>
#include"reverse_order.hpp"


template <typename T>
T* init_array(int size)
{
    T * array{new T[size]};
    for(int i{0}; i < size; ++i)
    {
        std::cout << "Please enter the element number " << i + 1 << " of the array:" << std::endl;
        std::cin >> array[i]; 
    }

    return array;
}

template <typename T>
void print_array_reverse(T* array, int size)
{
    for(int i{size - 1}; i >= 0; --i)
    {
        std::cout << "array[" << i << "] = " << array[i] << std::endl;
    }
    delete[] array;
}

int main()
{
  int size;
  std::cout << "Please insert the size of the array:" << std::endl;
  std::cin >> size;
  int * int_array = init_array<int>(size);
  print_array_reverse(int_array, size);
  double * double_array = init_array<double>(size);
  print_array_reverse(double_array, size);
  return 0;
}