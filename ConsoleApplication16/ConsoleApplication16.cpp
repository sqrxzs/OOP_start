#include <iostream>
#include "Date.h"
int main()
{
    setlocale(LC_ALL, "rus");
    Date date1(2, 3, 2025);
    Date date2(4, 3, 2025);

    std::cout << "Разница: " << (date2 - date1) << std::endl;

    Date newDate = date1 + 35;
    std::cout << "Новая дата с добавлением 35 дней: ";
    newDate.display();

    return 0;
}
