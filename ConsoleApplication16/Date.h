#include <iostream>

class Date {
private:
    int day;
    int month;
    int year;

private:
    int daysInMonth(int m) const {
        if (m == 2) {
            return 28;
        }
        if (m == 4 || m == 6 || m == 9 || m == 11) {
            return 30;
        }
        return 31;
    }
public:
    Date(int d, int m, int y) : day(d), month(m), year(y) {}

    int operator-(const Date& other) {
        int totalDays1 = year * 365 + day;
        for (int i = 0; i < month - 1; i++) {
            totalDays1 += daysInMonth(i + 1);
        }

        int totalDays2 = other.year * 365 + other.day;
        for (int i = 0; i < other.month - 1; i++) {
            totalDays2 += daysInMonth(i + 1);
        }

        return totalDays1 - totalDays2;
    }

    Date operator+(int days) {
        Date newDate(day, month, year);
        newDate.day += days;

        while (newDate.day > daysInMonth(newDate.month)) {
            newDate.day -= daysInMonth(newDate.month);
            newDate.month++;

            if (newDate.month > 12) {
                newDate.month = 1;
                newDate.year++;
            }
        }
        return newDate;
    }

    void display() const {
        std::cout << day << "/" << month << "/" << year << std::endl;
    }


};
