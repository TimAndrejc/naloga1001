//
// Created by Tim Andrejc on 15. 5. 24.
//

#ifndef NALOGA1001_DATE_H
#define NALOGA1001_DATE_H

#include <string>
#include <vector>

using namespace std;

class Date {
private:
    int day;
    int month;
    int year;
public:
    inline static const vector<int> maxDayByMonth{31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

    static const int maxMonth = 12;

    static const int daysInYear = 365;

    Date(int day, int month, int year);

    Date();

    string toString() const;

    static bool isLeapYear(const unsigned int year);

    static int getDaysInMonth(unsigned int month, unsigned int year);

    static bool isDateValid(unsigned int day, unsigned int month, unsigned int year);

    int getDay() const;

    int getMonth() const;

    int getYear() const;

    void setDay(int day);

    void setMonth(int month);

    void setYear(int year);

    static Date parse(const string date);

    bool operator>(Date date2) {
        return (year * 10000 + month * 100 + day) > (date2.year * 10000 + date2.month * 100 + date2.day);
    }
};

#endif //NALOGA1001_DATE_H
