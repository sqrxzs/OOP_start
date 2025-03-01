#pragma once
#include <iostream>

using namespace std;
class Point
{
private:
	int* a;
	int* b;

	int* x;
	int* y;
public:
	Point() {
		this->a = new int(500);
		cout << "One number: " << endl;
		cin >> *a;

		this->b = new int(500);
		cout << "Two number: " << endl;
		cin >> *b;

		this->x = new int(500);
		cout << "Tree number: " << endl;
		cin >> *x;

		this->y = new int(500);
		cout << "Four number: " << endl;
		cin >> *y; 
	}
	
	void displayInfo() {
		cout << "One drob: " << *a << "/" << *b <<endl;
		cout << " Two drob: " << *x << "/" << *y << endl;
	}
    void resultSumm() {
        cout << "Сумма дробей: " << *a << "/" << *b << " + " << *x << "/" << *y
            << " = " << ((*a * *y) + (*x * *b)) << "/" << (*b * *y) << endl;
    }

    void resultSubtract() {
        cout << "Разность дробей: " << *a << "/" << *b << " - " << *x << "/" << *y
            << " = " << ((*a * *y) - (*x * *b)) << "/" << (*b * *y) << endl;
    }

    void resultMultiply() {
        cout << "Произведение дробей: " << *a << "/" << *b << " * " << *x << "/" << *y
            << " = " << (*a * *x) << "/" << (*b * *y) << endl;
    }

    // Сложение дроби и целого числа
    void addInteger(int integer) {
        cout << "Сложение дроби " << *a << "/" << *b << " с целым числом " << integer
            << " = " << (*a + integer * *b) << "/" << *b << endl;
    }

    // Вычитание дроби и целого числа
    void subtractInteger(int integer) {
        cout << "Вычитание дроби " << *a << "/" << *b << " с целым числом " << integer
            << " = " << (*a - integer * *b) << "/" << *b << endl;
    }

    // Умножение дроби на целое число
    void multiplyInteger(int integer) {
        cout << "Умножение дроби " << *a << "/" << *b << " на целое число " << integer
            << " = " << (*a * integer) << "/" << *b << endl;
    }

    // Деструктор для освобождения памяти
    ~Point() {
        delete a;
        delete b;
        delete x;
        delete y;
    }
};


