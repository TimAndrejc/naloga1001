//
// Created by Tim Andrejc on 15. 5. 24.
//
#include <vector>
#include <string>
#include "Date.h"

using namespace std;

Date::Date(int day, int month, int year) {
    if (isDateValid(day, month, year)) {
        this->day = day;
        this->month = month;
        this->year = year;
    } else {
        this->day = 1;
        this->month = 1;
        this->year = 1970;
    }
}

Date::Date() {
    this->day = 1;
    this->month = 1;
    this->year = 1970;
}

string Date::toString() const {
    return to_string(day) + "." + to_string(month) + "." + to_string(year);
}

bool Date::isLeapYear(const unsigned int year) {
    if ((year % 4 == 0 && year % 100 != 0) || year % 400 == 0)
        return true;
    return false;
}

int Date::getDaysInMonth(unsigned int month, unsigned int year) {
    if (month > maxMonth || month == 0) {
        return 0;
    }
    if (month == 2 && isLeapYear(year))
        return maxDayByMonth[month - 1] + 1;
    return maxDayByMonth[month - 1];
}

bool Date::isDateValid(unsigned int day, unsigned int month, unsigned int year) {
    if (day == 0 || month == 0) {
        return false;
    }
    if (day > getDaysInMonth(month, year) || month > maxMonth) {
        return false;
    }
    return true;
}

int Date::getDay() const {
    return day;
}

void Date::setDay(const int day) {
    if (isDateValid(day, this->month, this->year)) {
        this->day = day;
    }
}

int Date::getMonth() const {
    return month;
}

void Date::setMonth(int month) {
    if (Date::isDateValid(this->day, month, this->year)) {
        this->month = month;
    }
}

int Date::getYear() const {
    return year;
}

void Date::setYear(int year) {
    if (isDateValid(this->day, this->month, year)) {
        this->year = year;
    }
}

Date Date::parse(const string date) {
    string str;
    vector<int> temp;
    for (char i: date) {
        if (i == '.') {
            temp.push_back(stoi(str));
            str = "";
        }else{
            str += i;
        }
    }
    temp.push_back(stoi(str));

    return Date(temp[0], temp[1], temp[2]);
}