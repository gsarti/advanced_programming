#ifndef DATE_H__
#define DATE_H__
#include <map>

/**
    Defines the month type used inside the Date class
*/
enum class month_enum { january = 1,
                        february,
                        march,
                        april,
                        may,
                        june,
                        july,
                        august,
                        september,
                        october,
                        november,
                        december 
                      };

class Date {

private:
    unsigned short m_day;
    month_enum m_month;
    int m_year;
    std::map<month_enum, unsigned char> m_days_per_month; // Month-duration mapping

    // Allows the divide-and-conquer strategy for public add_days method
    void add_one_day();

public:
    Date(const unsigned short day, const month_enum month, const int year);

    const unsigned short day() const;
    const month_enum month() const;
    const unsigned int year() const;

    /**
    Add n days to the current date.

    @param n the number of days to add
    @return nothing, the object is changed consequently
    */
    const void add_days(const unsigned int n);

    /**
    Allows checking for leap years.

    @param none
    @return true if current year is leap, false otherwise
    */
    const bool is_leap() const;
};

// Operators overloading for Date class

std::ostream& operator<<(std::ostream& os, const Date& d);
bool operator==(const Date& lhs, const Date& rhs);
bool operator!=(const Date& lhs, const Date& rhs);

#endif //DATE_H