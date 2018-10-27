/**
    Advanced Programming 2018-2019
    Purpose: Test the date class

    @author Gabriele Sarti
    @version 26/10/18
*/

#include "date.hpp"
#include <iostream>

// Tests for the Date class
int main()
{
    Date d1 = Date(18, month_enum::october, 2018);
    Date d2 = Date(19, month_enum::october, 2018);
    Date d3 = Date(18, month_enum::november, 2018);
    Date d4 = Date(28, month_enum::february, 2400);
    Date d5 = Date(28, month_enum::february, 2016);
    d1 == d1 ? std::cout << "true" << std::endl : std::cout << "false" << std::endl;
    d1 == d2 ? std::cout << "true" << std::endl : std::cout << "false" << std::endl;
    d1 == d3 ? std::cout << "true" << std::endl : std::cout << "false" << std::endl;
    d4 == d5 ? std::cout << "true" << std::endl : std::cout << "false" << std::endl;
    d4.is_leap() ? std::cout << "true" << std::endl : std::cout << "false" << std::endl;
    d5.is_leap() ? std::cout << "true" << std::endl : std::cout << "false" << std::endl;
    d4.add_days(1);
    std::cout << d4 << std::endl;
    d5.add_days(1);
    std::cout << d5 << std::endl;
    d1.add_days(24);
    std::cout << d1 << std::endl;
    return 0;
}