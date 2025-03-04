#include <iostream>

const double M_PI = 3.14;
using namespace std;
class Circle {
private:
    double radius;

public:
    Circle(double r) : radius(r) {}

    bool operator==(const Circle& other) {
        return radius == other.radius;
    }

    bool operator>(const Circle& other) {
        return getLength() > other.getLength();
    }

    Circle& operator+=(double r) {
        radius += r;
        return *this;
    }

    Circle& operator-=(double r) {
        radius -= r;
        if (radius < 0) {
            radius = 0;
        }
        return *this;
    }

    double getLength() const {
        return 2 * M_PI * radius;
    }

    void display() const {
        cout << "Радиус окружности: " << radius << ", Длина: " << getLength() << endl;
    }
};

