#include <iostream>
#include "Complex.h"
int main() {
    setlocale(LC_ALL, "rus");
    Complex c1, c2;
    cin >> c1;
    cin >> c2;

    cout << "Первое комплексное число: " << c1 << endl;
    cout << "Второе комплексное число: " << c2 << endl;

    Complex sum = c1 + c2;
    cout << "Сумма: " << sum << endl;

    Complex diff = c1 - c2;
    cout << "Разность: " << diff << endl;
    cout << "Комплексные числа " << (c1 == c2 ? "равны" : "не равны") << endl;

    return 0;
}