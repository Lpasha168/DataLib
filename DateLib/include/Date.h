#ifndef DATE_H
#define DATE_H

#include <string>

class Date {
private:
    int day;
    int month;
    int year;

public:
    Date(int d = 1, int m = 1, int y = 1970);

    bool isValid() const;
    bool isLeapYear() const;
    int dayOfWeek() const;               // алгоритм Зеллера
    int daysBetween(const Date& other) const;
    void addDays(int days);

    bool operator<(const Date& other) const;
    bool operator>(const Date& other) const;

    std::string toString() const;
};

#endif
