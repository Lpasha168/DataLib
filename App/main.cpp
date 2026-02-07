
#include <iostream>
#include "Date.h"

int main() {
    try {
        int d, m, y;
        std::cout << "Enter date (day month year): ";
        std::cin >> d >> m >> y;

        Date date(d, m, y);

        std::cout << "Date: " << date.toString() << "\n";
        std::cout << "Leap year? " << (date.isLeapYear() ? "Yes" : "No") << "\n";
        std::cout << "Day of week: " << date.dayOfWeek() << "\n";

        Date another(1, 1, 2000);
        std::cout << "Days between " << date.toString() << " and 01/01/2000: "
            << date.daysBetween(another) << "\n";

        date.addDays(10);
        std::cout << "After adding 10 days: " << date.toString() << "\n";


        std::cout << "Enter birth date (day month year): ";
        int bd, bm, by;
        std::cin >> bd >> bm >> by;
        Date birth(bd, bm, by);
        Date today(7, 2, 2026);
        int age = today.daysBetween(birth) / 365;
        std::cout << "Age: " << age << " years\n";
    }
    catch (std::exception& e) {
        std::cerr << e.what() << "\n";
    }
    return 0;
}

