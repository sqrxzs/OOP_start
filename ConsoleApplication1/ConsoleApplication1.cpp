#include <iostream>

using namespace std;

class GeometricFigure {
public:
    virtual double area() const = 0;
    virtual ~GeometricFigure() {}
};

// Производный класс: Окружность
class Circle : public GeometricFigure {
private:
    double radius;

public:
    Circle(double r) : radius(r) {}

    double area() const override {
        return 3.14159265358979323846 * radius * radius; // Формула для площади круга
    }
};

// Производный класс: Прямоугольник
class Rectangle : public GeometricFigure {
private:
    double width;
    double height;

public:
    Rectangle(double w, double h) : width(w), height(h) {}

    double area() const override {
        return width * height; 
    }
};

// Производный класс: Треугольник
class Triangle : public GeometricFigure {
private:
    double base;
    double height;

public:
    Triangle(double b, double h) : base(b), height(h) {}

    double area() const override {
        return 0.5 * base * height; 
    }
};

int main() {
    setlocale(LC_ALL, "rus");
    GeometricFigure* circle = new Circle(5);
    GeometricFigure* rectangle = new Rectangle(4, 6);
    GeometricFigure* triangle = new Triangle(3, 7);

    std::cout << "Площадь круга: " << circle->area() << std::endl;
    std::cout << "Площадь прямоугольника: " << rectangle->area() << std::endl;
    std::cout << "Площадь треугольника: " << triangle->area() << std::endl;

    // Освобождение памяти
    delete circle;
    delete rectangle;
    delete triangle;

    return 0;
}