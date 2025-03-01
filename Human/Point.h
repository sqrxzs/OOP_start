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
        cout << "����� ������: " << *a << "/" << *b << " + " << *x << "/" << *y
            << " = " << ((*a * *y) + (*x * *b)) << "/" << (*b * *y) << endl;
    }

    void resultSubtract() {
        cout << "�������� ������: " << *a << "/" << *b << " - " << *x << "/" << *y
            << " = " << ((*a * *y) - (*x * *b)) << "/" << (*b * *y) << endl;
    }

    void resultMultiply() {
        cout << "������������ ������: " << *a << "/" << *b << " * " << *x << "/" << *y
            << " = " << (*a * *x) << "/" << (*b * *y) << endl;
    }

    // �������� ����� � ������ �����
    void addInteger(int integer) {
        cout << "�������� ����� " << *a << "/" << *b << " � ����� ������ " << integer
            << " = " << (*a + integer * *b) << "/" << *b << endl;
    }

    // ��������� ����� � ������ �����
    void subtractInteger(int integer) {
        cout << "��������� ����� " << *a << "/" << *b << " � ����� ������ " << integer
            << " = " << (*a - integer * *b) << "/" << *b << endl;
    }

    // ��������� ����� �� ����� �����
    void multiplyInteger(int integer) {
        cout << "��������� ����� " << *a << "/" << *b << " �� ����� ����� " << integer
            << " = " << (*a * integer) << "/" << *b << endl;
    }

    // ���������� ��� ������������ ������
    ~Point() {
        delete a;
        delete b;
        delete x;
        delete y;
    }
};


