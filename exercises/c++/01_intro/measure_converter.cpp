/**
    Advanced Programming 2018-2019
    Purpose: Allows conversion between inches and meters and vice versa.

    @author Gabriele Sarti
    @version 6/10/18
*/

#include <iostream>
#include <sstream>
#include "getters.hpp"


/**
    Converts a meters value in inches and vice versa.

    @param value the value to be converted.
    @param unit_measure the unit measure of the value.
    @return a string containing the result of the conversion.
*/
std::string convert_m_inch(double value, std::string unit_measure)
{
    std::ostringstream result;

    if (unit_measure == "m") 
    {
        result << value * 39.3701 << " inch" << std::endl;
    }
    else if (unit_measure == "inch")
    {
        result << value * 0.0254 << " m" << std::endl;
    }
    else
    {
        result << "Error: unit measure not found" << std::endl;
    }

    return result.str();
}

int main()
{
    double value = get_double();
    std::string unit_measure;

    std::cin >> unit_measure;
   
    std::cout << convert_m_inch(value, unit_measure) << std::endl;
    
    return 0;
}