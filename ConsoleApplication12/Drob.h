#pragma once
#include <iostream>

using namespace std;

class Drob
{
private:
	int* x;
	int* y;
public:
	int getX() const {
		return*x;
	}
	int getY() const {
		return *y;
	}
	int setX(int* p_x) {
		x = p_x;
	}
	int setY(int* p_y) {
		y = p_y;
	}
	Drob(int* pp_x, int* pp_y) {
		x = pp_x;
		y = pp_y;
	}
	void print() {
		cout << "Сложение: " << *x + *y << " Вычетание: " << *x - *y << " Умножение: "  << *x * *y << " Деление: " << *x/ *y << endl;
	}
};

