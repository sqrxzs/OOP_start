#pragma once
#include <iostream>
using namespace std;

class Complex {
private:
    double real;  // �������������� �����
    double imag;  // ������ �����

public:
    Complex() : real(0), imag(0) {}
    Complex(double r, double i) : real(r), imag(i) {}
    Complex(const Complex& c) : real(c.real), imag(c.imag) {}

    // ���������� ���������� ����� � ������
    friend ostream& operator<<(ostream& os, const Complex& c) {
        os << c.real << (c.imag >= 0 ? "+" : "") << c.imag << "i";
        return os;
    }

    friend istream& operator>>(istream& is, Complex& c) {
        cout << "������� �������������� �����: ";
        is >> c.real;
        cout << "������� ������ �����: ";
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


