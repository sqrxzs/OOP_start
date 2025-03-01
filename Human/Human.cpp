#include <iostream>
#include "Human.h"
#include "Point.h"
using namespace std;

int main()
{
    setlocale(LC_ALL, "rus");
    Point point;
    point.displayInfo();
    point.resultSumm();
    point.resultSubtract();
    point.resultMultiply();

    int integer;
    cout << "Введите целое число: ";
    cin >> integer;
    point.addInteger(integer);
    point.subtractInteger(integer);
    point.multiplyInteger(integer);

    return 0;
}
