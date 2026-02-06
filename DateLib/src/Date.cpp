#include "Date.h"
#include <sstream>
#include <cmath>

Date::Date(int d, int m, int y) : day(d), month(m), year(y) {}

bool Date::isLeapYear() const {
    return (year % 4 == 0 && year % 100 != 0) || (year % 400 == 0);
}

bool Date::isValid() const {
    if (year < 1 || month < 1 || month > 12 || day < 1)
        return false;

    int daysInMonth[] = { 31,28,31,30,31,30,31,31,30,31,30,31 };
    if (isLeapYear())
        daysInMonth[1] = 29;

    return day <= daysInMonth[month - 1];
}

int Date::dayOfWeek() const {
    int m = month;
    int y = year;
    if (m < 3) {
        m += 12;
        y--;
    }

    int k = y % 100;
    int j = y / 100;

    int h = (day + (13 * (m + 1)) / 5 + k + k / 4 + j / 4 + 5 * j) % 7;
    return (h + 6) % 7; // 0 - воскресенье
}

static int dateToDays(int d, int m, int y) {
    return y * 365 + y / 4 - y / 100 + y / 400 + (m * 30) + d;
}

int Date::daysBetween(const Date& other) const {
    int d1 = dateToDays(day, month, year);
    int d2 = dateToDays(other.day, other.month, other.year);
    return std::abs(d1 - d2);
}

void Date::addDays(int days) {
    day += days;
    while (!isValid()) {
        day--;
        month++;
        if (month > 12) {
            month = 1;
            year++;
        }
    }
}

bool Date::operator<(const Date& other) const {
    if (year != other.year) return year < other.year;
    if (month != other.month) return month < other.month;
    return day < other.day;
}

bool Date::operator>(const Date& other) const {
    return other < *this;
}

std::string Date::toString() const {
    std::ostringstream oss;
    oss << day << "." << month << "." << year;
    return oss.str();
}
