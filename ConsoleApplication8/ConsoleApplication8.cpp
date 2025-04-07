#include <iostream>
#include "Visitor.h"
#include "Chain_of_Responsibility.h"
#include "Observer.h"
#include "Strategy.h"

using namespace std;

int main() {
    setlocale(LC_ALL, "rus");
    cout << "=== Демонстрация всех паттернов ===\n\n";

    // 1. Демонстрация Стратегии
    cout << "1. Паттерн Стратегия:\n";
    Order order;
    order.setStrategy(new WeightBasedDelivery(15));
    cout << "Стоимость доставки (15 кг): " << order.calculateDelivery() << " руб.\n\n";

    // 2. Демонстрация Наблюдателя
    cout << "2. Паттерн Наблюдатель:\n";
    WeatherSubject weather;
    weather.addObserver(new SMSNotification());
    weather.setMeasurements(25.5, 755.0, 65.0);
    cout << endl;

    // 3. Демонстрация Цепочки обязанностей
    cout << "3. Паттерн Цепочка обязанностей:\n";
    JuniorSupport junior;
    SeniorSupport senior;
    junior.setNextHandler(&senior);

    Request simpleReq("Простая проблема");
    Request complexReq("Сложная техническая проблема");

    junior.handleRequest(simpleReq);
    junior.handleRequest(complexReq);
    cout << endl;

    // 5. Демонстрация Посетителя
    cout << "4. Паттерн Посетитель:\n";
    Shape* shapes[] = { new Rectangle(4, 5), new Circle(3) };
    AreaCalculator areaCalc;

    for (auto shape : shapes) {
        shape->accept(areaCalc);
    }
    cout << endl;

    cout << "=== Демонстрация завершена ===\n";
    return 0;
}