#pragma once
#include <iostream>
using namespace std;

class Complex {
private:
    double real;  // Действительная часть
    double imag;  // Мнимая часть

public:
    Complex() : real(0), imag(0) {}
    Complex(double r, double i) : real(r), imag(i) {}
    Complex(const Complex& c) : real(c.real), imag(c.imag) {}

    // Перегрузка операторов ввода и вывода
    friend ostream& operator<<(ostream& os, const Complex& c) {
        os << c.real << (c.imag >= 0 ? "+" : "") << c.imag << "i";
        return os;
    }

    friend istream& operator>>(istream& is, Complex& c) {
        cout << "Введите действительную часть: ";
        is >> c.real;
        cout << "Введите мнимую часть: ";
        is >> c.imag;
        return is;
    }

    Complex operator+(const Complex& c) const {
        return Complex(real + c.real, imag + c.imag);
    }

    Complex operator-(const Complex& c) const {
        return Complex(real - c.real, imag - c.imag);
    }

    bool operator==(const Complex& c) const {
        return (real == c.real && imag == c.imag);
    }

    bool operator!=(const Complex& c) const {
        return !(*this == c);
    }

    Complex operator()() const {
        return *this;
    }

    double getReal() const { return real; }
    double getImag() const { return imag; }
};


