/**
    Advanced Programming 2018-2019
    Purpose: Implement methods for the Date class

    @author Gabriele Sarti
    @version 26/10/18
*/

# include "date.hpp"
#include <iostream>
#include <sstream>

Date::Date(const unsigned short day, const month_enum month, const int year)
{
    m_day = day;
    m_month = month;
    m_year = year;

    m_days_per_month = {
        { month_enum::january ,   31},
        { month_enum::february ,  is_leap() ? 29 : 28},
        { month_enum::march ,     31},
        { month_enum::april ,     30},
        { month_enum::may ,       31},
        { month_enum::june ,      30},
        { month_enum::july ,      31},
        { month_enum::august ,    31},
        { month_enum::september , 30},
        { month_enum::october ,   31},
        { month_enum::november ,  30},
        { month_enum::december ,  31},
    };
}

const unsigned short Date::day() const
{
    return m_day;
}

const month_enum Date::month() const
{
    return m_month;
}

const unsigned int Date::year() const
{
    return m_year;
}

void Date::add_one_day()
{
    if (m_day != m_days_per_month[m_month])
    {
        m_day = 1;
        if (m_month == month_enum::december)
        {
            m_month = month_enum::january;
            ++m_year;
        }
        else
        {
            int temp = static_cast<int>(m_month);
            ++temp;
            m_month = static_cast<month_enum>(temp);
        }
    }
    else
    {
        ++m_day;
    }
}

const void Date::add_days(const unsigned int n)
{
    for(unsigned int i = 0; i < n; ++i)
    {
        add_one_day();
    }
}

const bool Date::is_leap() const
{
    return m_year % 4 == 0 && m_year % 400 != 0;
}

std::ostream& operator<<(std::ostream& os, const Date& d)
{
  os << d.day() << " " << static_cast<int>(d.month()) << " " << d.year();
  return os;
}

bool operator==(const Date& lhs, const Date& rhs)
{
    return lhs.day() == rhs.day() &&
           lhs.month() == rhs.month() &&
           lhs.year() == rhs.year();
}

bool operator!=(const Date& lhs, const Date& rhs)
{
    return lhs.day() != rhs.day() ||
           lhs.month() != rhs.month() ||
           lhs.year() != rhs.year();
}