#include <iostream>
#include <locale> 
#include "Date.h"

int main() {
    std::setlocale(LC_ALL, "ru_RU.UTF-8");
    Date birth(15, 5, 2000);
    Date today(6, 2, 2026);

    std::cout << "Дата рождения: " << birth.toString() << std::endl;
    std::cout << "Сегодня: " << today.toString() << std::endl;

    std::cout << "Возраст (в днях): "
              << birth.daysBetween(today) << std::endl;

    int dow = birth.dayOfWeek();
    std::cout << "День недели рождения (0-вс): " << dow << std::endl;

    Date future = today;
    future.addDays(10);
    std::cout << "Дата через 10 дней: " << future.toString() << std::endl;

    if (birth < today)
        std::cout << "Дата рождения раньше сегодняшней\n";

    return 0;
}
