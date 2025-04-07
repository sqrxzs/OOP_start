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
        cout << "�������: " << rect.getWidth() * rect.getHeight() << " ��.�\n";
    }
    void visit(Circle& circle) override {
        cout << "�������: " << 3.14 * circle.getRadius() * circle.getRadius() << " ��.�\n";
    }
    void visit(Triangle& tri) override {
        // ���������� ��� ������������
    }
};

class PerimeterCalculator : public Visitor {
public:
    void visit(Rectangle& rect) override {
        cout << "��������: " << 2 * (rect.getWidth() + rect.getHeight()) << " �\n";
    }
    void visit(Circle& circle) override {
        cout << "��������: " << 2 * 3.14 * circle.getRadius() << " �\n";
    }
    void visit(Triangle& tri)  {
        // ���������� ��� ������������
    }
};
