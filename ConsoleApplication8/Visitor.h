#include <iostream>
#include <cmath>
using namespace std;

class Visitor {
public:
    virtual void visit(class Rectangle& rect) = 0;
    virtual void visit(class Circle& circle) = 0;
    virtual void visit(class Triangle& tri) = 0;
    virtual ~Visitor() {}
};

class Shape {
public:
    virtual void accept(Visitor& visitor) = 0;
    virtual ~Shape() {}
};

class Rectangle : public Shape {
    double width, height;
public:
    Rectangle(double w, double h) : width(w), height(h) {}
    void accept(Visitor& visitor) override {
        visitor.visit(*this);
    }
    double getWidth() { return width; }
    double getHeight() { return height; }
};

class Circle : public Shape {
    double radius;
public:
    Circle(double r) : radius(r) {}
    void accept(Visitor& visitor) override {
        visitor.visit(*this);
    }
    double getRadius() { return radius; }
};

class AreaCalculator : public Visitor {
public:
    void visit(Rectangle& rect) override {
        cout << "Площадь: " << rect.getWidth() * rect.getHeight() << " кв.м\n";
    }
    void visit(Circle& circle) override {
        cout << "Площадь: " << 3.14 * circle.getRadius() * circle.getRadius() << " кв.м\n";
    }
    void visit(Triangle& tri) override {
        // Реализация для треугольника
    }
};

class PerimeterCalculator : public Visitor {
public:
    void visit(Rectangle& rect) override {
        cout << "Периметр: " << 2 * (rect.getWidth() + rect.getHeight()) << " м\n";
    }
    void visit(Circle& circle) override {
        cout << "Периметр: " << 2 * 3.14 * circle.getRadius() << " м\n";
    }
    void visit(Triangle& tri)  {
        // Реализация для треугольника
    }
};
