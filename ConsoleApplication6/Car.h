#pragma once
#include <iostream>
#include <memory>
using namespace std;

class Car {
private:
    string brand;
    string model;
    int year;

public:
    Car(const string& b, const string& m, int y) : brand(b), model(m), year(y) {}

    void display() {
        cout << "Марка: " << brand << ", Модель: " << model << ", Год: " << year << endl;
    }
};


