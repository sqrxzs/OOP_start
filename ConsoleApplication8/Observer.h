#include <iostream>
#include <vector>
using namespace std;

class Observer {
public:
    virtual void update(float temp, float pressure, float humidity) = 0;
    virtual ~Observer() {}
};

class WeatherSubject {
    vector<Observer*> observers;
    float temperature, pressure, humidity;
public:
    void addObserver(Observer* o) {
        observers.push_back(o);
    }
    void removeObserver(Observer* o) {
        // Реализация удаления наблюдателя
    }
    void notifyObservers() {
        for (auto obs : observers) {
            obs->update(temperature, pressure, humidity);
        }
    }
    void setMeasurements(float t, float p, float h) {
        temperature = t;
        pressure = p;
        humidity = h;
        notifyObservers();
    }
};

class SMSNotification : public Observer {
public:
    void update(float temp, float pressure, float humidity) override {
        cout << "SMS: Погода изменилась! Температура: " << temp << "°C\n";
    }
};

class EmailNotification : public Observer {
public:
    void update(float temp, float pressure, float humidity) override {
        cout << "Email: Новая информация о погоде. Влажность: " << humidity << "%\n";
    }
};
