#include <iostream>
#include <vector>
using namespace std;

class GraphicObject {
public:
    virtual void draw() = 0;
    virtual ~GraphicObject() {}
};

class Circle : public GraphicObject {
public:
    void draw() override { cout << "Рисуем круг" << endl; }
};

class Rectangle : public GraphicObject {
public:
    void draw() override { cout << "Рисуем прямоугольник" << endl; }
};

class GroupOfObjects : public GraphicObject {
    vector<GraphicObject*> objects;
public:
    void add(GraphicObject* obj) { objects.push_back(obj); }
    void draw() override {
        cout << "Рисуем группу:" << endl;
        for (auto obj : objects) obj->draw();
    }
};