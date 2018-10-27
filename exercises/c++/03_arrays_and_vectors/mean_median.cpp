/**
    Advanced Programming 2018-2019
    Purpose: Compute mean and median for temperature.txt values

    @author Gabriele Sarti
    @version 27/10/18
*/

#include <vector>
#include <fstream>
#include <algorithm>
#include <iostream>

/**
    Imports values from a text file

    @param filename the name of the file containing the list of values
    @return an std::vector containing all the values
*/
const std::vector<double> import_values(std::string filename)
{
    double value = 0.0;
    std::ifstream file(filename);
    std::string line;
    std::vector<double> values;

    while (file >> value)
    {
        values.push_back(value);
    }

    return values;
}

/**
    Computes the mean for a vector of values

    @param values the vector containing the values
    @return the mean of values inside vector values
*/
const double mean(std::vector<double> values)
{
    double sum = 0.0;

    for (double val : values)
    {
        sum += val;
    }

    return sum / values.size();
}

/**
    Computes the median for a vector of values

    @param values the vector containing the values
    @return the median of values inside vector values
*/
const double median(std::vector<double> values)
{
    std::sort(values.begin(), values.end());
    int size = values.size();
    double median;
    if (size % 2 == 0 )
    {
        median = (values[size / 2] + values[(size / 2) - 1]) / 2.0;
    }
    else
    {
        median = values[size / 2];
    }
    return median;
}

int main()
{
    std::vector<double> temp = import_values("temperatures.txt");
    std::cout << "Mean: " << mean(temp) << std::endl;
    std::cout << "Median: " << median(temp) << std::endl;
    return 0;
}