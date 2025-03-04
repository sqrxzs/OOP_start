#include <iostream>
#include "Circle.h"
using namespace std;

int main() {
    setlocale(LC_ALL, "rus");
    Circle circle1(5);
    Circle circle2(5);
    Circle circle3(3);

    if (circle1 == circle2) {
        cout << "Окружность 1 равна окружности 2." << endl;
    }
    else {
        cout << "Окружность 1 не равна окружности 2." << endl;
    }

    if (circle1 > circle3) {
        cout << "Окружность 1 больше окружности 3." << endl;
    }
    else {
        cout << "Окружность 1 не больше окружности 3." << endl;
    }

    circle1 += 2;
    cout << "После увеличения радиуса окружности 1 на 2:" << endl;
    circle1.display();

    circle1 -= 3;
    cout << "После уменьшения радиуса окружности 1 на 3:" << endl;
    circle1.display();

    circle1 -= 10;
    cout << "После уменьшения радиуса окружности 1 на 10 (не может быть отрицательным):" << endl;
    circle1.display();

    return 0;
}