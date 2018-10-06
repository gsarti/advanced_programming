/**
    Advanced Programming 2018-2019
    Purpose: Providing two reusable functions to read specific input types.

    @author Gabriele Sarti
    @version 6/10/18
*/

#include <iostream>
#include "getters.hpp"


int get_int()
{
    int value;
    while(!(std::cin >> value))
    {
        std::cin.clear();
        std::cin.ignore();
    }
    return value;    
}

double get_double()
{
    double value;
    while(!(std::cin >> value))
    {
        std::cin.clear();
        std::cin.ignore();
    }    
    return value;    
}