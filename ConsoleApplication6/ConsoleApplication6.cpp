#include <iostream>
#include "Car.h"

using namespace std;
int main()
{
    setlocale(LC_ALL, "rus");
    unique_ptr<Car> uniqueCar = make_unique<Car>("Toyota", "Camry", 2020);
    cout << "Уникальный указатель:" << endl;
    uniqueCar->display();

    shared_ptr<Car> sharedCar1 = make_shared<Car>("Honda", "Accord", 2019);
    {
        shared_ptr<Car> sharedCar2 = sharedCar1;
        cout << "Общий указатель (второй владелец):" << endl;
        sharedCar2->display();
    }
    cout << "Общий указатель (после выхода из блока):" << endl;
    sharedCar1->display();

    weak_ptr<Car> weakCar = sharedCar1;
    if (auto sharedFromWeak = weakCar.lock()) {
        cout << "Слабый указатель (объект существует):" << endl;
        sharedFromWeak->display();
    }
    else {
        cout << "Слабый указатель (объект не существует)." << endl;
    }

    sharedCar1.reset(); // Уничтожаем последний shared_ptr

    if (auto sharedFromWeak = weakCar.lock()) {
        cout << "Слабый указатель (объект существует):" << endl;
        sharedFromWeak->display();
    }
    else {
        cout << "Слабый указатель (объект не существует)." << endl;
    }

    return 0;
}
